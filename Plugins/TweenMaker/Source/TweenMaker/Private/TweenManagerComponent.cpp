// Copyright 2018 Francesco Desogus. All Rights Reserved.

#include "TweenManagerComponent.h"
#include "TweenManagerActor.h"
#include "Tweens/BaseTween.h"
#include "Tweens/TweenVector.h"
#include "Tweens/TweenVector2D.h"
#include "Tweens/TweenRotator.h"
#include "Tweens/TweenLinearColor.h"
#include "Tweens/TweenFloat.h"
#include "Utils/Utility.h"
#include "Utils/TweenEnums.h"
#include "TweenContainer.h"
#include "Kismet/GameplayStatics.h"

// public ----------------------------------------------------------------------
UTweenManagerComponent::UTweenManagerComponent()
{
    PrimaryComponentTick.bCanEverTick = true;
}

// public ----------------------------------------------------------------------
void UTweenManagerComponent::BeginPlay()
{
    Super::BeginPlay();

    SetTickableWhenPaused(true);
}

// public ----------------------------------------------------------------------
void UTweenManagerComponent::TickComponent(float pDeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
    Super::TickComponent(pDeltaTime, TickType, ThisTickFunction);

    // Iterating all TweenContainers backward, so that they can be removed in the for itself if needed
    for (int i = mTweenContainers.Num() - 1; i >= 0; --i)
    {
        UTweenContainer* tweenContainer = mTweenContainers[i];

        // If the container is empty (it was probably created and never used) or is pending a deletion, remove it
        if (tweenContainer->IsEmpty() || tweenContainer->IsPendingDeletion())
        {
            DestroyTweenContainer(tweenContainer, i);
        }
        // Updating the TweenContainer, but only if it's not paused
        else if (!tweenContainer->IsPaused() && (!UGameplayStatics::IsGamePaused(GetWorld()) || tweenContainer->bShouldTweenWhileGamePaused))
        {
            bool bIsDone = tweenContainer->UpdateTweens(pDeltaTime);

            // It can be "done" ONLY if all tweens associated to the object are done (i.e. if there is an infinite loop,
            // it will always be false). In that case, the TweenContainer is no longer needed
            if (bIsDone)
            {
                DestroyTweenContainer(tweenContainer, i);
            }
        }
    }
}

// public ----------------------------------------------------------------------
void UTweenManagerComponent::BP_CreateTweenContainer(UTweenContainer*& pOutTweenContainer,
                                                     int32 pNumLoops,
                                                     ETweenLoopType pLoopType,
                                                     float pTimeScale)
{
    pOutTweenContainer = pOutTweenContainer = CreateTweenContainer(pNumLoops, pLoopType, pTimeScale);
}

// public ----------------------------------------------------------------------
int32 UTweenManagerComponent::DeleteAllTweens()
{
    int32 tweensDeleted = mTweenContainers.Num();

    for (int i = mTweenContainers.Num() - 1; i >= 0; --i)
    {
        UTweenContainer* tweenContainer = mTweenContainers[i];
        DestroyTweenContainer(tweenContainer, i);
    }

    return tweensDeleted;
}

// public ----------------------------------------------------------------------
bool UTweenManagerComponent::DeleteAllTweensByObject(UObject* pTweenTarget, ETweenGenericType pTweensType)
{
    bool hasDeletedSomething = false;

    switch (pTweensType)
    {
        case ETweenGenericType::Any:
        {
            // Looking for the specific pair in the reference map
            for (auto iterator = mTweensByObjectMap.CreateIterator(); iterator; ++iterator)
            {
                TPair<TWeakObjectPtr<UObject>, ETweenGenericType> currentPair = iterator.Key();

                if (currentPair.Key == pTweenTarget)
                {
                    TArray<TWeakObjectPtr<UBaseTween>> tweensToRemove;
                    mTweensByObjectMap.MultiFind(currentPair, tweensToRemove);

                    for (int i = 0; i < tweensToRemove.Num(); ++i)
                    {
                        TWeakObjectPtr<UBaseTween> tween = tweensToRemove[i];

                        if (tween.IsValid())
                        {
                            tween.Get()->DeleteTween();
                            hasDeletedSomething = true;
                        }
                    }

                    mTweensByObjectMap.Remove(currentPair);
                }
            }
            break;
        }
        default:
        {
            TPair<TWeakObjectPtr<UObject>, ETweenGenericType> pairToFind = TPair<TWeakObjectPtr<UObject>, ETweenGenericType>(pTweenTarget, pTweensType);

            TArray<TWeakObjectPtr<UBaseTween>> tweensToRemove;
            mTweensByObjectMap.MultiFind(pairToFind, tweensToRemove);

            // Looking for the specific pair in the reference map
            for (int i = 0; i < tweensToRemove.Num(); ++i)
            {
                TWeakObjectPtr<UBaseTween> tween = tweensToRemove[i];

                if (tween.IsValid())
                {
                    tween.Get()->DeleteTween();
                    hasDeletedSomething = true;
                }
            }

            mTweensByObjectMap.Remove(pairToFind);
            break;
        }
    }

    return hasDeletedSomething;
}

// public ----------------------------------------------------------------------
bool UTweenManagerComponent::IsObjectTweening(UObject* pTweenTarget, ETweenGenericType pTweensType, UBaseTween*& pTweenFound) const
{
    bool found  = false;
    pTweenFound = nullptr;

    if (pTweensType != ETweenGenericType::Any)
    {
        TPair<TWeakObjectPtr<UObject>, ETweenGenericType> pairToFind = TPair<TWeakObjectPtr<UObject>, ETweenGenericType>(pTweenTarget, pTweensType);

        TArray<TWeakObjectPtr<UBaseTween>> tweensFound;
        mTweensByObjectMap.MultiFind(pairToFind, tweensFound);

        for (int i = 0; i < tweensFound.Num() && !found; ++i)
        {
            TWeakObjectPtr<UBaseTween> tween = tweensFound[i];

            if (tween.IsValid())
            {
                found = tween.Get()->IsTweening();

                if (found)
                {
                    pTweenFound = tween.Get();
                }
            }
        }
    }
    else
    {
        for (int i = 0; i < mTweenContainers.Num() && !found; ++i)
        {
            UTweenContainer* tweenContainer = mTweenContainers[i];
            found = tweenContainer->IsObjectTweeningInContainer(pTweenTarget, pTweensType, pTweenFound);
        }
    }


    return found;
}

// public ----------------------------------------------------------------------
bool UTweenManagerComponent::FindTweenByName(FName pTweenName,
                                             ETweenGenericType pTweensType,
                                             UBaseTween*& pTweenFound) const
{
    bool found  = false;
    pTweenFound = nullptr;

    if (pTweensType != ETweenGenericType::Any)
    {
        TPair<FName, ETweenGenericType> pairToFind = TPair<FName, ETweenGenericType>(pTweenName, pTweensType);

        // Find the specific pair
        const TWeakObjectPtr<UBaseTween>* tween = mTweensByNameMap.Find(pairToFind);

        found = tween && tween->IsValid();

        if (found)
        {
            pTweenFound = tween->Get();
        }
    }
    else
    {
        // Iterate across all Tweens with a name
        for (auto& element : mTweensByNameMap)
        {
            // If the element has the name we're looking for and it's valid, take it. If there are more than one element with
            // the same name and type, only the first one will be retrieved
            FName currentName = element.Key.Key;
            if (currentName == pTweenName && element.Value.IsValid())
            {
                pTweenFound = element.Value.Get();
                found = true;
                break;
            }
        }
    }

    return found;
}

// public ----------------------------------------------------------------------
UTweenContainer* UTweenManagerComponent::CreateTweenContainer(int32 pNumLoops, ETweenLoopType pLoopType, float pTimeScale)
{
    UTweenContainer* newTweenContainer = NewObject<UTweenContainer>(this);
    newTweenContainer->Init(this, pNumLoops, pLoopType, pTimeScale);

    mTweenContainers.Add(newTweenContainer);

    return newTweenContainer;
}

// public ----------------------------------------------------------------------
UTweenContainer* UTweenManagerComponent::CreateTweenContainerStatic(int32 pNumLoops, ETweenLoopType pLoopType, float pTimeScale)
{
    UTweenContainer* outTweenContainer = nullptr;
    UTweenManagerComponent* instance   = ATweenManagerActor::GetInstance();

    if (instance != nullptr)
    {
        outTweenContainer = instance->CreateTweenContainer(pNumLoops, pLoopType, pTimeScale);
    }

    return outTweenContainer;
}

// private ---------------------------------------------------------------------
UTweenVector* UTweenManagerComponent::AppendTweenVector(UTweenContainer* pTweenContainer,
                                                        int32 pSequenceIndex,
                                                        ETweenVectorType pTweenType,
                                                        UObject* pTarget,
                                                        ETweenTargetType pTargetType,
                                                        const FVector& pFrom,
                                                        const FVector& pTo,
                                                        float pDuration,
                                                        ETweenEaseType pEaseType,
                                                        ETweenSpace pTweenSpace,
                                                        bool pDeleteTweenOnHit,
                                                        bool pDeleteTweenOnOverlap,
                                                        int32 pNumLoops,
                                                        ETweenLoopType pLoopType,
                                                        float pDelay,
                                                        float pTimeScale,
                                                        bool pTweenWhileGameIsPaused,
                                                        UTweenVectorLatentFactory* pLatentProxy)
{
    // Creating the Tween and saving the reference
    UTweenVector* newTween = NewObject<UTweenVector>(this);
    
    SaveTweenReference(pTarget, pTweenType, newTween);

    // Init for the Tween
    newTween->InitBase(pTweenContainer, pSequenceIndex, pTarget, pTargetType, pEaseType, pDuration, pDelay, pTimeScale, pTweenWhileGameIsPaused, pNumLoops, pLoopType);
    newTween->Init(pFrom, pTo, pTweenType, pTweenSpace, pDeleteTweenOnHit, pDeleteTweenOnOverlap, pLatentProxy);

    // Actually adding the Tween to the TweenContainer
    pTweenContainer->AddSequenceTween(newTween, pSequenceIndex);

    return newTween;
}

// private ---------------------------------------------------------------------
UTweenVector* UTweenManagerComponent::JoinTweenVector(UTweenContainer* pTweenContainer,
                                                      int32 pSequenceIndex,
                                                      ETweenVectorType pTweenType,
                                                      UObject* pTarget,
                                                      ETweenTargetType pTargetType,
                                                      const FVector& pFrom,
                                                      const FVector& pTo,
                                                      float pDuration,
                                                      ETweenEaseType pEaseType,
                                                      ETweenSpace pTweenSpace,
                                                      bool pDeleteTweenOnHit,
                                                      bool pDeleteTweenOnOverlap,
                                                      float pDelay,
                                                      float pTimeScale,
                                                      bool pTweenWhileGameIsPaused,
                                                      UTweenVectorLatentFactory* pLatentProxy)
{
    UTweenVector* newTween = NewObject<UTweenVector>(this);
    SaveTweenReference(pTarget, pTweenType, newTween);

    newTween->InitBase(pTweenContainer, pSequenceIndex, pTarget, pTargetType, pEaseType, pDuration, pDelay, pTimeScale, pTweenWhileGameIsPaused);
    newTween->Init(pFrom, pTo, pTweenType, pTweenSpace, pDeleteTweenOnHit, pDeleteTweenOnOverlap, pLatentProxy);

    pTweenContainer->AddParallelTween(newTween, pSequenceIndex);

    return newTween;
}

// private ---------------------------------------------------------------------
UTweenVector2D* UTweenManagerComponent::AppendTweenVector2D(UTweenContainer* pTweenContainer,
                                                            int32 pSequenceIndex,
                                                            ETweenVector2DType pTweenType,
                                                            UObject* pTarget,
                                                            ETweenTargetType pTargetType,
                                                            const FVector2D& pFrom,
                                                            const FVector2D& pTo,
                                                            float pDuration,
                                                            ETweenEaseType pEaseType,
                                                            int32 pNumLoops,
                                                            ETweenLoopType pLoopType,
                                                            float pDelay,
                                                            float pTimeScale,
                                                            bool pTweenWhileGameIsPaused,
                                                            UTweenVector2DLatentFactory* pLatentProxy)
{
    UTweenVector2D* newTween = NewObject<UTweenVector2D>(this);
    SaveTweenReference(pTarget, pTweenType, newTween);

    newTween->InitBase(pTweenContainer, pSequenceIndex, pTarget, pTargetType, pEaseType, pDuration, pDelay, pTimeScale, pTweenWhileGameIsPaused, pNumLoops, pLoopType);
    newTween->Init(pFrom, pTo, pTweenType, pLatentProxy);

    pTweenContainer->AddSequenceTween(newTween, pSequenceIndex);

    return newTween;
}

// private ---------------------------------------------------------------------
UTweenVector2D* UTweenManagerComponent::JoinTweenVector2D(UTweenContainer* pTweenContainer,
                                                          int32 pSequenceIndex,
                                                          ETweenVector2DType pTweenType,
                                                          UObject* pTarget,
                                                          ETweenTargetType pTargetType,
                                                          const FVector2D& pFrom,
                                                          const FVector2D& pTo,
                                                          float pDuration,
                                                          ETweenEaseType pEaseType,
                                                          float pDelay,
                                                          float pTimeScale,
                                                          bool pTweenWhileGameIsPaused,
                                                          UTweenVector2DLatentFactory* pLatentProxy)
{
    UTweenVector2D* newTween = NewObject<UTweenVector2D>(this);
    SaveTweenReference(pTarget, pTweenType, newTween);

    newTween->InitBase(pTweenContainer, pSequenceIndex, pTarget, pTargetType, pEaseType, pDuration, pDelay, pTimeScale, pTweenWhileGameIsPaused);
    newTween->Init(pFrom, pTo, pTweenType, pLatentProxy);

    pTweenContainer->AddParallelTween(newTween, pSequenceIndex);

    return newTween;
}

// private ---------------------------------------------------------------------
UTweenRotator* UTweenManagerComponent::AppendTweenRotator(UTweenContainer* pTweenContainer,
                                                          int32 pSequenceIndex,
                                                          ETweenRotatorType pTweenType,
                                                          UObject* pTarget,
                                                          ETweenTargetType pTargetType,
                                                          const FRotator& pFrom,
                                                          const FRotator& pTo,
                                                          float pDuration,
                                                          ETweenEaseType pEaseType,
                                                          ETweenSpace pTweenSpace,
                                                          ETweenRotationMode pRotationMode,
                                                          bool pLocalSpace,
                                                          bool pDeleteTweenOnHit,
                                                          bool pDeleteTweenOnOverlap,
                                                          int32 pNumLoops,
                                                          ETweenLoopType pLoopType,
                                                          float pDelay,
                                                          float pTimeScale,
                                                          bool pTweenWhileGameIsPaused,
                                                          UTweenRotatorLatentFactory* pLatentProxy)
{
    UTweenRotator* newTween = NewObject<UTweenRotator>(this);
    SaveTweenReference(pTarget, pTweenType, newTween);

    newTween->InitBase(pTweenContainer, pSequenceIndex, pTarget, pTargetType, pEaseType, pDuration, pDelay, pTimeScale, pTweenWhileGameIsPaused, pNumLoops, pLoopType);
    newTween->Init(pFrom, pTo, pTweenType, pTweenSpace, pRotationMode, pLocalSpace, pDeleteTweenOnHit, pDeleteTweenOnOverlap, pLatentProxy);

    pTweenContainer->AddSequenceTween(newTween, pSequenceIndex);

    return newTween;
}

// private ---------------------------------------------------------------------
UTweenRotator* UTweenManagerComponent::JoinTweenRotator(UTweenContainer* pTweenContainer,
                                                        int32 pSequenceIndex,
                                                        ETweenRotatorType pTweenType,
                                                        UObject* pTarget,
                                                        ETweenTargetType pTargetType,
                                                        const FRotator& pFrom,
                                                        const FRotator& pTo,
                                                        float pDuration,
                                                        ETweenEaseType pEaseType,
                                                        ETweenSpace pTweenSpace,
                                                        ETweenRotationMode pRotationMode,
                                                        bool pLocalSpace,
                                                        bool pDeleteTweenOnHit,
                                                        bool pDeleteTweenOnOverlap,
                                                        float pDelay,
                                                        float pTimeScale,
                                                        bool pTweenWhileGameIsPaused,
                                                        UTweenRotatorLatentFactory* pLatentProxy)
{
    UTweenRotator* newTween = NewObject<UTweenRotator>(this);
    SaveTweenReference(pTarget, pTweenType, newTween);

    newTween->InitBase(pTweenContainer, pSequenceIndex, pTarget, pTargetType, pEaseType, pDuration, pDelay, pTimeScale, pTweenWhileGameIsPaused);
    newTween->Init(pFrom, pTo, pTweenType, pTweenSpace, pRotationMode, pLocalSpace, pDeleteTweenOnHit, pDeleteTweenOnOverlap, pLatentProxy);

    pTweenContainer->AddParallelTween(newTween, pSequenceIndex);

    return newTween;
}

// private ---------------------------------------------------------------------
UTweenLinearColor* UTweenManagerComponent::AppendTweenLinearColor(UTweenContainer *pTweenContainer, int32 pSequenceIndex, ETweenLinearColorType pTweenType,
                                                                  UObject* pTarget,
                                                                  FName pParameterName,
                                                                  ETweenTargetType pTargetType,
                                                                  const FLinearColor& pFrom,
                                                                  const FLinearColor& pTo,
                                                                  float pDuration,
                                                                  ETweenEaseType pEaseType,
                                                                  int32 pNumLoops,
                                                                  ETweenLoopType pLoopType,
                                                                  float pDelay,
                                                                  float pTimeScale,
                                                                  bool pTweenWhileGameIsPaused,
                                                                  UTweenLinearColorLatentFactory* pLatentProxy)
{
    UTweenLinearColor* newTween = NewObject<UTweenLinearColor>(this);
    SaveTweenReference(pTarget, pTweenType, newTween);

    newTween->InitBase(pTweenContainer, pSequenceIndex, pTarget, pTargetType, pEaseType, pDuration, pDelay, pTimeScale, pTweenWhileGameIsPaused, pNumLoops, pLoopType);
    newTween->Init(pParameterName, pFrom, pTo, pTweenType, pLatentProxy);


    pTweenContainer->AddSequenceTween(newTween, pSequenceIndex);

    return newTween;
}

// private ---------------------------------------------------------------------
UTweenLinearColor* UTweenManagerComponent::JoinTweenLinearColor(UTweenContainer* pTweenContainer,
                                                                int32 pSequenceIndex,
                                                                ETweenLinearColorType pTweenType,
                                                                UObject* pTarget,
                                                                FName pParameterName,
                                                                ETweenTargetType pTargetType,
                                                                const FLinearColor& pFrom,
                                                                const FLinearColor& pTo,
                                                                float pDuration,
                                                                ETweenEaseType pEaseType,
                                                                float pDelay,
                                                                float pTimeScale,
                                                                bool pTweenWhileGameIsPaused,
                                                                UTweenLinearColorLatentFactory* pLatentProxy)
{
    UTweenLinearColor* newTween = NewObject<UTweenLinearColor>(this);
    SaveTweenReference(pTarget, pTweenType, newTween);

    newTween->InitBase(pTweenContainer, pSequenceIndex, pTarget, pTargetType, pEaseType, pDuration, pDelay, pTimeScale, pTweenWhileGameIsPaused);
    newTween->Init(pParameterName, pFrom, pTo, pTweenType, pLatentProxy);

    pTweenContainer->AddParallelTween(newTween, pSequenceIndex);

    return newTween;
}

// private ---------------------------------------------------------------------
UTweenFloat* UTweenManagerComponent::AppendTweenFloat(UTweenContainer* pTweenContainer,
                                                      int32 pSequenceIndex,
                                                      ETweenFloatType pTweenType,
                                                      UObject* pTarget,
                                                      ETweenTargetType pTargetType,
                                                      float pFrom,
                                                      float pTo,
                                                      float pDuration,
                                                      ETweenEaseType pEaseType,
                                                      int32 pNumLoops,
                                                      ETweenLoopType pLoopType,
                                                      float pDelay,
                                                      float pTimeScale,
                                                      bool pTweenWhileGameIsPaused,
                                                      UTweenFloatLatentFactory* pLatentProxy,
                                                      FName pParameterName)
{
    UTweenFloat* newTween = NewObject<UTweenFloat>(this);
    SaveTweenReference(pTarget, pTweenType, newTween);

    newTween->InitBase(pTweenContainer, pSequenceIndex, pTarget, pTargetType, pEaseType, pDuration, pDelay, pTimeScale, pTweenWhileGameIsPaused, pNumLoops, pLoopType);
    newTween->Init(pFrom, pTo, pTweenType, pParameterName, pLatentProxy);


    pTweenContainer->AddSequenceTween(newTween, pSequenceIndex);

    return newTween;
}

// private ---------------------------------------------------------------------
UTweenFloat* UTweenManagerComponent::JoinTweenFloat(UTweenContainer* pTweenContainer,
                                                    int32 pSequenceIndex,
                                                    ETweenFloatType pTweenType,
                                                    UObject* pTarget,
                                                    ETweenTargetType pTargetType,
                                                    float pFrom,
                                                    const float pTo,
                                                    float pDuration,
                                                    ETweenEaseType pEaseType,
                                                    float pDelay,
                                                    float pTimeScale,
                                                    bool pTweenWhileGameIsPaused,
                                                    UTweenFloatLatentFactory* pLatentProxy,
                                                    FName pParameterName)
{
    UTweenFloat* newTween = NewObject<UTweenFloat>(this);
    SaveTweenReference(pTarget, pTweenType, newTween);

    newTween->InitBase(pTweenContainer, pSequenceIndex, pTarget, pTargetType, pEaseType, pDuration, pDelay, pTimeScale, pTweenWhileGameIsPaused);
    newTween->Init(pFrom, pTo, pTweenType, pParameterName, pLatentProxy);

    pTweenContainer->AddParallelTween(newTween, pSequenceIndex);

    return newTween;
}

// private ---------------------------------------------------------------------
UTweenFloat* UTweenManagerComponent::AppendTweenRotateAroundFloat(UTweenContainer* pTweenContainer,
                                                                  int32 pSequenceIndex,
                                                                  ETweenFloatType pTweenType,
                                                                  UObject* pTarget,
                                                                  ETweenTargetType pTargetType,
                                                                  const FVector& pPoint,
                                                                  float pStartingAngle,
                                                                  float pEndingAngle,
                                                                  float pRadius,
                                                                  const FVector& pAxis,
                                                                  ETweenSpace pTweenSpace,
                                                                  float pPeriod,
                                                                  ETweenEaseType pEaseType,
                                                                  bool pDeleteTweenOnHit,
                                                                  bool pDeleteTweenOnOverlap,
                                                                  int32 pNumLoops,
                                                                  ETweenLoopType pLoopType,
                                                                  float pDelay,
                                                                  float pTimeScale,
                                                                  bool pTweenWhileGameIsPaused,
                                                                  UTweenFloatLatentFactory* pLatentProxy)
{
    UTweenFloat* newTween = NewObject<UTweenFloat>(this);
    SaveTweenReference(pTarget, pTweenType, newTween);

    newTween->InitBase(pTweenContainer, pSequenceIndex, pTarget, pTargetType, pEaseType, pPeriod, pDelay, pTimeScale, pTweenWhileGameIsPaused, pNumLoops, pLoopType);
    newTween->InitRotateAround(pPoint, pStartingAngle, pEndingAngle, pRadius, pAxis, pTweenSpace, pTweenType, pDeleteTweenOnHit, pDeleteTweenOnOverlap, pLatentProxy);

    pTweenContainer->AddSequenceTween(newTween, pSequenceIndex);

    return newTween;
}

// private ---------------------------------------------------------------------
UTweenFloat* UTweenManagerComponent::JoinTweenRotateAroundFloat(UTweenContainer* pTweenContainer,
                                                                int32 pSequenceIndex,
                                                                ETweenFloatType pTweenType,
                                                                UObject* pTarget,
                                                                ETweenTargetType pTargetType,
                                                                const FVector& pPoint,
                                                                float pStartingAngle,
                                                                float pEndingAngle,
                                                                float pRadius,
                                                                const FVector& pAxis,
                                                                ETweenSpace pTweenSpace,
                                                                float pPeriod,
                                                                ETweenEaseType pEaseType,
                                                                bool pDeleteTweenOnHit,
                                                                bool pDeleteTweenOnOverlap,
                                                                float pDelay,
                                                                float pTimeScale,
                                                                bool pTweenWhileGameIsPaused,
                                                                UTweenFloatLatentFactory* pLatentProxy)
{
    UTweenFloat* newTween = NewObject<UTweenFloat>(this);
    SaveTweenReference(pTarget, pTweenType, newTween);

    newTween->InitBase(pTweenContainer, pSequenceIndex, pTarget, pTargetType, pEaseType, pPeriod, pDelay, pTimeScale, pTweenWhileGameIsPaused);
    newTween->InitRotateAround(pPoint, pStartingAngle, pEndingAngle, pRadius, pAxis, pTweenSpace, pTweenType, pDeleteTweenOnHit, pDeleteTweenOnOverlap, pLatentProxy);

    pTweenContainer->AddParallelTween(newTween, pSequenceIndex);

    return newTween;
}

// private ---------------------------------------------------------------------
UTweenFloat* UTweenManagerComponent::AppendTweenFollowSplineFloat(UTweenContainer* pTweenContainer,
                                                                  int32 pSequenceIndex,
                                                                  ETweenFloatType pTweenType,
                                                                  UObject* pTarget,
                                                                  ETweenTargetType pTargetType,
                                                                  USplineComponent* pSpline,
                                                                  bool pApplyRotation,
                                                                  bool pApplyScale,
                                                                  bool pUseConstantSpeed,
                                                                  float pDuration,
                                                                  ETweenEaseType pEaseType,
                                                                  bool pDeleteTweenOnHit,
                                                                  bool pDeleteTweenOnOverlap,
                                                                  int32 pNumLoops,
                                                                  ETweenLoopType pLoopType,
                                                                  float pDelay,
                                                                  float pTimeScale,
                                                                  bool pTweenWhileGameIsPaused,
                                                                  UTweenFloatLatentFactory* pLatentProxy)
{
    UTweenFloat* newTween = NewObject<UTweenFloat>(this);
    SaveTweenReference(pTarget, pTweenType, newTween);

    newTween->InitBase(pTweenContainer, pSequenceIndex, pTarget, pTargetType, pEaseType, pDuration, pDelay, pTimeScale, pTweenWhileGameIsPaused, pNumLoops, pLoopType);
    newTween->InitFollowSpline(pSpline, pApplyRotation, pApplyScale, pTweenType, pDeleteTweenOnHit, pDeleteTweenOnOverlap, pUseConstantSpeed, pLatentProxy);

    pTweenContainer->AddSequenceTween(newTween, pSequenceIndex);

    return newTween;
}

// private ---------------------------------------------------------------------
UTweenFloat* UTweenManagerComponent::JoinTweenFollowSplineFloat(UTweenContainer* pTweenContainer,
                                                                int32 pSequenceIndex,
                                                                ETweenFloatType pTweenType,
                                                                UObject* pTarget,
                                                                ETweenTargetType pTargetType,
                                                                USplineComponent* pSpline,
                                                                bool pApplyRotation,
                                                                bool pApplyScale,
                                                                bool pUseConstantSpeed,
                                                                float pDuration,
                                                                ETweenEaseType pEaseType,
                                                                bool pDeleteTweenOnHit,
                                                                bool pDeleteTweenOnOverlap,
                                                                float pDelay,
                                                                float pTimeScale,
                                                                bool pTweenWhileGameIsPaused,
                                                                UTweenFloatLatentFactory* pLatentProxy)
{
    UTweenFloat* newTween = NewObject<UTweenFloat>(this);
    SaveTweenReference(pTarget, pTweenType, newTween);

    newTween->InitBase(pTweenContainer, pSequenceIndex, pTarget, pTargetType, pEaseType, pDuration, pDelay, pTimeScale, pTweenWhileGameIsPaused);
    newTween->InitFollowSpline(pSpline, pApplyRotation, pApplyScale, pTweenType, pDeleteTweenOnHit, pDeleteTweenOnOverlap, pUseConstantSpeed, pLatentProxy);

    pTweenContainer->AddParallelTween(newTween, pSequenceIndex);

    return newTween;
}

// private ---------------------------------------------------------------------
void UTweenManagerComponent::DestroyTweenContainer(UTweenContainer* pTweenContainer, int32 pIndex)
{
    // Making the TweenContainer remove its own Tweens's references from the reference map
    pTweenContainer->RemoveTweensReferences(mTweensByObjectMap);

    mTweenContainers.RemoveAt(pIndex);

    // Making sure the tween gets destroyed right away
    Utility::DestroyUObject(pTweenContainer);
}

// private ---------------------------------------------------------------------

void UTweenManagerComponent::SaveTweenReference(UObject* pTweenTarget, ETweenGenericType pTweenType, UBaseTween* pTween)
{
    mTweensByObjectMap.Add(TPair<TWeakObjectPtr<UObject>, ETweenGenericType>(pTweenTarget, pTweenType), pTween);

    pTween->OnNameChanged.AddDynamic(this, &UTweenManagerComponent::UpdateNameMap);
    pTween->OnTweenDestroyed.AddDynamic(this, &UTweenManagerComponent::TweenDestroyed);
}

// private ---------------------------------------------------------------------
void UTweenManagerComponent::UpdateNameMap(UBaseTween* pTween, const FName& pPreviousName, const FName& pNewName)
{
    TPair<FName, ETweenGenericType> pairToRemove = TPair<FName, ETweenGenericType>(pPreviousName, pTween->GetTweenGenericType());
    TPair<FName, ETweenGenericType> pairToAdd    = TPair<FName, ETweenGenericType>(pNewName, pTween->GetTweenGenericType());

    // Remove the old entry, if there was one (since now the name has changed), and add the new one
    if (pPreviousName != NAME_None)
    {
        mTweensByNameMap.RemoveSingle(pairToRemove, pTween);
    }

    mTweensByNameMap.Add(pairToAdd, pTween);
}

// private ---------------------------------------------------------------------
void UTweenManagerComponent::TweenDestroyed(UBaseTween* pTween)
{
    // Remove the name pair from the map, in case it was present
    TPair<FName, ETweenGenericType> pairToRemove = TPair<FName, ETweenGenericType>(pTween->GetTweenName(), pTween->GetTweenGenericType());
    mTweensByNameMap.RemoveSingle(pairToRemove, pTween);
}
