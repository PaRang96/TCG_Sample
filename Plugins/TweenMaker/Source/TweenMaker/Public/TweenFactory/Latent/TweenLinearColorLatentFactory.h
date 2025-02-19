// Copyright 2018 Francesco Desogus. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"

#include "Kismet/BlueprintAsyncActionBase.h"
#include "TweenManagerComponent.h"
#include "Utils/TweenEnums.h"

#include "TweenLinearColorLatentFactory.generated.h"

class ATweenManagerActor;
class UTweenManagerComponent;
class UTweenContainer;
class UBaseTween;
class UTweenLinearColor;
class UMaterialInstanceDynamic;


/**
 * @brief The UTweenVectorLatentFactory class handles the creation of all LinearColor related Tweens, i.e. all tweens that
 *        in order to be executed they need to change a single LinearColor value.
 *
 *        The class inherits from UBlueprintAsyncActionBase in order to be able to create "Latent" functions for Blueprint,
 *        which allow the user to easily deal with the Tween callbacks.
 */
UCLASS()
class TWEENMAKER_API UTweenLinearColorLatentFactory : public UBlueprintAsyncActionBase
{
    GENERATED_BODY()

public:

    /**
     * @brief Constructor.
     */
    UTweenLinearColorLatentFactory(const FObjectInitializer& ObjectInitializer);

    /// @brief Called by a Latent proxy when the Tween starts the execution.
    UPROPERTY(BlueprintAssignable)
    FBP_OnTweenLinearColorChange OnTweenStart;

    /// @brief Called by a Latent proxy at each Tween's update during the the execution.
    UPROPERTY(BlueprintAssignable)
    FBP_OnTweenLinearColorChange OnTweenUpdate;

    /// @brief Called by a Latent proxy when the Tween ends the execution.
    UPROPERTY(BlueprintAssignable)
    FBP_OnTweenLinearColorChange OnTweenEnd;

    /*
     **************************************************************************
     * "Create" methods
     **************************************************************************
     */

    /**
      * Creates a Latent Tween that modifies a "Vector" material parameter from the starting value to the ending value.
      * With this function a new TweenContainer will be created, which will hold any other Tween appended/joined to this one.
      *
      * @param TweenManager (optional) The TweenManager that will handle the Tween. If none is passed, the global TweenManagerActor will be used if present.
      * @param TweenTarget The target material.
      * @param OutTweenContainer (optional, output) If this pin is connected with a variable, it will contain the TweenContainer that owns the Tween.
      * @param OutTween (optional, output) If this pin is connected with a variable, it will contain the Tween that was just created.
      * @param ParameterName The name of the material's parameter to tween.
      * @param From	The starting value.
      * @param To The ending value.
      * @param Duration The total duration of the Tween (in seconds).
      * @param EaseType	The easing functions to apply.
      * @param NumLoops	The number of times the Tween should repeat. If <= 0, it will loop indefinitely.
      * @param LoopType	The type of loop to apply (if "yoyo", it will go backwards when it reached the end; otherwise it will reset).
      * @param Delay The initial delay to apply to the Tween (in seconds).
      * @param TimeScale The scale to apply to the Tween execution. If < 1 the Tween will slow down, if > 1 it will speed up. If < 0 it will make the Tween go backward.
	  * @param TweenWhileGameIsPaused Sets whether the Tween should keep updating while the game is paused. Useful for Tween on UMG widgets that animate menus.
	  */
    UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly="true", DisplayName="Create Latent Tween Material Vector From To", KeyWords="Tween Material Vector From To Latent Create", AdvancedDisplay=8, AutoCreateRefTerm="OutTweenContainer, OutTween"), Category = "Tween|LatentTween|Material")
    static UTweenLinearColorLatentFactory* BP_CreateLatentTweenMaterialVectorFromTo(UTweenManagerComponent* TweenManager,
                                                                                    UMaterialInstanceDynamic* TweenTarget,
                                                                                    UTweenContainer*& OutTweenContainer,
                                                                                    UTweenLinearColor*& OutTween,
                                                                                    FName ParameterName,
                                                                                    FLinearColor From,
                                                                                    FLinearColor To,
                                                                                    float Duration              = 1.0f,
                                                                                    ETweenEaseType EaseType     = ETweenEaseType::Linear,
                                                                                    int32 NumLoops              = 1,
                                                                                    ETweenLoopType LoopType     = ETweenLoopType::Yoyo,
                                                                                    float Delay                 = 0.0f,
                                                                                    float TimeScale             = 1.0f,
                                                                                    bool TweenWhileGameIsPaused = false);

    /**
      * Creates a Latent Tween that modifies a "Vector" material parameter from its current value (at the start of the Tween) to the ending value.
      * With this function a new TweenContainer will be created, which will hold any other Tween appended/joined to this one.
      *
      * @param TweenManager (optional) The TweenManager that will handle the Tween. If none is passed, the global TweenManagerActor will be used if present.
      * @param TweenTarget The target material.
      * @param OutTweenContainer (optional, output) If this pin is connected with a variable, it will contain the TweenContainer that owns the Tween.
      * @param OutTween (optional, output) If this pin is connected with a variable, it will contain the Tween that was just created.
      * @param ParameterName The name of the material's parameter to tween.
      * @param To The ending value.
      * @param Duration The total duration of the Tween (in seconds).
      * @param EaseType	The easing functions to apply.
      * @param NumLoops	The number of times the Tween should repeat. If <= 0, it will loop indefinitely.
      * @param LoopType	The type of loop to apply (if "yoyo", it will go backwards when it reached the end; otherwise it will reset).
      * @param Delay The initial delay to apply to the Tween (in seconds).
      * @param TimeScale The scale to apply to the Tween execution. If < 1 the Tween will slow down, if > 1 it will speed up. If < 0 it will make the Tween go backward.
	  * @param TweenWhileGameIsPaused Sets whether the Tween should keep updating while the game is paused. Useful for Tween on UMG widgets that animate menus.
	  */
    UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly="true", DisplayName="Create Latent Tween Material Vector To", KeyWords="Tween Material Vector To Latent Create", AdvancedDisplay=7, AutoCreateRefTerm="OutTweenContainer, OutTween"), Category = "Tween|LatentTween|Material")
    static UTweenLinearColorLatentFactory* BP_CreateLatentTweenMaterialVectorTo(UTweenManagerComponent* TweenManager,
                                                                                UMaterialInstanceDynamic* TweenTarget,
                                                                                UTweenContainer*& OutTweenContainer,
                                                                                UTweenLinearColor*& OutTween,
                                                                                FName ParameterName,
                                                                                FLinearColor To,
                                                                                float Duration              = 1.0f,
                                                                                ETweenEaseType EaseType     = ETweenEaseType::Linear,
                                                                                int32 NumLoops              = 1,
                                                                                ETweenLoopType LoopType     = ETweenLoopType::Yoyo,
                                                                                float Delay                 = 0.0f,
                                                                                float TimeScale             = 1.0f,
                                                                                bool TweenWhileGameIsPaused = false);

    /*
     **************************************************************************
     * "Append" methods
     **************************************************************************
     */

    /**
      * Appends to the TweenContainer a Latent Tween that modifies a "Vector" material parameter from the starting value to the ending value.
      * It will be executed when all previous Tweens in the TweenContainer are completed.
      *
      * @param TweenContainer The TweenContainer that will own the new Tween.
      * @param TweenTarget The target material.
      * @param OutTween (optional, output) If this pin is connected with a variable, it will contain the Tween that was just created.
      * @param ParameterName The name of the material's parameter to tween.
      * @param From	The starting value.
      * @param To The ending value.
      * @param Duration The total duration of the Tween (in seconds).
      * @param EaseType	The easing functions to apply.
      * @param NumLoops	The number of times the Tween should repeat. If <= 0, it will loop indefinitely.
      * @param LoopType	The type of loop to apply (if "yoyo", it will go backwards when it reached the end; otherwise it will reset).
      * @param Delay The initial delay to apply to the Tween (in seconds).
      * @param TimeScale The scale to apply to the Tween execution. If < 1 the Tween will slow down, if > 1 it will speed up. If < 0 it will make the Tween go backward.
	  * @param TweenWhileGameIsPaused Sets whether the Tween should keep updating while the game is paused. Useful for Tween on UMG widgets that animate menus.
	  */
    UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly="true", DisplayName="Append Latent Tween Material Vector From To", KeyWords="Tween Material Vector From To Latent Append Sequence", AdvancedDisplay=7, AutoCreateRefTerm="OutTween"), Category = "Tween|LatentTween|Material")
    static UTweenLinearColorLatentFactory* BP_AppendLatentTweenMaterialVectorFromTo(UTweenContainer* TweenContainer,
                                                                                    UTweenLinearColor*& OutTween,
                                                                                    UMaterialInstanceDynamic* TweenTarget,
                                                                                    FName ParameterName,
                                                                                    FLinearColor From,
                                                                                    FLinearColor To,
                                                                                    float Duration              = 1.0f,
                                                                                    ETweenEaseType EaseType     = ETweenEaseType::Linear,
                                                                                    int32 NumLoops              = 1,
                                                                                    ETweenLoopType LoopType     = ETweenLoopType::Yoyo,
                                                                                    float Delay                 = 0.0f,
                                                                                    float TimeScale             = 1.0f,
                                                                                    bool TweenWhileGameIsPaused = false);

    /**
      * Appends to the TweenContainer a Latent Tween that modifies a "Vector" material parameter from its current value (at the start of the Tween) to the ending value.
      * It will be executed when all previous Tweens in the TweenContainer are completed.
      *
      * @param TweenContainer The TweenContainer that will own the new Tween.
      * @param TweenTarget The target material.
      * @param OutTween (optional, output) If this pin is connected with a variable, it will contain the Tween that was just created.
      * @param ParameterName The name of the material's parameter to tween.
      * @param To The ending value.
      * @param Duration The total duration of the Tween (in seconds).
      * @param EaseType	The easing functions to apply.
      * @param NumLoops	The number of times the Tween should repeat. If <= 0, it will loop indefinitely.
      * @param LoopType	The type of loop to apply (if "yoyo", it will go backwards when it reached the end; otherwise it will reset).
      * @param Delay The initial delay to apply to the Tween (in seconds).
      * @param TimeScale The scale to apply to the Tween execution. If < 1 the Tween will slow down, if > 1 it will speed up. If < 0 it will make the Tween go backward.
	  * @param TweenWhileGameIsPaused Sets whether the Tween should keep updating while the game is paused. Useful for Tween on UMG widgets that animate menus.
	  */
    UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly="true", DisplayName="Append Latent Tween Material Vector To", KeyWords="Tween Material Vector To Latent Append Sequence", AdvancedDisplay=6, AutoCreateRefTerm="OutTween"), Category = "Tween|LatentTween|Material")
    static UTweenLinearColorLatentFactory* BP_AppendLatentTweenMaterialVectorTo(UTweenContainer* TweenContainer,
                                                                                UTweenLinearColor*& OutTween,
                                                                                UMaterialInstanceDynamic* TweenTarget,
                                                                                FName ParameterName,
                                                                                FLinearColor To,
                                                                                float Duration              = 1.0f,
                                                                                ETweenEaseType EaseType     = ETweenEaseType::Linear,
                                                                                int32 NumLoops              = 1,
                                                                                ETweenLoopType LoopType     = ETweenLoopType::Yoyo,
                                                                                float Delay                 = 0.0f,
                                                                                float TimeScale             = 1.0f,
                                                                                bool TweenWhileGameIsPaused = false);

    /*
     **************************************************************************
     * "Join" methods
     **************************************************************************
     */

    /**
      * Joins to the TweenContainer a Latent Tween that modifies a "Vector" material parameter from the starting value to the ending value.
      * It will be executed in parallel with the last appended Tween in the TweenContainer.
      *
      * @param TweenContainer The TweenContainer that will own the new Tween.
      * @param TweenTarget The target material.
      * @param OutTween (optional, output) If this pin is connected with a variable, it will contain the Tween that was just created.
      * @param ParameterName The name of the material's parameter to tween.
      * @param From	The starting value.
      * @param To The ending value.
      * @param Duration The total duration of the Tween (in seconds).
      * @param EaseType	The easing functions to apply.
      * @param Delay The initial delay to apply to the Tween (in seconds).
      * @param TimeScale The scale to apply to the Tween execution. If < 1 the Tween will slow down, if > 1 it will speed up. If < 0 it will make the Tween go backward.
	  * @param TweenWhileGameIsPaused Sets whether the Tween should keep updating while the game is paused. Useful for Tween on UMG widgets that animate menus.
	  */
    UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly="true", DisplayName="Join Latent Tween Material Vector From To", KeyWords="Tween Material Vector From To Latent Join Parallel", AdvancedDisplay=7, AutoCreateRefTerm="OutTween"), Category = "Tween|LatentTween|Material")
    static UTweenLinearColorLatentFactory* BP_JoinLatentTweenMaterialVectorFromTo(UTweenContainer* TweenContainer,
                                                                                  UTweenLinearColor*& OutTween,
                                                                                  UMaterialInstanceDynamic* TweenTarget,
                                                                                  FName ParameterName,
                                                                                  FLinearColor From,
                                                                                  FLinearColor To,
                                                                                  float Duration              = 1.0f,
                                                                                  ETweenEaseType EaseType     = ETweenEaseType::Linear,
                                                                                  float Delay                 = 0.0f,
                                                                                  float TimeScale             = 1.0f,
                                                                                  bool TweenWhileGameIsPaused = false);

    /**
      * Joins to the TweenContainer a Latent Tween that modifies a "Vector" material parameter from its current value (at the start of the Tween) to the ending value.
      * It will be executed in parallel with the last appended Tween in the TweenContainer.
      *
      * @param TweenContainer The TweenContainer that will own the new Tween.
      * @param TweenTarget The target material.
      * @param OutTween (optional, output) If this pin is connected with a variable, it will contain the Tween that was just created.
      * @param ParameterName The name of the material's parameter to tween.
      * @param To The ending value.
      * @param Duration The total duration of the Tween (in seconds).
      * @param EaseType	The easing functions to apply.
      * @param Delay The initial delay to apply to the Tween (in seconds).
      * @param TimeScale The scale to apply to the Tween execution. If < 1 the Tween will slow down, if > 1 it will speed up. If < 0 it will make the Tween go backward.
	  * @param TweenWhileGameIsPaused Sets whether the Tween should keep updating while the game is paused. Useful for Tween on UMG widgets that animate menus.
	  */
    UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly="true", DisplayName="Join Latent Tween Material Vector To", KeyWords="Tween Material Vector To Latent Join Parallel", AdvancedDisplay=6, AutoCreateRefTerm="OutTween"), Category = "Tween|LatentTween|Material")
    static UTweenLinearColorLatentFactory* BP_JoinLatentTweenMaterialVectorTo(UTweenContainer* TweenContainer,
                                                                              UTweenLinearColor*& OutTween,
                                                                              UMaterialInstanceDynamic* TweenTarget,
                                                                              FName ParameterName,
                                                                              FLinearColor To,
                                                                              float Duration              = 1.0f,
                                                                              ETweenEaseType EaseType     = ETweenEaseType::Linear,
                                                                              float Delay                 = 0.0f,
                                                                              float TimeScale             = 1.0f,
                                                                              bool TweenWhileGameIsPaused = false);

    // UBlueprintAsyncActionBase interface
    virtual void Activate() override;
    // End of UBlueprintAsyncActionBase interface

private:

    /*
     **************************************************************************
     * Helper methods that create the actual Tweens
     **************************************************************************
     */

    static UTweenLinearColorLatentFactory* CreateProxyForAppendTweenMaterialVector(UTweenContainer* pTweenContainer,
                                                                                   ETweenLinearColorType pTweenType,
                                                                                   UObject* pTarget,
                                                                                   FName pParameterName,
                                                                                   ETweenTargetType pTargetType,
                                                                                   const FLinearColor& pFrom,
                                                                                   const FLinearColor& pTo,
                                                                                   float Duration,
                                                                                   ETweenEaseType pEaseType,
                                                                                   int32 pNumLoops,
                                                                                   ETweenLoopType pLoopType,
                                                                                   float pDelay,
                                                                                   float pTimeScale,
                                                                                   bool pTweenWhileGameIsPaused,
                                                                                   UTweenLinearColor*& OutTween);

    static UTweenLinearColorLatentFactory* CreateProxyForJoinTweenMaterialVector(UTweenContainer* pTweenContainer,
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
                                                                                 UTweenLinearColor*& OutTween);
};
