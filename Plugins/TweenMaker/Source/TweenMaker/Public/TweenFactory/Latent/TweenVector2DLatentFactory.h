// Copyright 2018 Francesco Desogus. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"

#include "Kismet/BlueprintAsyncActionBase.h"
#include "TweenManagerComponent.h"
#include "Utils/TweenEnums.h"

#include "TweenVector2DLatentFactory.generated.h"

class ATweenManagerActor;
class UTweenManagerComponent;
class UTweenContainer;
class UBaseTween;
class UWidget;
class UTweenVector2D;

/**
 * @brief The UTweenVector2DLatentFactory class handles the creation of all 2D vector related Tweens, i.e. all tweens that
 *        in order to be executed they need to change a single 2D vector value.
 *
 *        The class inherits from UBlueprintAsyncActionBase in order to be able to create "Latent" functions for Blueprint,
 *        which allow the user to easily deal with the Tween callbacks.
 */
UCLASS()
class TWEENMAKER_API UTweenVector2DLatentFactory : public UBlueprintAsyncActionBase
{
    GENERATED_BODY()

public:

    /**
     * @brief Constructor.
     */
    UTweenVector2DLatentFactory(const FObjectInitializer& ObjectInitializer);

    /// @brief Called by a Latent proxy when the Tween starts the execution.
    UPROPERTY(BlueprintAssignable)
    FBP_OnTweenVector2DChange OnTweenStart;

    /// @brief Called by a Latent proxy at each Tween's update during the the execution.
    UPROPERTY(BlueprintAssignable)
    FBP_OnTweenVector2DChange OnTweenUpdate;

    /// @brief Called by a Latent proxy when the Tween ends the execution.
    UPROPERTY(BlueprintAssignable)
    FBP_OnTweenVector2DChange OnTweenEnd;

    /*
     **************************************************************************
     * "Create" methods
     **************************************************************************
     */

    /**
      * Creates a Latent Tween that moves a UMG widget from its current location (at the start of the Tween) to the given location.
      * With this function a new TweenContainer will be created, which will hold any other Tween appended/joined to this one.
      *
      * @param TweenManager (optional) The TweenManager that will handle the Tween. If none is passed, the global TweenManagerActor will be used if present.
      * @param TweenTarget The Widget to move.
      * @param OutTweenContainer (optional, output) If this pin is connected with a variable, it will contain the TweenContainer that owns the Tween.
      * @param OutTween (optional, output) If this pin is connected with a variable, it will contain the Tween that was just created.
      * @param To The ending value.
      * @param Duration The total duration of the Tween (in seconds).
      * @param EaseType	The easing functions to apply.
      * @param NumLoops	The number of times the Tween should repeat. If <= 0, it will loop indefinitely.
      * @param LoopType	The type of loop to apply (if "yoyo", it will go backwards when it reached the end; otherwise it will reset).
      * @param Delay The initial delay to apply to the Tween (in seconds).
      * @param TimeScale The scale to apply to the Tween execution. If < 1 the Tween will slow down, if > 1 it will speed up. If < 0 it will make the Tween go backward.
	  * @param TweenWhileGameIsPaused Sets whether the Tween should keep updating while the game is paused. Useful for Tween on UMG widgets that animate menus.
	  */
    UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly="true", DisplayName="Create Latent Tween Move Widget To", KeyWords="Tween Widget UMG Move To Latent Create", AdvancedDisplay=7, AutoCreateRefTerm="OutTweenContainer, OutTween"), Category = "Tween|LatentTween|UMG|Move")
    static UTweenVector2DLatentFactory* BP_CreateLatentTweenMoveWidgetTo(UTweenManagerComponent* TweenManager,
                                                                         UWidget* TweenTarget,
                                                                         UTweenContainer*& OutTweenContainer,
                                                                         UTweenVector2D*& OutTween,
                                                                         FVector2D To,
                                                                         float Duration              = 1.0f,
                                                                         ETweenEaseType EaseType     = ETweenEaseType::Linear,
                                                                         int32 NumLoops              = 1,
                                                                         ETweenLoopType LoopType     = ETweenLoopType::Yoyo,
                                                                         float Delay                 = 0.0f,
                                                                         float TimeScale             = 1.0f,
                                                                         bool TweenWhileGameIsPaused = false);

    /**
      * Creates a Latent Tween that moves a UMG widget by the given offset with respect to its current location (at the start of the Tween).
      * With this function a new TweenContainer will be created, which will hold any other Tween appended/joined to this one.
      *
      * @param TweenManager (optional) The TweenManager that will handle the Tween. If none is passed, the global TweenManagerActor will be used if present.
      * @param TweenTarget The Widget to move.
      * @param OutTweenContainer (optional, output) If this pin is connected with a variable, it will contain the TweenContainer that owns the Tween.
      * @param OutTween (optional, output) If this pin is connected with a variable, it will contain the Tween that was just created.
      * @param By The offset to apply.
      * @param Duration The total duration of the Tween (in seconds).
      * @param EaseType	The easing functions to apply.
      * @param NumLoops	The number of times the Tween should repeat. If <= 0, it will loop indefinitely.
      * @param LoopType	The type of loop to apply (if "yoyo", it will go backwards when it reached the end; otherwise it will reset).
      * @param Delay The initial delay to apply to the Tween (in seconds).
      * @param TimeScale The scale to apply to the Tween execution. If < 1 the Tween will slow down, if > 1 it will speed up. If < 0 it will make the Tween go backward.
	  * @param TweenWhileGameIsPaused Sets whether the Tween should keep updating while the game is paused. Useful for Tween on UMG widgets that animate menus.
	  */
    UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly="true", DisplayName="Create Latent Tween Move Widget By", KeyWords="Tween Widget UMG Move By Latent Create", AdvancedDisplay=7, AutoCreateRefTerm="OutTweenContainer, OutTween"), Category = "Tween|LatentTween|UMG|Move")
    static UTweenVector2DLatentFactory* BP_CreateLatentTweenMoveWidgetBy(UTweenManagerComponent* TweenManager,
                                                                         UWidget* TweenTarget,
                                                                         UTweenContainer*& OutTweenContainer,
                                                                         UTweenVector2D*& OutTween,
                                                                         FVector2D By,
                                                                         float Duration              = 1.0f,
                                                                         ETweenEaseType EaseType     = ETweenEaseType::Linear,
                                                                         int32 NumLoops              = 1,
                                                                         ETweenLoopType LoopType     = ETweenLoopType::Yoyo,
                                                                         float Delay                 = 0.0f,
                                                                         float TimeScale             = 1.0f,
                                                                         bool TweenWhileGameIsPaused = false);

    /**
      * Creates a Latent Tween that scales a UMG widget from its current scale (at the start of the Tween) to the given size.
      * With this function a new TweenContainer will be created, which will hold any other Tween appended/joined to this one.
      *
      * @param TweenManager (optional) The TweenManager that will handle the Tween. If none is passed, the global TweenManagerActor will be used if present.
      * @param TweenTarget The Widget to scale.
      * @param OutTweenContainer (optional, output) If this pin is connected with a variable, it will contain the TweenContainer that owns the Tween.
      * @param OutTween (optional, output) If this pin is connected with a variable, it will contain the Tween that was just created.
      * @param To The ending value.
      * @param Duration The total duration of the Tween (in seconds).
      * @param EaseType	The easing functions to apply.
      * @param NumLoops	The number of times the Tween should repeat. If <= 0, it will loop indefinitely.
      * @param LoopType	The type of loop to apply (if "yoyo", it will go backwards when it reached the end; otherwise it will reset).
      * @param Delay The initial delay to apply to the Tween (in seconds).
      * @param TimeScale The scale to apply to the Tween execution. If < 1 the Tween will slow down, if > 1 it will speed up. If < 0 it will make the Tween go backward.
	  * @param TweenWhileGameIsPaused Sets whether the Tween should keep updating while the game is paused. Useful for Tween on UMG widgets that animate menus.
	  */
    UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly="true", DisplayName="Create Latent Tween Scale Widget To", KeyWords="Tween Scale Widget UMG To Latent Create", AdvancedDisplay=7, AutoCreateRefTerm="OutTweenContainer, OutTween"), Category = "Tween|LatentTween|UMG|Scale")
    static UTweenVector2DLatentFactory* BP_CreateLatentTweenScaleWidgetTo(UTweenManagerComponent* TweenManager,
                                                                          UWidget* TweenTarget,
                                                                          UTweenContainer*& OutTweenContainer,
                                                                          UTweenVector2D*& OutTween,
                                                                          FVector2D To,
                                                                          float Duration              = 1.0f,
                                                                          ETweenEaseType EaseType     = ETweenEaseType::Linear,
                                                                          int32 NumLoops              = 1,
                                                                          ETweenLoopType LoopType     = ETweenLoopType::Yoyo,
                                                                          float Delay                 = 0.0f,
                                                                          float TimeScale             = 1.0f,
                                                                          bool TweenWhileGameIsPaused = false);

    /**
      * Creates a Latent Tween that scales a UMG widget by the given offset with respect to its current size (at the start of the Tween).
      * With this function a new TweenContainer will be created, which will hold any other Tween appended/joined to this one.
      *
      * @param TweenManager (optional) The TweenManager that will handle the Tween. If none is passed, the global TweenManagerActor will be used if present.
      * @param TweenTarget The Widget to scale.
      * @param OutTweenContainer (optional, output) If this pin is connected with a variable, it will contain the TweenContainer that owns the Tween.
      * @param OutTween (optional, output) If this pin is connected with a variable, it will contain the Tween that was just created.
      * @param By The offset to apply.
      * @param Duration The total duration of the Tween (in seconds).
      * @param EaseType	The easing functions to apply.
      * @param NumLoops	The number of times the Tween should repeat. If <= 0, it will loop indefinitely.
      * @param LoopType	The type of loop to apply (if "yoyo", it will go backwards when it reached the end; otherwise it will reset).
      * @param Delay The initial delay to apply to the Tween (in seconds).
      * @param TimeScale The scale to apply to the Tween execution. If < 1 the Tween will slow down, if > 1 it will speed up. If < 0 it will make the Tween go backward.
	  * @param TweenWhileGameIsPaused Sets whether the Tween should keep updating while the game is paused. Useful for Tween on UMG widgets that animate menus.
	  */
    UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly="true", DisplayName="Create Latent Tween Scale Widget By", KeyWords="Tween Scale Widget UMG By Latent Create", AdvancedDisplay=7, AutoCreateRefTerm="OutTweenContainer, OutTween"), Category = "Tween|LatentTween|UMG|Scale")
    static UTweenVector2DLatentFactory* BP_CreateLatentTweenScaleWidgetBy(UTweenManagerComponent* TweenManager,
                                                                          UWidget* TweenTarget,
                                                                          UTweenContainer*& OutTweenContainer,
                                                                          UTweenVector2D*& OutTween,
                                                                          FVector2D By,
                                                                          float Duration              = 1.0f,
                                                                          ETweenEaseType EaseType     = ETweenEaseType::Linear,
                                                                          int32 NumLoops              = 1,
                                                                          ETweenLoopType LoopType     = ETweenLoopType::Yoyo,
                                                                          float Delay                 = 0.0f,
                                                                          float TimeScale             = 1.0f,
                                                                          bool TweenWhileGameIsPaused = false);

    /**
      * Creates a Latent Tween that modifies a UMG widget's shear value from its current value (at the start of the Tween) to the given ending value.
      * With this function a new TweenContainer will be created, which will hold any other Tween appended/joined to this one.
      *
      * @param TweenManager (optional) The TweenManager that will handle the Tween. If none is passed, the global TweenManagerActor will be used if present.
      * @param TweenTarget The Widget to shear.
      * @param OutTweenContainer (optional, output) If this pin is connected with a variable, it will contain the TweenContainer that owns the Tween.
      * @param OutTween (optional, output) If this pin is connected with a variable, it will contain the Tween that was just created.
      * @param To The ending value.
      * @param Duration The total duration of the Tween (in seconds).
      * @param EaseType	The easing functions to apply.
      * @param NumLoops	The number of times the Tween should repeat. If <= 0, it will loop indefinitely.
      * @param LoopType	The type of loop to apply (if "yoyo", it will go backwards when it reached the end; otherwise it will reset).
      * @param Delay The initial delay to apply to the Tween (in seconds).
      * @param TimeScale The scale to apply to the Tween execution. If < 1 the Tween will slow down, if > 1 it will speed up. If < 0 it will make the Tween go backward.
	  * @param TweenWhileGameIsPaused Sets whether the Tween should keep updating while the game is paused. Useful for Tween on UMG widgets that animate menus.
	  */
    UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly="true", DisplayName="Create Latent Tween Shear Widget To", KeyWords="Tween Shear Widget UMG By Latent Create", AdvancedDisplay=7, AutoCreateRefTerm="OutTweenContainer, OutTween"), Category = "Tween|LatentTween|UMG|Shear")
    static UTweenVector2DLatentFactory* BP_CreateLatentTweenShearWidgetTo(UTweenManagerComponent* TweenManager,
                                                                          UWidget* TweenTarget,
                                                                          UTweenContainer*& OutTweenContainer,
                                                                          UTweenVector2D*& OutTween,
                                                                          FVector2D To,
                                                                          float Duration              = 1.0f,
                                                                          ETweenEaseType EaseType     = ETweenEaseType::Linear,
                                                                          int32 NumLoops              = 1,
                                                                          ETweenLoopType LoopType     = ETweenLoopType::Yoyo,
                                                                          float Delay                 = 0.0f,
                                                                          float TimeScale             = 1.0f,
                                                                          bool TweenWhileGameIsPaused = false);

    /**
      * Creates a custom Latent Tween that goes from a starting value to an ending one. This type of Tween is meant for creating custom behaviours
      * by binding a function or an event to the OnTweenUpdate delegate in order to use the tweened value at each Tick by calling GetCurrentValue from the Tween object.
      * With this function a new TweenContainer will be created, which will hold any other Tween appended/joined to this one.

      * @param TweenManager (optional) The TweenManager that will handle the Tween. If none is passed, the global TweenManagerActor will be used if present.
      * @param TweenTarget The target of the tween. Can be anything, as long as it's not null.
      * @param OutTweenContainer (optional, output) If this pin is connected with a variable, it will contain the TweenContainer that owns the Tween.
      * @param OutTween (optional, output) If this pin is connected with a variable, it will contain the Tween that was just created.
      * @param From The starting value.
      * @param To The ending value.
      * @param Duration The total duration of the Tween (in seconds).
      * @param EaseType	The easing functions to apply.
      * @param NumLoops	The number of times the Tween should repeat. If <= 0, it will loop indefinitely.
      * @param LoopType	The type of loop to apply (if "yoyo", it will go backwards when it reached the end; otherwise it will reset).
      * @param Delay The initial delay to apply to the Tween (in seconds).
      * @param TimeScale The scale to apply to the Tween execution. If < 1 the Tween will slow down, if > 1 it will speed up. If < 0 it will make the Tween go backward.
	  * @param TweenWhileGameIsPaused Sets whether the Tween should keep updating while the game is paused. Useful for Tween on UMG widgets that animate menus.
	  */
    UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly="true", DisplayName="Create Latent Tween Custom Vector2D", KeyWords="Tween Custom Vector2D Latent Create", AdvancedDisplay=8, AutoCreateRefTerm="OutTweenContainer, OutTween"), Category = "Tween|LatentTween|Custom")
    static UTweenVector2DLatentFactory* BP_CreateLatentTweenCustomVector2D(UTweenManagerComponent* TweenManager,
                                                                           UObject* TweenTarget,
                                                                           UTweenContainer*& OutTweenContainer,
                                                                           UTweenVector2D*& OutTween,
                                                                           FVector2D From,
                                                                           FVector2D To,
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
      * Appends to the TweenContainer a Latent Tween that moves a UMG widget from its current location (at the start of the Tween) to the given location.
      * It will be executed when all previous Tweens in the TweenContainer are completed.
      *
      * @param TweenContainer The TweenContainer that will own the new Tween.
      * @param TweenTarget The Widget to move.
      * @param OutTween (optional, output) If this pin is connected with a variable, it will contain the Tween that was just created.
      * @param To The ending value.
      * @param Duration The total duration of the Tween (in seconds).
      * @param EaseType	The easing functions to apply.
      * @param NumLoops	The number of times the Tween should repeat. If <= 0, it will loop indefinitely.
      * @param LoopType	The type of loop to apply (if "yoyo", it will go backwards when it reached the end; otherwise it will reset).
      * @param Delay The initial delay to apply to the Tween (in seconds).
      * @param TimeScale The scale to apply to the Tween execution. If < 1 the Tween will slow down, if > 1 it will speed up. If < 0 it will make the Tween go backward.
	  * @param TweenWhileGameIsPaused Sets whether the Tween should keep updating while the game is paused. Useful for Tween on UMG widgets that animate menus.
	  */
    UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly="true", DisplayName="Append Latent Tween Move Widget To", KeyWords="Tween Widget UMG Move To Latent Append Sequence", AdvancedDisplay=6, AutoCreateRefTerm="OutTween"), Category = "Tween|LatentTween|UMG|Move")
    static UTweenVector2DLatentFactory* BP_AppendLatentTweenMoveWidgetTo(UTweenContainer* TweenContainer,
                                                                         UTweenVector2D*& OutTween,
                                                                         UWidget* TweenTarget,
                                                                         FVector2D To,
                                                                         float Duration              = 1.0f,
                                                                         ETweenEaseType EaseType     = ETweenEaseType::Linear,
                                                                         int32 NumLoops              = 1,
                                                                         ETweenLoopType LoopType     = ETweenLoopType::Yoyo,
                                                                         float Delay                 = 0.0f,
                                                                         float TimeScale             = 1.0f,
                                                                         bool TweenWhileGameIsPaused = false);

    /**
      * Appends to the TweenContainer a Latent Tween that moves a UMG widget by the given offset with respect to its current location (at the start of the Tween).
      * It will be executed when all previous Tweens in the TweenContainer are completed.
      *
      * @param TweenContainer The TweenContainer that will own the new Tween.
      * @param TweenTarget The Widget to move.
      * @param OutTween (optional, output) If this pin is connected with a variable, it will contain the Tween that was just created.
      * @param By The offset to apply.
      * @param Duration The total duration of the Tween (in seconds).
      * @param EaseType	The easing functions to apply.
      * @param NumLoops	The number of times the Tween should repeat. If <= 0, it will loop indefinitely.
      * @param LoopType	The type of loop to apply (if "yoyo", it will go backwards when it reached the end; otherwise it will reset).
      * @param Delay The initial delay to apply to the Tween (in seconds).
      * @param TimeScale The scale to apply to the Tween execution. If < 1 the Tween will slow down, if > 1 it will speed up. If < 0 it will make the Tween go backward.
	  * @param TweenWhileGameIsPaused Sets whether the Tween should keep updating while the game is paused. Useful for Tween on UMG widgets that animate menus.
	  */
    UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly="true", DisplayName="Append Latent Tween Move Widget By", KeyWords="Tween Widget UMG Move By Latent Append Sequence", AdvancedDisplay=6, AutoCreateRefTerm="OutTween"), Category = "Tween|LatentTween|UMG|Move")
    static UTweenVector2DLatentFactory* BP_AppendLatentTweenMoveWidgetBy(UTweenContainer* TweenContainer,
                                                                         UTweenVector2D*& OutTween,
                                                                         UWidget* TweenTarget,
                                                                         FVector2D By,
                                                                         float Duration              = 1.0f,
                                                                         ETweenEaseType EaseType     = ETweenEaseType::Linear,
                                                                         int32 NumLoops              = 1,
                                                                         ETweenLoopType LoopType     = ETweenLoopType::Yoyo,
                                                                         float Delay                 = 0.0f,
                                                                         float TimeScale             = 1.0f,
                                                                         bool TweenWhileGameIsPaused = false);

    /**
      * Appends to the TweenContainer a Latent Tween that moves a UMG widget from its current scale (at the start of the Tween) to the given size.
      * It will be executed when all previous Tweens in the TweenContainer are completed.
      *
      * @param TweenContainer The TweenContainer that will own the new Tween.
      * @param TweenTarget The Widget to scale.
      * @param OutTween (optional, output) If this pin is connected with a variable, it will contain the Tween that was just created.
      * @param To The ending value.
      * @param Duration The total duration of the Tween (in seconds).
      * @param EaseType	The easing functions to apply.
      * @param NumLoops	The number of times the Tween should repeat. If <= 0, it will loop indefinitely.
      * @param LoopType	The type of loop to apply (if "yoyo", it will go backwards when it reached the end; otherwise it will reset).
      * @param Delay The initial delay to apply to the Tween (in seconds).
      * @param TimeScale The scale to apply to the Tween execution. If < 1 the Tween will slow down, if > 1 it will speed up. If < 0 it will make the Tween go backward.
	  * @param TweenWhileGameIsPaused Sets whether the Tween should keep updating while the game is paused. Useful for Tween on UMG widgets that animate menus.
	  */
    UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly="true", DisplayName="Append Latent Tween Scale Widget To", KeyWords="Tween Scale Widget UMG To Latent Append Sequence", AdvancedDisplay=6, AutoCreateRefTerm="OutTween"), Category = "Tween|LatentTween|UMG|Scale")
    static UTweenVector2DLatentFactory* BP_AppendLatentTweenScaleWidgetTo(UTweenContainer* TweenContainer,
                                                                          UTweenVector2D*& OutTween,
                                                                          UWidget* TweenTarget,
                                                                          FVector2D To,
                                                                          float Duration              = 1.0f,
                                                                          ETweenEaseType EaseType     = ETweenEaseType::Linear,
                                                                          int32 NumLoops              = 1,
                                                                          ETweenLoopType LoopType     = ETweenLoopType::Yoyo,
                                                                          float Delay                 = 0.0f,
                                                                          float TimeScale             = 1.0f,
                                                                          bool TweenWhileGameIsPaused = false);

    /**
      * Appends to the TweenContainer a Latent Tween that scales a UMG widget by the given offset with respect to its current size (at the start of the Tween).
      * It will be executed when all previous Tweens in the TweenContainer are completed.
      *
      * @param TweenContainer The TweenContainer that will own the new Tween.
      * @param TweenTarget The Widget to scale.
      * @param OutTween (optional, output) If this pin is connected with a variable, it will contain the Tween that was just created.
      * @param By The offset to apply.
      * @param Duration The total duration of the Tween (in seconds).
      * @param EaseType	The easing functions to apply.
      * @param NumLoops	The number of times the Tween should repeat. If <= 0, it will loop indefinitely.
      * @param LoopType	The type of loop to apply (if "yoyo", it will go backwards when it reached the end; otherwise it will reset).
      * @param Delay The initial delay to apply to the Tween (in seconds).
      * @param TimeScale The scale to apply to the Tween execution. If < 1 the Tween will slow down, if > 1 it will speed up. If < 0 it will make the Tween go backward.
	  * @param TweenWhileGameIsPaused Sets whether the Tween should keep updating while the game is paused. Useful for Tween on UMG widgets that animate menus.
	  */
    UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly="true", DisplayName="Append Latent Tween Scale Widget By", KeyWords="Tween Scale Widget UMG By Latent Append Sequence", AdvancedDisplay=6, AutoCreateRefTerm="OutTween"), Category = "Tween|LatentTween|UMG|Scale")
    static UTweenVector2DLatentFactory* BP_AppendLatentTweenScaleWidgetBy(UTweenContainer* TweenContainer,
                                                                          UTweenVector2D*& OutTween,
                                                                          UWidget* TweenTarget,
                                                                          FVector2D By,
                                                                          float Duration              = 1.0f,
                                                                          ETweenEaseType EaseType     = ETweenEaseType::Linear,
                                                                          int32 NumLoops              = 1,
                                                                          ETweenLoopType LoopType     = ETweenLoopType::Yoyo,
                                                                          float Delay                 = 0.0f,
                                                                          float TimeScale             = 1.0f,
                                                                          bool TweenWhileGameIsPaused = false);

    /**
      * Appends to the TweenContainer a Latent Tween that modifies a UMG widget's shear value from its current value (at the start of the Tween) to the given ending value.
      * It will be executed when all previous Tweens in the TweenContainer are completed.
      *
      * @param TweenContainer The TweenContainer that will own the new Tween.
      * @param TweenTarget The Widget to shear.
      * @param OutTween (optional, output) If this pin is connected with a variable, it will contain the Tween that was just created.
      * @param To The ending value.
      * @param Duration The total duration of the Tween (in seconds).
      * @param EaseType	The easing functions to apply.
      * @param NumLoops	The number of times the Tween should repeat. If <= 0, it will loop indefinitely.
      * @param LoopType	The type of loop to apply (if "yoyo", it will go backwards when it reached the end; otherwise it will reset).
      * @param Delay The initial delay to apply to the Tween (in seconds).
      * @param TimeScale The scale to apply to the Tween execution. If < 1 the Tween will slow down, if > 1 it will speed up. If < 0 it will make the Tween go backward.
	  * @param TweenWhileGameIsPaused Sets whether the Tween should keep updating while the game is paused. Useful for Tween on UMG widgets that animate menus.
	  */
    UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly="true", DisplayName="Append Latent Tween Shear Widget To", KeyWords="Tween Shear Widget UMG By Latent Append Sequence", AdvancedDisplay=6, AutoCreateRefTerm="OutTween"), Category = "Tween|LatentTween|UMG|Shear")
    static UTweenVector2DLatentFactory* BP_AppendLatentTweenShearWidgetTo(UTweenContainer* TweenContainer,
                                                                          UTweenVector2D*& OutTween,
                                                                          UWidget* TweenTarget,
                                                                          FVector2D To,
                                                                          float Duration              = 1.0f,
                                                                          ETweenEaseType EaseType     = ETweenEaseType::Linear,
                                                                          int32 NumLoops              = 1,
                                                                          ETweenLoopType LoopType     = ETweenLoopType::Yoyo,
                                                                          float Delay                 = 0.0f,
                                                                          float TimeScale             = 1.0f,
                                                                          bool TweenWhileGameIsPaused = false);

    /**
      * Appends to the TweenContainer a custom Latent Tween that goes from a starting value to an ending one. This type of Tween is meant for creating custom behaviours
      * by binding a function or an event to the OnTweenUpdate delegate in order to use the tweened value at each Tick by calling GetCurrentValue from the Tween object.
      * The Tween will be executed when all Tweens before it are completed.
      *
      * @param TweenContainer The TweenContainer that will own the new Tween.
      * @param TweenTarget The target of the tween. Can be anything, as long as it's not null.
      * @param OutTween (optional, output) If this pin is connected with a variable, it will contain the Tween that was just created.
      * @param From The starting value.
      * @param To The ending value.
      * @param Duration The total duration of the Tween (in seconds).
      * @param EaseType	The easing functions to apply.
      * @param NumLoops	The number of times the Tween should repeat. If <= 0, it will loop indefinitely.
      * @param LoopType	The type of loop to apply (if "yoyo", it will go backwards when it reached the end; otherwise it will reset).
      * @param Delay The initial delay to apply to the Tween (in seconds).
      * @param TimeScale The scale to apply to the Tween execution. If < 1 the Tween will slow down, if > 1 it will speed up. If < 0 it will make the Tween go backward.
	  * @param TweenWhileGameIsPaused Sets whether the Tween should keep updating while the game is paused. Useful for Tween on UMG widgets that animate menus.
	  */
    UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly="true", DisplayName="Append Latent Tween Custom Vector2D", KeyWords="Tween Custom Vector2D Latent Append Sequence", AdvancedDisplay=7, AutoCreateRefTerm="OutTween"), Category = "Tween|LatentTween|Custom")
    static UTweenVector2DLatentFactory* BP_AppendLatentTweenCustomVector2D(UTweenContainer* TweenContainer,
                                                                           UTweenVector2D*& OutTween,
                                                                           UObject* TweenTarget,
                                                                           FVector2D From,
                                                                           FVector2D To,
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
      * Joins to the TweenContainer a Latent Tween that moves a UMG widget from its current location (at the start of the Tween) to the given location.
      * It will be executed in parallel with the last appended Tween in the TweenContainer.
      *
      * @param TweenContainer The TweenContainer that will own the new Tween.
      * @param TweenTarget The Widget to move.
      * @param OutTween (optional, output) If this pin is connected with a variable, it will contain the Tween that was just created.
      * @param To The ending value.
      * @param Duration The total duration of the Tween (in seconds).
      * @param EaseType	The easing functions to apply.
      * @param Delay The initial delay to apply to the Tween (in seconds).
      * @param TimeScale The scale to apply to the Tween execution. If < 1 the Tween will slow down, if > 1 it will speed up. If < 0 it will make the Tween go backward.
	  * @param TweenWhileGameIsPaused Sets whether the Tween should keep updating while the game is paused. Useful for Tween on UMG widgets that animate menus.
	  */
    UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly="true", DisplayName="Join Latent Tween Move Widget To", KeyWords="Tween Widget UMG Move To Latent Join Parallel", AdvancedDisplay=6, AutoCreateRefTerm="OutTween"), Category = "Tween|LatentTween|UMG|Move")
    static UTweenVector2DLatentFactory* BP_JoinLatentTweenMoveWidgetTo(UTweenContainer* TweenContainer,
                                                                       UTweenVector2D*& OutTween,
                                                                       UWidget* TweenTarget,
                                                                       FVector2D To,
                                                                       float Duration              = 1.0f,
                                                                       ETweenEaseType EaseType     = ETweenEaseType::Linear,
                                                                       float Delay                 = 0.0f,
                                                                       float TimeScale             = 1.0f,
                                                                       bool TweenWhileGameIsPaused = false);

    /**
      * Joins to the TweenContainer a Latent Tween that moves a UMG widget by the given offset with respect to its current location (at the start of the Tween).
      * It will be executed in parallel with the last appended Tween in the TweenContainer.
      *
      * @param TweenContainer The TweenContainer that will own the new Tween.
      * @param TweenTarget The Widget to move.
      * @param OutTween (optional, output) If this pin is connected with a variable, it will contain the Tween that was just created.
      * @param By The offset to apply.
      * @param Duration The total duration of the Tween (in seconds).
      * @param EaseType	The easing functions to apply.
      * @param Delay The initial delay to apply to the Tween (in seconds).
      * @param TimeScale The scale to apply to the Tween execution. If < 1 the Tween will slow down, if > 1 it will speed up. If < 0 it will make the Tween go backward.
	  * @param TweenWhileGameIsPaused Sets whether the Tween should keep updating while the game is paused. Useful for Tween on UMG widgets that animate menus.
	  */
    UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly="true", DisplayName="Join Latent Tween Move Widget By", KeyWords="Tween Widget UMG Move By Latent Join Parallel", AdvancedDisplay=6, AutoCreateRefTerm="OutTween"), Category = "Tween|LatentTween|UMG|Move")
    static UTweenVector2DLatentFactory* BP_JoinLatentTweenMoveWidgetBy(UTweenContainer* TweenContainer,
                                                                       UTweenVector2D*& OutTween,
                                                                       UWidget* TweenTarget,
                                                                       FVector2D By,
                                                                       float Duration              = 1.0f,
                                                                       ETweenEaseType EaseType     = ETweenEaseType::Linear,
                                                                       float Delay                 = 0.0f,
                                                                       float TimeScale             = 1.0f,
                                                                       bool TweenWhileGameIsPaused = false);

    /**
      * Joins to the TweenContainer a Latent Tween that moves a UMG widget from its current scale (at the start of the Tween) to the given size.
      * It will be executed in parallel with the last appended Tween in the TweenContainer.
      *
      * @param TweenContainer The TweenContainer that will own the new Tween.
      * @param TweenTarget The Widget to scale.
      * @param OutTween (optional, output) If this pin is connected with a variable, it will contain the Tween that was just created.
      * @param To The ending value.
      * @param Duration The total duration of the Tween (in seconds).
      * @param EaseType	The easing functions to apply.
      * @param Delay The initial delay to apply to the Tween (in seconds).
      * @param TimeScale The scale to apply to the Tween execution. If < 1 the Tween will slow down, if > 1 it will speed up. If < 0 it will make the Tween go backward.
	  * @param TweenWhileGameIsPaused Sets whether the Tween should keep updating while the game is paused. Useful for Tween on UMG widgets that animate menus.
	  */
    UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly="true", DisplayName="Join Latent Tween Scale Widget To", KeyWords="Tween Scale Widget UMG To Latent Join Parallel", AdvancedDisplay=6, AutoCreateRefTerm="OutTween"), Category = "Tween|LatentTween|UMG|Scale")
    static UTweenVector2DLatentFactory* BP_JoinLatentTweenScaleWidgetTo(UTweenContainer* TweenContainer,
                                                                        UTweenVector2D*& OutTween,
                                                                        UWidget* TweenTarget,
                                                                        FVector2D To,
                                                                        float Duration              = 1.0f,
                                                                        ETweenEaseType EaseType     = ETweenEaseType::Linear,
                                                                        float Delay                 = 0.0f,
                                                                        float TimeScale             = 1.0f,
                                                                        bool TweenWhileGameIsPaused = false);

    /**
      * Joins to the TweenContainer a Latent Tween that scales a UMG widget by the given offset with respect to its current size (at the start of the Tween).
      * It will be executed in parallel with the last appended Tween in the TweenContainer.
      *
      * @param TweenContainer The TweenContainer that will own the new Tween.
      * @param TweenTarget The Widget to scale.
      * @param OutTween (optional, output) If this pin is connected with a variable, it will contain the Tween that was just created.
      * @param By The offset to apply.
      * @param Duration The total duration of the Tween (in seconds).
      * @param EaseType	The easing functions to apply.
      * @param Delay The initial delay to apply to the Tween (in seconds).
      * @param TimeScale The scale to apply to the Tween execution. If < 1 the Tween will slow down, if > 1 it will speed up. If < 0 it will make the Tween go backward.
	  * @param TweenWhileGameIsPaused Sets whether the Tween should keep updating while the game is paused. Useful for Tween on UMG widgets that animate menus.
	  */
    UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly="true", DisplayName="Join Latent Tween Scale Widget By", KeyWords="Tween Scale Widget UMG By Latent Join Parallel", AdvancedDisplay=6, AutoCreateRefTerm="OutTween"), Category = "Tween|LatentTween|UMG|Scale")
    static UTweenVector2DLatentFactory* BP_JoinLatentTweenScaleWidgetBy(UTweenContainer* TweenContainer,
                                                                        UTweenVector2D*& OutTween,
                                                                        UWidget* TweenTarget,
                                                                        FVector2D By,
                                                                        float Duration              = 1.0f,
                                                                        ETweenEaseType EaseType     = ETweenEaseType::Linear,
                                                                        float Delay                 = 0.0f,
                                                                        float TimeScale             = 1.0f,
                                                                        bool TweenWhileGameIsPaused = false);

    /**
      * Joins to the TweenContainer a Latent Tween that modifies a UMG widget's shear value from its current value (at the start of the Tween) to the given ending value.
      * It will be executed in parallel with the last appended Tween in the TweenContainer.
      *
      * @param TweenContainer The TweenContainer that will own the new Tween.
      * @param TweenTarget The Widget to shear.
      * @param OutTween (optional, output) If this pin is connected with a variable, it will contain the Tween that was just created.
      * @param To The ending value.
      * @param Duration The total duration of the Tween (in seconds).
      * @param EaseType	The easing functions to apply.
      * @param Delay The initial delay to apply to the Tween (in seconds).
      * @param TimeScale The scale to apply to the Tween execution. If < 1 the Tween will slow down, if > 1 it will speed up. If < 0 it will make the Tween go backward.
	  * @param TweenWhileGameIsPaused Sets whether the Tween should keep updating while the game is paused. Useful for Tween on UMG widgets that animate menus.
	  */
    UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly="true", DisplayName="Join Latent Tween Shear Widget To", KeyWords="Tween Shear Widget UMG To Latent Join Parallel", AdvancedDisplay=6, AutoCreateRefTerm="OutTween"), Category = "Tween|LatentTween|UMG|Shear")
    static UTweenVector2DLatentFactory* BP_JoinLatentTweenShearWidgetTo(UTweenContainer* TweenContainer,
                                                                        UTweenVector2D*& OutTween,
                                                                        UWidget* TweenTarget,
                                                                        FVector2D To,
                                                                        float Duration              = 1.0f,
                                                                        ETweenEaseType EaseType     = ETweenEaseType::Linear,
                                                                        float Delay                 = 0.0f,
                                                                        float TimeScale             = 1.0f,
                                                                        bool TweenWhileGameIsPaused = false);

    /**
      * Joins to the TweenContainer a custom Latent Tween that goes from a starting value to an ending one. This type of Tween is meant for creating custom behaviours
      * by binding a function or an event to the OnTweenUpdate delegate in order to use the tweened value at each Tick by calling GetCurrentValue from the Tween object.
      * The Tween will be executed when all Tweens before it are completed.
      *
      * @param TweenContainer The TweenContainer that will own the new Tween.
      * @param TweenTarget The target of the tween. Can be anything, as long as it's not null.
      * @param OutTween (optional, output) If this pin is connected with a variable, it will contain the Tween that was just created.
      * @param From The starting value.
      * @param To The ending value.
      * @param Duration The total duration of the Tween (in seconds).
      * @param EaseType	The easing functions to apply.
      * @param Delay The initial delay to apply to the Tween (in seconds).
      * @param TimeScale The scale to apply to the Tween execution. If < 1 the Tween will slow down, if > 1 it will speed up. If < 0 it will make the Tween go backward.
	  * @param TweenWhileGameIsPaused Sets whether the Tween should keep updating while the game is paused. Useful for Tween on UMG widgets that animate menus.
	  */
    UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly="true", DisplayName="Join Latent Tween Custom Vector2D", KeyWords="Tween Custom Vector2D Latent Join Parallel", AdvancedDisplay=7, AutoCreateRefTerm="OutTween"), Category = "Tween|LatentTween|Custom")
    static UTweenVector2DLatentFactory* BP_JoinLatentTweenCustomVector2D(UTweenContainer* TweenContainer,
                                                                         UTweenVector2D*& OutTween,
                                                                         UObject* TweenTarget,
                                                                         FVector2D From,
                                                                         FVector2D To,
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

    static UTweenVector2DLatentFactory* CreateProxyForAppendTweenVector2D(UTweenContainer* pTweenContainer,
                                                                          ETweenVector2DType pTweenType,
                                                                          UObject* pTarget,
                                                                          ETweenTargetType pTargetType,
                                                                          const FVector2D& pFrom,
                                                                          const FVector2D& pTo,
                                                                          float Duration,
                                                                          ETweenEaseType pEaseType,
                                                                          int32 pNumLoops,
                                                                          ETweenLoopType pLoopType,
                                                                          float pDelay,
                                                                          float pTimeScale,
                                                                          bool pTweenWhileGameIsPaused,
                                                                          UTweenVector2D*& OutTween);

    static UTweenVector2DLatentFactory* CreateProxyForJoinTweenVector2D(UTweenContainer* pTweenContainer,
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
                                                                        UTweenVector2D*& OutTween);
};
