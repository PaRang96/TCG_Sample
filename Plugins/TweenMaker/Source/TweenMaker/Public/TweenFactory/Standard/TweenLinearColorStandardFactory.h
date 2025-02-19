// Copyright 2018 Francesco Desogus. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"

#include "TweenManagerComponent.h"
#include "Utils/TweenEnums.h"

#include "TweenLinearColorStandardFactory.generated.h"

class ATweenManagerActor;
class UTweenManagerComponent;
class UTweenContainer;
class UBaseTween;
class UTweenLinearColor;
class UMaterialInstanceDynamic;

/**
 * @brief The UTweenLinearColorStandardFactory class handles the creation of all LinearColor related Tweens, i.e. all tweens that
 *        in order to be executed they need to change a single LinearColor value.
 *
 *        The methods here are "standard", meaning that if the user wishes to use one of the tween callbacks (OnTweenStart,
 *        OnTweenUpdate, OnTweenEnd) he has to manually bind the delegates.
 */
UCLASS()
class TWEENMAKER_API UTweenLinearColorStandardFactory : public UObject
{
    GENERATED_BODY()

public:
    
    /**
     * @brief Constructor.
     */
    UTweenLinearColorStandardFactory(const FObjectInitializer& ObjectInitializer);


    /*
     **************************************************************************
     * "Create" methods
     **************************************************************************
     */


    /**
      * Creates a Tween that modifies a "Vector" material parameter from the starting value to the ending value.
      * With this function a new TweenContainer will be created, which will hold any other Tween appended/joined to this one.
      *
      * @param TweenManager (optional) The TweenManager that will handle the Tween. If none is passed, the global TweenManagerActor will be used if present.
      * @param TweenTarget The target material.
      * @param TweenContainer The TweenContainer that owns the Tween.
      * @param Tween The created Tween.
      * @param ParameterName The name of the material's parameter to tween.
      * @param From	The starting value.
      * @param To The ending value.
      * @param Duration The total duration of the Tween (in seconds).
      * @param EaseType	The easing functions to apply.
      * @param NumLoops	The number of times the Tween should repeat. If <= 0, it will loop indefinitely.
      * @param LoopType	The type of loop to apply (if "yoyo", it will go backwards when it reached the end; otherwise it will reset).
      * @param Delay The initial delay to apply to the Tween (in seconds).
      * @param TimeScale The scale to apply to the Tween execution. If < 1 the Tween will slow down, if > 1 it will speed up. If < 0 it will make the Tween go backward.
      * @param SequenceIndex The index of the sequence in which the new Tween should be added (hidden in Blueprint).
	  * @param TweenWhileGameIsPaused Sets whether the Tween should keep updating while the game is paused. Useful for Tween on UMG widgets that animate menus.
	  */
    UFUNCTION(BlueprintCallable, meta = (DisplayName="Create Tween Material Vector From To", KeyWords="Tween Tween Material Vector From To Create", AdvancedDisplay=8, HidePin=SequenceIndex), Category = "Tween|StandardTween|Material")
    static void BP_CreateTweenMaterialVectorFromTo(UTweenManagerComponent* TweenManager,
                                                   UMaterialInstanceDynamic* TweenTarget,
                                                   UTweenContainer*& TweenContainer,
                                                   UTweenLinearColor*& Tween,
                                                   FName ParameterName,
                                                   FLinearColor From,
                                                   FLinearColor To,
                                                   float Duration              = 1.0f,
                                                   ETweenEaseType EaseType     = ETweenEaseType::Linear,
                                                   int32 NumLoops              = 1,
                                                   ETweenLoopType LoopType     = ETweenLoopType::Yoyo,
                                                   float Delay                 = 0.0f,
                                                   float TimeScale             = 1.0f,
                                                   bool TweenWhileGameIsPaused = false,
                                                   int32 SequenceIndex         = -1);

    /**
      * Creates a Tween that modifies a "Vector" material parameter from its current value (at the start of the Tween) to the ending value.
      * With this function a new TweenContainer will be created, which will hold any other Tween appended/joined to this one.
      *
      * @param TweenManager (optional) The TweenManager that will handle the Tween. If none is passed, the global TweenManagerActor will be used if present.
      * @param TweenTarget The target material.
      * @param TweenContainer The TweenContainer that owns the Tween.
      * @param Tween The created Tween.
      * @param ParameterName The name of the material's parameter to tween.
      * @param To The ending value.
      * @param Duration The total duration of the Tween (in seconds).
      * @param EaseType	The easing functions to apply.
      * @param NumLoops	The number of times the Tween should repeat. If <= 0, it will loop indefinitely.
      * @param LoopType	The type of loop to apply (if "yoyo", it will go backwards when it reached the end; otherwise it will reset).
      * @param Delay The initial delay to apply to the Tween (in seconds).
      * @param TimeScale The scale to apply to the Tween execution. If < 1 the Tween will slow down, if > 1 it will speed up. If < 0 it will make the Tween go backward.
      * @param SequenceIndex The index of the sequence in which the new Tween should be added (hidden in Blueprint).
	  * @param TweenWhileGameIsPaused Sets whether the Tween should keep updating while the game is paused. Useful for Tween on UMG widgets that animate menus.
	  */
    UFUNCTION(BlueprintCallable, meta = (DisplayName="Create Tween Material Vector To", KeyWords="Tween Tween Material Vector To Create", AdvancedDisplay=7, HidePin=SequenceIndex), Category = "Tween|StandardTween|Material")
    static void BP_CreateTweenMaterialVectorTo(UTweenManagerComponent* TweenManager,
                                               UMaterialInstanceDynamic* TweenTarget,
                                               UTweenContainer*& TweenContainer,
                                               UTweenLinearColor*& Tween,
                                               FName ParameterName,
                                               FLinearColor To,
                                               float Duration              = 1.0f,
                                               ETweenEaseType EaseType     = ETweenEaseType::Linear,
                                               int32 NumLoops              = 1,
                                               ETweenLoopType LoopType     = ETweenLoopType::Yoyo,
                                               float Delay                 = 0.0f,
                                               float TimeScale             = 1.0f,
                                               bool TweenWhileGameIsPaused = false,
                                               int32 SequenceIndex         = -1);

    /*
     **************************************************************************
     * "Append" methods
     **************************************************************************
     */


    /**
      * Appends to the TweenContainer a Tween that modifies a "Vector" material parameter from the starting value to the ending value.
      * It will be executed when all previous Tweens in the TweenContainer are completed.
      *
      * @param TweenContainer The TweenContainer that will own the new Tween.
      * @param TweenTarget The target material.
      * @param ParameterName The name of the material's parameter to tween.
      * @param From	The starting value.
      * @param To The ending value.
      * @param Duration The total duration of the Tween (in seconds).
      * @param EaseType	The easing functions to apply.
      * @param NumLoops	The number of times the Tween should repeat. If <= 0, it will loop indefinitely.
      * @param LoopType	The type of loop to apply (if "yoyo", it will go backwards when it reached the end; otherwise it will reset).
      * @param Delay The initial delay to apply to the Tween (in seconds).
      * @param TimeScale The scale to apply to the Tween execution. If < 1 the Tween will slow down, if > 1 it will speed up. If < 0 it will make the Tween go backward.
      * @param SequenceIndex The index of the sequence in which the new Tween should be added (hidden in Blueprint).
	  * @param TweenWhileGameIsPaused Sets whether the Tween should keep updating while the game is paused. Useful for Tween on UMG widgets that animate menus.
	  *
      * @return The newly created Tween.
      */
    UFUNCTION(BlueprintCallable, meta = (DisplayName="Append Tween Material Vector From To", KeyWords="Tween Tween Material Vector From To Append Sequence", AdvancedDisplay=6, HidePin=SequenceIndex), Category = "Tween|StandardTween|Material")
    static UTweenLinearColor* BP_AppendTweenMaterialVectorFromTo(UTweenContainer* TweenContainer,
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
                                                                 bool TweenWhileGameIsPaused = false,
                                                                 int32 SequenceIndex         = -1);

    /**
      * Appends to the TweenContainer a Tween that modifies a "Vector" material parameter from its current value (at the start of the Tween) to the ending value.
      * It will be executed when all previous Tweens in the TweenContainer are completed.
      *
      * @param TweenContainer The TweenContainer that will own the new Tween.
      * @param TweenTarget The target material.
      * @param ParameterName The name of the material's parameter to tween.
      * @param To The ending value.
      * @param Duration The total duration of the Tween (in seconds).
      * @param EaseType	The easing functions to apply.
      * @param NumLoops	The number of times the Tween should repeat. If <= 0, it will loop indefinitely.
      * @param LoopType	The type of loop to apply (if "yoyo", it will go backwards when it reached the end; otherwise it will reset).
      * @param Delay The initial delay to apply to the Tween (in seconds).
      * @param TimeScale The scale to apply to the Tween execution. If < 1 the Tween will slow down, if > 1 it will speed up. If < 0 it will make the Tween go backward.
      * @param SequenceIndex The index of the sequence in which the new Tween should be added (hidden in Blueprint).
	  * @param TweenWhileGameIsPaused Sets whether the Tween should keep updating while the game is paused. Useful for Tween on UMG widgets that animate menus.
	  *
      * @return The newly created Tween.
      */
    UFUNCTION(BlueprintCallable, meta = (DisplayName="Append Tween Material Vector To", KeyWords="Tween Tween Material Vector To Append Sequence", AdvancedDisplay=5, HidePin=SequenceIndex), Category = "Tween|StandardTween|Material")
    static UTweenLinearColor* BP_AppendTweenMaterialVectorTo(UTweenContainer* TweenContainer,
                                                             UMaterialInstanceDynamic* TweenTarget,
                                                             FName ParameterName,
                                                             FLinearColor To,
                                                             float Duration              = 1.0f,
                                                             ETweenEaseType EaseType     = ETweenEaseType::Linear,
                                                             int32 NumLoops              = 1,
                                                             ETweenLoopType LoopType     = ETweenLoopType::Yoyo,
                                                             float Delay                 = 0.0f,
                                                             float TimeScale             = 1.0f,
                                                             bool TweenWhileGameIsPaused = false,
                                                             int32 SequenceIndex         = -1);

    /*
     **************************************************************************
     * "Join" methods
     **************************************************************************
     */

    /**
      * Joins to the TweenContainer a Tween that modifies a "Vector" material parameter from the starting value to the ending value.
      * It will be executed in parallel with the last appended Tween in the TweenContainer.
      *
      * @param TweenContainer The TweenContainer that will own the new Tween.
      * @param TweenTarget The target material.
      * @param ParameterName The name of the material's parameter to tween.
      * @param From	The starting value.
      * @param To The ending value.
      * @param Duration The total duration of the Tween (in seconds).
      * @param EaseType	The easing functions to apply.
      * @param Delay The initial delay to apply to the Tween (in seconds).
      * @param TimeScale The scale to apply to the Tween execution. If < 1 the Tween will slow down, if > 1 it will speed up. If < 0 it will make the Tween go backward.
      * @param SequenceIndex The index of the sequence in which the new Tween should be added (hidden in Blueprint).
	  * @param TweenWhileGameIsPaused Sets whether the Tween should keep updating while the game is paused. Useful for Tween on UMG widgets that animate menus.
	  *
      * @return The newly created Tween.
      */
    UFUNCTION(BlueprintCallable, meta = (DisplayName="Join Tween Material Vector From To", KeyWords="Tween Material Vector From To Join Parallel", AdvancedDisplay=6, HidePin=SequenceIndex), Category = "Tween|StandardTween|Material")
    static UTweenLinearColor* BP_JoinTweenMaterialVectorFromTo(UTweenContainer* TweenContainer,
                                                               UMaterialInstanceDynamic* TweenTarget,
                                                               FName ParameterName,
                                                               FLinearColor From,
                                                               FLinearColor To,
                                                               float Duration              = 1.0f,
                                                               ETweenEaseType EaseType     = ETweenEaseType::Linear,
                                                               float Delay                 = 0.0f,
                                                               float TimeScale             = 1.0f,
                                                               bool TweenWhileGameIsPaused = false,
                                                               int32 SequenceIndex         = -1);

    /**
      * Joins to the TweenContainer a Tween that modifies a "Vector" material parameter from its current value (at the start of the Tween) to the ending value.
      * It will be executed in parallel with the last appended Tween in the TweenContainer.
      *
      * @param TweenContainer The TweenContainer that will own the new Tween.
      * @param TweenTarget The target material.
      * @param ParameterName The name of the material's parameter to tween.
      * @param To The ending value.
      * @param Duration The total duration of the Tween (in seconds).
      * @param EaseType	The easing functions to apply.
      * @param Delay The initial delay to apply to the Tween (in seconds).
      * @param TimeScale The scale to apply to the Tween execution. If < 1 the Tween will slow down, if > 1 it will speed up. If < 0 it will make the Tween go backward.
      * @param SequenceIndex The index of the sequence in which the new Tween should be added (hidden in Blueprint).
	  * @param TweenWhileGameIsPaused Sets whether the Tween should keep updating while the game is paused. Useful for Tween on UMG widgets that animate menus.
	  *
      * @return The newly created Tween.
      */
    UFUNCTION(BlueprintCallable, meta = (DisplayName="Join Tween Material Vector To", KeyWords="Tween Material Vector To Join Parallel", AdvancedDisplay=5, HidePin=SequenceIndex), Category = "Tween|StandardTween|Material")
    static UTweenLinearColor* BP_JoinTweenMaterialVectorTo(UTweenContainer* TweenContainer,
                                                           UMaterialInstanceDynamic* TweenTarget,
                                                           FName ParameterName,
                                                           FLinearColor To,
                                                           float Duration              = 1.0f,
                                                           ETweenEaseType EaseType     = ETweenEaseType::Linear,
                                                           float Delay                 = 0.0f,
                                                           float TimeScale             = 1.0f,
                                                           bool TweenWhileGameIsPaused = false,
                                                           int32 SequenceIndex         = -1);

private:

    /*
     **************************************************************************
     * Helper methods that create the actual Tweens
     **************************************************************************
     */

    static UTweenLinearColor* CreateAppendTweenMaterialVector(UTweenContainer* pTweenContainer,
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
                                                              int32 pSequenceIndex);

    static UTweenLinearColor* CreateJoinTweenMaterialVector(UTweenContainer* pTweenContainer,
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
                                                            int32 pSequenceIndex);
};
