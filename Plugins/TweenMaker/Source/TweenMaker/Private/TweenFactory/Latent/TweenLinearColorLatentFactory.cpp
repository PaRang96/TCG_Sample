// Copyright 2018 Francesco Desogus. All Rights Reserved.

#include "TweenFactory/Latent/TweenLinearColorLatentFactory.h"

#include "Tweens/TweenRotator.h"
#include "TweenContainer.h"
#include "Materials/MaterialInstanceDynamic.h"

// public ----------------------------------------------------------------------
UTweenLinearColorLatentFactory::UTweenLinearColorLatentFactory(const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer)
{

}

// static public ---------------------------------------------------------------
UTweenLinearColorLatentFactory* UTweenLinearColorLatentFactory::BP_CreateLatentTweenMaterialVectorFromTo(UTweenManagerComponent* pTweenManagerComponent,
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
                                                                                                         bool pTweenWhileGameIsPaused)
{
    pOutTweenContainer = pTweenManagerComponent != nullptr ? pTweenManagerComponent->CreateTweenContainer() 
                                                           : UTweenManagerComponent::CreateTweenContainerStatic();

    return BP_AppendLatentTweenMaterialVectorFromTo(pOutTweenContainer,
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
UTweenLinearColorLatentFactory* UTweenLinearColorLatentFactory::BP_CreateLatentTweenMaterialVectorTo(UTweenManagerComponent* pTweenManagerComponent,
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
                                                                                                     bool pTweenWhileGameIsPaused)
{
    pOutTweenContainer = pTweenManagerComponent != nullptr ? pTweenManagerComponent->CreateTweenContainer() 
                                                           : UTweenManagerComponent::CreateTweenContainerStatic();

    return BP_AppendLatentTweenMaterialVectorTo(pOutTweenContainer,
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
UTweenLinearColorLatentFactory* UTweenLinearColorLatentFactory::BP_AppendLatentTweenMaterialVectorFromTo(UTweenContainer* pTweenContainer,
                                                                                                         UTweenLinearColor*& OutTween,
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
                                                                                                         bool pTweenWhileGameIsPaused)
{
    ETweenTargetType targetType     = ETweenTargetType::Material;
    ETweenLinearColorType tweenType = ETweenLinearColorType::MaterialVectorFromTo;

    return CreateProxyForAppendTweenMaterialVector(pTweenContainer,
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
                                                   OutTween);
}

// static public ---------------------------------------------------------------
UTweenLinearColorLatentFactory* UTweenLinearColorLatentFactory::BP_AppendLatentTweenMaterialVectorTo(UTweenContainer* pTweenContainer,
                                                                                                     UTweenLinearColor*& OutTween,
                                                                                                     UMaterialInstanceDynamic* pTweenTarget,
                                                                                                     FName pParameterName,
                                                                                                     FLinearColor pTo,
                                                                                                     float pDuration,
                                                                                                     ETweenEaseType pEaseType,
                                                                                                     int32 pNumLoops,
                                                                                                     ETweenLoopType pLoopType,
                                                                                                     float pDelay,
                                                                                                     float pTimeScale,
                                                                                                     bool pTweenWhileGameIsPaused)
{
    ETweenTargetType targetType     = ETweenTargetType::Material;
    ETweenLinearColorType tweenType = ETweenLinearColorType::MaterialVectorTo;
    FLinearColor dummyFromColor     = FLinearColor();

    return CreateProxyForAppendTweenMaterialVector(pTweenContainer,
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
                                                   OutTween);
}

// static public ---------------------------------------------------------------
UTweenLinearColorLatentFactory* UTweenLinearColorLatentFactory::BP_JoinLatentTweenMaterialVectorFromTo(UTweenContainer* pTweenContainer,
                                                                                                       UTweenLinearColor*& OutTween,
                                                                                                       UMaterialInstanceDynamic* pTweenTarget,
                                                                                                       FName pParameterName,
                                                                                                       FLinearColor pFrom,
                                                                                                       FLinearColor pTo,
                                                                                                       float pDuration,
                                                                                                       ETweenEaseType pEaseType,
                                                                                                       float pDelay,
                                                                                                       float pTimeScale,
                                                                                                       bool pTweenWhileGameIsPaused)
{
    ETweenTargetType targetType     = ETweenTargetType::Material;
    ETweenLinearColorType tweenType = ETweenLinearColorType::MaterialVectorFromTo;

    return CreateProxyForJoinTweenMaterialVector(pTweenContainer,
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
                                                 OutTween);
}

// static public ---------------------------------------------------------------
UTweenLinearColorLatentFactory* UTweenLinearColorLatentFactory::BP_JoinLatentTweenMaterialVectorTo(UTweenContainer* pTweenContainer,
                                                                                                   UTweenLinearColor*& OutTween,
                                                                                                   UMaterialInstanceDynamic* pTweenTarget,
                                                                                                   FName pParameterName,
                                                                                                   FLinearColor pTo,
                                                                                                   float pDuration,
                                                                                                   ETweenEaseType pEaseType,
                                                                                                   float pDelay,
                                                                                                   float pTimeScale,
                                                                                                   bool pTweenWhileGameIsPaused)
{
    ETweenTargetType targetType     = ETweenTargetType::Material;
    ETweenLinearColorType tweenType = ETweenLinearColorType::MaterialVectorTo;
    FLinearColor dummyFromColor     = FLinearColor();

    return CreateProxyForJoinTweenMaterialVector(pTweenContainer,
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
                                                 OutTween);
}

// public ----------------------------------------------------------------------
void UTweenLinearColorLatentFactory::Activate()
{
    Super::Activate();
}

// static private --------------------------------------------------------------
UTweenLinearColorLatentFactory* UTweenLinearColorLatentFactory::CreateProxyForAppendTweenMaterialVector(UTweenContainer* pTweenContainer,
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
                                                                                                        UTweenLinearColor*& OutTween)
{
    UTweenLinearColorLatentFactory* proxy = NewObject<UTweenLinearColorLatentFactory>();

    if (pTweenContainer != nullptr)
    {
        UTweenManagerComponent* instance = pTweenContainer->OwningTweenManager;

        if (instance != nullptr)
        {
            int32 tweenIndex = pTweenContainer->GetSequencesNum();
            
            OutTween = instance->AppendTweenLinearColor(pTweenContainer,
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
                                                        pTweenWhileGameIsPaused,
                                                        proxy);
        }
    }
    else
    {
        UE_LOG(LogTweenMaker, Warning, TEXT("UTweenLinearColorLatentFactory::CreateProxyForAppendTweenMaterialVector() -> the Tween that had as target the "
                                            "object with name %s couldn't be added because the passed TweenContainer was null."), *pTarget->GetName());
    }


    return proxy;
}

// static private --------------------------------------------------------------
UTweenLinearColorLatentFactory* UTweenLinearColorLatentFactory::CreateProxyForJoinTweenMaterialVector(UTweenContainer* pTweenContainer,
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
                                                                                                      UTweenLinearColor*& OutTween)
{
    UTweenLinearColorLatentFactory* proxy = NewObject<UTweenLinearColorLatentFactory>();

    if (pTweenContainer != nullptr)
    {
        UTweenManagerComponent* instance = pTweenContainer->OwningTweenManager;

        if (instance != nullptr)
        {
            int32 tweenIndex = pTweenContainer->GetSequencesNum() - 1;

            OutTween = instance->JoinTweenLinearColor(pTweenContainer,
                                                      tweenIndex,
                                                      pTweenType,
                                                      pTarget,
                                                      pParameterName,
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
        UE_LOG(LogTweenMaker, Warning, TEXT("UTweenLinearColorLatentFactory::CreateProxyForJoinTweenMaterialVector() -> the Tween that had as target the "
                                            "object with name %s couldn't be added because the passed TweenContainer was null."), *pTarget->GetName());
    }


    return proxy;
}

