// Copyright 2018 Francesco Desogus. All Rights Reserved.

#include "Tweens/TweenRotator.h"
#include "TweenFactory/Latent//TweenRotatorLatentFactory.h"
#include "GameFramework/Actor.h"
#include "Utils/Utility.h"
#include "Components/PrimitiveComponent.h"
#include "Kismet/KismetMathLibrary.h"
#include "Utils/EaseEquations.h"

namespace
{
    FQuat ComputeLocalSpaceQuat(const FQuat& baseOffset, const FQuat& currentValue)
    {
        return baseOffset * currentValue * baseOffset.Inverse();
    }
}

// public ----------------------------------------------------------------------
UTweenRotator::UTweenRotator(const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer)
    , mTweenLatentProxy(nullptr)
    , mCurrentValue(FQuat::Identity)
    , mFrom(FQuat::Identity)
    , mTo(FQuat::Identity)
    , mFromRotator(FRotator::ZeroRotator)
    , mToRotator(FRotator::ZeroRotator)
    , mBaseOffset(FQuat::Identity)
    , bDeleteTweenOnHit(false)
    , bDeleteTweenOnOverlap(false)
    , bHasBoundedFunctions(false)
{

}

// public ----------------------------------------------------------------------
void UTweenRotator::Init(const FRotator& pFrom,
                         const FRotator& pTo,
                         ETweenRotatorType pTweenType,
                         ETweenSpace pTweenSpace,
                         ETweenRotationMode pRotationMode,
                         bool pLocalSpace,
                         bool pDeleteTweenOnHit,
                         bool pDeleteTweenOnOverlap,
                         UTweenRotatorLatentFactory* pTweenLatentProxy)
{
    mFrom                 = pFrom.Quaternion();
    mTo                   = pTo.Quaternion();
    mFromRotator          = pFrom;
    mToRotator            = pTo;
    mTweenType            = pTweenType;
    mTweenSpace           = pTweenSpace;
    mRotationMode         = pRotationMode;
    mLocalSpace           = pLocalSpace;
    mTweenLatentProxy     = pTweenLatentProxy;
    bDeleteTweenOnHit     = pDeleteTweenOnHit;
    bDeleteTweenOnOverlap = pDeleteTweenOnOverlap;
    bHasBoundedFunctions  = false;

    mCurrentValue = FQuat::Identity;
    mBaseOffset   = FQuat::Identity;
}

// public ----------------------------------------------------------------------
bool UTweenRotator::Update(float pDeltaTime, float pTimeScale)
{
    Super::Update(pDeltaTime, pTimeScale);

    mElapsedTime += pDeltaTime * pTimeScale * mTimeScaleAbsolute;

    bool hasEnded = mElapsedTime >= mTweenDuration;

    if (hasEnded)
    {
        mCurrentValue = mTo;
    }
    else
    {
        // To rotate I first compute the float for the spherical interpolation
        float alpha = 0;

        if (mCurveFloat)
        {
            alpha = EaseEquations::ComputeCustomFloatEasing(mCurveFloat, mElapsedTime, 0, 1.0f, mTweenDuration);
        }
        else
        {
            alpha = EaseEquations::ComputeFloatEasing(mEaseType, mElapsedTime, 0, 1.0f, mTweenDuration);
        }

        if (mTweenType == ETweenRotatorType::RotateBy)
        {
            float pitch = FMath::Lerp(mFromRotator.Pitch, mToRotator.Pitch, alpha);
            float yaw   = FMath::Lerp(mFromRotator.Yaw, mToRotator.Yaw, alpha);
            float roll  = FMath::Lerp(mFromRotator.Roll, mToRotator.Roll, alpha);

            FRotator rot  = FRotator(pitch, yaw, roll);

            mCurrentValue = rot.Quaternion();
        }
        else
        {
            switch (mRotationMode)
            {
                case ETweenRotationMode::ShortestPath:
                {
                    mCurrentValue = FQuat::Slerp(mFrom, mTo, alpha);
                    break;
                }
                case ETweenRotationMode::FullPath:
                {
                    mCurrentValue = FQuat::SlerpFullPath(mFrom, mTo, alpha);
                    break;
                }
            }
        }
    }

    switch (mTargetType)
    {
        case ETweenTargetType::Actor:
        {
            AActor* actor = Cast<AActor>(mTargetObject);
            UpdateForActor(actor);
            break;
        }
        case ETweenTargetType::SceneComponent:
        {
            USceneComponent* component = Cast<USceneComponent>(mTargetObject);
            UpdateForSceneComponent(component);
            break;
        }
        default:
        {
            break;
        }
    }

    return hasEnded;
}

// protected -------------------------------------------------------------------
void UTweenRotator::PreDelay()
{
    Super::PreDelay();

    BindDelegates();
}

// protected -------------------------------------------------------------------
void UTweenRotator::PrepareTween()
{
    Super::PrepareTween();

    switch (mTweenType)
    {
        case ETweenRotatorType::RotateTo:
        {
            switch (mTargetType)
            {
                case ETweenTargetType::Actor:
                {
                    AActor* actor = Cast<AActor>(mTargetObject);

                    switch (mTweenSpace)
                    {
                        case ETweenSpace::World:
                        {
                            mFrom = actor->GetActorRotation().Quaternion();
                            break;
                        }
                        case ETweenSpace::Relative:
                        {
                            mFrom = actor->GetRootComponent()->GetRelativeRotation().Quaternion();
                            break;
                        }
                        default:
                        {
                            break;
                        }
                    }
                    break;
                }
                case ETweenTargetType::SceneComponent:
                {
                    USceneComponent* sceneComponent = Cast<USceneComponent>(mTargetObject);

                    switch (mTweenSpace)
                    {
                        case ETweenSpace::World:
                        {
                            mFrom = sceneComponent->GetComponentRotation().Quaternion();
                            break;
                        }
                        case ETweenSpace::Relative:
                        {
                            mFrom = sceneComponent->GetRelativeRotation().Quaternion();
                            break;
                        }
                        default:
                        {
                            break;
                        }
                    }
                    break;
                }
                default:
                {
                    break;
                }
            }

            break;
        }
        case ETweenRotatorType::RotateBy:
        {
            mFrom        = FQuat::Identity;
            mFromRotator = FRotator::ZeroRotator;

            switch (mTargetType)
            {
                case ETweenTargetType::Actor:
                {
                    AActor* actor = Cast<AActor>(mTargetObject);
                    mBaseOffset = actor->GetRootComponent()->GetRelativeTransform().GetRotation();
                    break;
                }
                case ETweenTargetType::SceneComponent:
                {
                    USceneComponent* sceneComponent = Cast<USceneComponent>(mTargetObject);
                    mBaseOffset = sceneComponent->GetRelativeTransform().GetRotation();
                    break;
                }
                default:
                {
                    break;
                }
            }

            break;
        }
    }
}

// protected -------------------------------------------------------------------
void UTweenRotator::PositionAt(bool pBeginning)
{
    // Don't bother doing anything if the Tween has not even ever started
    if (bHasPreparedTween)
    {
        // Start again at the from!
        mCurrentValue = pBeginning ? mFrom : mTo;
        
        switch (mTargetType)
        {
            case ETweenTargetType::Actor:
            {
                AActor* actor = Cast<AActor>(mTargetObject);
                UpdateForActor(actor);
                break;
            }
            case ETweenTargetType::SceneComponent:
            {
                USceneComponent* component = Cast<USceneComponent>(mTargetObject);
                UpdateForSceneComponent(component);
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
void UTweenRotator::OnTweenPausedInternal()
{
    Super::OnTweenPausedInternal();
}

// protected -------------------------------------------------------------------
void UTweenRotator::OnTweenResumedInternal()
{
    Super::OnTweenResumedInternal();
}

// protected -------------------------------------------------------------------
void UTweenRotator::OnTweenDeletedInternal()
{
    Super::OnTweenDeletedInternal();

    UnbindDelegates();
}

// protected -------------------------------------------------------------------
void UTweenRotator::Restart(bool pRestartFromEnd)
{
    Super::Restart(pRestartFromEnd);

    if (pRestartFromEnd)
    {
        Swap(mFrom, mTo);
        Swap(mFromRotator, mToRotator);
    }

    mElapsedTime = 0.0f;
}

// protected -------------------------------------------------------------------
void UTweenRotator::Invert(bool pShouldInvertElapsedTime)
{
    Super::Invert(pShouldInvertElapsedTime);

    Swap(mFrom, mTo);
    Swap(mFromRotator, mToRotator);
}

// protected -------------------------------------------------------------------
void UTweenRotator::BroadcastOnTweenStart()
{
    Super::BroadcastOnTweenStart();

    if (mTweenLatentProxy != nullptr)
    {
        mTweenLatentProxy->OnTweenStart.Broadcast(this);
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
void UTweenRotator::BroadcastOnTweenUpdate()
{
    Super::BroadcastOnTweenUpdate();

    if (mTweenLatentProxy != nullptr)
    {
        mTweenLatentProxy->OnTweenUpdate.Broadcast(this);
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
void UTweenRotator::BroadcastOnTweenEnd()
{
    Super::BroadcastOnTweenEnd();

    if (mTweenLatentProxy != nullptr)
    {
        mTweenLatentProxy->OnTweenEnd.Broadcast(this);
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
void UTweenRotator::UpdateForActor(AActor* pTarget)
{
    switch (mTweenType)
    {
        case ETweenRotatorType::RotateTo:
        {
            switch (mTweenSpace)
            {
                case ETweenSpace::World:
                {
                    pTarget->SetActorRotation(mCurrentValue.Rotator());
                    break;
                }
                case ETweenSpace::Relative:
                {
                    pTarget->SetActorRelativeRotation(mCurrentValue.Rotator());
                    break;
                }
                default:
                {
                    break;
                }
            }
            break;
        }
        case ETweenRotatorType::RotateBy:
        {
            FQuat currentValue = mLocalSpace ? ComputeLocalSpaceQuat(mBaseOffset, mCurrentValue) : mCurrentValue;
            pTarget->SetActorRelativeRotation(UKismetMathLibrary::ComposeRotators(mBaseOffset.Rotator(), currentValue.Rotator()));
            break;
        }
        default:
        {
            break;
        }
    }
}

// private ---------------------------------------------------------------------
void UTweenRotator::UpdateForSceneComponent(USceneComponent* pTarget)
{
    switch (mTweenType)
    {
        case ETweenRotatorType::RotateTo:
        {
            switch (mTweenSpace)
            {
                case ETweenSpace::World:
                {
                    pTarget->SetWorldRotation(mCurrentValue.Rotator());
                    break;
                }
                case ETweenSpace::Relative:
                {
                    pTarget->SetRelativeRotation(mCurrentValue.Rotator());
                    break;
                }
                default:
                {
                    break;
                }
            }
            break;
        }
        case ETweenRotatorType::RotateBy:
        {
            FQuat currentValue = mLocalSpace ? ComputeLocalSpaceQuat(mBaseOffset, mCurrentValue) : mCurrentValue;
            pTarget->SetRelativeRotation(UKismetMathLibrary::ComposeRotators(mBaseOffset.Rotator(), currentValue.Rotator()));
            break;
        }
        default:
        {
            break;
        }
    }
}

// private ---------------------------------------------------------------------
void UTweenRotator::BindDelegates()
{
    // Proceed only if no functions were bounded yet
    if (!bHasBoundedFunctions && mTargetObject.IsValid())
    {
        bool foundCorrectType = false;

        switch (mTweenType)
        {
            case ETweenRotatorType::RotateBy:
            case ETweenRotatorType::RotateTo:
            {
                if (AActor* actor = Cast<AActor>(mTargetObject))
                {
                    if (  bDeleteTweenOnOverlap
                        || OnTweenActorBeginOverlap.IsBound()
                        || OnTweenActorBeginOverlapDelegate.IsBound())
                    {
                        foundCorrectType = true;
                        actor->OnActorBeginOverlap.AddDynamic(this, &UTweenRotator::OnActorBeginOverlap);
                    }

                    if (   bDeleteTweenOnHit
                        || OnTweenActorHit.IsBound()
                        || OnTweenActorHitDelegate.IsBound())
                    {
                        foundCorrectType = true;
                        actor->OnActorHit.AddDynamic(this, &UTweenRotator::OnActorHit);
                    }
                }
                else if (UPrimitiveComponent* component = Cast<UPrimitiveComponent>(mTargetObject))
                {
                    // I can only bind the event if the tween target is actually a UPrimitiveComponent, not just a USceneComponent
                    if (   bDeleteTweenOnOverlap
                        || OnTweenPrimitiveComponentBeginOverlap.IsBound()
                        || OnTweenPrimitiveComponentBeginOverlapDelegate.IsBound())
                    {
                        foundCorrectType = true;
                        component->OnComponentBeginOverlap.AddDynamic(this, &UTweenRotator::OnPrimitiveComponentBeginOverlap);
                    }

                    if (   bDeleteTweenOnHit
                        || OnTweenPrimitiveComponentHit.IsBound()
                        || OnTweenPrimitiveComponentHitDelegate.IsBound())
                    {
                        foundCorrectType = true;
                        component->OnComponentHit.AddDynamic(this, &UTweenRotator::OnPrimitiveComponentHit);
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
            UE_LOG(LogTweenMaker, Warning, TEXT("UTweenRotator::BindDelegates -> DeleteTweenOnOverlap was selected, but the TweenTarget"
                                                "with name %s doesn't derive from an Actor nor a PrimitiveComponent. "
                                                "Ignoring the selection."), *mTargetObject.Get()->GetName());
        }

        if (   bDeleteTweenOnHit
            && !foundCorrectType)
        {
            UE_LOG(LogTweenMaker, Warning, TEXT("UTweenRotator::BindDelegates -> bDeleteTweenOnHit was selected, but the TweenTarget"
                                                "with name %s doesn't derive from an Actor nor a PrimitiveComponent. "
                                                "Ignoring the selection."), *mTargetObject.Get()->GetName());
        }

        if (   (   OnTweenActorBeginOverlap.IsBound()
                || OnTweenActorBeginOverlapDelegate.IsBound())
            && !foundCorrectType)
        {
            UE_LOG(LogTweenMaker, Warning, TEXT("UTweenRotator::BindDelegates -> OnTweenActorBeginOverlap was bound, "
                                                "but the TweenTarget with name %s doesn't derive from an Actor nor a PrimitiveComponent. "
                                                "Ignoring the binding."), *mTargetObject.Get()->GetName());
        }

        if (   (  OnTweenActorHit.IsBound()
               || OnTweenActorHitDelegate.IsBound())
            && !foundCorrectType)
        {
            UE_LOG(LogTweenMaker, Warning, TEXT("UTweenRotator::BindDelegates -> OnTweenActorHit was bound, but the TweenTarget"
                                                "with name %s doesn't derive from an Actor nor a PrimitiveComponent. "
                                                "Ignoring the binding."), *mTargetObject.Get()->GetName());
        }

        if (   (   OnTweenPrimitiveComponentBeginOverlap.IsBound()
                || OnTweenPrimitiveComponentBeginOverlapDelegate.IsBound())
            && !foundCorrectType)
        {
            UE_LOG(LogTweenMaker, Warning, TEXT("UTweenRotator::BindDelegates -> OnTweenPrimitiveComponentBeginOverlap was bound, "
                                                "but the TweenTarget with name %s doesn't derive from an Actor nor a PrimitiveComponent. "
                                                "Ignoring the binding."), *mTargetObject.Get()->GetName());
        }

        if (  (   OnTweenPrimitiveComponentHit.IsBound()
               || OnTweenPrimitiveComponentHitDelegate.IsBound())
            && !foundCorrectType)
        {
            UE_LOG(LogTweenMaker, Warning, TEXT("UTweenRotator::BindDelegates -> OnTweenPrimitiveComponentHit was bound, but the TweenTarget"
                                                "with name %s doesn't derive from an Actor nor a PrimitiveComponent. "
                                                "Ignoring the binding."), *mTargetObject.Get()->GetName());
        }
    }
}

// private ---------------------------------------------------------------------
void UTweenRotator::UnbindDelegates()
{
    if (bHasBoundedFunctions)
    {
        switch (mTweenType)
        {
            case ETweenRotatorType::RotateBy:
            case ETweenRotatorType::RotateTo:
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
                else if (UPrimitiveComponent* component = Cast<UPrimitiveComponent>(mTargetObject))
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
void UTweenRotator::OnActorBeginOverlap(AActor* pThisActor, AActor* pOtherActor)
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
void UTweenRotator::OnActorHit(AActor* pThisActor,
                               AActor* pOtherActor,
                               FVector pNormalImpulse,
                               const FHitResult& pHit)
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
void UTweenRotator::OnPrimitiveComponentBeginOverlap(UPrimitiveComponent* pThisComponent,
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
void UTweenRotator::OnPrimitiveComponentHit(UPrimitiveComponent* pThisComponent,
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