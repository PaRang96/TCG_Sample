// Copyright 2018 Francesco Desogus. All Rights Reserved.

#include "TweenFactory/Standard/TweenLinearColorStandardFactory.h"

#include "Tweens/TweenRotator.h"
#include "TweenContainer.h"
#include "Materials/MaterialInstanceDynamic.h"

// public ----------------------------------------------------------------------
UTweenLinearColorStandardFactory::UTweenLinearColorStandardFactory(const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer)
{

}

// static public ---------------------------------------------------------------
void UTweenLinearColorStandardFactory::BP_CreateTweenMaterialVectorFromTo(UTweenManagerComponent* pTweenManagerComponent,
                                                                          UMaterialInstanceDynamic* pTweenTarget,
                                                                          UTweenContainer*& pOutTweenContainer,
                                                                          UTweenLinearColor*& pOutTween,
                                                                          FName pParameterName,
                                                                          FLinearColor pFrom,
                                                                          FLinearColor pTo,
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
    pOutTween = BP_AppendTweenMaterialVectorFromTo(pOutTweenContainer,
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
void UTweenLinearColorStandardFactory::BP_CreateTweenMaterialVectorTo(UTweenManagerComponent* pTweenManagerComponent,
                                                                      UMaterialInstanceDynamic* pTweenTarget,
                                                                      UTweenContainer*& pOutTweenContainer,
                                                                      UTweenLinearColor*& pOutTween,
                                                                      FName pParameterName,
                                                                      FLinearColor pTo,
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
    pOutTween = BP_AppendTweenMaterialVectorTo(pOutTweenContainer,
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
UTweenLinearColor* UTweenLinearColorStandardFactory::BP_AppendTweenMaterialVectorFromTo(UTweenContainer* pTweenContainer,
                                                                                        UMaterialInstanceDynamic* pTweenTarget,
                                                                                        FName pParameterName,
                                                                                        FLinearColor pFrom,
                                                                                        FLinearColor pTo,
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
    ETweenLinearColorType tweenType = ETweenLinearColorType::MaterialVectorFromTo;

    return CreateAppendTweenMaterialVector(pTweenContainer,
                                           tweenType,
                                           pTweenTarget,
                                           pParameterName,
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
UTweenLinearColor* UTweenLinearColorStandardFactory::BP_AppendTweenMaterialVectorTo(UTweenContainer* pTweenContainer,
                                                                                    UMaterialInstanceDynamic* pTweenTarget,
                                                                                    FName pParameterName,
                                                                                    FLinearColor pTo,
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
    ETweenLinearColorType tweenType = ETweenLinearColorType::MaterialVectorTo;
    FLinearColor dummyFromColor = FLinearColor();

    return CreateAppendTweenMaterialVector(pTweenContainer,
                                           tweenType,
                                           pTweenTarget,
                                           pParameterName,
                                           targetType,
                                           dummyFromColor,
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
UTweenLinearColor* UTweenLinearColorStandardFactory::BP_JoinTweenMaterialVectorFromTo(UTweenContainer* pTweenContainer,
                                                                                      UMaterialInstanceDynamic* pTweenTarget,
                                                                                      FName pParameterName,
                                                                                      FLinearColor pFrom,
                                                                                      FLinearColor pTo,
                                                                                      float pDuration,
                                                                                      ETweenEaseType pEaseType,
                                                                                      float pDelay,
                                                                                      float pTimeScale,
                                                                                      bool pTweenWhileGameIsPaused,
                                                                                      int32 pSequenceIndex)
{
    ETweenTargetType targetType = ETweenTargetType::Material;
    ETweenLinearColorType tweenType = ETweenLinearColorType::MaterialVectorFromTo;

    return CreateJoinTweenMaterialVector(pTweenContainer,
                                         tweenType,
                                         pTweenTarget,
                                         pParameterName,
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

// static public ---------------------------------------------------------------
UTweenLinearColor* UTweenLinearColorStandardFactory::BP_JoinTweenMaterialVectorTo(UTweenContainer* pTweenContainer,
                                                                                  UMaterialInstanceDynamic* pTweenTarget,
                                                                                  FName pParameterName,
                                                                                  FLinearColor pTo,
                                                                                  float pDuration,
                                                                                  ETweenEaseType pEaseType,
                                                                                  float pDelay,
                                                                                  float pTimeScale,
                                                                                  bool pTweenWhileGameIsPaused,
                                                                                  int32 pSequenceIndex)
{
    ETweenTargetType targetType = ETweenTargetType::Material;
    ETweenLinearColorType tweenType = ETweenLinearColorType::MaterialVectorTo;
    FLinearColor dummyFromColor = FLinearColor();

    return CreateJoinTweenMaterialVector(pTweenContainer,
                                         tweenType,
                                         pTweenTarget,
                                         pParameterName,
                                         targetType,
                                         dummyFromColor,
                                         pTo,
                                         pDuration,
                                         pEaseType,
                                         pDelay,
                                         pTimeScale,
                                         pTweenWhileGameIsPaused,
                                         pSequenceIndex);
}

// static private --------------------------------------------------------------
UTweenLinearColor* UTweenLinearColorStandardFactory::CreateAppendTweenMaterialVector(UTweenContainer* pTweenContainer,
                                                                                     ETweenLinearColorType pTweenType,
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
                                                                                     int32 pSequenceIndex)
{
    UTweenLinearColor *outTween = nullptr;

    if (pTweenContainer != nullptr)
    {
        UTweenManagerComponent *tweenManagerInstance = pTweenContainer->OwningTweenManager;

        if (tweenManagerInstance != nullptr)
        {
            int32 tweenIndex = pSequenceIndex > -1 ? pSequenceIndex : pTweenContainer->GetSequencesNum();

            outTween = tweenManagerInstance->AppendTweenLinearColor(pTweenContainer,
                                                                    tweenIndex,
                                                                    pTweenType,
                                                                    pTarget,
                                                                    pParameterName,
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
        UE_LOG(LogTweenMaker, Warning, TEXT("UTweenLinearColorStandardFactory::CreateAppendTweenMaterialVector() -> the Tween that had as target the "
                                            "object with name %s couldn't be added because the passed TweenContainer was null."), *pTarget->GetName());
    }

    return outTween;
}

// static private --------------------------------------------------------------
UTweenLinearColor* UTweenLinearColorStandardFactory::CreateJoinTweenMaterialVector(UTweenContainer* pTweenContainer,
                                                                                   ETweenLinearColorType pTweenType,
                                                                                   UObject* pTweenTarget,
                                                                                   FName pParameterName,
                                                                                   ETweenTargetType pTargetType,
                                                                                   const FLinearColor& pFrom,
                                                                                   const FLinearColor& pTo,
                                                                                   float pDuration,
                                                                                   ETweenEaseType pEaseType,
                                                                                   float pDelay,
                                                                                   float pTimeScale,
                                                                                   bool pTweenWhileGameIsPaused,
                                                                                   int32 pSequenceIndex)
{
    UTweenLinearColor *outTween = nullptr;

    if (pTweenContainer != nullptr)
    {
        UTweenManagerComponent *tweenManagerInstance = pTweenContainer->OwningTweenManager;

        if (tweenManagerInstance != nullptr)
        {
            int32 tweenIndex = pSequenceIndex > -1 ? pSequenceIndex : pTweenContainer->GetSequencesNum() - 1;

            outTween = tweenManagerInstance->JoinTweenLinearColor(pTweenContainer,
                                                                  tweenIndex,
                                                                  pTweenType,
                                                                  pTweenTarget,
                                                                  pParameterName,
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
        UE_LOG(LogTweenMaker, Warning, TEXT("UTweenLinearColorStandardFactory::CreateJoinTweenMaterialVector() -> the Tween that had as target the "
                                            "object with name %s couldn't be added because the passed TweenContainer was null."), *pTweenTarget->GetName());
    }

    return outTween;
}
