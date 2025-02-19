// Copyright 2018 Francesco Desogus. All Rights Reserved.

#include "TweenFactory/Latent/TweenRotatorLatentFactory.h"

#include "GameFramework/Actor.h"
#include "Tweens/TweenRotator.h"
#include "TweenContainer.h"

// public ----------------------------------------------------------------------
UTweenRotatorLatentFactory::UTweenRotatorLatentFactory(const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer)
{

}

// static public ---------------------------------------------------------------
UTweenRotatorLatentFactory* UTweenRotatorLatentFactory::BP_CreateLatentTweenRotateActorTo(UTweenManagerComponent* pTweenManagerComponent,
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
                                                                                          bool pTweenWhileGameIsPaused)
{
    pOutTweenContainer = pTweenManagerComponent != nullptr ? pTweenManagerComponent->CreateTweenContainer() 
                                                           : UTweenManagerComponent::CreateTweenContainerStatic();

    return BP_AppendLatentTweenRotateActorTo(pOutTweenContainer,
                                             pOutTween,
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
                                             pTweenWhileGameIsPaused);
}

// static public ---------------------------------------------------------------
UTweenRotatorLatentFactory* UTweenRotatorLatentFactory::BP_CreateLatentTweenRotateActorBy(UTweenManagerComponent* pTweenManagerComponent,
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
                                                                                          bool pTweenWhileGameIsPaused)
{
    pOutTweenContainer = pTweenManagerComponent != nullptr ? pTweenManagerComponent->CreateTweenContainer() 
                                                           : UTweenManagerComponent::CreateTweenContainerStatic();

    return BP_AppendLatentTweenRotateActorBy(pOutTweenContainer,
                                             pOutTween,
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
                                             pTweenWhileGameIsPaused);
}

// static public ---------------------------------------------------------------
UTweenRotatorLatentFactory* UTweenRotatorLatentFactory::BP_CreateLatentTweenRotateSceneComponentTo(UTweenManagerComponent* pTweenManagerComponent,
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
                                                                                                   bool pTweenWhileGameIsPaused)
{
    pOutTweenContainer = pTweenManagerComponent != nullptr ? pTweenManagerComponent->CreateTweenContainer() 
                                                           : UTweenManagerComponent::CreateTweenContainerStatic();

    return BP_AppendLatentTweenRotateSceneComponentTo(pOutTweenContainer,
                                                      pOutTween,
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
                                                      pTweenWhileGameIsPaused);
}

// static public ---------------------------------------------------------------
UTweenRotatorLatentFactory* UTweenRotatorLatentFactory::BP_CreateLatentTweenRotateSceneComponentBy(UTweenManagerComponent* pTweenManagerComponent,
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
                                                                                                   bool pTweenWhileGameIsPaused)
{
    pOutTweenContainer = pTweenManagerComponent != nullptr ? pTweenManagerComponent->CreateTweenContainer() 
                                                           : UTweenManagerComponent::CreateTweenContainerStatic();

    return BP_AppendLatentTweenRotateSceneComponentBy(pOutTweenContainer,
                                                      pOutTween,
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
                                                      pTweenWhileGameIsPaused);
}

// static public ---------------------------------------------------------------
UTweenRotatorLatentFactory* UTweenRotatorLatentFactory::BP_AppendLatentTweenRotateActorTo(UTweenContainer* pTweenContainer,
                                                                                          UTweenRotator*& OutTween,
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
                                                                                          bool pTweenWhileGameIsPaused)
{
    ETweenTargetType targetType = ETweenTargetType::Actor;
    ETweenRotatorType tweenType = ETweenRotatorType::RotateTo;
    FRotator dummyFromRotator   = FRotator::ZeroRotator;
    bool localSpace = false; // RotateTo is never in local space

    return CreateProxyForAppendTweenRotator(pTweenContainer,
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
                                            OutTween);
}

// static public ---------------------------------------------------------------
UTweenRotatorLatentFactory* UTweenRotatorLatentFactory::BP_AppendLatentTweenRotateActorBy(UTweenContainer* pTweenContainer,
                                                                                          UTweenRotator*& OutTween,
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
                                                                                          bool pTweenWhileGameIsPaused)
{
    ETweenTargetType targetType          = ETweenTargetType::Actor;
    ETweenRotatorType tweenType          = ETweenRotatorType::RotateBy;
    FRotator dummyFromRotator            = FRotator::ZeroRotator;
    ETweenSpace dummySpace               = ETweenSpace::World;
    ETweenRotationMode dummyRotationMode = ETweenRotationMode::ShortestPath;

    return CreateProxyForAppendTweenRotator(pTweenContainer,
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
                                            OutTween);
}

// static public ---------------------------------------------------------------
UTweenRotatorLatentFactory* UTweenRotatorLatentFactory::BP_AppendLatentTweenRotateSceneComponentTo(UTweenContainer* pTweenContainer,
                                                                                                   UTweenRotator*& OutTween,
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
                                                                                                   bool pTweenWhileGameIsPaused)
{
    ETweenTargetType targetType = ETweenTargetType::SceneComponent;
    ETweenRotatorType tweenType = ETweenRotatorType::RotateTo;
    FRotator dummyFromRotator   = FRotator::ZeroRotator;
    bool localSpace = false; 

    return CreateProxyForAppendTweenRotator(pTweenContainer,
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
                                            OutTween);
}

// static public ---------------------------------------------------------------
UTweenRotatorLatentFactory* UTweenRotatorLatentFactory::BP_AppendLatentTweenRotateSceneComponentBy(UTweenContainer* pTweenContainer,
                                                                                                   UTweenRotator*& OutTween,
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
                                                                                                   bool pTweenWhileGameIsPaused)
{
    ETweenTargetType targetType          = ETweenTargetType::SceneComponent;
    ETweenRotatorType tweenType          = ETweenRotatorType::RotateBy;
    FRotator dummyFromRotator            = FRotator::ZeroRotator;
    ETweenSpace dummySpace               = ETweenSpace::World;
    ETweenRotationMode dummyRotationMode = ETweenRotationMode::ShortestPath;

    return CreateProxyForAppendTweenRotator(pTweenContainer,
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
                                            OutTween);
}

// static public ---------------------------------------------------------------
UTweenRotatorLatentFactory* UTweenRotatorLatentFactory::BP_JoinLatentTweenRotateActorTo(UTweenContainer* pTweenContainer,
                                                                                        UTweenRotator*& OutTween,
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
                                                                                        bool pTweenWhileGameIsPaused)
{
    ETweenTargetType targetType = ETweenTargetType::Actor;
    ETweenRotatorType tweenType = ETweenRotatorType::RotateTo;
    FRotator dummyFromRotator   = FRotator::ZeroRotator;
    bool localSpace = false;

    return CreateProxyForJoinTweenRotator(pTweenContainer,
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
                                          OutTween);
}

// static public ---------------------------------------------------------------
UTweenRotatorLatentFactory* UTweenRotatorLatentFactory::BP_JoinLatentTweenRotateActorBy(UTweenContainer* pTweenContainer,
                                                                                        UTweenRotator*& OutTween,
                                                                                        AActor* pTweenTarget,
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
    ETweenTargetType targetType          = ETweenTargetType::Actor;
    ETweenRotatorType tweenType          = ETweenRotatorType::RotateBy;
    FRotator dummyFromRotator            = FRotator::ZeroRotator;
    ETweenSpace dummySpace               = ETweenSpace::World;
    ETweenRotationMode dummyRotationMode = ETweenRotationMode::ShortestPath;

    return CreateProxyForJoinTweenRotator(pTweenContainer,
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
                                          OutTween);
}

// static public ---------------------------------------------------------------
UTweenRotatorLatentFactory* UTweenRotatorLatentFactory::BP_JoinLatentTweenRotateSceneComponentTo(UTweenContainer* pTweenContainer,
                                                                                                 UTweenRotator*& OutTween,
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
                                                                                                 bool pTweenWhileGameIsPaused)
{
    ETweenTargetType targetType = ETweenTargetType::SceneComponent;
    ETweenRotatorType tweenType = ETweenRotatorType::RotateTo;
    FRotator dummyFromRotator   = FRotator::ZeroRotator;
    bool localSpace = false;

    return CreateProxyForJoinTweenRotator(pTweenContainer,
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
                                          OutTween);
}

// static public ---------------------------------------------------------------
UTweenRotatorLatentFactory* UTweenRotatorLatentFactory::BP_JoinLatentTweenRotateSceneComponentBy(UTweenContainer* pTweenContainer,
                                                                                                 UTweenRotator*& OutTween,
                                                                                                 USceneComponent* pTweenTarget,
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
    ETweenTargetType targetType          = ETweenTargetType::SceneComponent;
    ETweenRotatorType tweenType          = ETweenRotatorType::RotateBy;
    FRotator dummyFromRotator            = FRotator::ZeroRotator;
    ETweenSpace dummySpace               = ETweenSpace::World;
    ETweenRotationMode dummyRotationMode = ETweenRotationMode::ShortestPath;

    return CreateProxyForJoinTweenRotator(pTweenContainer,
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
                                          OutTween);
}

// public ----------------------------------------------------------------------
void UTweenRotatorLatentFactory::Activate()
{
    Super::Activate();
}

// static private --------------------------------------------------------------
UTweenRotatorLatentFactory* UTweenRotatorLatentFactory::CreateProxyForAppendTweenRotator(UTweenContainer* pTweenContainer,
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
                                                                                         UTweenRotator*& OutTween)
{
    UTweenRotatorLatentFactory* proxy = NewObject<UTweenRotatorLatentFactory>();

    if (pTweenContainer != nullptr)
    {
        UTweenManagerComponent* instance = pTweenContainer->OwningTweenManager;

        if (instance != nullptr)
        {
            int32 tweenIndex = pTweenContainer->GetSequencesNum();

            OutTween = instance->AppendTweenRotator(pTweenContainer,
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
                                                    pTweenWhileGameIsPaused,
                                                    proxy);
        }
    }
    else
    {
        UE_LOG(LogTweenMaker, Warning, TEXT("UTweenRotatorLatentFactory::CreateProxyForAppendTweenRotator() -> the Tween that had as target the "
                                            "object with name %s couldn't be added because the passed TweenContainer was null."), *pTarget->GetName());
    }

    return proxy;
}

// static private --------------------------------------------------------------
UTweenRotatorLatentFactory* UTweenRotatorLatentFactory::CreateProxyForJoinTweenRotator(UTweenContainer* pTweenContainer,
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
                                                                                       UTweenRotator*& OutTween)
{
    UTweenRotatorLatentFactory* proxy = NewObject<UTweenRotatorLatentFactory>();

    if (pTweenContainer != nullptr)
    {
        UTweenManagerComponent* instance = pTweenContainer->OwningTweenManager;

        if (instance != nullptr)
        {
            int32 tweenIndex = pTweenContainer->GetSequencesNum() - 1;

            OutTween = instance->JoinTweenRotator(pTweenContainer,
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
                                                  pDelay,
                                                  pTimeScale,
                                                  pTweenWhileGameIsPaused,
                                                  proxy);
        }
    }
    else
    {
        UE_LOG(LogTweenMaker, Warning, TEXT("UTweenRotatorLatentFactory::CreateProxyForJoinTweenRotator() -> the Tween that had as target the "
                                            "object with name %s couldn't be added because the passed TweenContainer was null."), *pTarget->GetName());
    }

    return proxy;
}

