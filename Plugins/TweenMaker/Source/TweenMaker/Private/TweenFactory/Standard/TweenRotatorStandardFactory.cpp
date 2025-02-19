// Copyright 2018 Francesco Desogus. All Rights Reserved.

#include "TweenFactory/Standard/TweenRotatorStandardFactory.h"

#include "GameFramework/Actor.h"
#include "Tweens/TweenRotator.h"
#include "TweenContainer.h"

// public ----------------------------------------------------------------------
UTweenRotatorStandardFactory::UTweenRotatorStandardFactory(const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer)
{

}

// static public ---------------------------------------------------------------
void UTweenRotatorStandardFactory::BP_CreateTweenRotateActorTo(UTweenManagerComponent* pTweenManagerComponent,
                                                               AActor* pTweenTarget,
                                                               UTweenContainer*& pOutTweenContainer,
                                                               UTweenRotator*& pOutTween,
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
                                                               bool pTweenWhileGameIsPaused,
                                                               int32 pSequenceIndex)
{
    pOutTweenContainer = pTweenManagerComponent != nullptr ? pTweenManagerComponent->CreateTweenContainer()
                                                           : UTweenManagerComponent::CreateTweenContainerStatic();
    pOutTween = BP_AppendTweenRotateActorTo(pOutTweenContainer,
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
                                            pSequenceIndex);
}

// static public ---------------------------------------------------------------
void UTweenRotatorStandardFactory::BP_CreateTweenRotateActorBy(UTweenManagerComponent* pTweenManagerComponent,
                                                               AActor* pTweenTarget,
                                                               UTweenContainer*& pOutTweenContainer,
                                                               UTweenRotator*& pOutTween,
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
                                                               bool pTweenWhileGameIsPaused,
                                                               int32 pSequenceIndex)
{
    pOutTweenContainer = pTweenManagerComponent != nullptr ? pTweenManagerComponent->CreateTweenContainer()
                                                           : UTweenManagerComponent::CreateTweenContainerStatic();
    pOutTween = BP_AppendTweenRotateActorBy(pOutTweenContainer,
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
                                            pSequenceIndex);
}

// static public ---------------------------------------------------------------
void UTweenRotatorStandardFactory::BP_CreateTweenRotateSceneComponentTo(UTweenManagerComponent* pTweenManagerComponent,
                                                                        USceneComponent* pTweenTarget,
                                                                        UTweenContainer*& pOutTweenContainer,
                                                                        UTweenRotator*& pOutTween,
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
                                                                        bool pTweenWhileGameIsPaused,
                                                                        int32 pSequenceIndex)
{
    pOutTweenContainer = pTweenManagerComponent != nullptr ? pTweenManagerComponent->CreateTweenContainer()
                                                           : UTweenManagerComponent::CreateTweenContainerStatic();
    pOutTween = BP_AppendTweenRotateSceneComponentTo(pOutTweenContainer,
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
                                                     pSequenceIndex);
}

// static public ---------------------------------------------------------------
void UTweenRotatorStandardFactory::BP_CreateTweenRotateSceneComponentBy(UTweenManagerComponent* pTweenManagerComponent,
                                                                        USceneComponent* pTweenTarget,
                                                                        UTweenContainer*& pOutTweenContainer,
                                                                        UTweenRotator*& pOutTween,
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
                                                                        bool pTweenWhileGameIsPaused,
                                                                        int32 pSequenceIndex)
{
    pOutTweenContainer = pTweenManagerComponent != nullptr ? pTweenManagerComponent->CreateTweenContainer()
                                                           : UTweenManagerComponent::CreateTweenContainerStatic();
    pOutTween = BP_AppendTweenRotateSceneComponentBy(pOutTweenContainer,
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
                                                     pSequenceIndex);
}

// static public ---------------------------------------------------------------
UTweenRotator* UTweenRotatorStandardFactory::BP_AppendTweenRotateActorTo(UTweenContainer* pTweenContainer,
                                                                         AActor* pTweenTarget,
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
                                                                         bool pTweenWhileGameIsPaused,
                                                                         int32 pSequenceIndex)
{
    ETweenTargetType targetType = ETweenTargetType::Actor;
    ETweenRotatorType tweenType = ETweenRotatorType::RotateTo;
    FRotator dummyFromRotator = FRotator::ZeroRotator;
    bool localSpace = false;

    return CreateAppendTweenRotator(pTweenContainer,
                                    tweenType,
                                    pTweenTarget,
                                    targetType,
                                    dummyFromRotator,
                                    pTo,
                                    pDuration,
                                    pEaseType,
                                    pTweenSpace,
                                    pRotationMode,
                                    localSpace,
                                    pDeleteTweenOnHit,
                                    pDeleteTweenOnOverlap,
                                    pNumLoops,
                                    pLoopType,
                                    pDelay,
                                    pTimeScale,
                                    pTweenWhileGameIsPaused,
                                    pSequenceIndex);
}

// static public ---------------------------------------------------------------
UTweenRotator* UTweenRotatorStandardFactory::BP_AppendTweenRotateActorBy(UTweenContainer* pTweenContainer,
                                                                         AActor* pTweenTarget,
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
                                                                         bool pTweenWhileGameIsPaused,
                                                                         int32 pSequenceIndex)
{
    ETweenTargetType targetType          = ETweenTargetType::Actor;
    ETweenRotatorType tweenType          = ETweenRotatorType::RotateBy;
    FRotator dummyFromRotator            = FRotator::ZeroRotator;
    ETweenSpace dummySpace               = ETweenSpace::World;
    ETweenRotationMode dummyRotationMode = ETweenRotationMode::ShortestPath;

    return CreateAppendTweenRotator(pTweenContainer,
                                    tweenType,
                                    pTweenTarget,
                                    targetType,
                                    dummyFromRotator,
                                    pBy,
                                    pDuration,
                                    pEaseType,
                                    dummySpace,
                                    dummyRotationMode,
                                    pLocalSpace,
                                    pDeleteTweenOnHit,
                                    pDeleteTweenOnOverlap,
                                    pNumLoops,
                                    pLoopType,
                                    pDelay,
                                    pTimeScale,
                                    pTweenWhileGameIsPaused,
                                    pSequenceIndex);
}

// static public ---------------------------------------------------------------
UTweenRotator* UTweenRotatorStandardFactory::BP_AppendTweenRotateSceneComponentTo(UTweenContainer* pTweenContainer,
                                                                                  USceneComponent* pTweenTarget,
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
                                                                                  bool pTweenWhileGameIsPaused,
                                                                                  int32 pSequenceIndex)
{
    ETweenTargetType targetType = ETweenTargetType::SceneComponent;
    ETweenRotatorType tweenType = ETweenRotatorType::RotateTo;
    FRotator dummyFromRotator   = FRotator::ZeroRotator;
    bool localSpace = false;

    return CreateAppendTweenRotator(pTweenContainer,
                                    tweenType,
                                    pTweenTarget,
                                    targetType,
                                    dummyFromRotator,
                                    pTo,
                                    pDuration,
                                    pEaseType,
                                    pTweenSpace,
                                    pRotationMode,
                                    localSpace,
                                    pDeleteTweenOnHit,
                                    pDeleteTweenOnOverlap,
                                    pNumLoops,
                                    pLoopType,
                                    pDelay,
                                    pTimeScale,
                                    pTweenWhileGameIsPaused,
                                    pSequenceIndex);
}

// static public ---------------------------------------------------------------
UTweenRotator* UTweenRotatorStandardFactory::BP_AppendTweenRotateSceneComponentBy(UTweenContainer* pTweenContainer,
                                                                                  USceneComponent* pTweenTarget,
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
                                                                                  bool pTweenWhileGameIsPaused,
                                                                                  int32 pSequenceIndex)
{
    ETweenTargetType targetType          = ETweenTargetType::SceneComponent;
    ETweenRotatorType tweenType          = ETweenRotatorType::RotateBy;
    FRotator dummyFromRotator            = FRotator::ZeroRotator;
    ETweenSpace dummySpace               = ETweenSpace::World;
    ETweenRotationMode dummyRotationMode = ETweenRotationMode::ShortestPath;

    return CreateAppendTweenRotator(pTweenContainer,
                                    tweenType,
                                    pTweenTarget,
                                    targetType,
                                    dummyFromRotator,
                                    pBy,
                                    pDuration,
                                    pEaseType,
                                    dummySpace,
                                    dummyRotationMode,
                                    pLocalSpace,
                                    pDeleteTweenOnHit,
                                    pDeleteTweenOnOverlap,
                                    pNumLoops,
                                    pLoopType,
                                    pDelay,
                                    pTimeScale,
                                    pTweenWhileGameIsPaused,
                                    pSequenceIndex);
}

// static public ---------------------------------------------------------------
UTweenRotator* UTweenRotatorStandardFactory::BP_JoinTweenRotateActorTo(UTweenContainer* pTweenContainer,
                                                                       AActor* pTweenTarget,
                                                                       FRotator pTo,
                                                                       float pDuration,
                                                                       ETweenEaseType pEaseType,
                                                                       ETweenSpace pTweenSpace,
                                                                       ETweenRotationMode pRotationMode,
                                                                       bool pDeleteTweenOnHit,
                                                                       bool pDeleteTweenOnOverlap,
                                                                       float pDelay,
                                                                       float pTimeScale,
                                                                       bool pTweenWhileGameIsPaused,
                                                                       int32 pSequenceIndex)
{
    ETweenTargetType targetType = ETweenTargetType::Actor;
    ETweenRotatorType tweenType = ETweenRotatorType::RotateTo;
    FRotator dummyFromRotator   = FRotator::ZeroRotator;
    bool localSpace = false;

    return CreateJoinTweenRotator(pTweenContainer,
                                  tweenType,
                                  pTweenTarget,
                                  targetType,
                                  dummyFromRotator,
                                  pTo,
                                  pDuration,
                                  pEaseType,
                                  pTweenSpace,
                                  pRotationMode,
                                  localSpace,
                                  pDeleteTweenOnHit,
                                  pDeleteTweenOnOverlap,
                                  pDelay,
                                  pTimeScale,
                                  pTweenWhileGameIsPaused,
                                  pSequenceIndex);
}

// static public ---------------------------------------------------------------
UTweenRotator* UTweenRotatorStandardFactory::BP_JoinTweenRotateActorBy(UTweenContainer* pTweenContainer,
                                                                       AActor* pTweenTarget,
                                                                       FRotator pBy,
                                                                       float pDuration,
                                                                       ETweenEaseType pEaseType,
                                                                       bool pLocalSpace,
                                                                       bool pDeleteTweenOnHit,
                                                                       bool pDeleteTweenOnOverlap,
                                                                       float pDelay,
                                                                       float pTimeScale,
                                                                       bool pTweenWhileGameIsPaused,
                                                                       int32 pSequenceIndex)
{
    ETweenTargetType targetType          = ETweenTargetType::Actor;
    ETweenRotatorType tweenType          = ETweenRotatorType::RotateBy;
    FRotator dummyFromRotator            = FRotator::ZeroRotator;
    ETweenSpace dummySpace               = ETweenSpace::World;
    ETweenRotationMode dummyRotationMode = ETweenRotationMode::ShortestPath;

    return CreateJoinTweenRotator(pTweenContainer,
                                  tweenType,
                                  pTweenTarget,
                                  targetType,
                                  dummyFromRotator,
                                  pBy,
                                  pDuration,
                                  pEaseType,
                                  dummySpace,
                                  dummyRotationMode,
                                  pLocalSpace,
                                  pDeleteTweenOnHit,
                                  pDeleteTweenOnOverlap,
                                  pDelay,
                                  pTimeScale,
                                  pTweenWhileGameIsPaused,
                                  pSequenceIndex);
}

// static public ---------------------------------------------------------------
UTweenRotator* UTweenRotatorStandardFactory::BP_JoinTweenRotateSceneComponentTo(UTweenContainer* pTweenContainer,
                                                                                USceneComponent* pTweenTarget,
                                                                                FRotator pTo,
                                                                                float pDuration,
                                                                                ETweenEaseType pEaseType,
                                                                                ETweenSpace pTweenSpace,
                                                                                ETweenRotationMode pRotationMode,
                                                                                bool pDeleteTweenOnHit,
                                                                                bool pDeleteTweenOnOverlap,
                                                                                float pDelay,
                                                                                float pTimeScale,
                                                                                bool pTweenWhileGameIsPaused,
                                                                                int32 pSequenceIndex)
{
    ETweenTargetType targetType = ETweenTargetType::SceneComponent;
    ETweenRotatorType tweenType = ETweenRotatorType::RotateTo;
    FRotator dummyFromRotator   = FRotator::ZeroRotator;
    bool localSpace = false;

    return CreateJoinTweenRotator(pTweenContainer,
                                  tweenType,
                                  pTweenTarget,
                                  targetType,
                                  dummyFromRotator,
                                  pTo,
                                  pDuration,
                                  pEaseType,
                                  pTweenSpace,
                                  pRotationMode,
                                  localSpace,
                                  pDeleteTweenOnHit,
                                  pDeleteTweenOnOverlap,
                                  pDelay,
                                  pTimeScale,
                                  pTweenWhileGameIsPaused,
                                  pSequenceIndex);
}

// static public ---------------------------------------------------------------
UTweenRotator* UTweenRotatorStandardFactory::BP_JoinTweenRotateSceneComponentBy(UTweenContainer* pTweenContainer,
                                                                                USceneComponent* pTweenTarget,
                                                                                FRotator pBy,
                                                                                float pDuration,
                                                                                ETweenEaseType pEaseType,
                                                                                bool pLocalSpace,
                                                                                bool pDeleteTweenOnHit,
                                                                                bool pDeleteTweenOnOverlap,
                                                                                float pDelay,
                                                                                float pTimeScale,
                                                                                bool pTweenWhileGameIsPaused,
                                                                                int32 pSequenceIndex)
{
    ETweenTargetType targetType          = ETweenTargetType::SceneComponent;
    ETweenRotatorType tweenType          = ETweenRotatorType::RotateBy;
    FRotator dummyFromRotator            = FRotator::ZeroRotator;
    ETweenSpace dummySpace               = ETweenSpace::World;
    ETweenRotationMode dummyRotationMode = ETweenRotationMode::ShortestPath;

    return CreateJoinTweenRotator(pTweenContainer,
                                  tweenType,
                                  pTweenTarget,
                                  targetType,
                                  dummyFromRotator,
                                  pBy,
                                  pDuration,
                                  pEaseType,
                                  dummySpace,
                                  dummyRotationMode,
                                  pLocalSpace,
                                  pDeleteTweenOnHit,
                                  pDeleteTweenOnOverlap,
                                  pDelay,
                                  pTimeScale,
                                  pTweenWhileGameIsPaused,
                                  pSequenceIndex);
}

/*
 **************************************************************************
 * Helper methods that create the actual Tweens
 **************************************************************************
 */

// static private --------------------------------------------------------------
UTweenRotator* UTweenRotatorStandardFactory::CreateAppendTweenRotator(UTweenContainer* pTweenContainer,
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
                                                                      int32 pSequenceIndex)
{
    UTweenRotator *outTween = nullptr;

    if (pTweenContainer != nullptr)
    {
        UTweenManagerComponent *tweenManagerInstance = pTweenContainer->OwningTweenManager;

        if (tweenManagerInstance != nullptr)
        {
            int32 tweenIndex = pSequenceIndex > -1 ? pSequenceIndex : pTweenContainer->GetSequencesNum();

            outTween = tweenManagerInstance->AppendTweenRotator(pTweenContainer,
                                                                tweenIndex,
                                                                pTweenType,
                                                                pTarget,
                                                                pTargetType,
                                                                pFrom,
                                                                pTo,
                                                                pDuration,
                                                                pEaseType,
                                                                pTweenSpace,
                                                                pRotationMode,
                                                                pLocalSpace,
                                                                pDeleteTweenOnHit,
                                                                pDeleteTweenOnOverlap,
                                                                pNumLoops,
                                                                pLoopType,
                                                                pDelay,
                                                                pTimeScale,
                                                                pTweenWhileGameIsPaused);
        }
    }
    else
    {
        UE_LOG(LogTweenMaker, Warning, TEXT("UTweenRotatorStandardFactory::CreateAppendTweenRotator() -> the Tween that had as target the "
                                            "object with name %s couldn't be added because the passed TweenContainer was null."), *pTarget->GetName());
    }

    return outTween;
}

// static private --------------------------------------------------------------
UTweenRotator* UTweenRotatorStandardFactory::CreateJoinTweenRotator(UTweenContainer* pTweenContainer,
                                                                    ETweenRotatorType pTweenType,
                                                                    UObject* pTweenTarget,
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
                                                                    int32 pSequenceIndex)
{
    UTweenRotator *outTween = nullptr;
    
    if (pTweenContainer != nullptr)
    {
        UTweenManagerComponent *tweenManagerInstance = pTweenContainer->OwningTweenManager;

        if (tweenManagerInstance != nullptr)
        {
            int32 tweenIndex = pSequenceIndex > -1 ? pSequenceIndex : pTweenContainer->GetSequencesNum() - 1;

            outTween = tweenManagerInstance->JoinTweenRotator(pTweenContainer,
                                                              tweenIndex,
                                                              pTweenType,
                                                              pTweenTarget,
                                                              pTargetType,
                                                              pFrom,
                                                              pTo,
                                                              pDuration,
                                                              pEaseType,
                                                              pTweenSpace,
                                                              pRotationMode,
                                                              pLocalSpace,
                                                              pDeleteTweenOnHit,
                                                              pDeleteTweenOnOverlap,
                                                              pDelay,
                                                              pTimeScale,
                                                              pTweenWhileGameIsPaused);
        }
    }
    else
    {
        UE_LOG(LogTweenMaker, Warning, TEXT("UTweenRotatorStandardFactory::CreateJoinTweenRotator() -> the Tween that had as target the "
                                            "object with name %s couldn't be added because the passed TweenContainer was null."), *pTweenTarget->GetName());
    }

    return outTween;
}

