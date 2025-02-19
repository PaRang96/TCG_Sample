// Copyright 2018 Francesco Desogus. All Rights Reserved.

#include "TweenFactory/Latent/TweenVectorLatentFactory.h"

#include "GameFramework/Actor.h"
#include "Tweens/TweenRotator.h"
#include "TweenContainer.h"

// public ----------------------------------------------------------------------
UTweenVectorLatentFactory::UTweenVectorLatentFactory(const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer)
{

}

// static public ---------------------------------------------------------------
UTweenVectorLatentFactory* UTweenVectorLatentFactory::BP_CreateLatentTweenMoveActorTo(UTweenManagerComponent* pTweenManagerComponent,
                                                                                      AActor* pTweenTarget,
                                                                                      UTweenContainer*& pOutTweenContainer,
                                                                                      UTweenVector*& pOutTween,
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
    pOutTweenContainer = pTweenManagerComponent != nullptr ? pTweenManagerComponent->CreateTweenContainer() 
                                                           : UTweenManagerComponent::CreateTweenContainerStatic();

    return BP_AppendLatentTweenMoveActorTo(pOutTweenContainer,
                                           pOutTween,
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
                                           pTweenWhileGameIsPaused);
}

// static public ---------------------------------------------------------------
UTweenVectorLatentFactory* UTweenVectorLatentFactory::BP_CreateLatentTweenMoveActorBy(UTweenManagerComponent* pTweenManagerComponent,
                                                                                      AActor* pTweenTarget,
                                                                                      UTweenContainer*& pOutTweenContainer,
                                                                                      UTweenVector*& pOutTween,
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
    pOutTweenContainer = pTweenManagerComponent != nullptr ? pTweenManagerComponent->CreateTweenContainer() 
                                                           : UTweenManagerComponent::CreateTweenContainerStatic();

    return BP_AppendLatentTweenMoveActorBy(pOutTweenContainer,
                                           pOutTween,
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
                                           pTweenWhileGameIsPaused);
}

// static public ---------------------------------------------------------------
UTweenVectorLatentFactory* UTweenVectorLatentFactory::BP_CreateLatentTweenScaleActorTo(UTweenManagerComponent* pTweenManagerComponent,
                                                                                       AActor* pTweenTarget,
                                                                                       UTweenContainer*& pOutTweenContainer,
                                                                                       UTweenVector*& pOutTween,
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
    pOutTweenContainer = pTweenManagerComponent != nullptr ? pTweenManagerComponent->CreateTweenContainer() 
                                                           : UTweenManagerComponent::CreateTweenContainerStatic();

    return BP_AppendLatentTweenScaleActorTo(pOutTweenContainer,
                                            pOutTween,
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
                                            pTweenWhileGameIsPaused);
}

// static public ---------------------------------------------------------------
UTweenVectorLatentFactory* UTweenVectorLatentFactory::BP_CreateLatentTweenScaleActorBy(UTweenManagerComponent* pTweenManagerComponent,
                                                                                       AActor* pTweenTarget,
                                                                                       UTweenContainer*& pOutTweenContainer,
                                                                                       UTweenVector*& pOutTween,
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
    pOutTweenContainer = pTweenManagerComponent != nullptr ? pTweenManagerComponent->CreateTweenContainer() 
                                                           : UTweenManagerComponent::CreateTweenContainerStatic();

    return BP_AppendLatentTweenScaleActorBy(pOutTweenContainer,
                                            pOutTween,
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
                                            pTweenWhileGameIsPaused);
}

// static public ---------------------------------------------------------------
UTweenVectorLatentFactory* UTweenVectorLatentFactory::BP_CreateLatentTweenMoveSceneComponentTo(UTweenManagerComponent* pTweenManagerComponent,
                                                                                               USceneComponent* pTweenTarget,
                                                                                               UTweenContainer*& pOutTweenContainer,
                                                                                               UTweenVector*& pOutTween,
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
    pOutTweenContainer = pTweenManagerComponent != nullptr ? pTweenManagerComponent->CreateTweenContainer() 
                                                           : UTweenManagerComponent::CreateTweenContainerStatic();

    return BP_AppendLatentTweenMoveSceneComponentTo(pOutTweenContainer,
                                                    pOutTween,
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
                                                    pTweenWhileGameIsPaused);
}

// static public ---------------------------------------------------------------
UTweenVectorLatentFactory* UTweenVectorLatentFactory::BP_CreateLatentTweenMoveSceneComponentBy(UTweenManagerComponent* pTweenManagerComponent,
                                                                                               USceneComponent* pTweenTarget,
                                                                                               UTweenContainer*& pOutTweenContainer,
                                                                                               UTweenVector*& pOutTween,
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
    pOutTweenContainer = pTweenManagerComponent != nullptr ? pTweenManagerComponent->CreateTweenContainer() 
                                                           : UTweenManagerComponent::CreateTweenContainerStatic();

    return BP_AppendLatentTweenMoveSceneComponentBy(pOutTweenContainer,
                                                    pOutTween,
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
                                                    pTweenWhileGameIsPaused);
}

// static public ---------------------------------------------------------------
UTweenVectorLatentFactory* UTweenVectorLatentFactory::BP_CreateLatentTweenScaleSceneComponentTo(UTweenManagerComponent* pTweenManagerComponent,
                                                                                                USceneComponent* pTweenTarget,
                                                                                                UTweenContainer*& pOutTweenContainer,
                                                                                                UTweenVector*& pOutTween,
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
    pOutTweenContainer = pTweenManagerComponent != nullptr ? pTweenManagerComponent->CreateTweenContainer() 
                                                           : UTweenManagerComponent::CreateTweenContainerStatic();

    return BP_AppendLatentTweenScaleSceneComponentTo(pOutTweenContainer,
                                                     pOutTween,
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
                                                     pTweenWhileGameIsPaused);
}

// static public ---------------------------------------------------------------
UTweenVectorLatentFactory* UTweenVectorLatentFactory::BP_CreateLatentTweenScaleSceneComponentBy(UTweenManagerComponent* pTweenManagerComponent,
                                                                                                USceneComponent* pTweenTarget,
                                                                                                UTweenContainer*& pOutTweenContainer,
                                                                                                UTweenVector*& pOutTween,
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
    pOutTweenContainer = pTweenManagerComponent != nullptr ? pTweenManagerComponent->CreateTweenContainer() 
                                                           : UTweenManagerComponent::CreateTweenContainerStatic();

    return BP_AppendLatentTweenMoveSceneComponentBy(pOutTweenContainer,
                                                    pOutTween,
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
                                                    pTweenWhileGameIsPaused);
}

// static public ---------------------------------------------------------------
UTweenVectorLatentFactory* UTweenVectorLatentFactory::BP_CreateLatentTweenCustomVector(UTweenManagerComponent* pTweenManagerComponent,
                                                                                       UObject* pTweenTarget,
                                                                                       UTweenContainer*& pOutTweenContainer,
                                                                                       UTweenVector*& pOutTween,
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
    pOutTweenContainer = pTweenManagerComponent != nullptr ? pTweenManagerComponent->CreateTweenContainer() 
                                                           : UTweenManagerComponent::CreateTweenContainerStatic();

    return BP_AppendLatentTweenCustomVector(pOutTweenContainer,
                                            pOutTween,
                                            pTweenTarget,
                                            pFrom,
                                            pTo,
                                            pDuration,
                                            pEaseType,
                                            pNumLoops,
                                            pLoopType,
                                            pDelay,
                                            pTimeScale,
                                            pTweenWhileGameIsPaused);
}

// static public ---------------------------------------------------------------
UTweenVectorLatentFactory* UTweenVectorLatentFactory::BP_AppendLatentTweenMoveActorTo(UTweenContainer* pTweenContainer,
                                                                                      UTweenVector*& OutTween,
                                                                                      AActor* pTweenTarget,
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
    ETweenTargetType targetType = ETweenTargetType::Actor;
    ETweenVectorType tweenType  = ETweenVectorType::MoveTo;
    FVector dummyFromVec        = FVector(0, 0, 0);

    return CreateProxyForAppendTweenVector(pTweenContainer,
                                           tweenType,
                                           pTweenTarget,
                                           targetType,
                                           dummyFromVec,
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
                                           OutTween);
}

// static public ---------------------------------------------------------------
UTweenVectorLatentFactory* UTweenVectorLatentFactory::BP_AppendLatentTweenMoveActorBy(UTweenContainer* pTweenContainer,
                                                                                      UTweenVector*& OutTween,
                                                                                      AActor* pTweenTarget,
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
    ETweenTargetType targetType = ETweenTargetType::Actor;
    ETweenVectorType tweenType  = ETweenVectorType::MoveBy;
    FVector dummyFromVec        = FVector(0, 0, 0);
    ETweenSpace dummySpace      = ETweenSpace::World;

    return CreateProxyForAppendTweenVector(pTweenContainer,
                                           tweenType,
                                           pTweenTarget,
                                           targetType,
                                           dummyFromVec,
                                           pBy,
                                           pDuration,
                                           pEaseType,
                                           dummySpace,
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
UTweenVectorLatentFactory* UTweenVectorLatentFactory::BP_AppendLatentTweenScaleActorTo(UTweenContainer* pTweenContainer,
                                                                                       UTweenVector*& OutTween,
                                                                                       AActor* pTweenTarget,
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
    ETweenTargetType targetType = ETweenTargetType::Actor;
    ETweenVectorType tweenType  = ETweenVectorType::ScaleTo;
    FVector dummyFromVec        = FVector(0, 0, 0);

    return CreateProxyForAppendTweenVector(pTweenContainer,
                                           tweenType,
                                           pTweenTarget,
                                           targetType,
                                           dummyFromVec,
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
                                           OutTween);
}

// static public ---------------------------------------------------------------
UTweenVectorLatentFactory* UTweenVectorLatentFactory::BP_AppendLatentTweenScaleActorBy(UTweenContainer* pTweenContainer,
                                                                                       UTweenVector*& OutTween,
                                                                                       AActor* pTweenTarget,
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
    ETweenTargetType targetType = ETweenTargetType::Actor;
    ETweenVectorType tweenType  = ETweenVectorType::ScaleBy;
    FVector dummyFromVec        = FVector(0, 0, 0);
    ETweenSpace dummySpace      = ETweenSpace::World;

    return CreateProxyForAppendTweenVector(pTweenContainer,
                                           tweenType,
                                           pTweenTarget,
                                           targetType,
                                           dummyFromVec,
                                           pBy,
                                           pDuration,
                                           pEaseType,
                                           dummySpace,
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
UTweenVectorLatentFactory* UTweenVectorLatentFactory::BP_AppendLatentTweenMoveSceneComponentTo(UTweenContainer* pTweenContainer,
                                                                                               UTweenVector*& OutTween,
                                                                                               USceneComponent* pTweenTarget,
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
    ETweenTargetType targetType = ETweenTargetType::SceneComponent;
    ETweenVectorType tweenType  = ETweenVectorType::MoveTo;
    FVector dummyFromVec        = FVector(0, 0, 0);

    return CreateProxyForAppendTweenVector(pTweenContainer,
                                           tweenType,
                                           pTweenTarget,
                                           targetType,
                                           dummyFromVec,
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
                                           OutTween);
}

// static public ---------------------------------------------------------------
UTweenVectorLatentFactory* UTweenVectorLatentFactory::BP_AppendLatentTweenMoveSceneComponentBy(UTweenContainer* pTweenContainer,
                                                                                               UTweenVector*& OutTween,
                                                                                               USceneComponent* pTweenTarget,
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
    ETweenTargetType targetType = ETweenTargetType::SceneComponent;
    ETweenVectorType tweenType  = ETweenVectorType::MoveBy;
    FVector dummyFromVec        = FVector(0, 0, 0);
    ETweenSpace dummySpace      = ETweenSpace::World;

    return CreateProxyForAppendTweenVector(pTweenContainer,
                                           tweenType,
                                           pTweenTarget,
                                           targetType,
                                           dummyFromVec,
                                           pBy,
                                           pDuration,
                                           pEaseType,
                                           dummySpace,
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
UTweenVectorLatentFactory* UTweenVectorLatentFactory::BP_AppendLatentTweenScaleSceneComponentTo(UTweenContainer* pTweenContainer,
                                                                                                UTweenVector*& OutTween,
                                                                                                USceneComponent* pTweenTarget,
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
    ETweenTargetType targetType = ETweenTargetType::SceneComponent;
    ETweenVectorType tweenType  = ETweenVectorType::ScaleTo;
    FVector dummyFromVec        = FVector(0, 0, 0);

    return CreateProxyForAppendTweenVector(pTweenContainer,
                                           tweenType,
                                           pTweenTarget,
                                           targetType,
                                           dummyFromVec,
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
                                           OutTween);
}

// static public ---------------------------------------------------------------
UTweenVectorLatentFactory* UTweenVectorLatentFactory::BP_AppendLatentTweenScaleSceneComponentBy(UTweenContainer* pTweenContainer,
                                                                                                UTweenVector*& OutTween,
                                                                                                USceneComponent* pTweenTarget,
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
    ETweenTargetType targetType = ETweenTargetType::SceneComponent;
    ETweenVectorType tweenType  = ETweenVectorType::ScaleBy;
    FVector dummyFromVec        = FVector(0, 0, 0);
    ETweenSpace dummySpace      = ETweenSpace::World;

    return CreateProxyForAppendTweenVector(pTweenContainer,
                                           tweenType,
                                           pTweenTarget,
                                           targetType,
                                           dummyFromVec,
                                           pBy,
                                           pDuration,
                                           pEaseType,
                                           dummySpace,
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
UTweenVectorLatentFactory* UTweenVectorLatentFactory::BP_AppendLatentTweenCustomVector(UTweenContainer* pTweenContainer,
                                                                                       UTweenVector*& OutTween,
                                                                                       UObject* pTweenTarget,
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
    ETweenTargetType targetType = ETweenTargetType::Custom;
    ETweenVectorType tweenType  = ETweenVectorType::Custom;
    ETweenSpace dummySpace      = ETweenSpace::World;

    return CreateProxyForAppendTweenVector(pTweenContainer,
                                           tweenType,
                                           pTweenTarget,
                                           targetType,
                                           pFrom,
                                           pTo,
                                           pDuration,
                                           pEaseType,
                                           dummySpace,
                                           false,
                                           false,
                                           pNumLoops,
                                           pLoopType,
                                           pDelay,
                                           pTimeScale,
                                           pTweenWhileGameIsPaused,
                                           OutTween);
}

// static public ---------------------------------------------------------------
UTweenVectorLatentFactory* UTweenVectorLatentFactory::BP_JoinLatentTweenMoveActorTo(UTweenContainer* pTweenContainer,
                                                                                    UTweenVector*& OutTween,
                                                                                    AActor* pTweenTarget,
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
    ETweenTargetType targetType = ETweenTargetType::Actor;
    ETweenVectorType tweenType  = ETweenVectorType::MoveTo;
    FVector dummyFromVec        = FVector(0, 0, 0);

    return CreateProxyForJoinTweenVector(pTweenContainer,
                                         tweenType,
                                         pTweenTarget,
                                         targetType,
                                         dummyFromVec,
                                         pTo,
                                         pDuration,
                                         pEaseType,
                                         pTweenSpace,
                                         pDeleteTweenOnHit,
                                         pDeleteTweenOnOverlap,
                                         pDelay,
                                         pTimeScale,
                                         pTweenWhileGameIsPaused,
                                         OutTween);
}

// static public ---------------------------------------------------------------
UTweenVectorLatentFactory* UTweenVectorLatentFactory::BP_JoinLatentTweenMoveActorBy(UTweenContainer* pTweenContainer,
                                                                                    UTweenVector*& OutTween,
                                                                                    AActor* pTweenTarget,
                                                                                    FVector pBy,
                                                                                    float pDuration,
                                                                                    ETweenEaseType pEaseType,
                                                                                    bool pDeleteTweenOnHit,
                                                                                    bool pDeleteTweenOnOverlap,
                                                                                    float pDelay,
                                                                                    float pTimeScale,
                                                                                    bool pTweenWhileGameIsPaused)
{
    ETweenTargetType targetType = ETweenTargetType::Actor;
    ETweenVectorType tweenType  = ETweenVectorType::MoveBy;
    FVector dummyFromVec        = FVector(0, 0, 0);
    ETweenSpace dummySpace      = ETweenSpace::World;

    return CreateProxyForJoinTweenVector(pTweenContainer,
                                         tweenType,
                                         pTweenTarget,
                                         targetType,
                                         dummyFromVec,
                                         pBy,
                                         pDuration,
                                         pEaseType,
                                         dummySpace,
                                         pDeleteTweenOnHit,
                                         pDeleteTweenOnOverlap,
                                         pDelay,
                                         pTimeScale,
                                         pTweenWhileGameIsPaused,
                                         OutTween);
}

// static public ---------------------------------------------------------------
UTweenVectorLatentFactory* UTweenVectorLatentFactory::BP_JoinLatentTweenScaleActorTo(UTweenContainer* pTweenContainer,
                                                                                     UTweenVector*& OutTween,
                                                                                     AActor* pTweenTarget,
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
    ETweenTargetType targetType = ETweenTargetType::Actor;
    ETweenVectorType tweenType  = ETweenVectorType::ScaleTo;
    FVector dummyFromVec        = FVector(0, 0, 0);

    return CreateProxyForJoinTweenVector(pTweenContainer,
                                         tweenType,
                                         pTweenTarget,
                                         targetType,
                                         dummyFromVec,
                                         pTo,
                                         pDuration,
                                         pEaseType,
                                         pTweenSpace,
                                         pDeleteTweenOnHit,
                                         pDeleteTweenOnOverlap,
                                         pDelay,
                                         pTimeScale,
                                         pTweenWhileGameIsPaused,
                                         OutTween);
}

// static public ---------------------------------------------------------------
UTweenVectorLatentFactory* UTweenVectorLatentFactory::BP_JoinLatentTweenScaleActorBy(UTweenContainer* pTweenContainer,
                                                                                     UTweenVector*& OutTween,
                                                                                     AActor* pTweenTarget,
                                                                                     FVector pBy,
                                                                                     float pDuration,
                                                                                     ETweenEaseType pEaseType,
                                                                                     bool pDeleteTweenOnHit,
                                                                                     bool pDeleteTweenOnOverlap,
                                                                                     float pDelay,
                                                                                     float pTimeScale,
                                                                                     bool pTweenWhileGameIsPaused)
{
    ETweenTargetType targetType = ETweenTargetType::Actor;
    ETweenVectorType tweenType  = ETweenVectorType::ScaleBy;
    FVector dummyFromVec        = FVector(0, 0, 0);
    ETweenSpace dummySpace      = ETweenSpace::World;

    return CreateProxyForJoinTweenVector(pTweenContainer,
                                         tweenType,
                                         pTweenTarget,
                                         targetType,
                                         dummyFromVec,
                                         pBy,
                                         pDuration,
                                         pEaseType,
                                         dummySpace,
                                         pDeleteTweenOnHit,
                                         pDeleteTweenOnOverlap,
                                         pDelay,
                                         pTimeScale,
                                         pTweenWhileGameIsPaused,
                                         OutTween);
}

// static public ---------------------------------------------------------------
UTweenVectorLatentFactory* UTweenVectorLatentFactory::BP_JoinLatentTweenMoveSceneComponentTo(UTweenContainer* pTweenContainer,
                                                                                             UTweenVector*& OutTween,
                                                                                             USceneComponent* pTweenTarget,
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
    ETweenTargetType targetType = ETweenTargetType::SceneComponent;
    ETweenVectorType tweenType  = ETweenVectorType::MoveTo;
    FVector dummyFromVec        = FVector(0, 0, 0);

    return CreateProxyForJoinTweenVector(pTweenContainer,
                                         tweenType,
                                         pTweenTarget,
                                         targetType,
                                         dummyFromVec,
                                         pTo,
                                         pDuration,
                                         pEaseType,
                                         pTweenSpace,
                                         pDeleteTweenOnHit,
                                         pDeleteTweenOnOverlap,
                                         pDelay,
                                         pTimeScale,
                                         pTweenWhileGameIsPaused,
                                         OutTween);
}

// static public ---------------------------------------------------------------
UTweenVectorLatentFactory* UTweenVectorLatentFactory::BP_JoinLatentTweenMoveSceneComponentBy(UTweenContainer* pTweenContainer,
                                                                                             UTweenVector*& OutTween,
                                                                                             USceneComponent* pTweenTarget,
                                                                                             FVector pBy,
                                                                                             float pDuration,
                                                                                             ETweenEaseType pEaseType,
                                                                                             bool pDeleteTweenOnHit,
                                                                                             bool pDeleteTweenOnOverlap,
                                                                                             float pDelay,
                                                                                             float pTimeScale,
                                                                                             bool pTweenWhileGameIsPaused)
{
    ETweenTargetType targetType = ETweenTargetType::SceneComponent;
    ETweenVectorType tweenType  = ETweenVectorType::MoveBy;
    FVector dummyFromVec        = FVector(0, 0, 0);
    ETweenSpace dummySpace      = ETweenSpace::World;

    return CreateProxyForJoinTweenVector(pTweenContainer,
                                         tweenType,
                                         pTweenTarget,
                                         targetType,
                                         dummyFromVec,
                                         pBy,
                                         pDuration,
                                         pEaseType,
                                         dummySpace,
                                         pDeleteTweenOnHit,
                                         pDeleteTweenOnOverlap,
                                         pDelay,
                                         pTimeScale,
                                         pTweenWhileGameIsPaused,
                                         OutTween);
}

// static public ---------------------------------------------------------------
UTweenVectorLatentFactory* UTweenVectorLatentFactory::BP_JoinLatentTweenScaleSceneComponentTo(UTweenContainer* pTweenContainer,
                                                                                              UTweenVector*& OutTween,
                                                                                              USceneComponent* pTweenTarget,
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
    ETweenTargetType targetType = ETweenTargetType::SceneComponent;
    ETweenVectorType tweenType  = ETweenVectorType::ScaleTo;
    FVector dummyFromVec        = FVector(0, 0, 0);

    return CreateProxyForJoinTweenVector(pTweenContainer,
                                         tweenType,
                                         pTweenTarget,
                                         targetType,
                                         dummyFromVec,
                                         pTo,
                                         pDuration,
                                         pEaseType,
                                         pTweenSpace,
                                         pDeleteTweenOnHit,
                                         pDeleteTweenOnOverlap,
                                         pDelay,
                                         pTimeScale,
                                         pTweenWhileGameIsPaused,
                                         OutTween);
}

// static public ---------------------------------------------------------------
UTweenVectorLatentFactory* UTweenVectorLatentFactory::BP_JoinLatentTweenScaleSceneComponentBy(UTweenContainer* pTweenContainer,
                                                                                              UTweenVector*& OutTween,
                                                                                              USceneComponent* pTweenTarget,
                                                                                              FVector pBy,
                                                                                              float pDuration,
                                                                                              ETweenEaseType pEaseType,
                                                                                              bool pDeleteTweenOnHit,
                                                                                              bool pDeleteTweenOnOverlap,
                                                                                              float pDelay,
                                                                                              float pTimeScale,
                                                                                              bool pTweenWhileGameIsPaused)
{
    ETweenTargetType targetType = ETweenTargetType::SceneComponent;
    ETweenVectorType tweenType  = ETweenVectorType::ScaleBy;
    FVector dummyFromVec        = FVector(0, 0, 0);
    ETweenSpace dummySpace      = ETweenSpace::World;

    return CreateProxyForJoinTweenVector(pTweenContainer,
                                         tweenType,
                                         pTweenTarget,
                                         targetType,
                                         dummyFromVec,
                                         pBy,
                                         pDuration,
                                         pEaseType,
                                         dummySpace,
                                         pDeleteTweenOnHit,
                                         pDeleteTweenOnOverlap,
                                         pDelay,
                                         pTimeScale,
                                         pTweenWhileGameIsPaused,
                                         OutTween);
}

// static public ---------------------------------------------------------------
UTweenVectorLatentFactory* UTweenVectorLatentFactory::BP_JoinLatentTweenCustomVector(UTweenContainer* pTweenContainer,
                                                                                     UTweenVector*& OutTween,
                                                                                     UObject* pTweenTarget,
                                                                                     FVector pFrom,
                                                                                     FVector pTo,
                                                                                     float pDuration,
                                                                                     ETweenEaseType pEaseType,
                                                                                     float pDelay,
                                                                                     float pTimeScale,
                                                                                     bool pTweenWhileGameIsPaused)
{
    ETweenTargetType targetType = ETweenTargetType::Custom;
    ETweenVectorType tweenType  = ETweenVectorType::Custom;
    ETweenSpace dummySpace      = ETweenSpace::World;

    return CreateProxyForJoinTweenVector(pTweenContainer,
                                         tweenType,
                                         pTweenTarget,
                                         targetType,
                                         pFrom,
                                         pTo,
                                         pDuration,
                                         pEaseType,
                                         dummySpace,
                                         false,
                                         false,
                                         pDelay,
                                         pTimeScale,
                                         pTweenWhileGameIsPaused,
                                         OutTween);
}

// public ----------------------------------------------------------------------
void UTweenVectorLatentFactory::Activate()
{
    Super::Activate();
}

// static private --------------------------------------------------------------
UTweenVectorLatentFactory* UTweenVectorLatentFactory::CreateProxyForAppendTweenVector(UTweenContainer* pTweenContainer,
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
                                                                                      UTweenVector*& OutTween)
{
    UTweenVectorLatentFactory* proxy = NewObject<UTweenVectorLatentFactory>();

    if (pTweenContainer != nullptr)
    {
        UTweenManagerComponent* instance = pTweenContainer->OwningTweenManager;

        if (instance != nullptr)
        {
            int32 tweenIndex = pTweenContainer->GetSequencesNum();

            OutTween = instance->AppendTweenVector(pTweenContainer,
                                                   tweenIndex,
                                                   pTweenType,
                                                   pTarget,
                                                   pTargetType,
                                                   pFrom,
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
                                                   proxy);
        }
    }
    else
    {
        UE_LOG(LogTweenMaker, Warning, TEXT("UTweenVectorLatentFactory::CreateProxyForAppendTweenVector() -> the Tween that had as target the "
                                            "object with name %s couldn't be added because the passed TweenContainer was null."), *pTarget->GetName());
    }

    return proxy;
}

// static private --------------------------------------------------------------
UTweenVectorLatentFactory* UTweenVectorLatentFactory::CreateProxyForJoinTweenVector(UTweenContainer* pTweenContainer,
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
                                                                                    UTweenVector*& OutTween)
{
    UTweenVectorLatentFactory* proxy = NewObject<UTweenVectorLatentFactory>();

    if (pTweenContainer != nullptr)
    {
        UTweenManagerComponent* instance = pTweenContainer->OwningTweenManager;

        if (instance != nullptr)
        {
            int32 tweenIndex = pTweenContainer->GetSequencesNum() - 1;

            OutTween = instance->JoinTweenVector(pTweenContainer,
                                                 tweenIndex,
                                                 pTweenType,
                                                 pTarget,
                                                 pTargetType,
                                                 pFrom,
                                                 pTo,
                                                 pDuration,
                                                 pEaseType,
                                                 pTweenSpace,
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
        UE_LOG(LogTweenMaker, Warning, TEXT("UTweenVectorLatentFactory::CreateProxyForJoinTweenVector() -> the Tween that had as target the "
                                            "object with name %s couldn't be added because the passed TweenContainer was null."), *pTarget->GetName());
    }

    return proxy;
}