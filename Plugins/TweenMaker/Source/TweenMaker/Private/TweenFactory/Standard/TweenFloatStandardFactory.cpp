// Copyright 2018 Francesco Desogus. All Rights Reserved.

#include "TweenFactory/Standard/TweenFloatStandardFactory.h"

#include "Tweens/TweenFloat.h"
#include "Materials/MaterialInstanceDynamic.h"
#include "Components/Widget.h"
#include "GameFramework/Actor.h"
#include "Components/SceneComponent.h"
#include "TweenContainer.h"

// public ----------------------------------------------------------------------
UTweenFloatStandardFactory::UTweenFloatStandardFactory(const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer)
{

}

// static public ---------------------------------------------------------------
void UTweenFloatStandardFactory::BP_CreateTweenMaterialFloatFromTo(UTweenManagerComponent* pTweenManagerComponent,
                                                                   UMaterialInstanceDynamic* pTweenTarget,
                                                                   UTweenContainer*& pOutTweenContainer,
                                                                   UTweenFloat*& pOutTween,
                                                                   FName pParameterName,
                                                                   float pFrom,
                                                                   float pTo,
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
    
    pOutTween = BP_AppendTweenMaterialFloatFromTo(pOutTweenContainer,
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
                                                  pSequenceIndex);
}

// static public ---------------------------------------------------------------
void UTweenFloatStandardFactory::BP_CreateTweenMaterialFloatTo(UTweenManagerComponent* pTweenManagerComponent,
                                                               UMaterialInstanceDynamic* pTweenTarget,
                                                               UTweenContainer*& pOutTweenContainer,
                                                               UTweenFloat*& pOutTween,
                                                               FName pParameterName,
                                                               float pTo,
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
    
    pOutTween = BP_AppendTweenMaterialFloatTo(pOutTweenContainer,
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
                                              pSequenceIndex);
}

// static public ---------------------------------------------------------------
void UTweenFloatStandardFactory::BP_CreateTweenRotateActorAroundPoint(UTweenManagerComponent* pTweenManagerComponent,
                                                                      AActor* pTweenTarget,
                                                                      UTweenContainer*& pOutTweenContainer,
                                                                      UTweenFloat*& pOutTween,
                                                                      FVector pPoint,
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
                                                                      bool pTweenWhileGameIsPaused,
                                                                      int32 pSequenceIndex)
{
    pOutTweenContainer = pTweenManagerComponent != nullptr ? pTweenManagerComponent->CreateTweenContainer()
                                                           : UTweenManagerComponent::CreateTweenContainerStatic();
    
    pOutTween = BP_AppendTweenRotateActorAroundPoint(pOutTweenContainer,
                                                     pTweenTarget,
                                                     pPoint,
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
                                                     pSequenceIndex);
}

// static public ---------------------------------------------------------------
void UTweenFloatStandardFactory::BP_CreateTweenRotateActorAroundPointByOffset(UTweenManagerComponent* pTweenManagerComponent,
                                                                              AActor* pTweenTarget,
                                                                              UTweenContainer*& pOutTweenContainer,
                                                                              UTweenFloat*& pOutTween,
                                                                              FVector pPoint,
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
                                                                              bool pTweenWhileGameIsPaused,
                                                                              int32 pSequenceIndex)
{
    float startingAngle = 0.0f;
    FVector axis;
    float radius = 0.0f;
    Utility::ComputeDataForRotateAroundPoint(pTweenTarget, pPoint, pReferenceAxis, pTweenSpace, axis, radius);

    pOutTweenContainer = pTweenManagerComponent != nullptr ? pTweenManagerComponent->CreateTweenContainer()
                                                           : UTweenManagerComponent::CreateTweenContainerStatic();
    
    pOutTween = BP_AppendTweenRotateActorAroundPoint(pOutTweenContainer,
                                                     pTweenTarget,
                                                     pPoint,
                                                     startingAngle,
                                                     pOffsetAngle,
                                                     radius,
                                                     axis,
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
                                                     pSequenceIndex);
}

// static public ---------------------------------------------------------------
void UTweenFloatStandardFactory::BP_CreateTweenActorFollowSpline(UTweenManagerComponent* pTweenManagerComponent,
                                                                 AActor* pTweenTarget,
                                                                 UTweenContainer*& pOutTweenContainer,
                                                                 UTweenFloat*& pOutTween,
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
                                                                 bool pTweenWhileGameIsPaused,
                                                                 int32 pSequenceIndex)
{
    pOutTweenContainer = pTweenManagerComponent != nullptr ? pTweenManagerComponent->CreateTweenContainer()
                                                           : UTweenManagerComponent::CreateTweenContainerStatic();
    
    pOutTween = BP_AppendTweenActorFollowSpline(pOutTweenContainer,
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
                                                pSequenceIndex);
}

// static public ---------------------------------------------------------------
void UTweenFloatStandardFactory::BP_CreateTweenRotateSceneComponentAroundPoint(UTweenManagerComponent* pTweenManagerComponent,
                                                                               USceneComponent* pTweenTarget,
                                                                               UTweenContainer*& pOutTweenContainer,
                                                                               UTweenFloat*& pOutTween,
                                                                               FVector pPoint,
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
                                                                               bool pTweenWhileGameIsPaused,
                                                                               int32 pSequenceIndex)
{
    pOutTweenContainer = pTweenManagerComponent != nullptr ? pTweenManagerComponent->CreateTweenContainer()
                                                           : UTweenManagerComponent::CreateTweenContainerStatic();
    
    pOutTween = BP_AppendTweenRotateSceneComponentAroundPoint(pOutTweenContainer,
                                                              pTweenTarget,
                                                              pPoint,
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
                                                              pSequenceIndex);
}

// static public ---------------------------------------------------------------
void UTweenFloatStandardFactory::BP_CreateTweenRotateSceneComponentAroundPointByOffset(UTweenManagerComponent* pTweenManagerComponent,
                                                                                       USceneComponent* pTweenTarget,
                                                                                       UTweenContainer*& pOutTweenContainer,
                                                                                       UTweenFloat*& pOutTween,
                                                                                       FVector pPoint,
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
                                                                                       bool pTweenWhileGameIsPaused,
                                                                                       int32 pSequenceIndex)
{
    float startingAngle = 0;
    FVector axis;
    float radius = 0.0f;
    Utility::ComputeDataForRotateAroundPoint(pTweenTarget, pPoint, pReferenceAxis, pTweenSpace, axis, radius);

    pOutTweenContainer = pTweenManagerComponent != nullptr ? pTweenManagerComponent->CreateTweenContainer()
                                                           : UTweenManagerComponent::CreateTweenContainerStatic();
    
    pOutTween = BP_AppendTweenRotateSceneComponentAroundPoint(pOutTweenContainer,
                                                              pTweenTarget,
                                                              pPoint,
                                                              startingAngle,
                                                              pOffsetAngle,
                                                              radius,
                                                              axis,
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
                                                              pSequenceIndex);
}

// static public ---------------------------------------------------------------
void UTweenFloatStandardFactory::BP_CreateTweenSceneComponentFollowSpline(UTweenManagerComponent* pTweenManagerComponent,
                                                                          USceneComponent* pTweenTarget,
                                                                          UTweenContainer*& pOutTweenContainer,
                                                                          UTweenFloat*& pOutTween,
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
                                                                          bool pTweenWhileGameIsPaused,
                                                                          int32 pSequenceIndex)
{
    pOutTweenContainer = pTweenManagerComponent != nullptr ? pTweenManagerComponent->CreateTweenContainer()
                                                           : UTweenManagerComponent::CreateTweenContainerStatic();
    
    pOutTween = BP_AppendTweenSceneComponentFollowSpline(pOutTweenContainer,
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
                                                         pSequenceIndex);
}

// static public ---------------------------------------------------------------
void UTweenFloatStandardFactory::BP_CreateTweenWidgetAngleTo(UTweenManagerComponent* pTweenManagerComponent,
                                                             UWidget* pTweenTarget,
                                                             UTweenContainer*& pOutTweenContainer,
                                                             UTweenFloat*& pOutTween,
                                                             float pTo,
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
    pOutTween = BP_AppendTweenWidgetAngleTo(pOutTweenContainer,
                                            pTweenTarget,
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
void UTweenFloatStandardFactory::BP_CreateTweenWidgetOpacityTo(UTweenManagerComponent* pTweenManagerComponent,
                                                               UWidget* pTweenTarget,
                                                               UTweenContainer*& pOutTweenContainer,
                                                               UTweenFloat*& pOutTween,
                                                               float pTo,
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
    pOutTween = BP_AppendTweenWidgetOpacityTo(pOutTweenContainer,
                                              pTweenTarget,
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
void UTweenFloatStandardFactory::BP_CreateTweenCustomFloat(UTweenManagerComponent* pTweenManagerComponent,
                                                           UObject* pTweenTarget,
                                                           UTweenContainer*& pOutTweenContainer,
                                                           UTweenFloat*& pOutTween,
                                                           float pFrom,
                                                           float pTo,
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
    pOutTween = BP_AppendTweenCustomFloat(pOutTweenContainer,
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
UTweenFloat* UTweenFloatStandardFactory::BP_AppendTweenMaterialFloatFromTo(UTweenContainer* pTweenContainer,
                                                                           UMaterialInstanceDynamic* pTweenTarget,
                                                                           FName pParameterName,
                                                                           float pFrom,
                                                                           float pTo,
                                                                           float pDuration,
                                                                           ETweenEaseType pEaseType,
                                                                           int32 pNumLoops,
                                                                           ETweenLoopType pLoopType,
                                                                           float pDelay,
                                                                           float pTimeScale,
                                                                           bool pTweenWhileGameIsPaused,
                                                                           int32 pSequenceIndex)
{
    ETweenTargetType targetType = ETweenTargetType::Material;
    ETweenFloatType tweenType   = ETweenFloatType::MaterialScalarFromTo;

    return CreateAppendTweenFloat(pTweenContainer,
                                  tweenType,
                                  pTweenTarget,
                                  targetType,
                                  pFrom,
                                  pTo,
                                  pDuration,
                                  pEaseType,
                                  pNumLoops,
                                  pLoopType,
                                  pDelay,
                                  pTimeScale,
                                  pTweenWhileGameIsPaused,
                                  pSequenceIndex,
                                  pParameterName);
}

// static public ---------------------------------------------------------------
UTweenFloat* UTweenFloatStandardFactory::BP_AppendTweenMaterialFloatTo(UTweenContainer* pTweenContainer,
                                                                       UMaterialInstanceDynamic* pTweenTarget,
                                                                       FName pParameterName,
                                                                       float pTo,
                                                                       float pDuration,
                                                                       ETweenEaseType pEaseType,
                                                                       int32 pNumLoops,
                                                                       ETweenLoopType pLoopType,
                                                                       float pDelay,
                                                                       float pTimeScale,
                                                                       bool pTweenWhileGameIsPaused,
                                                                       int32 pSequenceIndex)
{
    ETweenTargetType targetType = ETweenTargetType::Material;
    ETweenFloatType tweenType   = ETweenFloatType::MaterialScalarTo;
    float dummyFromFloat        = 0.0f;

    return CreateAppendTweenFloat(pTweenContainer,
                                  tweenType,
                                  pTweenTarget,
                                  targetType,
                                  dummyFromFloat,
                                  pTo,
                                  pDuration,
                                  pEaseType,
                                  pNumLoops,
                                  pLoopType,
                                  pDelay,
                                  pTimeScale,
                                  pTweenWhileGameIsPaused,
                                  pSequenceIndex,
                                  pParameterName);
}

// static public ---------------------------------------------------------------
UTweenFloat* UTweenFloatStandardFactory::BP_AppendTweenRotateActorAroundPoint(UTweenContainer* pTweenContainer,
                                                                              AActor* pTweenTarget,
                                                                              FVector pPoint,
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
                                                                              bool pTweenWhileGameIsPaused,
                                                                              int32 pSequenceIndex)
{
    ETweenTargetType targetType = ETweenTargetType::Actor;
    ETweenFloatType tweenType   = ETweenFloatType::RotateAroundPoint;

    return CreateAppendTweenRotateAroundFloat(pTweenContainer,
                                              tweenType,
                                              pTweenTarget,
                                              targetType,
                                              pPoint,
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
                                              pSequenceIndex);
}

// static public ---------------------------------------------------------------
UTweenFloat* UTweenFloatStandardFactory::BP_AppendTweenRotateActorAroundPointByOffset(UTweenContainer* pTweenContainer,
                                                                                      AActor* pTweenTarget,
                                                                                      FVector pPoint,
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
                                                                                      bool pTweenWhileGameIsPaused,
                                                                                      int32 pSequenceIndex)
{
    float startingAngle = 0.0f;
    FVector axis;
    float radius = 0.0f;
    Utility::ComputeDataForRotateAroundPoint(pTweenTarget, pPoint, pReferenceAxis, pTweenSpace, axis, radius);

    return BP_AppendTweenRotateActorAroundPoint(pTweenContainer,
                                                pTweenTarget,
                                                pPoint,
                                                startingAngle,
                                                pOffsetAngle,
                                                radius,
                                                axis,
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
                                                pSequenceIndex);
}

// static public ---------------------------------------------------------------
UTweenFloat* UTweenFloatStandardFactory::BP_AppendTweenActorFollowSpline(UTweenContainer* pTweenContainer,
                                                                         AActor* pTweenTarget,
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
                                                                         bool pTweenWhileGameIsPaused,
                                                                         int32 pSequenceIndex)
{
    ETweenTargetType targetType = ETweenTargetType::Actor;
    ETweenFloatType tweenType   = ETweenFloatType::FollowSpline;

    return CreateAppendTweenFollowSpline(pTweenContainer,
                                         tweenType,
                                         pTweenTarget,
                                         targetType,
                                         pSpline,
                                         pApplyRotation,
                                         pApplyScale,
                                         pUseConstantSpeed,
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
UTweenFloat* UTweenFloatStandardFactory::BP_AppendTweenRotateSceneComponentAroundPoint(UTweenContainer* pTweenContainer,
                                                                                       USceneComponent* pTweenTarget,
                                                                                       FVector pPoint,
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
                                                                                       bool pTweenWhileGameIsPaused,
                                                                                       int32 pSequenceIndex)
{
    ETweenTargetType targetType = ETweenTargetType::SceneComponent;
    ETweenFloatType tweenType   = ETweenFloatType::RotateAroundPoint;

    return CreateAppendTweenRotateAroundFloat(pTweenContainer,
                                              tweenType,
                                              pTweenTarget,
                                              targetType,
                                              pPoint,
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
                                              pSequenceIndex);
}

// static public ---------------------------------------------------------------
UTweenFloat* UTweenFloatStandardFactory::BP_AppendTweenRotateSceneComponentAroundPointByOffset(UTweenContainer* pTweenContainer,
                                                                                               USceneComponent* pTweenTarget,
                                                                                               FVector pPoint,
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
                                                                                               bool pTweenWhileGameIsPaused,
                                                                                               int32 pSequenceIndex)
{
    float startingAngle = 0;
    FVector axis;
    float radius = 0.0f;
    Utility::ComputeDataForRotateAroundPoint(pTweenTarget, pPoint, pReferenceAxis, pTweenSpace, axis, radius);

    return BP_AppendTweenRotateSceneComponentAroundPoint(pTweenContainer,
                                                         pTweenTarget,
                                                         pPoint,
                                                         startingAngle,
                                                         pOffsetAngle,
                                                         radius,
                                                         axis,
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
                                                         pSequenceIndex);
}

// static public ---------------------------------------------------------------
UTweenFloat* UTweenFloatStandardFactory::BP_AppendTweenSceneComponentFollowSpline(UTweenContainer* pTweenContainer,
                                                                                  USceneComponent* pTweenTarget,
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
                                                                                  bool pTweenWhileGameIsPaused,
                                                                                  int32 pSequenceIndex)
{
    ETweenTargetType targetType = ETweenTargetType::SceneComponent;
    ETweenFloatType tweenType   = ETweenFloatType::FollowSpline;

    return CreateAppendTweenFollowSpline(pTweenContainer,
                                         tweenType,
                                         pTweenTarget,
                                         targetType,
                                         pSpline,
                                         pApplyRotation,
                                         pApplyScale,
                                         pUseConstantSpeed,
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
UTweenFloat* UTweenFloatStandardFactory::BP_AppendTweenWidgetAngleTo(UTweenContainer* pTweenContainer,
                                                                     UWidget* pTweenTarget,
                                                                     float pTo,
                                                                     float pDuration,
                                                                     ETweenEaseType pEaseType,
                                                                     int32 pNumLoops,
                                                                     ETweenLoopType pLoopType,
                                                                     float pDelay,
                                                                     float pTimeScale,
                                                                     bool pTweenWhileGameIsPaused,
                                                                     int32 pSequenceIndex)
{
    ETweenTargetType targetType = ETweenTargetType::UMG;
    ETweenFloatType tweenType   = ETweenFloatType::WidgetAngleTo;
    float dummyFromFloat        = 0.0f;

    return CreateAppendTweenFloat(pTweenContainer,
                                  tweenType,
                                  pTweenTarget,
                                  targetType,
                                  dummyFromFloat,
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
UTweenFloat* UTweenFloatStandardFactory::BP_AppendTweenWidgetOpacityTo(UTweenContainer* pTweenContainer,
                                                                       UWidget* pTweenTarget,
                                                                       float pTo,
                                                                       float pDuration,
                                                                       ETweenEaseType pEaseType,
                                                                       int32 pNumLoops,
                                                                       ETweenLoopType pLoopType,
                                                                       float pDelay,
                                                                       float pTimeScale,
                                                                       bool pTweenWhileGameIsPaused,
                                                                       int32 pSequenceIndex)
{
    ETweenTargetType targetType = ETweenTargetType::UMG;
    ETweenFloatType tweenType   = ETweenFloatType::WidgetOpacityTo;
    float dummyFromFloat        = 0.0f;

    return CreateAppendTweenFloat(pTweenContainer,
                                  tweenType,
                                  pTweenTarget,
                                  targetType,
                                  dummyFromFloat,
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
UTweenFloat* UTweenFloatStandardFactory::BP_AppendTweenCustomFloat(UTweenContainer* pTweenContainer,
                                                                   UObject* pTweenTarget,
                                                                   float pFrom,
                                                                   float pTo,
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
    ETweenFloatType tweenType   = ETweenFloatType::Custom;

    return CreateAppendTweenFloat(pTweenContainer,
                                  tweenType,
                                  pTweenTarget,
                                  targetType,
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
UTweenFloat* UTweenFloatStandardFactory::BP_JoinTweenMaterialFloatFromTo(UTweenContainer* pTweenContainer,
                                                                         UMaterialInstanceDynamic* pTweenTarget,
                                                                         FName pParameterName,
                                                                         float pFrom,
                                                                         float pTo,
                                                                         float pDuration,
                                                                         ETweenEaseType pEaseType,
                                                                         float pDelay,
                                                                         float pTimeScale,
                                                                         bool pTweenWhileGameIsPaused,
                                                                         int32 pSequenceIndex)
{
    ETweenTargetType targetType = ETweenTargetType::Material;
    ETweenFloatType tweenType   = ETweenFloatType::MaterialScalarFromTo;

    return CreateJoinTweenFloat(pTweenContainer,
                                tweenType,
                                pTweenTarget,
                                targetType,
                                pFrom,
                                pTo,
                                pDuration,
                                pEaseType,
                                pDelay,
                                pTimeScale,
                                pTweenWhileGameIsPaused,
                                pSequenceIndex,
                                pParameterName);
}

// static public ---------------------------------------------------------------
UTweenFloat* UTweenFloatStandardFactory::BP_JoinTweenMaterialFloatTo(UTweenContainer* pTweenContainer,
                                                                     UMaterialInstanceDynamic* pTweenTarget,
                                                                     FName pParameterName,
                                                                     float pTo,
                                                                     float pDuration,
                                                                     ETweenEaseType pEaseType,
                                                                     float pDelay,
                                                                     float pTimeScale,
                                                                     bool pTweenWhileGameIsPaused,
                                                                     int32 pSequenceIndex)
{
    ETweenTargetType targetType = ETweenTargetType::Material;
    ETweenFloatType tweenType   = ETweenFloatType::MaterialScalarTo;
    float dummyFromFloat        = 0.0f;

    return CreateJoinTweenFloat(pTweenContainer,
                                tweenType,
                                pTweenTarget,
                                targetType,
                                dummyFromFloat,
                                pTo,
                                pDuration,
                                pEaseType,
                                pDelay,
                                pTimeScale,
                                pTweenWhileGameIsPaused,
                                pSequenceIndex,
                                pParameterName);
}

// static public ---------------------------------------------------------------
UTweenFloat* UTweenFloatStandardFactory::BP_JoinTweenRotateActorAroundPoint(UTweenContainer* pTweenContainer,
                                                                            AActor* pTweenTarget,
                                                                            FVector pPoint,
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
                                                                            bool pTweenWhileGameIsPaused,
                                                                            int32 pSequenceIndex)
{
    ETweenTargetType targetType = ETweenTargetType::Actor;
    ETweenFloatType tweenType   = ETweenFloatType::RotateAroundPoint;

    return CreateJoinTweenRotateAroundFloat(pTweenContainer,
                                            tweenType,
                                            pTweenTarget,
                                            targetType,
                                            pPoint,
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
                                            pSequenceIndex);
}

// static public ---------------------------------------------------------------
UTweenFloat* UTweenFloatStandardFactory::BP_JoinTweenRotateActorAroundPointByOffset(UTweenContainer* pTweenContainer,
                                                                                    AActor* pTweenTarget,
                                                                                    FVector pPoint,
                                                                                    float pOffsetAngle,
                                                                                    ETweenReferenceAxis pReferenceAxis,
                                                                                    ETweenSpace pTweenSpace,
                                                                                    float pDuration,
                                                                                    ETweenEaseType pEaseType,
                                                                                    bool pDeleteTweenOnHit,
                                                                                    bool pDeleteTweenOnOverlap,
                                                                                    float pDelay,
                                                                                    float pTimeScale,
                                                                                    bool pTweenWhileGameIsPaused,
                                                                                    int32 pSequenceIndex)
{
    float startingAngle = 0;
    FVector axis;
    float radius = 0.0f;
    Utility::ComputeDataForRotateAroundPoint(pTweenTarget, pPoint, pReferenceAxis, pTweenSpace, axis, radius);

    return BP_JoinTweenRotateActorAroundPoint(pTweenContainer,
                                              pTweenTarget,
                                              pPoint,
                                              startingAngle,
                                              pOffsetAngle,
                                              radius,
                                              axis,
                                              pTweenSpace,
                                              pDuration,
                                              pEaseType,
                                              pDeleteTweenOnHit,
                                              pDeleteTweenOnOverlap,
                                              pDelay,
                                              pTimeScale,
                                              pTweenWhileGameIsPaused,
                                              pSequenceIndex);
}

// static public ---------------------------------------------------------------
UTweenFloat* UTweenFloatStandardFactory::BP_JoinTweenActorFollowSpline(UTweenContainer* pTweenContainer,
                                                                       AActor* pTweenTarget,
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
                                                                       bool pTweenWhileGameIsPaused,
                                                                       int32 pSequenceIndex)
{
    ETweenTargetType targetType = ETweenTargetType::Actor;
    ETweenFloatType tweenType   = ETweenFloatType::FollowSpline;

    return CreateJoinTweenFollowSpline(pTweenContainer,
                                       tweenType,
                                       pTweenTarget,
                                       targetType,
                                       pSpline,
                                       pApplyRotation,
                                       pApplyScale,
                                       pUseConstantSpeed,
                                       pDuration,
                                       pEaseType,
                                       pDeleteTweenOnHit,
                                       pDeleteTweenOnOverlap,
                                       pDelay,
                                       pTimeScale,
                                       pTweenWhileGameIsPaused,
                                       pSequenceIndex);
}

// static public ---------------------------------------------------------------
UTweenFloat* UTweenFloatStandardFactory::BP_JoinTweenRotateSceneComponentAroundPoint(UTweenContainer* pTweenContainer,
                                                                                     USceneComponent* pTweenTarget,
                                                                                     FVector pPoint,
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
                                                                                     bool pTweenWhileGameIsPaused,
                                                                                     int32 pSequenceIndex)
{
    ETweenTargetType targetType = ETweenTargetType::SceneComponent;
    ETweenFloatType tweenType   = ETweenFloatType::RotateAroundPoint;

    return CreateJoinTweenRotateAroundFloat(pTweenContainer,
                                            tweenType,
                                            pTweenTarget,
                                            targetType,
                                            pPoint,
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
                                            pSequenceIndex);
}

// static public ---------------------------------------------------------------
UTweenFloat* UTweenFloatStandardFactory::BP_JoinTweenRotateSceneComponentAroundPointByOffset(UTweenContainer* pTweenContainer,
                                                                                             USceneComponent* pTweenTarget,
                                                                                             FVector pPoint,
                                                                                             float pOffsetAngle,
                                                                                             ETweenReferenceAxis pReferenceAxis,
                                                                                             ETweenSpace pTweenSpace,
                                                                                             float pDuration,
                                                                                             ETweenEaseType pEaseType,
                                                                                             bool pDeleteTweenOnHit,
                                                                                             bool pDeleteTweenOnOverlap,
                                                                                             float pDelay,
                                                                                             float pTimeScale,
                                                                                             bool pTweenWhileGameIsPaused,
                                                                                             int32 pSequenceIndex)
{
    float startingAngle = 0.0f;
    FVector axis;
    float radius = 0.0f;
    Utility::ComputeDataForRotateAroundPoint(pTweenTarget, pPoint, pReferenceAxis, pTweenSpace, axis, radius);
    
    return BP_JoinTweenRotateSceneComponentAroundPoint(pTweenContainer,
                                                       pTweenTarget,
                                                       pPoint,
                                                       startingAngle,
                                                       pOffsetAngle,
                                                       radius,
                                                       axis,
                                                       pTweenSpace,
                                                       pDuration,
                                                       pEaseType,
                                                       pDeleteTweenOnHit,
                                                       pDeleteTweenOnOverlap,
                                                       pDelay,
                                                       pTimeScale,
                                                       pTweenWhileGameIsPaused,
                                                       pSequenceIndex);
}

// static public ---------------------------------------------------------------
UTweenFloat* UTweenFloatStandardFactory::BP_JoinTweenSceneComponentFollowSpline(UTweenContainer* pTweenContainer,
                                                                                USceneComponent* pTweenTarget,
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
                                                                                bool pTweenWhileGameIsPaused,
                                                                                int32 pSequenceIndex)
{
    ETweenTargetType targetType = ETweenTargetType::SceneComponent;
    ETweenFloatType tweenType   = ETweenFloatType::FollowSpline;

    return CreateJoinTweenFollowSpline(pTweenContainer,
                                       tweenType,
                                       pTweenTarget,
                                       targetType,
                                       pSpline,
                                       pApplyRotation,
                                       pApplyScale,
                                       pUseConstantSpeed,
                                       pDuration,
                                       pEaseType,
                                       pDeleteTweenOnHit,
                                       pDeleteTweenOnOverlap,
                                       pDelay,
                                       pTimeScale,
                                       pTweenWhileGameIsPaused,
                                       pSequenceIndex);
}

// static public ---------------------------------------------------------------
UTweenFloat* UTweenFloatStandardFactory::BP_JoinTweenWidgetAngleTo(UTweenContainer* pTweenContainer,
                                                                   UWidget* pTweenTarget,
                                                                   float pTo,
                                                                   float pDuration,
                                                                   ETweenEaseType pEaseType,
                                                                   float pDelay,
                                                                   float pTimeScale,
                                                                   bool pTweenWhileGameIsPaused,
                                                                   int32 pSequenceIndex)
{
    ETweenTargetType targetType = ETweenTargetType::UMG;
    ETweenFloatType tweenType = ETweenFloatType::WidgetAngleTo;
    float dummyFromFloat = 0.0f;

    return CreateJoinTweenFloat(pTweenContainer,
                                tweenType,
                                pTweenTarget,
                                targetType,
                                dummyFromFloat,
                                pTo,
                                pDuration,
                                pEaseType,
                                pDelay,
                                pTimeScale,
                                pTweenWhileGameIsPaused,
                                pSequenceIndex);
}

// static public ---------------------------------------------------------------
UTweenFloat* UTweenFloatStandardFactory::BP_JoinTweenWidgetOpacityTo(UTweenContainer* pTweenContainer,
                                                                     UWidget* pTweenTarget,
                                                                     float pTo,
                                                                     float pDuration,
                                                                     ETweenEaseType pEaseType,
                                                                     float pDelay,
                                                                     float pTimeScale,
                                                                     bool pTweenWhileGameIsPaused,
                                                                     int32 pSequenceIndex)
{
    ETweenTargetType targetType = ETweenTargetType::UMG;
    ETweenFloatType tweenType   = ETweenFloatType::WidgetOpacityTo;
    float dummyFromFloat        = 0.0f;

    return CreateJoinTweenFloat(pTweenContainer,
                                tweenType,
                                pTweenTarget,
                                targetType,
                                dummyFromFloat,
                                pTo,
                                pDuration,
                                pEaseType,
                                pDelay,
                                pTimeScale,
                                pTweenWhileGameIsPaused,
                                pSequenceIndex);
}

// static public ---------------------------------------------------------------
UTweenFloat* UTweenFloatStandardFactory::BP_JoinTweenCustomFloat(UTweenContainer* pTweenContainer,
                                                                 UObject* pTweenTarget,
                                                                 float pFrom,
                                                                 float pTo,
                                                                 float pDuration,
                                                                 ETweenEaseType pEaseType,
                                                                 float pDelay,
                                                                 float pTimeScale,
                                                                 bool pTweenWhileGameIsPaused,
                                                                 int32 pSequenceIndex)
{
    ETweenTargetType targetType = ETweenTargetType::Custom;
    ETweenFloatType tweenType = ETweenFloatType::Custom;

    return CreateJoinTweenFloat(pTweenContainer,
                                tweenType,
                                pTweenTarget,
                                targetType,
                                pFrom,
                                pTo,
                                pDuration,
                                pEaseType,
                                pDelay,
                                pTimeScale,
                                pTweenWhileGameIsPaused,
                                pSequenceIndex);
}

// static private --------------------------------------------------------------
UTweenFloat* UTweenFloatStandardFactory::CreateAppendTweenFloat(UTweenContainer* pTweenContainer,
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
                                                                int32 pSequenceIndex,
                                                                FName pParameterName)
{
    UTweenFloat* outTween = nullptr;

    if (pTweenContainer != nullptr)
    {
        UTweenManagerComponent* tweenManagerInstance = pTweenContainer->OwningTweenManager;

        if (tweenManagerInstance != nullptr)
        {
            int32 tweenIndex = pSequenceIndex > -1 ? pSequenceIndex : pTweenContainer->GetSequencesNum();

            outTween = tweenManagerInstance->AppendTweenFloat(pTweenContainer,
                                                              tweenIndex,
                                                              pTweenType,
                                                              pTarget,
                                                              pTargetType,
                                                              pFrom,
                                                              pTo,
                                                              pDuration,
                                                              pEaseType,
                                                              pNumLoops,
                                                              pLoopType,
                                                              pDelay,
                                                              pTimeScale,
                                                              pTweenWhileGameIsPaused,
                                                              nullptr,
                                                              pParameterName);
        }
    }
    else
    {
        UE_LOG(LogTweenMaker, Warning, TEXT("UTweenFloatStandardFactory::CreateAppendTweenFloat() -> the Tween that had as target the "
                                            "object with name %s couldn't be added because the passed TweenContainer was null."), *pTarget->GetName());
    }

    return outTween;
}

// static private --------------------------------------------------------------
UTweenFloat* UTweenFloatStandardFactory::CreateJoinTweenFloat(UTweenContainer *pTweenContainer, ETweenFloatType pTweenType,
                                                              UObject *pTweenTarget, ETweenTargetType pTargetType,
                                                              float pFrom, float pTo, float pDuration,
                                                              ETweenEaseType pEaseType, float pDelay, float pTimeScale, bool pTweenWhileGameIsPaused,
                                                              int32 pSequenceIndex, FName pParameterName)
{
    UTweenFloat* outTween = nullptr;

    if (pTweenContainer != nullptr)
    {
        UTweenManagerComponent* tweenManagerInstance = pTweenContainer->OwningTweenManager;

        if (tweenManagerInstance != nullptr)
        {
            int32 tweenIndex = pSequenceIndex > -1 ? pSequenceIndex : pTweenContainer->GetSequencesNum() - 1;

            outTween = tweenManagerInstance->JoinTweenFloat(pTweenContainer,
                                                            tweenIndex,
                                                            pTweenType,
                                                            pTweenTarget,
                                                            pTargetType,
                                                            pFrom,
                                                            pTo,
                                                            pDuration,
                                                            pEaseType,
                                                            pDelay,
                                                            pTimeScale,
                                                            pTweenWhileGameIsPaused,
                                                            nullptr,
                                                            pParameterName);
        }
    }
    else
    {
        UE_LOG(LogTweenMaker, Warning, TEXT("UTweenFloatStandardFactory::CreateJoinTweenFloat() -> the Tween that had as target the "
                                            "object with name %s couldn't be added because the passed TweenContainer was null."), *pTweenTarget->GetName());
    }

    return outTween;
}

// static private --------------------------------------------------------------
UTweenFloat* UTweenFloatStandardFactory::CreateAppendTweenRotateAroundFloat(UTweenContainer* pTweenContainer,
                                                                            ETweenFloatType pTweenType,
                                                                            UObject* pTarget,
                                                                            ETweenTargetType pTargetType,
                                                                            const FVector& pPoint,
                                                                            float pStartingAngle,
                                                                            float pEndingAngle,
                                                                            float pRadius,
                                                                            const FVector& pAxis,
                                                                            ETweenSpace pTweenSpace,
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
    UTweenFloat* outTween = nullptr;

    if (pTweenContainer != nullptr)
    {
        UTweenManagerComponent* tweenManagerInstance = pTweenContainer->OwningTweenManager;

        if (tweenManagerInstance != nullptr)
        {
            int32 tweenIndex = pSequenceIndex > -1 ? pSequenceIndex : pTweenContainer->GetSequencesNum();

            outTween = tweenManagerInstance->AppendTweenRotateAroundFloat(pTweenContainer,
                                                                          tweenIndex,
                                                                          pTweenType,
                                                                          pTarget,
                                                                          pTargetType,
                                                                          pPoint,
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
                                                                          pTweenWhileGameIsPaused);
        }
    }
    else
    {
        UE_LOG(LogTweenMaker, Warning, TEXT("UTweenFloatStandardFactory::CreateAppendTweenRotateAroundFloat() -> the Tween that had as target the "
                                            "object with name %s couldn't be added because the passed TweenContainer was null."), *pTarget->GetName());
    }

    return outTween;
}

// static private --------------------------------------------------------------
UTweenFloat* UTweenFloatStandardFactory::CreateJoinTweenRotateAroundFloat(UTweenContainer* pTweenContainer,
                                                                          ETweenFloatType pTweenType,
                                                                          UObject* pTarget,
                                                                          ETweenTargetType pTargetType,
                                                                          const FVector& pPoint,
                                                                          float pStartingAngle,
                                                                          float pEndingAngle,
                                                                          float pRadius,
                                                                          const FVector& pAxis,
                                                                          ETweenSpace pTweenSpace,
                                                                          float pDuration,
                                                                          ETweenEaseType pEaseType,
                                                                          bool pDeleteTweenOnHit,
                                                                          bool pDeleteTweenOnOverlap,
                                                                          float pDelay,
                                                                          float pTimeScale,
                                                                          bool pTweenWhileGameIsPaused,
                                                                          int32 pSequenceIndex)
{
    UTweenFloat* outTween = nullptr;

    if (pTweenContainer != nullptr)
    {
        UTweenManagerComponent* tweenManagerInstance = pTweenContainer->OwningTweenManager;

        if (tweenManagerInstance != nullptr)
        {
            int32 tweenIndex = pSequenceIndex > -1 ? pSequenceIndex : pTweenContainer->GetSequencesNum() - 1;

            outTween = tweenManagerInstance->JoinTweenRotateAroundFloat(pTweenContainer,
                                                                        tweenIndex,
                                                                        pTweenType,
                                                                        pTarget,
                                                                        pTargetType,
                                                                        pPoint,
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
                                                                        pTweenWhileGameIsPaused);
        }
    }
    else
    {
        UE_LOG(LogTweenMaker, Warning, TEXT("UTweenFloatStandardFactory::CreateJoinTweenRotateAroundFloat() -> the Tween that had as target the "
                                            "object with name %s couldn't be added because the passed TweenContainer was null."), *pTarget->GetName());
    }

    return outTween;
}

// static private --------------------------------------------------------------
UTweenFloat* UTweenFloatStandardFactory::CreateAppendTweenFollowSpline(UTweenContainer* pTweenContainer,
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
                                                                       int32 pSequenceIndex)
{
    UTweenFloat* outTween = nullptr;

    if (pTweenContainer != nullptr)
    {
        UTweenManagerComponent* tweenManagerInstance = pTweenContainer->OwningTweenManager;

        if (tweenManagerInstance != nullptr)
        {
            int32 tweenIndex = pSequenceIndex > -1 ? pSequenceIndex : pTweenContainer->GetSequencesNum();

            outTween = tweenManagerInstance->AppendTweenFollowSplineFloat(pTweenContainer,
                                                                          tweenIndex,
                                                                          pTweenType,
                                                                          pTarget,
                                                                          pTargetType,
                                                                          pSpline,
                                                                          pApplyRotation,
                                                                          pApplyScale,
                                                                          pUseConstantSpeed,
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
    }
    else
    {
        UE_LOG(LogTweenMaker, Warning, TEXT("UTweenFloatStandardFactory::CreateAppendTweenFollowSpline() -> the Tween that had as target the "
                                            "object with name %s couldn't be added because the passed TweenContainer was null."), *pTarget->GetName());
    }

    return outTween;
}

// static private --------------------------------------------------------------
UTweenFloat* UTweenFloatStandardFactory::CreateJoinTweenFollowSpline(UTweenContainer* pTweenContainer,
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
                                                                     int32 pSequenceIndex)
{
    UTweenFloat* outTween = nullptr;

    if (pTweenContainer != nullptr)
    {
        UTweenManagerComponent* tweenManagerInstance = pTweenContainer->OwningTweenManager;

        if (tweenManagerInstance != nullptr)
        {
            int32 tweenIndex = pSequenceIndex > -1 ? pSequenceIndex : pTweenContainer->GetSequencesNum() - 1;

            outTween = tweenManagerInstance->JoinTweenFollowSplineFloat(pTweenContainer,
                                                                        tweenIndex,
                                                                        pTweenType,
                                                                        pTarget,
                                                                        pTargetType,
                                                                        pSpline,
                                                                        pApplyRotation,
                                                                        pApplyScale,
                                                                        pUseConstantSpeed,
                                                                        pDuration,
                                                                        pEaseType,
                                                                        pDeleteTweenOnHit,
                                                                        pDeleteTweenOnOverlap,
                                                                        pDelay,
                                                                        pTimeScale,
                                                                        pTweenWhileGameIsPaused);
        }
    }
    else
    {
        UE_LOG(LogTweenMaker, Warning, TEXT("UTweenFloatStandardFactory::CreateJoinTweenFollowSpline() -> the Tween that had as target the "
                                            "object with name %s couldn't be added because the passed TweenContainer was null."), *pTarget->GetName());
    }

    return outTween;
}

