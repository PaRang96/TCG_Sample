// Copyright 2018 Francesco Desogus. All Rights Reserved.

#include "Tweens/BaseTween.h"
#include "Tweens/TweenVector.h"
#include "TweenContainer.h"
#include "TweenFactory/Standard/TweenVectorStandardFactory.h"
#include "TweenFactory/Standard/TweenVector2DStandardFactory.h"
#include "TweenFactory/Standard/TweenRotatorStandardFactory.h"
#include "TweenFactory/Standard/TweenLinearColorStandardFactory.h"
#include "TweenFactory/Standard/TweenFloatStandardFactory.h"
#include "Curves/CurveFloat.h"

// public ----------------------------------------------------------------------
UBaseTween::UBaseTween(const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer)
    , mTweenName(NAME_None)
    , mTweenDuration(0.0f)
    , mElapsedTime(0.0f)
    , mTargetObject(nullptr)
    , mTargetType(ETweenTargetType::Custom)
    , mEaseType(ETweenEaseType::Linear)
    , mNumLoops(1)
    , mLoopType(ETweenLoopType::Yoyo)
    , mTimeScale(1.0f)
    , mCurveFloat(nullptr)
    , bTweenWhileGameIsPaused(false)
    , bHasPreparedTween(false)
    , mTweenGenericType(ETweenGenericType::Any)
    , mDelay(0.0f)
    , mDelayElapsedTime(0.0f)
    , bHasCalledPreDelay(false)
    , bShouldInvertTweenFromStart(false)
    , bIsTweenDone(false)
    , bIsTweenPaused(false)
    , bShouldSkipTween(false)
    , bIsPendingDeletion(false)
{

}

// public ----------------------------------------------------------------------
void UBaseTween::BeginDestroy()
{
    PreDestroy();

    Super::BeginDestroy();
}

// public ----------------------------------------------------------------------
void UBaseTween::InitBase(UTweenContainer* pTweenContainer,
                          int32 pSequenceIndex,
                          TWeakObjectPtr<UObject> pTargetObject,
                          ETweenTargetType pTargetType,
                          ETweenEaseType pEaseType,
                          float pDuration,
                          float pDelay,
                          float pTimeScale,
                          bool pTweenWhileGameIsPaused,
                          int32 pNumLoops,
                          ETweenLoopType pLoopType)
{
    mOwningTweenContainer   = pTweenContainer;
    mTweenSequenceIndex     = pSequenceIndex >= 0 ? pSequenceIndex : 0;
    mTargetObject           = pTargetObject;
    mTargetType             = pTargetType;
    mEaseType               = pEaseType;
    mLoopType               = pLoopType;
    mTweenDuration          = pDuration;
    mNumLoops               = pNumLoops;
    mDelay                  = pDelay;
    mTimeScale              = pTimeScale;
    mTimeScaleAbsolute      = FMath::Abs(mTimeScale);
    mTweenGenericType       = ETweenGenericType::Any;
    bTweenWhileGameIsPaused = pTweenWhileGameIsPaused;

    mElapsedTime      = 0.0f;
    mDelayElapsedTime = 0.0f;

    bIsTweenDone                = false;
    bIsTweenPaused              = false;
    bShouldSkipTween            = false,
    bIsPendingDeletion          = false;
    bHasPreparedTween           = false;
    bHasCalledPreDelay          = false;
    bShouldInvertTweenFromStart = false;
}

// public ----------------------------------------------------------------------
bool UBaseTween::UpdateTween(float pDeltaTime, float pTimeScale)
{
    // I execute the update if this tween is NOT going to be deleted soon
    bool hasEnded = bIsPendingDeletion;

    // If there is a delay, I increment the elapsed time and return
    if (mDelayElapsedTime < mDelay)
    {
        // If the PreDelay method wasn't already called, do it
        if (!bHasCalledPreDelay)
        {
            PreDelay();
        }

        mDelayElapsedTime += pDeltaTime;
    }
    // If the tween is not ending, I continue
    else if (!hasEnded)
    {
        // If by any chance the tween target isn't valid anymore (e.g. actor removed from the level) I'll just remove the tween and return
        if (!mTargetObject.IsValid())
        {
            DeleteTween();
            return true;
        }

        // If this is the elapsed time is 0, the Tween is starting. Need to broadcast the event and prepare the tween.
        if (mElapsedTime <= 0)
        {
            BroadcastOnTweenStart();

            // I only prepare the Tween once in its lifetime (so it's not executed again if it loops)
            if (!bHasPreparedTween)
            {
                PrepareTween();
                bHasPreparedTween = true;

                if (bShouldInvertTweenFromStart)
                {
                    Invert(false);
                }
            }
        }

        // Handling the actual update
        hasEnded = Update(pDeltaTime, pTimeScale);

        // Always broadcast the "update" event, even if the Tween is ending. This way the user 
        // can receive "one last" update event before ending
        BroadcastOnTweenUpdate();

        if (hasEnded)
        {
            BroadcastOnTweenEnd();
            bIsTweenDone = true;
        }
    }

    return hasEnded;
}

// private ---------------------------------------------------------------------
void UBaseTween::PreDestroy()
{
    // Only fire the event if there is valid name (since for now the delegate only does something if that happens)
    if (mTweenName != NAME_None)
    {
        OnTweenDestroyed.Broadcast(this);
    }
}

// public ----------------------------------------------------------------------
void UBaseTween::SetTweenName(FName pTweenName)
{
    OnNameChanged.Broadcast(this, mTweenName, pTweenName);
    mTweenName = pTweenName;
}

// public ----------------------------------------------------------------------
void UBaseTween::DeleteTween(bool pFireEndEvent, ESnapMode pSnapMode)
{
    bIsPendingDeletion = true;

    switch (pSnapMode)
    {
        case ESnapMode::SnapToBeginning:
        {
            PositionAt(true);
            break;
        }
        case ESnapMode::SnapToEnd:
        {
            PositionAt(false);
            break;
        }
        case ESnapMode::None:
        default:
        {
            break;
        }
    }

    if (pFireEndEvent)
    {
        BroadcastOnTweenEnd();
    }

    OnTweenDeletedInternal();
}

// public ----------------------------------------------------------------------
void UBaseTween::PauseTween(bool pSkipTween)
{
    bIsTweenPaused = true;
    bShouldSkipTween = pSkipTween;

    OnTweenPausedInternal();
}

// public ----------------------------------------------------------------------
void UBaseTween::TogglePauseTween(bool pSkipTween)
{
    bIsTweenPaused = !bIsTweenPaused;

    if (bIsTweenPaused)
    {
        bShouldSkipTween = pSkipTween;
        OnTweenPausedInternal();
    }
    else
    {
        OnTweenResumedInternal();
    }
}

// public ----------------------------------------------------------------------
void UBaseTween::RestartTween()
{
    bIsTweenPaused = false;
    mElapsedTime = 0.0f;
    bIsTweenDone = false;
}

// public ----------------------------------------------------------------------
void UBaseTween::ResumeTween()
{
    bIsTweenPaused = false;
    bShouldSkipTween = false;

    OnTweenResumedInternal();
}

// public ----------------------------------------------------------------------
void UBaseTween::SetDelay(float NewDelay)
{
    mDelay = NewDelay;
}

// public ----------------------------------------------------------------------
void UBaseTween::SetTimeScale(float pNewTimeScale)
{
    // If one of them is negative, the result will be negative, meaning that there is a sign difference:
    // in that case we need to invert the Tween
    if (pNewTimeScale * mTimeScale < 0)
    {
        Invert();
    }

    mTimeScale = pNewTimeScale;
    mTimeScaleAbsolute = FMath::Abs(mTimeScale);
}

// public ----------------------------------------------------------------------
void UBaseTween::SetCustomEasisng(UCurveFloat *Curve)
{
    mCurveFloat = Curve;
}

// public ----------------------------------------------------------------------
UTweenVector* UBaseTween::AppendTweenMoveActorTo(AActor* pTweenTarget,
                                                 FVector pTo,
                                                 float pDuration,
                                                 ETweenEaseType pEaseType,
                                                 ETweenSpace pTweenSpace,
                                                 bool pDeleteTweenOnHit,
                                                 bool pDeleteTweenOnOverlap,
                                                 int32 pNumLoops,
                                                 ETweenLoopType pLoopType,
                                                 float pDelay,
                                                 float pTimeScale,
                                                 bool pTweenWhileGameIsPaused)
{
    int32 newSequenceIndex = mTweenSequenceIndex + 1;
    return UTweenVectorStandardFactory::BP_AppendTweenMoveActorTo(mOwningTweenContainer,
                                                                  pTweenTarget,
                                                                  pTo,
                                                                  pDuration,
                                                                  pEaseType,
                                                                  pTweenSpace,
                                                                  pDeleteTweenOnHit,
                                                                  pDeleteTweenOnOverlap,
                                                                  pNumLoops,
                                                                  pLoopType,
                                                                  pDelay,
                                                                  pTimeScale,
                                                                  pTweenWhileGameIsPaused,
                                                                  newSequenceIndex);
}

// public ----------------------------------------------------------------------
UTweenVector* UBaseTween::AppendTweenMoveActorBy(AActor* pTweenTarget,
                                                 FVector pBy,
                                                 float pDuration,
                                                 ETweenEaseType pEaseType,
                                                 bool pDeleteTweenOnHit,
                                                 bool pDeleteTweenOnOverlap,
                                                 int32 pNumLoops,
                                                 ETweenLoopType pLoopType,
                                                 float pDelay,
                                                 float pTimeScale,
                                                 bool pTweenWhileGameIsPaused)
{
    int32 newSequenceIndex = mTweenSequenceIndex + 1;
    return UTweenVectorStandardFactory::BP_AppendTweenMoveActorBy(mOwningTweenContainer,
                                                                  pTweenTarget,
                                                                  pBy,
                                                                  pDuration,
                                                                  pEaseType,
                                                                  pDeleteTweenOnHit,
                                                                  pDeleteTweenOnOverlap,
                                                                  pNumLoops,
                                                                  pLoopType,
                                                                  pDelay,
                                                                  pTimeScale,
                                                                  pTweenWhileGameIsPaused,
                                                                  newSequenceIndex);
}

// public ----------------------------------------------------------------------
UTweenVector* UBaseTween::AppendTweenScaleActorTo(AActor* pTweenTarget,
                                                  FVector pTo,
                                                  float pDuration,
                                                  ETweenEaseType pEaseType,
                                                  ETweenSpace pTweenSpace,
                                                  bool pDeleteTweenOnHit,
                                                  bool pDeleteTweenOnOverlap,
                                                  int32 pNumLoops,
                                                  ETweenLoopType pLoopType,
                                                  float pDelay,
                                                  float pTimeScale,
                                                  bool pTweenWhileGameIsPaused)
{
    int32 newSequenceIndex = mTweenSequenceIndex + 1;
    return UTweenVectorStandardFactory::BP_AppendTweenScaleActorTo(mOwningTweenContainer,
                                                                   pTweenTarget,
                                                                   pTo,
                                                                   pDuration,
                                                                   pEaseType,
                                                                   pTweenSpace,
                                                                   pDeleteTweenOnHit,
                                                                   pDeleteTweenOnOverlap,
                                                                   pNumLoops,
                                                                   pLoopType,
                                                                   pDelay,
                                                                   pTimeScale,
                                                                   pTweenWhileGameIsPaused,
                                                                   newSequenceIndex);
}

// public ----------------------------------------------------------------------
UTweenVector* UBaseTween::AppendTweenScaleActorBy(AActor* pTweenTarget,
                                                  FVector pBy,
                                                  float pDuration,
                                                  ETweenEaseType pEaseType,
                                                  bool pDeleteTweenOnHit,
                                                  bool pDeleteTweenOnOverlap,
                                                  int32 pNumLoops,
                                                  ETweenLoopType pLoopType,
                                                  float pDelay,
                                                  float pTimeScale,
                                                  bool pTweenWhileGameIsPaused)
{
    int32 newSequenceIndex = mTweenSequenceIndex + 1;
    return UTweenVectorStandardFactory::BP_AppendTweenScaleActorBy(mOwningTweenContainer,
                                                                   pTweenTarget,
                                                                   pBy,
                                                                   pDuration,
                                                                   pEaseType,
                                                                   pDeleteTweenOnHit,
                                                                   pDeleteTweenOnOverlap,
                                                                   pNumLoops,
                                                                   pLoopType,
                                                                   pDelay,
                                                                   pTimeScale,
                                                                   pTweenWhileGameIsPaused,
                                                                   newSequenceIndex);
}

// public ----------------------------------------------------------------------
UTweenVector* UBaseTween::AppendTweenMoveSceneComponentTo(USceneComponent* pTweenTarget,
                                                          FVector pTo,
                                                          float pDuration,
                                                          ETweenEaseType pEaseType,
                                                          ETweenSpace pTweenSpace,
                                                          bool pDeleteTweenOnHit,
                                                          bool pDeleteTweenOnOverlap,
                                                          int32 pNumLoops,
                                                          ETweenLoopType pLoopType,
                                                          float pDelay,
                                                          float pTimeScale,
                                                          bool pTweenWhileGameIsPaused)
{
    int32 newSequenceIndex = mTweenSequenceIndex + 1;
    return UTweenVectorStandardFactory::BP_AppendTweenMoveSceneComponentTo(mOwningTweenContainer,
                                                                           pTweenTarget,
                                                                           pTo,
                                                                           pDuration,
                                                                           pEaseType,
                                                                           pTweenSpace,
                                                                           pDeleteTweenOnHit,
                                                                           pDeleteTweenOnOverlap,
                                                                           pNumLoops,
                                                                           pLoopType,
                                                                           pDelay,
                                                                           pTimeScale,
                                                                           pTweenWhileGameIsPaused,
                                                                           newSequenceIndex);
}

// public ----------------------------------------------------------------------
UTweenVector* UBaseTween::AppendTweenMoveSceneComponentBy(USceneComponent* pTweenTarget,
                                                          FVector pBy,
                                                          float pDuration,
                                                          ETweenEaseType pEaseType,
                                                          bool pDeleteTweenOnHit,
                                                          bool pDeleteTweenOnOverlap,
                                                          int32 pNumLoops,
                                                          ETweenLoopType pLoopType,
                                                          float pDelay,
                                                          float pTimeScale,
                                                          bool pTweenWhileGameIsPaused)
{
    int32 newSequenceIndex = mTweenSequenceIndex + 1;
    return UTweenVectorStandardFactory::BP_AppendTweenMoveSceneComponentBy(mOwningTweenContainer,
                                                                           pTweenTarget,
                                                                           pBy,
                                                                           pDuration,
                                                                           pEaseType,
                                                                           pDeleteTweenOnHit,
                                                                           pDeleteTweenOnOverlap,
                                                                           pNumLoops,
                                                                           pLoopType,
                                                                           pDelay,
                                                                           pTimeScale,
                                                                           pTweenWhileGameIsPaused,
                                                                           newSequenceIndex);
}

// public ----------------------------------------------------------------------
UTweenVector* UBaseTween::AppendTweenScaleSceneComponentTo(USceneComponent* pTweenTarget,
                                                           FVector pTo,
                                                           float pDuration,
                                                           ETweenEaseType pEaseType,
                                                           ETweenSpace pTweenSpace,
                                                           bool pDeleteTweenOnHit,
                                                           bool pDeleteTweenOnOverlap,
                                                           int32 pNumLoops,
                                                           ETweenLoopType pLoopType,
                                                           float pDelay,
                                                           float pTimeScale,
                                                           bool pTweenWhileGameIsPaused)
{
    int32 newSequenceIndex = mTweenSequenceIndex + 1;
    return UTweenVectorStandardFactory::BP_AppendTweenScaleSceneComponentTo(mOwningTweenContainer,
                                                                            pTweenTarget,
                                                                            pTo,
                                                                            pDuration,
                                                                            pEaseType,
                                                                            pTweenSpace,
                                                                            pDeleteTweenOnHit,
                                                                            pDeleteTweenOnOverlap,
                                                                            pNumLoops,
                                                                            pLoopType,
                                                                            pDelay,
                                                                            pTimeScale,
                                                                            pTweenWhileGameIsPaused,
                                                                            newSequenceIndex);
}

// public ----------------------------------------------------------------------
UTweenVector* UBaseTween::AppendTweenScaleSceneComponentBy(USceneComponent* pTweenTarget,
                                                           FVector pBy,
                                                           float pDuration,
                                                           ETweenEaseType pEaseType,
                                                           bool pDeleteTweenOnHit,
                                                           bool pDeleteTweenOnOverlap,
                                                           int32 pNumLoops,
                                                           ETweenLoopType pLoopType,
                                                           float pDelay,
                                                           float pTimeScale,
                                                           bool pTweenWhileGameIsPaused)
{
    int32 newSequenceIndex = mTweenSequenceIndex + 1;
    return UTweenVectorStandardFactory::BP_AppendTweenScaleSceneComponentBy(mOwningTweenContainer,
                                                                            pTweenTarget,
                                                                            pBy,
                                                                            pDuration,
                                                                            pEaseType,
                                                                            pDeleteTweenOnHit,
                                                                            pDeleteTweenOnOverlap,
                                                                            pNumLoops,
                                                                            pLoopType,
                                                                            pDelay,
                                                                            pTimeScale,
                                                                            pTweenWhileGameIsPaused,
                                                                            newSequenceIndex);
}

// public ----------------------------------------------------------------------
UTweenVector* UBaseTween::AppendTweenCustomVector(UObject* pTweenTarget,
                                                  FVector pFrom,
                                                  FVector pTo,
                                                  float pDuration,
                                                  ETweenEaseType pEaseType,
                                                  int32 pNumLoops,
                                                  ETweenLoopType pLoopType,
                                                  float pDelay,
                                                  float pTimeScale,
                                                  bool pTweenWhileGameIsPaused)
{
    int32 newSequenceIndex = mTweenSequenceIndex + 1;
    return UTweenVectorStandardFactory::BP_AppendTweenCustomVector(mOwningTweenContainer,
                                                                   pTweenTarget,
                                                                   pFrom,
                                                                   pTo,
                                                                   pDuration,
                                                                   pEaseType,
                                                                   pNumLoops,
                                                                   pLoopType,
                                                                   pDelay,
                                                                   pTimeScale,
                                                                   pTweenWhileGameIsPaused,
                                                                   newSequenceIndex);
}

// public ----------------------------------------------------------------------
UTweenRotator* UBaseTween::AppendTweenRotateActorTo(AActor* pTweenTarget,
                                                    FRotator pTo,
                                                    float pDuration,
                                                    ETweenEaseType pEaseType,
                                                    ETweenSpace pTweenSpace,
                                                    ETweenRotationMode pRotationMode,
                                                    bool pDeleteTweenOnHit,
                                                    bool pDeleteTweenOnOverlap,
                                                    int32 pNumLoops,
                                                    ETweenLoopType pLoopType,
                                                    float pDelay,
                                                    float pTimeScale,
                                                    bool pTweenWhileGameIsPaused)
{
    int32 newSequenceIndex = mTweenSequenceIndex + 1;
    return UTweenRotatorStandardFactory::BP_AppendTweenRotateActorTo(mOwningTweenContainer,
                                                                     pTweenTarget,
                                                                     pTo,
                                                                     pDuration,
                                                                     pEaseType,
                                                                     pTweenSpace,
                                                                     pRotationMode,
                                                                     pDeleteTweenOnHit,
                                                                     pDeleteTweenOnOverlap,
                                                                     pNumLoops,
                                                                     pLoopType,
                                                                     pDelay,
                                                                     pTimeScale,
                                                                     pTweenWhileGameIsPaused,
                                                                     newSequenceIndex);
}

// public ----------------------------------------------------------------------
UTweenRotator* UBaseTween::AppendTweenRotateActorBy(AActor* pTweenTarget,
                                                    FRotator pBy,
                                                    float pDuration,
                                                    ETweenEaseType pEaseType,
                                                    bool pLocalSpace,
                                                    bool pDeleteTweenOnHit,
                                                    bool pDeleteTweenOnOverlap,
                                                    int32 pNumLoops,
                                                    ETweenLoopType pLoopType,
                                                    float pDelay,
                                                    float pTimeScale,
                                                    bool pTweenWhileGameIsPaused)
{
    int32 newSequenceIndex = mTweenSequenceIndex + 1;
    return UTweenRotatorStandardFactory::BP_AppendTweenRotateActorBy(mOwningTweenContainer,
                                                                     pTweenTarget,
                                                                     pBy,
                                                                     pDuration,
                                                                     pEaseType,
                                                                     pLocalSpace,
                                                                     pDeleteTweenOnHit,
                                                                     pDeleteTweenOnOverlap,
                                                                     pNumLoops,
                                                                     pLoopType,
                                                                     pDelay,
                                                                     pTimeScale,
                                                                     pTweenWhileGameIsPaused,
                                                                     newSequenceIndex);
}

// public ----------------------------------------------------------------------
UTweenRotator* UBaseTween::AppendTweenRotateSceneComponentTo(USceneComponent* pTweenTarget,
                                                             FRotator pTo,
                                                             float pDuration,
                                                             ETweenEaseType pEaseType,
                                                             ETweenSpace pTweenSpace,
                                                             ETweenRotationMode pRotationMode,
                                                             bool pDeleteTweenOnHit,
                                                             bool pDeleteTweenOnOverlap,
                                                             int32 pNumLoops,
                                                             ETweenLoopType pLoopType,
                                                             float pDelay,
                                                             float pTimeScale,
                                                             bool pTweenWhileGameIsPaused)
{
    int32 newSequenceIndex = mTweenSequenceIndex + 1;
    return UTweenRotatorStandardFactory::BP_AppendTweenRotateSceneComponentTo(mOwningTweenContainer,
                                                                              pTweenTarget,
                                                                              pTo,
                                                                              pDuration,
                                                                              pEaseType,
                                                                              pTweenSpace,
                                                                              pRotationMode,
                                                                              pDeleteTweenOnHit,
                                                                              pDeleteTweenOnOverlap,
                                                                              pNumLoops,
                                                                              pLoopType,
                                                                              pDelay,
                                                                              pTimeScale,
                                                                              pTweenWhileGameIsPaused,
                                                                              newSequenceIndex);
}

// public ----------------------------------------------------------------------
UTweenRotator* UBaseTween::AppendTweenRotateSceneComponentBy(USceneComponent* pTweenTarget,
                                                             FRotator pBy,
                                                             float pDuration,
                                                             ETweenEaseType pEaseType,
                                                             bool pLocalSpace,
                                                             bool pDeleteTweenOnHit,
                                                             bool pDeleteTweenOnOverlap,
                                                             int32 pNumLoops,
                                                             ETweenLoopType pLoopType,
                                                             float pDelay,
                                                             float pTimeScale,
                                                             bool pTweenWhileGameIsPaused)
{
    int32 newSequenceIndex = mTweenSequenceIndex + 1;
    return UTweenRotatorStandardFactory::BP_AppendTweenRotateSceneComponentBy(mOwningTweenContainer,
                                                                              pTweenTarget,
                                                                              pBy,
                                                                              pDuration,
                                                                              pEaseType,
                                                                              pLocalSpace,
                                                                              pDeleteTweenOnHit,
                                                                              pDeleteTweenOnOverlap,
                                                                              pNumLoops,
                                                                              pLoopType,
                                                                              pDelay,
                                                                              pTimeScale,
                                                                              pTweenWhileGameIsPaused,
                                                                              newSequenceIndex);
}

// public ----------------------------------------------------------------------
UTweenLinearColor* UBaseTween::AppendTweenMaterialVectorFromTo(UMaterialInstanceDynamic* pTweenTarget,
                                                               FName pParameterName,
                                                               FLinearColor pFrom,
                                                               FLinearColor pTo,
                                                               float pDuration,
                                                               ETweenEaseType pEaseType,
                                                               int32 pNumLoops,
                                                               ETweenLoopType pLoopType,
                                                               float pDelay,
                                                               float pTimeScale,
                                                               bool pTweenWhileGameIsPaused)
{
    int32 newSequenceIndex = mTweenSequenceIndex + 1;
    return UTweenLinearColorStandardFactory::BP_AppendTweenMaterialVectorFromTo(mOwningTweenContainer,
                                                                                pTweenTarget,
                                                                                pParameterName,
                                                                                pFrom,
                                                                                pTo,
                                                                                pDuration,
                                                                                pEaseType,
                                                                                pNumLoops,
                                                                                pLoopType,
                                                                                pDelay,
                                                                                pTimeScale,
                                                                                pTweenWhileGameIsPaused,
                                                                                newSequenceIndex);
}

// public ----------------------------------------------------------------------
UTweenLinearColor* UBaseTween::AppendTweenMaterialVectorTo(UMaterialInstanceDynamic* pTweenTarget,
                                                           FName pParameterName,
                                                           FLinearColor pTo,
                                                           float pDuration,
                                                           ETweenEaseType pEaseType,
                                                           int32 pNumLoops,
                                                           ETweenLoopType pLoopType,
                                                           float pDelay,
                                                           float pTimeScale,
                                                           bool pTweenWhileGameIsPaused)
{
    int32 newSequenceIndex = mTweenSequenceIndex + 1;
    return UTweenLinearColorStandardFactory::BP_AppendTweenMaterialVectorTo(mOwningTweenContainer,
                                                                            pTweenTarget,
                                                                            pParameterName,
                                                                            pTo,
                                                                            pDuration,
                                                                            pEaseType,
                                                                            pNumLoops,
                                                                            pLoopType,
                                                                            pDelay,
                                                                            pTimeScale,
                                                                            pTweenWhileGameIsPaused,
                                                                            newSequenceIndex);
}

// public ----------------------------------------------------------------------
UTweenFloat* UBaseTween::AppendTweenMaterialFloatFromTo(UMaterialInstanceDynamic* pTweenTarget,
                                                        FName pParameterName,
                                                        float pFrom,
                                                        float pTo,
                                                        float pDuration,
                                                        ETweenEaseType pEaseType,
                                                        int32 pNumLoops,
                                                        ETweenLoopType pLoopType,
                                                        float pDelay,
                                                        float pTimeScale,
                                                        bool pTweenWhileGameIsPaused)
{
    int32 newSequenceIndex = mTweenSequenceIndex + 1;
    return UTweenFloatStandardFactory::BP_AppendTweenMaterialFloatFromTo(mOwningTweenContainer,
                                                                         pTweenTarget,
                                                                         pParameterName,
                                                                         pFrom,
                                                                         pTo,
                                                                         pDuration,
                                                                         pEaseType,
                                                                         pNumLoops,
                                                                         pLoopType,
                                                                         pDelay,
                                                                         pTimeScale,
                                                                         pTweenWhileGameIsPaused,
                                                                         newSequenceIndex);
}

// public ----------------------------------------------------------------------
UTweenFloat* UBaseTween::AppendTweenMaterialFloatTo(UMaterialInstanceDynamic* pTweenTarget,
                                                    FName pParameterName,
                                                    float pTo,
                                                    float pDuration,
                                                    ETweenEaseType pEaseType,
                                                    int32 pNumLoops,
                                                    ETweenLoopType pLoopType,
                                                    float pDelay,
                                                    float pTimeScale,
                                                    bool pTweenWhileGameIsPaused)
{
    int32 newSequenceIndex = mTweenSequenceIndex + 1;
    return UTweenFloatStandardFactory::BP_AppendTweenMaterialFloatTo(mOwningTweenContainer,
                                                                     pTweenTarget,
                                                                     pParameterName,
                                                                     pTo,
                                                                     pDuration,
                                                                     pEaseType,
                                                                     pNumLoops,
                                                                     pLoopType,
                                                                     pDelay,
                                                                     pTimeScale,
                                                                     pTweenWhileGameIsPaused,
                                                                     newSequenceIndex);
}

// public ----------------------------------------------------------------------
UTweenFloat* UBaseTween::AppendTweenRotateActorAroundPoint(AActor* pTweenTarget,
                                                           FVector pPivotPoint,
                                                           float pStartingAngle,
                                                           float pEndingAngle,
                                                           float pRadius,
                                                           FVector pAxis,
                                                           ETweenSpace pTweenSpace,
                                                           float pDuration,
                                                           ETweenEaseType pEaseType,
                                                           bool pDeleteTweenOnHit,
                                                           bool pDeleteTweenOnOverlap,
                                                           int32 pNumLoops,
                                                           ETweenLoopType pLoopType,
                                                           float pDelay,
                                                           float pTimeScale,
                                                           bool pTweenWhileGameIsPaused)
{
    int32 newSequenceIndex = mTweenSequenceIndex + 1;
    return UTweenFloatStandardFactory::BP_AppendTweenRotateActorAroundPoint(mOwningTweenContainer,
                                                                            pTweenTarget,
                                                                            pPivotPoint,
                                                                            pStartingAngle,
                                                                            pEndingAngle,
                                                                            pRadius,
                                                                            pAxis,
                                                                            pTweenSpace,
                                                                            pDuration,
                                                                            pEaseType,
                                                                            pDeleteTweenOnHit,
                                                                            pDeleteTweenOnOverlap,
                                                                            pNumLoops,
                                                                            pLoopType,
                                                                            pDelay,
                                                                            pTimeScale,
                                                                            pTweenWhileGameIsPaused,
                                                                            newSequenceIndex);
}

// public ----------------------------------------------------------------------
UTweenFloat* UBaseTween::AppendTweenRotateActorAroundPointByOffset(AActor* pTweenTarget,
                                                                   FVector pPivotPoint,
                                                                   float pOffsetAngle,
                                                                   ETweenReferenceAxis pReferenceAxis,
                                                                   ETweenSpace pTweenSpace,
                                                                   float pDuration,
                                                                   ETweenEaseType pEaseType,
                                                                   bool pDeleteTweenOnHit,
                                                                   bool pDeleteTweenOnOverlap,
                                                                   int32 pNumLoops,
                                                                   ETweenLoopType pLoopType,
                                                                   float pDelay,
                                                                   float pTimeScale,
                                                                   bool pTweenWhileGameIsPaused)
{
    int32 newSequenceIndex = mTweenSequenceIndex + 1;
    return UTweenFloatStandardFactory::BP_AppendTweenRotateActorAroundPointByOffset(mOwningTweenContainer,
                                                                                    pTweenTarget,
                                                                                    pPivotPoint,
                                                                                    pOffsetAngle,
                                                                                    pReferenceAxis,
                                                                                    pTweenSpace,
                                                                                    pDuration,
                                                                                    pEaseType,
                                                                                    pDeleteTweenOnHit,
                                                                                    pDeleteTweenOnOverlap,
                                                                                    pNumLoops,
                                                                                    pLoopType,
                                                                                    pDelay,
                                                                                    pTimeScale,
                                                                                    pTweenWhileGameIsPaused,
                                                                                    newSequenceIndex);
}

// public ----------------------------------------------------------------------
UTweenFloat* UBaseTween::AppendTweenActorFollowSpline(AActor* pTweenTarget,
                                                      USplineComponent* pSpline,
                                                      float pDuration,
                                                      bool pApplyRotation,
                                                      bool pApplyScale,
                                                      bool pUseConstantSpeed,
                                                      ETweenEaseType pEaseType,
                                                      bool pDeleteTweenOnHit,
                                                      bool pDeleteTweenOnOverlap,
                                                      int32 pNumLoops,
                                                      ETweenLoopType pLoopType,
                                                      float pDelay,
                                                      float pTimeScale,
                                                      bool pTweenWhileGameIsPaused)
{
    int32 newSequenceIndex = mTweenSequenceIndex + 1;
    return UTweenFloatStandardFactory::BP_AppendTweenActorFollowSpline(mOwningTweenContainer,
                                                                       pTweenTarget,
                                                                       pSpline,
                                                                       pDuration,
                                                                       pApplyRotation,
                                                                       pApplyScale,
                                                                       pUseConstantSpeed,
                                                                       pEaseType,
                                                                       pDeleteTweenOnHit,
                                                                       pDeleteTweenOnOverlap,
                                                                       pNumLoops,
                                                                       pLoopType,
                                                                       pDelay,
                                                                       pTimeScale,
                                                                       pTweenWhileGameIsPaused,
                                                                       newSequenceIndex);
}

// public ----------------------------------------------------------------------
UTweenFloat* UBaseTween::AppendTweenRotateSceneComponentAroundPoint(USceneComponent* pTweenTarget,
                                                                    FVector pPivotPoint,
                                                                    float pStartingAngle,
                                                                    float pEndingAngle,
                                                                    float pRadius,
                                                                    FVector pAxis,
                                                                    ETweenSpace pTweenSpace,
                                                                    float pDuration,
                                                                    ETweenEaseType pEaseType,
                                                                    bool pDeleteTweenOnHit,
                                                                    bool pDeleteTweenOnOverlap,
                                                                    int32 pNumLoops,
                                                                    ETweenLoopType pLoopType,
                                                                    float pDelay,
                                                                    float pTimeScale,
                                                                    bool pTweenWhileGameIsPaused)
{
    int32 newSequenceIndex = mTweenSequenceIndex + 1;
    return UTweenFloatStandardFactory::BP_AppendTweenRotateSceneComponentAroundPoint(mOwningTweenContainer,
                                                                                     pTweenTarget,
                                                                                     pPivotPoint,
                                                                                     pStartingAngle,
                                                                                     pEndingAngle,
                                                                                     pRadius,
                                                                                     pAxis,
                                                                                     pTweenSpace,
                                                                                     pDuration,
                                                                                     pEaseType,
                                                                                     pDeleteTweenOnHit,
                                                                                     pDeleteTweenOnOverlap,
                                                                                     pNumLoops,
                                                                                     pLoopType,
                                                                                     pDelay,
                                                                                     pTimeScale,
                                                                                     pTweenWhileGameIsPaused,
                                                                                     newSequenceIndex);
}

// public ----------------------------------------------------------------------
UTweenFloat* UBaseTween::AppendTweenRotateSceneComponentAroundPointByOffset(USceneComponent* pTweenTarget,
                                                                            FVector pPivotPoint,
                                                                            float pOffsetAngle,
                                                                            ETweenReferenceAxis pReferenceAxis,
                                                                            ETweenSpace pTweenSpace,
                                                                            float pDuration,
                                                                            ETweenEaseType pEaseType,
                                                                            bool pDeleteTweenOnHit,
                                                                            bool pDeleteTweenOnOverlap,
                                                                            int32 pNumLoops,
                                                                            ETweenLoopType pLoopType,
                                                                            float pDelay,
                                                                            float pTimeScale,
                                                                            bool pTweenWhileGameIsPaused)
{
    int32 newSequenceIndex = mTweenSequenceIndex + 1;
    return UTweenFloatStandardFactory::BP_AppendTweenRotateSceneComponentAroundPointByOffset(mOwningTweenContainer,
                                                                                             pTweenTarget,
                                                                                             pPivotPoint,
                                                                                             pOffsetAngle,
                                                                                             pReferenceAxis,
                                                                                             pTweenSpace,
                                                                                             pDuration,
                                                                                             pEaseType,
                                                                                             pDeleteTweenOnHit,
                                                                                             pDeleteTweenOnOverlap,
                                                                                             pNumLoops,
                                                                                             pLoopType,
                                                                                             pDelay,
                                                                                             pTimeScale,
                                                                                             pTweenWhileGameIsPaused,
                                                                                             newSequenceIndex);
}

// public ----------------------------------------------------------------------
UTweenFloat* UBaseTween::AppendTweenSceneComponentFollowSpline(USceneComponent* pTweenTarget,
                                                               USplineComponent* pSpline,
                                                               float pDuration,
                                                               bool pApplyRotation,
                                                               bool pApplyScale,
                                                               bool pUseConstantSpeed,
                                                               ETweenEaseType pEaseType,
                                                               bool pDeleteTweenOnHit,
                                                               bool pDeleteTweenOnOverlap,
                                                               int32 pNumLoops,
                                                               ETweenLoopType pLoopType,
                                                               float pDelay,
                                                               float pTimeScale,
                                                               bool pTweenWhileGameIsPaused)
{
    int32 newSequenceIndex = mTweenSequenceIndex + 1;
    return UTweenFloatStandardFactory::BP_AppendTweenSceneComponentFollowSpline(mOwningTweenContainer,
                                                                                pTweenTarget,
                                                                                pSpline,
                                                                                pDuration,
                                                                                pApplyRotation,
                                                                                pApplyScale,
                                                                                pUseConstantSpeed,
                                                                                pEaseType,
                                                                                pDeleteTweenOnHit,
                                                                                pDeleteTweenOnOverlap,
                                                                                pNumLoops,
                                                                                pLoopType,
                                                                                pDelay,
                                                                                pTimeScale,
                                                                                pTweenWhileGameIsPaused,
                                                                                newSequenceIndex);
}

// public ----------------------------------------------------------------------
UTweenFloat* UBaseTween::AppendTweenWidgetAngleTo(UWidget* pTweenTarget,
                                                  float pTo,
                                                  float pDuration,
                                                  ETweenEaseType pEaseType,
                                                  int32 pNumLoops,
                                                  ETweenLoopType pLoopType,
                                                  float pDelay,
                                                  float pTimeScale,
                                                  bool pTweenWhileGameIsPaused)
{
    int32 newSequenceIndex = mTweenSequenceIndex + 1;
    return UTweenFloatStandardFactory::BP_AppendTweenWidgetAngleTo(mOwningTweenContainer,
                                                                   pTweenTarget,
                                                                   pTo,
                                                                   pDuration,
                                                                   pEaseType,
                                                                   pNumLoops,
                                                                   pLoopType,
                                                                   pDelay,
                                                                   pTimeScale,
                                                                   pTweenWhileGameIsPaused,
                                                                   newSequenceIndex);
}

// public ----------------------------------------------------------------------
UTweenFloat* UBaseTween::AppendTweenWidgetOpacityTo(UWidget* pTweenTarget,
                                                    float pTo,
                                                    float pDuration,
                                                    ETweenEaseType pEaseType,
                                                    int32 pNumLoops,
                                                    ETweenLoopType pLoopType,
                                                    float pDelay,
                                                    float pTimeScale,
                                                    bool pTweenWhileGameIsPaused)
{
    int32 newSequenceIndex = mTweenSequenceIndex + 1;
    return UTweenFloatStandardFactory::BP_AppendTweenWidgetOpacityTo(mOwningTweenContainer,
                                                                     pTweenTarget,
                                                                     pTo,
                                                                     pDuration,
                                                                     pEaseType,
                                                                     pNumLoops,
                                                                     pLoopType,
                                                                     pDelay,
                                                                     pTimeScale,
                                                                     pTweenWhileGameIsPaused,
                                                                     newSequenceIndex);
}

// public ----------------------------------------------------------------------
UTweenFloat* UBaseTween::AppendTweenCustomFloat(UObject* pTweenTarget,
                                                float pFrom,
                                                float pTo,
                                                float pDuration,
                                                ETweenEaseType pEaseType,
                                                int32 pNumLoops,
                                                ETweenLoopType pLoopType,
                                                float pDelay,
                                                float pTimeScale,
                                                bool pTweenWhileGameIsPaused)
{
    int32 newSequenceIndex = mTweenSequenceIndex + 1;
    return UTweenFloatStandardFactory::BP_AppendTweenCustomFloat(mOwningTweenContainer,
                                                                 pTweenTarget,
                                                                 pFrom,
                                                                 pTo,
                                                                 pDuration,
                                                                 pEaseType,
                                                                 pNumLoops,
                                                                 pLoopType,
                                                                 pDelay,
                                                                 pTimeScale,
                                                                 pTweenWhileGameIsPaused,
                                                                 newSequenceIndex);
}

// public ----------------------------------------------------------------------
UTweenVector2D* UBaseTween::AppendTweenMoveWidgetTo(UWidget* pTweenTarget,
                                                    FVector2D pTo,
                                                    float pDuration,
                                                    ETweenEaseType pEaseType,
                                                    int32 pNumLoops,
                                                    ETweenLoopType pLoopType,
                                                    float pDelay,
                                                    float pTimeScale,
                                                    bool pTweenWhileGameIsPaused)
{
    int32 newSequenceIndex = mTweenSequenceIndex + 1;
    return UTweenVector2DStandardFactory::BP_AppendTweenMoveWidgetTo(mOwningTweenContainer,
                                                                     pTweenTarget,
                                                                     pTo,
                                                                     pDuration,
                                                                     pEaseType,
                                                                     pNumLoops,
                                                                     pLoopType,
                                                                     pDelay,
                                                                     pTimeScale,
                                                                     pTweenWhileGameIsPaused,
                                                                     newSequenceIndex);
}

// public ----------------------------------------------------------------------
UTweenVector2D* UBaseTween::AppendTweenMoveWidgetBy(UWidget* pTweenTarget,
                                                    FVector2D pBy,
                                                    float pDuration,
                                                    ETweenEaseType pEaseType,
                                                    int32 pNumLoops,
                                                    ETweenLoopType pLoopType,
                                                    float pDelay,
                                                    float pTimeScale,
                                                    bool pTweenWhileGameIsPaused)
{
    int32 newSequenceIndex = mTweenSequenceIndex + 1;
    return UTweenVector2DStandardFactory::BP_AppendTweenMoveWidgetBy(mOwningTweenContainer,
                                                                     pTweenTarget,
                                                                     pBy,
                                                                     pDuration,
                                                                     pEaseType,
                                                                     pNumLoops,
                                                                     pLoopType,
                                                                     pDelay,
                                                                     pTimeScale,
                                                                     pTweenWhileGameIsPaused,
                                                                     newSequenceIndex);
}

// public ----------------------------------------------------------------------
UTweenVector2D* UBaseTween::AppendTweenScaleWidgetTo(UWidget* pTweenTarget,
                                                     FVector2D pTo,
                                                     float pDuration,
                                                     ETweenEaseType pEaseType,
                                                     int32 pNumLoops,
                                                     ETweenLoopType pLoopType,
                                                     float pDelay,
                                                     float pTimeScale,
                                                     bool pTweenWhileGameIsPaused)
{
    int32 newSequenceIndex = mTweenSequenceIndex + 1;
    return UTweenVector2DStandardFactory::BP_AppendTweenScaleWidgetTo(mOwningTweenContainer,
                                                                      pTweenTarget,
                                                                      pTo,
                                                                      pDuration,
                                                                      pEaseType,
                                                                      pNumLoops,
                                                                      pLoopType,
                                                                      pDelay,
                                                                      pTimeScale,
                                                                      pTweenWhileGameIsPaused,
                                                                      newSequenceIndex);
}

// public ----------------------------------------------------------------------
UTweenVector2D* UBaseTween::AppendTweenScaleWidgetBy(UWidget* pTweenTarget,
                                                     FVector2D pBy,
                                                     float pDuration,
                                                     ETweenEaseType pEaseType,
                                                     int32 pNumLoops,
                                                     ETweenLoopType pLoopType,
                                                     float pDelay,
                                                     float pTimeScale,
                                                     bool pTweenWhileGameIsPaused)
{
    int32 newSequenceIndex = mTweenSequenceIndex + 1;
    return UTweenVector2DStandardFactory::BP_AppendTweenScaleWidgetBy(mOwningTweenContainer,
                                                                      pTweenTarget,
                                                                      pBy,
                                                                      pDuration,
                                                                      pEaseType,
                                                                      pNumLoops,
                                                                      pLoopType,
                                                                      pDelay,
                                                                      pTimeScale,
                                                                      pTweenWhileGameIsPaused,
                                                                      newSequenceIndex);
}

// public ----------------------------------------------------------------------
UTweenVector2D* UBaseTween::AppendTweenShearWidgetTo(UWidget* pTweenTarget,
                                                     FVector2D pTo,
                                                     float pDuration,
                                                     ETweenEaseType pEaseType,
                                                     int32 pNumLoops,
                                                     ETweenLoopType pLoopType,
                                                     float pDelay,
                                                     float pTimeScale,
                                                     bool pTweenWhileGameIsPaused)
{
    int32 newSequenceIndex = mTweenSequenceIndex + 1;
    return UTweenVector2DStandardFactory::BP_AppendTweenShearWidgetTo(mOwningTweenContainer,
                                                                      pTweenTarget,
                                                                      pTo,
                                                                      pDuration,
                                                                      pEaseType,
                                                                      pNumLoops,
                                                                      pLoopType,
                                                                      pDelay,
                                                                      pTimeScale,
                                                                      pTweenWhileGameIsPaused,
                                                                      newSequenceIndex);
}

// public ----------------------------------------------------------------------
UTweenVector2D* UBaseTween::AppendTweenCustomVector2D(UObject* pTweenTarget,
                                                      FVector2D pFrom,
                                                      FVector2D pTo,
                                                      float pDuration,
                                                      ETweenEaseType pEaseType,
                                                      int32 pNumLoops,
                                                      ETweenLoopType pLoopType,
                                                      float pDelay,
                                                      float pTimeScale,
                                                      bool pTweenWhileGameIsPaused)
{
    int32 newSequenceIndex = mTweenSequenceIndex + 1;
    return UTweenVector2DStandardFactory::BP_AppendTweenCustomVector2D(mOwningTweenContainer,
                                                                       pTweenTarget,
                                                                       pFrom,
                                                                       pTo,
                                                                       pDuration,
                                                                       pEaseType,
                                                                       pNumLoops,
                                                                       pLoopType,
                                                                       pDelay,
                                                                       pTimeScale,
                                                                       pTweenWhileGameIsPaused,
                                                                       newSequenceIndex);
}

// public ----------------------------------------------------------------------
UTweenVector* UBaseTween::JoinTweenMoveActorTo(AActor* pTweenTarget,
                                               FVector pTo,
                                               float pDuration,
                                               ETweenEaseType pEaseType,
                                               ETweenSpace pTweenSpace,
                                               bool pDeleteTweenOnHit,
                                               bool pDeleteTweenOnOverlap,
                                               float pDelay,
                                               float pTimeScale,
                                               bool pTweenWhileGameIsPaused)
{
    int32 newSequenceIndex = mTweenSequenceIndex;
    return UTweenVectorStandardFactory::BP_JoinTweenMoveActorTo(mOwningTweenContainer,
                                                                pTweenTarget,
                                                                pTo,
                                                                pDuration,
                                                                pEaseType,
                                                                pTweenSpace,
                                                                pDeleteTweenOnHit,
                                                                pDeleteTweenOnOverlap,
                                                                pDelay,
                                                                pTimeScale,
                                                                pTweenWhileGameIsPaused,
                                                                newSequenceIndex);
}

// public ----------------------------------------------------------------------
UTweenVector* UBaseTween::JoinTweenMoveActorBy(AActor* pTweenTarget,
                                               FVector pBy,
                                               float pDuration,
                                               ETweenEaseType pEaseType,
                                               bool pDeleteTweenOnHit,
                                               bool pDeleteTweenOnOverlap,
                                               float pDelay,
                                               float pTimeScale,
                                               bool pTweenWhileGameIsPaused)
{
    int32 newSequenceIndex = mTweenSequenceIndex;
    return UTweenVectorStandardFactory::BP_JoinTweenMoveActorBy(mOwningTweenContainer,
                                                                pTweenTarget,
                                                                pBy,
                                                                pDuration,
                                                                pEaseType,
                                                                pDeleteTweenOnHit,
                                                                pDeleteTweenOnOverlap,
                                                                pDelay,
                                                                pTimeScale,
                                                                pTweenWhileGameIsPaused,
                                                                newSequenceIndex);
}

// public ----------------------------------------------------------------------
UTweenVector* UBaseTween::JoinTweenScaleActorTo(AActor* pTweenTarget,
                                                FVector pTo,
                                                float pDuration,
                                                ETweenEaseType pEaseType,
                                                ETweenSpace pTweenSpace,
                                                bool pDeleteTweenOnHit,
                                                bool pDeleteTweenOnOverlap,
                                                float pDelay,
                                                float pTimeScale,
                                                bool pTweenWhileGameIsPaused)
{
    int32 newSequenceIndex = mTweenSequenceIndex;
    return UTweenVectorStandardFactory::BP_JoinTweenScaleActorTo(mOwningTweenContainer,
                                                                 pTweenTarget,
                                                                 pTo,
                                                                 pDuration,
                                                                 pEaseType,
                                                                 pTweenSpace,
                                                                 pDeleteTweenOnHit,
                                                                 pDeleteTweenOnOverlap,
                                                                 pDelay,
                                                                 pTimeScale,
                                                                 pTweenWhileGameIsPaused,
                                                                 newSequenceIndex);
}

// public ----------------------------------------------------------------------
UTweenVector* UBaseTween::JoinTweenScaleActorBy(AActor* pTweenTarget,
                                                FVector pBy,
                                                float pDuration,
                                                ETweenEaseType pEaseType,
                                                bool pDeleteTweenOnHit,
                                                bool pDeleteTweenOnOverlap,
                                                float pDelay,
                                                float pTimeScale,
                                                bool pTweenWhileGameIsPaused)
{
    int32 newSequenceIndex = mTweenSequenceIndex;
    return UTweenVectorStandardFactory::BP_JoinTweenScaleActorBy(mOwningTweenContainer,
                                                                 pTweenTarget,
                                                                 pBy,
                                                                 pDuration,
                                                                 pEaseType,
                                                                 pDeleteTweenOnHit,
                                                                 pDeleteTweenOnOverlap,
                                                                 pDelay,
                                                                 pTimeScale,
                                                                 pTweenWhileGameIsPaused,
                                                                 newSequenceIndex);
}

// public ----------------------------------------------------------------------
UTweenVector* UBaseTween::JoinTweenMoveSceneComponentTo(USceneComponent* pTweenTarget,
                                                        FVector pTo,
                                                        float pDuration,
                                                        ETweenEaseType pEaseType,
                                                        ETweenSpace pTweenSpace,
                                                        bool pDeleteTweenOnHit,
                                                        bool pDeleteTweenOnOverlap,
                                                        float pDelay,
                                                        float pTimeScale,
                                                        bool pTweenWhileGameIsPaused)
{
    int32 newSequenceIndex = mTweenSequenceIndex;
    return UTweenVectorStandardFactory::BP_JoinTweenMoveSceneComponentTo(mOwningTweenContainer,
                                                                         pTweenTarget,
                                                                         pTo,
                                                                         pDuration,
                                                                         pEaseType,
                                                                         pTweenSpace,
                                                                         pDeleteTweenOnHit,
                                                                         pDeleteTweenOnOverlap,
                                                                         pDelay,
                                                                         pTimeScale,
                                                                         pTweenWhileGameIsPaused,
                                                                         newSequenceIndex);
}

// public ----------------------------------------------------------------------
UTweenVector* UBaseTween::JoinTweenMoveSceneComponentBy(USceneComponent* pTweenTarget,
                                                        FVector pBy,
                                                        float pDuration,
                                                        ETweenEaseType pEaseType,
                                                        bool pDeleteTweenOnHit,
                                                        bool pDeleteTweenOnOverlap,
                                                        float pDelay,
                                                        float pTimeScale,
                                                        bool pTweenWhileGameIsPaused)
{
    int32 newSequenceIndex = mTweenSequenceIndex;
    return UTweenVectorStandardFactory::BP_JoinTweenMoveSceneComponentBy(mOwningTweenContainer,
                                                                         pTweenTarget,
                                                                         pBy,
                                                                         pDuration,
                                                                         pEaseType,
                                                                         pDeleteTweenOnHit,
                                                                         pDeleteTweenOnOverlap,
                                                                         pDelay,
                                                                         pTimeScale,
                                                                         pTweenWhileGameIsPaused,
                                                                         newSequenceIndex);
}

// public ----------------------------------------------------------------------
UTweenVector* UBaseTween::JoinTweenScaleSceneComponentTo(USceneComponent* pTweenTarget,
                                                         FVector pTo,
                                                         float pDuration,
                                                         ETweenEaseType pEaseType,
                                                         ETweenSpace pTweenSpace,
                                                         bool pDeleteTweenOnHit,
                                                         bool pDeleteTweenOnOverlap,
                                                         float pDelay,
                                                         float pTimeScale,
                                                         bool pTweenWhileGameIsPaused)
{
    int32 newSequenceIndex = mTweenSequenceIndex;
    return UTweenVectorStandardFactory::BP_JoinTweenScaleSceneComponentTo(mOwningTweenContainer,
                                                                          pTweenTarget,
                                                                          pTo,
                                                                          pDuration,
                                                                          pEaseType,
                                                                          pTweenSpace,
                                                                          pDeleteTweenOnHit,
                                                                          pDeleteTweenOnOverlap,
                                                                          pDelay,
                                                                          pTimeScale,
                                                                          pTweenWhileGameIsPaused,
                                                                          newSequenceIndex);
}

// public ----------------------------------------------------------------------
UTweenVector* UBaseTween::JoinTweenScaleSceneComponentBy(USceneComponent* pTweenTarget,
                                                         FVector pBy,
                                                         float pDuration,
                                                         ETweenEaseType pEaseType,
                                                         bool pDeleteTweenOnHit,
                                                         bool pDeleteTweenOnOverlap,
                                                         float pDelay,
                                                         float pTimeScale,
                                                         bool pTweenWhileGameIsPaused)
{
    int32 newSequenceIndex = mTweenSequenceIndex;
    return UTweenVectorStandardFactory::BP_JoinTweenScaleSceneComponentBy(mOwningTweenContainer,
                                                                          pTweenTarget,
                                                                          pBy,
                                                                          pDuration,
                                                                          pEaseType,
                                                                          pDeleteTweenOnHit,
                                                                          pDeleteTweenOnOverlap,
                                                                          pDelay,
                                                                          pTimeScale,
                                                                          pTweenWhileGameIsPaused,
                                                                          newSequenceIndex);
}

// public ----------------------------------------------------------------------
UTweenVector* UBaseTween::JoinTweenCustomVector(UObject* pTweenTarget,
                                                FVector pFrom,
                                                FVector pTo,
                                                float pDuration,
                                                ETweenEaseType pEaseType,
                                                float pDelay,
                                                float pTimeScale,
                                                bool pTweenWhileGameIsPaused)
{
    int32 newSequenceIndex = mTweenSequenceIndex;
    return UTweenVectorStandardFactory::BP_JoinTweenCustomVector(mOwningTweenContainer,
                                                                 pTweenTarget,
                                                                 pFrom,
                                                                 pTo,
                                                                 pDuration,
                                                                 pEaseType,
                                                                 pDelay,
                                                                 pTimeScale,
                                                                 pTweenWhileGameIsPaused,
                                                                 newSequenceIndex);
}

// public ----------------------------------------------------------------------
UTweenRotator* UBaseTween::JoinTweenRotateActorTo(AActor* pTweenTarget,
                                                  FRotator pTo,
                                                  float pDuration,
                                                  ETweenEaseType pEaseType,
                                                  ETweenSpace pTweenSpace,
                                                  ETweenRotationMode pRotationMode,
                                                  bool pDeleteTweenOnHit,
                                                  bool pDeleteTweenOnOverlap,
                                                  float pDelay,
                                                  float pTimeScale,
                                                  bool pTweenWhileGameIsPaused)
{
    int32 newSequenceIndex = mTweenSequenceIndex;
    return UTweenRotatorStandardFactory::BP_JoinTweenRotateActorTo(mOwningTweenContainer,
                                                                   pTweenTarget,
                                                                   pTo,
                                                                   pDuration,
                                                                   pEaseType,
                                                                   pTweenSpace,
                                                                   pRotationMode,
                                                                   pDeleteTweenOnHit,
                                                                   pDeleteTweenOnOverlap,
                                                                   pDelay,
                                                                   pTimeScale,
                                                                   pTweenWhileGameIsPaused,
                                                                   newSequenceIndex);
}

// public ----------------------------------------------------------------------
UTweenRotator* UBaseTween::JoinTweenRotateActorBy(AActor* pTweenTarget,
                                                  FRotator pBy,
                                                  float pDuration,
                                                  ETweenEaseType pEaseType,
                                                  bool pLocalSpace,
                                                  bool pDeleteTweenOnHit,
                                                  bool pDeleteTweenOnOverlap,
                                                  float pDelay,
                                                  float pTimeScale,
                                                  bool pTweenWhileGameIsPaused)
{
    int32 newSequenceIndex = mTweenSequenceIndex;
    return UTweenRotatorStandardFactory::BP_JoinTweenRotateActorBy(mOwningTweenContainer,
                                                                   pTweenTarget,
                                                                   pBy,
                                                                   pDuration,
                                                                   pEaseType,
                                                                   pLocalSpace,
                                                                   pDeleteTweenOnHit,
                                                                   pDeleteTweenOnOverlap,
                                                                   pDelay,
                                                                   pTimeScale,
                                                                   pTweenWhileGameIsPaused,
                                                                   newSequenceIndex);
}

// public ----------------------------------------------------------------------
UTweenRotator* UBaseTween::JoinTweenRotateSceneComponentTo(USceneComponent* pTweenTarget,
                                                           FRotator pTo,
                                                           float pDuration,
                                                           ETweenEaseType pEaseType,
                                                           ETweenSpace pTweenSpace,
                                                           ETweenRotationMode pRotationMode,
                                                           bool pDeleteTweenOnHit,
                                                           bool pDeleteTweenOnOverlap,
                                                           float pDelay,
                                                           float pTimeScale,
                                                           bool pTweenWhileGameIsPaused)
{
    int32 newSequenceIndex = mTweenSequenceIndex;
    return UTweenRotatorStandardFactory::BP_JoinTweenRotateSceneComponentTo(mOwningTweenContainer,
                                                                            pTweenTarget,
                                                                            pTo,
                                                                            pDuration,
                                                                            pEaseType,
                                                                            pTweenSpace,
                                                                            pRotationMode,
                                                                            pDeleteTweenOnHit,
                                                                            pDeleteTweenOnOverlap,
                                                                            pDelay,
                                                                            pTimeScale,
                                                                            pTweenWhileGameIsPaused,
                                                                            newSequenceIndex);
}

// public ----------------------------------------------------------------------
UTweenRotator* UBaseTween::JoinTweenRotateSceneComponentBy(USceneComponent* pTweenTarget,
                                                           FRotator pBy,
                                                           float pDuration,
                                                           ETweenEaseType pEaseType,
                                                           bool pLocalSpace,
                                                           bool pDeleteTweenOnHit,
                                                           bool pDeleteTweenOnOverlap,
                                                           float pDelay,
                                                           float pTimeScale,
                                                           bool pTweenWhileGameIsPaused)
{
    int32 newSequenceIndex = mTweenSequenceIndex;
    return UTweenRotatorStandardFactory::BP_JoinTweenRotateSceneComponentBy(mOwningTweenContainer,
                                                                            pTweenTarget,
                                                                            pBy,
                                                                            pDuration,
                                                                            pEaseType,
                                                                            pLocalSpace,
                                                                            pDeleteTweenOnHit,
                                                                            pDeleteTweenOnOverlap,
                                                                            pDelay,
                                                                            pTimeScale,
                                                                            pTweenWhileGameIsPaused,
                                                                            newSequenceIndex);
}

// public ----------------------------------------------------------------------
UTweenLinearColor* UBaseTween::JoinTweenMaterialVectorFromTo(UMaterialInstanceDynamic* pTweenTarget,
                                                             FName pParameterName,
                                                             FLinearColor pFrom,
                                                             FLinearColor pTo,
                                                             float pDuration,
                                                             ETweenEaseType pEaseType,
                                                             float pDelay,
                                                             float pTimeScale,
                                                             bool pTweenWhileGameIsPaused)
{
    int32 newSequenceIndex = mTweenSequenceIndex;
    return UTweenLinearColorStandardFactory::BP_JoinTweenMaterialVectorFromTo(mOwningTweenContainer,
                                                                              pTweenTarget,
                                                                              pParameterName,
                                                                              pFrom,
                                                                              pTo,
                                                                              pDuration,
                                                                              pEaseType,
                                                                              pDelay,
                                                                              pTimeScale,
                                                                              pTweenWhileGameIsPaused,
                                                                              newSequenceIndex);
}

// public ----------------------------------------------------------------------
UTweenLinearColor* UBaseTween::JoinTweenMaterialVectorTo(UMaterialInstanceDynamic* pTweenTarget,
                                                         FName pParameterName,
                                                         FLinearColor pTo,
                                                         float pDuration,
                                                         ETweenEaseType pEaseType,
                                                         float pDelay,
                                                         float pTimeScale,
                                                         bool pTweenWhileGameIsPaused)
{
    int32 newSequenceIndex = mTweenSequenceIndex;
    return UTweenLinearColorStandardFactory::BP_JoinTweenMaterialVectorTo(mOwningTweenContainer,
                                                                          pTweenTarget,
                                                                          pParameterName,
                                                                          pTo,
                                                                          pDuration,
                                                                          pEaseType,
                                                                          pDelay,
                                                                          pTimeScale,
                                                                          pTweenWhileGameIsPaused,
                                                                          newSequenceIndex);
}

// public ----------------------------------------------------------------------
UTweenFloat* UBaseTween::JoinTweenMaterialFloatFromTo(UMaterialInstanceDynamic* pTweenTarget,
                                                      FName pParameterName,
                                                      float pFrom,
                                                      float pTo,
                                                      float pDuration,
                                                      ETweenEaseType pEaseType,
                                                      float pDelay,
                                                      float pTimeScale,
                                                      bool pTweenWhileGameIsPaused)
{
    int32 newSequenceIndex = mTweenSequenceIndex;
    return UTweenFloatStandardFactory::BP_JoinTweenMaterialFloatFromTo(mOwningTweenContainer,
                                                                       pTweenTarget,
                                                                       pParameterName,
                                                                       pFrom,
                                                                       pTo,
                                                                       pDuration,
                                                                       pEaseType,
                                                                       pDelay,
                                                                       pTimeScale,
                                                                       pTweenWhileGameIsPaused,
                                                                       newSequenceIndex);
}

// public ----------------------------------------------------------------------
UTweenFloat* UBaseTween::JoinTweenMaterialFloatTo(UMaterialInstanceDynamic* pTweenTarget,
                                                  FName pParameterName,
                                                  float pTo,
                                                  float pDuration,
                                                  ETweenEaseType pEaseType,
                                                  float pDelay,
                                                  float pTimeScale,
                                                  bool pTweenWhileGameIsPaused)
{
    int32 newSequenceIndex = mTweenSequenceIndex;
    return UTweenFloatStandardFactory::BP_JoinTweenMaterialFloatTo(mOwningTweenContainer,
                                                                   pTweenTarget,
                                                                   pParameterName,
                                                                   pTo,
                                                                   pDuration,
                                                                   pEaseType,
                                                                   pDelay,
                                                                   pTimeScale,
                                                                   pTweenWhileGameIsPaused,
                                                                   newSequenceIndex);
}

// public ----------------------------------------------------------------------
UTweenFloat* UBaseTween::JoinTweenRotateActorAroundPoint(AActor* pTweenTarget,
                                                         FVector pPivotPoint,
                                                         float pStartingAngle,
                                                         float pEndingAngle,
                                                         float pRadius,
                                                         FVector pAxis,
                                                         ETweenSpace pTweenSpace,
                                                         float pDuration,
                                                         ETweenEaseType pEaseType,
                                                         bool pDeleteTweenOnHit,
                                                         bool pDeleteTweenOnOverlap,
                                                         float pDelay,
                                                         float pTimeScale,
                                                         bool pTweenWhileGameIsPaused)
{
    int32 newSequenceIndex = mTweenSequenceIndex;
    return UTweenFloatStandardFactory::BP_JoinTweenRotateActorAroundPoint(mOwningTweenContainer,
                                                                          pTweenTarget,
                                                                          pPivotPoint,
                                                                          pStartingAngle,
                                                                          pEndingAngle,
                                                                          pRadius,
                                                                          pAxis,
                                                                          pTweenSpace,
                                                                          pDuration,
                                                                          pEaseType,
                                                                          pDeleteTweenOnHit,
                                                                          pDeleteTweenOnOverlap,
                                                                          pDelay,
                                                                          pTimeScale,
                                                                          pTweenWhileGameIsPaused,
                                                                          newSequenceIndex);
}

// public ----------------------------------------------------------------------
UTweenFloat* UBaseTween::JoinTweenRotateActorAroundPointByOffset(AActor* pTweenTarget,
                                                                 FVector pPivotPoint,
                                                                 float pOffsetAngle,
                                                                 ETweenReferenceAxis pReferenceAxis,
                                                                 ETweenSpace pTweenSpace,
                                                                 float pDuration,
                                                                 ETweenEaseType pEaseType,
                                                                 bool pDeleteTweenOnHit,
                                                                 bool pDeleteTweenOnOverlap,
                                                                 float pDelay,
                                                                 float pTimeScale,
                                                                 bool pTweenWhileGameIsPaused)
{
    int32 newSequenceIndex = mTweenSequenceIndex;
    return UTweenFloatStandardFactory::BP_JoinTweenRotateActorAroundPointByOffset(mOwningTweenContainer,
                                                                                  pTweenTarget,
                                                                                  pPivotPoint,
                                                                                  pOffsetAngle,
                                                                                  pReferenceAxis,
                                                                                  pTweenSpace,
                                                                                  pDuration,
                                                                                  pEaseType,
                                                                                  pDeleteTweenOnHit,
                                                                                  pDeleteTweenOnOverlap,
                                                                                  pDelay,
                                                                                  pTimeScale,
                                                                                  pTweenWhileGameIsPaused,
                                                                                  newSequenceIndex);
}

// public ----------------------------------------------------------------------
UTweenFloat* UBaseTween::JoinTweenActorFollowSpline(AActor* pTweenTarget,
                                                    USplineComponent* pSpline,
                                                    float pDuration,
                                                    bool pApplyRotation,
                                                    bool pApplyScale,
                                                    bool pUseConstantSpeed,
                                                    ETweenEaseType pEaseType,
                                                    bool pDeleteTweenOnHit,
                                                    bool pDeleteTweenOnOverlap,
                                                    float pDelay,
                                                    float pTimeScale,
                                                    bool pTweenWhileGameIsPaused)
{
    int32 newSequenceIndex = mTweenSequenceIndex;
    return UTweenFloatStandardFactory::BP_JoinTweenActorFollowSpline(mOwningTweenContainer,
                                                                     pTweenTarget,
                                                                     pSpline,
                                                                     pDuration,
                                                                     pApplyRotation,
                                                                     pApplyScale,
                                                                     pUseConstantSpeed,
                                                                     pEaseType,
                                                                     pDeleteTweenOnHit,
                                                                     pDeleteTweenOnOverlap,
                                                                     pDelay,
                                                                     pTimeScale,
                                                                     pTweenWhileGameIsPaused,
                                                                     newSequenceIndex);
}

// public ----------------------------------------------------------------------
UTweenFloat* UBaseTween::JoinTweenRotateSceneComponentAroundPoint(USceneComponent* pTweenTarget,
                                                                  FVector pPivotPoint,
                                                                  float pStartingAngle,
                                                                  float pEndingAngle,
                                                                  float pRadius,
                                                                  FVector pAxis,
                                                                  ETweenSpace pTweenSpace,
                                                                  float pDuration,
                                                                  ETweenEaseType pEaseType,
                                                                  bool pDeleteTweenOnHit,
                                                                  bool pDeleteTweenOnOverlap,
                                                                  float pDelay,
                                                                  float pTimeScale,
                                                                  bool pTweenWhileGameIsPaused)
{
    int32 newSequenceIndex = mTweenSequenceIndex;
    return UTweenFloatStandardFactory::BP_JoinTweenRotateSceneComponentAroundPoint(mOwningTweenContainer,
                                                                                   pTweenTarget,
                                                                                   pPivotPoint,
                                                                                   pStartingAngle,
                                                                                   pEndingAngle,
                                                                                   pRadius,
                                                                                   pAxis,
                                                                                   pTweenSpace,
                                                                                   pDuration,
                                                                                   pEaseType,
                                                                                   pDeleteTweenOnHit,
                                                                                   pDeleteTweenOnOverlap,
                                                                                   pDelay,
                                                                                   pTimeScale,
                                                                                   pTweenWhileGameIsPaused,
                                                                                   newSequenceIndex);
}

// public ----------------------------------------------------------------------
UTweenFloat* UBaseTween::JoinTweenRotateSceneComponentAroundPointByOffset(USceneComponent* pTweenTarget,
                                                                          FVector pPivotPoint,
                                                                          float pOffsetAngle,
                                                                          ETweenReferenceAxis pReferenceAxis,
                                                                          ETweenSpace pTweenSpace,
                                                                          float pDuration,
                                                                          ETweenEaseType pEaseType,
                                                                          bool pDeleteTweenOnHit,
                                                                          bool pDeleteTweenOnOverlap,
                                                                          float pDelay,
                                                                          float pTimeScale,
                                                                          bool pTweenWhileGameIsPaused)
{
    int32 newSequenceIndex = mTweenSequenceIndex;
    return UTweenFloatStandardFactory::BP_JoinTweenRotateSceneComponentAroundPointByOffset(mOwningTweenContainer,
                                                                                           pTweenTarget,
                                                                                           pPivotPoint,
                                                                                           pOffsetAngle,
                                                                                           pReferenceAxis,
                                                                                           pTweenSpace,
                                                                                           pDuration,
                                                                                           pEaseType,
                                                                                           pDeleteTweenOnHit,
                                                                                           pDeleteTweenOnOverlap,
                                                                                           pDelay,
                                                                                           pTimeScale,
                                                                                           pTweenWhileGameIsPaused,
                                                                                           newSequenceIndex);
}

// public ----------------------------------------------------------------------
UTweenFloat* UBaseTween::JoinTweenSceneComponentFollowSpline(USceneComponent* pTweenTarget,
                                                             USplineComponent* pSpline,
                                                             float pDuration,
                                                             bool pApplyRotation,
                                                             bool pApplyScale,
                                                             bool pUseConstantSpeed,
                                                             ETweenEaseType pEaseType,
                                                             bool pDeleteTweenOnHit,
                                                             bool pDeleteTweenOnOverlap,
                                                             float pDelay,
                                                             float pTimeScale,
                                                             bool pTweenWhileGameIsPaused)
{
    int32 newSequenceIndex = mTweenSequenceIndex;
    return UTweenFloatStandardFactory::BP_JoinTweenSceneComponentFollowSpline(mOwningTweenContainer,
                                                                              pTweenTarget,
                                                                              pSpline,
                                                                              pDuration,
                                                                              pApplyRotation,
                                                                              pApplyScale,
                                                                              pUseConstantSpeed,
                                                                              pEaseType,
                                                                              pDeleteTweenOnHit,
                                                                              pDeleteTweenOnOverlap,
                                                                              pDelay,
                                                                              pTimeScale,
                                                                              pTweenWhileGameIsPaused,
                                                                              newSequenceIndex);
}

// public ----------------------------------------------------------------------
UTweenFloat* UBaseTween::JoinTweenWidgetAngleTo(UWidget* pTweenTarget,
                                                float pTo,
                                                float pDuration,
                                                ETweenEaseType pEaseType,
                                                float pDelay,
                                                float pTimeScale,
                                                bool pTweenWhileGameIsPaused)
{
    int32 newSequenceIndex = mTweenSequenceIndex;
    return UTweenFloatStandardFactory::BP_JoinTweenWidgetAngleTo(mOwningTweenContainer,
                                                                 pTweenTarget,
                                                                 pTo,
                                                                 pDuration,
                                                                 pEaseType,
                                                                 pDelay,
                                                                 pTimeScale,
                                                                 pTweenWhileGameIsPaused,
                                                                 newSequenceIndex);
}

// public ----------------------------------------------------------------------
UTweenFloat* UBaseTween::JoinTweenWidgetOpacityTo(UWidget* pTweenTarget,
                                                  float pTo,
                                                  float pDuration,
                                                  ETweenEaseType pEaseType,
                                                  float pDelay,
                                                  float pTimeScale,
                                                  bool pTweenWhileGameIsPaused)
{
    int32 newSequenceIndex = mTweenSequenceIndex;
    return UTweenFloatStandardFactory::BP_JoinTweenWidgetOpacityTo(mOwningTweenContainer,
                                                                   pTweenTarget,
                                                                   pTo,
                                                                   pDuration,
                                                                   pEaseType,
                                                                   pDelay,
                                                                   pTimeScale,
                                                                   pTweenWhileGameIsPaused,
                                                                   newSequenceIndex);
}

// public ----------------------------------------------------------------------
UTweenFloat* UBaseTween::JoinTweenCustomFloat(UObject* pTweenTarget,
                                              float pFrom,
                                              float pTo,
                                              float pDuration,
                                              ETweenEaseType pEaseType,
                                              float pDelay,
                                              float pTimeScale,
                                              bool pTweenWhileGameIsPaused)
{
    int32 newSequenceIndex = mTweenSequenceIndex;
    return UTweenFloatStandardFactory::BP_JoinTweenCustomFloat(mOwningTweenContainer,
                                                               pTweenTarget,
                                                               pFrom,
                                                               pTo,
                                                               pDuration,
                                                               pEaseType,
                                                               pDelay,
                                                               pTimeScale,
                                                               pTweenWhileGameIsPaused,
                                                               newSequenceIndex);
}

// public ----------------------------------------------------------------------
UTweenVector2D* UBaseTween::JoinTweenMoveWidgetTo(UWidget* pTweenTarget,
                                                  FVector2D pTo,
                                                  float pDuration,
                                                  ETweenEaseType pEaseType,
                                                  float pDelay,
                                                  float pTimeScale,
                                                  bool pTweenWhileGameIsPaused)
{
    int32 newSequenceIndex = mTweenSequenceIndex;
    return UTweenVector2DStandardFactory::BP_JoinTweenMoveWidgetTo(mOwningTweenContainer,
                                                                   pTweenTarget,
                                                                   pTo,
                                                                   pDuration,
                                                                   pEaseType,
                                                                   pDelay,
                                                                   pTimeScale,
                                                                   pTweenWhileGameIsPaused,
                                                                   newSequenceIndex);
}

// public ----------------------------------------------------------------------
UTweenVector2D* UBaseTween::JoinTweenMoveWidgetBy(UWidget* pTweenTarget,
                                                  FVector2D pBy,
                                                  float pDuration,
                                                  ETweenEaseType pEaseType,
                                                  float pDelay,
                                                  float pTimeScale,
                                                  bool pTweenWhileGameIsPaused)
{
    int32 newSequenceIndex = mTweenSequenceIndex;
    return UTweenVector2DStandardFactory::BP_JoinTweenMoveWidgetBy(mOwningTweenContainer,
                                                                   pTweenTarget,
                                                                   pBy,
                                                                   pDuration,
                                                                   pEaseType,
                                                                   pDelay,
                                                                   pTimeScale,
                                                                   pTweenWhileGameIsPaused,
                                                                   newSequenceIndex);
}

// public ----------------------------------------------------------------------
UTweenVector2D* UBaseTween::JoinTweenScaleWidgetTo(UWidget* pTweenTarget,
                                                   FVector2D pTo,
                                                   float pDuration,
                                                   ETweenEaseType pEaseType,
                                                   float pDelay,
                                                   float pTimeScale,
                                                   bool pTweenWhileGameIsPaused)
{
    int32 newSequenceIndex = mTweenSequenceIndex;
    return UTweenVector2DStandardFactory::BP_JoinTweenScaleWidgetTo(mOwningTweenContainer,
                                                                    pTweenTarget,
                                                                    pTo,
                                                                    pDuration,
                                                                    pEaseType,
                                                                    pDelay,
                                                                    pTimeScale,
                                                                    pTweenWhileGameIsPaused,
                                                                    newSequenceIndex);
}

// public ----------------------------------------------------------------------
UTweenVector2D* UBaseTween::JoinTweenScaleWidgetBy(UWidget* pTweenTarget,
                                                   FVector2D pBy,
                                                   float pDuration,
                                                   ETweenEaseType pEaseType,
                                                   float pDelay,
                                                   float pTimeScale,
                                                   bool pTweenWhileGameIsPaused)
{
    int32 newSequenceIndex = mTweenSequenceIndex;
    return UTweenVector2DStandardFactory::BP_JoinTweenScaleWidgetBy(mOwningTweenContainer,
                                                                    pTweenTarget,
                                                                    pBy,
                                                                    pDuration,
                                                                    pEaseType,
                                                                    pDelay,
                                                                    pTimeScale,
                                                                    pTweenWhileGameIsPaused,
                                                                    newSequenceIndex);
}

// public ----------------------------------------------------------------------
UTweenVector2D* UBaseTween::JoinTweenShearWidgetTo(UWidget* pTweenTarget,
                                                   FVector2D pTo,
                                                   float pDuration,
                                                   ETweenEaseType pEaseType,
                                                   float pDelay,
                                                   float pTimeScale,
                                                   bool pTweenWhileGameIsPaused)
{
    int32 newSequenceIndex = mTweenSequenceIndex;
    return UTweenVector2DStandardFactory::BP_JoinTweenShearWidgetTo(mOwningTweenContainer,
                                                                    pTweenTarget,
                                                                    pTo,
                                                                    pDuration,
                                                                    pEaseType,
                                                                    pDelay,
                                                                    pTimeScale,
                                                                    pTweenWhileGameIsPaused,
                                                                    newSequenceIndex);
}

// public ----------------------------------------------------------------------
UTweenVector2D* UBaseTween::JoinTweenCustomVector2D(UObject* pTweenTarget,
                                                    FVector2D pFrom,
                                                    FVector2D pTo,
                                                    float pDuration,
                                                    ETweenEaseType pEaseType,
                                                    float pDelay,
                                                    float pTimeScale,
                                                    bool pTweenWhileGameIsPaused)
{
    int32 newSequenceIndex = mTweenSequenceIndex;
    return UTweenVector2DStandardFactory::BP_JoinTweenCustomVector2D(mOwningTweenContainer,
                                                                     pTweenTarget,
                                                                     pFrom,
                                                                     pTo,
                                                                     pDuration,
                                                                     pEaseType,
                                                                     pDelay,
                                                                     pTimeScale,
                                                                     pTweenWhileGameIsPaused,
                                                                     newSequenceIndex);
}






