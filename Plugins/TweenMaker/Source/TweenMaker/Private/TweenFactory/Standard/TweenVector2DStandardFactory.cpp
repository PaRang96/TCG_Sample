// Copyright 2018 Francesco Desogus. All Rights Reserved.

#include "TweenFactory/Standard/TweenVector2DStandardFactory.h"

#include "TweenManagerActor.h"
#include "Components/Widget.h"
#include "Tweens/TweenVector2D.h"
#include "TweenContainer.h"

// public ----------------------------------------------------------------------
UTweenVector2DStandardFactory::UTweenVector2DStandardFactory(const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer)
{

}

// static public ---------------------------------------------------------------
void UTweenVector2DStandardFactory::BP_CreateTweenMoveWidgetTo(UTweenManagerComponent* pTweenManagerComponent,
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
                                                               bool pTweenWhileGameIsPaused,
                                                               int32 pSequenceIndex)
{
    pOutTweenContainer = pTweenManagerComponent != nullptr ? pTweenManagerComponent->CreateTweenContainer()
                                                           : UTweenManagerComponent::CreateTweenContainerStatic();
    
    pOutTween = BP_AppendTweenMoveWidgetTo(pOutTweenContainer,
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
void UTweenVector2DStandardFactory::BP_CreateTweenMoveWidgetBy(UTweenManagerComponent* pTweenManagerComponent,
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
                                                               bool pTweenWhileGameIsPaused,
                                                               int32 pSequenceIndex)
{
    pOutTweenContainer = pTweenManagerComponent != nullptr ? pTweenManagerComponent->CreateTweenContainer()
                                                           : UTweenManagerComponent::CreateTweenContainerStatic();
    
    pOutTween = BP_AppendTweenMoveWidgetBy(pOutTweenContainer,
                                           pTweenTarget,
                                           pBy,
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
void UTweenVector2DStandardFactory::BP_CreateTweenScaleWidgetTo(UTweenManagerComponent* pTweenManagerComponent,
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
                                                                bool pTweenWhileGameIsPaused,
                                                                int32 pSequenceIndex)
{
    pOutTweenContainer = pTweenManagerComponent != nullptr ? pTweenManagerComponent->CreateTweenContainer()
                                                           : UTweenManagerComponent::CreateTweenContainerStatic();
    
    pOutTween = BP_AppendTweenScaleWidgetTo(pOutTweenContainer,
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
void UTweenVector2DStandardFactory::BP_CreateTweenScaleWidgetBy(UTweenManagerComponent* pTweenManagerComponent,
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
                                                                bool pTweenWhileGameIsPaused,
                                                                int32 pSequenceIndex)
{
    pOutTweenContainer = pTweenManagerComponent != nullptr ? pTweenManagerComponent->CreateTweenContainer()
                                                           : UTweenManagerComponent::CreateTweenContainerStatic();
    
    pOutTween = BP_AppendTweenScaleWidgetBy(pOutTweenContainer,
                                            pTweenTarget,
                                            pBy,
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
void UTweenVector2DStandardFactory::BP_CreateTweenShearWidgetTo(UTweenManagerComponent* pTweenManagerComponent,
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
                                                                bool pTweenWhileGameIsPaused,
                                                                int32 pSequenceIndex)
{
    pOutTweenContainer = pTweenManagerComponent != nullptr ? pTweenManagerComponent->CreateTweenContainer()
                                                           : UTweenManagerComponent::CreateTweenContainerStatic();
    
    pOutTween = BP_AppendTweenShearWidgetTo(pOutTweenContainer,
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
void UTweenVector2DStandardFactory::BP_CreateTweenCustomVector2D(UTweenManagerComponent* pTweenManagerComponent,
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
                                                                 bool pTweenWhileGameIsPaused,
                                                                 int32 pSequenceIndex)
{
    pOutTweenContainer = pTweenManagerComponent != nullptr ? pTweenManagerComponent->CreateTweenContainer()
                                                           : UTweenManagerComponent::CreateTweenContainerStatic();
    
    pOutTween = BP_AppendTweenCustomVector2D(pOutTweenContainer,
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
UTweenVector2D* UTweenVector2DStandardFactory::BP_AppendTweenMoveWidgetTo(UTweenContainer* pTweenContainer,
                                                                          UWidget* pTweenTarget,
                                                                          FVector2D pTo,
                                                                          float pDuration,
                                                                          ETweenEaseType pEaseType,
                                                                          int32 pNumLoops,
                                                                          ETweenLoopType pLoopType,
                                                                          float pDelay,
                                                                          float pTimeScale,
                                                                          bool pTweenWhileGameIsPaused,
                                                                          int32 pSequenceIndex)
{
    ETweenTargetType targetType  = ETweenTargetType::UMG;
    ETweenVector2DType tweenType = ETweenVector2DType::MoveTo;
    FVector2D dummyFromVec       = FVector2D(0, 0);

    return CreateAppendTweenVector2D(pTweenContainer,
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
                                     pSequenceIndex);
}

// static public ---------------------------------------------------------------
UTweenVector2D* UTweenVector2DStandardFactory::BP_AppendTweenMoveWidgetBy(UTweenContainer* pTweenContainer,
                                                                          UWidget* pTweenTarget,
                                                                          FVector2D pBy,
                                                                          float pDuration,
                                                                          ETweenEaseType pEaseType,
                                                                          int32 pNumLoops,
                                                                          ETweenLoopType pLoopType,
                                                                          float pDelay,
                                                                          float pTimeScale,
                                                                          bool pTweenWhileGameIsPaused,
                                                                          int32 pSequenceIndex)
{
    ETweenTargetType targetType  = ETweenTargetType::UMG;
    ETweenVector2DType tweenType = ETweenVector2DType::MoveBy;
    FVector2D dummyFromVec       = FVector2D(0, 0);

    return CreateAppendTweenVector2D(pTweenContainer,
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
                                     pSequenceIndex);
}

// static public ---------------------------------------------------------------
UTweenVector2D* UTweenVector2DStandardFactory::BP_AppendTweenScaleWidgetTo(UTweenContainer* pTweenContainer,
                                                                           UWidget* pTweenTarget,
                                                                           FVector2D pTo,
                                                                           float pDuration,
                                                                           ETweenEaseType pEaseType,
                                                                           int32 pNumLoops,
                                                                           ETweenLoopType pLoopType,
                                                                           float pDelay,
                                                                           float pTimeScale,
                                                                           bool pTweenWhileGameIsPaused,
                                                                           int32 pSequenceIndex)
{
    ETweenTargetType targetType  = ETweenTargetType::UMG;
    ETweenVector2DType tweenType = ETweenVector2DType::ScaleTo;
    FVector2D dummyFromVec       = FVector2D(0, 0);

    return CreateAppendTweenVector2D(pTweenContainer,
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
                                     pSequenceIndex);
}

// static public ---------------------------------------------------------------
UTweenVector2D* UTweenVector2DStandardFactory::BP_AppendTweenScaleWidgetBy(UTweenContainer* pTweenContainer,
                                                                           UWidget* pTweenTarget,
                                                                           FVector2D pBy,
                                                                           float pDuration,
                                                                           ETweenEaseType pEaseType,
                                                                           int32 pNumLoops,
                                                                           ETweenLoopType pLoopType,
                                                                           float pDelay,
                                                                           float pTimeScale,
                                                                           bool pTweenWhileGameIsPaused,
                                                                           int32 pSequenceIndex)
{
    ETweenTargetType targetType  = ETweenTargetType::UMG;
    ETweenVector2DType tweenType = ETweenVector2DType::ScaleBy;
    FVector2D dummyFromVec       = FVector2D(0, 0);

    return CreateAppendTweenVector2D(pTweenContainer,
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
                                     pSequenceIndex);
}

// static public ---------------------------------------------------------------
UTweenVector2D* UTweenVector2DStandardFactory::BP_AppendTweenShearWidgetTo(UTweenContainer* pTweenContainer,
                                                                           UWidget* pTweenTarget,
                                                                           FVector2D pTo,
                                                                           float pDuration,
                                                                           ETweenEaseType pEaseType,
                                                                           int32 pNumLoops,
                                                                           ETweenLoopType pLoopType,
                                                                           float pDelay,
                                                                           float pTimeScale,
                                                                           bool pTweenWhileGameIsPaused,
                                                                           int32 pSequenceIndex)
{
    ETweenTargetType targetType  = ETweenTargetType::UMG;
    ETweenVector2DType tweenType = ETweenVector2DType::ShearTo;
    FVector2D dummyFromVec       = FVector2D(0, 0);

    return CreateAppendTweenVector2D(pTweenContainer,
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
                                     pSequenceIndex);
}

// static public ---------------------------------------------------------------
UTweenVector2D* UTweenVector2DStandardFactory::BP_AppendTweenCustomVector2D(UTweenContainer* pTweenContainer,
                                                                            UObject* pTweenTarget,
                                                                            FVector2D pFrom,
                                                                            FVector2D pTo,
                                                                            float pDuration,
                                                                            ETweenEaseType pEaseType,
                                                                            int32 pNumLoops,
                                                                            ETweenLoopType pLoopType,
                                                                            float pDelay,
                                                                            float pTimeScale,
                                                                            bool pTweenWhileGameIsPaused,
                                                                            int32 pSequenceIndex)
{
    ETweenTargetType targetType  = ETweenTargetType::Custom;
    ETweenVector2DType tweenType = ETweenVector2DType::Custom;

    return CreateAppendTweenVector2D(pTweenContainer,
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
UTweenVector2D* UTweenVector2DStandardFactory::BP_JoinTweenMoveWidgetTo(UTweenContainer* pTweenContainer,
                                                                        UWidget* pTweenTarget,
                                                                        FVector2D pTo,
                                                                        float pDuration,
                                                                        ETweenEaseType pEaseType,
                                                                        float pDelay,
                                                                        float pTimeScale,
                                                                        bool pTweenWhileGameIsPaused,
                                                                        int32 pSequenceIndex)
{
    ETweenTargetType targetType  = ETweenTargetType::UMG;
    ETweenVector2DType tweenType = ETweenVector2DType::MoveTo;
    FVector2D dummyFromVec       = FVector2D(0, 0);

    return CreateJoinTweenVector2D(pTweenContainer,
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
                                   pSequenceIndex);
}

// static public ---------------------------------------------------------------
UTweenVector2D* UTweenVector2DStandardFactory::BP_JoinTweenMoveWidgetBy(UTweenContainer* pTweenContainer,
                                                                        UWidget* pTweenTarget,
                                                                        FVector2D pBy,
                                                                        float pDuration,
                                                                        ETweenEaseType pEaseType,
                                                                        float pDelay,
                                                                        float pTimeScale,
                                                                        bool pTweenWhileGameIsPaused,
                                                                        int32 pSequenceIndex)
{
    ETweenTargetType targetType  = ETweenTargetType::UMG;
    ETweenVector2DType tweenType = ETweenVector2DType::MoveBy;
    FVector2D dummyFromVec       = FVector2D(0, 0);

    return CreateJoinTweenVector2D(pTweenContainer,
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
                                   pSequenceIndex);
}

// static public ---------------------------------------------------------------
UTweenVector2D* UTweenVector2DStandardFactory::BP_JoinTweenScaleWidgetTo(UTweenContainer* pTweenContainer,
                                                                         UWidget* pTweenTarget,
                                                                         FVector2D pTo,
                                                                         float pDuration,
                                                                         ETweenEaseType pEaseType,
                                                                         float pDelay,
                                                                         float pTimeScale,
                                                                         bool pTweenWhileGameIsPaused,
                                                                         int32 pSequenceIndex)
{
    ETweenTargetType targetType  = ETweenTargetType::UMG;
    ETweenVector2DType tweenType = ETweenVector2DType::ScaleTo;
    FVector2D dummyFromVec       = FVector2D(0, 0);

    return CreateJoinTweenVector2D(pTweenContainer,
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
                                   pSequenceIndex);
}

// static public ---------------------------------------------------------------
UTweenVector2D* UTweenVector2DStandardFactory::BP_JoinTweenScaleWidgetBy(UTweenContainer* pTweenContainer,
                                                                         UWidget* pTweenTarget,
                                                                         FVector2D pBy,
                                                                         float pDuration,
                                                                         ETweenEaseType pEaseType,
                                                                         float pDelay,
                                                                         float pTimeScale,
                                                                         bool pTweenWhileGameIsPaused,
                                                                         int32 pSequenceIndex)
{
    ETweenTargetType targetType  = ETweenTargetType::UMG;
    ETweenVector2DType tweenType = ETweenVector2DType::ScaleBy;
    FVector2D dummyFromVec       = FVector2D(0, 0);

    return CreateJoinTweenVector2D(pTweenContainer,
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
                                   pSequenceIndex);
}

// static public ---------------------------------------------------------------
UTweenVector2D* UTweenVector2DStandardFactory::BP_JoinTweenShearWidgetTo(UTweenContainer* pTweenContainer,
                                                                         UWidget* pTweenTarget,
                                                                         FVector2D pTo,
                                                                         float pDuration,
                                                                         ETweenEaseType pEaseType,
                                                                         float pDelay,
                                                                         float pTimeScale,
                                                                         bool pTweenWhileGameIsPaused,
                                                                         int32 pSequenceIndex)
{
    ETweenTargetType targetType  = ETweenTargetType::UMG;
    ETweenVector2DType tweenType = ETweenVector2DType::ShearTo;
    FVector2D dummyFromVec       = FVector2D(0, 0);

    return CreateJoinTweenVector2D(pTweenContainer,
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
                                   pSequenceIndex);
}

// static public ---------------------------------------------------------------
UTweenVector2D* UTweenVector2DStandardFactory::BP_JoinTweenCustomVector2D(UTweenContainer* pTweenContainer,
                                                                          UObject* pTweenTarget,
                                                                          FVector2D pFrom,
                                                                          FVector2D pTo,
                                                                          float pDuration,
                                                                          ETweenEaseType pEaseType,
                                                                          float pDelay,
                                                                          float pTimeScale,
                                                                          bool pTweenWhileGameIsPaused,
                                                                          int32 pSequenceIndex)
{
    ETweenTargetType targetType  = ETweenTargetType::Custom;
    ETweenVector2DType tweenType = ETweenVector2DType::Custom;

    return CreateJoinTweenVector2D(pTweenContainer,
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
UTweenVector2D* UTweenVector2DStandardFactory::CreateAppendTweenVector2D(UTweenContainer* pTweenContainer,
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
                                                                         int32 pSequenceIndex)
{
    UTweenVector2D* outTween = nullptr;

    if (pTweenContainer != nullptr)
    {
        UTweenManagerComponent* tweenManagerInstance = pTweenContainer->OwningTweenManager;

        if (tweenManagerInstance != nullptr)
        {
            int32 tweenIndex = pSequenceIndex > -1 ? pSequenceIndex : pTweenContainer->GetSequencesNum();
            
            outTween = tweenManagerInstance->AppendTweenVector2D(pTweenContainer,
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
                                                                 pTweenWhileGameIsPaused);
        }
    }
    else
    {
        UE_LOG(LogTweenMaker, Warning, TEXT("UTweenVector2DStandardFactory::CreateAppendTweenVector2D() -> the Tween that had as target the "
                                            "object with name %s couldn't be added because the passed TweenContainer was null."), *pTarget->GetName());
    }

    return outTween;
}

// static private --------------------------------------------------------------
UTweenVector2D* UTweenVector2DStandardFactory::CreateJoinTweenVector2D(UTweenContainer* pTweenContainer,
                                                                       ETweenVector2DType pTweenType,
                                                                       UObject* pTweenTarget,
                                                                       ETweenTargetType pTargetType,
                                                                       const FVector2D& pFrom,
                                                                       const FVector2D& pTo,
                                                                       float pDuration,
                                                                       ETweenEaseType pEaseType,
                                                                       float pDelay,
                                                                       float pTimeScale,
                                                                       bool pTweenWhileGameIsPaused,
                                                                       int32 pSequenceIndex)
{
    UTweenVector2D* outTween = nullptr;

    if (pTweenContainer != nullptr)
    {
        UTweenManagerComponent* tweenManagerInstance = pTweenContainer->OwningTweenManager;

        if (tweenManagerInstance != nullptr)
        {
            int32 tweenIndex = pSequenceIndex > -1 ? pSequenceIndex : pTweenContainer->GetSequencesNum() - 1;
            
            outTween = tweenManagerInstance->JoinTweenVector2D(pTweenContainer,
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
                                                               pTweenWhileGameIsPaused);
        }
    }
    else
    {
        UE_LOG(LogTweenMaker, Warning, TEXT("UTweenVector2DStandardFactory::CreateJoinTweenVector2D() -> the Tween that had as target the "
                                            "object with name %s couldn't be added because the passed TweenContainer was null."), *pTweenTarget->GetName());
    }

    return outTween;
}
