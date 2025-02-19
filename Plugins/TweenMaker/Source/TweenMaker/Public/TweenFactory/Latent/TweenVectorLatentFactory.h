// Copyright 2018 Francesco Desogus. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"

#include "Kismet/BlueprintAsyncActionBase.h"
#include "TweenManagerComponent.h"
#include "Utils/TweenEnums.h"
#include "Tweens/TweenVector.h"

#include "TweenVectorLatentFactory.generated.h"

class ATweenManagerActor;
class UTweenManagerComponent;
class UTweenContainer;
class UBaseTween;

/**
 * @brief The UTweenVectorLatentFactory class handles the creation of all vector related Tweens, i.e. all tweens that
 *        in order to be executed they need to change a single vector value.
 *
 *        The class inherits from UBlueprintAsyncActionBase in order to be able to create "Latent" functions for Blueprint,
 *        which allow the user to easily deal with the Tween callbacks.
 */
UCLASS()
class TWEENMAKER_API UTweenVectorLatentFactory : public UBlueprintAsyncActionBase
{
    GENERATED_BODY()

public:

    /**
     * @brief Constructor.
     */
    UTweenVectorLatentFactory(const FObjectInitializer& ObjectInitializer);

    /// @brief Called by a Latent proxy when the Tween starts the execution.
    UPROPERTY(BlueprintAssignable)
    FBP_OnTweenVectorChange OnTweenStart;

    /// @brief Called by a Latent proxy at each Tween's update during the the execution.
    UPROPERTY(BlueprintAssignable)
    FBP_OnTweenVectorChange OnTweenUpdate;

    /// @brief Called by a Latent proxy when the Tween ends the execution.
    UPROPERTY(BlueprintAssignable)
    FBP_OnTweenVectorChange OnTweenEnd;

    /*
     **************************************************************************
     * "Create" methods
     **************************************************************************
     */

    /**
      * Creates a Latent Tween that moves an Actor from its current location (at the start of the Tween) to the given location.
      * With this function a new TweenContainer will be created, which will hold any other Tween appended/joined to this one.
      *
      * @param TweenManager (optional) The TweenManager that will handle the Tween. If none is passed, the global TweenManagerActor will be used if present.
      * @param TweenTarget The Actor to move.
      * @param OutTweenContainer (optional, output) If this pin is connected with a variable, it will contain the TweenContainer that owns the Tween.
      * @param OutTween (optional, output) If this pin is connected with a variable, it will contain the Tween that was just created.
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
	  */
    UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly="true", DisplayName="Create Latent Tween Move Actor To", KeyWords="Tween Actor Move To Latent Create", AdvancedDisplay=7, AutoCreateRefTerm="OutTweenContainer, OutTween"), Category = "Tween|LatentTween|Actor|Move")
    static UTweenVectorLatentFactory* BP_CreateLatentTweenMoveActorTo(UTweenManagerComponent* TweenManager,
                                                                      AActor* TweenTarget,
                                                                      UTweenContainer*& OutTweenContainer,
                                                                      UTweenVector*& OutTween,
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
                                                                      bool TweenWhileGameIsPaused = false);

    /**
      * Creates a Latent Tween that moves an Actor by the given offset with respect to its current location (at the start of the Tween).
      * With this function a new TweenContainer will be created, which will hold any other Tween appended/joined to this one.
      *
      * @param TweenManager (optional) The TweenManager that will handle the Tween. If none is passed, the global TweenManagerActor will be used if present.
      * @param TweenTarget The Actor to move.
      * @param OutTweenContainer (optional, output) If this pin is connected with a variable, it will contain the TweenContainer that owns the Tween.
      * @param OutTween (optional, output) If this pin is connected with a variable, it will contain the Tween that was just created.
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
	  */
    UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly="true", DisplayName="Create Latent Tween Move Actor By", KeyWords="Tween Actor Move By Latent Create", AdvancedDisplay=7, AutoCreateRefTerm="OutTweenContainer, OutTween"), Category = "Tween|LatentTween|Actor|Move")
    static UTweenVectorLatentFactory* BP_CreateLatentTweenMoveActorBy(UTweenManagerComponent* TweenManager,
                                                                      AActor* TweenTarget,
                                                                      UTweenContainer*& OutTweenContainer,
                                                                      UTweenVector*& OutTween,
                                                                      FVector By,
                                                                      float Duration              = 1.0f,
                                                                      ETweenEaseType EaseType     = ETweenEaseType::Linear,
                                                                      bool DeleteTweenOnHit       = false,
                                                                      bool DeleteTweenOnOverlap   = false,
                                                                      int32 NumLoops              = 1,
                                                                      ETweenLoopType LoopType     = ETweenLoopType::Yoyo,
                                                                      float Delay                 = 0.0f,
                                                                      float TimeScale             = 1.0f,
                                                                      bool TweenWhileGameIsPaused = false);


    /**
      * Creates a Latent Tween that scales an Actor from its current scale (at the start of the Tween) to the given size.
      * With this function a new TweenContainer will be created, which will hold any other Tween appended/joined to this one.
      *
      * @param TweenManager (optional) The TweenManager that will handle the Tween. If none is passed, the global TweenManagerActor will be used if present.
      * @param TweenTarget The Actor to move.
      * @param OutTweenContainer (optional, output) If this pin is connected with a variable, it will contain the TweenContainer that owns the Tween.
      * @param OutTween (optional, output) If this pin is connected with a variable, it will contain the Tween that was just created.
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
	  */
    UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly="true", DisplayName="Create Latent Tween Scale Actor To", KeyWords="Tween Scale Actor To Latent Create", AdvancedDisplay=7, AutoCreateRefTerm="OutTweenContainer, OutTween"), Category = "Tween|LatentTween|Actor|Scale")
    static UTweenVectorLatentFactory* BP_CreateLatentTweenScaleActorTo(UTweenManagerComponent* TweenManager,
                                                                       AActor* TweenTarget,
                                                                       UTweenContainer*& OutTweenContainer,
                                                                       UTweenVector*& OutTween,
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
                                                                       bool TweenWhileGameIsPaused = false);

    /**
      * Creates a Latent Tween that scales an Actor by the given offset with respect to its current size (at the start of the Tween).
      * With this function a new TweenContainer will be created, which will hold any other Tween appended/joined to this one.
      *
      * @param TweenManager (optional) The TweenManager that will handle the Tween. If none is passed, the global TweenManagerActor will be used if present.
      * @param TweenTarget The Actor to move.
      * @param OutTweenContainer (optional, output) If this pin is connected with a variable, it will contain the TweenContainer that owns the Tween.
      * @param OutTween (optional, output) If this pin is connected with a variable, it will contain the Tween that was just created.
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
	  */
    UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly="true", DisplayName="Create Latent Tween Scale Actor By", KeyWords="Tween Scale Actor By Latent Create", AdvancedDisplay=7, AutoCreateRefTerm="OutTweenContainer, OutTween"), Category = "Tween|LatentTween|Actor|Scale")
    static UTweenVectorLatentFactory* BP_CreateLatentTweenScaleActorBy(UTweenManagerComponent* TweenManager,
                                                                       AActor* TweenTarget,
                                                                       UTweenContainer*& OutTweenContainer,
                                                                       UTweenVector*& OutTween,
                                                                       FVector By,
                                                                       float Duration              = 1.0f,
                                                                       ETweenEaseType EaseType     = ETweenEaseType::Linear,
                                                                       bool DeleteTweenOnHit       = false,
                                                                       bool DeleteTweenOnOverlap   = false,
                                                                       int32 NumLoops              = 1,
                                                                       ETweenLoopType LoopType     = ETweenLoopType::Yoyo,
                                                                       float Delay                 = 0.0f,
                                                                       float TimeScale             = 1.0f,
                                                                       bool TweenWhileGameIsPaused = false);

    /**
      * Creates a Latent Tween that moves a SceneComponent from its current location (at the start of the Tween) to the given location.
      * With this function a new TweenContainer will be created, which will hold any other Tween appended/joined to this one.
      *
      * @param TweenManager (optional) The TweenManager that will handle the Tween. If none is passed, the global TweenManagerActor will be used if present.
      * @param TweenTarget The SceneComponent to move.
      * @param OutTweenContainer (optional, output) If this pin is connected with a variable, it will contain the TweenContainer that owns the Tween.
      * @param OutTween (optional, output) If this pin is connected with a variable, it will contain the Tween that was just created.
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
	  */
    UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly="true", DisplayName="Create Latent Tween Move Scene Component To", KeyWords="Tween Scene Component Move To Latent Create", AdvancedDisplay=7, AutoCreateRefTerm="OutTweenContainer, OutTween"), Category = "Tween|LatentTween|SceneComponent|Move")
    static UTweenVectorLatentFactory* BP_CreateLatentTweenMoveSceneComponentTo(UTweenManagerComponent* TweenManager,
                                                                               USceneComponent* TweenTarget,
                                                                               UTweenContainer*& OutTweenContainer,
                                                                               UTweenVector*& OutTween,
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
                                                                               bool TweenWhileGameIsPaused = false);

    /**
      * Creates a Latent Tween that moves a SceneComponent by the given offset with respect to its current location (at the start of the Tween).
      * With this function a new TweenContainer will be created, which will hold any other Tween appended/joined to this one.
      *
      * @param TweenManager (optional) The TweenManager that will handle the Tween. If none is passed, the global TweenManagerActor will be used if present.
      * @param TweenTarget The SceneComponent to move.
      * @param OutTweenContainer (optional, output) If this pin is connected with a variable, it will contain the TweenContainer that owns the Tween.
      * @param OutTween (optional, output) If this pin is connected with a variable, it will contain the Tween that was just created.
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
	  */
    UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly="true", DisplayName="Create Latent Tween Move Scene Component By", KeyWords="Tween Scene Component Move By Latent Create", AdvancedDisplay=7, AutoCreateRefTerm="OutTweenContainer, OutTween"), Category = "Tween|LatentTween|SceneComponent|Move")
    static UTweenVectorLatentFactory* BP_CreateLatentTweenMoveSceneComponentBy(UTweenManagerComponent* TweenManager,
                                                                               USceneComponent* TweenTarget,
                                                                               UTweenContainer*& OutTweenContainer,
                                                                               UTweenVector*& OutTween,
                                                                               FVector By,
                                                                               float Duration              = 1.0f,
                                                                               ETweenEaseType EaseType     = ETweenEaseType::Linear,
                                                                               bool DeleteTweenOnHit       = false,
                                                                               bool DeleteTweenOnOverlap   = false,
                                                                               int32 NumLoops              = 1,
                                                                               ETweenLoopType LoopType     = ETweenLoopType::Yoyo,
                                                                               float Delay                 = 0.0f,
                                                                               float TimeScale             = 1.0f,
                                                                               bool TweenWhileGameIsPaused = false);

    /**
      * Creates a Latent Tween that scales a SceneComponent from its current scale (at the start of the Tween) to the given size.
      * With this function a new TweenContainer will be created, which will hold any other Tween appended/joined to this one.
      *
      * @param TweenManager (optional) The TweenManager that will handle the Tween. If none is passed, the global TweenManagerActor will be used if present.
      * @param TweenTarget The SceneComponent to move.
      * @param OutTweenContainer (optional, output) If this pin is connected with a variable, it will contain the TweenContainer that owns the Tween.
      * @param OutTween (optional, output) If this pin is connected with a variable, it will contain the Tween that was just created.
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
	  */
    UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly="true", DisplayName="Create Latent Tween Scale Scene Component To", KeyWords="Tween Scale Scene Component To Latent Create", AdvancedDisplay=7, AutoCreateRefTerm="OutTweenContainer, OutTween"), Category = "Tween|LatentTween|SceneComponent|Scale")
    static UTweenVectorLatentFactory* BP_CreateLatentTweenScaleSceneComponentTo(UTweenManagerComponent* TweenManager,
                                                                                USceneComponent* TweenTarget,
                                                                                UTweenContainer*& OutTweenContainer,
                                                                                UTweenVector*& OutTween,
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
                                                                                bool TweenWhileGameIsPaused = false);

    /**
      * Creates a Latent Tween that scales a SceneComponent by the given offset with respect to its current size (at the start of the Tween).
      * With this function a new TweenContainer will be created, which will hold any other Tween appended/joined to this one.

      * @param TweenManager (optional) The TweenManager that will handle the Tween. If none is passed, the global TweenManagerActor will be used if present.
      * @param TweenTarget The SceneComponent to move.
      * @param OutTweenContainer (optional, output) If this pin is connected with a variable, it will contain the TweenContainer that owns the Tween.
      * @param OutTween (optional, output) If this pin is connected with a variable, it will contain the Tween that was just created.
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
	  */
    UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly="true", DisplayName="Create Latent Tween Scale Scene Component By", KeyWords="Tween Scale Scene Component By Latent Create", AdvancedDisplay=7, AutoCreateRefTerm="OutTweenContainer, OutTween"), Category = "Tween|LatentTween|SceneComponent|Scale")
    static UTweenVectorLatentFactory* BP_CreateLatentTweenScaleSceneComponentBy(UTweenManagerComponent* TweenManager,
                                                                                USceneComponent* TweenTarget,
                                                                                UTweenContainer*& OutTweenContainer,
                                                                                UTweenVector*& OutTween,
                                                                                FVector By,
                                                                                float Duration              = 1.0f,
                                                                                ETweenEaseType EaseType     = ETweenEaseType::Linear,
                                                                                bool DeleteTweenOnHit       = false,
                                                                                bool DeleteTweenOnOverlap   = false,
                                                                                int32 NumLoops              = 1,
                                                                                ETweenLoopType LoopType     = ETweenLoopType::Yoyo,
                                                                                float Delay                 = 0.0f,
                                                                                float TimeScale             = 1.0f,
                                                                                bool TweenWhileGameIsPaused = false);


    /**
      * Creates a Latent custom Tween that goes from a starting value to an ending one. This type of Tween is meant for creating custom behaviours
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
    UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly="true", DisplayName="Create Latent Tween Custom Vector", KeyWords="Tween Custom Vector Latent", AdvancedDisplay=8, AutoCreateRefTerm="OutTweenContainer, OutTween"), Category = "Tween|LatentTween|Custom")
    static UTweenVectorLatentFactory* BP_CreateLatentTweenCustomVector(UTweenManagerComponent* TweenManager,
                                                                       UObject* TweenTarget,
                                                                       UTweenContainer*& OutTweenContainer,
                                                                       UTweenVector*& OutTween,
                                                                       FVector From,
                                                                       FVector To,
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
      * Appends to the TweenContainer a Latent Tween that moves an Actor from its current location (at the start of the Tween) to the given location.
      * It will be executed when all previous Tweens in the TweenContainer are completed.
      *
      * @param TweenContainer The TweenContainer that will own the new Tween.
      * @param TweenTarget The Actor to move.
      * @param OutTween (optional, output) If this pin is connected with a variable, it will contain the Tween that was just created.
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
	  */
    UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly="true", DisplayName="Append Latent Tween Move Actor To", KeyWords="Tween Actor Move To Latent Append", AdvancedDisplay=6, AutoCreateRefTerm="Tween"), Category = "Tween|LatentTween|Actor|Move")
    static UTweenVectorLatentFactory* BP_AppendLatentTweenMoveActorTo(UTweenContainer* TweenContainer,
                                                                      UTweenVector*& OutTween,
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
                                                                      bool TweenWhileGameIsPaused = false);

    /**
      * Appends to the TweenContainer a Latent Tween that moves an Actor by the given offset with respect to its current location (at the start of the Tween).
      * It will be executed when all previous Tweens in the TweenContainer are completed.
      *
      * @param TweenContainer The TweenContainer that will own the new Tween.
      * @param TweenTarget The Actor to move.
      * @param OutTween (optional, output) If this pin is connected with a variable, it will contain the Tween that was just created.
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
	  */
    UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly="true", DisplayName="Append Latent Tween Move Actor By", KeyWords="Tween Actor Move By Latent Append Sequence", AdvancedDisplay=6, AutoCreateRefTerm="Tween"), Category = "Tween|LatentTween|Actor|Move")
    static UTweenVectorLatentFactory* BP_AppendLatentTweenMoveActorBy(UTweenContainer* TweenContainer,
                                                                      UTweenVector*& OutTween,
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
                                                                      bool TweenWhileGameIsPaused = false);

    /**
      * Appends to the TweenContainer a Latent Tween that scales an Actor from its current scale (at the start of the Tween) to the given size.
      * It will be executed when all previous Tweens in the TweenContainer are completed.
      *
      * @param TweenContainer The TweenContainer that will own the new Tween.
      * @param TweenTarget The Actor to move.
      * @param OutTween (optional, output) If this pin is connected with a variable, it will contain the Tween that was just created.
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
	  */
    UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly="true", DisplayName="Append Latent Tween Scale Actor To", KeyWords="Tween Scale Actor To Latent Append Sequence", AdvancedDisplay=6, AutoCreateRefTerm="Tween"), Category = "Tween|LatentTween|Actor|Scale")
    static UTweenVectorLatentFactory* BP_AppendLatentTweenScaleActorTo(UTweenContainer* TweenContainer,
                                                                       UTweenVector*& OutTween,
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
                                                                       bool TweenWhileGameIsPaused = false);

    /**
      * Appends to the TweenContainer a Latent Tween that scales an Actor by the given offset with respect to its current size (at the start of the Tween).
      * It will be executed when all previous Tweens in the TweenContainer are completed.

      * @param TweenContainer The TweenContainer that will own the new Tween.
      * @param TweenTarget The Actor to move.
      * @param OutTween (optional, output) If this pin is connected with a variable, it will contain the Tween that was just created.
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
	  */
    UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly="true", DisplayName="Append Latent Tween Scale Actor By", KeyWords="Tween Scale Actor By Latent Append Sequence", AdvancedDisplay=6, AutoCreateRefTerm="Tween"), Category = "Tween|LatentTween|Actor|Scale")
    static UTweenVectorLatentFactory* BP_AppendLatentTweenScaleActorBy(UTweenContainer* TweenContainer,
                                                                       UTweenVector*& OutTween,
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
                                                                       bool TweenWhileGameIsPaused = false);

    /**
      * Appends to the TweenContainer a Latent Tween that moves a SceneComponent from its current location (at the start of the Tween) to the given location.
      * It will be executed when all previous Tweens in the TweenContainer are completed.
      *
      * @param TweenContainer The TweenContainer that will own the new Tween.
      * @param TweenTarget The SceneComponent to move.
      * @param OutTween (optional, output) If this pin is connected with a variable, it will contain the Tween that was just created.
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
	  */
    UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly="true", DisplayName="Append Latent Tween Move Scene Component To", KeyWords="Tween Scene Component Move To Latent Append Sequence", AdvancedDisplay=6, AutoCreateRefTerm="Tween"), Category = "Tween|LatentTween|SceneComponent|Move")
    static UTweenVectorLatentFactory* BP_AppendLatentTweenMoveSceneComponentTo(UTweenContainer* TweenContainer,
                                                                               UTweenVector*& OutTween,
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
                                                                               bool TweenWhileGameIsPaused = false);

    /**
      * Appends to the TweenContainer a Latent Tween that moves a SceneComponent by the given offset with respect to its current location (at the start of the Tween).
      * It will be executed when all previous Tweens in the TweenContainer are completed.
      *
      * @param TweenContainer The TweenContainer that will own the new Tween.
      * @param TweenTarget The SceneComponent to move.
      * @param OutTween (optional, output) If this pin is connected with a variable, it will contain the Tween that was just created.
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
	  */
    UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly="true", DisplayName="Append Latent Tween Move Scene Component By", KeyWords="Tween Scene Component Move By Latent Append Sequence", AdvancedDisplay=6, AutoCreateRefTerm="Tween"), Category = "Tween|LatentTween|SceneComponent|Move")
    static UTweenVectorLatentFactory* BP_AppendLatentTweenMoveSceneComponentBy(UTweenContainer* TweenContainer,
                                                                               UTweenVector*& OutTween,
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
                                                                               bool TweenWhileGameIsPaused = false);

    /**
      * Appends to the TweenContainer a Latent Tween that scales a SceneComponent from its current scale (at the start of the Tween) to the given size.
      * It will be executed when all previous Tweens in the TweenContainer are completed.
      *
      * @param TweenContainer The TweenContainer that will own the new Tween.
      * @param TweenTarget The SceneComponent to move.
      * @param OutTween (optional, output) If this pin is connected with a variable, it will contain the Tween that was just created.
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
	  */
    UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly="true", DisplayName="Append Latent Tween Scale Scene Component To", KeyWords="Tween Scale Scene Component To Latent Append Sequence", AdvancedDisplay=6, AutoCreateRefTerm="Tween"), Category = "Tween|LatentTween|SceneComponent|Scale")
    static UTweenVectorLatentFactory* BP_AppendLatentTweenScaleSceneComponentTo(UTweenContainer* TweenContainer,
                                                                                UTweenVector*& OutTween,
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
                                                                                bool TweenWhileGameIsPaused = false);

    /**
      * Appends to the TweenContainer a Latent Tween that scales a SceneComponent by the given offset with respect to its current size (at the start of the Tween).
      * It will be executed when all previous Tweens in the TweenContainer are completed.

      * @param TweenContainer The TweenContainer that will own the new Tween.
      * @param TweenTarget The SceneComponent to move.
      * @param OutTween (optional, output) If this pin is connected with a variable, it will contain the Tween that was just created.
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
	  */
    UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly="true", DisplayName="Append Latent Tween Scale Scene Component By", KeyWords="Tween Scale Scene Component By Latent Append Sequence", AdvancedDisplay=6, AutoCreateRefTerm="Tween"), Category = "Tween|LatentTween|SceneComponent|Scale")
    static UTweenVectorLatentFactory* BP_AppendLatentTweenScaleSceneComponentBy(UTweenContainer* TweenContainer,
                                                                                UTweenVector*& OutTween,
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
    UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly="true", DisplayName="Append Latent Tween Custom Vector", KeyWords="Tween Custom Vector Latent Append Sequence", AdvancedDisplay=7, AutoCreateRefTerm="Tween"), Category = "Tween|LatentTween|Custom")
    static UTweenVectorLatentFactory* BP_AppendLatentTweenCustomVector(UTweenContainer* TweenContainer,
                                                                       UTweenVector*& OutTween,
                                                                       UObject* TweenTarget,
                                                                       FVector From,
                                                                       FVector To,
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
      * Joins to the TweenContainer a Latent Tween that moves an Actor by the given offset with respect to its current location (at the start of the Tween).
      * It will be executed in parallel with the last appended Tween in the TweenContainer.
      *
      * @param TweenContainer The TweenContainer that will own the new Tween.
      * @param TweenTarget The Actor to move.
      * @param OutTween (optional, output) If this pin is connected with a variable, it will contain the Tween that was just created.
      * @param To The ending value.
      * @param Duration The total duration of the Tween (in seconds).
      * @param EaseType	The easing functions to apply.
      * @param TweenSpace The space in which the Tween makes its update (i.e. 'world' or 'relative').
      * @param DeleteTweenOnHit If true the Tween will be deleted when the TweenTarget hits something.
      * @param DeleteTweenOnOverlap If true the Tween will be deleted when the TweenTarget overlaps something.
      * @param Delay The initial delay to apply to the Tween (in seconds).
      * @param TimeScale The scale to apply to the Tween execution. If < 1 the Tween will slow down, if > 1 it will speed up. If < 0 it will make the Tween go backward.
	  * @param TweenWhileGameIsPaused Sets whether the Tween should keep updating while the game is paused. Useful for Tween on UMG widgets that animate menus.
	  */
    UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly="true", DisplayName="Join Latent Tween Move Actor To", KeyWords="Tween Actor Move To Latent Join Parallel", AdvancedDisplay=6, AutoCreateRefTerm="Tween"), Category = "Tween|LatentTween|Actor|Move")
    static UTweenVectorLatentFactory* BP_JoinLatentTweenMoveActorTo(UTweenContainer* TweenContainer,
                                                                    UTweenVector*& OutTween,
                                                                    AActor* TweenTarget,
                                                                    FVector To,
                                                                    float Duration              = 1.0f,
                                                                    ETweenEaseType EaseType     = ETweenEaseType::Linear,
                                                                    ETweenSpace TweenSpace      = ETweenSpace::World,
                                                                    bool DeleteTweenOnHit       = false,
                                                                    bool DeleteTweenOnOverlap   = false,
                                                                    float Delay                 = 0.0f,
                                                                    float TimeScale             = 1.0f,
                                                                    bool TweenWhileGameIsPaused = false);

    /**
      * Joins to the TweenContainer a Latent Tween that moves an Actor by the given offset with respect to its current location (at the start of the Tween).
      * It will be executed in parallel with the last appended Tween in the TweenContainer.
      *
      * @param TweenContainer The TweenContainer that will own the new Tween.
      * @param TweenTarget The Actor to move.
      * @param OutTween (optional, output) If this pin is connected with a variable, it will contain the Tween that was just created.
      * @param By The offset to apply.
      * @param Duration The total duration of the Tween (in seconds).
      * @param EaseType	The easing functions to apply.
      * @param DeleteTweenOnHit If true the Tween will be deleted when the TweenTarget hits something.
      * @param DeleteTweenOnOverlap If true the Tween will be deleted when the TweenTarget overlaps something.
      * @param Delay The initial delay to apply to the Tween (in seconds).
      * @param TimeScale The scale to apply to the Tween execution. If < 1 the Tween will slow down, if > 1 it will speed up. If < 0 it will make the Tween go backward.
	  * @param TweenWhileGameIsPaused Sets whether the Tween should keep updating while the game is paused. Useful for Tween on UMG widgets that animate menus.
	  */
    UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly="true", DisplayName="Join Latent Tween Move Actor By", KeyWords="Tween Actor Move By Latent Join Parallel", AdvancedDisplay=6, AutoCreateRefTerm="Tween"), Category = "Tween|LatentTween|Actor|Move")
    static UTweenVectorLatentFactory* BP_JoinLatentTweenMoveActorBy(UTweenContainer* TweenContainer,
                                                                    UTweenVector*& OutTween,
                                                                    AActor* TweenTarget,
                                                                    FVector By,
                                                                    float Duration              = 1.0f,
                                                                    ETweenEaseType EaseType     = ETweenEaseType::Linear,
                                                                    bool DeleteTweenOnHit       = false,
                                                                    bool DeleteTweenOnOverlap   = false,
                                                                    float Delay                 = 0.0f,
                                                                    float TimeScale             = 1.0f,
                                                                    bool TweenWhileGameIsPaused = false);

    /**
      * Joins to the TweenContainer a Latent Tween that scales an Actor from its current scale (at the start of the Tween) to the given size.
      * It will be executed in parallel with the last appended Tween in the TweenContainer.
      *
      * @param TweenContainer The TweenContainer that will own the new Tween.
      * @param TweenTarget The Actor to move.
      * @param OutTween (optional, output) If this pin is connected with a variable, it will contain the Tween that was just created.
      * @param To The ending value.
      * @param Duration The total duration of the Tween (in seconds).
      * @param EaseType	The easing functions to apply.
      * @param TweenSpace The space in which the Tween makes its update (i.e. 'world' or 'relative').
      * @param DeleteTweenOnHit If true the Tween will be deleted when the TweenTarget hits something.
      * @param DeleteTweenOnOverlap If true the Tween will be deleted when the TweenTarget overlaps something.
      * @param Delay The initial delay to apply to the Tween (in seconds).
      * @param TimeScale The scale to apply to the Tween execution. If < 1 the Tween will slow down, if > 1 it will speed up. If < 0 it will make the Tween go backward.
	  * @param TweenWhileGameIsPaused Sets whether the Tween should keep updating while the game is paused. Useful for Tween on UMG widgets that animate menus.
	  */
    UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly="true", DisplayName="Join Latent Tween Scale Actor To", KeyWords="Tween Scale Actor To Latent Join Parallel", AdvancedDisplay=6, AutoCreateRefTerm="Tween"), Category = "Tween|LatentTween|Actor|Scale")
    static UTweenVectorLatentFactory* BP_JoinLatentTweenScaleActorTo(UTweenContainer* TweenContainer,
                                                                     UTweenVector*& OutTween,
                                                                     AActor* TweenTarget,
                                                                     FVector To,
                                                                     float Duration              = 1.0f,
                                                                     ETweenEaseType EaseType     = ETweenEaseType::Linear,
                                                                     ETweenSpace TweenSpace      = ETweenSpace::World,
                                                                     bool DeleteTweenOnHit       = false,
                                                                     bool DeleteTweenOnOverlap   = false,
                                                                     float Delay                 = 0.0f,
                                                                     float TimeScale             = 1.0f,
                                                                     bool TweenWhileGameIsPaused = false);

    /**
      * Joins to the TweenContainer a Latent Tween that scales an Actor by the given offset with respect to its current size (at the start of the Tween).
      * It will be executed in parallel with the last appended Tween in the TweenContainer.

      * @param TweenContainer The TweenContainer that will own the new Tween.
      * @param TweenTarget The Actor to move.
      * @param OutTween (optional, output) If this pin is connected with a variable, it will contain the Tween that was just created.
      * @param By The offset to apply.
      * @param Duration The total duration of the Tween (in seconds).
      * @param EaseType	The easing functions to apply.
      * @param DeleteTweenOnHit If true the Tween will be deleted when the TweenTarget hits something.
      * @param DeleteTweenOnOverlap If true the Tween will be deleted when the TweenTarget overlaps something.
      * @param Delay The initial delay to apply to the Tween (in seconds).
      * @param TimeScale The scale to apply to the Tween execution. If < 1 the Tween will slow down, if > 1 it will speed up. If < 0 it will make the Tween go backward.
	  * @param TweenWhileGameIsPaused Sets whether the Tween should keep updating while the game is paused. Useful for Tween on UMG widgets that animate menus.
	  */
    UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly="true", DisplayName="Join Latent Tween Scale Actor By", KeyWords="Tween Scale Actor By Latent Join Parallel", AdvancedDisplay=6, AutoCreateRefTerm="Tween"), Category = "Tween|LatentTween|Actor|Scale")
    static UTweenVectorLatentFactory* BP_JoinLatentTweenScaleActorBy(UTweenContainer* TweenContainer,
                                                                     UTweenVector*& OutTween,
                                                                     AActor* TweenTarget,
                                                                     FVector By,
                                                                     float Duration              = 1.0f,
                                                                     ETweenEaseType EaseType     = ETweenEaseType::Linear,
                                                                     bool DeleteTweenOnHit       = false,
                                                                     bool DeleteTweenOnOverlap   = false,
                                                                     float Delay                 = 0.0f,
                                                                     float TimeScale             = 1.0f,
                                                                     bool TweenWhileGameIsPaused = false);

    /**
      * Joins to the TweenContainer a Latent Tween that moves a SceneComponent by the given offset with respect to its current location (at the start of the Tween).
      * It will be executed in parallel with the last appended Tween in the TweenContainer.
      *
      * @param TweenContainer The TweenContainer that will own the new Tween.
      * @param TweenTarget The SceneComponent to move.
      * @param OutTween (optional, output) If this pin is connected with a variable, it will contain the Tween that was just created.
      * @param To The ending value.
      * @param Duration The total duration of the Tween (in seconds).
      * @param EaseType	The easing functions to apply.
      * @param TweenSpace The space in which the Tween makes its update (i.e. 'world' or 'relative').
      * @param DeleteTweenOnHit If true the Tween will be deleted when the TweenTarget hits something.
      * @param DeleteTweenOnOverlap If true the Tween will be deleted when the TweenTarget overlaps something.
      * @param Delay The initial delay to apply to the Tween (in seconds).
      * @param TimeScale The scale to apply to the Tween execution. If < 1 the Tween will slow down, if > 1 it will speed up. If < 0 it will make the Tween go backward.
	  * @param TweenWhileGameIsPaused Sets whether the Tween should keep updating while the game is paused. Useful for Tween on UMG widgets that animate menus.
	  */
    UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly="true", DisplayName="Join Latent Tween Move Scene Component To", KeyWords="Tween Scene Component Move To Latent Join Parallel", AdvancedDisplay=6, AutoCreateRefTerm="Tween"), Category = "Tween|LatentTween|SceneComponent|Move")
    static UTweenVectorLatentFactory* BP_JoinLatentTweenMoveSceneComponentTo(UTweenContainer* TweenContainer,
                                                                             UTweenVector*& OutTween,
                                                                             USceneComponent* TweenTarget,
                                                                             FVector To,
                                                                             float Duration              = 1.0f,
                                                                             ETweenEaseType EaseType     = ETweenEaseType::Linear,
                                                                             ETweenSpace TweenSpace      = ETweenSpace::World,
                                                                             bool DeleteTweenOnHit       = false,
                                                                             bool DeleteTweenOnOverlap   = false,
                                                                             float Delay                 = 0.0f,
                                                                             float TimeScale             = 1.0f,
                                                                             bool TweenWhileGameIsPaused = false);

    /**
      * Joins to the TweenContainer a Latent Tween that moves a SceneComponent by the given offset with respect to its current location (at the start of the Tween).
      * It will be executed in parallel with the last appended Tween in the TweenContainer.
      *
      * @param TweenContainer The TweenContainer that will own the new Tween.
      * @param TweenTarget The SceneComponent to move.
      * @param OutTween (optional, output) If this pin is connected with a variable, it will contain the Tween that was just created.
      * @param By The offset to apply.
      * @param Duration The total duration of the Tween (in seconds).
      * @param EaseType	The easing functions to apply.
      * @param DeleteTweenOnHit If true the Tween will be deleted when the TweenTarget hits something.
      * @param DeleteTweenOnOverlap If true the Tween will be deleted when the TweenTarget overlaps something.
      * @param Delay The initial delay to apply to the Tween (in seconds).
      * @param TimeScale The scale to apply to the Tween execution. If < 1 the Tween will slow down, if > 1 it will speed up. If < 0 it will make the Tween go backward.
	  * @param TweenWhileGameIsPaused Sets whether the Tween should keep updating while the game is paused. Useful for Tween on UMG widgets that animate menus.
	  */
    UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly="true", DisplayName="Join Latent Tween Move Scene Component By", KeyWords="Tween Scene Component Move By Latent Join Parallel", AdvancedDisplay=6, AutoCreateRefTerm="Tween"), Category = "Tween|LatentTween|SceneComponent|Move")
    static UTweenVectorLatentFactory* BP_JoinLatentTweenMoveSceneComponentBy(UTweenContainer* TweenContainer,
                                                                             UTweenVector*& OutTween,
                                                                             USceneComponent* TweenTarget,
                                                                             FVector By,
                                                                             float Duration              = 1.0f,
                                                                             ETweenEaseType EaseType     = ETweenEaseType::Linear,
                                                                             bool DeleteTweenOnHit       = false,
                                                                             bool DeleteTweenOnOverlap   = false,
                                                                             float Delay                 = 0.0f,
                                                                             float TimeScale             = 1.0f,
                                                                             bool TweenWhileGameIsPaused = false);


    /**
      * Joins to the TweenContainer a Latent Tween that scales a SceneComponent from its current scale (at the start of the Tween) to the given size.
      * It will be executed in parallel with the last appended Tween in the TweenContainer.
      *
      * @param TweenContainer The TweenContainer that will own the new Tween.
      * @param TweenTarget The SceneComponent to move.
      * @param OutTween (optional, output) If this pin is connected with a variable, it will contain the Tween that was just created.
      * @param To The ending value.
      * @param Duration The total duration of the Tween (in seconds).
      * @param EaseType	The easing functions to apply.
      * @param TweenSpace The space in which the Tween makes its update (i.e. 'world' or 'relative').
      * @param DeleteTweenOnHit If true the Tween will be deleted when the TweenTarget hits something.
      * @param DeleteTweenOnOverlap If true the Tween will be deleted when the TweenTarget overlaps something.
      * @param Delay The initial delay to apply to the Tween (in seconds).
      * @param TimeScale The scale to apply to the Tween execution. If < 1 the Tween will slow down, if > 1 it will speed up. If < 0 it will make the Tween go backward.
	  * @param TweenWhileGameIsPaused Sets whether the Tween should keep updating while the game is paused. Useful for Tween on UMG widgets that animate menus.
	  */
    UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly="true", DisplayName="Join Latent Tween Scale Scene Component To", KeyWords="Tween Scale Scene Component To Latent Join Parallel", AdvancedDisplay=6, AutoCreateRefTerm="Tween"), Category = "Tween|LatentTween|SceneComponent|Scale")
    static UTweenVectorLatentFactory* BP_JoinLatentTweenScaleSceneComponentTo(UTweenContainer* TweenContainer,
                                                                              UTweenVector*& OutTween,
                                                                              USceneComponent* TweenTarget,
                                                                              FVector To,
                                                                              float Duration              = 1.0f,
                                                                              ETweenEaseType EaseType     = ETweenEaseType::Linear,
                                                                              ETweenSpace TweenSpace      = ETweenSpace::World,
                                                                              bool DeleteTweenOnHit       = false,
                                                                              bool DeleteTweenOnOverlap   = false,
                                                                              float Delay                 = 0.0f,
                                                                              float TimeScale             = 1.0f,
                                                                              bool TweenWhileGameIsPaused = false);

    /**
      * Joins to the TweenContainer a Latent Tween that scales a SceneComponent by the given offset with respect to its current size (at the start of the Tween).
      * It will be executed in parallel with the last appended Tween in the TweenContainer.

      * @param TweenContainer The TweenContainer that will own the new Tween.
      * @param TweenTarget The SceneComponent to move.
      * @param OutTween (optional, output) If this pin is connected with a variable, it will contain the Tween that was just created.
      * @param By The offset to apply.
      * @param Duration The total duration of the Tween (in seconds).
      * @param EaseType	The easing functions to apply.
      * @param DeleteTweenOnHit If true the Tween will be deleted when the TweenTarget hits something.
      * @param DeleteTweenOnOverlap If true the Tween will be deleted when the TweenTarget overlaps something.
      * @param Delay The initial delay to apply to the Tween (in seconds).
      * @param TimeScale The scale to apply to the Tween execution. If < 1 the Tween will slow down, if > 1 it will speed up. If < 0 it will make the Tween go backward.
	  * @param TweenWhileGameIsPaused Sets whether the Tween should keep updating while the game is paused. Useful for Tween on UMG widgets that animate menus.
	  */
    UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly="true", DisplayName="Join Latent Tween Scale Scene Component By", KeyWords="Tween Scale Scene Component By Latent Join Parallel", AdvancedDisplay=6, AutoCreateRefTerm="Tween"), Category = "Tween|LatentTween|SceneComponent|Scale")
    static UTweenVectorLatentFactory* BP_JoinLatentTweenScaleSceneComponentBy(UTweenContainer* TweenContainer,
                                                                              UTweenVector*& OutTween,
                                                                              USceneComponent* TweenTarget,
                                                                              FVector By,
                                                                              float Duration              = 1.0f,
                                                                              ETweenEaseType EaseType     = ETweenEaseType::Linear,
                                                                              bool DeleteTweenOnHit       = false,
                                                                              bool DeleteTweenOnOverlap   = false,
                                                                              float Delay                 = 0.0f,
                                                                              float TimeScale             = 1.0f,
                                                                              bool TweenWhileGameIsPaused = false);

    /**
      * Joins to the TweenContainer a custom Latent Tween that goes from a starting value to an ending one. This type of Tween is meant for creating custom behaviours
      * by binding a function or an event to the OnTweenUpdate delegate in order to use the tweened value at each Tick by calling GetCurrentValue from the Tween object.
      * The Tween will be executed in parallel with all Tweens in the same sequence.
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
    UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly="true", DisplayName="Join Latent Tween Custom Vector", KeyWords="Tween Custom Vector Latent Join Parallel", AdvancedDisplay=7, AutoCreateRefTerm="Tween"), Category = "Tween|LatentTween|Custom")
    static UTweenVectorLatentFactory* BP_JoinLatentTweenCustomVector(UTweenContainer* TweenContainer,
                                                                     UTweenVector*& OutTween,
                                                                     UObject* TweenTarget,
                                                                     FVector From,
                                                                     FVector To,
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

    static UTweenVectorLatentFactory* CreateProxyForAppendTweenVector(UTweenContainer* pTweenContainer,
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
                                                                      UTweenVector*& OutTween);

    static UTweenVectorLatentFactory* CreateProxyForJoinTweenVector(UTweenContainer* pTweenContainer,
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
                                                                    UTweenVector*& OutTween);

};
