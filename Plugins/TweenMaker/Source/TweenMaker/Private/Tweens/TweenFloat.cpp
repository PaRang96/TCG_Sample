// Copyright 2018 Francesco Desogus. All Rights Reserved.

#include "Tweens/TweenFloat.h"

#include "TweenFactory/Latent/TweenFloatLatentFactory.h"
#include "GameFramework/Actor.h"
#include "Utils/Utility.h"
#include "Utils/EaseEquations.h"
#include "Materials/MaterialInstanceDynamic.h"
#include "Kismet/KismetMathLibrary.h"
#include "Components/SplineComponent.h"
#include "Components/Widget.h"

namespace 
{
    FVector GetLocationFromSpace(AActor* pActor, ETweenSpace pTweenSpace)
    {
        switch (pTweenSpace)
        {
            case ETweenSpace::World:
                return pActor->GetRootComponent()->GetComponentLocation();
            case ETweenSpace::Relative:
                return pActor->GetRootComponent()->GetRelativeLocation();
            default:
                return FVector();
        }
    }

    FVector GetLocationFromSpace(USceneComponent* pSceneComponent, ETweenSpace pTweenSpace)
    {
        switch (pTweenSpace)
        {
            case ETweenSpace::World:
                return pSceneComponent->GetComponentLocation();
            case ETweenSpace::Relative:
                return pSceneComponent->GetRelativeLocation();
            default:
                return FVector();
        }
    }

    void SetLocationFromSpace(AActor* pActor, ETweenSpace pTweenSpace, const FVector& pNewLocation, bool pDoSweep)
    {
        switch (pTweenSpace)
        {
            case ETweenSpace::World:
                pActor->SetActorLocation(pNewLocation, pDoSweep);
                break;
            case ETweenSpace::Relative:
                pActor->SetActorRelativeLocation(pNewLocation, pDoSweep);
                break;
            default:
                break;
        }
    }

    void SetLocationFromSpace(USceneComponent* pSceneComponent, ETweenSpace pTweenSpace, const FVector& pNewLocation, bool pDoSweep)
    {
        switch (pTweenSpace)
        {
            case ETweenSpace::World:
                pSceneComponent->SetWorldLocation(pNewLocation, pDoSweep);
            break;
            case ETweenSpace::Relative:
                pSceneComponent->SetRelativeLocation(pNewLocation, pDoSweep);
            break;
            default:
                break;
        }
    }

    FVector ComputeArountPointUpdate(
        float pCurrentValue,
        float pPreviousValue,
        const FVector& pPivotPoint,
        const FVector& pAxis,
        float pRadius,
        FVector& outOffsetVector)
    {
        // Computing the delta angle
        float angle = pCurrentValue - pPreviousValue;

        // Rotating the offset vector by the angle delta. This basically rotates the vector around pivot point. The offset vector
        // starts at the direction from the pivot point to the initial location of the target,
        // and it rotates while still pointing towards the pivot point
        outOffsetVector = outOffsetVector.RotateAngleAxis(angle, pAxis);

        // Applying the offset vector to the target. Since the offset vector rotates around the origin,
        // I add the rotation point to position the actor in the correct place
        return pPivotPoint + outOffsetVector * pRadius;
    }
}

// public ----------------------------------------------------------------------
UTweenFloat::UTweenFloat(const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer)
    , TweenLatentProxy(nullptr)
    , mCurrentValue(0.0f)
    , mFrom(0.0f)
    , mTo(0.0f)
    , bDeleteTweenOnHit(false)
    , bDeleteTweenOnOverlap(false)
    , bHasBoundedFunctions(false)
    , mParameterName(FName(""))
{

}

// public ----------------------------------------------------------------------
void UTweenFloat::Init(float pFrom,
                       float pTo,
                       ETweenFloatType pTweenType,
                       const FName& pParameterName,
                       UTweenFloatLatentFactory* pTweenLatentProxy)
{
    mParameterName       = pParameterName;
    mFrom                = pFrom;
    mTo                  = pTo;
    mTweenType           = pTweenType;
    TweenLatentProxy     = pTweenLatentProxy;
    bHasBoundedFunctions = false;

    mCurrentValue  = 0.0f;
    mPreviousValue = 0.0f;
}

// public ----------------------------------------------------------------------
void UTweenFloat::InitRotateAround(const FVector& pPoint,
                                   float pStartingAngle,
                                   float pEndingAngle,
                                   float pRadius,
                                   const FVector& pAxis,
                                   ETweenSpace pTweenSpace,
                                   ETweenFloatType pTweenType,
                                   bool pDeleteTweenOnHit,
                                   bool pDeleteTweenOnOverlap,
                                   UTweenFloatLatentFactory* pTweenLatentProxy)
{
    mFrom            = pStartingAngle;
    mTo              = pEndingAngle;
    mTweenType       = pTweenType;
    TweenLatentProxy = pTweenLatentProxy;

    mCurrentValue  = 0.0f;
    mPreviousValue = mFrom;

    mPivotPoint           = pPoint;
    mRadius               = pRadius;
    mAxis                 = pAxis;
    mTweenSpace           = pTweenSpace;
    bDeleteTweenOnHit     = pDeleteTweenOnHit;
    bDeleteTweenOnOverlap = pDeleteTweenOnOverlap;
    bHasBoundedFunctions  = false;
}

// public ----------------------------------------------------------------------
void UTweenFloat::InitFollowSpline(USplineComponent* pSpline,
                                   bool pApplyRotation,
                                   bool pApplyScale,
                                   ETweenFloatType pTweenType,
                                   bool pDeleteTweenOnHit,
                                   bool pDeleteTweenOnOverlap,
                                   bool pUseConstantSpeed,
                                   UTweenFloatLatentFactory* pTweenLatentProxy)
{
    mFrom                 = 0;
    mTo                   = pSpline->Duration;
    mTweenType            = pTweenType;
    TweenLatentProxy      = pTweenLatentProxy;
    bDeleteTweenOnHit     = pDeleteTweenOnHit;
    bDeleteTweenOnOverlap = pDeleteTweenOnOverlap;
    bHasBoundedFunctions  = false;
    bUseConstantSpeed     = pUseConstantSpeed;

    mCurrentValue  = 0.0f;
    mPreviousValue = 0.0f;

    mSpline = pSpline;
    bSplineApplyRotation = pApplyRotation;
    bSplineApplyScale = pApplyScale;

    // Note: if the time scale is negative, the Invert() function will be called, which forces the recomputation of the "next point index".
    // So, to make things easier if we're in that case I make the next point in spline start one point beyond, since it will be subracted right away
    mNextPointIndex = mTimeScale >= 0 ? 1 : mSpline->GetNumberOfSplinePoints();
    mNextPointIndex = FMath::Clamp(mNextPointIndex, 0, mSpline->GetNumberOfSplinePoints());
}

// protected -------------------------------------------------------------------
bool UTweenFloat::Update(float pDeltaTime, float pTimeScale)
{
    Super::Update(pDeltaTime, pTimeScale);

    // Updating the elapsed time, while considering the time scale
    mElapsedTime += pDeltaTime * pTimeScale * mTimeScaleAbsolute;

    // Checking if the Tween should end
    bool hasEnded = mElapsedTime >= mTweenDuration;

    // If the Tween is ending, I'll set the current value to the desired value
    if (hasEnded)
    {
        mCurrentValue = mTo;
    }
    // Otherwise I'll compute the new value with the chosen easing function
    else
    {
        if (mCurveFloat)
        {
            mCurrentValue = EaseEquations::ComputeCustomFloatEasing(mCurveFloat, mElapsedTime, mFrom, mTo, mTweenDuration);
        }
        else
        {
            mCurrentValue = EaseEquations::ComputeFloatEasing(mEaseType, mElapsedTime, mFrom, mTo, mTweenDuration);
        }
    }

    // Depending on the type of tween target, I'll call the appropriate method for handling the new value
    switch (mTargetType)
    {
        case ETweenTargetType::Material:
        {
            UMaterialInstanceDynamic* material = Cast<UMaterialInstanceDynamic>(mTargetObject);
            UpdateForMaterial(material);
            break;
        }
        case ETweenTargetType::Actor:
        {
            AActor* actor = Cast<AActor>(mTargetObject);
            UpdateForActor(actor);
            break;
        }
        case ETweenTargetType::SceneComponent:
        {
            USceneComponent* sceneComponent = Cast<USceneComponent>(mTargetObject);
            UpdateForSceneComponent(sceneComponent);
            break;
        }
        case ETweenTargetType::UMG:
        {
            UWidget* widget = Cast<UWidget>(mTargetObject);
            UpdateForWidget(widget);
            break;
        }
        case ETweenTargetType::Custom:
        {
            break;
        }
    }

    mPreviousValue = mCurrentValue;

    return hasEnded;
}

// protected -------------------------------------------------------------------
void UTweenFloat::PreDelay()
{
    Super::PreDelay();

    BindDelegates();
}

// protected -------------------------------------------------------------------
void UTweenFloat::PrepareTween()
{
    Super::PrepareTween();

    switch (mTweenType)
    {
        case ETweenFloatType::MaterialScalarTo:
        {
            switch (mTargetType)
            {
                case ETweenTargetType::Material:
                {
                    UMaterialInstanceDynamic* material = Cast<UMaterialInstanceDynamic>(mTargetObject);
                    material->GetScalarParameterValue(FMaterialParameterInfo(mParameterName), mFrom);
                    break;
                }
            }

            break;
        }
        case ETweenFloatType::RotateAroundPoint:
        {
            FVector objectLocation = FVector(0, 0, 0);

            // Depending on the type of tween target, I'll call the appropriate method for handling the new value
            switch (mTargetType)
            {
                case ETweenTargetType::Actor:
                {
                    AActor* actor = Cast<AActor>(mTargetObject);
                    objectLocation = GetLocationFromSpace(actor, mTweenSpace);
                    break;
                }
                case ETweenTargetType::SceneComponent:
                {
                    USceneComponent* sceneComponent = Cast<USceneComponent>(mTargetObject);
                    objectLocation = GetLocationFromSpace(sceneComponent, mTweenSpace);
                    break;
                }
                default:
                {
                    break;
                }
            }

            // The offset vector at start is just the direction vector
            mOffsetVector = objectLocation - mPivotPoint;
            mOffsetVector.Normalize();

            break;
        }
        case ETweenFloatType::WidgetAngleTo:
        {
            UWidget* widget = Cast<UWidget>(mTargetObject);
            mFrom = widget->GetRenderTransform().Angle;
            break;
        }
        case ETweenFloatType::WidgetOpacityTo:
        {
            UWidget* widget = Cast<UWidget>(mTargetObject);
            mFrom = widget->GetRenderOpacity();
            break;
        }
        default:
        {
            break;
        }
    }
}

// protected -------------------------------------------------------------------
void UTweenFloat::PositionAt(bool pBeginning)
{
    // Don't bother doing anything if the Tween has not even ever started
    if (bHasPreparedTween)
    {
        // Start again at the from!
        mCurrentValue = pBeginning ? mFrom : mTo;

        // Depending on the type of tween target, I'll call the appropriate method for handling the new value
        switch (mTargetType)
        {
            case ETweenTargetType::Material:
            {
                UMaterialInstanceDynamic* material = Cast<UMaterialInstanceDynamic>(mTargetObject);
                UpdateForMaterial(material);
                break;
            }
            case ETweenTargetType::Actor:
            {
                AActor* actor = Cast<AActor>(mTargetObject);
                UpdateForActor(actor);
                break;
            }
            case ETweenTargetType::SceneComponent:
            {
                USceneComponent* sceneComponent = Cast<USceneComponent>(mTargetObject);
                UpdateForSceneComponent(sceneComponent);
                break;
            }
            case ETweenTargetType::UMG:
            {
                UWidget* widget = Cast<UWidget>(mTargetObject);
                UpdateForWidget(widget);
                break;
            }
            case ETweenTargetType::Custom:
            {
                break;
            }
            default:
            {
                break;
            }
        }
    }
}

// protected -------------------------------------------------------------------
void UTweenFloat::OnTweenPausedInternal()
{
    Super::OnTweenPausedInternal();
}

// protected -------------------------------------------------------------------
void UTweenFloat::OnTweenResumedInternal()
{
    Super::OnTweenResumedInternal();
}

// protected -------------------------------------------------------------------
void UTweenFloat::OnTweenDeletedInternal()
{
    Super::OnTweenDeletedInternal();

    UnbindDelegates();
}

// protected -------------------------------------------------------------------
void UTweenFloat::Restart(bool pRestartFromEnd)
{
    Super::Restart(pRestartFromEnd);

    if (pRestartFromEnd)
    {
        Swap(mFrom, mTo);
    }

    // If this is a spline, update the "next point in spline" approprately
    if (mSpline)
    {
        mNextPointIndex = mFrom == 0 ? 1 : mSpline->GetNumberOfSplinePoints() - 1;
        mNextPointIndex = FMath::Clamp(mNextPointIndex, 0, mSpline->GetNumberOfSplinePoints() - 1);
    }

    mElapsedTime = 0.0f;
}

// protected -------------------------------------------------------------------
void UTweenFloat::Invert(bool pShouldInvertElapsedTime)
{
    Super::Invert(pShouldInvertElapsedTime);

    // If this is a spline, update the "next point in spline" approprately
    if (mSpline)
    {
        // Check if we're going from 0 to the end or backward and update accordingly (taking into account that we'll now switch)
        mNextPointIndex = mFrom == 0 ? (mNextPointIndex - 1) % mSpline->GetNumberOfSplinePoints()
                                     : (mNextPointIndex + 1) % mSpline->GetNumberOfSplinePoints();
        mNextPointIndex = FMath::Clamp(mNextPointIndex, 0, mSpline->GetNumberOfSplinePoints() - 1);
    }

    Swap(mFrom, mTo);
}

// protected -------------------------------------------------------------------
void UTweenFloat::BroadcastOnTweenStart()
{
    Super::BroadcastOnTweenStart();

    // If this tween is Latent, the proxy won't be null
    if (TweenLatentProxy != nullptr)
    {
        TweenLatentProxy->OnTweenStart.Broadcast(this);
    }
    else
    {
        if (OnTweenStart.IsBound())
        {
            OnTweenStart.Broadcast(this);
        }

        OnTweenStartDelegate.ExecuteIfBound(this);
    }

    // Binding the OnHit/OnOverlap delegates if present
    BindDelegates();
}

// protected -------------------------------------------------------------------
void UTweenFloat::BroadcastOnTweenUpdate()
{
    Super::BroadcastOnTweenUpdate();

    if (TweenLatentProxy != nullptr)
    {
        TweenLatentProxy->OnTweenUpdate.Broadcast(this);
    }
    else
    {
        if (OnTweenUpdate.IsBound())
        {
            OnTweenUpdate.Broadcast(this);
        }

        OnTweenUpdateDelegate.ExecuteIfBound(this);
    }
}

// protected -------------------------------------------------------------------
void UTweenFloat::BroadcastOnTweenEnd()
{
    Super::BroadcastOnTweenEnd();

    if (TweenLatentProxy != nullptr)
    {
        TweenLatentProxy->OnTweenEnd.Broadcast(this);
    }
    else
    {
        if (OnTweenEnd.IsBound())
        {
            OnTweenEnd.Broadcast(this);
        }

        OnTweenEndDelegate.ExecuteIfBound(this);
    }
}

// private ---------------------------------------------------------------------
void UTweenFloat::UpdateForMaterial(UMaterialInstanceDynamic* pTarget)
{
    switch (mTweenType)
    {
        case ETweenFloatType::MaterialScalarTo:
        case ETweenFloatType::MaterialScalarFromTo:
        {
            pTarget->SetScalarParameterValue(mParameterName, mCurrentValue);
            break;
        }
        default:
        {
            break;
        }
    }
}

// private ---------------------------------------------------------------------
void UTweenFloat::UpdateForActor(AActor* pTarget)
{
    switch (mTweenType)
    {
        case ETweenFloatType::RotateAroundPoint:
        {
            FVector newLocation = ComputeArountPointUpdate(mCurrentValue, mPreviousValue, mPivotPoint, mAxis, mRadius, mOffsetVector);
            SetLocationFromSpace(pTarget, mTweenSpace, newLocation, bHasBoundedFunctions);
            break;
        }
        case ETweenFloatType::FollowSpline:
        {
            if (mSpline != nullptr)
            {
                FVector newLocation = mSpline->GetLocationAtTime(mCurrentValue, ESplineCoordinateSpace::World, bUseConstantSpeed);
                pTarget->SetActorLocation(newLocation, bHasBoundedFunctions);

                if (bSplineApplyRotation)
                {
                    FRotator newRotation = mSpline->GetRotationAtTime(mCurrentValue, ESplineCoordinateSpace::World, bUseConstantSpeed);
                    pTarget->SetActorRotation(newRotation);
                }

                if (bSplineApplyScale)
                {
                    FVector newScale = mSpline->GetScaleAtTime(mCurrentValue, ESplineCoordinateSpace::World);
                    pTarget->SetActorScale3D(newScale);
                }

                CheckSplinePointReached(newLocation);
            }

            break;
        }
        default:
        {
            break;
        }
    }
}

// private ---------------------------------------------------------------------
void UTweenFloat::UpdateForSceneComponent(USceneComponent* pTarget)
{
    switch (mTweenType)
    {
        case ETweenFloatType::RotateAroundPoint:
        {
            FVector newLocation = ComputeArountPointUpdate(mCurrentValue, mPreviousValue, mPivotPoint, mAxis, mRadius, mOffsetVector);
            SetLocationFromSpace(pTarget, mTweenSpace, newLocation, bHasBoundedFunctions);
            break;
        }
        case ETweenFloatType::FollowSpline:
        {
            if (mSpline != nullptr)
            {
                FVector newLocation = mSpline->GetLocationAtTime(mCurrentValue, ESplineCoordinateSpace::World, bUseConstantSpeed);
                pTarget->SetWorldLocation(newLocation, bHasBoundedFunctions);

                if (bSplineApplyRotation)
                {
                    FRotator newRotation = mSpline->GetRotationAtTime(mCurrentValue, ESplineCoordinateSpace::World, bUseConstantSpeed);
                    pTarget->SetWorldRotation(newRotation);
                }

                if (bSplineApplyScale)
                {
                    FVector newScale = mSpline->GetScaleAtTime(mCurrentValue, ESplineCoordinateSpace::World);
                    pTarget->SetWorldScale3D(newScale);
                }

                CheckSplinePointReached(newLocation);
            }

            break;
        }
        default:
        {
            break;
        }
    }
}

// private ---------------------------------------------------------------------
void UTweenFloat::UpdateForWidget(UWidget* pTarget)
{
    switch (mTweenType)
    {
        case ETweenFloatType::WidgetAngleTo:
        {
            pTarget->SetRenderTransformAngle(mCurrentValue);
            break;
        }
        case ETweenFloatType::WidgetOpacityTo:
        {
            pTarget->SetRenderOpacity(mCurrentValue);
            break;
        }
        default:
        {
            break;
        }
    }
}

// private ---------------------------------------------------------------------
void UTweenFloat::CheckSplinePointReached(const FVector& WorldPosition)
{
    bool isSomethingBound = OnTweenSplinePointReached.IsBound() || OnTweenSplinePointReachedDelegate.IsBound();

    if (isSomethingBound)
    {
        int numPoints = mSpline->GetNumberOfSplinePoints();
        bool found = false;

        // Find the input key at this position. From what I understand, I can consider "input keys" as normalized point indices. For example,
        // If I'm going from point 2 to point 3 and I'm currently in the middle, the resulting input index will be 2.5. If I'm at 3/4 towards 
        // point 3, the input key will be 2.75 and so on.
        // So, to determine the closest point index, I take the current input key and round it
        float closestInputKey = mSpline->FindInputKeyClosestToWorldLocation(WorldPosition);
        int point = FMath::RoundToInt(closestInputKey);

        // Several cases to consider, depending on whether the Tween is going backward and whether it's inverted.
        // This "if" matches the standard case, meaning that it's going forward with a normal timescale. If that's the case,
        // check if the closest point index matches the next one we expect to find. If so, if the input key is 
        // greater or equal thatn the point index, it means that we've want past it, so we can consider it "reaching it"
        if (   mFrom == 0
            && mTimeScale >= 0
            && point == mNextPointIndex
            && closestInputKey >= mNextPointIndex)
        {
            // We're going forward, so increment the next expected point
            mNextPointIndex = (mNextPointIndex + 1) % mSpline->GetNumberOfSplinePoints();
            found = true;
        }
        // Same thing as above, but this matches the "going backward" case
        else if (   (mTo == 0 || mTimeScale < 0)
                 && point == mNextPointIndex
                 && closestInputKey <= mNextPointIndex)
        {
            // Decrement the point
            mNextPointIndex = (mNextPointIndex - 1) % mSpline->GetNumberOfSplinePoints();
            found = true;
        }

        if (found)
        {
            if (OnTweenSplinePointReached.IsBound())
            {
                OnTweenSplinePointReached.Broadcast(this, point);
            }
            else if (OnTweenSplinePointReachedDelegate.IsBound())
            {
                OnTweenSplinePointReachedDelegate.Execute(this, point);
            }
        }
    }
}

// private ---------------------------------------------------------------------
void UTweenFloat::BindDelegates()
{
    if (!bHasBoundedFunctions && mTargetObject.IsValid())
    {
        bool foundCorrectType = false;

        switch (mTweenType)
        {
            case ETweenFloatType::FollowSpline:
            case ETweenFloatType::RotateAroundPoint:
            case ETweenFloatType::Custom:
            {
                // I can only bind the event if the tween target is actually an AActor...
                if (AActor* actor = Cast<AActor>(mTargetObject))
                {
                    if (   bDeleteTweenOnOverlap
                        || OnTweenActorBeginOverlap.IsBound()
                        || OnTweenActorBeginOverlapDelegate.IsBound())
                    {
                        foundCorrectType = true;
                        actor->OnActorBeginOverlap.AddDynamic(this, &UTweenFloat::OnActorBeginOverlap);
                    }

                    if (   bDeleteTweenOnHit
                        || OnTweenActorHit.IsBound()
                        || OnTweenActorHitDelegate.IsBound())
                    {
                        foundCorrectType = true;
                        actor->OnActorHit.AddDynamic(this, &UTweenFloat::OnActorHit);
                    }
                }
                    // ... or a UPrimitiveComponent
                else if (UPrimitiveComponent* component = Cast<UPrimitiveComponent>(mTargetObject))
                {
                    if (   bDeleteTweenOnOverlap
                        || OnTweenPrimitiveComponentBeginOverlap.IsBound()
                        || OnTweenPrimitiveComponentBeginOverlapDelegate.IsBound())
                    {
                        foundCorrectType = true;
                        component->OnComponentBeginOverlap.AddDynamic(this, &UTweenFloat::OnPrimitiveComponentBeginOverlap);
                    }

                    if (   bDeleteTweenOnHit
                        || OnTweenPrimitiveComponentHit.IsBound()
                        || OnTweenPrimitiveComponentHitDelegate.IsBound())
                    {
                        foundCorrectType = true;
                        component->OnComponentHit.AddDynamic(this, &UTweenFloat::OnPrimitiveComponentHit);
                    }
                }
                
                break;
            }
            default:
            {
                break;
            }
        }

        bHasBoundedFunctions = foundCorrectType;

        if (   bDeleteTweenOnOverlap
            && !foundCorrectType)
        {
            UE_LOG(LogTweenMaker, Warning, TEXT("UTweenFloat::BindDelegates -> DeleteTweenOnOverlap was selected, but the TweenTarget"
                                                "with name %s doesn't derive from an Actor nor a PrimitiveComponent. "
                                                "Ignoring the selection."), *mTargetObject.Get()->GetName());
        }

        if (   bDeleteTweenOnHit
            && !foundCorrectType)
        {
            UE_LOG(LogTweenMaker, Warning, TEXT("UTweenFloat::BindDelegates -> bDeleteTweenOnHit was selected, but the TweenTarget"
                                                "with name %s doesn't derive from an Actor nor a PrimitiveComponent. "
                                                "Ignoring the selection."), *mTargetObject.Get()->GetName());
        }

        if (   (   OnTweenActorBeginOverlap.IsBound()
                || OnTweenActorBeginOverlapDelegate.IsBound())
            && !foundCorrectType)
        {
            UE_LOG(LogTweenMaker, Warning, TEXT("UTweenFloat::BindDelegates -> OnTweenActorBeginOverlap was bound, "
                                                "but the TweenTarget with name %s doesn't derive from an Actor nor a PrimitiveComponent. "
                                                "Ignoring the binding."), *mTargetObject.Get()->GetName());
        }

        if ( (   OnTweenActorHit.IsBound()
             || OnTweenActorHitDelegate.IsBound())
            && !foundCorrectType)
        {
            UE_LOG(LogTweenMaker, Warning, TEXT("UTweenFloat::BindDelegates -> OnTweenActorHit was bound, but the TweenTarget"
                                                "with name %s doesn't derive from an Actor nor a PrimitiveComponent. "
                                                "Ignoring the binding."), *mTargetObject.Get()->GetName());
        }

        if (    (   OnTweenPrimitiveComponentBeginOverlap.IsBound()
                || OnTweenPrimitiveComponentBeginOverlapDelegate.IsBound())
            && !foundCorrectType)
        {
            UE_LOG(LogTweenMaker, Warning, TEXT("UTweenFloat::BindDelegates -> OnTweenPrimitiveComponentBeginOverlap was bound, "
                                                "but the TweenTarget with name %s doesn't derive from an Actor nor a PrimitiveComponent. "
                                                "Ignoring the binding."), *mTargetObject.Get()->GetName());
        }

        if (    (   OnTweenPrimitiveComponentHit.IsBound()
                || OnTweenPrimitiveComponentHitDelegate.IsBound())
            && !foundCorrectType)
        {
            UE_LOG(LogTweenMaker, Warning, TEXT("UTweenFloat::BindDelegates -> OnTweenPrimitiveComponentHit was bound, but the TweenTarget"
                                                "with name %s doesn't derive from an Actor nor a PrimitiveComponent. "
                                                "Ignoring the binding."), *mTargetObject.Get()->GetName());
        }
    }
}

// private ---------------------------------------------------------------------
void UTweenFloat::UnbindDelegates()
{
    if (bHasBoundedFunctions)
    {
        switch (mTweenType)
        {
            case ETweenFloatType::FollowSpline:
            case ETweenFloatType::RotateAroundPoint:
            case ETweenFloatType::Custom:
            {
                if (AActor* actor = Cast<AActor>(mTargetObject))
                {
                    if (   bDeleteTweenOnOverlap
                        || OnTweenActorBeginOverlap.IsBound()
                        || OnTweenActorBeginOverlapDelegate.IsBound())
                    {
                        actor->OnActorBeginOverlap.RemoveAll(this);
                    }

                    if (   bDeleteTweenOnHit
                        || OnTweenActorHit.IsBound()
                        || OnTweenActorHitDelegate.IsBound())
                    {
                        actor->OnActorHit.RemoveAll(this);
                    }
                }
                else if (UPrimitiveComponent *component = Cast<UPrimitiveComponent>(mTargetObject))
                {
                    // I can only bind the event if the tween target is actually a UPrimitiveComponent, not just a USceneComponent
                    if (   bDeleteTweenOnOverlap
                        || OnTweenPrimitiveComponentBeginOverlap.IsBound()
                        || OnTweenPrimitiveComponentBeginOverlapDelegate.IsBound())
                    {
                        component->OnComponentBeginOverlap.RemoveAll(this);
                    }

                    if (   bDeleteTweenOnHit
                        || OnTweenPrimitiveComponentHit.IsBound()
                        || OnTweenPrimitiveComponentHitDelegate.IsBound())
                    {
                        component->OnComponentHit.RemoveAll(this);
                    }
                }
                break;
            }
            default:
            {
                break;
            }
        }

        bHasBoundedFunctions = false;
    }
}

// private ---------------------------------------------------------------------
void UTweenFloat::OnActorBeginOverlap(AActor* pThisActor, AActor* pOtherActor)
{
    if (IsTweening())
    {
        if (OnTweenActorBeginOverlap.IsBound())
        {
            OnTweenActorBeginOverlap.Broadcast(this, pThisActor, pOtherActor);
        }
        else if (OnTweenActorBeginOverlapDelegate.IsBound())
        {
            OnTweenActorBeginOverlapDelegate.Execute(this, pThisActor, pOtherActor);
        }

        if (bDeleteTweenOnOverlap)
        {
            DeleteTween();
        }
    }
}

// private ---------------------------------------------------------------------
void UTweenFloat::OnActorHit(AActor* pThisActor, AActor* pOtherActor, FVector pNormalImpulse, const FHitResult& pHit)
{
    if (IsTweening())
    {
        if (OnTweenActorHit.IsBound())
        {
            OnTweenActorHit.Broadcast(this, pThisActor, pOtherActor, pNormalImpulse, pHit);
        }
        else if (OnTweenActorHitDelegate.IsBound())
        {
            OnTweenActorHitDelegate.Execute(this, pThisActor, pOtherActor, pNormalImpulse, pHit);
        }

        if (bDeleteTweenOnHit)
        {
            DeleteTween();
        }
    }
}

// private ---------------------------------------------------------------------
void UTweenFloat::OnPrimitiveComponentBeginOverlap(UPrimitiveComponent* pThisComponent,
                                                   AActor* pOtherActor,
                                                   UPrimitiveComponent* pOtherComp,
                                                   int32 pOtherBodyIndex,
                                                   bool bFromSweep,
                                                   const FHitResult& pSweepResult)
{
    if (IsTweening())
    {
        if (OnTweenPrimitiveComponentBeginOverlap.IsBound())
        {
            OnTweenPrimitiveComponentBeginOverlap.Broadcast(this, pThisComponent, pOtherActor, pOtherComp, pSweepResult);
        }
        else if (OnTweenPrimitiveComponentBeginOverlapDelegate.IsBound())
        {
            OnTweenPrimitiveComponentBeginOverlapDelegate.Execute(this, pThisComponent, pOtherActor, pOtherComp, pSweepResult);
        }

        if (bDeleteTweenOnOverlap)
        {
            DeleteTween();
        }
    }
}

// private ---------------------------------------------------------------------
void UTweenFloat::OnPrimitiveComponentHit(UPrimitiveComponent* pThisComponent,
                                          AActor* pOtherActor,
                                          UPrimitiveComponent* pOtherComp,
                                          FVector pNormalImpulse,
                                          const FHitResult& pHitResult)
{
    if (IsTweening())
    {
        if (OnTweenPrimitiveComponentHit.IsBound())
        {
            OnTweenPrimitiveComponentHit.Broadcast(this, pThisComponent, pOtherActor, pOtherComp, pNormalImpulse, pHitResult);
        }
        else if (OnTweenPrimitiveComponentHitDelegate.IsBound())
        {
            OnTweenPrimitiveComponentHitDelegate.Execute(this, pThisComponent, pOtherActor, pOtherComp, pNormalImpulse, pHitResult);
        }

        if (bDeleteTweenOnHit)
        {
            DeleteTween();
        }
    }
}
