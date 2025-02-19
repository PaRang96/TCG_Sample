// Copyright 2018 Francesco Desogus. All Rights Reserved.

#include "TweenFactory/Latent/TweenFloatLatentFactory.h"

#include "GameFramework/Actor.h"
#include "Tweens/TweenFloat.h"
#include "Materials/MaterialInstanceDynamic.h"
#include "Components/Widget.h"
#include "TweenContainer.h"

// public ----------------------------------------------------------------------
UTweenFloatLatentFactory::UTweenFloatLatentFactory(const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer)
{

}

// static public ---------------------------------------------------------------
UTweenFloatLatentFactory* UTweenFloatLatentFactory::BP_CreateLatentTweenMaterialFloatFromTo(UTweenManagerComponent* pTweenManagerComponent,
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
                                                                                            bool pTweenWhileGameIsPaused)
{
    pOutTweenContainer = pTweenManagerComponent != nullptr ? pTweenManagerComponent->CreateTweenContainer() 
                                                           : UTweenManagerComponent::CreateTweenContainerStatic();
    
    return BP_AppendLatentTweenMaterialFloatFromTo(pOutTweenContainer,
                                                   pOutTween,
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
                                                   pTweenWhileGameIsPaused);
}

// static public ---------------------------------------------------------------
UTweenFloatLatentFactory* UTweenFloatLatentFactory::BP_CreateLatentTweenMaterialFloatTo(UTweenManagerComponent* pTweenManagerComponent,
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
                                                                                        bool pTweenWhileGameIsPaused)
{
    pOutTweenContainer = pTweenManagerComponent != nullptr ? pTweenManagerComponent->CreateTweenContainer() 
                                                           : UTweenManagerComponent::CreateTweenContainerStatic();
    
    return BP_AppendLatentTweenMaterialFloatTo(pOutTweenContainer,
                                               pOutTween,
                                               pTweenTarget,
                                               pParameterName,
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
UTweenFloatLatentFactory* UTweenFloatLatentFactory::BP_CreateLatentTweenRotateActorAroundPoint(UTweenManagerComponent* pTweenManagerComponent,
                                                                                               AActor* pTweenTarget,
                                                                                               UTweenContainer*& pOutTweenContainer,
                                                                                               UTweenFloat*& pOutTween,
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
    pOutTweenContainer = pTweenManagerComponent != nullptr ? pTweenManagerComponent->CreateTweenContainer() 
                                                           : UTweenManagerComponent::CreateTweenContainerStatic();

    return BP_AppendLatentTweenRotateActorAroundPoint(pOutTweenContainer,
                                                      pOutTween,
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
                                                      pTweenWhileGameIsPaused);
}

// static public ---------------------------------------------------------------
UTweenFloatLatentFactory* UTweenFloatLatentFactory::BP_CreateLatentTweenRotateActorAroundPointByOffset(UTweenManagerComponent* pTweenManagerComponent,
                                                                                                       AActor* pTweenTarget,
                                                                                                       UTweenContainer*& pOutTweenContainer,
                                                                                                       UTweenFloat*& pOutTween,
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
    float startingAngle = 0;
    FVector axis;
    float radius;
    Utility::ComputeDataForRotateAroundPoint(pTweenTarget, pPivotPoint, pReferenceAxis, pTweenSpace, axis, radius);

    pOutTweenContainer = pTweenManagerComponent != nullptr ? pTweenManagerComponent->CreateTweenContainer() 
                                                           : UTweenManagerComponent::CreateTweenContainerStatic();
    
    return BP_AppendLatentTweenRotateActorAroundPoint(pOutTweenContainer,
                                                      pOutTween,
                                                      pTweenTarget,
                                                      pPivotPoint,
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
                                                      pTweenWhileGameIsPaused);
}

// static public ---------------------------------------------------------------
UTweenFloatLatentFactory* UTweenFloatLatentFactory::BP_CreateLatentTweenActorFollowSpline(UTweenManagerComponent* pTweenManagerComponent,
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
                                                                                          bool pTweenWhileGameIsPaused)
{
    pOutTweenContainer = pTweenManagerComponent != nullptr ? pTweenManagerComponent->CreateTweenContainer() 
                                                           : UTweenManagerComponent::CreateTweenContainerStatic();
    
    return BP_AppendLatentTweenActorFollowSpline(pOutTweenContainer,
                                                 pOutTween,
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
                                                 pTweenWhileGameIsPaused);
}

// static public ---------------------------------------------------------------
UTweenFloatLatentFactory* UTweenFloatLatentFactory::BP_CreateLatentTweenRotateSceneComponentAroundPoint(UTweenManagerComponent *pTweenManagerComponent,
                                                                                                        USceneComponent* pTweenTarget,
                                                                                                        UTweenContainer*& pOutTweenContainer,
                                                                                                        UTweenFloat*& pOutTween,
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
    pOutTweenContainer = pTweenManagerComponent != nullptr ? pTweenManagerComponent->CreateTweenContainer() 
                                                           : UTweenManagerComponent::CreateTweenContainerStatic();
    
    return BP_AppendLatentTweenRotateSceneComponentAroundPoint(pOutTweenContainer,
                                                               pOutTween,
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
                                                               pTweenWhileGameIsPaused);
}

// static public ---------------------------------------------------------------
UTweenFloatLatentFactory* UTweenFloatLatentFactory::BP_CreateLatentTweenRotateSceneComponentAroundPointByOffset(UTweenManagerComponent *pTweenManagerComponent,
                                                                                                                USceneComponent *pTweenTarget,
                                                                                                                UTweenContainer *&pOutTweenContainer,
                                                                                                                UTweenFloat *&pOutTween,
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
    float startingAngle = 0;
    FVector axis;
    float radius;
    Utility::ComputeDataForRotateAroundPoint(pTweenTarget, pPivotPoint, pReferenceAxis, pTweenSpace, axis, radius);

    pOutTweenContainer = pTweenManagerComponent != nullptr ? pTweenManagerComponent->CreateTweenContainer() 
                                                           : UTweenManagerComponent::CreateTweenContainerStatic();
    
    return BP_AppendLatentTweenRotateSceneComponentAroundPoint(pOutTweenContainer,
                                                               pOutTween,
                                                               pTweenTarget,
                                                               pPivotPoint,
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
                                                               pTweenWhileGameIsPaused);
}

// static public ---------------------------------------------------------------
UTweenFloatLatentFactory* UTweenFloatLatentFactory::BP_CreateLatentTweenSceneComponentFollowSpline(UTweenManagerComponent* pTweenManagerComponent,
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
                                                                                                   bool pTweenWhileGameIsPaused)
{
    pOutTweenContainer = pTweenManagerComponent != nullptr ? pTweenManagerComponent->CreateTweenContainer() 
                                                           : UTweenManagerComponent::CreateTweenContainerStatic();
    
    return BP_AppendLatentTweenSceneComponentFollowSpline(pOutTweenContainer,
                                                          pOutTween,
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
                                                          pTweenWhileGameIsPaused);
}

// static public ---------------------------------------------------------------
UTweenFloatLatentFactory* UTweenFloatLatentFactory::BP_CreateLatentTweenWidgetAngleTo(UTweenManagerComponent* pTweenManagerComponent,
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
                                                                                      bool pTweenWhileGameIsPaused)
{
    pOutTweenContainer = pTweenManagerComponent != nullptr ? pTweenManagerComponent->CreateTweenContainer() 
                                                           : UTweenManagerComponent::CreateTweenContainerStatic();

    return BP_AppendLatentTweenWidgetAngleTo(pOutTweenContainer,
                                             pOutTween,
                                             pTweenTarget,
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
UTweenFloatLatentFactory* UTweenFloatLatentFactory::BP_CreateLatentTweenWidgetOpacityTo(UTweenManagerComponent* pTweenManagerComponent,
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
                                                                                        bool pTweenWhileGameIsPaused)
{
    pOutTweenContainer = pTweenManagerComponent != nullptr ? pTweenManagerComponent->CreateTweenContainer()
                                                           : UTweenManagerComponent::CreateTweenContainerStatic();

    return BP_AppendLatentTweenWidgetOpacityTo(pOutTweenContainer,
                                               pOutTween,
                                               pTweenTarget,
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
UTweenFloatLatentFactory* UTweenFloatLatentFactory::BP_CreateLatentTweenCustomFloat(UTweenManagerComponent* pTweenManagerComponent,
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
                                                                                    bool pTweenWhileGameIsPaused)
{
    pOutTweenContainer = pTweenManagerComponent != nullptr ? pTweenManagerComponent->CreateTweenContainer()
                                                           : UTweenManagerComponent::CreateTweenContainerStatic();
    
    return BP_AppendLatentTweenCustomFloat(pOutTweenContainer,
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
UTweenFloatLatentFactory* UTweenFloatLatentFactory::BP_AppendLatentTweenMaterialFloatFromTo(UTweenContainer* pTweenContainer,
                                                                                            UTweenFloat*& pOutTween,
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
                                                                                            bool pTweenWhileGameIsPaused)
{
    ETweenTargetType targetType = ETweenTargetType::Material;
    ETweenFloatType tweenType   = ETweenFloatType::MaterialScalarFromTo;

    return CreateProxyForAppendTweenFloat(pTweenContainer,
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
                                          pOutTween,
                                          pParameterName);
}

// static public ---------------------------------------------------------------
UTweenFloatLatentFactory* UTweenFloatLatentFactory::BP_AppendLatentTweenMaterialFloatTo(UTweenContainer* pTweenContainer,
                                                                                        UTweenFloat*& OutTween,
                                                                                        UMaterialInstanceDynamic* pTweenTarget,
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
    ETweenTargetType targetType = ETweenTargetType::Material;
    ETweenFloatType tweenType   = ETweenFloatType::MaterialScalarTo;
    float dummyFromFloat        = 0.0f;

    return CreateProxyForAppendTweenFloat(pTweenContainer,
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
                                          OutTween,
                                          pParameterName);
}

// static public ---------------------------------------------------------------
UTweenFloatLatentFactory* UTweenFloatLatentFactory::BP_AppendLatentTweenRotateActorAroundPoint(UTweenContainer* pTweenContainer,
                                                                                               UTweenFloat*& OutTween,
                                                                                               AActor* pTweenTarget,
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
    ETweenTargetType targetType = ETweenTargetType::Actor;
    ETweenFloatType tweenType   = ETweenFloatType::RotateAroundPoint;

    return CreateProxyForAppendTweenRotateAroundFloat(pTweenContainer,
                                                      tweenType,
                                                      pTweenTarget,
                                                      targetType,
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
                                                      OutTween);
}

// static public ---------------------------------------------------------------
UTweenFloatLatentFactory* UTweenFloatLatentFactory::BP_AppendLatentTweenRotateActorAroundPointByOffset(UTweenContainer* pTweenContainer,
                                                                                                       UTweenFloat*& OutTween,
                                                                                                       AActor* pTweenTarget,
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
    float startingAngle = 0;
    FVector axis;
    float radius;
    Utility::ComputeDataForRotateAroundPoint(pTweenTarget, pPivotPoint, pReferenceAxis, pTweenSpace, axis, radius);

    return BP_AppendLatentTweenRotateActorAroundPoint(pTweenContainer,
                                                      OutTween,
                                                      pTweenTarget,
                                                      pPivotPoint,
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
                                                      pTweenWhileGameIsPaused);
}

// static public ---------------------------------------------------------------
UTweenFloatLatentFactory* UTweenFloatLatentFactory::BP_AppendLatentTweenActorFollowSpline(UTweenContainer* pTweenContainer,
                                                                                          UTweenFloat*& OutTween,
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
                                                                                          bool pTweenWhileGameIsPaused)
{
    ETweenTargetType targetType = ETweenTargetType::Actor;
    ETweenFloatType tweenType   = ETweenFloatType::FollowSpline;

    return CreateProxyForAppendTweenFollowSpline(pTweenContainer,
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
                                                 OutTween);
}

// static public ---------------------------------------------------------------
UTweenFloatLatentFactory* UTweenFloatLatentFactory::BP_AppendLatentTweenRotateSceneComponentAroundPoint(UTweenContainer* pTweenContainer,
                                                                                                        UTweenFloat*& OutTween,
                                                                                                        USceneComponent* pTweenTarget,
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
    ETweenTargetType targetType = ETweenTargetType::SceneComponent;
    ETweenFloatType tweenType   = ETweenFloatType::RotateAroundPoint;

    return CreateProxyForAppendTweenRotateAroundFloat(pTweenContainer,
                                                      tweenType,
                                                      pTweenTarget,
                                                      targetType,
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
                                                      OutTween);
}

// static public ---------------------------------------------------------------
UTweenFloatLatentFactory* UTweenFloatLatentFactory::BP_AppendLatentTweenRotateSceneComponentAroundPointByOffset(UTweenContainer* pTweenContainer,
                                                                                                                UTweenFloat*& OutTween,
                                                                                                                USceneComponent* pTweenTarget,
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
    float startingAngle = 0;
    FVector axis;
    float radius;
    Utility::ComputeDataForRotateAroundPoint(pTweenTarget, pPivotPoint, pReferenceAxis, pTweenSpace, axis, radius);

    return BP_AppendLatentTweenRotateSceneComponentAroundPoint(pTweenContainer,
                                                               OutTween,
                                                               pTweenTarget,
                                                               pPivotPoint,
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
                                                               pTweenWhileGameIsPaused);
}

// static public ---------------------------------------------------------------
UTweenFloatLatentFactory* UTweenFloatLatentFactory::BP_AppendLatentTweenSceneComponentFollowSpline(UTweenContainer* pTweenContainer,
                                                                                                   UTweenFloat*& OutTween,
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
                                                                                                   bool pTweenWhileGameIsPaused)
{
    ETweenTargetType targetType = ETweenTargetType::SceneComponent;
    ETweenFloatType tweenType   = ETweenFloatType::FollowSpline;

    return CreateProxyForAppendTweenFollowSpline(pTweenContainer,
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
                                                 OutTween);
}

// static public ---------------------------------------------------------------
UTweenFloatLatentFactory* UTweenFloatLatentFactory::BP_AppendLatentTweenWidgetAngleTo(UTweenContainer* pTweenContainer,
                                                                                      UTweenFloat*& OutTween,
                                                                                      UWidget* pTweenTarget,
                                                                                      float pTo,
                                                                                      float pDuration,
                                                                                      ETweenEaseType pEaseType,
                                                                                      int32 pNumLoops,
                                                                                      ETweenLoopType pLoopType,
                                                                                      float pDelay,
                                                                                      float pTimeScale,
                                                                                      bool pTweenWhileGameIsPaused)
{
    ETweenTargetType targetType = ETweenTargetType::UMG;
    ETweenFloatType tweenType   = ETweenFloatType::WidgetAngleTo;
    float dummyFromFloat        = 0.0f;

    return CreateProxyForAppendTweenFloat(pTweenContainer,
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
                                          OutTween);
}

// static public ---------------------------------------------------------------
UTweenFloatLatentFactory* UTweenFloatLatentFactory::BP_AppendLatentTweenWidgetOpacityTo(UTweenContainer* pTweenContainer,
                                                                                        UTweenFloat*& OutTween,
                                                                                        UWidget* pTweenTarget,
                                                                                        float pTo,
                                                                                        float pDuration,
                                                                                        ETweenEaseType pEaseType,
                                                                                        int32 pNumLoops,
                                                                                        ETweenLoopType pLoopType,
                                                                                        float pDelay,
                                                                                        float pTimeScale,
                                                                                        bool pTweenWhileGameIsPaused)
{
    ETweenTargetType targetType = ETweenTargetType::UMG;
    ETweenFloatType tweenType   = ETweenFloatType::WidgetOpacityTo;
    float dummyFromFloat        = 0.0f;

    return CreateProxyForAppendTweenFloat(pTweenContainer,
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
                                          OutTween);
}

// static public ---------------------------------------------------------------
UTweenFloatLatentFactory* UTweenFloatLatentFactory::BP_AppendLatentTweenCustomFloat(UTweenContainer* pTweenContainer,
                                                                                    UTweenFloat*& OutTween,
                                                                                    UObject* pTweenTarget,
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
    ETweenTargetType targetType = ETweenTargetType::Custom;
    ETweenFloatType tweenType   = ETweenFloatType::Custom;

    return CreateProxyForAppendTweenFloat(pTweenContainer,
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
                                          OutTween);
}

// static public ---------------------------------------------------------------
UTweenFloatLatentFactory* UTweenFloatLatentFactory::BP_JoinLatentTweenMaterialFloatFromTo(UTweenContainer* pTweenContainer,
                                                                                          UTweenFloat*& OutTween,
                                                                                          UMaterialInstanceDynamic* pTweenTarget,
                                                                                          FName pParameterName,
                                                                                          float pFrom,
                                                                                          float pTo,
                                                                                          float pDuration,
                                                                                          ETweenEaseType pEaseType,
                                                                                          float pDelay,
                                                                                          float pTimeScale,
                                                                                          bool pTweenWhileGameIsPaused)
{
    ETweenTargetType targetType = ETweenTargetType::Material;
    ETweenFloatType tweenType   = ETweenFloatType::MaterialScalarFromTo;

    return CreateProxyForJoinTweenFloat(pTweenContainer,
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
                                        OutTween,
                                        pParameterName);
}

// static public ---------------------------------------------------------------
UTweenFloatLatentFactory* UTweenFloatLatentFactory::BP_JoinLatentTweenMaterialFloatTo(UTweenContainer* pTweenContainer,
                                                                                      UTweenFloat*& OutTween,
                                                                                      UMaterialInstanceDynamic* pTweenTarget,
                                                                                      FName pParameterName,
                                                                                      float pTo,
                                                                                      float pDuration,
                                                                                      ETweenEaseType pEaseType,
                                                                                      float pDelay,
                                                                                      float pTimeScale,
                                                                                      bool pTweenWhileGameIsPaused)
{
    ETweenTargetType targetType = ETweenTargetType::Material;
    ETweenFloatType tweenType   = ETweenFloatType::MaterialScalarTo;
    float dummyFromFloat        = 0.0f;

    return CreateProxyForJoinTweenFloat(pTweenContainer,
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
                                        OutTween,
                                        pParameterName);
}

// static public ---------------------------------------------------------------
UTweenFloatLatentFactory* UTweenFloatLatentFactory::BP_JoinLatentTweenRotateActorAroundPoint(UTweenContainer* pTweenContainer,
                                                                                             UTweenFloat*& OutTween,
                                                                                             AActor* pTweenTarget,
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
    ETweenTargetType targetType = ETweenTargetType::Actor;
    ETweenFloatType tweenType   = ETweenFloatType::RotateAroundPoint;

    return CreateProxyForJoinTweenRotateAroundFloat(pTweenContainer,
                                                    tweenType,
                                                    pTweenTarget,
                                                    targetType,
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
                                                    OutTween);
}

// static public ---------------------------------------------------------------
UTweenFloatLatentFactory* UTweenFloatLatentFactory::BP_JoinLatentTweenRotateActorAroundPointByOffset(UTweenContainer* pTweenContainer,
                                                                                                     UTweenFloat*& OutTween,
                                                                                                     AActor* pTweenTarget,
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
    float startingAngle = 0;
    FVector axis;
    float radius;
    Utility::ComputeDataForRotateAroundPoint(pTweenTarget, pPivotPoint, pReferenceAxis, pTweenSpace, axis, radius);

    return BP_JoinLatentTweenRotateActorAroundPoint(pTweenContainer,
                                                    OutTween,
                                                    pTweenTarget,
                                                    pPivotPoint,
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
                                                    pTweenWhileGameIsPaused);
}

// static public ---------------------------------------------------------------
UTweenFloatLatentFactory* UTweenFloatLatentFactory::BP_JoinLatentTweenActorFollowSpline(UTweenContainer* pTweenContainer,
                                                                                        UTweenFloat*& OutTween,
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
                                                                                        bool pTweenWhileGameIsPaused)
{
    ETweenTargetType targetType = ETweenTargetType::Actor;
    ETweenFloatType tweenType   = ETweenFloatType::FollowSpline;

    return CreateProxyForJoinTweenFollowSpline(pTweenContainer,
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
                                               OutTween);
}

// static public ---------------------------------------------------------------
UTweenFloatLatentFactory* UTweenFloatLatentFactory::BP_JoinLatentTweenRotateSceneComponentAroundPoint(UTweenContainer* pTweenContainer,
                                                                                                      UTweenFloat*& OutTween,
                                                                                                      USceneComponent* pTweenTarget,
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
    ETweenTargetType targetType = ETweenTargetType::SceneComponent;
    ETweenFloatType tweenType   = ETweenFloatType::RotateAroundPoint;

    return CreateProxyForJoinTweenRotateAroundFloat(pTweenContainer,
                                                    tweenType,
                                                    pTweenTarget,
                                                    targetType,
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
                                                    OutTween);
}

// static public ---------------------------------------------------------------
UTweenFloatLatentFactory* UTweenFloatLatentFactory::BP_JoinLatentTweenRotateSceneComponentAroundPointByOffset(UTweenContainer* pTweenContainer,
                                                                                                              UTweenFloat*& OutTween,
                                                                                                              USceneComponent* pTweenTarget,
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
    float startingAngle = 0;
    FVector axis;
    float radius;
    Utility::ComputeDataForRotateAroundPoint(pTweenTarget, pPivotPoint, pReferenceAxis, pTweenSpace, axis, radius);

    return BP_JoinLatentTweenRotateSceneComponentAroundPoint(pTweenContainer,
                                                             OutTween,
                                                             pTweenTarget,
                                                             pPivotPoint,
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
                                                             pTweenWhileGameIsPaused);
}

// static public ---------------------------------------------------------------
UTweenFloatLatentFactory* UTweenFloatLatentFactory::BP_JoinLatentTweenSceneComponentFollowSpline(UTweenContainer* pTweenContainer,
                                                                                                 UTweenFloat*& OutTween,
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
                                                                                                 bool pTweenWhileGameIsPaused)
{
    ETweenTargetType targetType = ETweenTargetType::SceneComponent;
    ETweenFloatType tweenType   = ETweenFloatType::FollowSpline;

    return CreateProxyForJoinTweenFollowSpline(pTweenContainer,
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
                                               OutTween);
}

// static public ---------------------------------------------------------------
UTweenFloatLatentFactory* UTweenFloatLatentFactory::BP_JoinLatentTweenWidgetAngleTo(UTweenContainer* pTweenContainer,
                                                                                    UTweenFloat*& OutTween,
                                                                                    UWidget* pTweenTarget,
                                                                                    float pTo,
                                                                                    float pDuration,
                                                                                    ETweenEaseType pEaseType,
                                                                                    float pDelay,
                                                                                    float pTimeScale,
                                                                                    bool pTweenWhileGameIsPaused)
{
    ETweenTargetType targetType = ETweenTargetType::UMG;
    ETweenFloatType tweenType   = ETweenFloatType::WidgetAngleTo;
    float dummyFromFloat        = 0.0f;

    return CreateProxyForJoinTweenFloat(pTweenContainer,
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
                                        OutTween);
}

// static public ---------------------------------------------------------------
UTweenFloatLatentFactory* UTweenFloatLatentFactory::BP_JoinLatentTweenWidgetOpacityTo(UTweenContainer* pTweenContainer,
                                                                                      UTweenFloat*& OutTween,
                                                                                      UWidget* pTweenTarget,
                                                                                      float pTo,
                                                                                      float pDuration,
                                                                                      ETweenEaseType pEaseType,
                                                                                      float pDelay,
                                                                                      float pTimeScale,
                                                                                      bool pTweenWhileGameIsPaused)
{
    ETweenTargetType targetType = ETweenTargetType::UMG;
    ETweenFloatType tweenType   = ETweenFloatType::WidgetOpacityTo;
    float dummyFromFloat        = 0.0f;

    return CreateProxyForJoinTweenFloat(pTweenContainer,
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
                                        OutTween);
}

// static public ---------------------------------------------------------------
UTweenFloatLatentFactory* UTweenFloatLatentFactory::BP_JoinLatentTweenCustomFloat(UTweenContainer* pTweenContainer,
                                                                                  UTweenFloat*& OutTween,
                                                                                  UObject* pTweenTarget,
                                                                                  float pFrom,
                                                                                  float pTo,
                                                                                  float pDuration,
                                                                                  ETweenEaseType pEaseType,
                                                                                  float pDelay,
                                                                                  float pTimeScale,
                                                                                  bool pTweenWhileGameIsPaused)
{
    ETweenTargetType targetType = ETweenTargetType::Custom;
    ETweenFloatType tweenType   = ETweenFloatType::Custom;

    return CreateProxyForJoinTweenFloat(pTweenContainer,
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
                                        OutTween);
}

// public ----------------------------------------------------------------------
void UTweenFloatLatentFactory::Activate()
{
    Super::Activate();
}

// static private --------------------------------------------------------------
UTweenFloatLatentFactory* UTweenFloatLatentFactory::CreateProxyForAppendTweenFloat(UTweenContainer* pTweenContainer,
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
                                                                                   UTweenFloat*& OutTween,
                                                                                   FName pParameterName)
{
    UTweenFloatLatentFactory* proxy = NewObject<UTweenFloatLatentFactory>();

    if (pTweenContainer != nullptr)
    {
        UTweenManagerComponent* instance = pTweenContainer->OwningTweenManager;

        if (instance != nullptr)
        {
            int32 tweenIndex = pTweenContainer->GetSequencesNum();

            OutTween = instance->AppendTweenFloat(pTweenContainer,
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
                                                  proxy,
                                                  pParameterName);
        }
    }
    else
    {
        UE_LOG(LogTweenMaker, Warning, TEXT("UTweenFloatLatentFactory::CreateProxyForAppendTweenFloat() -> the Tween that had as target the "
                                            "object with name %s couldn't be added because the passed TweenContainer was null."), *pTarget->GetName());
    }

    return proxy;
}

// static private --------------------------------------------------------------
UTweenFloatLatentFactory* UTweenFloatLatentFactory::CreateProxyForJoinTweenFloat(UTweenContainer* pTweenContainer,
                                                                                 ETweenFloatType pTweenType,
                                                                                 UObject* pTarget,
                                                                                 ETweenTargetType pTargetType,
                                                                                 float pFrom,
                                                                                 float pTo,
                                                                                 float pDuration,
                                                                                 ETweenEaseType pEaseType,
                                                                                 float pDelay,
                                                                                 float pTimeScale,
                                                                                 bool pTweenWhileGameIsPaused,
                                                                                 UTweenFloat*& OutTween,
                                                                                 FName pParameterName)
{
    UTweenFloatLatentFactory* proxy = NewObject<UTweenFloatLatentFactory>();

    if (pTweenContainer != nullptr)
    {
        UTweenManagerComponent* instance = pTweenContainer->OwningTweenManager;

        if (instance != nullptr)
        {
            int32 tweenIndex = pTweenContainer->GetSequencesNum() - 1;

            OutTween = instance->JoinTweenFloat(pTweenContainer,
                                                tweenIndex,
                                                pTweenType,
                                                pTarget,
                                                pTargetType,
                                                pFrom,
                                                pTo,
                                                pDuration,
                                                pEaseType,
                                                pDelay,
                                                pTimeScale,
                                                pTweenWhileGameIsPaused,
                                                proxy,
                                                pParameterName);
        }
    }
    else
    {
        UE_LOG(LogTweenMaker, Warning, TEXT("UTweenFloatLatentFactory::CreateProxyForJoinTweenFloat() -> the Tween that had as target the "
                                            "object with name %s couldn't be added because the passed TweenContainer was null."), *pTarget->GetName());
    }

    return proxy;
}

// static private --------------------------------------------------------------
UTweenFloatLatentFactory* UTweenFloatLatentFactory::CreateProxyForAppendTweenRotateAroundFloat(UTweenContainer* pTweenContainer,
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
                                                                                               UTweenFloat*& OutTween)
{
    UTweenFloatLatentFactory* proxy = NewObject<UTweenFloatLatentFactory>();

    if (pTweenContainer != nullptr)
    {
        UTweenManagerComponent* instance = pTweenContainer->OwningTweenManager;

        if (instance != nullptr)
        {
            int32 tweenIndex = pTweenContainer->GetSequencesNum();

            OutTween = instance->AppendTweenRotateAroundFloat(pTweenContainer,
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
                                                              pTweenWhileGameIsPaused,
                                                              proxy);
        }
    }
    else
    {
        UE_LOG(LogTweenMaker, Warning, TEXT("UTweenFloatLatentFactory::CreateProxyForAppendTweenRotateAroundFloat() -> the Tween that had as target the "
                                            "object with name %s couldn't be added because the passed TweenContainer was null."), *pTarget->GetName());
    }

    return proxy;
}

// static private --------------------------------------------------------------
UTweenFloatLatentFactory* UTweenFloatLatentFactory::CreateProxyForJoinTweenRotateAroundFloat(UTweenContainer *pTweenContainer,
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
                                                                                             UTweenFloat*& OutTween)
{
    UTweenFloatLatentFactory* proxy = NewObject<UTweenFloatLatentFactory>();

    if (pTweenContainer != nullptr)
    {
        UTweenManagerComponent* instance = pTweenContainer->OwningTweenManager;

        if (instance != nullptr)
        {
            int32 tweenIndex = pTweenContainer->GetSequencesNum() - 1;

            OutTween = instance->JoinTweenRotateAroundFloat(pTweenContainer,
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
                                                            pTweenWhileGameIsPaused,
                                                            proxy);
        }
    }
    else
    {
        UE_LOG(LogTweenMaker,  Warning, TEXT("UTweenFloatLatentFactory::CreateProxyForJoinTweenRotateAroundFloat() -> the Tween that had as target the "
                                            "object with name %s couldn't be added because the passed TweenContainer was null."), *pTarget->GetName());
    }

    return proxy;
}

// static private --------------------------------------------------------------
UTweenFloatLatentFactory* UTweenFloatLatentFactory::CreateProxyForAppendTweenFollowSpline(UTweenContainer* pTweenContainer,
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
                                                                                          UTweenFloat*& OutTween)
{
    UTweenFloatLatentFactory* proxy = NewObject<UTweenFloatLatentFactory>();

    if (pTweenContainer != nullptr)
    {
        UTweenManagerComponent* instance = pTweenContainer->OwningTweenManager;


        if (instance != nullptr)
        {
            int32 tweenIndex = pTweenContainer->GetSequencesNum();

            OutTween = instance->AppendTweenFollowSplineFloat(pTweenContainer,
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
                                                              pTweenWhileGameIsPaused,
                                                              proxy);
        }
    }
    else
    {
        UE_LOG(LogTweenMaker, Warning, TEXT("UTweenFloatLatentFactory::CreateProxyForJoinTweenRotateAroundFloat() -> the Tween that had as target the "
                                            "object with name %s couldn't be added because the passed TweenContainer was null."), *pTarget->GetName());
    }


    return proxy;
}

// static private --------------------------------------------------------------
UTweenFloatLatentFactory* UTweenFloatLatentFactory::CreateProxyForJoinTweenFollowSpline(UTweenContainer *pTweenContainer,
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
                                                                                        UTweenFloat*& OutTween)
{
    UTweenFloatLatentFactory* proxy = NewObject<UTweenFloatLatentFactory>();

    if (pTweenContainer != nullptr)
    {
        UTweenManagerComponent* instance = pTweenContainer->OwningTweenManager;


        if (instance != nullptr)
        {
            int32 tweenIndex = pTweenContainer->GetSequencesNum() - 1;
            
            OutTween = instance->JoinTweenFollowSplineFloat(pTweenContainer,
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
                                                            pTweenWhileGameIsPaused,
                                                            proxy);
        }
    }
    else
    {
        UE_LOG(LogTweenMaker, Warning, TEXT("UTweenFloatLatentFactory::CreateProxyForJoinTweenRotateAroundFloat() -> the Tween that had as target the "
                                            "object with name %s couldn't be added because the passed TweenContainer was null."), *pTarget->GetName());
    }

    return proxy;
}
