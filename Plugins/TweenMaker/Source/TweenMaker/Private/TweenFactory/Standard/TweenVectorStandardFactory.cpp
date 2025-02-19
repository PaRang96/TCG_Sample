// Copyright 2018 Francesco Desogus. All Rights Reserved.

#include "TweenFactory/Standard/TweenVectorStandardFactory.h"

#include "GameFramework/Actor.h"
#include "TweenContainer.h"

// public ----------------------------------------------------------------------
UTweenVectorStandardFactory::UTweenVectorStandardFactory(const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer)
{

}

// static public ---------------------------------------------------------------
void UTweenVectorStandardFactory::BP_CreateTweenMoveActorTo(UTweenManagerComponent* pTweenManagerComponent,
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
                                                            bool pTweenWhileGameIsPaused,
                                                            int32 pSequenceIndex)

{
    pOutTweenContainer = pTweenManagerComponent != nullptr ? pTweenManagerComponent->CreateTweenContainer()
                                                           : UTweenManagerComponent::CreateTweenContainerStatic();

    pOutTween = BP_AppendTweenMoveActorTo(pOutTweenContainer,
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
                                          pSequenceIndex);
}

// static public ---------------------------------------------------------------
void UTweenVectorStandardFactory::BP_CreateTweenMoveActorBy(UTweenManagerComponent* pTweenManagerComponent,
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
                                                            bool pTweenWhileGameIsPaused,
                                                            int32 pSequenceIndex)
{
    pOutTweenContainer = pTweenManagerComponent != nullptr ? pTweenManagerComponent->CreateTweenContainer()
                                                           : UTweenManagerComponent::CreateTweenContainerStatic();
    
    pOutTween = BP_AppendTweenMoveActorBy(pOutTweenContainer,
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
                                          pSequenceIndex);
}

// static public ---------------------------------------------------------------
void UTweenVectorStandardFactory::BP_CreateTweenScaleActorTo(UTweenManagerComponent* pTweenManagerComponent,
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
                                                             bool pTweenWhileGameIsPaused, int32 pSequenceIndex)
{
    pOutTweenContainer = pTweenManagerComponent != nullptr ? pTweenManagerComponent->CreateTweenContainer()
                                                           : UTweenManagerComponent::CreateTweenContainerStatic();
    
    pOutTween = BP_AppendTweenScaleActorTo(pOutTweenContainer,
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
                                           pSequenceIndex);
}

// static public ---------------------------------------------------------------
void UTweenVectorStandardFactory::BP_CreateTweenScaleActorBy(UTweenManagerComponent* pTweenManagerComponent,
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
                                                             bool pTweenWhileGameIsPaused,
                                                             int32 pSequenceIndex)
{
    pOutTweenContainer = pTweenManagerComponent != nullptr ? pTweenManagerComponent->CreateTweenContainer()
                                                           : UTweenManagerComponent::CreateTweenContainerStatic();
    
    pOutTween = BP_AppendTweenScaleActorBy(pOutTweenContainer,
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
                                           pSequenceIndex);
}

// static public ---------------------------------------------------------------
void UTweenVectorStandardFactory::BP_CreateTweenMoveSceneComponentTo(UTweenManagerComponent* pTweenManagerComponent,
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
                                                                     bool pTweenWhileGameIsPaused,
                                                                     int32 pSequenceIndex)
{
    pOutTweenContainer = pTweenManagerComponent != nullptr ? pTweenManagerComponent->CreateTweenContainer()
                                                           : UTweenManagerComponent::CreateTweenContainerStatic();
    
    pOutTween = BP_AppendTweenMoveSceneComponentTo(pOutTweenContainer,
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
                                                   pSequenceIndex);
}

// static public ---------------------------------------------------------------
void UTweenVectorStandardFactory::BP_CreateTweenMoveSceneComponentBy(UTweenManagerComponent* pTweenManagerComponent,
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
                                                                     bool pTweenWhileGameIsPaused,
                                                                     int32 pSequenceIndex)
{
    pOutTweenContainer = pTweenManagerComponent != nullptr ? pTweenManagerComponent->CreateTweenContainer()
                                                           : UTweenManagerComponent::CreateTweenContainerStatic();
    
    pOutTween = BP_AppendTweenMoveSceneComponentBy(pOutTweenContainer,
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
                                                   pSequenceIndex);

}

// static public ---------------------------------------------------------------
void UTweenVectorStandardFactory::BP_CreateTweenScaleSceneComponentTo(UTweenManagerComponent* pTweenManagerComponent,
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
                                                                      bool pTweenWhileGameIsPaused,
                                                                      int32 pSequenceIndex)
{
    pOutTweenContainer = pTweenManagerComponent != nullptr ? pTweenManagerComponent->CreateTweenContainer()
                                                           : UTweenManagerComponent::CreateTweenContainerStatic();
    
    pOutTween = BP_AppendTweenScaleSceneComponentTo(pOutTweenContainer,
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
                                                    pSequenceIndex);
}

// static public ---------------------------------------------------------------
void UTweenVectorStandardFactory::BP_CreateTweenScaleSceneComponentBy(UTweenManagerComponent* pTweenManagerComponent,
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
                                                                      bool pTweenWhileGameIsPaused,
                                                                      int32 pSequenceIndex)
{
    pOutTweenContainer = pTweenManagerComponent != nullptr ? pTweenManagerComponent->CreateTweenContainer()
                                                           : UTweenManagerComponent::CreateTweenContainerStatic();
    
    pOutTween = BP_AppendTweenScaleSceneComponentBy(pOutTweenContainer,
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
                                                    pSequenceIndex);
}

// static public ---------------------------------------------------------------
void UTweenVectorStandardFactory::BP_CreateTweenCustomVector(UTweenManagerComponent* pTweenManagerComponent,
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
                                                             bool pTweenWhileGameIsPaused,
                                                             int32 pSequenceIndex)
{
    pOutTweenContainer = pTweenManagerComponent != nullptr ? pTweenManagerComponent->CreateTweenContainer()
                                                           : UTweenManagerComponent::CreateTweenContainerStatic();
    
    pOutTween = BP_AppendTweenCustomVector(pOutTweenContainer,
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
                                           pSequenceIndex);
}

// static public ---------------------------------------------------------------
UTweenVector* UTweenVectorStandardFactory::BP_AppendTweenMoveActorTo(UTweenContainer* pTweenContainer,
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
                                                                     bool pTweenWhileGameIsPaused,
                                                                     int32 pSequenceIndex)
{
    ETweenTargetType targetType = ETweenTargetType::Actor;
    ETweenVectorType tweenType  = ETweenVectorType::MoveTo;
    FVector dummyFromVec        = FVector(0, 0, 0);

    return CreateAppendTweenVector(pTweenContainer,
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
                                   pSequenceIndex);
}

// static public ---------------------------------------------------------------
UTweenVector* UTweenVectorStandardFactory::BP_AppendTweenMoveActorBy(UTweenContainer* pTweenContainer,
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
                                                                     bool pTweenWhileGameIsPaused,
                                                                     int32 pSequenceIndex)
{
    ETweenTargetType targetType = ETweenTargetType::Actor;
    ETweenVectorType tweenType  = ETweenVectorType::MoveBy;
    FVector dummyFromVec        = FVector(0, 0, 0);
    ETweenSpace dummySpace      = ETweenSpace::World;

    return CreateAppendTweenVector(pTweenContainer,
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
                                   pSequenceIndex);
}

// static public ---------------------------------------------------------------
UTweenVector* UTweenVectorStandardFactory::BP_AppendTweenScaleActorTo(UTweenContainer* pTweenContainer,
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
                                                                      bool pTweenWhileGameIsPaused,
                                                                      int32 pSequenceIndex)
{
    ETweenTargetType targetType = ETweenTargetType::Actor;
    ETweenVectorType tweenType  = ETweenVectorType::ScaleTo;
    FVector dummyFromVec        = FVector(0, 0, 0);

    return CreateAppendTweenVector(pTweenContainer,
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
                                   pSequenceIndex);
}

// static public ---------------------------------------------------------------
UTweenVector* UTweenVectorStandardFactory::BP_AppendTweenScaleActorBy(UTweenContainer* pTweenContainer,
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
                                                                      bool pTweenWhileGameIsPaused,
                                                                      int32 pSequenceIndex)
{
    ETweenTargetType targetType = ETweenTargetType::Actor;
    ETweenVectorType tweenType  = ETweenVectorType::ScaleBy;
    FVector dummyFromVec        = FVector(0, 0, 0);
    ETweenSpace dummySpace      = ETweenSpace::World;

    return CreateAppendTweenVector(pTweenContainer,
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
                                   pSequenceIndex);
}

// static public ---------------------------------------------------------------
UTweenVector* UTweenVectorStandardFactory::BP_AppendTweenMoveSceneComponentTo(UTweenContainer* pTweenContainer,
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
                                                                              bool pTweenWhileGameIsPaused,
                                                                              int32 pSequenceIndex)
{
    ETweenTargetType targetType = ETweenTargetType::SceneComponent;
    ETweenVectorType tweenType  = ETweenVectorType::MoveTo;
    FVector dummyFromVec        = FVector(0, 0, 0);

    return CreateAppendTweenVector(pTweenContainer,
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
                                   pSequenceIndex);
}

// static public ---------------------------------------------------------------
UTweenVector* UTweenVectorStandardFactory::BP_AppendTweenMoveSceneComponentBy(UTweenContainer* pTweenContainer,
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
                                                                              bool pTweenWhileGameIsPaused,
                                                                              int32 pSequenceIndex)
{
    ETweenTargetType targetType = ETweenTargetType::SceneComponent;
    ETweenVectorType tweenType  = ETweenVectorType::MoveBy;
    FVector dummyFromVec        = FVector(0, 0, 0);
    ETweenSpace dummySpace      = ETweenSpace::World;

    return CreateAppendTweenVector(pTweenContainer,
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
                                   pSequenceIndex);
}

// static public ---------------------------------------------------------------
UTweenVector* UTweenVectorStandardFactory::BP_AppendTweenScaleSceneComponentTo(UTweenContainer* pTweenContainer,
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
                                                                               bool pTweenWhileGameIsPaused,
                                                                               int32 pSequenceIndex)
{
    ETweenTargetType targetType = ETweenTargetType::SceneComponent;
    ETweenVectorType tweenType  = ETweenVectorType::ScaleTo;
    FVector dummyFromVec        = FVector(0, 0, 0);

    return CreateAppendTweenVector(pTweenContainer,
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
                                   pSequenceIndex);
}

// static public ---------------------------------------------------------------
UTweenVector* UTweenVectorStandardFactory::BP_AppendTweenScaleSceneComponentBy(UTweenContainer* pTweenContainer,
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
                                                                               bool pTweenWhileGameIsPaused,
                                                                               int32 pSequenceIndex)
{
    ETweenTargetType targetType = ETweenTargetType::SceneComponent;
    ETweenVectorType tweenType  = ETweenVectorType::ScaleBy;
    FVector dummyFromVec        = FVector(0, 0, 0);
    ETweenSpace dummySpace      = ETweenSpace::World;

    return CreateAppendTweenVector(pTweenContainer,
                                   tweenType,
                                   pTweenTarget,
                                   targetType,
                                   dummyFromVec,
                                   pBy, pDuration,
                                   pEaseType,
                                   dummySpace,
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
UTweenVector* UTweenVectorStandardFactory::BP_AppendTweenCustomVector(UTweenContainer* pTweenContainer,
                                                                      UObject* pTweenTarget,
                                                                      FVector pFrom,
                                                                      FVector pTo,
                                                                      float pDuration,
                                                                      ETweenEaseType pEaseType,
                                                                      int32 pNumLoops,
                                                                      ETweenLoopType pLoopType,
                                                                      float pDelay,
                                                                      float pTimeScale,
                                                                      bool pTweenWhileGameIsPaused,
                                                                      int32 pSequenceIndex)
{
    ETweenTargetType targetType = ETweenTargetType::Custom;
    ETweenVectorType tweenType  = ETweenVectorType::Custom;
    ETweenSpace dummySpace      = ETweenSpace::World;

    return CreateAppendTweenVector(pTweenContainer,
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
                                   pSequenceIndex);
}

// static public ---------------------------------------------------------------
UTweenVector* UTweenVectorStandardFactory::BP_JoinTweenMoveActorTo(UTweenContainer* pTweenContainer,
                                                                   AActor* pTweenTarget,
                                                                   FVector pTo,
                                                                   float pDuration,
                                                                   ETweenEaseType pEaseType,
                                                                   ETweenSpace pTweenSpace,
                                                                   bool pDeleteTweenOnHit,
                                                                   bool pDeleteTweenOnOverlap,
                                                                   float pDelay,
                                                                   float pTimeScale,
                                                                   bool pTweenWhileGameIsPaused,
                                                                   int32 pSequenceIndex)
{
    ETweenTargetType targetType = ETweenTargetType::Actor;
    ETweenVectorType tweenType  = ETweenVectorType::MoveTo;
    FVector dummyFromVec        = FVector(0, 0, 0);

    return CreateJoinTweenVector(pTweenContainer,
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
                                 pSequenceIndex);
}

// static public ---------------------------------------------------------------
UTweenVector* UTweenVectorStandardFactory::BP_JoinTweenMoveActorBy(UTweenContainer* pTweenContainer,
                                                                   AActor* pTweenTarget,
                                                                   FVector pBy,
                                                                   float pDuration,
                                                                   ETweenEaseType pEaseType,
                                                                   bool pDeleteTweenOnHit,
                                                                   bool pDeleteTweenOnOverlap,
                                                                   float pDelay,
                                                                   float pTimeScale,
                                                                   bool pTweenWhileGameIsPaused,
                                                                   int32 pSequenceIndex)
{
    ETweenTargetType targetType = ETweenTargetType::Actor;
    ETweenVectorType tweenType  = ETweenVectorType::MoveBy;
    FVector dummyFromVec        = FVector(0, 0, 0);
    ETweenSpace dummySpace      = ETweenSpace::World;

    return CreateJoinTweenVector(pTweenContainer,
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
                                 pSequenceIndex);
}

// static public ---------------------------------------------------------------
UTweenVector* UTweenVectorStandardFactory::BP_JoinTweenScaleActorTo(UTweenContainer* pTweenContainer,
                                                                    AActor* pTweenTarget,
                                                                    FVector pTo,
                                                                    float pDuration,
                                                                    ETweenEaseType pEaseType,
                                                                    ETweenSpace pTweenSpace,
                                                                    bool pDeleteTweenOnHit,
                                                                    bool pDeleteTweenOnOverlap,
                                                                    float pDelay,
                                                                    float pTimeScale,
                                                                    bool pTweenWhileGameIsPaused,
                                                                    int32 pSequenceIndex)
{
    ETweenTargetType targetType = ETweenTargetType::Actor;
    ETweenVectorType tweenType  = ETweenVectorType::ScaleTo;
    FVector dummyFromVec        = FVector(0, 0, 0);

    return CreateJoinTweenVector(pTweenContainer,
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
                                 pSequenceIndex);
}

// static public ---------------------------------------------------------------
UTweenVector* UTweenVectorStandardFactory::BP_JoinTweenScaleActorBy(UTweenContainer* pTweenContainer,
                                                                    AActor* pTweenTarget,
                                                                    FVector pBy,
                                                                    float pDuration,
                                                                    ETweenEaseType pEaseType,
                                                                    bool pDeleteTweenOnHit,
                                                                    bool pDeleteTweenOnOverlap,
                                                                    float pDelay,
                                                                    float pTimeScale,
                                                                    bool pTweenWhileGameIsPaused,
                                                                    int32 pSequenceIndex)
{
    ETweenTargetType targetType = ETweenTargetType::Actor;
    ETweenVectorType tweenType  = ETweenVectorType::ScaleBy;
    FVector dummyFromVec        = FVector(0, 0, 0);
    ETweenSpace dummySpace      = ETweenSpace::World;

    return CreateJoinTweenVector(pTweenContainer,
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
                                 pSequenceIndex);
}

// static public ---------------------------------------------------------------
UTweenVector* UTweenVectorStandardFactory::BP_JoinTweenMoveSceneComponentTo(UTweenContainer* pTweenContainer,
                                                                            USceneComponent* pTweenTarget,
                                                                            FVector pTo,
                                                                            float pDuration,
                                                                            ETweenEaseType pEaseType,
                                                                            ETweenSpace pTweenSpace,
                                                                            bool pDeleteTweenOnHit,
                                                                            bool pDeleteTweenOnOverlap,
                                                                            float pDelay,
                                                                            float pTimeScale,
                                                                            bool pTweenWhileGameIsPaused,
                                                                            int32 pSequenceIndex)
{
    ETweenTargetType targetType = ETweenTargetType::SceneComponent;
    ETweenVectorType tweenType  = ETweenVectorType::MoveTo;
    FVector dummyFromVec        = FVector(0, 0, 0);

    return CreateJoinTweenVector(pTweenContainer,
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
                                 pSequenceIndex);
}

// static public ---------------------------------------------------------------
UTweenVector* UTweenVectorStandardFactory::BP_JoinTweenMoveSceneComponentBy(UTweenContainer* pTweenContainer,
                                                                            USceneComponent* pTweenTarget,
                                                                            FVector pBy,
                                                                            float pDuration,
                                                                            ETweenEaseType pEaseType,
                                                                            bool pDeleteTweenOnHit,
                                                                            bool pDeleteTweenOnOverlap,
                                                                            float pDelay,
                                                                            float pTimeScale,
                                                                            bool pTweenWhileGameIsPaused,
                                                                            int32 pSequenceIndex)
{
    ETweenTargetType targetType = ETweenTargetType::SceneComponent;
    ETweenVectorType tweenType  = ETweenVectorType::MoveBy;
    FVector dummyFromVec        = FVector(0, 0, 0);
    ETweenSpace dummySpace      = ETweenSpace::World;

    return CreateJoinTweenVector(pTweenContainer,
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
                                 pSequenceIndex);
}

// static public ---------------------------------------------------------------
UTweenVector* UTweenVectorStandardFactory::BP_JoinTweenScaleSceneComponentTo(UTweenContainer* pTweenContainer,
                                                                             USceneComponent* pTweenTarget,
                                                                             FVector pTo,
                                                                             float pDuration,
                                                                             ETweenEaseType pEaseType,
                                                                             ETweenSpace pTweenSpace,
                                                                             bool pDeleteTweenOnHit,
                                                                             bool pDeleteTweenOnOverlap,
                                                                             float pDelay,
                                                                             float pTimeScale,
                                                                             bool pTweenWhileGameIsPaused,
                                                                             int32 pSequenceIndex)
{
    ETweenTargetType targetType = ETweenTargetType::SceneComponent;
    ETweenVectorType tweenType  = ETweenVectorType::ScaleTo;
    FVector dummyFromVec        = FVector(0, 0, 0);

    return CreateJoinTweenVector(pTweenContainer,
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
                                 pSequenceIndex);
}

// static public ---------------------------------------------------------------
UTweenVector* UTweenVectorStandardFactory::BP_JoinTweenScaleSceneComponentBy(UTweenContainer* pTweenContainer,
                                                                             USceneComponent* pTweenTarget,
                                                                             FVector pBy,
                                                                             float pDuration,
                                                                             ETweenEaseType pEaseType,
                                                                             bool pDeleteTweenOnHit,
                                                                             bool pDeleteTweenOnOverlap,
                                                                             float pDelay,
                                                                             float pTimeScale,
                                                                             bool pTweenWhileGameIsPaused,
                                                                             int32 pSequenceIndex)
{
    ETweenTargetType targetType = ETweenTargetType::SceneComponent;
    ETweenVectorType tweenType  = ETweenVectorType::ScaleBy;
    FVector dummyFromVec        = FVector(0, 0, 0);
    ETweenSpace dummySpace      = ETweenSpace::World;

    return CreateJoinTweenVector(pTweenContainer,
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
                                 pSequenceIndex);
}

// static public ---------------------------------------------------------------
UTweenVector* UTweenVectorStandardFactory::BP_JoinTweenCustomVector(UTweenContainer* pTweenContainer,
                                                                    UObject* pTweenTarget,
                                                                    FVector pFrom,
                                                                    FVector pTo,
                                                                    float pDuration,
                                                                    ETweenEaseType pEaseType,
                                                                    float pDelay,
                                                                    float pTimeScale,
                                                                    bool pTweenWhileGameIsPaused,
                                                                    int32 pSequenceIndex)
{
    ETweenTargetType targetType = ETweenTargetType::Custom;
    ETweenVectorType tweenType  = ETweenVectorType::Custom;
    ETweenSpace dummySpace      = ETweenSpace::World;

    return CreateJoinTweenVector(pTweenContainer,
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
                                 pSequenceIndex);
}

// static public ---------------------------------------------------------------
UTweenVector* UTweenVectorStandardFactory::CreateAppendTweenVector(UTweenContainer* pTweenContainer,
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
                                                                   int32 pSequenceIndex)
{
    UTweenVector* outTween = nullptr;

    if (pTweenContainer != nullptr)
    {
        // Getting the owning TweenManagerComponent for this TweenContainer. This is a handy way to deal with both "global"
        // TweenManagers and actually instanced TweenManagerComponents
        UTweenManagerComponent* tweenManagerInstance = pTweenContainer->OwningTweenManager;

        // If the instance is valid, I procede with the actual creation
        if (tweenManagerInstance != nullptr)
        {
            // If a sequence index was passed (i.e. the value is != -1) then I insert the tween in that position. Otherwise,
            // I just place the tween at the end of the TweenContainer's sequences
            int32 tweenIndex = pSequenceIndex > -1 ? pSequenceIndex : pTweenContainer->GetSequencesNum();
            
            outTween = tweenManagerInstance->AppendTweenVector(pTweenContainer,
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
                                                               pTweenWhileGameIsPaused);
        }
    }
    else
    {
        UE_LOG(LogTweenMaker, Warning, TEXT("UTweenVectorStandardFactory::CreateAppendTweenVector() -> the Tween that had as target the "
                                            "object with name %s couldn't be added because the passed TweenContainer was null."), *pTarget->GetName());
    }

    return outTween;
}

// static public ---------------------------------------------------------------
UTweenVector* UTweenVectorStandardFactory::CreateJoinTweenVector(UTweenContainer* pTweenContainer,
                                                                 ETweenVectorType pTweenType,
                                                                 UObject* pTweenTarget,
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
                                                                 int32 pSequenceIndex)
{
    UTweenVector* outTween = nullptr;

    if (pTweenContainer != nullptr)
    {
        UTweenManagerComponent* tweenManagerInstance = pTweenContainer->OwningTweenManager;

        if (tweenManagerInstance != nullptr)
        {
            // If a sequence index was passed (i.e. the value is != -1) then I insert the tween in that position. Otherwise,
            // I just place the tween into the last sequence
            int32 tweenIndex = pSequenceIndex > -1 ? pSequenceIndex : pTweenContainer->GetSequencesNum() - 1;
            
            outTween = tweenManagerInstance->JoinTweenVector(pTweenContainer,
                                                             tweenIndex,
                                                             pTweenType,
                                                             pTweenTarget,
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
                                                             pTweenWhileGameIsPaused);
        }
    }
    else
    {
        UE_LOG(LogTweenMaker, Warning, TEXT("UTweenVectorStandardFactory::CreateJoinTweenVector() -> the Tween that had as target the "
                                            "object with name %s couldn't be added because the passed TweenContainer was null."), *pTweenTarget->GetName());
    }

    return outTween;
}
