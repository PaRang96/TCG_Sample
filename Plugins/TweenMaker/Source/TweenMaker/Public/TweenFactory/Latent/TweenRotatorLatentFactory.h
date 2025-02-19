// Copyright 2018 Francesco Desogus. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"

#include "Kismet/BlueprintAsyncActionBase.h"
#include "TweenManagerComponent.h"
#include "Utils/TweenEnums.h"

#include "TweenRotatorLatentFactory.generated.h"

class ATweenManagerActor;
class UTweenManagerComponent;
class UTweenContainer;
class UBaseTween;
class UTweenRotator;

/**
 * @brief The UTweenRotatorLatentFactory class handles the creation of all Rotator related Tweens, i.e. all tweens that
 *        in order to be executed they need to change a single Rotator value.
 *
 *        The class inherits from UBlueprintAsyncActionBase in order to be able to create "Latent" functions for Blueprint,
 *        which allow the user to easily deal with the Tween callbacks.
 */
UCLASS()
class TWEENMAKER_API UTweenRotatorLatentFactory : public UBlueprintAsyncActionBase
{
    GENERATED_BODY()

public:

    /**
     * @brief Constructor.
     */
    UTweenRotatorLatentFactory(const FObjectInitializer& ObjectInitializer);

    /// @brief Called by a Latent proxy when the Tween starts the execution.
    UPROPERTY(BlueprintAssignable)
    FBP_OnTweenRotatorChange OnTweenStart;

    /// @brief Called by a Latent proxy at each Tween's update during the the execution.
    UPROPERTY(BlueprintAssignable)
    FBP_OnTweenRotatorChange OnTweenUpdate;

    /// @brief Called by a Latent proxy when the Tween ends the execution.
    UPROPERTY(BlueprintAssignable)
    FBP_OnTweenRotatorChange OnTweenEnd;

    /*
     **************************************************************************
     * "Create" methods
     **************************************************************************
     */

    /**
      * Creates a Latent Tween that rotates an Actor from its current orientation (at the start of the Tween) to the given rotation.
      * With this function a new TweenContainer will be created, which will hold any other Tween appended/joined to this one.
      *
      * @param TweenManager (optional) The TweenManager that will handle the Tween. If none is passed, the global TweenManagerActor will be used if present.
      * @param TweenTarget The Actor to rotate.
      * @param OutTweenContainer (optional, output) If this pin is connected with a variable, it will contain the TweenContainer that owns the Tween.
      * @param OutTween (optional, output) If this pin is connected with a variable, it will contain the Tween that was just created.
      * @param To The ending value.
      * @param Duration The total duration of the Tween (in seconds).
      * @param EaseType	The easing functions to apply.
      * @param TweenSpace The space in which the Tween makes its update (i.e. 'world' or 'relative').
      * @param RotationMode	The rotation mode to use.
      * @param DeleteTweenOnHit If true the Tween will be deleted when the TweenTarget hits something.
      * @param DeleteTweenOnOverlap If true the Tween will be deleted when the TweenTarget overlaps something.
      * @param NumLoops	The number of times the Tween should repeat. If <= 0, it will loop indefinitely.
      * @param LoopType	The type of loop to apply (if "yoyo", it will go backwards when it reached the end; otherwise it will reset).
      * @param Delay The initial delay to apply to the Tween (in seconds).
      * @param TimeScale The scale to apply to the Tween execution. If < 1 the Tween will slow down, if > 1 it will speed up. If < 0 it will make the Tween go backward.
      * @param TweenWhileGameIsPaused Sets whether the Tween should keep updating while the game is paused. Useful for Tween on UMG widgets that animate menus.
      */
    UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly="true", DisplayName="Create Latent Tween Rotate Actor To", KeyWords="Tween Rotate Actor To Latent Create", AdvancedDisplay=7, AutoCreateRefTerm="OutTweenContainer, OutTween"), Category = "Tween|LatentTween|Actor|Rotate")
    static UTweenRotatorLatentFactory* BP_CreateLatentTweenRotateActorTo(UTweenManagerComponent* TweenManager,
                                                                         AActor* TweenTarget,
                                                                         UTweenContainer*& OutTweenContainer,
                                                                         UTweenRotator*& OutTween,
                                                                         FRotator To,
                                                                         float Duration                  = 1.0f,
                                                                         ETweenEaseType EaseType         = ETweenEaseType::Linear,
                                                                         ETweenSpace TweenSpace          = ETweenSpace::World,
                                                                         ETweenRotationMode RotationMode = ETweenRotationMode::ShortestPath,
                                                                         bool DeleteTweenOnHit           = false,
                                                                         bool DeleteTweenOnOverlap       = false,
                                                                         int32 NumLoops                  = 1,
                                                                         ETweenLoopType LoopType         = ETweenLoopType::Yoyo,
                                                                         float Delay                     = 0.0f,
                                                                         float TimeScale                 = 1.0f,
                                                                         bool TweenWhileGameIsPaused     = false);

    /**
      * Creates a Latent Tween that rotates an Actor by the given offset with respect to its current orientation (at the start of the Tween).
      * With this function a new TweenContainer will be created, which will hold any other Tween appended/joined to this one.
      *
      * @param TweenManager (optional) The TweenManager that will handle the Tween. If none is passed, the global TweenManagerActor will be used if present.
      * @param TweenTarget The Actor to rotate.
      * @param OutTweenContainer (optional, output) If this pin is connected with a variable, it will contain the TweenContainer that owns the Tween.
      * @param OutTween (optional, output) If this pin is connected with a variable, it will contain the Tween that was just created.
      * @param By The offset to apply.
      * @param Duration The total duration of the Tween (in seconds).
      * @param EaseType	The easing functions to apply.
      * @param LocalSpace Whether to rotate around actor's own local axes, not parent/world
      * @param DeleteTweenOnHit If true the Tween will be deleted when the TweenTarget hits something.
      * @param DeleteTweenOnOverlap If true the Tween will be deleted when the TweenTarget overlaps something.
      * @param NumLoops	The number of times the Tween should repeat. If <= 0, it will loop indefinitely.
      * @param LoopType	The type of loop to apply (if "yoyo", it will go backwards when it reached the end; otherwise it will reset).
      * @param Delay The initial delay to apply to the Tween (in seconds).
      * @param TimeScale The scale to apply to the Tween execution. If < 1 the Tween will slow down, if > 1 it will speed up. If < 0 it will make the Tween go backward.
      * @param TweenWhileGameIsPaused Sets whether the Tween should keep updating while the game is paused. Useful for Tween on UMG widgets that animate menus.
      */
    UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly="true", DisplayName="Create Latent Tween Rotate Actor By", KeyWords="Tween Rotate Actor By Latent Create", AdvancedDisplay=8, AutoCreateRefTerm="OutTweenContainer, OutTween"), Category = "Tween|LatentTween|Actor|Rotate")
    static UTweenRotatorLatentFactory* BP_CreateLatentTweenRotateActorBy(UTweenManagerComponent* TweenManager,
                                                                         AActor* TweenTarget,
                                                                         UTweenContainer*& OutTweenContainer,
                                                                         UTweenRotator*& OutTween,
                                                                         FRotator By,
                                                                         float Duration              = 1.0f,
                                                                         ETweenEaseType EaseType     = ETweenEaseType::Linear,
                                                                         bool LocalSpace             = false,
                                                                         bool DeleteTweenOnHit       = false,
                                                                         bool DeleteTweenOnOverlap   = false,
                                                                         int32 NumLoops              = 1,
                                                                         ETweenLoopType LoopType     = ETweenLoopType::Yoyo,
                                                                         float Delay                 = 0.0f,
                                                                         float TimeScale             = 1.0f,
                                                                         bool TweenWhileGameIsPaused = false);


    /**
      * Creates a Latent Tween that rotates a SceneComponent from its current orientation (at the start of the Tween) to the given rotation.
      * With this function a new TweenContainer will be created, which will hold any other Tween appended/joined to this one.
      *
      * @param TweenManager (optional) The TweenManager that will handle the Tween. If none is passed, the global TweenManagerActor will be used if present.
      * @param TweenTarget The SceneComponent to rotate.
      * @param OutTweenContainer (optional, output) If this pin is connected with a variable, it will contain the TweenContainer that owns the Tween.
      * @param OutTween (optional, output) If this pin is connected with a variable, it will contain the Tween that was just created.
      * @param To The ending value.
      * @param Duration The total duration of the Tween (in seconds).
      * @param EaseType	The easing functions to apply.
      * @param TweenSpace The space in which the Tween makes its update (i.e. 'world' or 'relative').
      * @param RotationMode	The rotation mode to use.
      * @param DeleteTweenOnHit If true the Tween will be deleted when the TweenTarget hits something.
      * @param DeleteTweenOnOverlap If true the Tween will be deleted when the TweenTarget overlaps something.
      * @param NumLoops	The number of times the Tween should repeat. If <= 0, it will loop indefinitely.
      * @param LoopType	The type of loop to apply (if "yoyo", it will go backwards when it reached the end; otherwise it will reset).
      * @param Delay The initial delay to apply to the Tween (in seconds).
      * @param TimeScale The scale to apply to the Tween execution. If < 1 the Tween will slow down, if > 1 it will speed up. If < 0 it will make the Tween go backward.
      * @param TweenWhileGameIsPaused Sets whether the Tween should keep updating while the game is paused. Useful for Tween on UMG widgets that animate menus.
      */
    UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly="true", DisplayName="Create Latent Tween Rotate Scene Component To", KeyWords="Tween Rotate Scene Component To Latent Create", AdvancedDisplay=7, AutoCreateRefTerm="OutTweenContainer, OutTween"), Category = "Tween|LatentTween|SceneComponent|Rotate")
    static UTweenRotatorLatentFactory* BP_CreateLatentTweenRotateSceneComponentTo(UTweenManagerComponent* TweenManager,
                                                                                  USceneComponent* TweenTarget,
                                                                                  UTweenContainer*& OutTweenContainer,
                                                                                  UTweenRotator*& OutTween,
                                                                                  FRotator To,
                                                                                  float Duration                  = 1.0f,
                                                                                  ETweenEaseType EaseType         = ETweenEaseType::Linear,
                                                                                  ETweenSpace TweenSpace          = ETweenSpace::World,
                                                                                  ETweenRotationMode RotationMode = ETweenRotationMode::ShortestPath,
                                                                                  bool DeleteTweenOnHit           = false,
                                                                                  bool DeleteTweenOnOverlap       = false,
                                                                                  int32 NumLoops                  = 1,
                                                                                  ETweenLoopType LoopType         = ETweenLoopType::Yoyo,
                                                                                  float Delay                     = 0.0f,
                                                                                  float TimeScale                 = 1.0f,
                                                                                  bool TweenWhileGameIsPaused     = false);

    /**
      * Creates a Latent Tween that rotates a SceneComponent by the given offset with respect to its current orientation (at the start of the Tween).
      * With this function a new TweenContainer will be created, which will hold any other Tween appended/joined to this one.
      *
      * @param TweenManager (optional) The TweenManager that will handle the Tween. If none is passed, the global TweenManagerActor will be used if present.
      * @param TweenTarget The SceneComponent to rotate.
      * @param OutTweenContainer (optional, output) If this pin is connected with a variable, it will contain the TweenContainer that owns the Tween.
      * @param OutTween (optional, output) If this pin is connected with a variable, it will contain the Tween that was just created.
      * @param By The offset to apply.
      * @param Duration The total duration of the Tween (in seconds).
      * @param EaseType	The easing functions to apply.
      * @param LocalSpace Whether to rotate around component's own local axes, not parent/world
      * @param DeleteTweenOnHit If true the Tween will be deleted when the TweenTarget hits something.
      * @param DeleteTweenOnOverlap If true the Tween will be deleted when the TweenTarget overlaps something.
      * @param NumLoops	The number of times the Tween should repeat. If <= 0, it will loop indefinitely.
      * @param LoopType	The type of loop to apply (if "yoyo", it will go backwards when it reached the end; otherwise it will reset).
      * @param Delay The initial delay to apply to the Tween (in seconds).
      * @param TimeScale The scale to apply to the Tween execution. If < 1 the Tween will slow down, if > 1 it will speed up. If < 0 it will make the Tween go backward.
      * @param TweenWhileGameIsPaused Sets whether the Tween should keep updating while the game is paused. Useful for Tween on UMG widgets that animate menus.
      */
    UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly="true", DisplayName="Create Latent Tween Rotate Scene Component By", KeyWords="Tween Rotate Scene Component By Latent Create", AdvancedDisplay=8, AutoCreateRefTerm="OutTweenContainer, OutTween"), Category = "Tween|LatentTween|SceneComponent|Rotate")
    static UTweenRotatorLatentFactory* BP_CreateLatentTweenRotateSceneComponentBy(UTweenManagerComponent* TweenManager,
                                                                                  USceneComponent* TweenTarget,
                                                                                  UTweenContainer*& OutTweenContainer,
                                                                                  UTweenRotator*& OutTween,
                                                                                  FRotator By,
                                                                                  float Duration              = 1.0f,
                                                                                  ETweenEaseType EaseType     = ETweenEaseType::Linear,
                                                                                  bool LocalSpace            = false,
                                                                                  bool DeleteTweenOnHit       = false,
                                                                                  bool DeleteTweenOnOverlap   = false,
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
      * Appends to the TweenContainer a Latent Tween that rotates an Actor from its current orientation (at the start of the Tween) to the given rotation.
      * It will be executed when all previous Tweens in the TweenContainer are completed.
      *
      * @param TweenContainer The TweenContainer that will own the new Tween.
      * @param TweenTarget The Actor to rotate.
      * @param OutTween (optional, output) If this pin is connected with a variable, it will contain the Tween that was just created.
      * @param To The ending value.
      * @param Duration The total duration of the Tween (in seconds).
      * @param EaseType	The easing functions to apply.
      * @param TweenSpace The space in which the Tween makes its update (i.e. 'world' or 'relative').
      * @param RotationMode	The rotation mode to use.
      * @param DeleteTweenOnHit If true the Tween will be deleted when the TweenTarget hits something.
      * @param DeleteTweenOnOverlap If true the Tween will be deleted when the TweenTarget overlaps something.
      * @param NumLoops	The number of times the Tween should repeat. If <= 0, it will loop indefinitely.
      * @param LoopType	The type of loop to apply (if "yoyo", it will go backwards when it reached the end; otherwise it will reset).
      * @param Delay The initial delay to apply to the Tween (in seconds).
      * @param TimeScale The scale to apply to the Tween execution. If < 1 the Tween will slow down, if > 1 it will speed up. If < 0 it will make the Tween go backward.
      * @param TweenWhileGameIsPaused Sets whether the Tween should keep updating while the game is paused. Useful for Tween on UMG widgets that animate menus.
      */
    UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly="true", DisplayName="Append Latent Tween Rotate Actor To", KeyWords="Tween Rotate Actor To Latent Append Sequence", AdvancedDisplay=6, AutoCreateRefTerm="OutTween"), Category = "Tween|LatentTween|Actor|Rotate")
    static UTweenRotatorLatentFactory* BP_AppendLatentTweenRotateActorTo(UTweenContainer* TweenContainer,
                                                                         UTweenRotator*& OutTween,
                                                                         AActor* TweenTarget,
                                                                         FRotator To,
                                                                         float Duration                  = 1.0f,
                                                                         ETweenEaseType EaseType         = ETweenEaseType::Linear,
                                                                         ETweenSpace TweenSpace          = ETweenSpace::World,
                                                                         ETweenRotationMode RotationMode = ETweenRotationMode::ShortestPath,
                                                                         bool DeleteTweenOnHit           = false,
                                                                         bool DeleteTweenOnOverlap       = false,
                                                                         int32 NumLoops                  = 1,
                                                                         ETweenLoopType LoopType         = ETweenLoopType::Yoyo,
                                                                         float Delay                     = 0.0f,
                                                                         float TimeScale                 = 1.0f,
                                                                         bool TweenWhileGameIsPaused     = false);

    /**
      * Appends to the TweenContainer a Latent Tween that rotates an Actor by the given offset with respect to its current orientation (at the start of the Tween).
      * It will be executed when all previous Tweens in the TweenContainer are completed.
      *
      * @param TweenContainer The TweenContainer that will own the new Tween.
      * @param TweenTarget The Actor to rotate.
      * @param OutTween (optional, output) If this pin is connected with a variable, it will contain the Tween that was just created.
      * @param By The offset to apply.
      * @param Duration The total duration of the Tween (in seconds).
      * @param EaseType	The easing functions to apply.
      * @param LocalSpace Whether to rotate around actor's own local axes, not parent/world
      * @param DeleteTweenOnHit If true the Tween will be deleted when the TweenTarget hits something.
      * @param DeleteTweenOnOverlap If true the Tween will be deleted when the TweenTarget overlaps something.
      * @param NumLoops	The number of times the Tween should repeat. If <= 0, it will loop indefinitely.
      * @param LoopType	The type of loop to apply (if "yoyo", it will go backwards when it reached the end; otherwise it will reset).
      * @param Delay The initial delay to apply to the Tween (in seconds).
      * @param TimeScale The scale to apply to the Tween execution. If < 1 the Tween will slow down, if > 1 it will speed up. If < 0 it will make the Tween go backward.
      * @param TweenWhileGameIsPaused Sets whether the Tween should keep updating while the game is paused. Useful for Tween on UMG widgets that animate menus.
      */
    UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly="true", DisplayName="Append Latent Tween Rotate Actor By", KeyWords="Tween Rotate Actor By Latent Append Sequence", AdvancedDisplay=7, AutoCreateRefTerm="OutTween"), Category = "Tween|LatentTween|Actor|Rotate")
    static UTweenRotatorLatentFactory* BP_AppendLatentTweenRotateActorBy(UTweenContainer* TweenContainer,
                                                                         UTweenRotator*& OutTween,
                                                                         AActor* TweenTarget,
                                                                         FRotator By,
                                                                         float Duration              = 1.0f,
                                                                         ETweenEaseType EaseType     = ETweenEaseType::Linear,
                                                                         bool LocalSpace             = false,
                                                                         bool DeleteTweenOnHit       = false,
                                                                         bool DeleteTweenOnOverlap   = false,
                                                                         int32 NumLoops              = 1,
                                                                         ETweenLoopType LoopType     = ETweenLoopType::Yoyo,
                                                                         float Delay                 = 0.0f,
                                                                         float TimeScale             = 1.0f,
                                                                         bool TweenWhileGameIsPaused = false);

    /**
      * Appends to the TweenContainer a Latent Tween that rotates a SceneComponent from its current orientation (at the start of the Tween) to the given rotation.
      * It will be executed when all previous Tweens in the TweenContainer are completed.
      *
      * @param TweenContainer The TweenContainer that will own the new Tween.
      * @param TweenTarget The SceneComponent to rotate.
      * @param OutTween (optional, output) If this pin is connected with a variable, it will contain the Tween that was just created.
      * @param To The ending value.
      * @param Duration The total duration of the Tween (in seconds).
      * @param EaseType	The easing functions to apply.
      * @param TweenSpace The space in which the Tween makes its update (i.e. 'world' or 'relative').
      * @param RotationMode	The rotation mode to use.
      * @param DeleteTweenOnHit If true the Tween will be deleted when the TweenTarget hits something.
      * @param DeleteTweenOnOverlap If true the Tween will be deleted when the TweenTarget overlaps something.
      * @param NumLoops	The number of times the Tween should repeat. If <= 0, it will loop indefinitely.
      * @param LoopType	The type of loop to apply (if "yoyo", it will go backwards when it reached the end; otherwise it will reset).
      * @param Delay The initial delay to apply to the Tween (in seconds).
      * @param TimeScale The scale to apply to the Tween execution. If < 1 the Tween will slow down, if > 1 it will speed up. If < 0 it will make the Tween go backward.
      * @param TweenWhileGameIsPaused Sets whether the Tween should keep updating while the game is paused. Useful for Tween on UMG widgets that animate menus.
      */
    UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly="true", DisplayName="Append Latent Tween Rotate Scene Component To", KeyWords="Tween Rotate Scene Component To Latent Append Sequence", AdvancedDisplay=6, AutoCreateRefTerm="OutTween"), Category = "Tween|LatentTween|SceneComponent|Rotate")
    static UTweenRotatorLatentFactory* BP_AppendLatentTweenRotateSceneComponentTo(UTweenContainer* TweenContainer,
                                                                                  UTweenRotator*& OutTween,
                                                                                  USceneComponent* TweenTarget,
                                                                                  FRotator To,
                                                                                  float Duration                  = 1.0f,
                                                                                  ETweenEaseType EaseType         = ETweenEaseType::Linear,
                                                                                  ETweenSpace TweenSpace          = ETweenSpace::World,
                                                                                  ETweenRotationMode RotationMode = ETweenRotationMode::ShortestPath,
                                                                                  bool DeleteTweenOnHit           = false,
                                                                                  bool DeleteTweenOnOverlap       = false,
                                                                                  int32 NumLoops                  = 1,
                                                                                  ETweenLoopType LoopType         = ETweenLoopType::Yoyo,
                                                                                  float Delay                     = 0.0f,
                                                                                  float TimeScale                 = 1.0f,
                                                                                  bool TweenWhileGameIsPaused     = false);

    /**
      * Appends to the TweenContainer a Latent Tween that rotates a SceneComponent by the given offset with respect to its current orientation (at the start of the Tween).
      * It will be executed when all previous Tweens in the TweenContainer are completed.
      *
      * @param TweenContainer The TweenContainer that will own the new Tween.
      * @param TweenTarget The SceneComponent to rotate.
      * @param OutTween (optional, output) If this pin is connected with a variable, it will contain the Tween that was just created.
      * @param By The offset to apply.
      * @param Duration The total duration of the Tween (in seconds).
      * @param EaseType	The easing functions to apply.
      * @param LocalSpace Whether to rotate around component's own local axes, not parent/world
      * @param DeleteTweenOnHit If true the Tween will be deleted when the TweenTarget hits something.
      * @param DeleteTweenOnOverlap If true the Tween will be deleted when the TweenTarget overlaps something.
      * @param NumLoops	The number of times the Tween should repeat. If <= 0, it will loop indefinitely.
      * @param LoopType	The type of loop to apply (if "yoyo", it will go backwards when it reached the end; otherwise it will reset).
      * @param Delay The initial delay to apply to the Tween (in seconds).
      * @param TimeScale The scale to apply to the Tween execution. If < 1 the Tween will slow down, if > 1 it will speed up. If < 0 it will make the Tween go backward.
      * @param TweenWhileGameIsPaused Sets whether the Tween should keep updating while the game is paused. Useful for Tween on UMG widgets that animate menus.
      */
    UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly="true", DisplayName="Append Latent Tween Rotate Scene Component By", KeyWords="Tween Rotate Scene Component By Latent Append Sequence", AdvancedDisplay=7, AutoCreateRefTerm="OutTween"), Category = "Tween|LatentTween|SceneComponent|Rotate")
    static UTweenRotatorLatentFactory* BP_AppendLatentTweenRotateSceneComponentBy(UTweenContainer* TweenContainer,
                                                                                  UTweenRotator*& OutTween,
                                                                                  USceneComponent* TweenTarget,
                                                                                  FRotator By,
                                                                                  float Duration              = 1.0f,
                                                                                  ETweenEaseType EaseType     = ETweenEaseType::Linear,
                                                                                  bool LocalSpace             = false,
                                                                                  bool DeleteTweenOnHit       = false,
                                                                                  bool DeleteTweenOnOverlap   = false,
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
      * Joins to the TweenContainer a Latent Tween that rotates an Actor from its current orientation (at the start of the Tween) to the given rotation.
      * It will be executed in parallel with the last appended Tween in the TweenContainer.
      *
      * @param TweenContainer The TweenContainer that will own the new Tween.
      * @param TweenTarget The Actor to rotate.
      * @param OutTween (optional, output) If this pin is connected with a variable, it will contain the Tween that was just created.
      * @param To The ending value.
      * @param Duration The total duration of the Tween (in seconds).
      * @param EaseType	The easing functions to apply.
      * @param TweenSpace The space in which the Tween makes its update (i.e. 'world' or 'relative').
      * @param RotationMode	The rotation mode to use.
      * @param DeleteTweenOnHit If true the Tween will be deleted when the TweenTarget hits something.
      * @param DeleteTweenOnOverlap If true the Tween will be deleted when the TweenTarget overlaps something.
      * @param Delay The initial delay to apply to the Tween (in seconds).
      * @param TimeScale The scale to apply to the Tween execution. If < 1 the Tween will slow down, if > 1 it will speed up. If < 0 it will make the Tween go backward.
      * @param TweenWhileGameIsPaused Sets whether the Tween should keep updating while the game is paused. Useful for Tween on UMG widgets that animate menus.
      */
    UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly="true", DisplayName="Join Latent Tween Rotate Actor To", KeyWords="Tween Rotate Actor To Latent Join Parallel", AdvancedDisplay=6, AutoCreateRefTerm="OutTween"), Category = "Tween|LatentTween|Actor|Rotate")
    static UTweenRotatorLatentFactory* BP_JoinLatentTweenRotateActorTo(UTweenContainer* TweenContainer,
                                                                       UTweenRotator*& OutTween,
                                                                       AActor* TweenTarget,
                                                                       FRotator To,
                                                                       float Duration                  = 1.0f,
                                                                       ETweenEaseType EaseType         = ETweenEaseType::Linear,
                                                                       ETweenSpace TweenSpace          = ETweenSpace::World,
                                                                       ETweenRotationMode RotationMode = ETweenRotationMode::ShortestPath,
                                                                       bool DeleteTweenOnHit           = false,
                                                                       bool DeleteTweenOnOverlap       = false,
                                                                       float Delay                     = 0.0f,
                                                                       float TimeScale                 = 1.0f,
                                                                       bool TweenWhileGameIsPaused     = false);

    /**
      * Joins to the TweenContainer a Latent Tween that rotates an Actor by the given offset with respect to its current orientation (at the start of the Tween).
      * It will be executed in parallel with the last appended Tween in the TweenContainer.
      *
      * @param TweenContainer The TweenContainer that will own the new Tween.
      * @param TweenTarget The Actor to rotate.
      * @param OutTween (optional, output) If this pin is connected with a variable, it will contain the Tween that was just created.
      * @param By The offset to apply.
      * @param Duration The total duration of the Tween (in seconds).
      * @param EaseType	The easing functions to apply.
      * @param LocalSpace Whether to rotate around actor's own local axes, not parent/world
      * @param DeleteTweenOnHit If true the Tween will be deleted when the TweenTarget hits something.
      * @param DeleteTweenOnOverlap If true the Tween will be deleted when the TweenTarget overlaps something.
      * @param Delay The initial delay to apply to the Tween (in seconds).
      * @param TimeScale The scale to apply to the Tween execution. If < 1 the Tween will slow down, if > 1 it will speed up. If < 0 it will make the Tween go backward.
      * @param TweenWhileGameIsPaused Sets whether the Tween should keep updating while the game is paused. Useful for Tween on UMG widgets that animate menus.
     */
    UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly="true", DisplayName="Join Latent Tween Rotate Actor By", KeyWords="Tween Rotate Actor By Latent Join Parallel", AdvancedDisplay=7, AutoCreateRefTerm="OutTween"), Category = "Tween|LatentTween|Actor|Rotate")
    static UTweenRotatorLatentFactory* BP_JoinLatentTweenRotateActorBy(UTweenContainer* TweenContainer,
                                                                       UTweenRotator*& OutTween,
                                                                       AActor* TweenTarget,
                                                                       FRotator By,
                                                                       float Duration              = 1.0f,
                                                                       ETweenEaseType EaseType     = ETweenEaseType::Linear,
                                                                       bool LocalSpace             = false,
                                                                       bool DeleteTweenOnHit       = false,
                                                                       bool DeleteTweenOnOverlap   = false,
                                                                       float Delay                 = 0.0f,
                                                                       float TimeScale             = 1.0f,
                                                                       bool TweenWhileGameIsPaused = false);

    /**
      * Joins to the TweenContainer a Latent Tween that rotates a SceneComponent from its current orientation (at the start of the Tween) to the given rotation.
      * It will be executed in parallel with the last appended Tween in the TweenContainer.
      *
      * @param TweenContainer The TweenContainer that will own the new Tween.
      * @param TweenTarget The SceneComponent to rotate.
      * @param OutTween (optional, output) If this pin is connected with a variable, it will contain the Tween that was just created.
      * @param To The ending value.
      * @param Duration The total duration of the Tween (in seconds).
      * @param EaseType	The easing functions to apply.
      * @param TweenSpace The space in which the Tween makes its update (i.e. 'world' or 'relative').
      * @param RotationMode	The rotation mode to use.
      * @param DeleteTweenOnHit If true the Tween will be deleted when the TweenTarget hits something.
      * @param DeleteTweenOnOverlap If true the Tween will be deleted when the TweenTarget overlaps something.
      * @param Delay The initial delay to apply to the Tween (in seconds).
      * @param TimeScale The scale to apply to the Tween execution. If < 1 the Tween will slow down, if > 1 it will speed up. If < 0 it will make the Tween go backward.
      * @param TweenWhileGameIsPaused Sets whether the Tween should keep updating while the game is paused. Useful for Tween on UMG widgets that animate menus.
      */
    UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly="true", DisplayName="Join Latent Tween Rotate Scene Component To", KeyWords="Tween Rotate Scene Component To Latent Join Parallel", AdvancedDisplay=6, AutoCreateRefTerm="OutTween"), Category = "Tween|LatentTween|SceneComponent|Rotate")
    static UTweenRotatorLatentFactory* BP_JoinLatentTweenRotateSceneComponentTo(UTweenContainer* TweenContainer,
                                                                                UTweenRotator*& OutTween,
                                                                                USceneComponent* TweenTarget,
                                                                                FRotator To,
                                                                                float Duration                  = 1.0f,
                                                                                ETweenEaseType EaseType         = ETweenEaseType::Linear,
                                                                                ETweenSpace TweenSpace          = ETweenSpace::World,
                                                                                ETweenRotationMode RotationMode = ETweenRotationMode::ShortestPath,
                                                                                bool DeleteTweenOnHit           = false,
                                                                                bool DeleteTweenOnOverlap       = false,
                                                                                float Delay                     = 0.0f,
                                                                                float TimeScale                 = 1.0f,
                                                                                bool TweenWhileGameIsPaused     = false);

    /**
      * Joins to the TweenContainer a Latent Tween that rotates a SceneComponent by the given offset with respect to its current orientation (at the start of the Tween).
      * It will be executed in parallel with the last appended Tween in the TweenContainer.
      *
      * @param TweenContainer The TweenContainer that will own the new Tween.
      * @param TweenTarget The SceneComponent to rotate.
      * @param OutTween (optional, output) If this pin is connected with a variable, it will contain the Tween that was just created.
      * @param By The offset to apply.
      * @param Duration The total duration of the Tween (in seconds).
      * @param EaseType	The easing functions to apply.
      * @param LocalSpace Whether to rotate around actor's own local axes, not parent/world
      * @param DeleteTweenOnHit If true the Tween will be deleted when the TweenTarget hits something.
      * @param DeleteTweenOnOverlap If true the Tween will be deleted when the TweenTarget overlaps something.
      * @param Delay The initial delay to apply to the Tween (in seconds).
      * @param TimeScale The scale to apply to the Tween execution. If < 1 the Tween will slow down, if > 1 it will speed up. If < 0 it will make the Tween go backward.
      * @param TweenWhileGameIsPaused Sets whether the Tween should keep updating while the game is paused. Useful for Tween on UMG widgets that animate menus.
      */
    UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly="true", DisplayName="Join Latent Tween Rotate Scene Component By", KeyWords="Tween Rotate Scene Component By Latent Join Parallel", AdvancedDisplay=7, AutoCreateRefTerm="OutTween"), Category = "Tween|LatentTween|SceneComponent|Rotate")
    static UTweenRotatorLatentFactory* BP_JoinLatentTweenRotateSceneComponentBy(UTweenContainer* TweenContainer,
                                                                                UTweenRotator*& OutTween,
                                                                                USceneComponent* TweenTarget,
                                                                                FRotator By,
                                                                                float Duration              = 1.0f,
                                                                                ETweenEaseType EaseType     = ETweenEaseType::Linear,
                                                                                bool LocalSpace				= false,
                                                                                bool DeleteTweenOnHit       = false,
                                                                                bool DeleteTweenOnOverlap   = false,
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

    static UTweenRotatorLatentFactory* CreateProxyForAppendTweenRotator(UTweenContainer* pTweenContainer,
                                                                        ETweenRotatorType pTweenType,
                                                                        UObject* pTarget,
                                                                        ETweenTargetType pTargetType,
                                                                        const FRotator& pFrom,
                                                                        const FRotator& pTo,
                                                                        float pDuration,
                                                                        ETweenEaseType pEaseType,
                                                                        ETweenSpace pTweenSpace,
                                                                        ETweenRotationMode pRotationMode,
                                                                        bool pLocalSpace,
                                                                        bool pDeleteTweenOnHit,
                                                                        bool pDeleteTweenOnOverlap,
                                                                        int32 pNumLoops,
                                                                        ETweenLoopType pLoopType,
                                                                        float pDelay,
                                                                        float pTimeScale,
                                                                        bool pTweenWhileGameIsPaused,
                                                                        UTweenRotator*& OutTween);

    static UTweenRotatorLatentFactory* CreateProxyForJoinTweenRotator(UTweenContainer* pTweenContainer,
                                                                      ETweenRotatorType pTweenType,
                                                                      UObject* pTarget,
                                                                      ETweenTargetType pTargetType,
                                                                      const FRotator& pFrom,
                                                                      const FRotator& pTo,
                                                                      float pDuration,
                                                                      ETweenEaseType pEaseType,
                                                                      ETweenSpace pTweenSpace,
                                                                      ETweenRotationMode pRotationMode,
                                                                      bool pLocalSpace,
                                                                      bool pDeleteTweenOnHit,
                                                                      bool pDeleteTweenOnOverlap,
                                                                      float pDelay,
                                                                      float pTimeScale,
                                                                      bool pTweenWhileGameIsPaused,
                                                                      UTweenRotator*& OutTween);
};
