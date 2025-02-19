// Copyright 2018 Francesco Desogus. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "TweenManagerComponent.h"
#include "Utils/TweenEnums.h"
#include "Tweens/TweenVector.h"

#include "TweenVectorStandardFactory.generated.h"

class ATweenManagerActor;
class UTweenManagerComponent;
class UTweenContainer;
class UBaseTween;


/**
 * @brief The UTweenVectorStandardFactory class handles the creation of all vector related Tweens, i.e. all tweens that
 *        in order to be executed they need to change a single vector value.
 *
 *        The methods here are "standard", meaning that if the user wishes to use one of the tween callbacks (OnTweenStart,
 *        OnTweenUpdate, OnTweenEnd) he has to manually bind the delegates.
 */
UCLASS()
class TWEENMAKER_API UTweenVectorStandardFactory : public UObject
{
    GENERATED_BODY()

public:
    
    /**
     * @brief Constructor.
     */
    UTweenVectorStandardFactory(const FObjectInitializer& ObjectInitializer);

    /*
     **************************************************************************
     * "Create" methods
     **************************************************************************
     */

    /**
      * Creates a Tween that moves an Actor from its current location (at the start of the Tween) to the given location.
      * With this function a new TweenContainer will be created, which will hold any other Tween appended/joined to this one.
      *
      * @param TweenManager (optional) The TweenManager that will handle the Tween. If none is passed, the global TweenManagerActor will be used if present.
      * @param TweenTarget The Actor to move.
      * @param TweenContainer The TweenContainer that owns the Tween.
      * @param Tween The created Tween.
      * @param To The ending value.
      * @param Duration The total duration of the Tween (in seconds).
      * @param EaseType	The easing functions to apply.
      * @param TweenSpace The space in which the Tween makes its update (i.e. 'world' or 'relative').
      * @param DeleteTweenOnHit If true the Tween will be deleted when the TweenTarget hits something.
      * @param DeleteTweenOnOverlap If true the Tween will be deleted when the TweenTarget overlaps something.
      * @param NumLoops	The number of times the Tween should repeat. If <= 0, it will loop indefinitely.
      * @param LoopType	The type of loop to apply (if "yoyo", it will go backwards when it reached the end; otherwise it will reset).
      * @param Delay The initial delay to apply to the Tween (in seconds).
      * @param TimeScale The scale to apply to the Tween execution. If < 1 the Tween will slow down, if > 1 it will speed up. If < 0 it will make the Tween go backward.
	  * @param TweenWhileGameIsPaused Sets whether the Tween should keep updating while the game is paused. Useful for Tween on UMG widgets that animate menus.
	  * @param SequenceIndex The index of the sequence in which the new Tween should be added (hidden in Blueprint).
      */
    UFUNCTION(BlueprintCallable, meta = (DisplayName="Create Tween Move Actor To", KeyWords="Create Tween Move Actor To", AdvancedDisplay=7, HidePin=SequenceIndex), Category = "Tween|StandardTween|Actor|Move")
    static void BP_CreateTweenMoveActorTo(UTweenManagerComponent* TweenManager,
                                          AActor* TweenTarget,
                                          UTweenContainer*& TweenContainer,
                                          UTweenVector*& Tween,
                                          FVector To,
                                          float Duration              = 1.0f,
                                          ETweenEaseType EaseType     = ETweenEaseType::Linear,
                                          ETweenSpace TweenSpace      = ETweenSpace::World,
                                          bool DeleteTweenOnHit       = false,
                                          bool DeleteTweenOnOverlap   = false,
                                          int32 NumLoops              = 1,
                                          ETweenLoopType LoopType     = ETweenLoopType::Yoyo,
                                          float Delay                 = 0.0f,
                                          float TimeScale             = 1.0f,
                                          bool TweenWhileGameIsPaused = false,
                                          int32 SequenceIndex         = -1);

    /**
      * Creates a Tween that moves an Actor by the given offset with respect to its current location (at the start of the Tween).
      * With this function a new TweenContainer will be created, which will hold any other Tween appended/joined to this one.
      *
      * @param TweenManager (optional) The TweenManager that will handle the Tween. If none is passed, the global TweenManagerActor will be used if present.
      * @param TweenTarget The Actor to move.
      * @param TweenContainer The TweenContainer that owns the Tween.
      * @param Tween The created Tween.
      * @param By The offset to apply.
      * @param Duration The total duration of the Tween (in seconds).
      * @param EaseType	The easing functions to apply.
      * @param DeleteTweenOnHit If true the Tween will be deleted when the TweenTarget hits something.
      * @param DeleteTweenOnOverlap If true the Tween will be deleted when the TweenTarget overlaps something.
      * @param NumLoops	The number of times the Tween should repeat. If <= 0, it will loop indefinitely.
      * @param LoopType	The type of loop to apply (if "yoyo", it will go backwards when it reached the end; otherwise it will reset).
      * @param Delay The initial delay to apply to the Tween (in seconds).
      * @param TimeScale The scale to apply to the Tween execution. If < 1 the Tween will slow down, if > 1 it will speed up. If < 0 it will make the Tween go backward.
	  * @param TweenWhileGameIsPaused Sets whether the Tween should keep updating while the game is paused. Useful for Tween on UMG widgets that animate menus.
	  * @param SequenceIndex The index of the sequence in which the new Tween should be added (hidden in Blueprint).
      */
    UFUNCTION(BlueprintCallable, meta = (DisplayName="Create Tween Move Actor By", KeyWords="Tween Move Actor By Create", AdvancedDisplay=7, HidePin=SequenceIndex), Category = "Tween|StandardTween|Actor|Move")
    static void BP_CreateTweenMoveActorBy(UTweenManagerComponent* TweenManager,
                                          AActor* TweenTarget,
                                          UTweenContainer*& TweenContainer,
                                          UTweenVector*& Tween,
                                          FVector By,
                                          float Duration              = 1.0f,
                                          ETweenEaseType EaseType     = ETweenEaseType::Linear,
                                          bool DeleteTweenOnHit       = false,
                                          bool DeleteTweenOnOverlap   = false,
                                          int32 NumLoops              = 1,
                                          ETweenLoopType LoopType     = ETweenLoopType::Yoyo,
                                          float Delay                 = 0.0f,
                                          float TimeScale             = 1.0f,
                                          bool TweenWhileGameIsPaused = false,
                                          int32 SequenceIndex         = -1);

    /**
      * Creates a Tween that scales an Actor from its current scale (at the start of the Tween) to the given size.
      * With this function a new TweenContainer will be created, which will hold any other Tween appended/joined to this one.
      *
      * @param TweenManager (optional) The TweenManager that will handle the Tween. If none is passed, the global TweenManagerActor will be used if present.
      * @param TweenTarget The Actor to move.
      * @param TweenContainer The TweenContainer that owns the Tween.
      * @param Tween The created Tween.
      * @param To The ending value.
      * @param Duration The total duration of the Tween (in seconds).
      * @param EaseType	The easing functions to apply.
      * @param TweenSpace The space in which the Tween makes its update (i.e. 'world' or 'relative').
      * @param DeleteTweenOnHit If true the Tween will be deleted when the TweenTarget hits something.
      * @param DeleteTweenOnOverlap If true the Tween will be deleted when the TweenTarget overlaps something.
      * @param NumLoops	The number of times the Tween should repeat. If <= 0, it will loop indefinitely.
      * @param LoopType	The type of loop to apply (if "yoyo", it will go backwards when it reached the end; otherwise it will reset).
      * @param Delay The initial delay to apply to the Tween (in seconds).
      * @param TimeScale The scale to apply to the Tween execution. If < 1 the Tween will slow down, if > 1 it will speed up. If < 0 it will make the Tween go backward.
	  * @param TweenWhileGameIsPaused Sets whether the Tween should keep updating while the game is paused. Useful for Tween on UMG widgets that animate menus.
	  * @param SequenceIndex The index of the sequence in which the new Tween should be added (hidden in Blueprint).
      */
    UFUNCTION(BlueprintCallable, meta = (DisplayName="Create Tween Scale Actor To", KeyWords="Tween Scale Actor To Create", AdvancedDisplay=7, HidePin=SequenceIndex), Category = "Tween|StandardTween|Actor|Scale")
    static void BP_CreateTweenScaleActorTo(UTweenManagerComponent* TweenManager,
                                           AActor* TweenTarget,
                                           UTweenContainer*& TweenContainer,
                                           UTweenVector*& Tween,
                                           FVector To,
                                           float Duration              = 1.0f,
                                           ETweenEaseType EaseType     = ETweenEaseType::Linear,
                                           ETweenSpace TweenSpace      = ETweenSpace::World,
                                           bool DeleteTweenOnHit       = false,
                                           bool DeleteTweenOnOverlap   = false,
                                           int32 NumLoops              = 1,
                                           ETweenLoopType LoopType     = ETweenLoopType::Yoyo,
                                           float Delay                 = 0.0f,
                                           float TimeScale             = 1.0f,
                                           bool TweenWhileGameIsPaused = false,
                                           int32 SequenceIndex         = -1);

    /**
      * Creates a Tween that scales an Actor by the given offset with respect to its current size (at the start of the Tween).
      * With this function a new TweenContainer will be created, which will hold any other Tween appended/joined to this one.
      *
      * @param TweenManager (optional) The TweenManager that will handle the Tween. If none is passed, the global TweenManagerActor will be used if present.
      * @param TweenTarget The Actor to move.
      * @param TweenContainer The TweenContainer that owns the Tween.
      * @param Tween The created Tween.
      * @param By The offset to apply.
      * @param Duration The total duration of the Tween (in seconds).
      * @param EaseType	The easing functions to apply.
      * @param DeleteTweenOnHit If true the Tween will be deleted when the TweenTarget hits something.
      * @param DeleteTweenOnOverlap If true the Tween will be deleted when the TweenTarget overlaps something.
      * @param NumLoops	The number of times the Tween should repeat. If <= 0, it will loop indefinitely.
      * @param LoopType	The type of loop to apply (if "yoyo", it will go backwards when it reached the end; otherwise it will reset).
      * @param Delay The initial delay to apply to the Tween (in seconds).
      * @param TimeScale The scale to apply to the Tween execution. If < 1 the Tween will slow down, if > 1 it will speed up. If < 0 it will make the Tween go backward.
	  * @param TweenWhileGameIsPaused Sets whether the Tween should keep updating while the game is paused. Useful for Tween on UMG widgets that animate menus.
	  * @param SequenceIndex The index of the sequence in which the new Tween should be added (hidden in Blueprint).
      */
    UFUNCTION(BlueprintCallable, meta = (DisplayName="Create Tween Scale Actor By", KeyWords="Tween Scale Actor By Create", AdvancedDisplay=7, HidePin=SequenceIndex), Category = "Tween|StandardTween|Actor|Scale")
    static void BP_CreateTweenScaleActorBy(UTweenManagerComponent* TweenManager,
                                           AActor* TweenTarget,
                                           UTweenContainer*& TweenContainer,
                                           UTweenVector*& Tween,
                                           FVector By,
                                           float Duration              = 1.0f,
                                           ETweenEaseType EaseType     = ETweenEaseType::Linear,
                                           bool DeleteTweenOnHit       = false,
                                           bool DeleteTweenOnOverlap   = false,
                                           int32 NumLoops              = 1,
                                           ETweenLoopType LoopType     = ETweenLoopType::Yoyo,
                                           float Delay                 = 0.0f,
                                           float TimeScale             = 1.0f,
                                           bool TweenWhileGameIsPaused = false,
                                           int32 SequenceIndex         = -1);


    /**
      * Creates a Tween that moves a SceneComponent from its current location (at the start of the Tween) to the given location.
      * With this function a new TweenContainer will be created, which will hold any other Tween appended/joined to this one.
      *
      * @param TweenManager (optional) The TweenManager that will handle the Tween. If none is passed, the global TweenManagerActor will be used if present.
      * @param TweenTarget The SceneComponent to move.
      * @param TweenContainer The TweenContainer that owns the Tween.
      * @param Tween The created Tween.
      * @param To The ending value.
      * @param Duration The total duration of the Tween (in seconds).
      * @param EaseType	The easing functions to apply.
      * @param TweenSpace The space in which the Tween makes its update (i.e. 'world' or 'relative').
      * @param DeleteTweenOnHit If true the Tween will be deleted when the TweenTarget hits something.
      * @param DeleteTweenOnOverlap If true the Tween will be deleted when the TweenTarget overlaps something.
      * @param NumLoops	The number of times the Tween should repeat. If <= 0, it will loop indefinitely.
      * @param LoopType	The type of loop to apply (if "yoyo", it will go backwards when it reached the end; otherwise it will reset).
      * @param Delay The initial delay to apply to the Tween (in seconds).
      * @param TimeScale The scale to apply to the Tween execution. If < 1 the Tween will slow down, if > 1 it will speed up. If < 0 it will make the Tween go backward.
	  * @param TweenWhileGameIsPaused Sets whether the Tween should keep updating while the game is paused. Useful for Tween on UMG widgets that animate menus.
	  * @param SequenceIndex The index of the sequence in which the new Tween should be added (hidden in Blueprint).
      */
    UFUNCTION(BlueprintCallable, meta = (DisplayName="Create Tween Move Scene Component To", KeyWords="Tween Move Scene Component To Create", AdvancedDisplay=7, HidePin=SequenceIndex), Category = "Tween|StandardTween|SceneComponent|Move")
    static void BP_CreateTweenMoveSceneComponentTo(UTweenManagerComponent* TweenManager,
                                                   USceneComponent* TweenTarget,
                                                   UTweenContainer*& TweenContainer,
                                                   UTweenVector*& Tween,
                                                   FVector To,
                                                   float Duration              = 1.0f,
                                                   ETweenEaseType EaseType     = ETweenEaseType::Linear,
                                                   ETweenSpace TweenSpace      = ETweenSpace::World,
                                                   bool DeleteTweenOnHit       = false,
                                                   bool DeleteTweenOnOverlap   = false,
                                                   int32 NumLoops              = 1,
                                                   ETweenLoopType LoopType     = ETweenLoopType::Yoyo,
                                                   float Delay                 = 0.0f,
                                                   float TimeScale             = 1.0f,
                                                   bool TweenWhileGameIsPaused = false,
                                                   int32 SequenceIndex         = -1);


    /**
      * Creates a Tween that moves a SceneComponent by the given offset with respect to its current location (at the start of the Tween).
      * With this function a new TweenContainer will be created, which will hold any other Tween appended/joined to this one.
      *
      * @param TweenManager (optional) The TweenManager that will handle the Tween. If none is passed, the global TweenManagerActor will be used if present.
      * @param TweenTarget The SceneComponent to move.
      * @param TweenContainer The TweenContainer that owns the Tween.
      * @param Tween The created Tween.
      * @param By The offset to apply.
      * @param Duration The total duration of the Tween (in seconds).
      * @param EaseType	The easing functions to apply.
      * @param DeleteTweenOnHit If true the Tween will be deleted when the TweenTarget hits something.
      * @param DeleteTweenOnOverlap If true the Tween will be deleted when the TweenTarget overlaps something.
      * @param NumLoops	The number of times the Tween should repeat. If <= 0, it will loop indefinitely.
      * @param LoopType	The type of loop to apply (if "yoyo", it will go backwards when it reached the end; otherwise it will reset).
      * @param Delay The initial delay to apply to the Tween (in seconds).
      * @param TimeScale The scale to apply to the Tween execution. If < 1 the Tween will slow down, if > 1 it will speed up. If < 0 it will make the Tween go backward.
	  * @param TweenWhileGameIsPaused Sets whether the Tween should keep updating while the game is paused. Useful for Tween on UMG widgets that animate menus.
	  * @param SequenceIndex The index of the sequence in which the new Tween should be added (hidden in Blueprint).
      */
    UFUNCTION(BlueprintCallable, meta = (DisplayName="Create Tween Move Scene Component By", KeyWords="Tween Move Scene Component By Create", AdvancedDisplay=7, HidePin=SequenceIndex), Category = "Tween|StandardTween|SceneComponent|Move")
    static void BP_CreateTweenMoveSceneComponentBy(UTweenManagerComponent* TweenManager,
                                                   USceneComponent* TweenTarget,
                                                   UTweenContainer*& TweenContainer,
                                                   UTweenVector*& Tween,
                                                   FVector By,
                                                   float Duration              = 1.0f,
                                                   ETweenEaseType EaseType     = ETweenEaseType::Linear,
                                                   bool DeleteTweenOnHit       = false,
                                                   bool DeleteTweenOnOverlap   = false,
                                                   int32 NumLoops              = 1,
                                                   ETweenLoopType LoopType     = ETweenLoopType::Yoyo,
                                                   float Delay                 = 0.0f,
                                                   float TimeScale             = 1.0f,
                                                   bool TweenWhileGameIsPaused = false,
                                                   int32 SequenceIndex         = -1);

    /**
      * Creates a Tween that scales a SceneComponent from its current scale (at the start of the Tween) to the given size.
      * With this function a new TweenContainer will be created, which will hold any other Tween appended/joined to this one.
      *
      * @param TweenManager (optional) The TweenManager that will handle the Tween. If none is passed, the global TweenManagerActor will be used if present.
      * @param TweenTarget The SceneComponent to move.
      * @param TweenContainer The TweenContainer that owns the Tween.
      * @param Tween The created Tween.
      * @param To The ending value.
      * @param Duration The total duration of the Tween (in seconds).
      * @param EaseType	The easing functions to apply.
      * @param TweenSpace The space in which the Tween makes its update (i.e. 'world' or 'relative').
      * @param DeleteTweenOnHit If true the Tween will be deleted when the TweenTarget hits something.
      * @param DeleteTweenOnOverlap If true the Tween will be deleted when the TweenTarget overlaps something.
      * @param NumLoops	The number of times the Tween should repeat. If <= 0, it will loop indefinitely.
      * @param LoopType	The type of loop to apply (if "yoyo", it will go backwards when it reached the end; otherwise it will reset).
      * @param Delay The initial delay to apply to the Tween (in seconds).
      * @param TimeScale The scale to apply to the Tween execution. If < 1 the Tween will slow down, if > 1 it will speed up. If < 0 it will make the Tween go backward.
	  * @param TweenWhileGameIsPaused Sets whether the Tween should keep updating while the game is paused. Useful for Tween on UMG widgets that animate menus.
	  * @param SequenceIndex The index of the sequence in which the new Tween should be added (hidden in Blueprint).
      */
    UFUNCTION(BlueprintCallable, meta = (DisplayName="Create Tween Scale Scene Component To", KeyWords="Tween Scale Scene To Component Create", AdvancedDisplay=7, HidePin=SequenceIndex), Category = "Tween|StandardTween|SceneComponent|Scale")
    static void BP_CreateTweenScaleSceneComponentTo(UTweenManagerComponent* TweenManager,
                                                    USceneComponent* TweenTarget,
                                                    UTweenContainer*& TweenContainer,
                                                    UTweenVector*& Tween,
                                                    FVector To,
                                                    float Duration              = 1.0f,
                                                    ETweenEaseType EaseType     = ETweenEaseType::Linear,
                                                    ETweenSpace TweenSpace      = ETweenSpace::World,
                                                    bool DeleteTweenOnHit       = false,
                                                    bool DeleteTweenOnOverlap   = false,
                                                    int32 NumLoops              = 1,
                                                    ETweenLoopType LoopType     = ETweenLoopType::Yoyo,
                                                    float Delay                 = 0.0f,
                                                    float TimeScale             = 1.0f,
                                                    bool TweenWhileGameIsPaused = false,
                                                    int32 SequenceIndex         = -1);

    /**
      * Creates a Tween that scales a SceneComponent by the given offset with respect to its current size (at the start of the Tween).
      * With this function a new TweenContainer will be created, which will hold any other Tween appended/joined to this one.

      * @param TweenManager (optional) The TweenManager that will handle the Tween. If none is passed, the global TweenManagerActor will be used if present.
      * @param TweenTarget The SceneComponent to move.
      * @param TweenContainer The TweenContainer that owns the Tween.
      * @param Tween The created Tween.
      * @param By The offset to apply.
      * @param Duration The total duration of the Tween (in seconds).
      * @param EaseType	The easing functions to apply.
      * @param DeleteTweenOnHit If true the Tween will be deleted when the TweenTarget hits something.
      * @param DeleteTweenOnOverlap If true the Tween will be deleted when the TweenTarget overlaps something.
      * @param NumLoops	The number of times the Tween should repeat. If <= 0, it will loop indefinitely.
      * @param LoopType	The type of loop to apply (if "yoyo", it will go backwards when it reached the end; otherwise it will reset).
      * @param Delay The initial delay to apply to the Tween (in seconds).
      * @param TimeScale The scale to apply to the Tween execution. If < 1 the Tween will slow down, if > 1 it will speed up. If < 0 it will make the Tween go backward.
	  * @param TweenWhileGameIsPaused Sets whether the Tween should keep updating while the game is paused. Useful for Tween on UMG widgets that animate menus.
	  * @param SequenceIndex The index of the sequence in which the new Tween should be added (hidden in Blueprint).
      */
    UFUNCTION(BlueprintCallable, meta = (DisplayName="Create Tween Scale Scene Component By", KeyWords="Tween Scale Scene Component By Create", AdvancedDisplay=7, HidePin=SequenceIndex), Category = "Tween|StandardTween|SceneComponent|Scale")
    static void BP_CreateTweenScaleSceneComponentBy(UTweenManagerComponent* TweenManager,
                                                    USceneComponent* TweenTarget,
                                                    UTweenContainer*& TweenContainer,
                                                    UTweenVector*& Tween,
                                                    FVector By,
                                                    float Duration              = 1.0f,
                                                    ETweenEaseType EaseType     = ETweenEaseType::Linear,
                                                    bool DeleteTweenOnHit       = false,
                                                    bool DeleteTweenOnOverlap   = false,
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
    UFUNCTION(BlueprintCallable, meta = (DisplayName="Create Tween Custom Vector", KeyWords="Tween Custom Vector Create", AdvancedDisplay=8, HidePin=SequenceIndex), Category = "Tween|StandardTween|Custom")
    static void BP_CreateTweenCustomVector(UTweenManagerComponent* TweenManager,
                                           UObject* TweenTarget,
                                           UTweenContainer*& TweenContainer,
                                           UTweenVector*& Tween,
                                           FVector From,
                                           FVector To,
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
      * Appends to the TweenContainer a Tween that moves an Actor from its current location (at the start of the Tween) to the given location.
      * It will be executed when all previous Tweens in the TweenContainer are completed.
      *
      * @param TweenContainer The TweenContainer that will own the new Tween.
      * @param TweenTarget The Actor to move.
      * @param To The ending value.
      * @param Duration The total duration of the Tween (in seconds).
      * @param EaseType	The easing functions to apply.
      * @param TweenSpace The space in which the Tween makes its update (i.e. 'world' or 'relative').
      * @param DeleteTweenOnHit If true the Tween will be deleted when the TweenTarget hits something.
      * @param DeleteTweenOnOverlap If true the Tween will be deleted when the TweenTarget overlaps something.
      * @param NumLoops	The number of times the Tween should repeat. If <= 0, it will loop indefinitely.
      * @param LoopType	The type of loop to apply (if "yoyo", it will go backwards when it reached the end; otherwise it will reset).
      * @param Delay The initial delay to apply to the Tween (in seconds).
      * @param TimeScale The scale to apply to the Tween execution. If < 1 the Tween will slow down, if > 1 it will speed up. If < 0 it will make the Tween go backward.
	  * @param TweenWhileGameIsPaused Sets whether the Tween should keep updating while the game is paused. Useful for Tween on UMG widgets that animate menus.
	  * @param SequenceIndex The index of the sequence in which the new Tween should be added (hidden in Blueprint).
      *
      * @return The newly created Tween.
      */
    UFUNCTION(BlueprintCallable, meta = (DisplayName="Append Tween Move Actor To", KeyWords="Tween Move Actor To Append Sequence", AdvancedDisplay=5, HidePin=SequenceIndex), Category = "Tween|StandardTween|Actor|Move")
    static UTweenVector* BP_AppendTweenMoveActorTo(UTweenContainer* TweenContainer,
                                                   AActor* TweenTarget,
                                                   FVector To,
                                                   float Duration              = 1.0f,
                                                   ETweenEaseType EaseType     = ETweenEaseType::Linear,
                                                   ETweenSpace TweenSpace      = ETweenSpace::World,
                                                   bool DeleteTweenOnHit       = false,
                                                   bool DeleteTweenOnOverlap   = false,
                                                   int32 NumLoops              = 1,
                                                   ETweenLoopType LoopType     = ETweenLoopType::Yoyo,
                                                   float Delay                 = 0.0f,
                                                   float TimeScale             = 1.0f,
                                                   bool TweenWhileGameIsPaused = false,
                                                   int32 SequenceIndex         = -1);

    /**
      * Appends to the TweenContainer a Tween that moves an Actor by the given offset with respect to its current location (at the start of the Tween).
      * It will be executed when all previous Tweens in the TweenContainer are completed.
      *
      * @param TweenContainer The TweenContainer that will own the new Tween.
      * @param TweenTarget The Actor to move.
      * @param By The offset to apply.
      * @param Duration The total duration of the Tween (in seconds).
      * @param EaseType	The easing functions to apply.
      * @param DeleteTweenOnHit If true the Tween will be deleted when the TweenTarget hits something.
      * @param DeleteTweenOnOverlap If true the Tween will be deleted when the TweenTarget overlaps something.
      * @param NumLoops	The number of times the Tween should repeat. If <= 0, it will loop indefinitely.
      * @param LoopType	The type of loop to apply (if "yoyo", it will go backwards when it reached the end; otherwise it will reset).
      * @param Delay The initial delay to apply to the Tween (in seconds).
      * @param TimeScale The scale to apply to the Tween execution. If < 1 the Tween will slow down, if > 1 it will speed up. If < 0 it will make the Tween go backward.
	  * @param TweenWhileGameIsPaused Sets whether the Tween should keep updating while the game is paused. Useful for Tween on UMG widgets that animate menus.
	  * @param SequenceIndex The index of the sequence in which the new Tween should be added (hidden in Blueprint).
      *
      * @return The newly created Tween.
      */
    UFUNCTION(BlueprintCallable, meta = (DisplayName="Append Tween Move Actor By", KeyWords="Tween Move Actor By Append Sequence", AdvancedDisplay=5, HidePin=SequenceIndex), Category = "Tween|StandardTween|Actor|Move")
    static UTweenVector* BP_AppendTweenMoveActorBy(UTweenContainer* TweenContainer,
                                                   AActor* TweenTarget,
                                                   FVector By,
                                                   float Duration              = 1.0f,
                                                   ETweenEaseType EaseType     = ETweenEaseType::Linear,
                                                   bool DeleteTweenOnHit       = false,
                                                   bool DeleteTweenOnOverlap   = false,
                                                   int32 NumLoops              = 1,
                                                   ETweenLoopType LoopType     = ETweenLoopType::Yoyo,
                                                   float Delay                 = 0.0f,
                                                   float TimeScale             = 1.0f,
                                                   bool TweenWhileGameIsPaused = false,
                                                   int32 SequenceIndex         = -1);

    /**
      * Appends to the TweenContainer a Tween that scales an Actor from its current scale (at the start of the Tween) to the given size.
      * It will be executed when all previous Tweens in the TweenContainer are completed.
      *
      * @param TweenContainer The TweenContainer that will own the new Tween.
      * @param TweenTarget The Actor to move.
      * @param To The ending value.
      * @param Duration The total duration of the Tween (in seconds).
      * @param EaseType	The easing functions to apply.
      * @param TweenSpace The space in which the Tween makes its update (i.e. 'world' or 'relative').
      * @param DeleteTweenOnHit If true the Tween will be deleted when the TweenTarget hits something.
      * @param DeleteTweenOnOverlap If true the Tween will be deleted when the TweenTarget overlaps something.
      * @param NumLoops	The number of times the Tween should repeat. If <= 0, it will loop indefinitely.
      * @param LoopType	The type of loop to apply (if "yoyo", it will go backwards when it reached the end; otherwise it will reset).
      * @param Delay The initial delay to apply to the Tween (in seconds).
      * @param TimeScale The scale to apply to the Tween execution. If < 1 the Tween will slow down, if > 1 it will speed up. If < 0 it will make the Tween go backward.
	  * @param TweenWhileGameIsPaused Sets whether the Tween should keep updating while the game is paused. Useful for Tween on UMG widgets that animate menus.
	  * @param SequenceIndex The index of the sequence in which the new Tween should be added (hidden in Blueprint).
      *
      * @return The newly created Tween.
      */
    UFUNCTION(BlueprintCallable, meta = (DisplayName="Append Tween Scale Actor To", KeyWords="Tween Scale Actor To Append Sequence", AdvancedDisplay=5, HidePin=SequenceIndex), Category = "Tween|StandardTween|Actor|Scale")
    static UTweenVector* BP_AppendTweenScaleActorTo(UTweenContainer* TweenContainer,
                                                    AActor* TweenTarget,
                                                    FVector To,
                                                    float Duration              = 1.0f,
                                                    ETweenEaseType EaseType     = ETweenEaseType::Linear,
                                                    ETweenSpace TweenSpace      = ETweenSpace::World,
                                                    bool DeleteTweenOnHit       = false,
                                                    bool DeleteTweenOnOverlap   = false,
                                                    int32 NumLoops              = 1,
                                                    ETweenLoopType LoopType     = ETweenLoopType::Yoyo,
                                                    float Delay                 = 0.0f,
                                                    float TimeScale             = 1.0f,
                                                    bool TweenWhileGameIsPaused = false,
                                                    int32 SequenceIndex         = -1);

    /**
      * Appends to the TweenContainer a Tween that scales an Actor by the given offset with respect to its current size (at the start of the Tween).
      * It will be executed when all previous Tweens in the TweenContainer are completed.

      * @param TweenContainer The TweenContainer that will own the new Tween.
      * @param TweenTarget The Actor to move.
      * @param By The offset to apply.
      * @param Duration The total duration of the Tween (in seconds).
      * @param EaseType	The easing functions to apply.
      * @param DeleteTweenOnHit If true the Tween will be deleted when the TweenTarget hits something.
      * @param DeleteTweenOnOverlap If true the Tween will be deleted when the TweenTarget overlaps something.
      * @param NumLoops	The number of times the Tween should repeat. If <= 0, it will loop indefinitely.
      * @param LoopType	The type of loop to apply (if "yoyo", it will go backwards when it reached the end; otherwise it will reset).
      * @param Delay The initial delay to apply to the Tween (in seconds).
      * @param TimeScale The scale to apply to the Tween execution. If < 1 the Tween will slow down, if > 1 it will speed up. If < 0 it will make the Tween go backward.
	  * @param TweenWhileGameIsPaused Sets whether the Tween should keep updating while the game is paused. Useful for Tween on UMG widgets that animate menus.
	  * @param SequenceIndex The index of the sequence in which the new Tween should be added (hidden in Blueprint).
      *
      * @return The newly created Tween.
      */
    UFUNCTION(BlueprintCallable, meta = (DisplayName="Append Tween Scale Actor By", KeyWords="Tween Scale Actor By Append Sequence", AdvancedDisplay=5, HidePin=SequenceIndex), Category = "Tween|StandardTween|Actor|Scale")
    static UTweenVector* BP_AppendTweenScaleActorBy(UTweenContainer* TweenContainer,
                                                    AActor* TweenTarget,
                                                    FVector By,
                                                    float Duration              = 1.0f,
                                                    ETweenEaseType EaseType     = ETweenEaseType::Linear,
                                                    bool DeleteTweenOnHit       = false,
                                                    bool DeleteTweenOnOverlap   = false,
                                                    int32 NumLoops              = 1,
                                                    ETweenLoopType LoopType     = ETweenLoopType::Yoyo,
                                                    float Delay                 = 0.0f,
                                                    float TimeScale             = 1.0f,
                                                    bool TweenWhileGameIsPaused = false,
                                                    int32 SequenceIndex         = -1);

    /**
      * Appends to the TweenContainer a Tween that moves a SceneComponent from its current location (at the start of the Tween) to the given location.
      * It will be executed when all previous Tweens in the TweenContainer are completed.
      *
      * @param TweenContainer The TweenContainer that will own the new Tween.
      * @param TweenTarget The SceneComponent to move.
      * @param To The ending value.
      * @param Duration The total duration of the Tween (in seconds).
      * @param EaseType	The easing functions to apply.
      * @param TweenSpace The space in which the Tween makes its update (i.e. 'world' or 'relative').
      * @param DeleteTweenOnHit If true the Tween will be deleted when the TweenTarget hits something.
      * @param DeleteTweenOnOverlap If true the Tween will be deleted when the TweenTarget overlaps something.
      * @param NumLoops	The number of times the Tween should repeat. If <= 0, it will loop indefinitely.
      * @param LoopType	The type of loop to apply (if "yoyo", it will go backwards when it reached the end; otherwise it will reset).
      * @param Delay The initial delay to apply to the Tween (in seconds).
      * @param TimeScale The scale to apply to the Tween execution. If < 1 the Tween will slow down, if > 1 it will speed up. If < 0 it will make the Tween go backward.
	  * @param TweenWhileGameIsPaused Sets whether the Tween should keep updating while the game is paused. Useful for Tween on UMG widgets that animate menus.
	  * @param SequenceIndex The index of the sequence in which the new Tween should be added (hidden in Blueprint).
      *
      * @return The newly created Tween.
      */
    UFUNCTION(BlueprintCallable, meta = (DisplayName="Append Tween Move Scene Component To", KeyWords="Tween Move Scene Component To Append Sequence", AdvancedDisplay=5, HidePin=SequenceIndex), Category = "Tween|StandardTween|SceneComponent|Move")
    static UTweenVector* BP_AppendTweenMoveSceneComponentTo(UTweenContainer* TweenContainer,
                                                            USceneComponent* TweenTarget,
                                                            FVector To,
                                                            float Duration              = 1.0f,
                                                            ETweenEaseType EaseType     = ETweenEaseType::Linear,
                                                            ETweenSpace TweenSpace      = ETweenSpace::World,
                                                            bool DeleteTweenOnHit       = false,
                                                            bool DeleteTweenOnOverlap   = false,
                                                            int32 NumLoops              = 1,
                                                            ETweenLoopType LoopType     = ETweenLoopType::Yoyo,
                                                            float Delay                 = 0.0f,
                                                            float TimeScale             = 1.0f,
                                                            bool TweenWhileGameIsPaused = false,
                                                            int32 SequenceIndex         = -1);

    /**
      * Appends to the TweenContainer a Tween that moves a SceneComponent by the given offset with respect to its current location (at the start of the Tween).
      * It will be executed when all previous Tweens in the TweenContainer are completed.
      *
      * @param TweenContainer The TweenContainer that will own the new Tween.
      * @param TweenTarget The SceneComponent to move.
      * @param By The offset to apply.
      * @param Duration The total duration of the Tween (in seconds).
      * @param EaseType	The easing functions to apply.
      * @param DeleteTweenOnHit If true the Tween will be deleted when the TweenTarget hits something.
      * @param DeleteTweenOnOverlap If true the Tween will be deleted when the TweenTarget overlaps something.
      * @param NumLoops	The number of times the Tween should repeat. If <= 0, it will loop indefinitely.
      * @param LoopType	The type of loop to apply (if "yoyo", it will go backwards when it reached the end; otherwise it will reset).
      * @param Delay The initial delay to apply to the Tween (in seconds).
      * @param TimeScale The scale to apply to the Tween execution. If < 1 the Tween will slow down, if > 1 it will speed up. If < 0 it will make the Tween go backward.
	  * @param TweenWhileGameIsPaused Sets whether the Tween should keep updating while the game is paused. Useful for Tween on UMG widgets that animate menus.
	  * @param SequenceIndex The index of the sequence in which the new Tween should be added (hidden in Blueprint).
      *
      * @return The newly created Tween.
      */
    UFUNCTION(BlueprintCallable, meta = (DisplayName="Append Tween Move Scene Component By", KeyWords="Tween Move Scene Component By Append Sequence", AdvancedDisplay=5, HidePin=SequenceIndex), Category = "Tween|StandardTween|SceneComponent|Move")
    static UTweenVector* BP_AppendTweenMoveSceneComponentBy(UTweenContainer* TweenContainer,
                                                            USceneComponent* TweenTarget,
                                                            FVector By,
                                                            float Duration              = 1.0f,
                                                            ETweenEaseType EaseType     = ETweenEaseType::Linear,
                                                            bool DeleteTweenOnHit       = false,
                                                            bool DeleteTweenOnOverlap   = false,
                                                            int32 NumLoops              = 1,
                                                            ETweenLoopType LoopType     = ETweenLoopType::Yoyo,
                                                            float Delay                 = 0.0f,
                                                            float TimeScale             = 1.0f,
                                                            bool TweenWhileGameIsPaused = false,
                                                            int32 SequenceIndex         = -1);

    /**
      * Appends to the TweenContainer a Tween that scales a SceneComponent from its current scale (at the start of the Tween) to the given size.
      * It will be executed when all previous Tweens in the TweenContainer are completed.
      *
      * @param TweenContainer The TweenContainer that will own the new Tween.
      * @param TweenTarget The SceneComponent to move.
      * @param To The ending value.
      * @param Duration The total duration of the Tween (in seconds).
      * @param EaseType	The easing functions to apply.
      * @param TweenSpace The space in which the Tween makes its update (i.e. 'world' or 'relative').
      * @param DeleteTweenOnHit If true the Tween will be deleted when the TweenTarget hits something.
      * @param DeleteTweenOnOverlap If true the Tween will be deleted when the TweenTarget overlaps something.
      * @param NumLoops	The number of times the Tween should repeat. If <= 0, it will loop indefinitely.
      * @param LoopType	The type of loop to apply (if "yoyo", it will go backwards when it reached the end; otherwise it will reset).
      * @param Delay The initial delay to apply to the Tween (in seconds).
      * @param TimeScale The scale to apply to the Tween execution. If < 1 the Tween will slow down, if > 1 it will speed up. If < 0 it will make the Tween go backward.
	  * @param TweenWhileGameIsPaused Sets whether the Tween should keep updating while the game is paused. Useful for Tween on UMG widgets that animate menus.
	  * @param SequenceIndex The index of the sequence in which the new Tween should be added (hidden in Blueprint).
      *
      * @return The newly created Tween.
      */
    UFUNCTION(BlueprintCallable, meta = (DisplayName="Append Tween Scale Scene Component To", KeyWords="Tween Scale Scene Component To Append Sequence", AdvancedDisplay=5, HidePin=SequenceIndex), Category = "Tween|StandardTween|SceneComponent|Scale")
    static UTweenVector* BP_AppendTweenScaleSceneComponentTo(UTweenContainer* TweenContainer,
                                                             USceneComponent* TweenTarget,
                                                             FVector To,
                                                             float Duration              = 1.0f,
                                                             ETweenEaseType EaseType     = ETweenEaseType::Linear,
                                                             ETweenSpace TweenSpace      = ETweenSpace::World,
                                                             bool DeleteTweenOnHit       = false,
                                                             bool DeleteTweenOnOverlap   = false,
                                                             int32 NumLoops              = 1,
                                                             ETweenLoopType LoopType     = ETweenLoopType::Yoyo,
                                                             float Delay                 = 0.0f,
                                                             float TimeScale             = 1.0f,
                                                             bool TweenWhileGameIsPaused = false,
                                                             int32 SequenceIndex         = -1);

    /**
      * Appends to the TweenContainer a Tween that scales a SceneComponent by the given offset with respect to its current size (at the start of the Tween).
      * It will be executed when all previous Tweens in the TweenContainer are completed.

      * @param TweenContainer The TweenContainer that will own the new Tween.
      * @param TweenTarget The SceneComponent to move.
      * @param By The offset to apply.
      * @param Duration The total duration of the Tween (in seconds).
      * @param EaseType	The easing functions to apply.
      * @param DeleteTweenOnHit If true the Tween will be deleted when the TweenTarget hits something.
      * @param DeleteTweenOnOverlap If true the Tween will be deleted when the TweenTarget overlaps something.
      * @param NumLoops	The number of times the Tween should repeat. If <= 0, it will loop indefinitely.
      * @param LoopType	The type of loop to apply (if "yoyo", it will go backwards when it reached the end; otherwise it will reset).
      * @param Delay The initial delay to apply to the Tween (in seconds).
      * @param TimeScale The scale to apply to the Tween execution. If < 1 the Tween will slow down, if > 1 it will speed up. If < 0 it will make the Tween go backward.
	  * @param TweenWhileGameIsPaused Sets whether the Tween should keep updating while the game is paused. Useful for Tween on UMG widgets that animate menus.
	  * @param SequenceIndex The index of the sequence in which the new Tween should be added (hidden in Blueprint).
      *
      * @return The newly created Tween.
      */
    UFUNCTION(BlueprintCallable, meta = (DisplayName="Append Tween Scale Scene Component By", KeyWords="Tween Scale Scene Component By Append Sequence", AdvancedDisplay=5, HidePin=SequenceIndex), Category = "Tween|StandardTween|SceneComponent|Scale")
    static UTweenVector* BP_AppendTweenScaleSceneComponentBy(UTweenContainer* TweenContainer,
                                                             USceneComponent* TweenTarget,
                                                             FVector By,
                                                             float Duration              = 1.0f,
                                                             ETweenEaseType EaseType     = ETweenEaseType::Linear,
                                                             bool DeleteTweenOnHit       = false,
                                                             bool DeleteTweenOnOverlap   = false,
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
    UFUNCTION(BlueprintCallable, meta = (DisplayName="Append Tween Custom Vector", KeyWords="Tween Custom Vector Append Sequence", AdvancedDisplay=6, HidePin=SequenceIndex), Category = "Tween|StandardTween|Custom")
    static UTweenVector* BP_AppendTweenCustomVector(UTweenContainer* TweenContainer,
                                                    UObject* TweenTarget,
                                                    FVector From,
                                                    FVector To,
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
      * Joins to the TweenContainer a Tween that moves an Actor by the given offset with respect to its current location (at the start of the Tween).
      * It will be executed in parallel with the last appended Tween in the TweenContainer.
      *
      * @param TweenContainer The TweenContainer that will own the new Tween.
      * @param TweenTarget The Actor to move.
      * @param To The ending value.
      * @param Duration The total duration of the Tween (in seconds).
      * @param EaseType	The easing functions to apply.
      * @param TweenSpace The space in which the Tween makes its update (i.e. 'world' or 'relative').
      * @param DeleteTweenOnHit If true the Tween will be deleted when the TweenTarget hits something.
      * @param DeleteTweenOnOverlap If true the Tween will be deleted when the TweenTarget overlaps something.
      * @param Delay The initial delay to apply to the Tween (in seconds).
      * @param TimeScale The scale to apply to the Tween execution. If < 1 the Tween will slow down, if > 1 it will speed up. If < 0 it will make the Tween go backward.
	  * @param TweenWhileGameIsPaused Sets whether the Tween should keep updating while the game is paused. Useful for Tween on UMG widgets that animate menus.
	  * @param SequenceIndex The index of the sequence in which the new Tween should be added (hidden in Blueprint).
      *
      * @return The newly created Tween.
      */
    UFUNCTION(BlueprintCallable, meta = (DisplayName="Join Tween Move Actor To", KeyWords="Tween Move Actor To Join Parallel", AdvancedDisplay=5, HidePin=SequenceIndex), Category = "Tween|StandardTween|Actor|Move")
    static UTweenVector* BP_JoinTweenMoveActorTo(UTweenContainer* TweenContainer,
                                                 AActor* TweenTarget,
                                                 FVector To,
                                                 float Duration              = 1.0f,
                                                 ETweenEaseType EaseType     = ETweenEaseType::Linear,
                                                 ETweenSpace TweenSpace      = ETweenSpace::World,
                                                 bool DeleteTweenOnHit       = false,
                                                 bool DeleteTweenOnOverlap   = false,
                                                 float Delay                 = 0.0f,
                                                 float TimeScale             = 1.0f,
                                                 bool TweenWhileGameIsPaused = false,
                                                 int32 SequenceIndex         = -1);

    /**
      * Joins to the TweenContainer a Tween that moves an Actor by the given offset with respect to its current location (at the start of the Tween).
      * It will be executed in parallel with the last appended Tween in the TweenContainer.
      *
      * @param TweenContainer The TweenContainer that will own the new Tween.
      * @param TweenTarget The Actor to move.
      * @param By The offset to apply.
      * @param Duration The total duration of the Tween (in seconds).
      * @param EaseType	The easing functions to apply.
      * @param DeleteTweenOnHit If true the Tween will be deleted when the TweenTarget hits something.
      * @param DeleteTweenOnOverlap If true the Tween will be deleted when the TweenTarget overlaps something.
      * @param Delay The initial delay to apply to the Tween (in seconds).
      * @param TimeScale The scale to apply to the Tween execution. If < 1 the Tween will slow down, if > 1 it will speed up. If < 0 it will make the Tween go backward.
	  * @param TweenWhileGameIsPaused Sets whether the Tween should keep updating while the game is paused. Useful for Tween on UMG widgets that animate menus.
	  * @param SequenceIndex The index of the sequence in which the new Tween should be added (hidden in Blueprint).
      *
      * @return The newly created Tween.
      */
    UFUNCTION(BlueprintCallable, meta = (DisplayName="Join Tween Move Actor By", KeyWords="Tween Move Actor By Join Parallel", AdvancedDisplay=5, HidePin=SequenceIndex), Category = "Tween|StandardTween|Actor|Move")
    static UTweenVector* BP_JoinTweenMoveActorBy(UTweenContainer* TweenContainer,
                                                 AActor* TweenTarget,
                                                 FVector By,
                                                 float Duration              = 1.0f,
                                                 ETweenEaseType EaseType     = ETweenEaseType::Linear,
                                                 bool DeleteTweenOnHit       = false,
                                                 bool DeleteTweenOnOverlap   = false,
                                                 float Delay                 = 0.0f,
                                                 float TimeScale             = 1.0f,
                                                 bool TweenWhileGameIsPaused = false,
                                                 int32 SequenceIndex         = -1);

    /**
      * Joins to the TweenContainer a Tween that scales an Actor from its current scale (at the start of the Tween) to the given size.
      * It will be executed in parallel with the last appended Tween in the TweenContainer.
      *
      * @param TweenContainer The TweenContainer that will own the new Tween.
      * @param TweenTarget The Actor to move.
      * @param To The ending value.
      * @param Duration The total duration of the Tween (in seconds).
      * @param EaseType	The easing functions to apply.
      * @param TweenSpace The space in which the Tween makes its update (i.e. 'world' or 'relative').
      * @param DeleteTweenOnHit If true the Tween will be deleted when the TweenTarget hits something.
      * @param DeleteTweenOnOverlap If true the Tween will be deleted when the TweenTarget overlaps something.
      * @param Delay The initial delay to apply to the Tween (in seconds).
      * @param TimeScale The scale to apply to the Tween execution. If < 1 the Tween will slow down, if > 1 it will speed up. If < 0 it will make the Tween go backward.
	  * @param TweenWhileGameIsPaused Sets whether the Tween should keep updating while the game is paused. Useful for Tween on UMG widgets that animate menus.
	  * @param SequenceIndex The index of the sequence in which the new Tween should be added (hidden in Blueprint).
      *
      * @return The newly created Tween.
      */
    UFUNCTION(BlueprintCallable, meta = (DisplayName="Join Tween Scale Actor To", KeyWords="Tween Scale Actor To Join Parallel", AdvancedDisplay=5, HidePin=SequenceIndex), Category = "Tween|StandardTween|Actor|Scale")
    static UTweenVector* BP_JoinTweenScaleActorTo(UTweenContainer* TweenContainer,
                                                  AActor* TweenTarget,
                                                  FVector To,
                                                  float Duration              = 1.0f,
                                                  ETweenEaseType EaseType     = ETweenEaseType::Linear,
                                                  ETweenSpace TweenSpace      = ETweenSpace::World,
                                                  bool DeleteTweenOnHit       = false,
                                                  bool DeleteTweenOnOverlap   = false,
                                                  float Delay                 = 0.0f,
                                                  float TimeScale             = 1.0f,
                                                  bool TweenWhileGameIsPaused = false,
                                                  int32 SequenceIndex         = -1);

    /**
      * Joins to the TweenContainer a Tween that scales an Actor by the given offset with respect to its current size (at the start of the Tween).
      * It will be executed in parallel with the last appended Tween in the TweenContainer.

      * @param TweenContainer The TweenContainer that will own the new Tween.
      * @param TweenTarget The Actor to move.
      * @param By The offset to apply.
      * @param Duration The total duration of the Tween (in seconds).
      * @param EaseType	The easing functions to apply.
      * @param DeleteTweenOnHit If true the Tween will be deleted when the TweenTarget hits something.
      * @param DeleteTweenOnOverlap If true the Tween will be deleted when the TweenTarget overlaps something.
      * @param Delay The initial delay to apply to the Tween (in seconds).
      * @param TimeScale The scale to apply to the Tween execution. If < 1 the Tween will slow down, if > 1 it will speed up. If < 0 it will make the Tween go backward.
	  * @param TweenWhileGameIsPaused Sets whether the Tween should keep updating while the game is paused. Useful for Tween on UMG widgets that animate menus.
	  * @param SequenceIndex The index of the sequence in which the new Tween should be added (hidden in Blueprint).
      *
      * @return The newly created Tween.
      */
    UFUNCTION(BlueprintCallable, meta = (DisplayName="Join Tween Scale Actor By", KeyWords="Tween Scale Actor By Join Parallel", AdvancedDisplay=5, HidePin=SequenceIndex), Category = "Tween|StandardTween|Actor|Scale")
    static UTweenVector* BP_JoinTweenScaleActorBy(UTweenContainer* TweenContainer,
                                                  AActor* TweenTarget,
                                                  FVector By,
                                                  float Duration              = 1.0f,
                                                  ETweenEaseType EaseType     = ETweenEaseType::Linear,
                                                  bool DeleteTweenOnHit       = false,
                                                  bool DeleteTweenOnOverlap   = false,
                                                  float Delay                 = 0.0f,
                                                  float TimeScale             = 1.0f,
                                                  bool TweenWhileGameIsPaused = false,
                                                  int32 SequenceIndex         = -1);

    /**
      * Joins to the TweenContainer a Tween that moves a SceneComponent by the given offset with respect to its current location (at the start of the Tween).
      * It will be executed in parallel with the last appended Tween in the TweenContainer.
      *
      * @param TweenContainer The TweenContainer that will own the new Tween.
      * @param TweenTarget The SceneComponent to move.
      * @param To The ending value.
      * @param Duration The total duration of the Tween (in seconds).
      * @param EaseType	The easing functions to apply.
      * @param TweenSpace The space in which the Tween makes its update (i.e. 'world' or 'relative').
      * @param DeleteTweenOnHit If true the Tween will be deleted when the TweenTarget hits something.
      * @param DeleteTweenOnOverlap If true the Tween will be deleted when the TweenTarget overlaps something.
      * @param Delay The initial delay to apply to the Tween (in seconds).
      * @param TimeScale The scale to apply to the Tween execution. If < 1 the Tween will slow down, if > 1 it will speed up. If < 0 it will make the Tween go backward.
	  * @param TweenWhileGameIsPaused Sets whether the Tween should keep updating while the game is paused. Useful for Tween on UMG widgets that animate menus.
	  * @param SequenceIndex The index of the sequence in which the new Tween should be added (hidden in Blueprint).
      *
      * @return The newly created Tween.
      */
    UFUNCTION(BlueprintCallable, meta = (DisplayName="Join Tween Move Scene Component To", KeyWords="Tween Move Scene Component To Join Parallel", AdvancedDisplay=5, HidePin=SequenceIndex), Category = "Tween|StandardTween|SceneComponent|Move")
    static UTweenVector* BP_JoinTweenMoveSceneComponentTo(UTweenContainer* TweenContainer,
                                                          USceneComponent* TweenTarget,
                                                          FVector To,
                                                          float Duration              = 1.0f,
                                                          ETweenEaseType EaseType     = ETweenEaseType::Linear,
                                                          ETweenSpace TweenSpace      = ETweenSpace::World,
                                                          bool DeleteTweenOnHit       = false,
                                                          bool DeleteTweenOnOverlap   = false,
                                                          float Delay                 = 0.0f,
                                                          float TimeScale             = 1.0f,
                                                          bool TweenWhileGameIsPaused = false,
                                                          int32 SequenceIndex         = -1);

    /**
      * Joins to the TweenContainer a Tween that moves a SceneComponent by the given offset with respect to its current location (at the start of the Tween).
      * It will be executed in parallel with the last appended Tween in the TweenContainer.
      *
      * @param TweenContainer The TweenContainer that will own the new Tween.
      * @param TweenTarget The SceneComponent to move.
      * @param By The offset to apply.
      * @param Duration The total duration of the Tween (in seconds).
      * @param EaseType	The easing functions to apply.
      * @param DeleteTweenOnHit If true the Tween will be deleted when the TweenTarget hits something.
      * @param DeleteTweenOnOverlap If true the Tween will be deleted when the TweenTarget overlaps something.
      * @param Delay The initial delay to apply to the Tween (in seconds).
      * @param TimeScale The scale to apply to the Tween execution. If < 1 the Tween will slow down, if > 1 it will speed up. If < 0 it will make the Tween go backward.
	  * @param TweenWhileGameIsPaused Sets whether the Tween should keep updating while the game is paused. Useful for Tween on UMG widgets that animate menus.
	  * @param SequenceIndex The index of the sequence in which the new Tween should be added (hidden in Blueprint).
      *
      * @return The newly created Tween.
      */
    UFUNCTION(BlueprintCallable, meta = (DisplayName="Join Tween Move Scene Component By", KeyWords="Tween Move Scene Component By Join Parallel", AdvancedDisplay=5, HidePin=SequenceIndex), Category = "Tween|StandardTween|SceneComponent|Move")
    static UTweenVector* BP_JoinTweenMoveSceneComponentBy(UTweenContainer* TweenContainer,
                                                          USceneComponent* TweenTarget,
                                                          FVector By,
                                                          float Duration              = 1.0f,
                                                          ETweenEaseType EaseType     = ETweenEaseType::Linear,
                                                          bool DeleteTweenOnHit       = false,
                                                          bool DeleteTweenOnOverlap   = false,
                                                          float Delay                 = 0.0f,
                                                          float TimeScale             = 1.0f,
                                                          bool TweenWhileGameIsPaused = false,
                                                          int32 SequenceIndex         = -1);

    /**
      * Joins to the TweenContainer a Tween that scales a SceneComponent from its current scale (at the start of the Tween) to the given size.
      * It will be executed in parallel with the last appended Tween in the TweenContainer.
      *
      * @param TweenContainer The TweenContainer that will own the new Tween.
      * @param TweenTarget The SceneComponent to move.
      * @param To The ending value.
      * @param Duration The total duration of the Tween (in seconds).
      * @param EaseType	The easing functions to apply.
      * @param TweenSpace The space in which the Tween makes its update (i.e. 'world' or 'relative').
      * @param DeleteTweenOnHit If true the Tween will be deleted when the TweenTarget hits something.
      * @param DeleteTweenOnOverlap If true the Tween will be deleted when the TweenTarget overlaps something.
      * @param Delay The initial delay to apply to the Tween (in seconds).
      * @param TimeScale The scale to apply to the Tween execution. If < 1 the Tween will slow down, if > 1 it will speed up. If < 0 it will make the Tween go backward.
	  * @param TweenWhileGameIsPaused Sets whether the Tween should keep updating while the game is paused. Useful for Tween on UMG widgets that animate menus.
	  * @param SequenceIndex The index of the sequence in which the new Tween should be added (hidden in Blueprint).
      *
      * @return The newly created Tween.
      */
    UFUNCTION(BlueprintCallable, meta = (DisplayName="Join Tween Scale Scene Component To", KeyWords="Tween Scale Scene Component To Join Parallel", AdvancedDisplay=5, HidePin=SequenceIndex), Category = "Tween|StandardTween|SceneComponent|Scale")
    static UTweenVector* BP_JoinTweenScaleSceneComponentTo(UTweenContainer* TweenContainer,
                                                           USceneComponent* TweenTarget,
                                                           FVector To,
                                                           float Duration              = 1.0f,
                                                           ETweenEaseType EaseType     = ETweenEaseType::Linear,
                                                           ETweenSpace TweenSpace      = ETweenSpace::World,
                                                           bool DeleteTweenOnHit       = false,
                                                           bool DeleteTweenOnOverlap   = false,
                                                           float Delay                 = 0.0f,
                                                           float TimeScale             = 1.0f,
                                                           bool TweenWhileGameIsPaused = false,
                                                           int32 SequenceIndex         = -1);

    /**
      * Joins to the TweenContainer a Tween that scales a SceneComponent by the given offset with respect to its current size (at the start of the Tween).
      * It will be executed in parallel with the last appended Tween in the TweenContainer.

      * @param TweenContainer The TweenContainer that will own the new Tween.
      * @param TweenTarget The SceneComponent to move.
      * @param By The offset to apply.
      * @param Duration The total duration of the Tween (in seconds).
      * @param EaseType	The easing functions to apply.
      * @param DeleteTweenOnHit If true the Tween will be deleted when the TweenTarget hits something.
      * @param DeleteTweenOnOverlap If true the Tween will be deleted when the TweenTarget overlaps something.
      * @param Delay The initial delay to apply to the Tween (in seconds).
      * @param TimeScale The scale to apply to the Tween execution. If < 1 the Tween will slow down, if > 1 it will speed up. If < 0 it will make the Tween go backward.
	  * @param TweenWhileGameIsPaused Sets whether the Tween should keep updating while the game is paused. Useful for Tween on UMG widgets that animate menus.
	  * @param SequenceIndex The index of the sequence in which the new Tween should be added (hidden in Blueprint).
      *
      * @return The newly created Tween.
      */
    UFUNCTION(BlueprintCallable, meta = (DisplayName="Join Tween Scale Scene Component By", KeyWords="Tween Scale Scene Component By Join Parallel", AdvancedDisplay=5, HidePin=SequenceIndex), Category = "Tween|StandardTween|SceneComponent|Scale")
    static UTweenVector* BP_JoinTweenScaleSceneComponentBy(UTweenContainer* TweenContainer,
                                                           USceneComponent* TweenTarget,
                                                           FVector By,
                                                           float Duration              = 1.0f,
                                                           ETweenEaseType EaseType     = ETweenEaseType::Linear,
                                                           bool DeleteTweenOnHit       = false,
                                                           bool DeleteTweenOnOverlap   = false,
                                                           float Delay                 = 0.0f,
                                                           float TimeScale             = 1.0f,
                                                           bool TweenWhileGameIsPaused = false,
                                                           int32 SequenceIndex         = -1);

    /**
      * Joins to the TweenContainer a custom Tween that goes from a starting value to an ending one. This type of Tween is meant for creating custom behaviours
      * by binding a function or an event to the OnTweenUpdate delegate in order to use the tweened value at each Tick by calling GetCurrentValue from the Tween object.
      * The Tween will be executed in parallel with all Tweens in the same sequence.
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
      *
      * @return The newly created Tween.
      */
    UFUNCTION(BlueprintCallable, meta = (DisplayName="Join Tween Custom Vector", KeyWords="Tween Custom Vector Join Parallel", AdvancedDisplay=6, HidePin=SequenceIndex), Category = "Tween|StandardTween|Custom")
    static UTweenVector* BP_JoinTweenCustomVector(UTweenContainer* TweenContainer,
                                                  UObject* TweenTarget,
                                                  FVector From,
                                                  FVector To,
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

    static UTweenVector* CreateAppendTweenVector(UTweenContainer* pTweenContainer,
                                                 ETweenVectorType pTweenType,
                                                 UObject* pTarget,
                                                 ETweenTargetType pTargetType,
                                                 const FVector& pFrom,
                                                 const FVector& pTo,
                                                 float pDuration,
                                                 ETweenEaseType pEaseType,
                                                 ETweenSpace pTweenSpace,
                                                 bool DeleteTweenOnHit,
                                                 bool DeleteTweenOnOverlap,
                                                 int32 pNumLoops,
                                                 ETweenLoopType pLoopType,
                                                 float pDelay,
                                                 float pTimeScale,
                                                 bool pTweenWhileGameIsPaused,
                                                 int32 pSequenceIndex);

    static UTweenVector* CreateJoinTweenVector(UTweenContainer* pTweenContainer,
                                               ETweenVectorType pTweenType,
                                               UObject* pTarget,
                                               ETweenTargetType pTargetType,
                                               const FVector& pFrom,
                                               const FVector& pTo,
                                               float pDuration,
                                               ETweenEaseType pEaseType,
                                               ETweenSpace pTweenSpace,
                                               bool DeleteTweenOnHit,
                                               bool DeleteTweenOnOverlap,
                                               float pDelay,
                                               float pTimeScale,
                                               bool pTweenWhileGameIsPaused,
                                               int32 pSequenceIndex);
};
