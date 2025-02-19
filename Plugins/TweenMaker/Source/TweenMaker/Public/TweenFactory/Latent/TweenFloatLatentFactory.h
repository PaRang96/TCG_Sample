// Copyright 2018 Francesco Desogus. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"

#include "Kismet/BlueprintAsyncActionBase.h"
#include "TweenManagerComponent.h"
#include "Utils/TweenEnums.h"

#include "TweenFloatLatentFactory.generated.h"

class ATweenManagerActor;
class UTweenManagerComponent;
class UTweenContainer;
class UBaseTween;
class UTweenFloat;
class UMaterialInstanceDynamic;
class USplineComponent;
class UWidget;

/**
 * @brief The UTweenFloatLatentFactory class handles the creation of all float related Tweens, i.e. all tweens that
 *        in order to be executed they need to change a single float value.
 *
 *        The class inherits from UBlueprintAsyncActionBase in order to be able to create "Latent" functions for Blueprint,
 *        which allow the user to easily deal with the Tween callbacks.
 */
UCLASS()
class TWEENMAKER_API UTweenFloatLatentFactory : public UBlueprintAsyncActionBase
{
    GENERATED_BODY()

public:

    /**
     * @brief Constructor.
     */
    UTweenFloatLatentFactory(const FObjectInitializer& ObjectInitializer);

    /// @brief Called by a Latent proxy when the Tween starts the execution.
    UPROPERTY(BlueprintAssignable)
    FBP_OnTweenFloatChange OnTweenStart;

    /// @brief Called by a Latent proxy at each Tween's update during the the execution.
    UPROPERTY(BlueprintAssignable)
    FBP_OnTweenFloatChange OnTweenUpdate;

    /// @brief Called by a Latent proxy when the Tween ends the execution.
    UPROPERTY(BlueprintAssignable)
    FBP_OnTweenFloatChange OnTweenEnd;

    /*
     **************************************************************************
     * "Create" methods
     **************************************************************************
     */

    /**
      * Creates a Latent Tween that modifies a "float" material parameter from the starting value to the ending value.
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
    UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly="true", DisplayName="Create Latent Tween Material Float From To", KeyWords="Tween Material Float From To Latent Create", AdvancedDisplay=8, AutoCreateRefTerm="OutTweenContainer, OutTween"), Category = "Tween|LatentTween|Material")
    static UTweenFloatLatentFactory* BP_CreateLatentTweenMaterialFloatFromTo(UTweenManagerComponent* TweenManager,
                                                                             UMaterialInstanceDynamic* TweenTarget,
                                                                             UTweenContainer*& OutTweenContainer,
                                                                             UTweenFloat*& OutTween,
                                                                             FName ParameterName,
                                                                             float From,
                                                                             float To,
                                                                             float Duration              = 1.0f,
                                                                             ETweenEaseType EaseType     = ETweenEaseType::Linear,
                                                                             int32 NumLoops              = 1,
                                                                             ETweenLoopType LoopType     = ETweenLoopType::Yoyo,
                                                                             float Delay                 = 0.0f,
                                                                             float TimeScale             = 1.0f,
                                                                             bool TweenWhileGameIsPaused = false);

    /**
      * Creates a Latent Tween that modifies a "float" material parameter from its current value (at the start of the Tween) to the ending value.
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
    UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly="true", DisplayName="Create Latent Tween Material Float To", KeyWords="Tween Material Float To Latent Create", AdvancedDisplay=7, AutoCreateRefTerm="OutTweenContainer, OutTween"), Category = "Tween|LatentTween|Material")
    static UTweenFloatLatentFactory* BP_CreateLatentTweenMaterialFloatTo(UTweenManagerComponent* TweenManager,
                                                                         UMaterialInstanceDynamic* TweenTarget,
                                                                         UTweenContainer*& OutTweenContainer,
                                                                         UTweenFloat*& OutTween,
                                                                         FName ParameterName,
                                                                         float To,
                                                                         float Duration              = 1.0f,
                                                                         ETweenEaseType EaseType     = ETweenEaseType::Linear,
                                                                         int32 NumLoops              = 1,
                                                                         ETweenLoopType LoopType     = ETweenLoopType::Yoyo,
                                                                         float Delay                 = 0.0f,
                                                                         float TimeScale             = 1.0f,
                                                                         bool TweenWhileGameIsPaused = false);

    /**
      * Creates a Latent Tween that rotates an Actor around a given pivot point, with a given radius and rotation axis. The Actor will move
      * relative to its parent (if there is none, it will move in world coordinates).
      * With this function a new TweenContainer will be created, which will hold any other Tween appended/joined to this one.
      *
      * @param TweenManager (optional) The TweenManager that will handle the Tween. If none is passed, the global TweenManagerActor will be used if present.
      * @param TweenTarget The target of the rotation.
      * @param OutTweenContainer (optional, output) If this pin is connected with a variable, it will contain the TweenContainer that owns the Tween.
      * @param OutTween (optional, output) If this pin is connected with a variable, it will contain the Tween that was just created.
      * @param PivotPoint The point around which to rotate (the TweenSpace parameter defines if it's in world space or relative space).
      * @param StartingAngle The starting angle of the rotation (in degrees).
      * @param EndingAngle The ending angle of the rotation (in degrees).
      * @param Radius The radius of the rotation, in relation to the pivot point.
      * @param Axis The axis around which to rotate (the TweenSpace parameter defines if it's in world space or relative space).
      * @param TweenSpace The space in which the Tween makes its update (i.e. 'world' or 'relative').
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
    UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly="true", DisplayName="Create Latent Tween Rotate Actor Around Point", KeyWords="Tween Rotate Actor Around Point Latent Create", AdvancedDisplay=11, AutoCreateRefTerm="OutTweenContainer, OutTween"), Category = "Tween|LatentTween|Actor|Rotate")
    static UTweenFloatLatentFactory* BP_CreateLatentTweenRotateActorAroundPoint(UTweenManagerComponent* TweenManager,
                                                                                AActor* TweenTarget,
                                                                                UTweenContainer*& OutTweenContainer,
                                                                                UTweenFloat*& OutTween,
                                                                                FVector PivotPoint,
                                                                                float StartingAngle,
                                                                                float EndingAngle,
                                                                                float Radius,
                                                                                FVector Axis                = FVector(0.0f, 0.0f, 1.0f),
                                                                                ETweenSpace TweenSpace      = ETweenSpace::World,
                                                                                float Duration              = 1.0f,
                                                                                ETweenEaseType EaseType     = ETweenEaseType::Linear,
                                                                                bool DeleteTweenOnHit       = false,
                                                                                bool DeleteTweenOnOverlap   = false,
                                                                                int32 NumLoops              = 1,
                                                                                ETweenLoopType LoopType     = ETweenLoopType::Restart,
                                                                                float Delay                 = 0.0f,
                                                                                float TimeScale             = 1.0f,
                                                                                bool TweenWhileGameIsPaused = false);

    /**
      * Creates a Latent Tween that rotates an Actor around a given pivot point by an offset angle. The radius and the rotation axis will be automatically computed. The Actor will move
      * relative to its parent (if there is none, it will move in world coordinates).
      * With this function a new TweenContainer will be created, which will hold any other Tween appended/joined to this one.
      *
      * @param TweenManager (optional) The TweenManager that will handle the Tween. If none is passed, the global TweenManagerActor will be used if present.
      * @param TweenTarget The target of the roation.
      * @param OutTweenContainer (optional, output) If this pin is connected with a variable, it will contain the TweenContainer that owns the Tween.
      * @param OutTween (optional, output) If this pin is connected with a variable, it will contain the Tween that was just created.
      * @param PivotPoint The point around which to rotate (the TweenSpace parameter defines if it's in world space or relative space).
      * @param OffsetAngle The ending angle of the rotation (in degrees).
      * @param ReferenceAxis The reference axis used to compute the direction of the rotation. Different axes will result in different kind of rotations: experiment to find the one you need.
      * @param TweenSpace The space in which the Tween makes its update (i.e. 'world' or 'relative').
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
    UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly="true", DisplayName="Create Latent Tween Rotate Actor Around Point By Offset", KeyWords="Tween Rotate Actor Around Point By Offset Latent Create", AdvancedDisplay=10, AutoCreateRefTerm="OutTweenContainer, OutTween"), Category = "Tween|LatentTween|Actor|Rotate")
    static UTweenFloatLatentFactory* BP_CreateLatentTweenRotateActorAroundPointByOffset(UTweenManagerComponent* TweenManager,
                                                                                        AActor* TweenTarget,
                                                                                        UTweenContainer*& OutTweenContainer,
                                                                                        UTweenFloat*& OutTween,
                                                                                        FVector PivotPoint,
                                                                                        float OffsetAngle,
                                                                                        ETweenReferenceAxis ReferenceAxis = ETweenReferenceAxis::YAxis,
                                                                                        ETweenSpace TweenSpace            = ETweenSpace::World,
                                                                                        float Duration                    = 1.0f,
                                                                                        ETweenEaseType EaseType           = ETweenEaseType::Linear,
                                                                                        bool DeleteTweenOnHit             = false,
                                                                                        bool DeleteTweenOnOverlap         = false,
                                                                                        int32 NumLoops                    = 1,
                                                                                        ETweenLoopType LoopType           = ETweenLoopType::Restart,
                                                                                        float Delay                       = 0.0f,
                                                                                        float TimeScale                   = 1.0f,
                                                                                        bool TweenWhileGameIsPaused       = false);

    /**
      * Creates a Latent Tween that makes an Actor follow a spline path.
      * With this function a new TweenContainer will be created, which will hold any other Tween appended/joined to this one.
      *
      * @param TweenManager (optional) The TweenManager that will handle the Tween. If none is passed, the global TweenManagerActor will be used if present.
      * @param TweenTarget The target Actor.
      * @param OutTweenContainer (optional, output) If this pin is connected with a variable, it will contain the TweenContainer that owns the Tween.
      * @param OutTween (optional, output) If this pin is connected with a variable, it will contain the Tween that was just created.
      * @param Spline The SplineComponent path to follow.
      * @param Duration The total duration of the Tween (in seconds).
      * @param ApplyRotation If set, the spline rotation will be applied to the Actor.
      * @param ApplyScale If set, the spline scale will be applied to the Actor.
      * @param UseConstantSpeed If set, the movement will be at constant speed across the spline points (but it will sill take into account the easing).
      * @param EaseType	The easing functions to apply.
      * @param DeleteTweenOnHit If true the Tween will be deleted when the TweenTarget hits something.
      * @param DeleteTweenOnOverlap If true the Tween will be deleted when the TweenTarget overlaps something.
      * @param NumLoops	The number of times the Tween should repeat. If <= 0, it will loop indefinitely.
      * @param LoopType	The type of loop to apply (if "yoyo", it will go backwards when it reached the end; otherwise it will reset).
      * @param Delay The initial delay to apply to the Tween (in seconds).
      * @param TimeScale The scale to apply to the Tween execution. If < 1 the Tween will slow down, if > 1 it will speed up. If < 0 it will make the Tween go backward.
	  * @param TweenWhileGameIsPaused Sets whether the Tween should keep updating while the game is paused. Useful for Tween on UMG widgets that animate menus.
	  */
    UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly="true", DisplayName="Create Latent Tween Actor Follow Spline", KeyWords="Tween Actor Follow Spline Latent Create", AdvancedDisplay=10, AutoCreateRefTerm="OutTweenContainer, OutTween"), Category = "Tween|LatentTween|Actor|Spline")
    static UTweenFloatLatentFactory* BP_CreateLatentTweenActorFollowSpline(UTweenManagerComponent* TweenManager,
                                                                           AActor* TweenTarget,
                                                                           UTweenContainer*& OutTweenContainer,
                                                                           UTweenFloat*& OutTween,
                                                                           USplineComponent* Spline,
                                                                           float Duration              = 1.0f,
                                                                           bool ApplyRotation          = false,
                                                                           bool ApplyScale             = false,
                                                                           bool UseConstantSpeed       = true,
                                                                           ETweenEaseType EaseType     = ETweenEaseType::Linear,
                                                                           bool DeleteTweenOnHit       = false,
                                                                           bool DeleteTweenOnOverlap   = false,
                                                                           int32 NumLoops              = 1,
                                                                           ETweenLoopType LoopType     = ETweenLoopType::Restart,
                                                                           float Delay                 = 0.0f,
                                                                           float TimeScale             = 1.0f,
                                                                           bool TweenWhileGameIsPaused = false);

    /**
      * Creates a Latent Tween that rotates a SceneComponent around a given pivot point, with a given radius and rotation axis. The SceneComponent will move
      * relative to its parent (if there is none, it will move in world coordinates).
      * With this function a new TweenContainer will be created, which will hold any other Tween appended/joined to this one.
      *
      * @param TweenManager (optional) The TweenManager that will handle the Tween. If none is passed, the global TweenManagerActor will be used if present.
      * @param TweenTarget The target SceneComponent.
      * @param OutTweenContainer (optional, output) If this pin is connected with a variable, it will contain the TweenContainer that owns the Tween.
      * @param OutTween (optional, output) If this pin is connected with a variable, it will contain the Tween that was just created.
      * @param PivotPoint The point around which to rotate (the TweenSpace parameter defines if it's in world space or relative space).
      * @param StartingAngle The starting angle of the rotation (in degrees).
      * @param EndingAngle The ending angle of the rotation (in degrees).
      * @param Radius The radius of the rotation, in relation to the pivot point.
      * @param Axis The axis around which to rotate (the TweenSpace parameter defines if it's in world space or relative space).
      * @param TweenSpace The space in which the Tween makes its update (i.e. 'world' or 'relative').
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
    UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly="true", DisplayName="Create Latent Tween Rotate Scene Component Around Point", KeyWords="Tween Rotate Scene Component Around Point Latent Create", AdvancedDisplay=11, AutoCreateRefTerm="OutTweenContainer, OutTween"), Category = "Tween|LatentTween|SceneComponent|Rotate")
    static UTweenFloatLatentFactory* BP_CreateLatentTweenRotateSceneComponentAroundPoint(UTweenManagerComponent* TweenManager,
                                                                                         USceneComponent* TweenTarget,
                                                                                         UTweenContainer*& OutTweenContainer,
                                                                                         UTweenFloat*& OutTween,
                                                                                         FVector PivotPoint,
                                                                                         float StartingAngle,
                                                                                         float EndingAngle,
                                                                                         float Radius,
                                                                                         FVector Axis                = FVector(0.0f, 0.0f, 1.0f),
                                                                                         ETweenSpace TweenSpace      = ETweenSpace::World,
                                                                                         float Duration              = 1.0f,
                                                                                         ETweenEaseType EaseType     = ETweenEaseType::Linear,
                                                                                         bool DeleteTweenOnHit       = false,
                                                                                         bool DeleteTweenOnOverlap   = false,
                                                                                         int32 NumLoops              = 1,
                                                                                         ETweenLoopType LoopType     = ETweenLoopType::Restart,
                                                                                         float Delay                 = 0.0f,
                                                                                         float TimeScale             = 1.0f,
                                                                                         bool TweenWhileGameIsPaused = false);

    /**
      * Creates a Latent Tween that rotates a SceneComponent around a given pivot point by an offset angle. The radius and the rotation axis will be automatically computed. The SceneComponent will move
      * relative to its parent (if there is none, it will move in world coordinates).
      * With this function a new TweenContainer will be created, which will hold any other Tween appended/joined to this one.
      *
      * @param TweenManager (optional) The TweenManager that will handle the Tween. If none is passed, the global TweenManagerActor will be used if present.
      * @param TweenTarget The target SceneComponent.
      * @param OutTweenContainer (optional, output) If this pin is connected with a variable, it will contain the TweenContainer that owns the Tween.
      * @param OutTween (optional, output) If this pin is connected with a variable, it will contain the Tween that was just created.
      * @param PivotPoint The point around which to rotate (the TweenSpace parameter defines if it's in world space or relative space).
      * @param OffsetAngle The ending angle of the rotation (in degrees).
      * @param ReferenceAxis The reference axis used to compute the direction of the rotation. Different axes will result in different kind of rotations: experiment to find the one you need.
      * @param TweenSpace The space in which the Tween makes its update (i.e. 'world' or 'relative').
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
    UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly="true", DisplayName="Create Latent Tween Rotate Scene Component Around Point By Offset", KeyWords="Tween Rotate Scene Component Around Point By Offset Latent Create", AdvancedDisplay=10, AutoCreateRefTerm="OutTweenContainer, OutTween"), Category = "Tween|LatentTween|SceneComponent|Rotate")
    static UTweenFloatLatentFactory* BP_CreateLatentTweenRotateSceneComponentAroundPointByOffset(UTweenManagerComponent* TweenManager,
                                                                                                 USceneComponent* TweenTarget,
                                                                                                 UTweenContainer*& OutTweenContainer,
                                                                                                 UTweenFloat*& OutTween,
                                                                                                 FVector PivotPoint,
                                                                                                 float OffsetAngle,
                                                                                                 ETweenReferenceAxis ReferenceAxis = ETweenReferenceAxis::YAxis,
                                                                                                 ETweenSpace TweenSpace            = ETweenSpace::World,
                                                                                                 float Duration                    = 1.0f,
                                                                                                 ETweenEaseType EaseType           = ETweenEaseType::Linear,
                                                                                                 bool DeleteTweenOnHit             = false,
                                                                                                 bool DeleteTweenOnOverlap         = false,
                                                                                                 int32 NumLoops                    = 1,
                                                                                                 ETweenLoopType LoopType           = ETweenLoopType::Restart,
                                                                                                 float Delay                       = 0.0f,
                                                                                                 float TimeScale                   = 1.0f,
                                                                                                 bool TweenWhileGameIsPaused       = false);

    /**
      * Creates a Latent Tween that makes an SceneComponent follow a spline path.
      * With this function a new TweenContainer will be created, which will hold any other Tween appended/joined to this one.
      *
      * @param TweenManager (optional) The TweenManager that will handle the Tween. If none is passed, the global TweenManagerActor will be used if present.
      * @param TweenTarget The target SceneComponent.
      * @param OutTweenContainer (optional, output) If this pin is connected with a variable, it will contain the TweenContainer that owns the Tween.
      * @param OutTween (optional, output) If this pin is connected with a variable, it will contain the Tween that was just created.
      * @param Spline The SplineComponent path to follow.
      * @param Duration The total duration of the Tween (in seconds).
      * @param ApplyRotation If set, the spline rotation will be applied to the SceneComponent.
      * @param ApplyScale If set, the spline scale will be applied to the SceneComponent.
      * @param UseConstantSpeed If set, the movement will be at constant speed across the spline points (but it will sill take into account the easing).
      * @param EaseType	The easing functions to apply.
      * @param DeleteTweenOnHit If true the Tween will be deleted when the TweenTarget hits something.
      * @param DeleteTweenOnOverlap If true the Tween will be deleted when the TweenTarget overlaps something.
      * @param NumLoops	The number of times the Tween should repeat. If <= 0, it will loop indefinitely.
      * @param LoopType	The type of loop to apply (if "yoyo", it will go backwards when it reached the end; otherwise it will reset).
      * @param Delay The initial delay to apply to the Tween (in seconds).
      * @param TimeScale The scale to apply to the Tween execution. If < 1 the Tween will slow down, if > 1 it will speed up. If < 0 it will make the Tween go backward.
	  * @param TweenWhileGameIsPaused Sets whether the Tween should keep updating while the game is paused. Useful for Tween on UMG widgets that animate menus.
	  */
    UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly="true", DisplayName="Create Latent Tween Scene Component Follow Spline", KeyWords="Tween Scene Component Follow Spline Latent Create", AdvancedDisplay=10, AutoCreateRefTerm="OutTweenContainer, OutTween"), Category = "Tween|LatentTween|SceneComponent|Spline")
    static UTweenFloatLatentFactory* BP_CreateLatentTweenSceneComponentFollowSpline(UTweenManagerComponent* TweenManager,
                                                                                    USceneComponent* TweenTarget,
                                                                                    UTweenContainer*& OutTweenContainer,
                                                                                    UTweenFloat*& OutTween,
                                                                                    USplineComponent* Spline,
                                                                                    float Duration              = 1.0f,
                                                                                    bool ApplyRotation          = false,
                                                                                    bool ApplyScale             = false,
                                                                                    bool UseConstantSpeed       = true,
                                                                                    ETweenEaseType EaseType     = ETweenEaseType::Linear,
                                                                                    bool DeleteTweenOnHit       = false,
                                                                                    bool DeleteTweenOnOverlap   = false,
                                                                                    int32 NumLoops              = 1,
                                                                                    ETweenLoopType LoopType     = ETweenLoopType::Restart,
                                                                                    float Delay                 = 0.0f,
                                                                                    float TimeScale             = 1.0f,
                                                                                    bool TweenWhileGameIsPaused = false);

    /**
      * Creates a Latent Tween that makes a UMG widget rotate to the given angle.
      * With this function a new TweenContainer will be created, which will hold any other Tween appended/joined to this one.
      *
      * @param TweenManager (optional) The TweenManager that will handle the Tween. If none is passed, the global TweenManagerActor will be used if present.
      * @param TweenTarget The target Widget.
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
    UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly="true", DisplayName="Create Latent Tween Widget Angle To", KeyWords="Tween Widget Angle To UMG Latent Create", AdvancedDisplay=7, AutoCreateRefTerm="OutTweenContainer, OutTween"), Category = "Tween|LatentTween|UMG|Angle")
    static UTweenFloatLatentFactory* BP_CreateLatentTweenWidgetAngleTo(UTweenManagerComponent* TweenManager,
                                                                       UWidget* TweenTarget,
                                                                       UTweenContainer*& OutTweenContainer,
                                                                       UTweenFloat*& OutTween,
                                                                       float To,
                                                                       float Duration              = 1.0f,
                                                                       ETweenEaseType EaseType     = ETweenEaseType::Linear,
                                                                       int32 NumLoops              = 1,
                                                                       ETweenLoopType LoopType     = ETweenLoopType::Yoyo,
                                                                       float Delay                 = 0.0f,
                                                                       float TimeScale             = 1.0f,
                                                                       bool TweenWhileGameIsPaused = false);
    
    /**
      * Creates a Latent Tween that makes a UMG widget's opacity reach the given value.
      * With this function a new TweenContainer will be created, which will hold any other Tween appended/joined to this one.
      *
      * @param TweenManager (optional) The TweenManager that will handle the Tween. If none is passed, the global TweenManagerActor will be used if present.
      * @param TweenTarget The target Widget.
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
    UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly="true", DisplayName="Create Latent Tween Widget Opacity To", KeyWords="Tween Widget Opacity To UMG Latent Create", AdvancedDisplay=7, AutoCreateRefTerm="OutTweenContainer, OutTween"), Category = "Tween|LatentTween|UMG|Angle")
    static UTweenFloatLatentFactory* BP_CreateLatentTweenWidgetOpacityTo(UTweenManagerComponent* TweenManager,
                                                                         UWidget* TweenTarget,
                                                                         UTweenContainer*& OutTweenContainer,
                                                                         UTweenFloat*& OutTween,
                                                                         float To,
                                                                         float Duration              = 1.0f,
                                                                         ETweenEaseType EaseType     = ETweenEaseType::Linear,
                                                                         int32 NumLoops              = 1,
                                                                         ETweenLoopType LoopType     = ETweenLoopType::Yoyo,
                                                                         float Delay                 = 0.0f,
                                                                         float TimeScale             = 1.0f,
                                                                         bool TweenWhileGameIsPaused = false);

    /**
      * Creates a custom Latent Tween that goes from a starting float value to an ending one. This type of Tween is meant for creating custom behaviours
      * by binding a function or an event to the OnTweenUpdate delegate in order to use the tweened value at each Tick by calling GetCurrentValue from the Tween object.
      * With this function a new TweenContainer will be created, which will hold any other Tween appended/joined to this one.
      *
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
    UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly="true", DisplayName="Create Latent Tween Custom Float", KeyWords="Tween Custom Float From Latent Create", AdvancedDisplay=8, AutoCreateRefTerm="OutTweenContainer, OutTween"), Category = "Tween|LatentTween|Custom")
    static UTweenFloatLatentFactory* BP_CreateLatentTweenCustomFloat(UTweenManagerComponent* TweenManager,
                                                                     UObject* TweenTarget,
                                                                     UTweenContainer*& OutTweenContainer,
                                                                     UTweenFloat*& OutTween,
                                                                     float From,
                                                                     float To,
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
      * Appends to the TweenContainer a Latent Tween that modifies a "float" material parameter from the starting value to the ending value.
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
    UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly="true", DisplayName="Append Latent Tween Material Float From To", KeyWords="Tween Material Float From To Latent Append Sequence", AdvancedDisplay=7, AutoCreateRefTerm="OutTween"), Category = "Tween|LatentTween|Material")
    static UTweenFloatLatentFactory* BP_AppendLatentTweenMaterialFloatFromTo(UTweenContainer* TweenContainer,
                                                                             UTweenFloat*& OutTween,
                                                                             UMaterialInstanceDynamic* TweenTarget,
                                                                             FName ParameterName,
                                                                             float From,
                                                                             float To,
                                                                             float Duration              = 1.0f,
                                                                             ETweenEaseType EaseType     = ETweenEaseType::Linear,
                                                                             int32 NumLoops              = 1,
                                                                             ETweenLoopType LoopType     = ETweenLoopType::Yoyo,
                                                                             float Delay                 = 0.0f,
                                                                             float TimeScale             = 1.0f,
                                                                             bool TweenWhileGameIsPaused = false);

    /**
      * Appends to the TweenContainer a Latent Tween that modifies a "float" material parameter from its current value (at the start of the Tween) to the ending value.
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
    UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly="true", DisplayName="Append Latent Tween Material Float To", KeyWords="Tween Material Float To Latent Append Sequence", AdvancedDisplay=6, AutoCreateRefTerm="OutTween"), Category = "Tween|LatentTween|Material")
    static UTweenFloatLatentFactory* BP_AppendLatentTweenMaterialFloatTo(UTweenContainer* TweenContainer,
                                                                         UTweenFloat*& OutTween,
                                                                         UMaterialInstanceDynamic* TweenTarget,
                                                                         FName ParameterName,
                                                                         float To,
                                                                         float Duration              = 1.0f,
                                                                         ETweenEaseType EaseType     = ETweenEaseType::Linear,
                                                                         int32 NumLoops              = 1,
                                                                         ETweenLoopType LoopType     = ETweenLoopType::Yoyo,
                                                                         float Delay                 = 0.0f,
                                                                         float TimeScale             = 1.0f,
                                                                         bool TweenWhileGameIsPaused = false);

    /**
      * Appends to the TweenContainer a Latent Tween that rotates an Actor around a given pivot point, with a given radius and rotation axis. The Actor will move
      * relative to its parent (if there is none, it will move in world coordinates).
      * It will be executed when all previous Tweens in the TweenContainer are completed.
      *
      * @param TweenContainer The TweenContainer that will own the new Tween.
      * @param TweenTarget The target Actor.
      * @param OutTween (optional, output) If this pin is connected with a variable, it will contain the Tween that was just created.
      * @param PivotPoint The point around which to rotate (the TweenSpace parameter defines if it's in world space or relative space).
      * @param StartingAngle The starting angle of the rotation (in degrees).
      * @param EndingAngle The ending angle of the rotation (in degrees).
      * @param Radius The radius of the rotation, in relation to the pivot point.
      * @param Axis The axis around which to rotate (the TweenSpace parameter defines if it's in world space or relative space).
      * @param TweenSpace The space in which the Tween makes its update (i.e. 'world' or 'relative').
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
    UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly="true", DisplayName="Append Latent Tween Rotate Actor Around Point", KeyWords="Tween Rotate Actor Around Point Latent Append Sequence", AdvancedDisplay=10, AutoCreateRefTerm="OutTween"), Category = "Tween|LatentTween|Actor|Rotate")
    static UTweenFloatLatentFactory* BP_AppendLatentTweenRotateActorAroundPoint(UTweenContainer* TweenContainer,
                                                                                UTweenFloat*& OutTween,
                                                                                AActor* TweenTarget,
                                                                                FVector PivotPoint,
                                                                                float StartingAngle,
                                                                                float EndingAngle,
                                                                                float Radius,
                                                                                FVector Axis                = FVector(0.0f, 0.0f, 1.0f),
                                                                                ETweenSpace TweenSpace      = ETweenSpace::World,
                                                                                float Duration              = 1.0f,
                                                                                ETweenEaseType EaseType     = ETweenEaseType::Linear,
                                                                                bool DeleteTweenOnHit       = false,
                                                                                bool DeleteTweenOnOverlap   = false,
                                                                                int32 NumLoops              = 1,
                                                                                ETweenLoopType LoopType     = ETweenLoopType::Restart,
                                                                                float Delay                 = 0.0f,
                                                                                float TimeScale             = 1.0f,
                                                                                bool TweenWhileGameIsPaused = false);

    /**
      * Appends to the TweenContainer a Latent Tween that rotates an Actor around a given pivot point by an offset angle. The radius and the rotation axis will be automatically computed. The Actor will move
      * relative to its parent (if there is none, it will move in world coordinates).
      * It will be executed when all previous Tweens in the TweenContainer are completed.
      *
      * @param TweenContainer The TweenContainer that will own the new Tween.
      * @param TweenTarget The target Actor.
      * @param OutTween (optional, output) If this pin is connected with a variable, it will contain the Tween that was just created.
      * @param PivotPoint The point around which to rotate (the TweenSpace parameter defines if it's in world space or relative space).
      * @param OffsetAngle The ending angle of the rotation (in degrees).
      * @param ReferenceAxis The reference axis used to compute the direction of the rotation. Different axes will result in different kind of rotations: experiment to find the one you need.
      * @param TweenSpace The space in which the Tween makes its update (i.e. 'world' or 'relative').
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
    UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly="true", DisplayName="Append Latent Tween Rotate Actor Around Point By Offset", KeyWords="Tween Rotate Actor Around Point By Offset Latent Append Sequence", AdvancedDisplay=9, AutoCreateRefTerm="OutTween"), Category = "Tween|LatentTween|Actor|Rotate")
    static UTweenFloatLatentFactory* BP_AppendLatentTweenRotateActorAroundPointByOffset(UTweenContainer* TweenContainer,
                                                                                        UTweenFloat*& OutTween,
                                                                                        AActor* TweenTarget,
                                                                                        FVector PivotPoint,
                                                                                        float OffsetAngle,
                                                                                        ETweenReferenceAxis ReferenceAxis = ETweenReferenceAxis::YAxis,
                                                                                        ETweenSpace TweenSpace            = ETweenSpace::World,
                                                                                        float Duration                    = 1.0f,
                                                                                        ETweenEaseType EaseType           = ETweenEaseType::Linear,
                                                                                        bool DeleteTweenOnHit             = false,
                                                                                        bool DeleteTweenOnOverlap         = false,
                                                                                        int32 NumLoops                    = 1,
                                                                                        ETweenLoopType LoopType           = ETweenLoopType::Restart,
                                                                                        float Delay                       = 0.0f,
                                                                                        float TimeScale                   = 1.0f,
                                                                                        bool TweenWhileGameIsPaused       = false);

    /**
      * Appends to the TweenContainer a Latent Tween that makes an Actor follow a spline path.
      * It will be executed when all previous Tweens in the TweenContainer are completed.
      *
      * @param TweenContainer The TweenContainer that will own the new Tween.
      * @param TweenTarget The target Actor.
      * @param OutTween (optional, output) If this pin is connected with a variable, it will contain the Tween that was just created.
      * @param Spline The SplineComponent path to follow.
      * @param Duration The total duration of the Tween (in seconds).
      * @param ApplyRotation If set, the spline rotation will be applied to the Actor.
      * @param ApplyScale If set, the spline scale will be applied to the Actor.
      * @param UseConstantSpeed If set, the movement will be at constant speed across the spline points (but it will sill take into account the easing).
      * @param EaseType	The easing functions to apply.
      * @param DeleteTweenOnHit If true the Tween will be deleted when the TweenTarget hits something.
      * @param DeleteTweenOnOverlap If true the Tween will be deleted when the TweenTarget overlaps something.
      * @param NumLoops	The number of times the Tween should repeat. If <= 0, it will loop indefinitely.
      * @param LoopType	The type of loop to apply (if "yoyo", it will go backwards when it reached the end; otherwise it will reset).
      * @param Delay The initial delay to apply to the Tween (in seconds).
      * @param TimeScale The scale to apply to the Tween execution. If < 1 the Tween will slow down, if > 1 it will speed up. If < 0 it will make the Tween go backward.
	  * @param TweenWhileGameIsPaused Sets whether the Tween should keep updating while the game is paused. Useful for Tween on UMG widgets that animate menus.
	  */
    UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly="true", DisplayName="Append Latent Tween Actor Follow Spline", KeyWords="Tween Actor Follow Spline Latent Append Sequence", AdvancedDisplay=9, AutoCreateRefTerm="OutTween"), Category = "Tween|LatentTween|Actor|Spline")
    static UTweenFloatLatentFactory* BP_AppendLatentTweenActorFollowSpline(UTweenContainer* TweenContainer,
                                                                           UTweenFloat*& OutTween,
                                                                           AActor* TweenTarget,
                                                                           USplineComponent* Spline,
                                                                           float Duration              = 1.0f,
                                                                           bool ApplyRotation          = false,
                                                                           bool ApplyScale             = false,
                                                                           bool UseConstantSpeed       = true,
                                                                           ETweenEaseType EaseType     = ETweenEaseType::Linear,
                                                                           bool DeleteTweenOnHit       = false,
                                                                           bool DeleteTweenOnOverlap   = false,
                                                                           int32 NumLoops              = 1,
                                                                           ETweenLoopType LoopType     = ETweenLoopType::Restart,
                                                                           float Delay                 = 0.0f,
                                                                           float TimeScale             = 1.0f,
                                                                           bool TweenWhileGameIsPaused = false);

    /**
      * Appends to the TweenContainer a Latent Tween that rotates an SceneComponent around a given pivot point, with a given radius and rotation axis. The SceneComponent will move
      * relative to its parent (if there is none, it will move in world coordinates).
      * It will be executed when all previous Tweens in the TweenContainer are completed.
      *
      * @param TweenContainer The TweenContainer that will own the new Tween.
      * @param TweenTarget The target SceneComponent.
      * @param OutTween (optional, output) If this pin is connected with a variable, it will contain the Tween that was just created.
      * @param PivotPoint The point around which to rotate (the TweenSpace parameter defines if it's in world space or relative space).
      * @param StartingAngle The starting angle of the rotation (in degrees).
      * @param EndingAngle The ending angle of the rotation (in degrees).
      * @param Radius The radius of the rotation, in relation to the pivot point.
      * @param Axis The axis around which to rotate (the TweenSpace parameter defines if it's in world space or relative space).
      * @param TweenSpace The space in which the Tween makes its update (i.e. 'world' or 'relative').
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
    UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly="true", DisplayName="Append Latent Tween Rotate Scene Component Around Point", KeyWords="Tween Rotate Scene Component Around Point Latent Append Sequence", AdvancedDisplay=10, AutoCreateRefTerm="OutTween"), Category = "Tween|LatentTween|SceneComponent|Rotate")
    static UTweenFloatLatentFactory* BP_AppendLatentTweenRotateSceneComponentAroundPoint(UTweenContainer* TweenContainer,
                                                                                         UTweenFloat*& OutTween,
                                                                                         USceneComponent* TweenTarget,
                                                                                         FVector PivotPoint,
                                                                                         float StartingAngle,
                                                                                         float EndingAngle,
                                                                                         float Radius,
                                                                                         FVector Axis                = FVector(0.0f, 0.0f, 1.0f),
                                                                                         ETweenSpace TweenSpace      = ETweenSpace::World,
                                                                                         float Duration              = 1.0f,
                                                                                         ETweenEaseType EaseType     = ETweenEaseType::Linear,
                                                                                         bool DeleteTweenOnHit       = false,
                                                                                         bool DeleteTweenOnOverlap   = false,
                                                                                         int32 NumLoops              = 1,
                                                                                         ETweenLoopType LoopType     = ETweenLoopType::Restart,
                                                                                         float Delay                 = 0.0f,
                                                                                         float TimeScale             = 1.0f,
                                                                                         bool TweenWhileGameIsPaused = false);

    /**
      * Appends to the TweenContainer a Latent Tween that rotates an SceneComponent around a given pivot point by an offset angle. The radius and the rotation axis will be automatically computed. The SceneComponent will move
      * relative to its parent (if there is none, it will move in world coordinates).
      * It will be executed when all previous Tweens in the TweenContainer are completed.
      *
      * @param TweenContainer The TweenContainer that will own the new Tween.
      * @param TweenTarget The target SceneComponent.
      * @param OutTween (optional, output) If this pin is connected with a variable, it will contain the Tween that was just created.
      * @param PivotPoint The point around which to rotate (the TweenSpace parameter defines if it's in world space or relative space).
      * @param OffsetAngle The ending angle of the rotation (in degrees).
      * @param ReferenceAxis The reference axis used to compute the direction of the rotation. Different axes will result in different kind of rotations: experiment to find the one you need.
      * @param TweenSpace The space in which the Tween makes its update (i.e. 'world' or 'relative').
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
    UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly="true", DisplayName="Append Latent Tween Rotate Scene Component Around Point By Offset", KeyWords="Tween Rotate Scene Component Around Point By Offset Latent Append Sequence", AdvancedDisplay=9, AutoCreateRefTerm="OutTween"), Category = "Tween|LatentTween|SceneComponent|Rotate")
    static UTweenFloatLatentFactory* BP_AppendLatentTweenRotateSceneComponentAroundPointByOffset(UTweenContainer* TweenContainer,
                                                                                                 UTweenFloat*& OutTween,
                                                                                                 USceneComponent* TweenTarget,
                                                                                                 FVector PivotPoint,
                                                                                                 float OffsetAngle,
                                                                                                 ETweenReferenceAxis ReferenceAxis = ETweenReferenceAxis::YAxis,
                                                                                                 ETweenSpace TweenSpace            = ETweenSpace::World,
                                                                                                 float Duration                    = 1.0f,
                                                                                                 ETweenEaseType EaseType           = ETweenEaseType::Linear,
                                                                                                 bool DeleteTweenOnHit             = false,
                                                                                                 bool DeleteTweenOnOverlap         = false,
                                                                                                 int32 NumLoops                    = 1,
                                                                                                 ETweenLoopType LoopType           = ETweenLoopType::Restart,
                                                                                                 float Delay                       = 0.0f,
                                                                                                 float TimeScale                   = 1.0f,
                                                                                                 bool TweenWhileGameIsPaused       = false);

    /**
      * Appends to the TweenContainer a Latent Tween that makes an SceneComponent follow a spline path.
      * It will be executed when all previous Tweens in the TweenContainer are completed.
      *
      * @param TweenContainer The TweenContainer that will own the new Tween.
      * @param TweenTarget The target SceneComponent.
      * @param OutTween (optional, output) If this pin is connected with a variable, it will contain the Tween that was just created.
      * @param Spline The SplineComponent path to follow.
      * @param Duration The total duration of the Tween (in seconds).
      * @param ApplyRotation If set, the spline rotation will be applied to the SceneComponent.
      * @param ApplyScale If set, the spline scale will be applied to the SceneComponent.
      * @param UseConstantSpeed If set, the movement will be at constant speed across the spline points (but it will sill take into account the easing).
      * @param EaseType	The easing functions to apply.
      * @param DeleteTweenOnHit If true the Tween will be deleted when the TweenTarget hits something.
      * @param DeleteTweenOnOverlap If true the Tween will be deleted when the TweenTarget overlaps something.
      * @param NumLoops	The number of times the Tween should repeat. If <= 0, it will loop indefinitely.
      * @param LoopType	The type of loop to apply (if "yoyo", it will go backwards when it reached the end; otherwise it will reset).
      * @param Delay The initial delay to apply to the Tween (in seconds).
      * @param TimeScale The scale to apply to the Tween execution. If < 1 the Tween will slow down, if > 1 it will speed up. If < 0 it will make the Tween go backward.
	  * @param TweenWhileGameIsPaused Sets whether the Tween should keep updating while the game is paused. Useful for Tween on UMG widgets that animate menus.
	  */
    UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly="true", DisplayName="Append Latent Tween Scene Component Follow Spline", KeyWords="Tween Scene Component Follow Spline Latent Append Sequence", AdvancedDisplay=9, AutoCreateRefTerm="OutTween"), Category = "Tween|LatentTween|SceneComponent|Spline")
    static UTweenFloatLatentFactory* BP_AppendLatentTweenSceneComponentFollowSpline(UTweenContainer* TweenContainer,
                                                                                    UTweenFloat*& OutTween,
                                                                                    USceneComponent* TweenTarget,
                                                                                    USplineComponent* Spline,
                                                                                    float Duration              = 1.0f,
                                                                                    bool ApplyRotation          = false,
                                                                                    bool ApplyScale             = false,
                                                                                    bool UseConstantSpeed       = true,
                                                                                    ETweenEaseType EaseType     = ETweenEaseType::Linear,
                                                                                    bool DeleteTweenOnHit       = false,
                                                                                    bool DeleteTweenOnOverlap   = false,
                                                                                    int32 NumLoops              = 1,
                                                                                    ETweenLoopType LoopType     = ETweenLoopType::Restart,
                                                                                    float Delay                 = 0.0f,
                                                                                    float TimeScale             = 1.0f,
                                                                                    bool TweenWhileGameIsPaused = false);

    /**
      * Appends to the TweenContainer a Latent Tween that makes a UMG widget rotate to the given angle.
      * It will be executed when all previous Tweens in the TweenContainer are completed.
      *
      * @param TweenContainer The TweenContainer that will own the new Tween.
      * @param TweenTarget The target Widget.
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
    UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly="true", DisplayName="Append Latent Tween Widget Angle To", KeyWords="Tween Widget Angle To UMG Latent Append Sequence", AdvancedDisplay=6, AutoCreateRefTerm="OutTween"), Category = "Tween|LatentTween|UMG|Angle")
    static UTweenFloatLatentFactory* BP_AppendLatentTweenWidgetAngleTo(UTweenContainer* TweenContainer,
                                                                       UTweenFloat*& OutTween,
                                                                       UWidget* TweenTarget,
                                                                       float To,
                                                                       float Duration              = 1.0f,
                                                                       ETweenEaseType EaseType     = ETweenEaseType::Linear,
                                                                       int32 NumLoops              = 1,
                                                                       ETweenLoopType LoopType     = ETweenLoopType::Yoyo,
                                                                       float Delay                 = 0.0f,
                                                                       float TimeScale             = 1.0f,
                                                                       bool TweenWhileGameIsPaused = false);

    /**
      * Appends to the TweenContainer a Latent Tween that makes a UMG widget's opacity reach the given value.
      * It will be executed when all previous Tweens in the TweenContainer are completed.
      *
      * @param TweenContainer The TweenContainer that will own the new Tween.
      * @param TweenTarget The target Widget.
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
    UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly="true", DisplayName="Append Latent Tween Widget Opacity To", KeyWords="Tween Widget Opacity To UMG Latent Append Sequence", AdvancedDisplay=6, AutoCreateRefTerm="OutTween"), Category = "Tween|LatentTween|UMG|Opacity")
    static UTweenFloatLatentFactory* BP_AppendLatentTweenWidgetOpacityTo(UTweenContainer* TweenContainer,
                                                                         UTweenFloat*& OutTween,
                                                                         UWidget* TweenTarget,
                                                                         float To,
                                                                         float Duration              = 1.0f,
                                                                         ETweenEaseType EaseType     = ETweenEaseType::Linear,
                                                                         int32 NumLoops              = 1,
                                                                         ETweenLoopType LoopType     = ETweenLoopType::Yoyo,
                                                                         float Delay                 = 0.0f,
                                                                         float TimeScale             = 1.0f,
                                                                         bool TweenWhileGameIsPaused = false);

    /**
      * Appends to the TweenContainer a custom Latent Tween that goes from a starting float value to an ending one. This type of Tween is meant for creating custom behaviours
      * by binding a function or an event to the OnTweenUpdate delegate in order to use the tweened value at each Tick by calling GetCurrentValue from the Tween object.
      * It will be executed when all previous Tweens in the TweenContainer are completed.
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
    UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly="true", DisplayName="Append Latent Tween Custom Float", KeyWords="Tween Custom Float From Latent Append Sequence", AdvancedDisplay=7, AutoCreateRefTerm="OutTween"), Category = "Tween|LatentTween|Custom")
    static UTweenFloatLatentFactory* BP_AppendLatentTweenCustomFloat(UTweenContainer* TweenContainer,
                                                                     UTweenFloat*& OutTween,
                                                                     UObject* TweenTarget,
                                                                     float From,
                                                                     float To,
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
      * Joins to the TweenContainer a Latent Tween that modifies a "float" material parameter from the starting value to the ending value.
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
    UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly="true", DisplayName="Join Latent Tween Material Float From To", KeyWords="Tween Material Float From To Latent Join Parallel", AdvancedDisplay=7, AutoCreateRefTerm="OutTween"), Category = "Tween|LatentTween|Material")
    static UTweenFloatLatentFactory* BP_JoinLatentTweenMaterialFloatFromTo(UTweenContainer* TweenContainer,
                                                                           UTweenFloat*& OutTween,
                                                                           UMaterialInstanceDynamic* TweenTarget,
                                                                           FName ParameterName,
                                                                           float From,
                                                                           float To,
                                                                           float Duration              = 1.0f,
                                                                           ETweenEaseType EaseType     = ETweenEaseType::Linear,
                                                                           float Delay                 = 0.0f,
                                                                           float TimeScale             = 1.0f,
                                                                           bool TweenWhileGameIsPaused = false);

    /**
      * Joins to the TweenContainer a Latent Tween that modifies a "float" material parameter from its current value (at the start of the Tween) to the ending value.
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
    UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly="true", DisplayName="Join Latent Tween Material Float To", KeyWords="Tween Material Float To Latent Join Parallel", AdvancedDisplay=6, AutoCreateRefTerm="OutTween"), Category = "Tween|LatentTween|Material")
    static UTweenFloatLatentFactory* BP_JoinLatentTweenMaterialFloatTo(UTweenContainer* TweenContainer,
                                                                       UTweenFloat*& OutTween,
                                                                       UMaterialInstanceDynamic* TweenTarget,
                                                                       FName ParameterName,
                                                                       float To,
                                                                       float Duration              = 1.0f,
                                                                       ETweenEaseType EaseType     = ETweenEaseType::Linear,
                                                                       float Delay                 = 0.0f,
                                                                       float TimeScale             = 1.0f,
                                                                       bool TweenWhileGameIsPaused = false);

    /**
      * Joins to the TweenContainer a Latent Tween that rotates an Actor around a given pivot point, with a given radius and rotation axis. The Actor will move
      * relative to its parent (if there is none, it will move in world coordinates).
      * It will be executed in parallel with the last appended Tween in the TweenContainer.
      *
      * @param TweenContainer The TweenContainer that will own the new Tween.
      * @param TweenTarget The target Actor.
      * @param OutTween (optional, output) If this pin is connected with a variable, it will contain the Tween that was just created.
      * @param PivotPoint The point around which to rotate (the TweenSpace parameter defines if it's in world space or relative space).
      * @param StartingAngle The starting angle of the rotation (in degrees).
      * @param EndingAngle The ending angle of the rotation (in degrees).
      * @param Radius The radius of the rotation, in relation to the pivot point.
      * @param Axis The axis around which to rotate (the TweenSpace parameter defines if it's in world space or relative space).
      * @param TweenSpace The space in which the Tween makes its update (i.e. 'world' or 'relative').
      * @param Duration The total duration of the Tween (in seconds).
      * @param EaseType	The easing functions to apply.
      * @param DeleteTweenOnHit If true the Tween will be deleted when the TweenTarget hits something.
      * @param DeleteTweenOnOverlap If true the Tween will be deleted when the TweenTarget overlaps something.
      * @param Delay The initial delay to apply to the Tween (in seconds).
      * @param TimeScale The scale to apply to the Tween execution. If < 1 the Tween will slow down, if > 1 it will speed up. If < 0 it will make the Tween go backward.
	  * @param TweenWhileGameIsPaused Sets whether the Tween should keep updating while the game is paused. Useful for Tween on UMG widgets that animate menus.
	  */
    UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly="true", DisplayName="Join Latent Tween Rotate Actor Around Point", KeyWords="Tween Rotate Actor Around Point Latent Join Parallel", AdvancedDisplay=10, AutoCreateRefTerm="OutTween"), Category = "Tween|LatentTween|Actor|Rotate")
    static UTweenFloatLatentFactory* BP_JoinLatentTweenRotateActorAroundPoint(UTweenContainer* TweenContainer,
                                                                              UTweenFloat*& OutTween,
                                                                              AActor* TweenTarget,
                                                                              FVector PivotPoint,
                                                                              float StartingAngle,
                                                                              float EndingAngle,
                                                                              float Radius,
                                                                              FVector Axis                = FVector(0.0f, 0.0f, 1.0f),
                                                                              ETweenSpace TweenSpace      = ETweenSpace::World,
                                                                              float Duration              = 1.0f,
                                                                              ETweenEaseType EaseType     = ETweenEaseType::Linear,
                                                                              bool DeleteTweenOnHit       = false,
                                                                              bool DeleteTweenOnOverlap   = false,
                                                                              float Delay                 = 0.0f,
                                                                              float TimeScale             = 1.0f,
                                                                              bool TweenWhileGameIsPaused = false);

    /**
      * Joins to the TweenContainer a Latent Tween that rotates an Actor around a given pivot pointby an offset angle. The radius and the rotation axis will be automatically computed. The Actor will move
      * relative to its parent (if there is none, it will move in world coordinates).
      * It will be executed in parallel with the last appended Tween in the TweenContainer.
      *
      * @param TweenContainer The TweenContainer that will own the new Tween.
      * @param TweenTarget The target Actor.
      * @param OutTween (optional, output) If this pin is connected with a variable, it will contain the Tween that was just created.
      * @param PivotPoint The point around which to rotate (the TweenSpace parameter defines if it's in world space or relative space).
      * @param OffsetAngle The ending angle of the rotation (in degrees).
      * @param ReferenceAxis The reference axis used to compute the direction of the rotation. Different axes will result in different kind of rotations: experiment to find the one you need.
      * @param TweenSpace The space in which the Tween makes its update (i.e. 'world' or 'relative').
      * @param Duration The total duration of the Tween (in seconds).
      * @param EaseType	The easing functions to apply.
      * @param DeleteTweenOnHit If true the Tween will be deleted when the TweenTarget hits something.
      * @param DeleteTweenOnOverlap If true the Tween will be deleted when the TweenTarget overlaps something.
      * @param Delay The initial delay to apply to the Tween (in seconds).
      * @param TimeScale The scale to apply to the Tween execution. If < 1 the Tween will slow down, if > 1 it will speed up. If < 0 it will make the Tween go backward.
	  * @param TweenWhileGameIsPaused Sets whether the Tween should keep updating while the game is paused. Useful for Tween on UMG widgets that animate menus.
	  */
    UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly="true", DisplayName="Join Latent Tween Rotate Actor Around Point By Offset", KeyWords="Tween Rotate Actor Around Point By Offset Latent Join Parallel", AdvancedDisplay=9, AutoCreateRefTerm="OutTween"), Category = "Tween|LatentTween|Actor|Rotate")
    static UTweenFloatLatentFactory* BP_JoinLatentTweenRotateActorAroundPointByOffset(UTweenContainer* TweenContainer,
                                                                                      UTweenFloat*& OutTween,
                                                                                      AActor* TweenTarget,
                                                                                      FVector PivotPoint,
                                                                                      float OffsetAngle,
                                                                                      ETweenReferenceAxis ReferenceAxis = ETweenReferenceAxis::YAxis,
                                                                                      ETweenSpace TweenSpace            = ETweenSpace::World,
                                                                                      float Duration                    = 1.0f,
                                                                                      ETweenEaseType EaseType           = ETweenEaseType::Linear,
                                                                                      bool DeleteTweenOnHit             = false,
                                                                                      bool DeleteTweenOnOverlap         = false,
                                                                                      float Delay                       = 0.0f,
                                                                                      float TimeScale                   = 1.0f,
                                                                                      bool TweenWhileGameIsPaused       = false);

    /**
      * Joins to the TweenContainer a Latent Tween that makes an Actor follow a spline path.
      * It will be executed in parallel with the last appended Tween in the TweenContainer.
      *
      * @param TweenContainer The TweenContainer that will own the new Tween.
      * @param TweenTarget The target Actor.
      * @param OutTween (optional, output) If this pin is connected with a variable, it will contain the Tween that was just created.
      * @param Spline The SplineComponent path to follow.
      * @param Duration The total duration of the Tween (in seconds).
      * @param ApplyRotation If set, the spline rotation will be applied to the Actor.
      * @param ApplyScale If set, the spline scale will be applied to the Actor.
      * @param UseConstantSpeed If set, the movement will be at constant speed across the spline points (but it will sill take into account the easing).
      * @param EaseType	The easing functions to apply.
      * @param DeleteTweenOnHit If true the Tween will be deleted when the TweenTarget hits something.
      * @param DeleteTweenOnOverlap If true the Tween will be deleted when the TweenTarget overlaps something.
      * @param Delay The initial delay to apply to the Tween (in seconds).
      * @param TimeScale The scale to apply to the Tween execution. If < 1 the Tween will slow down, if > 1 it will speed up. If < 0 it will make the Tween go backward.
	  * @param TweenWhileGameIsPaused Sets whether the Tween should keep updating while the game is paused. Useful for Tween on UMG widgets that animate menus.
	  */
    UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly="true", DisplayName="Join Latent Tween Actor Follow Spline", KeyWords="Tween Actor Follow Spline Latent Join Parallel", AdvancedDisplay=9, AutoCreateRefTerm="OutTween"), Category = "Tween|LatentTween|Actor|Spline")
    static UTweenFloatLatentFactory* BP_JoinLatentTweenActorFollowSpline(UTweenContainer* TweenContainer,
                                                                         UTweenFloat*& OutTween,
                                                                         AActor* TweenTarget,
                                                                         USplineComponent* Spline,
                                                                         float Duration              = 1.0f,
                                                                         bool ApplyRotation          = false,
                                                                         bool ApplyScale             = false,
                                                                         bool UseConstantSpeed       = true,
                                                                         ETweenEaseType EaseType     = ETweenEaseType::Linear,
                                                                         bool DeleteTweenOnHit       = false,
                                                                         bool DeleteTweenOnOverlap   = false,
                                                                         float Delay                 = 0.0f,
                                                                         float TimeScale             = 1.0f,
                                                                         bool TweenWhileGameIsPaused = false);

    /**
      * Joins to the TweenContainer a Latent Tween that rotates an SceneComponent around a given pivot point, with a given radius and rotation axis. The SceneComponent will move
      * relative to its parent (if there is none, it will move in world coordinates).
      * It will be executed in parallel with the last appended Tween in the TweenContainer.
      *
      * @param TweenContainer The TweenContainer that will own the new Tween.
      * @param TweenTarget The target SceneComponent.
      * @param OutTween (optional, output) If this pin is connected with a variable, it will contain the Tween that was just created.
      * @param PivotPoint The point around which to rotate (the TweenSpace parameter defines if it's in world space or relative space).
      * @param StartingAngle The starting angle of the rotation (in degrees).
      * @param EndingAngle The ending angle of the rotation (in degrees).
      * @param Radius The radius of the rotation, in relation to the pivot point.
      * @param Axis The axis around which to rotate (the TweenSpace parameter defines if it's in world space or relative space).
      * @param TweenSpace The space in which the Tween makes its update (i.e. 'world' or 'relative').
      * @param Duration The total duration of the Tween (in seconds).
      * @param EaseType	The easing functions to apply.
      * @param DeleteTweenOnHit If true the Tween will be deleted when the TweenTarget hits something.
      * @param DeleteTweenOnOverlap If true the Tween will be deleted when the TweenTarget overlaps something.
      * @param Delay The initial delay to apply to the Tween (in seconds).
      * @param TimeScale The scale to apply to the Tween execution. If < 1 the Tween will slow down, if > 1 it will speed up. If < 0 it will make the Tween go backward.
	  * @param TweenWhileGameIsPaused Sets whether the Tween should keep updating while the game is paused. Useful for Tween on UMG widgets that animate menus.
	  */
    UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly="true", DisplayName="Join Latent Tween Rotate Scene Component Around Point", KeyWords="Tween Rotate Scene Component Around Point Latent Join Parallel", AdvancedDisplay=10, AutoCreateRefTerm="OutTween"), Category = "Tween|LatentTween|SceneComponent|Rotate")
    static UTweenFloatLatentFactory* BP_JoinLatentTweenRotateSceneComponentAroundPoint(UTweenContainer* TweenContainer,
                                                                                       UTweenFloat*& OutTween,
                                                                                       USceneComponent* TweenTarget,
                                                                                       FVector PivotPoint,
                                                                                       float StartingAngle,
                                                                                       float EndingAngle,
                                                                                       float Radius,
                                                                                       FVector Axis                = FVector(0.0f, 0.0f, 1.0f),
                                                                                       ETweenSpace TweenSpace      = ETweenSpace::World,
                                                                                       float Duration              = 1.0f,
                                                                                       ETweenEaseType EaseType     = ETweenEaseType::Linear,
                                                                                       bool DeleteTweenOnHit       = false,
                                                                                       bool DeleteTweenOnOverlap   = false,
                                                                                       float Delay                 = 0.0f,
                                                                                       float TimeScale             = 1.0f,
                                                                                       bool TweenWhileGameIsPaused = false);

    /**
      * Joins to the TweenContainer a Latent Tween that rotates an SceneComponent around a given pivot pointby an offset angle. The radius and the rotation axis will be automatically computed. The SceneComponent will move
      * relative to its parent (if there is none, it will move in world coordinates).
      * It will be executed in parallel with the last appended Tween in the TweenContainer.
      *
      * @param TweenContainer The TweenContainer that will own the new Tween.
      * @param TweenTarget The target SceneComponent.
      * @param OutTween (optional, output) If this pin is connected with a variable, it will contain the Tween that was just created.
      * @param PivotPoint The point around which to rotate (the TweenSpace parameter defines if it's in world space or relative space).
      * @param OffsetAngle The ending angle of the rotation (in degrees).
      * @param ReferenceAxis The reference axis used to compute the direction of the rotation. Different axes will result in different kind of rotations: experiment to find the one you need.
      * @param TweenSpace The space in which the Tween makes its update (i.e. 'world' or 'relative').
      * @param Duration The total duration of the Tween (in seconds).
      * @param EaseType	The easing functions to apply.
      * @param DeleteTweenOnHit If true the Tween will be deleted when the TweenTarget hits something.
      * @param DeleteTweenOnOverlap If true the Tween will be deleted when the TweenTarget overlaps something.
      * @param Delay The initial delay to apply to the Tween (in seconds).
      * @param TimeScale The scale to apply to the Tween execution. If < 1 the Tween will slow down, if > 1 it will speed up. If < 0 it will make the Tween go backward.
	  * @param TweenWhileGameIsPaused Sets whether the Tween should keep updating while the game is paused. Useful for Tween on UMG widgets that animate menus.
	  */
    UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly="true", DisplayName="Join Latent Tween Rotate Scene Component Around Point By Offset", KeyWords="Tween Rotate Scene Component Around Point By Offset Latent Join Parallel", AdvancedDisplay=9, AutoCreateRefTerm="OutTween"), Category = "Tween|LatentTween|SceneComponent|Rotate")
    static UTweenFloatLatentFactory* BP_JoinLatentTweenRotateSceneComponentAroundPointByOffset(UTweenContainer* TweenContainer,
                                                                                               UTweenFloat*& OutTween,
                                                                                               USceneComponent* TweenTarget,
                                                                                               FVector PivotPoint,
                                                                                               float OffsetAngle,
                                                                                               ETweenReferenceAxis ReferenceAxis = ETweenReferenceAxis::YAxis,
                                                                                               ETweenSpace TweenSpace            = ETweenSpace::World,
                                                                                               float Duration                    = 1.0f,
                                                                                               ETweenEaseType EaseType           = ETweenEaseType::Linear,
                                                                                               bool DeleteTweenOnHit             = false,
                                                                                               bool DeleteTweenOnOverlap         = false,
                                                                                               float Delay                       = 0.0f,
                                                                                               float TimeScale                   = 1.0f,
                                                                                               bool TweenWhileGameIsPaused       = false);

    /**
      * Joins to the TweenContainer a Latent Tween that makes an SceneComponent follow a spline path.
      * It will be executed in parallel with the last appended Tween in the TweenContainer.
      *
      * @param TweenContainer The TweenContainer that will own the new Tween.
      * @param TweenTarget The target SceneComponent.
      * @param OutTween (optional, output) If this pin is connected with a variable, it will contain the Tween that was just created.
      * @param Spline The SplineComponent path to follow.
      * @param Duration The total duration of the Tween (in seconds).
      * @param ApplyRotation If set, the spline rotation will be applied to the SceneComponent.
      * @param ApplyScale If set, the spline scale will be applied to the SceneComponent.
      * @param UseConstantSpeed If set, the movement will be at constant speed across the spline points (but it will sill take into account the easing).
      * @param EaseType	The easing functions to apply.
      * @param DeleteTweenOnHit If true the Tween will be deleted when the TweenTarget hits something.
      * @param DeleteTweenOnOverlap If true the Tween will be deleted when the TweenTarget overlaps something.
      * @param Delay The initial delay to apply to the Tween (in seconds).
      * @param TimeScale The scale to apply to the Tween execution. If < 1 the Tween will slow down, if > 1 it will speed up. If < 0 it will make the Tween go backward.
	  * @param TweenWhileGameIsPaused Sets whether the Tween should keep updating while the game is paused. Useful for Tween on UMG widgets that animate menus.
	  */
    UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly="true", DisplayName="Join Latent Tween Scene Component Follow Spline", KeyWords="Tween Scene Component Follow Spline Latent Join Parallel", AdvancedDisplay=9, AutoCreateRefTerm="OutTween"), Category = "Tween|LatentTween|SceneComponent|Spline")
    static UTweenFloatLatentFactory* BP_JoinLatentTweenSceneComponentFollowSpline(UTweenContainer* TweenContainer,
                                                                                  UTweenFloat*& OutTween,
                                                                                  USceneComponent* TweenTarget,
                                                                                  USplineComponent* Spline,
                                                                                  float Duration              = 1.0f,
                                                                                  bool ApplyRotation          = false,
                                                                                  bool ApplyScale             = false,
                                                                                  bool UseConstantSpeed       = true,
                                                                                  ETweenEaseType EaseType     = ETweenEaseType::Linear,
                                                                                  bool DeleteTweenOnHit       = false,
                                                                                  bool DeleteTweenOnOverlap   = false,
                                                                                  float Delay                 = 0.0f,
                                                                                  float TimeScale             = 1.0f,
                                                                                  bool TweenWhileGameIsPaused = false);

    /**
      * Joins to the TweenContainer a Latent Tween that makes a UMG widget rotate to the given angle.
      * It will be executed in parallel with the last appended Tween in the TweenContainer.
      *
      * @param TweenContainer The TweenContainer that will own the new Tween.
      * @param TweenTarget The target Widget.
      * @param OutTween (optional, output) If this pin is connected with a variable, it will contain the Tween that was just created.
      * @param To The ending value.
      * @param Duration The total duration of the Tween (in seconds).
      * @param EaseType	The easing functions to apply.
      * @param Delay The initial delay to apply to the Tween (in seconds).
      * @param TimeScale The scale to apply to the Tween execution. If < 1 the Tween will slow down, if > 1 it will speed up. If < 0 it will make the Tween go backward.
	  * @param TweenWhileGameIsPaused Sets whether the Tween should keep updating while the game is paused. Useful for Tween on UMG widgets that animate menus.
	  */
    UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly="true", DisplayName="Join Latent Tween Widget Angle To", KeyWords="Tween Widget Angle To UMG Latent Join Parallel", AdvancedDisplay=6, AutoCreateRefTerm="OutTween"), Category = "Tween|LatentTween|UMG|Angle")
    static UTweenFloatLatentFactory* BP_JoinLatentTweenWidgetAngleTo(UTweenContainer* TweenContainer,
                                                                     UTweenFloat*& OutTween,
                                                                      UWidget* TweenTarget,
                                                                     float To,
                                                                     float Duration              = 1.0f,
                                                                     ETweenEaseType EaseType     = ETweenEaseType::Linear,
                                                                     float Delay                 = 0.0f,
                                                                     float TimeScale             = 1.0f,
                                                                     bool TweenWhileGameIsPaused = false);

    /**
      * Joins to the TweenContainer a Latent Tween that makes a UMG widget's opacity reach the given value.
      * It will be executed in parallel with the last appended Tween in the TweenContainer.
      *
      * @param TweenContainer The TweenContainer that will own the new Tween.
      * @param TweenTarget The target Widget.
      * @param OutTween (optional, output) If this pin is connected with a variable, it will contain the Tween that was just created.
      * @param To The ending value.
      * @param Duration The total duration of the Tween (in seconds).
      * @param EaseType	The easing functions to apply.
      * @param Delay The initial delay to apply to the Tween (in seconds).
      * @param TimeScale The scale to apply to the Tween execution. If < 1 the Tween will slow down, if > 1 it will speed up. If < 0 it will make the Tween go backward.
	  * @param TweenWhileGameIsPaused Sets whether the Tween should keep updating while the game is paused. Useful for Tween on UMG widgets that animate menus.
	  */
    UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly="true", DisplayName="Join Latent Tween Widget Opacity To", KeyWords="Tween Widget Opacity To UMG Latent Join Parallel", AdvancedDisplay=6, AutoCreateRefTerm="OutTween"), Category = "Tween|LatentTween|UMG|Opacity")
    static UTweenFloatLatentFactory* BP_JoinLatentTweenWidgetOpacityTo(UTweenContainer* TweenContainer,
                                                                       UTweenFloat*& OutTween,
                                                                       UWidget* TweenTarget,
                                                                       float To,
                                                                       float Duration              = 1.0f,
                                                                       ETweenEaseType EaseType     = ETweenEaseType::Linear,
                                                                       float Delay                 = 0.0f,
                                                                       float TimeScale             = 1.0f,
                                                                       bool TweenWhileGameIsPaused = false);

    /**
      * Joins to the TweenContainer a custom Latent Tween that goes from a starting float value to an ending one. This type of Tween is meant for creating custom behaviours
      * by binding a function or an event to the OnTweenUpdate delegate in order to use the tweened value at each Tick by calling GetCurrentValue from the Tween object.
      * It will be executed in parallel with the last appended Tween in the TweenContainer.
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
    UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly="true", DisplayName="Join Latent Tween Custom Float", KeyWords="Tween Custom Float Latent Join Parallel", AdvancedDisplay=7, AutoCreateRefTerm="OutTween"), Category = "Tween|LatentTween|Custom")
    static UTweenFloatLatentFactory* BP_JoinLatentTweenCustomFloat(UTweenContainer* TweenContainer,
                                                                   UTweenFloat*& OutTween,
                                                                   UObject* TweenTarget,
                                                                   float From,
                                                                   float To,
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

    static UTweenFloatLatentFactory* CreateProxyForAppendTweenFloat(UTweenContainer* pTweenContainer,
                                                                    ETweenFloatType pTweenType,
                                                                    UObject* pTarget,
                                                                    ETweenTargetType pTargetType,
                                                                    float pFrom,
                                                                    float pTo,
                                                                    float Duration,
                                                                    ETweenEaseType pEaseType,
                                                                    int32 pNumLoops,
                                                                    ETweenLoopType pLoopType,
                                                                    float pDelay,
                                                                    float pTimeScale,
                                                                    bool pTweenWhileGameIsPaused,
                                                                    UTweenFloat*& OutTween,
                                                                    FName pParameterName = FName("None"));

    static UTweenFloatLatentFactory* CreateProxyForJoinTweenFloat(UTweenContainer* pTweenContainer,
                                                                  ETweenFloatType pTweenType,
                                                                  UObject* pTarget,
                                                                  ETweenTargetType pTargetType,
                                                                  float pFrom,
                                                                  float pTo,
                                                                  float pDuration,
                                                                  ETweenEaseType pEaseType,
                                                                  float pDelay,
                                                                  float pTimeScale,
                                                                  bool pTweenWhileGameIsPaused,
                                                                  UTweenFloat*& OutTween,
                                                                  FName pParameterName = FName("None"));

    // For "rotate around"
    static UTweenFloatLatentFactory* CreateProxyForAppendTweenRotateAroundFloat(UTweenContainer* pTweenContainer,
                                                                                ETweenFloatType pTweenType,
                                                                                UObject* pTarget,
                                                                                ETweenTargetType pTargetType,
                                                                                const FVector& pPoint,
                                                                                float pStartingAngle,
                                                                                float pEndingAngle,
                                                                                float pRadius,
                                                                                const FVector& pAxis,
                                                                                ETweenSpace pTweenSpace,
                                                                                float pDuration,
                                                                                ETweenEaseType pEaseType,
                                                                                bool pDeleteTweenOnHit,
                                                                                bool pDeleteTweenOnOverlap,
                                                                                int32 pNumLoops,
                                                                                ETweenLoopType pLoopType,
                                                                                float pDelay,
                                                                                float pTimeScale,
                                                                                bool pTweenWhileGameIsPaused,
                                                                                UTweenFloat*& OutTween);

    static UTweenFloatLatentFactory* CreateProxyForJoinTweenRotateAroundFloat(UTweenContainer* pTweenContainer,
                                                                              ETweenFloatType pTweenType,
                                                                              UObject* pTarget,
                                                                              ETweenTargetType pTargetType,
                                                                              const FVector& pPoint,
                                                                              float pStartingAngle,
                                                                              float pEndingAngle,
                                                                              float pRadius,
                                                                              const FVector& pAxis,
                                                                              ETweenSpace pTweenSpace,
                                                                              float pDuration,
                                                                              ETweenEaseType pEaseType,
                                                                              bool pDeleteTweenOnHit,
                                                                              bool pDeleteTweenOnOverlap,
                                                                              float pDelay,
                                                                              float pTimeScale,
                                                                              bool pTweenWhileGameIsPaused,
                                                                              UTweenFloat*& OutTween);


    // For splines
    static UTweenFloatLatentFactory* CreateProxyForAppendTweenFollowSpline(UTweenContainer* pTweenContainer,
                                                                           ETweenFloatType pTweenType,
                                                                           UObject* pTarget,
                                                                           ETweenTargetType pTargetType,
                                                                           USplineComponent* pSpline,
                                                                           bool pApplyRotation,
                                                                           bool pApplyScale,
                                                                           bool pUseConstantSpeed,
                                                                           float pDuration,
                                                                           ETweenEaseType pEaseType,
                                                                           bool pDeleteTweenOnHit,
                                                                           bool pDeleteTweenOnOverlap,
                                                                           int32 pNumLoops,
                                                                           ETweenLoopType pLoopType,
                                                                           float pDelay,
                                                                           float pTimeScale,
                                                                           bool pTweenWhileGameIsPaused,
                                                                           UTweenFloat*& OutTween);

    static UTweenFloatLatentFactory* CreateProxyForJoinTweenFollowSpline(UTweenContainer* pTweenContainer,
                                                                         ETweenFloatType pTweenType,
                                                                         UObject* pTarget,
                                                                         ETweenTargetType pTargetType,
                                                                         USplineComponent* pSpline,
                                                                         bool pApplyRotation,
                                                                         bool pApplyScale,
                                                                         bool pUseConstantSpeed,
                                                                         float pDuration,
                                                                         ETweenEaseType pEaseType,
                                                                         bool pDeleteTweenOnHit,
                                                                         bool pDeleteTweenOnOverlap,
                                                                         float pDelay,
                                                                         float pTimeScale,
                                                                         bool pTweenWhileGameIsPaused,
                                                                         UTweenFloat*& OutTween);
};
