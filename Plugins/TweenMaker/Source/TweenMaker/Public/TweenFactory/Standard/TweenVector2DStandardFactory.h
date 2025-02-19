// Copyright 2018 Francesco Desogus. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"

#include "TweenManagerComponent.h"
#include "Utils/TweenEnums.h"

#include "TweenVector2DStandardFactory.generated.h"

class ATweenManagerActor;
class UTweenManagerComponent;
class UTweenContainer;
class UBaseTween;
class UWidget;
class UTweenVector2D;

/**
 * @brief The UTweenVector2DStandardFactory class handles the creation of all 2D vector related Tweens, i.e. all tweens that
 *        in order to be executed they need to change a single 2D vector value.
 *
 *        The methods here are "standard", meaning that if the user wishes to use one of the tween callbacks (OnTweenStart,
 *        OnTweenUpdate, OnTweenEnd) he has to manually bind the delegates.
 */
UCLASS()
class TWEENMAKER_API UTweenVector2DStandardFactory : public UObject
{
    GENERATED_BODY()

public:

    /**
     * @brief Constructor.
     */
    UTweenVector2DStandardFactory(const FObjectInitializer& ObjectInitializer);

    /*
     **************************************************************************
     * "Create" methods
     **************************************************************************
     */

    /**
      * Creates a Tween that moves a UMG widget from its current location (at the start of the Tween) to the given location.
      * With this function a new TweenContainer will be created, which will hold any other Tween appended/joined to this one.
      *
      * @param TweenManager (optional) The TweenManager that will handle the Tween. If none is passed, the global TweenManagerActor will be used if present.
      * @param TweenTarget The Widget to move.
      * @param TweenContainer The TweenContainer that owns the Tween.
      * @param Tween The created Tween.
      * @param To The ending value.
      * @param Duration The total duration of the Tween (in seconds).
      * @param EaseType	The easing functions to apply.
      * @param NumLoops	The number of times the Tween should repeat. If <= 0, it will loop indefinitely.
      * @param LoopType	The type of loop to apply (if "yoyo", it will go backwards when it reached the end; otherwise it will reset).
      * @param Delay The initial delay to apply to the Tween (in seconds).
      * @param TimeScale The scale to apply to the Tween execution. If < 1 the Tween will slow down, if > 1 it will speed up. If < 0 it will make the Tween go backward.
	  * @param TweenWhileGameIsPaused Sets whether the Tween should keep updating while the game is paused. Useful for Tween on UMG widgets that animate menus.
	  * @param SequenceIndex The index of the sequence in which the new Tween should be added (hidden in Blueprint).
      */
    UFUNCTION(BlueprintCallable, meta = (DisplayName="Create Tween Move Widget To", KeyWords="Tween Move Widget UMG To Create", AdvancedDisplay=7, HidePin=SequenceIndex), Category = "Tween|StandardTween|UMG|Move")
    static void BP_CreateTweenMoveWidgetTo(UTweenManagerComponent* TweenManager,
                                           UWidget* TweenTarget,
                                           UTweenContainer*& TweenContainer,
                                           UTweenVector2D*& Tween,
                                           FVector2D To,
                                           float Duration              = 1.0f,
                                           ETweenEaseType EaseType     = ETweenEaseType::Linear,
                                           int32 NumLoops              = 1,
                                           ETweenLoopType LoopType     = ETweenLoopType::Yoyo,
                                           float Delay                 = 0.0f,
                                           float TimeScale             = 1.0f,
                                           bool TweenWhileGameIsPaused = false,
                                           int32 SequenceIndex         = -1);


    /**
      * Creates a Tween that moves a UMG widget by the given offset with respect to its current location (at the start of the Tween).
      * With this function a new TweenContainer will be created, which will hold any other Tween appended/joined to this one.
      *
      * @param TweenManager (optional) The TweenManager that will handle the Tween. If none is passed, the global TweenManagerActor will be used if present.
      * @param TweenTarget The Widget to move.
      * @param TweenContainer The TweenContainer that owns the Tween.
      * @param Tween The created Tween.
      * @param By The offset to apply.
      * @param Duration The total duration of the Tween (in seconds).
      * @param EaseType	The easing functions to apply.
      * @param NumLoops	The number of times the Tween should repeat. If <= 0, it will loop indefinitely.
      * @param LoopType	The type of loop to apply (if "yoyo", it will go backwards when it reached the end; otherwise it will reset).
      * @param Delay The initial delay to apply to the Tween (in seconds).
      * @param TimeScale The scale to apply to the Tween execution. If < 1 the Tween will slow down, if > 1 it will speed up. If < 0 it will make the Tween go backward.
	  * @param TweenWhileGameIsPaused Sets whether the Tween should keep updating while the game is paused. Useful for Tween on UMG widgets that animate menus.
	  * @param SequenceIndex The index of the sequence in which the new Tween should be added (hidden in Blueprint).
      */
    UFUNCTION(BlueprintCallable, meta = (DisplayName="Create Tween Move Widget By", KeyWords="Tween Move Widget UMG By Create", AdvancedDisplay=7, HidePin=SequenceIndex), Category = "Tween|StandardTween|UMG|Move")
    static void BP_CreateTweenMoveWidgetBy(UTweenManagerComponent* TweenManager,
                                           UWidget* TweenTarget,
                                           UTweenContainer*& TweenContainer,
                                           UTweenVector2D*& Tween,
                                           FVector2D By,
                                           float Duration              = 1.0f,
                                           ETweenEaseType EaseType     = ETweenEaseType::Linear,
                                           int32 NumLoops              = 1,
                                           ETweenLoopType LoopType     = ETweenLoopType::Yoyo,
                                           float Delay                 = 0.0f,
                                           float TimeScale             = 1.0f,
                                           bool TweenWhileGameIsPaused = false,
                                           int32 SequenceIndex         = -1);


    /**
      * Creates a Tween that scales a UMG widget from its current scale (at the start of the Tween) to the given size.
      * With this function a new TweenContainer will be created, which will hold any other Tween appended/joined to this one.
      *
      * @param TweenManager (optional) The TweenManager that will handle the Tween. If none is passed, the global TweenManagerActor will be used if present.
      * @param TweenTarget The Widget to scale.
      * @param TweenContainer The TweenContainer that owns the Tween.
      * @param Tween The created Tween.
      * @param To The ending value.
      * @param Duration The total duration of the Tween (in seconds).
      * @param EaseType	The easing functions to apply.
      * @param NumLoops	The number of times the Tween should repeat. If <= 0, it will loop indefinitely.
      * @param LoopType	The type of loop to apply (if "yoyo", it will go backwards when it reached the end; otherwise it will reset).
      * @param Delay The initial delay to apply to the Tween (in seconds).
      * @param TimeScale The scale to apply to the Tween execution. If < 1 the Tween will slow down, if > 1 it will speed up. If < 0 it will make the Tween go backward.
	  * @param TweenWhileGameIsPaused Sets whether the Tween should keep updating while the game is paused. Useful for Tween on UMG widgets that animate menus.
	  * @param SequenceIndex The index of the sequence in which the new Tween should be added (hidden in Blueprint).
      */
    UFUNCTION(BlueprintCallable, meta = (DisplayName="Create Tween Scale Widget To", KeyWords="Tween Scale Widget UMG To Create", AdvancedDisplay=7, HidePin=SequenceIndex), Category = "Tween|StandardTween|UMG|Scale")
    static void BP_CreateTweenScaleWidgetTo(UTweenManagerComponent* TweenManager,
                                            UWidget* TweenTarget,
                                            UTweenContainer*& TweenContainer,
                                            UTweenVector2D*& Tween,
                                            FVector2D To,
                                            float Duration              = 1.0f,
                                            ETweenEaseType EaseType     = ETweenEaseType::Linear,
                                            int32 NumLoops              = 1,
                                            ETweenLoopType LoopType     = ETweenLoopType::Yoyo,
                                            float Delay                 = 0.0f,
                                            float TimeScale             = 1.0f,
                                            bool TweenWhileGameIsPaused = false,
                                            int32 SequenceIndex         = -1);

    /**
      * Creates a Tween that scales a UMG widget by the given offset with respect to its current size (at the start of the Tween).
      * With this function a new TweenContainer will be created, which will hold any other Tween appended/joined to this one.
      *
      * @param TweenManager (optional) The TweenManager that will handle the Tween. If none is passed, the global TweenManagerActor will be used if present.
      * @param TweenTarget The Widget to scale.
      * @param TweenContainer The TweenContainer that owns the Tween.
      * @param Tween The created Tween.
      * @param By The offset to apply.
      * @param Duration The total duration of the Tween (in seconds).
      * @param EaseType	The easing functions to apply.
      * @param NumLoops	The number of times the Tween should repeat. If <= 0, it will loop indefinitely.
      * @param LoopType	The type of loop to apply (if "yoyo", it will go backwards when it reached the end; otherwise it will reset).
      * @param Delay The initial delay to apply to the Tween (in seconds).
      * @param TimeScale The scale to apply to the Tween execution. If < 1 the Tween will slow down, if > 1 it will speed up. If < 0 it will make the Tween go backward.
	  * @param TweenWhileGameIsPaused Sets whether the Tween should keep updating while the game is paused. Useful for Tween on UMG widgets that animate menus.
	  * @param SequenceIndex The index of the sequence in which the new Tween should be added (hidden in Blueprint).
      */
    UFUNCTION(BlueprintCallable, meta = (DisplayName="Create Tween Scale Widget By", KeyWords="Tween Scale Widget UMG By Create", AdvancedDisplay=7, HidePin=SequenceIndex), Category = "Tween|StandardTween|UMG|Scale")
    static void BP_CreateTweenScaleWidgetBy(UTweenManagerComponent* TweenManager,
                                            UWidget* TweenTarget,
                                            UTweenContainer*& TweenContainer,
                                            UTweenVector2D*& Tween,
                                            FVector2D By,
                                            float Duration              = 1.0f,
                                            ETweenEaseType EaseType     = ETweenEaseType::Linear,
                                            int32 NumLoops              = 1,
                                            ETweenLoopType LoopType     = ETweenLoopType::Yoyo,
                                            float Delay                 = 0.0f,
                                            float TimeScale             = 1.0f,
                                            bool TweenWhileGameIsPaused = false,
                                            int32 SequenceIndex         = -1);


    /**
      * Creates a Tween that modifies a UMG widget's shear value from its current value (at the start of the Tween) to the given ending value.
      * With this function a new TweenContainer will be created, which will hold any other Tween appended/joined to this one.
      *
      * @param TweenManager (optional) The TweenManager that will handle the Tween. If none is passed, the global TweenManagerActor will be used if present.
      * @param TweenTarget The Widget to shear.
      * @param TweenContainer The TweenContainer that owns the Tween.
      * @param Tween The created Tween.
      * @param To The ending value.
      * @param Duration The total duration of the Tween (in seconds).
      * @param EaseType	The easing functions to apply.
      * @param NumLoops	The number of times the Tween should repeat. If <= 0, it will loop indefinitely.
      * @param LoopType	The type of loop to apply (if "yoyo", it will go backwards when it reached the end; otherwise it will reset).
      * @param Delay The initial delay to apply to the Tween (in seconds).
      * @param TimeScale The scale to apply to the Tween execution. If < 1 the Tween will slow down, if > 1 it will speed up. If < 0 it will make the Tween go backward.
	  * @param TweenWhileGameIsPaused Sets whether the Tween should keep updating while the game is paused. Useful for Tween on UMG widgets that animate menus.
	  * @param SequenceIndex The index of the sequence in which the new Tween should be added (hidden in Blueprint).
      */
    UFUNCTION(BlueprintCallable, meta = (DisplayName="Create Tween Shear Widget To", KeyWords="Tween Shear Widget UMG To Create", AdvancedDisplay=7, HidePin=SequenceIndex), Category = "Tween|StandardTween|UMG|Shear")
    static void BP_CreateTweenShearWidgetTo(UTweenManagerComponent* TweenManager,
                                            UWidget* TweenTarget,
                                            UTweenContainer*& TweenContainer,
                                            UTweenVector2D*& Tween,
                                            FVector2D To,
                                            float Duration              = 1.0f,
                                            ETweenEaseType EaseType     = ETweenEaseType::Linear,
                                            int32 NumLoops              = 1,
                                            ETweenLoopType LoopType     = ETweenLoopType::Yoyo,
                                            float Delay                 = 0.0f,
                                            float TimeScale             = 1.0f,
                                            bool TweenWhileGameIsPaused = false,
                                            int32 SequenceIndex         = -1);

    /**
      * Creates a custom Tween that goes from a starting value to an ending one. This type of Tween is meant for creating custom behaviours
      * by binding a function or an event to the OnTweenUpdate delegate in order to use the tweened value at each Tick by calling GetCurrentValue from the Tween object.
      * With this function a new TweenContainer will be created, which will hold any other Tween appended/joined to this one.

      * @param TweenManager (optional) The TweenManager that will handle the Tween. If none is passed, the global TweenManagerActor will be used if present.
      * @param TweenTarget The target of the tween. Can be anything, as long as it's not null.
      * @param TweenContainer The TweenContainer that owns the Tween.
      * @param Tween The created Tween.
      * @param From The starting value.
      * @param To The ending value.
      * @param Duration The total duration of the Tween (in seconds).
      * @param EaseType	The easing functions to apply.
      * @param NumLoops	The number of times the Tween should repeat. If <= 0, it will loop indefinitely.
      * @param LoopType	The type of loop to apply (if "yoyo", it will go backwards when it reached the end; otherwise it will reset).
      * @param Delay The initial delay to apply to the Tween (in seconds).
      * @param TimeScale The scale to apply to the Tween execution. If < 1 the Tween will slow down, if > 1 it will speed up. If < 0 it will make the Tween go backward.
	  * @param TweenWhileGameIsPaused Sets whether the Tween should keep updating while the game is paused. Useful for Tween on UMG widgets that animate menus.
	  * @param SequenceIndex The index of the sequence in which the new Tween should be added (hidden in Blueprint).
      */
    UFUNCTION(BlueprintCallable, meta = (DisplayName="Create Tween Custom Vector2D", KeyWords="Tween Custom Vector2D Create", AdvancedDisplay=8, HidePin=SequenceIndex), Category = "Tween|StandardTween|Custom")
    static void BP_CreateTweenCustomVector2D(UTweenManagerComponent* TweenManager,
                                             UObject* TweenTarget,
                                             UTweenContainer*& TweenContainer,
                                             UTweenVector2D*& Tween,
                                             FVector2D From,
                                             FVector2D To,
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
      * Appends to the TweenContainer a Tween that moves a UMG widget from its current location (at the start of the Tween) to the given location.
      * It will be executed when all previous Tweens in the TweenContainer are completed.
      *
      * @param TweenContainer The TweenContainer that will own the new Tween.
      * @param TweenTarget The Widget to move.
      * @param To The ending value.
      * @param Duration The total duration of the Tween (in seconds).
      * @param EaseType	The easing functions to apply.
      * @param NumLoops	The number of times the Tween should repeat. If <= 0, it will loop indefinitely.
      * @param LoopType	The type of loop to apply (if "yoyo", it will go backwards when it reached the end; otherwise it will reset).
      * @param Delay The initial delay to apply to the Tween (in seconds).
      * @param TimeScale The scale to apply to the Tween execution. If < 1 the Tween will slow down, if > 1 it will speed up. If < 0 it will make the Tween go backward.
	  * @param TweenWhileGameIsPaused Sets whether the Tween should keep updating while the game is paused. Useful for Tween on UMG widgets that animate menus.
	  * @param SequenceIndex The index of the sequence in which the new Tween should be added (hidden in Blueprint).
      *
      * @return The newly created Tween.
      */
    UFUNCTION(BlueprintCallable, meta = (DisplayName="Append Tween Move Widget To", KeyWords="Tween Move Widget UMG To Append Sequence", AdvancedDisplay=5, HidePin=SequenceIndex), Category = "Tween|StandardTween|UMG|Move")
    static UTweenVector2D* BP_AppendTweenMoveWidgetTo(UTweenContainer* TweenContainer,
                                                      UWidget* TweenTarget,
                                                      FVector2D To,
                                                      float Duration              = 1.0f,
                                                      ETweenEaseType EaseType     = ETweenEaseType::Linear,
                                                      int32 NumLoops              = 1,
                                                      ETweenLoopType LoopType     = ETweenLoopType::Yoyo,
                                                      float Delay                 = 0.0f,
                                                      float TimeScale             = 1.0f,
                                                      bool TweenWhileGameIsPaused = false,
                                                      int32 SequenceIndex         = -1);

    /**
      * Appends to the TweenContainer a Tween that moves a UMG widget by the given offset with respect to its current location (at the start of the Tween).
      * It will be executed when all previous Tweens in the TweenContainer are completed.
      *
      * @param TweenContainer The TweenContainer that will own the new Tween.
      * @param TweenTarget The Widget to move.
      * @param By The offset to apply.
      * @param Duration The total duration of the Tween (in seconds).
      * @param EaseType	The easing functions to apply.
      * @param NumLoops	The number of times the Tween should repeat. If <= 0, it will loop indefinitely.
      * @param LoopType	The type of loop to apply (if "yoyo", it will go backwards when it reached the end; otherwise it will reset).
      * @param Delay The initial delay to apply to the Tween (in seconds).
      * @param TimeScale The scale to apply to the Tween execution. If < 1 the Tween will slow down, if > 1 it will speed up. If < 0 it will make the Tween go backward.
	  * @param TweenWhileGameIsPaused Sets whether the Tween should keep updating while the game is paused. Useful for Tween on UMG widgets that animate menus.
	  * @param SequenceIndex The index of the sequence in which the new Tween should be added (hidden in Blueprint).
      *
      * @return The newly created Tween.
      */
    UFUNCTION(BlueprintCallable, meta = (DisplayName="Append Tween Move Widget By", KeyWords="Tween Move Widget UMG By Append Sequence", AdvancedDisplay=5, HidePin=SequenceIndex), Category = "Tween|StandardTween|UMG|Move")
    static UTweenVector2D* BP_AppendTweenMoveWidgetBy(UTweenContainer* TweenContainer,
                                                      UWidget* TweenTarget,
                                                      FVector2D By,
                                                      float Duration              = 1.0f,
                                                      ETweenEaseType EaseType     = ETweenEaseType::Linear,
                                                      int32 NumLoops              = 1,
                                                      ETweenLoopType LoopType     = ETweenLoopType::Yoyo,
                                                      float Delay                 = 0.0f,
                                                      float TimeScale             = 1.0f,
                                                      bool TweenWhileGameIsPaused = false,
                                                      int32 SequenceIndex         = -1);


    /**
      * Appends to the TweenContainer a Tween that moves a UMG widget from its current scale (at the start of the Tween) to the given size.
      * It will be executed when all previous Tweens in the TweenContainer are completed.
      *
      * @param TweenContainer The TweenContainer that will own the new Tween.
      * @param TweenTarget The Widget to scale.
      * @param To The ending value.
      * @param Duration The total duration of the Tween (in seconds).
      * @param EaseType	The easing functions to apply.
      * @param NumLoops	The number of times the Tween should repeat. If <= 0, it will loop indefinitely.
      * @param LoopType	The type of loop to apply (if "yoyo", it will go backwards when it reached the end; otherwise it will reset).
      * @param Delay The initial delay to apply to the Tween (in seconds).
      * @param TimeScale The scale to apply to the Tween execution. If < 1 the Tween will slow down, if > 1 it will speed up. If < 0 it will make the Tween go backward.
	  * @param TweenWhileGameIsPaused Sets whether the Tween should keep updating while the game is paused. Useful for Tween on UMG widgets that animate menus.
	  * @param SequenceIndex The index of the sequence in which the new Tween should be added (hidden in Blueprint).
      *
      * @return The newly created Tween.
      */
    UFUNCTION(BlueprintCallable, meta = (DisplayName="Append Tween Scale Widget To", KeyWords="Tween Scale Widget UMG To Append Sequence", AdvancedDisplay=5, HidePin=SequenceIndex), Category = "Tween|StandardTween|UMG|Scale")
    static UTweenVector2D* BP_AppendTweenScaleWidgetTo(UTweenContainer* TweenContainer,
                                                       UWidget* TweenTarget,
                                                       FVector2D To,
                                                       float Duration              = 1.0f,
                                                       ETweenEaseType EaseType     = ETweenEaseType::Linear,
                                                       int32 NumLoops              = 1,
                                                       ETweenLoopType LoopType     = ETweenLoopType::Yoyo,
                                                       float Delay                 = 0.0f,
                                                       float TimeScale             = 1.0f,
                                                       bool TweenWhileGameIsPaused = false,
                                                       int32 SequenceIndex         = -1);

    /**
      * Appends to the TweenContainer a Tween that scales a UMG widget by the given offset with respect to its current size (at the start of the Tween).
      * It will be executed when all previous Tweens in the TweenContainer are completed.
      *
      * @param TweenContainer The TweenContainer that will own the new Tween.
      * @param TweenTarget The Widget to scale.
      * @param By The offset to apply.
      * @param Duration The total duration of the Tween (in seconds).
      * @param EaseType	The easing functions to apply.
      * @param NumLoops	The number of times the Tween should repeat. If <= 0, it will loop indefinitely.
      * @param LoopType	The type of loop to apply (if "yoyo", it will go backwards when it reached the end; otherwise it will reset).
      * @param Delay The initial delay to apply to the Tween (in seconds).
      * @param TimeScale The scale to apply to the Tween execution. If < 1 the Tween will slow down, if > 1 it will speed up. If < 0 it will make the Tween go backward.
	  * @param TweenWhileGameIsPaused Sets whether the Tween should keep updating while the game is paused. Useful for Tween on UMG widgets that animate menus.
	  * @param SequenceIndex The index of the sequence in which the new Tween should be added (hidden in Blueprint).
      *
      * @return The newly created Tween.
      */
    UFUNCTION(BlueprintCallable, meta = (DisplayName="Append Tween Scale Widget By", KeyWords="Tween Scale Widget UMG By Append Sequence", AdvancedDisplay=5, HidePin=SequenceIndex), Category = "Tween|StandardTween|UMG|Scale")
    static UTweenVector2D* BP_AppendTweenScaleWidgetBy(UTweenContainer* TweenContainer,
                                                       UWidget* TweenTarget,
                                                       FVector2D By,
                                                       float Duration              = 1.0f,
                                                       ETweenEaseType EaseType     = ETweenEaseType::Linear,
                                                       int32 NumLoops              = 1,
                                                       ETweenLoopType LoopType     = ETweenLoopType::Yoyo,
                                                       float Delay                 = 0.0f,
                                                       float TimeScale             = 1.0f,
                                                       bool TweenWhileGameIsPaused = false,
                                                       int32 SequenceIndex         = -1);

    /**
      * Appends to the TweenContainer a Tween that modifies a UMG widget's shear value from its current value (at the start of the Tween) to the given ending value.
      * It will be executed when all previous Tweens in the TweenContainer are completed.
      *
      * @param TweenContainer The TweenContainer that will own the new Tween.
      * @param TweenTarget The Widget to shear.
      * @param To The ending value.
      * @param Duration The total duration of the Tween (in seconds).
      * @param EaseType	The easing functions to apply.
      * @param NumLoops	The number of times the Tween should repeat. If <= 0, it will loop indefinitely.
      * @param LoopType	The type of loop to apply (if "yoyo", it will go backwards when it reached the end; otherwise it will reset).
      * @param Delay The initial delay to apply to the Tween (in seconds).
      * @param TimeScale The scale to apply to the Tween execution. If < 1 the Tween will slow down, if > 1 it will speed up. If < 0 it will make the Tween go backward.
	  * @param TweenWhileGameIsPaused Sets whether the Tween should keep updating while the game is paused. Useful for Tween on UMG widgets that animate menus.
	  * @param SequenceIndex The index of the sequence in which the new Tween should be added (hidden in Blueprint).
      *
      * @return The newly created Tween.
      */
    UFUNCTION(BlueprintCallable, meta = (DisplayName="Append Tween Shear Widget To", KeyWords="Tween Shear Widget UMG To Append Sequence", AdvancedDisplay=5, HidePin=SequenceIndex), Category = "Tween|StandardTween|UMG|Shear")
    static UTweenVector2D* BP_AppendTweenShearWidgetTo(UTweenContainer* TweenContainer,
                                                       UWidget* TweenTarget,
                                                       FVector2D To,
                                                       float Duration              = 1.0f,
                                                       ETweenEaseType EaseType     = ETweenEaseType::Linear,
                                                       int32 NumLoops              = 1,
                                                       ETweenLoopType LoopType     = ETweenLoopType::Yoyo,
                                                       float Delay                 = 0.0f,
                                                       float TimeScale             = 1.0f,
                                                       bool TweenWhileGameIsPaused = false,
                                                       int32 SequenceIndex         = -1);

    /**
      * Appends to the TweenContainer a custom Tween that goes from a starting value to an ending one. This type of Tween is meant for creating custom behaviours
      * by binding a function or an event to the OnTweenUpdate delegate in order to use the tweened value at each Tick by calling GetCurrentValue from the Tween object.
      * The Tween will be executed when all Tweens before it are completed.
      *
      * @param TweenContainer The TweenContainer that will own the new Tween.
      * @param TweenTarget The target of the tween. Can be anything, as long as it's not null.
      * @param From The starting value.
      * @param To The ending value.
      * @param Duration The total duration of the Tween (in seconds).
      * @param EaseType	The easing functions to apply.
      * @param NumLoops	The number of times the Tween should repeat. If <= 0, it will loop indefinitely.
      * @param LoopType	The type of loop to apply (if "yoyo", it will go backwards when it reached the end; otherwise it will reset).
      * @param Delay The initial delay to apply to the Tween (in seconds).
      * @param TimeScale The scale to apply to the Tween execution. If < 1 the Tween will slow down, if > 1 it will speed up. If < 0 it will make the Tween go backward.
	  * @param TweenWhileGameIsPaused Sets whether the Tween should keep updating while the game is paused. Useful for Tween on UMG widgets that animate menus.
	  * @param SequenceIndex The index of the sequence in which the new Tween should be added (hidden in Blueprint).
      *
      * @return The newly created Tween.
      */
    UFUNCTION(BlueprintCallable, meta = (DisplayName="Append Tween Custom Vector2D", KeyWords="Tween Custom Vector2D Append Sequence", AdvancedDisplay=6, HidePin=SequenceIndex), Category = "Tween|StandardTween|Custom")
    static UTweenVector2D* BP_AppendTweenCustomVector2D(UTweenContainer* TweenContainer,
                                                        UObject* TweenTarget,
                                                        FVector2D From,
                                                        FVector2D To,
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
      * Joins to the TweenContainer a Tween that moves a UMG widget from its current location (at the start of the Tween) to the given location.
      * It will be executed in parallel with the last appended Tween in the TweenContainer.
      *
      * @param TweenContainer The TweenContainer that will own the new Tween.
      * @param TweenTarget The Widget to move.
      * @param To The ending value.
      * @param Duration The total duration of the Tween (in seconds).
      * @param EaseType	The easing functions to apply.
      * @param Delay The initial delay to apply to the Tween (in seconds).
      * @param TimeScale The scale to apply to the Tween execution. If < 1 the Tween will slow down, if > 1 it will speed up. If < 0 it will make the Tween go backward.
	  * @param TweenWhileGameIsPaused Sets whether the Tween should keep updating while the game is paused. Useful for Tween on UMG widgets that animate menus.
	  * @param SequenceIndex The index of the sequence in which the new Tween should be added (hidden in Blueprint).
      *
      * @return The newly created Tween.
      */
    UFUNCTION(BlueprintCallable, meta = (DisplayName="Join Tween Move Widget To", KeyWords="Tween Move Widget UMG To Join Parallel", AdvancedDisplay=5, HidePin=SequenceIndex), Category = "Tween|StandardTween|UMG|Move")
    static UTweenVector2D* BP_JoinTweenMoveWidgetTo(UTweenContainer* TweenContainer,
                                                    UWidget* TweenTarget,
                                                    FVector2D To,
                                                    float Duration              = 1.0f,
                                                    ETweenEaseType EaseType     = ETweenEaseType::Linear,
                                                    float Delay                 = 0.0f,
                                                    float TimeScale             = 1.0f,
                                                    bool TweenWhileGameIsPaused = false,
                                                    int32 SequenceIndex         = -1);

    /**
      * Joins to the TweenContainer a Tween that moves a UMG widget by the given offset with respect to its current location (at the start of the Tween).
      * It will be executed in parallel with the last appended Tween in the TweenContainer.
      *
      * @param TweenContainer The TweenContainer that will own the new Tween.
      * @param TweenTarget The Widget to move.
      * @param By The offset to apply.
      * @param Duration The total duration of the Tween (in seconds).
      * @param EaseType	The easing functions to apply.
      * @param Delay The initial delay to apply to the Tween (in seconds).
      * @param TimeScale The scale to apply to the Tween execution. If < 1 the Tween will slow down, if > 1 it will speed up. If < 0 it will make the Tween go backward.
	  * @param TweenWhileGameIsPaused Sets whether the Tween should keep updating while the game is paused. Useful for Tween on UMG widgets that animate menus.
	  * @param SequenceIndex The index of the sequence in which the new Tween should be added (hidden in Blueprint).
      *
      * @return The newly created Tween.
      */
    UFUNCTION(BlueprintCallable, meta = (DisplayName="Join Tween Move Widget By", KeyWords="Tween Move Widget UMG By Join Parallel", AdvancedDisplay=5, HidePin=SequenceIndex), Category = "Tween|StandardTween|UMG|Move")
    static UTweenVector2D* BP_JoinTweenMoveWidgetBy(UTweenContainer* TweenContainer,
                                                    UWidget* TweenTarget,
                                                    FVector2D By,
                                                    float Duration              = 1.0f,
                                                    ETweenEaseType EaseType     = ETweenEaseType::Linear,
                                                    float Delay                 = 0.0f,
                                                    float TimeScale             = 1.0f,
                                                    bool TweenWhileGameIsPaused = false,
                                                    int32 SequenceIndex         = -1);

    /**
      * Joins to the TweenContainer a Tween that moves a UMG widget from its current scale (at the start of the Tween) to the given size.
      * It will be executed in parallel with the last appended Tween in the TweenContainer.
      *
      * @param TweenContainer The TweenContainer that will own the new Tween.
      * @param TweenTarget The Widget to scale.
      * @param To The ending value.
      * @param Duration The total duration of the Tween (in seconds).
      * @param EaseType	The easing functions to apply.
      * @param Delay The initial delay to apply to the Tween (in seconds).
      * @param TimeScale The scale to apply to the Tween execution. If < 1 the Tween will slow down, if > 1 it will speed up. If < 0 it will make the Tween go backward.
	  * @param TweenWhileGameIsPaused Sets whether the Tween should keep updating while the game is paused. Useful for Tween on UMG widgets that animate menus.
	  * @param SequenceIndex The index of the sequence in which the new Tween should be added (hidden in Blueprint).
      *
      * @return The newly created Tween.
      */
    UFUNCTION(BlueprintCallable, meta = (DisplayName="Join Tween Scale Widget To", KeyWords="Tween Scale Widget UMG To Join Parallel", AdvancedDisplay=5, HidePin=SequenceIndex), Category = "Tween|StandardTween|UMG|Scale")
    static UTweenVector2D* BP_JoinTweenScaleWidgetTo(UTweenContainer* TweenContainer,
                                                     UWidget* TweenTarget,
                                                     FVector2D To,
                                                     float Duration              = 1.0f,
                                                     ETweenEaseType EaseType     = ETweenEaseType::Linear,
                                                     float Delay                 = 0.0f,
                                                     float TimeScale             = 1.0f,
                                                     bool TweenWhileGameIsPaused = false,
                                                     int32 SequenceIndex         = -1);

    /**
      * Joins to the TweenContainer a Tween that scales a UMG widget by the given offset with respect to its current size (at the start of the Tween).
      * It will be executed in parallel with the last appended Tween in the TweenContainer.
      *
      * @param TweenContainer The TweenContainer that will own the new Tween.
      * @param TweenTarget The Widget to scale.
      * @param By The offset to apply.
      * @param Duration The total duration of the Tween (in seconds).
      * @param EaseType	The easing functions to apply.
      * @param Delay The initial delay to apply to the Tween (in seconds).
      * @param TimeScale The scale to apply to the Tween execution. If < 1 the Tween will slow down, if > 1 it will speed up. If < 0 it will make the Tween go backward.
	  * @param TweenWhileGameIsPaused Sets whether the Tween should keep updating while the game is paused. Useful for Tween on UMG widgets that animate menus.
	  * @param SequenceIndex The index of the sequence in which the new Tween should be added (hidden in Blueprint).
      *
      * @return The newly created Tween.
      */
    UFUNCTION(BlueprintCallable, meta = (DisplayName="Join Tween Scale Widget By", KeyWords="Tween Scale Widget UMG By Join Parallel", AdvancedDisplay=5, HidePin=SequenceIndex), Category = "Tween|StandardTween|UMG|Scale")
    static UTweenVector2D* BP_JoinTweenScaleWidgetBy(UTweenContainer* TweenContainer,
                                                     UWidget* TweenTarget,
                                                     FVector2D By,
                                                     float Duration              = 1.0f,
                                                     ETweenEaseType EaseType     = ETweenEaseType::Linear,
                                                     float Delay                 = 0.0f,
                                                     float TimeScale             = 1.0f,
                                                     bool TweenWhileGameIsPaused = false,
                                                     int32 SequenceIndex         = -1);

    /**
      * Joins to the TweenContainer a Tween that modifies a UMG widget's shear value from its current value (at the start of the Tween) to the given ending value.
      * It will be executed in parallel with the last appended Tween in the TweenContainer.
      *
      * @param TweenContainer The TweenContainer that will own the new Tween.
      * @param TweenTarget The Widget to shear.
      * @param To The ending value.
      * @param Duration The total duration of the Tween (in seconds).
      * @param EaseType	The easing functions to apply.
      * @param Delay The initial delay to apply to the Tween (in seconds).
      * @param TimeScale The scale to apply to the Tween execution. If < 1 the Tween will slow down, if > 1 it will speed up. If < 0 it will make the Tween go backward.
	  * @param TweenWhileGameIsPaused Sets whether the Tween should keep updating while the game is paused. Useful for Tween on UMG widgets that animate menus.
	  * @param SequenceIndex The index of the sequence in which the new Tween should be added (hidden in Blueprint).
      *
      * @return The newly created Tween.
      */
    UFUNCTION(BlueprintCallable, meta = (DisplayName="Join Tween Shear Widget To", KeyWords="Tween Shear Widget UMG To Join Parallel", AdvancedDisplay=5, HidePin=SequenceIndex), Category = "Tween|StandardTween|UMG|Shear")
    static UTweenVector2D* BP_JoinTweenShearWidgetTo(UTweenContainer* TweenContainer,
                                                     UWidget* TweenTarget,
                                                     FVector2D To,
                                                     float Duration              = 1.0f,
                                                     ETweenEaseType EaseType     = ETweenEaseType::Linear,
                                                     float Delay                 = 0.0f,
                                                     float TimeScale             = 1.0f,
                                                     bool TweenWhileGameIsPaused = false,
                                                     int32 SequenceIndex         = -1);

    /**
      * Joins to the TweenContainer a custom Tween that goes from a starting value to an ending one. This type of Tween is meant for creating custom behaviours
      * by binding a function or an event to the OnTweenUpdate delegate in order to use the tweened value at each Tick by calling GetCurrentValue from the Tween object.
      * It will be executed in parallel with the last appended Tween in the TweenContainer.
      *
      * @param TweenContainer The TweenContainer that will own the new Tween.
      * @param TweenTarget The target of the tween. Can be anything, as long as it's not null.
      * @param From The starting value.
      * @param To The ending value.
      * @param Duration The total duration of the Tween (in seconds).
      * @param EaseType	The easing functions to apply.
      * @param Delay The initial delay to apply to the Tween (in seconds).
      * @param TimeScale The scale to apply to the Tween execution. If < 1 the Tween will slow down, if > 1 it will speed up. If < 0 it will make the Tween go backward.
	  * @param TweenWhileGameIsPaused Sets whether the Tween should keep updating while the game is paused. Useful for Tween on UMG widgets that animate menus.
	  * @param SequenceIndex The index of the sequence in which the new Tween should be added (hidden in Blueprint).
      *
      * @return The newly created Tween.
      */
    UFUNCTION(BlueprintCallable, meta = (DisplayName="Join Tween Custom Vector2D", KeyWords="Tween Custom Vector2D Join Parallel", AdvancedDisplay=6, HidePin=SequenceIndex), Category = "Tween|StandardTween|Custom")
    static UTweenVector2D* BP_JoinTweenCustomVector2D(UTweenContainer* TweenContainer,
                                                      UObject* TweenTarget,
                                                      FVector2D From,
                                                      FVector2D To,
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

    static UTweenVector2D* CreateAppendTweenVector2D(UTweenContainer* pTweenContainer,
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
                                                     int32 pSequenceIndex);

    static UTweenVector2D* CreateJoinTweenVector2D(UTweenContainer* pTweenContainer,
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
                                                   int32 pSequenceIndex);
};
