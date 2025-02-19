// Copyright 2018 Francesco Desogus. All Rights Reserved.

#include "TweenFactory/Latent/TweenVector2DLatentFactory.h"

#include "Components/Widget.h"
#include "Tweens/TweenVector2D.h"
#include "TweenContainer.h"

// public ----------------------------------------------------------------------
UTweenVector2DLatentFactory::UTweenVector2DLatentFactory(const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer)
{

}

// static public ---------------------------------------------------------------
UTweenVector2DLatentFactory* UTweenVector2DLatentFactory::BP_CreateLatentTweenMoveWidgetTo(UTweenManagerComponent* pTweenManagerComponent,
                                                                                           UWidget* pTweenTarget,
                                                                                           UTweenContainer*& pOutTweenContainer,
                                                                                           UTweenVector2D*& pOutTween,
                                                                                           FVector2D pTo,
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

    return BP_AppendLatentTweenMoveWidgetTo(pOutTweenContainer,
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
UTweenVector2DLatentFactory* UTweenVector2DLatentFactory::BP_CreateLatentTweenMoveWidgetBy(UTweenManagerComponent* pTweenManagerComponent,
                                                                                           UWidget* pTweenTarget,
                                                                                           UTweenContainer*& pOutTweenContainer,
                                                                                           UTweenVector2D*& pOutTween,
                                                                                           FVector2D pBy,
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

    return BP_AppendLatentTweenMoveWidgetBy(pOutTweenContainer,
                                            pOutTween,
                                            pTweenTarget,
                                            pBy,
                                            pDuration,
                                            pEaseType,
                                            pNumLoops,
                                            pLoopType,
                                            pDelay,
                                            pTimeScale,
                                            pTweenWhileGameIsPaused);
}

// static public ---------------------------------------------------------------
UTweenVector2DLatentFactory* UTweenVector2DLatentFactory::BP_CreateLatentTweenScaleWidgetTo(UTweenManagerComponent* pTweenManagerComponent,
                                                                                            UWidget* pTweenTarget,
                                                                                            UTweenContainer*& pOutTweenContainer,
                                                                                            UTweenVector2D*& pOutTween,
                                                                                            FVector2D pTo,
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

    return BP_AppendLatentTweenScaleWidgetTo(pOutTweenContainer,
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
UTweenVector2DLatentFactory* UTweenVector2DLatentFactory::BP_CreateLatentTweenScaleWidgetBy(UTweenManagerComponent* pTweenManagerComponent,
                                                                                            UWidget* pTweenTarget,
                                                                                            UTweenContainer*& pOutTweenContainer,
                                                                                            UTweenVector2D*& pOutTween,
                                                                                            FVector2D pBy,
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

    return BP_AppendLatentTweenScaleWidgetBy(pOutTweenContainer,
                                             pOutTween,
                                             pTweenTarget,
                                             pBy,
                                             pDuration,
                                             pEaseType,
                                             pNumLoops,
                                             pLoopType,
                                             pDelay,
                                             pTimeScale,
                                             pTweenWhileGameIsPaused);
}

// static public ---------------------------------------------------------------
UTweenVector2DLatentFactory* UTweenVector2DLatentFactory::BP_CreateLatentTweenShearWidgetTo(UTweenManagerComponent* pTweenManagerComponent,
                                                                                            UWidget* pTweenTarget,
                                                                                            UTweenContainer*& pOutTweenContainer,
                                                                                            UTweenVector2D*& pOutTween,
                                                                                            FVector2D pTo,
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

    return BP_AppendLatentTweenShearWidgetTo(pOutTweenContainer,
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
UTweenVector2DLatentFactory* UTweenVector2DLatentFactory::BP_CreateLatentTweenCustomVector2D(UTweenManagerComponent* pTweenManagerComponent,
                                                                                             UObject* pTweenTarget,
                                                                                             UTweenContainer*& pOutTweenContainer,
                                                                                             UTweenVector2D*& pOutTween,
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
    pOutTweenContainer = pTweenManagerComponent != nullptr ? pTweenManagerComponent->CreateTweenContainer() 
                                                           : UTweenManagerComponent::CreateTweenContainerStatic();

    return BP_AppendLatentTweenCustomVector2D(pOutTweenContainer,
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
UTweenVector2DLatentFactory* UTweenVector2DLatentFactory::BP_AppendLatentTweenMoveWidgetTo(UTweenContainer* pTweenContainer,
                                                                                           UTweenVector2D*& OutTween,
                                                                                           UWidget* pTweenTarget,
                                                                                           FVector2D pTo,
                                                                                           float pDuration,
                                                                                           ETweenEaseType pEaseType,
                                                                                           int32 pNumLoops,
                                                                                           ETweenLoopType pLoopType,
                                                                                           float pDelay,
                                                                                           float pTimeScale,
                                                                                           bool pTweenWhileGameIsPaused)
{
    ETweenTargetType targetType  = ETweenTargetType::UMG;
    ETweenVector2DType tweenType = ETweenVector2DType::MoveTo;
    FVector2D dummyFromVec       = FVector2D(0, 0);

    return CreateProxyForAppendTweenVector2D(pTweenContainer,
                                             tweenType,
                                             pTweenTarget,
                                             targetType,
                                             dummyFromVec,
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
UTweenVector2DLatentFactory* UTweenVector2DLatentFactory::BP_AppendLatentTweenMoveWidgetBy(UTweenContainer* pTweenContainer,
                                                                                           UTweenVector2D*& OutTween,
                                                                                           UWidget* pTweenTarget,
                                                                                           FVector2D pBy,
                                                                                           float pDuration,
                                                                                           ETweenEaseType pEaseType,
                                                                                           int32 pNumLoops,
                                                                                           ETweenLoopType pLoopType,
                                                                                           float pDelay,
                                                                                           float pTimeScale,
                                                                                           bool pTweenWhileGameIsPaused)
{
    ETweenTargetType targetType  = ETweenTargetType::UMG;
    ETweenVector2DType tweenType = ETweenVector2DType::MoveBy;
    FVector2D dummyFromVec       = FVector2D(0, 0);

    return CreateProxyForAppendTweenVector2D(pTweenContainer,
                                             tweenType,
                                             pTweenTarget,
                                             targetType,
                                             dummyFromVec,
                                             pBy,
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
UTweenVector2DLatentFactory* UTweenVector2DLatentFactory::BP_AppendLatentTweenScaleWidgetTo(UTweenContainer* pTweenContainer,
                                                                                            UTweenVector2D*& OutTween,
                                                                                            UWidget* pTweenTarget,
                                                                                            FVector2D pTo,
                                                                                            float pDuration,
                                                                                            ETweenEaseType pEaseType,
                                                                                            int32 pNumLoops,
                                                                                            ETweenLoopType pLoopType,
                                                                                            float pDelay,
                                                                                            float pTimeScale,
                                                                                            bool pTweenWhileGameIsPaused)
{
    ETweenTargetType targetType  = ETweenTargetType::UMG;
    ETweenVector2DType tweenType = ETweenVector2DType::ScaleTo;
    FVector2D dummyFromVec       = FVector2D(0, 0);

    return CreateProxyForAppendTweenVector2D(pTweenContainer,
                                             tweenType,
                                             pTweenTarget,
                                             targetType,
                                             dummyFromVec,
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
UTweenVector2DLatentFactory* UTweenVector2DLatentFactory::BP_AppendLatentTweenScaleWidgetBy(UTweenContainer* pTweenContainer,
                                                                                            UTweenVector2D*& OutTween,
                                                                                            UWidget* pTweenTarget,
                                                                                            FVector2D pBy,
                                                                                            float pDuration,
                                                                                            ETweenEaseType pEaseType,
                                                                                            int32 pNumLoops,
                                                                                            ETweenLoopType pLoopType,
                                                                                            float pDelay,
                                                                                            float pTimeScale,
                                                                                            bool pTweenWhileGameIsPaused)
{
    ETweenTargetType targetType  = ETweenTargetType::UMG;
    ETweenVector2DType tweenType = ETweenVector2DType::ScaleBy;
    FVector2D dummyFromVec       = FVector2D(0, 0);

    return CreateProxyForAppendTweenVector2D(pTweenContainer,
                                             tweenType,
                                             pTweenTarget,
                                             targetType,
                                             dummyFromVec,
                                             pBy,
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
UTweenVector2DLatentFactory* UTweenVector2DLatentFactory::BP_AppendLatentTweenShearWidgetTo(UTweenContainer* pTweenContainer,
                                                                                            UTweenVector2D*& OutTween,
                                                                                            UWidget* pTweenTarget,
                                                                                            FVector2D pTo,
                                                                                            float pDuration,
                                                                                            ETweenEaseType pEaseType,
                                                                                            int32 pNumLoops,
                                                                                            ETweenLoopType pLoopType,
                                                                                            float pDelay,
                                                                                            float pTimeScale,
                                                                                            bool pTweenWhileGameIsPaused)
{
    ETweenTargetType targetType  = ETweenTargetType::UMG;
    ETweenVector2DType tweenType = ETweenVector2DType::ShearTo;
    FVector2D dummyFromVec       = FVector2D(0, 0);

    return CreateProxyForAppendTweenVector2D(pTweenContainer,
                                             tweenType,
                                             pTweenTarget,
                                             targetType,
                                             dummyFromVec,
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
UTweenVector2DLatentFactory* UTweenVector2DLatentFactory::BP_AppendLatentTweenCustomVector2D(UTweenContainer* pTweenContainer,
                                                                                             UTweenVector2D*& OutTween,
                                                                                             UObject* pTweenTarget,
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
    ETweenTargetType targetType  = ETweenTargetType::Custom;
    ETweenVector2DType tweenType = ETweenVector2DType::Custom;

    return CreateProxyForAppendTweenVector2D(pTweenContainer,
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
UTweenVector2DLatentFactory* UTweenVector2DLatentFactory::BP_JoinLatentTweenMoveWidgetTo(UTweenContainer* pTweenContainer,
                                                                                         UTweenVector2D*& OutTween,
                                                                                         UWidget* pTweenTarget,
                                                                                         FVector2D pTo,
                                                                                         float pDuration,
                                                                                         ETweenEaseType pEaseType,
                                                                                         float pDelay,
                                                                                         float pTimeScale,
                                                                                         bool pTweenWhileGameIsPaused)
{
    ETweenTargetType targetType  = ETweenTargetType::UMG;
    ETweenVector2DType tweenType = ETweenVector2DType::MoveTo;
    FVector2D dummyFromVec       = FVector2D(0, 0);

    return CreateProxyForJoinTweenVector2D(pTweenContainer,
                                           tweenType,
                                           pTweenTarget,
                                           targetType,
                                           dummyFromVec,
                                           pTo,
                                           pDuration,
                                           pEaseType,
                                           pDelay,
                                           pTimeScale,
                                           pTweenWhileGameIsPaused,
                                           OutTween);
}

// static public ---------------------------------------------------------------
UTweenVector2DLatentFactory* UTweenVector2DLatentFactory::BP_JoinLatentTweenMoveWidgetBy(UTweenContainer* pTweenContainer,
                                                                                         UTweenVector2D*& OutTween,
                                                                                         UWidget* pTweenTarget,
                                                                                         FVector2D pBy,
                                                                                         float pDuration,
                                                                                         ETweenEaseType pEaseType,
                                                                                         float pDelay,
                                                                                         float pTimeScale,
                                                                                         bool pTweenWhileGameIsPaused)
{
    ETweenTargetType targetType  = ETweenTargetType::UMG;
    ETweenVector2DType tweenType = ETweenVector2DType::MoveBy;
    FVector2D dummyFromVec       = FVector2D(0, 0);

    return CreateProxyForJoinTweenVector2D(pTweenContainer,
                                           tweenType,
                                           pTweenTarget,
                                           targetType,
                                           dummyFromVec,
                                           pBy,
                                           pDuration,
                                           pEaseType,
                                           pDelay,
                                           pTimeScale,
                                           pTweenWhileGameIsPaused,
                                           OutTween);
}

// static public ---------------------------------------------------------------
UTweenVector2DLatentFactory* UTweenVector2DLatentFactory::BP_JoinLatentTweenScaleWidgetTo(UTweenContainer* pTweenContainer,
                                                                                          UTweenVector2D*& OutTween,
                                                                                          UWidget* pTweenTarget,
                                                                                          FVector2D pTo,
                                                                                          float pDuration,
                                                                                          ETweenEaseType pEaseType,
                                                                                          float pDelay,
                                                                                          float pTimeScale,
                                                                                          bool pTweenWhileGameIsPaused)
{
    ETweenTargetType targetType  = ETweenTargetType::UMG;
    ETweenVector2DType tweenType = ETweenVector2DType::ScaleTo;
    FVector2D dummyFromVec       = FVector2D(0, 0);

    return CreateProxyForJoinTweenVector2D(pTweenContainer,
                                           tweenType,
                                           pTweenTarget,
                                           targetType,
                                           dummyFromVec,
                                           pTo,
                                           pDuration,
                                           pEaseType,
                                           pDelay,
                                           pTimeScale,
                                           pTweenWhileGameIsPaused,
                                           OutTween);
}

// static public ---------------------------------------------------------------
UTweenVector2DLatentFactory* UTweenVector2DLatentFactory::BP_JoinLatentTweenScaleWidgetBy(UTweenContainer* pTweenContainer,
                                                                                          UTweenVector2D*& OutTween,
                                                                                          UWidget* pTweenTarget,
                                                                                          FVector2D pBy,
                                                                                          float pDuration,
                                                                                          ETweenEaseType pEaseType,
                                                                                          float pDelay,
                                                                                          float pTimeScale,
                                                                                          bool pTweenWhileGameIsPaused)
{
    ETweenTargetType targetType  = ETweenTargetType::UMG;
    ETweenVector2DType tweenType = ETweenVector2DType::ScaleBy;
    FVector2D dummyFromVec       = FVector2D(0, 0);

    return CreateProxyForJoinTweenVector2D(pTweenContainer,
                                           tweenType,
                                           pTweenTarget,
                                           targetType,
                                           dummyFromVec,
                                           pBy,
                                           pDuration,
                                           pEaseType,
                                           pDelay,
                                           pTimeScale,
                                           pTweenWhileGameIsPaused,
                                           OutTween);
}

// static public ---------------------------------------------------------------
UTweenVector2DLatentFactory* UTweenVector2DLatentFactory::BP_JoinLatentTweenShearWidgetTo(UTweenContainer* pTweenContainer,
                                                                                          UTweenVector2D*& OutTween,
                                                                                          UWidget* pTweenTarget,
                                                                                          FVector2D pTo,
                                                                                          float pDuration,
                                                                                          ETweenEaseType pEaseType,
                                                                                          float pDelay,
                                                                                          float pTimeScale,
                                                                                          bool pTweenWhileGameIsPaused)
{
    ETweenTargetType targetType  = ETweenTargetType::UMG;
    ETweenVector2DType tweenType = ETweenVector2DType::ShearTo;
    FVector2D dummyFromVec       = FVector2D(0, 0);

    return CreateProxyForJoinTweenVector2D(pTweenContainer,
                                           tweenType,
                                           pTweenTarget,
                                           targetType,
                                           dummyFromVec,
                                           pTo,
                                           pDuration,
                                           pEaseType,
                                           pDelay,
                                           pTimeScale,
                                           pTweenWhileGameIsPaused,
                                           OutTween);
}

// static public ---------------------------------------------------------------
UTweenVector2DLatentFactory* UTweenVector2DLatentFactory::BP_JoinLatentTweenCustomVector2D(UTweenContainer* pTweenContainer,
                                                                                           UTweenVector2D*& OutTween,
                                                                                           UObject* pTweenTarget,
                                                                                           FVector2D pFrom,
                                                                                           FVector2D pTo,
                                                                                           float pDuration,
                                                                                           ETweenEaseType pEaseType,
                                                                                           float pDelay,
                                                                                           float pTimeScale,
                                                                                           bool pTweenWhileGameIsPaused)
{
    ETweenTargetType targetType  = ETweenTargetType::Custom;
    ETweenVector2DType tweenType = ETweenVector2DType::Custom;

    return CreateProxyForJoinTweenVector2D(pTweenContainer,
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
void UTweenVector2DLatentFactory::Activate()
{
    Super::Activate();
}


// static private --------------------------------------------------------------
UTweenVector2DLatentFactory* UTweenVector2DLatentFactory::CreateProxyForAppendTweenVector2D(UTweenContainer* pTweenContainer,
                                                                                            ETweenVector2DType pTweenType,
                                                                                            UObject* pTarget,
                                                                                            ETweenTargetType
                                                                                            pTargetType,
                                                                                            const FVector2D& pFrom,
                                                                                            const FVector2D& pTo,
                                                                                            float pDuration,
                                                                                            ETweenEaseType pEaseType,
                                                                                            int32 pNumLoops,
                                                                                            ETweenLoopType pLoopType,
                                                                                            float pDelay,
                                                                                            float pTimeScale,
                                                                                            bool pTweenWhileGameIsPaused,
                                                                                            UTweenVector2D*& OutTween)
{
    UTweenVector2DLatentFactory* proxy = NewObject<UTweenVector2DLatentFactory>();

    if (pTweenContainer != nullptr)
    {
        UTweenManagerComponent* instance = pTweenContainer->OwningTweenManager;

        if (instance != nullptr)
        {
            int32 tweenIndex = pTweenContainer->GetSequencesNum();

            OutTween = instance->AppendTweenVector2D(pTweenContainer,
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
                                                     proxy);
        }
    }
    else
    {
        UE_LOG(LogTweenMaker, Warning, TEXT("UTweenVector2DLatentFactory::CreateProxyForAppendTweenVector2D() -> the Tween that had as target the "
                                            "object with name %s couldn't be added because the passed TweenContainer was null."), *pTarget->GetName());
    }

    return proxy;
}

// static private --------------------------------------------------------------
UTweenVector2DLatentFactory* UTweenVector2DLatentFactory::CreateProxyForJoinTweenVector2D(UTweenContainer* pTweenContainer,
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
                                                                                          UTweenVector2D*& OutTween)
{
    UTweenVector2DLatentFactory* proxy = NewObject<UTweenVector2DLatentFactory>();

    if (pTweenContainer != nullptr)
    {
        UTweenManagerComponent* instance = pTweenContainer->OwningTweenManager;

        if (instance != nullptr)
        {
            int32 tweenIndex = pTweenContainer->GetSequencesNum() - 1;

            OutTween = instance->JoinTweenVector2D(pTweenContainer,
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
                                                   proxy);
        }
    }
    else
    {
        UE_LOG(LogTweenMaker, Warning, TEXT("UTweenVector2DLatentFactory::CreateProxyForJoinTweenVector2D() -> the Tween that had as target the "
                                            "object with name %s couldn't be added because the passed TweenContainer was null."), *pTarget->GetName());
    }

    return proxy;
}
