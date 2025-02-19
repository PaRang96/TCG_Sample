// Copyright 2018 Francesco Desogus. All Rights Reserved.

#include "Tweens/TweenVector.h"
#include "TweenFactory/Latent//TweenVectorLatentFactory.h"
#include "GameFramework/Actor.h"
#include "Utils/Utility.h"
#include "Components/PrimitiveComponent.h"
#include "Utils/EaseEquations.h"
#include "Curves/CurveFloat.h"

// public ----------------------------------------------------------------------
UTweenVector::UTweenVector(const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer)
    , mTweenLatentProxy(nullptr)
    , mCurrentValue(FVector(0, 0, 0))
    , mFrom(FVector(0, 0, 0))
    , mTo(FVector(0, 0, 0))
    , bDeleteTweenOnHit(false)
    , bDeleteTweenOnOverlap(false)
    , bHasBoundedFunctions(false)
{

}

// public ----------------------------------------------------------------------
void UTweenVector::Init(const FVector& pFrom,
                        const FVector& pTo,
                        ETweenVectorType pTweenType,
                        ETweenSpace pTweenSpace,
                        bool pDeleteTweenOnHit,
                        bool pDeleteTweenOnOverlap,
                        UTweenVectorLatentFactory* pTweenLatentProxy)
{
    mFrom                 = pFrom;
    mTo                   = pTo;
    mTweenType            = pTweenType;
    mTweenSpace           = pTweenSpace;
    mTweenLatentProxy     = pTweenLatentProxy;
    bDeleteTweenOnHit     = pDeleteTweenOnHit;
    bDeleteTweenOnOverlap = pDeleteTweenOnOverlap;
    bHasBoundedFunctions  = false;

    mCurrentValue = FVector(0, 0, 0);
    mBaseOffset   = FVector(0, 0, 0);
}

// public ----------------------------------------------------------------------
bool UTweenVector::Update(float pDeltaTime, float pTimeScale)
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
        if (mCurveFloat)
        {
            EaseEquations::ComputeCustomVectorEasing(mCurveFloat, mElapsedTime, mFrom, mTo, mTweenDuration, mCurrentValue);
        }
        else
        {
            EaseEquations::ComputeVectorEasing(mEaseType, mElapsedTime, mFrom, mTo, mTweenDuration, mCurrentValue);
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
void UTweenVector::PreDelay()
{
    Super::PreDelay();

    BindDelegates();
}

// protected -------------------------------------------------------------------
void UTweenVector::PrepareTween()
{
    Super::PrepareTween();

    switch (mTweenType)
    {
        case ETweenVectorType::MoveTo:
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
                            mFrom = actor->GetActorLocation();
                            break;
                        }
                        case ETweenSpace::Relative:
                        {
                            mFrom = actor->GetRootComponent()->GetRelativeLocation();
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
                            mFrom = sceneComponent->GetComponentLocation();
                            break;
                        }
                        case ETweenSpace::Relative:
                        {
                            mFrom = sceneComponent->GetRelativeLocation();
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
        case ETweenVectorType::MoveBy:
        {
            switch (mTargetType)
            {
                case ETweenTargetType::Actor:
                {
                    AActor* actor = Cast<AActor>(mTargetObject);
                    mFrom = FVector(0, 0, 0);
                    mBaseOffset = actor->GetRootComponent()->GetRelativeTransform().GetLocation();
                    break;
                }
                case ETweenTargetType::SceneComponent:
                {
                    USceneComponent* sceneComponent = Cast<USceneComponent>(mTargetObject);
                    mFrom = FVector(0, 0, 0);
                    mBaseOffset = sceneComponent->GetRelativeTransform().GetLocation();
                    break;
                }
                default:
                {
                    break;
                }
            }

            break;
        }
        case ETweenVectorType::ScaleTo:
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
                            mFrom = actor->GetActorScale3D();
                            break;
                        }
                        case ETweenSpace::Relative:
                        {
                            mFrom = actor->GetActorRelativeScale3D();
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
                            mFrom = sceneComponent->GetComponentScale();
                            break;
                        }
                        case ETweenSpace::Relative:
                        {
                            mFrom = sceneComponent->GetRelativeScale3D();
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
        case ETweenVectorType::ScaleBy:
        {
            switch (mTargetType)
            {
                case ETweenTargetType::Actor:
                {
                    AActor* actor = Cast<AActor>(mTargetObject);
                    mFrom = FVector(0, 0, 0);
                    mBaseOffset = actor->GetActorRelativeScale3D();
                    break;
                }
                case ETweenTargetType::SceneComponent:
                {
                    USceneComponent* sceneComponent = Cast<USceneComponent>(mTargetObject);
                    mFrom = FVector(0, 0, 0);
                    mBaseOffset = sceneComponent->GetRelativeTransform().GetScale3D();
                    break;
                }
                default:
                {
                    break;
                }
            }

            break;
        }
        case ETweenVectorType::Custom:
        {
            // Does nothing
            break;
        }
        default:
        {
            break;
        }
    }
}

// protected -------------------------------------------------------------------
void UTweenVector::PositionAt(bool pBeginning)
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
void UTweenVector::OnTweenPausedInternal()
{
    Super::OnTweenPausedInternal();
}

// protected -------------------------------------------------------------------
void UTweenVector::OnTweenResumedInternal()
{
    Super::OnTweenResumedInternal();
}

// protected -------------------------------------------------------------------
void UTweenVector::OnTweenDeletedInternal()
{
    Super::OnTweenDeletedInternal();

    // Unbinding the OnHit/OnOverlap delegates if present
    UnbindDelegates();
}

// protected -------------------------------------------------------------------
void UTweenVector::Restart(bool pRestartFromEnd)
{
    Super::Restart(pRestartFromEnd);

    if (pRestartFromEnd)
    {
        Swap(mFrom, mTo);
    }

    mElapsedTime = 0.0f;
}

// protected -------------------------------------------------------------------
void UTweenVector::Invert(bool pShouldInvertElapsedTime)
{
    Super::Invert(pShouldInvertElapsedTime);

    Swap(mFrom, mTo);
}

// protected -------------------------------------------------------------------
void UTweenVector::BroadcastOnTweenStart()
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

    // Binding the OnHit/OnOverlap delegates if present and not yet bounded
    BindDelegates();
}

// protected -------------------------------------------------------------------
void UTweenVector::BroadcastOnTweenUpdate()
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
void UTweenVector::BroadcastOnTweenEnd()
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
void UTweenVector::UpdateForActor(AActor* pTarget)
{
    switch (mTweenType)
    {
        case ETweenVectorType::MoveTo:
        {
            switch (mTweenSpace)
            {
                case ETweenSpace::World:
                {
                    pTarget->SetActorLocation(mCurrentValue, bHasBoundedFunctions);
                    break;
                }
                case ETweenSpace::Relative:
                {
                    pTarget->SetActorRelativeLocation(mCurrentValue, bHasBoundedFunctions);
                    break;
                }
                default:
                {
                    break;
                }
            }
            break;
        }
        case ETweenVectorType::MoveBy:
        {
            pTarget->SetActorRelativeLocation(mCurrentValue + mBaseOffset, bHasBoundedFunctions);
            break;
        }
        case ETweenVectorType::ScaleTo:
        {
            switch (mTweenSpace)
            {
                case ETweenSpace::World:
                {
                    pTarget->SetActorScale3D(mCurrentValue);
                    break;
                }
                case ETweenSpace::Relative:
                {
                    pTarget->SetActorRelativeScale3D(mCurrentValue);
                    break;
                }
                default:
                {
                    break;
                }
            }
            break;
        }
        case ETweenVectorType::ScaleBy:
        {
            pTarget->SetActorRelativeScale3D(mCurrentValue + mBaseOffset);
            break;
        }
        case ETweenVectorType::Custom:
        {
            // Does nothing
            break;
        }
        default:
        {
            break;
        }
    }
}

// private ---------------------------------------------------------------------
void UTweenVector::UpdateForSceneComponent(USceneComponent* pTarget)
{
    switch (mTweenType)
    {
        case ETweenVectorType::MoveTo:
        {
            switch (mTweenSpace)
            {
                case ETweenSpace::World:
                {
                    pTarget->SetWorldLocation(mCurrentValue);
                    break;
                }
                case ETweenSpace::Relative:
                {
                    pTarget->SetRelativeLocation(mCurrentValue);
                    break;
                }
                default:
                {
                    break;
                }
            }
            break;
        }
        case ETweenVectorType::MoveBy:
        {
            pTarget->SetRelativeLocation(mCurrentValue + mBaseOffset/*, true*/);
            break;
        }
        case ETweenVectorType::ScaleTo:
        {
            switch (mTweenSpace)
            {
                case ETweenSpace::World:
                {
                    pTarget->SetWorldScale3D(mCurrentValue);
                    break;
                }
                case ETweenSpace::Relative:
                {
                    pTarget->SetRelativeScale3D(mCurrentValue);
                    break;
                }
                default:
                {
                    break;
                }
            }
            break;
        }
        case ETweenVectorType::ScaleBy:
        {
            pTarget->SetRelativeScale3D(mCurrentValue + mBaseOffset);
            break;
        }
        case ETweenVectorType::Custom:
        {
            // Does nothing
            break;
        }
        default:
        {
            break;
        }
    }
}

// private ---------------------------------------------------------------------
void UTweenVector::BindDelegates()
{
    if (!bHasBoundedFunctions && mTargetObject.IsValid())
    {
        bool foundCorrectType = false;

        switch (mTweenType)
        {
            case ETweenVectorType::MoveTo:
            case ETweenVectorType::MoveBy:
            case ETweenVectorType::ScaleTo:
            case ETweenVectorType::ScaleBy:
            case ETweenVectorType::Custom:
            {
                if (AActor* actor = Cast<AActor>(mTargetObject))
                {
                    if (   bDeleteTweenOnOverlap
                        || OnTweenActorBeginOverlap.IsBound()
                        || OnTweenActorBeginOverlapDelegate.IsBound())
                    {
                        foundCorrectType = true;
                        actor->OnActorBeginOverlap.AddDynamic(this, &UTweenVector::OnActorBeginOverlap);
                    }

                    if (   bDeleteTweenOnHit
                        || OnTweenActorHit.IsBound()
                        || OnTweenActorHitDelegate.IsBound())
                    {
                        foundCorrectType = true;
                        actor->OnActorHit.AddDynamic(this, &UTweenVector::OnActorHit);
                    }
                }
                else if (UPrimitiveComponent* component = Cast<UPrimitiveComponent>(mTargetObject))
                {
                    if (   bDeleteTweenOnOverlap
                        || OnTweenPrimitiveComponentBeginOverlap.IsBound()
                        || OnTweenPrimitiveComponentBeginOverlapDelegate.IsBound())
                    {
                        foundCorrectType = true;
                        component->OnComponentBeginOverlap.AddDynamic(this, &UTweenVector::OnPrimitiveComponentBeginOverlap);
                    }

                    if (   bDeleteTweenOnHit
                        || OnTweenPrimitiveComponentHit.IsBound()
                        || OnTweenPrimitiveComponentHitDelegate.IsBound())
                    {
                        foundCorrectType = true;
                        component->OnComponentHit.AddDynamic(this, &UTweenVector::OnPrimitiveComponentHit);
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

        if (   bDeleteTweenOnHit
            && !foundCorrectType)
        {
            UE_LOG(LogTweenMaker, Warning, TEXT("UTweenVector::BindDelegates -> DeleteTweenOnHit was selected, but the TweenTarget"
                                                "with name %s doesn't derive from an Actor nor a PrimitiveComponent. "
                                                "Ignoring the selection."), *mTargetObject.Get()->GetName());
        }

        if (   bDeleteTweenOnOverlap
            && !foundCorrectType)
        {
            UE_LOG(LogTweenMaker, Warning, TEXT("UTweenVector::BindDelegates -> DeleteTweenOnOverlap was selected, but the TweenTarget"
                                                "with name %s doesn't derive from an Actor nor a PrimitiveComponent. "
                                                "Ignoring the selection."), *mTargetObject.Get()->GetName());
        }

        if (   (  OnTweenActorBeginOverlap.IsBound()
               || OnTweenActorBeginOverlapDelegate.IsBound())
            && !foundCorrectType)
        {
            UE_LOG(LogTweenMaker, Warning, TEXT("UTweenVector::BindDelegates -> OnTweenActorBeginOverlap was bound, "
                                                "but the TweenTarget with name %s doesn't derive from an Actor nor a PrimitiveComponent. "
                                                "Ignoring the binding."), *mTargetObject.Get()->GetName());
        }

        if (   (   OnTweenActorHit.IsBound()
                || OnTweenActorHitDelegate.IsBound())
            && !foundCorrectType)
        {
            UE_LOG(LogTweenMaker, Warning, TEXT("UTweenVector::BindDelegates -> OnTweenActorHit was bound, but the TweenTarget"
                                                "with name %s doesn't derive from an Actor nor a PrimitiveComponent. "
                                                "Ignoring the binding."), *mTargetObject.Get()->GetName());
        }

        if (   (   OnTweenPrimitiveComponentBeginOverlap.IsBound()
                || OnTweenPrimitiveComponentBeginOverlapDelegate.IsBound())
            && !foundCorrectType)
        {
            UE_LOG(LogTweenMaker, Warning, TEXT("UTweenVector::BindDelegates -> OnTweenPrimitiveComponentBeginOverlap was bound, "
                                                "but the TweenTarget with name %s doesn't derive from an Actor nor a PrimitiveComponent. "
                                                "Ignoring the binding."), *mTargetObject.Get()->GetName());
        }

        if (   (   OnTweenPrimitiveComponentHit.IsBound()
                || OnTweenPrimitiveComponentHitDelegate.IsBound())
            && !foundCorrectType)
        {
            UE_LOG(LogTweenMaker, Warning, TEXT("UTweenVector::BindDelegates -> OnTweenPrimitiveComponentHit was bound, but the TweenTarget"
                                                "with name %s doesn't derive from an Actor nor a PrimitiveComponent. "
                                                "Ignoring the binding."), *mTargetObject.Get()->GetName());
        }
    }
}

// private ---------------------------------------------------------------------
void UTweenVector::UnbindDelegates()
{
    if (bHasBoundedFunctions)
    {
        switch (mTweenType)
        {
            case ETweenVectorType::MoveTo:
            case ETweenVectorType::MoveBy:
            case ETweenVectorType::ScaleTo:
            case ETweenVectorType::ScaleBy:
            case ETweenVectorType::Custom:
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
void UTweenVector::OnActorBeginOverlap(AActor* pThisActor, AActor* pOtherActor)
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
void UTweenVector::OnActorHit(AActor* pThisActor, AActor* pOtherActor, FVector pNormalImpulse, const FHitResult& pHit)
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
void UTweenVector::OnPrimitiveComponentBeginOverlap(UPrimitiveComponent* pThisComponent,
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
void UTweenVector::OnPrimitiveComponentHit(UPrimitiveComponent* pThisComponent,
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