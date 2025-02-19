// Copyright 2018 Francesco Desogus. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"

#include "TweenManagerComponent.h"
#include "Utils/TweenEnums.h"

#include "TweenFloatStandardFactory.generated.h"

class ATweenManagerActor;
class UTweenManagerComponent;
class UTweenContainer;
class UBaseTween;
class UTweenFloat;
class UMaterialInstanceDynamic;
class USplineComponent;
class UWidget;

/**
 * @brief The UTweenFloatStandardFactory class handles the creation of all float related Tweens, i.e. all tweens that
 *        in order to be executed they need to change a single float value.
 *
 *        The methods here are "standard", meaning that if the user wishes to use one of the tween callbacks (OnTweenStart,
 *        OnTweenUpdate, OnTweenEnd) he has to manually bind the delegates.
 */
UCLASS()
class TWEENMAKER_API UTweenFloatStandardFactory : public UObject
{
    GENERATED_BODY()

public:

    /**
     * @brief Constructor.
     */
    UTweenFloatStandardFactory(const FObjectInitializer& ObjectInitializer);

    /*
     **************************************************************************
     * "Create" methods
     **************************************************************************
     */

    /**
      * Creates a Tween that modifies a "float" material parameter from the starting value to the ending value.
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
    UFUNCTION(BlueprintCallable, meta = (DisplayName="Create Tween Material Float From To", KeyWords="Tween Tween Material Float From To Create", AdvancedDisplay=8, HidePin=SequenceIndex), Category = "Tween|StandardTween|Material")
    static void BP_CreateTweenMaterialFloatFromTo(UTweenManagerComponent* TweenManager,
                                                  UMaterialInstanceDynamic* TweenTarget,
                                                  UTweenContainer*& TweenContainer,
                                                  UTweenFloat*& Tween,
                                                  FName ParameterName,
                                                  float From,
                                                  float To,
                                                  float Duration              = 1.0f,
                                                  ETweenEaseType EaseType     = ETweenEaseType::Linear,
                                                  int32 NumLoops              = 1,
                                                  ETweenLoopType LoopType     = ETweenLoopType::Yoyo,
                                                  float Delay                 = 0.0f,
                                                  float TimeScale             = 1.0f,
                                                  bool TweenWhileGameIsPaused = false,
                                                  int32 SequenceIndex         = -1);


    /**
      * Creates a Tween that modifies a "float" material parameter from its current value (at the start of the Tween) to the ending value.
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
    UFUNCTION(BlueprintCallable, meta = (DisplayName="Create Tween Material Float To", KeyWords="Tween Tween Material Float To Create", AdvancedDisplay=7, HidePin=SequenceIndex), Category = "Tween|StandardTween|Material")
    static void BP_CreateTweenMaterialFloatTo(UTweenManagerComponent* TweenManager,
                                              UMaterialInstanceDynamic* TweenTarget,
                                              UTweenContainer*& TweenContainer,
                                              UTweenFloat*& Tween,
                                              FName ParameterName,
                                              float To,
                                              float Duration              = 1.0f,
                                              ETweenEaseType EaseType     = ETweenEaseType::Linear,
                                              int32 NumLoops              = 1,
                                              ETweenLoopType LoopType     = ETweenLoopType::Yoyo,
                                              float Delay                 = 0.0f,
                                              float TimeScale             = 1.0f,
                                              bool TweenWhileGameIsPaused = false,
                                              int32 SequenceIndex         = -1);

    /**
      * Creates a Tween that rotates an Actor around a given pivot point, with a given radius and rotation axis. The Actor will move
      * relative to its parent (if there is none, it will move in world coordinates).
      * With this function a new TweenContainer will be created, which will hold any other Tween appended/joined to this one.
      *
      * @param TweenManager (optional) The TweenManager that will handle the Tween. If none is passed, the global TweenManagerActor will be used if present.
      * @param TweenTarget The target Actor.
      * @param TweenContainer The TweenContainer that owns the Tween.
      * @param Tween The created Tween.
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
      * @param SequenceIndex The index of the sequence in which the new Tween should be added (hidden in Blueprint).
      * @param TweenWhileGameIsPaused Sets whether the Tween should keep updating while the game is paused. Useful for Tween on UMG widgets that animate menus.
      */
    UFUNCTION(BlueprintCallable, meta = (DisplayName="Create Tween Rotate Actor Around Point", KeyWords="Tween Rotate Actor Around Point Create", AdvancedDisplay=11, HidePin=SequenceIndex), Category = "Tween|StandardTween|Actor|Rotate")
    static void BP_CreateTweenRotateActorAroundPoint(UTweenManagerComponent* TweenManager,
                                                     AActor* TweenTarget,
                                                     UTweenContainer*& TweenContainer,
                                                     UTweenFloat*& Tween,
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
                                                     bool TweenWhileGameIsPaused = false,
                                                     int32 SequenceIndex         = -1);

    /**
      * Creates a Tween that rotates an Actor around a given pivot point by an offset angle. The radius and the rotation axis will be automatically computed. The Actor will move
      * relative to its parent (if there is none, it will move in world coordinates).
      * With this function a new TweenContainer will be created, which will hold any other Tween appended/joined to this one.
      *
      * @param TweenManager (optional) The TweenManager that will handle the Tween. If none is passed, the global TweenManagerActor will be used if present.
      * @param TweenTarget The target Actor.
      * @param TweenContainer The TweenContainer that owns the Tween.
      * @param Tween The created Tween.
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
      * @param SequenceIndex The index of the sequence in which the new Tween should be added (hidden in Blueprint).
      * @param TweenWhileGameIsPaused Sets whether the Tween should keep updating while the game is paused. Useful for Tween on UMG widgets that animate menus.
      */
    UFUNCTION(BlueprintCallable, meta = (DisplayName="Create Tween Rotate Actor Around Point By Offset", KeyWords="Tween Rotate Actor Around Point By Offset Create", AdvancedDisplay=10, HidePin=SequenceIndex), Category = "Tween|StandardTween|Actor|Rotate")
    static void BP_CreateTweenRotateActorAroundPointByOffset(UTweenManagerComponent* TweenManager,
                                                             AActor* TweenTarget,
                                                             UTweenContainer*& TweenContainer,
                                                             UTweenFloat*& Tween,
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
                                                             bool TweenWhileGameIsPaused       = false,
                                                             int32 SequenceIndex               = -1);

    /**
      * Creates a Tween that makes an Actor follow a spline path.
      * With this function a new TweenContainer will be created, which will hold any other Tween appended/joined to this one.
      *
      * @param TweenManager (optional) The TweenManager that will handle the Tween. If none is passed, the global TweenManagerActor will be used if present.
      * @param TweenTarget The target Actor.
      * @param TweenContainer The TweenContainer that owns the Tween.
      * @param Tween The created Tween.
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
      * @param SequenceIndex The index of the sequence in which the new Tween should be added (hidden in Blueprint).
      * @param TweenWhileGameIsPaused Sets whether the Tween should keep updating while the game is paused. Useful for Tween on UMG widgets that animate menus.
      */
    UFUNCTION(BlueprintCallable, meta = (DisplayName="Create Tween Actor Follow Spline", KeyWords="Tween Actor Follow Spline Create", AdvancedDisplay=10, HidePin=SequenceIndex), Category = "Tween|StandardTween|Actor|Spline")
    static void BP_CreateTweenActorFollowSpline(UTweenManagerComponent* TweenManager,
                                                AActor* TweenTarget,
                                                UTweenContainer*& TweenContainer,
                                                UTweenFloat*& Tween,
                                                USplineComponent* Spline,
                                                float Duration              = 1.0f,
                                                bool ApplyRotation          = false,
                                                bool ApplyScale             = false,
                                                bool UseConstantSpeed       = true,
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
      * Creates a Tween that rotates a SceneComponent around a given pivot point, with a given radius and rotation axis. The SceneComponent will move
      * relative to its parent (if there is none, it will move in world coordinates).
      * With this function a new TweenContainer will be created, which will hold any other Tween appended/joined to this one.
      *
      * @param TweenManager (optional) The TweenManager that will handle the Tween. If none is passed, the global TweenManagerActor will be used if present.
      * @param TweenTarget The target SceneComponent.
      * @param TweenContainer The TweenContainer that owns the Tween.
      * @param Tween The created Tween.
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
      * @param SequenceIndex The index of the sequence in which the new Tween should be added (hidden in Blueprint).
      * @param TweenWhileGameIsPaused Sets whether the Tween should keep updating while the game is paused. Useful for Tween on UMG widgets that animate menus.
      */
    UFUNCTION(BlueprintCallable, meta = (DisplayName="Create Tween Rotate Scene Component Around Point", KeyWords="Tween Rotate Scene Component Around Point Create", AdvancedDisplay=11, HidePin=SequenceIndex), Category = "Tween|StandardTween|SceneComponent|Rotate")
    static void BP_CreateTweenRotateSceneComponentAroundPoint(UTweenManagerComponent* TweenManager,
                                                              USceneComponent* TweenTarget,
                                                              UTweenContainer*& TweenContainer,
                                                              UTweenFloat*& Tween,
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
                                                              bool TweenWhileGameIsPaused = false,
                                                              int32 SequenceIndex         = -1);

    /**
      * Creates a Tween that rotates a SceneComponent around a given pivot point by an offset angle. The radius and the rotation axis will be automatically computed.
      * The SceneComponent will move relative to its parent (if there is none, it will move in world coordinates).
      * With this function a new TweenContainer will be created, which will hold any other Tween appended/joined to this one.
      *
      * @param TweenManager (optional) The TweenManager that will handle the Tween. If none is passed, the global TweenManagerActor will be used if present.
      * @param TweenTarget The target SceneComponent.
      * @param TweenContainer The TweenContainer that owns the Tween.
      * @param Tween The created Tween.
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
      * @param SequenceIndex The index of the sequence in which the new Tween should be added (hidden in Blueprint).
      * @param TweenWhileGameIsPaused Sets whether the Tween should keep updating while the game is paused. Useful for Tween on UMG widgets that animate menus.
      */
    UFUNCTION(BlueprintCallable, meta = (DisplayName="Create Tween Rotate Scene Component Around Point By Offset", KeyWords="Tween Rotate Scene Component Around Point By Offset Create", AdvancedDisplay=10, HidePin=SequenceIndex), Category = "Tween|StandardTween|SceneComponent|Rotate")
    static void BP_CreateTweenRotateSceneComponentAroundPointByOffset(UTweenManagerComponent* TweenManager,
                                                                      USceneComponent* TweenTarget,
                                                                      UTweenContainer*& TweenContainer,
                                                                      UTweenFloat*& Tween,
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
                                                                      bool TweenWhileGameIsPaused       = false,
                                                                      int32 SequenceIndex               = -1);

    /**
      * Creates a Tween that makes an SceneComponent follow a spline path.
      * With this function a new TweenContainer will be created, which will hold any other Tween appended/joined to this one.
      *
      * @param TweenManager (optional) The TweenManager that will handle the Tween. If none is passed, the global TweenManagerActor will be used if present.
      * @param TweenTarget The target SceneComponent.
      * @param TweenContainer The TweenContainer that owns the Tween.
      * @param Tween The created Tween.
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
      * @param SequenceIndex The index of the sequence in which the new Tween should be added (hidden in Blueprint).
      * @param TweenWhileGameIsPaused Sets whether the Tween should keep updating while the game is paused. Useful for Tween on UMG widgets that animate menus.
      */
    UFUNCTION(BlueprintCallable, meta = (DisplayName="Create Tween Scene Component Follow Spline", KeyWords="Tween Scene Component Follow Spline Create", AdvancedDisplay=10, HidePin=SequenceIndex), Category = "Tween|StandardTween|SceneComponent|Spline")
    static void BP_CreateTweenSceneComponentFollowSpline(UTweenManagerComponent* TweenManager,
                                                         USceneComponent* TweenTarget,
                                                         UTweenContainer*& TweenContainer,
                                                         UTweenFloat*& Tween,
                                                         USplineComponent* Spline,
                                                         float Duration              = 1.0f,
                                                         bool ApplyRotation          = false,
                                                         bool ApplyScale             = false,
                                                         bool UseConstantSpeed       = true,
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
      * Creates a Tween that makes a UMG widget rotate to the given angle.
      * With this function a new TweenContainer will be created, which will hold any other Tween appended/joined to this one.
      *
      * @param TweenManager (optional) The TweenManager that will handle the Tween. If none is passed, the global TweenManagerActor will be used if present.
      * @param TweenTarget The target Widget.
      * @param TweenContainer The TweenContainer that owns the Tween.
      * @param Tween The created Tween.
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
    UFUNCTION(BlueprintCallable, meta = (DisplayName="Create Tween Widget Angle To", KeyWords="Tween Widget Angle To UMG", AdvancedDisplay=7, HidePin=SequenceIndex), Category = "Tween|StandardTween|UMG|Angle")
    static void BP_CreateTweenWidgetAngleTo(UTweenManagerComponent* TweenManager,
                                            UWidget* TweenTarget,
                                            UTweenContainer*& TweenContainer,
                                            UTweenFloat*& Tween,
                                            float To,
                                            float Duration              = 1.0f,
                                            ETweenEaseType EaseType     = ETweenEaseType::Linear,
                                            int32 NumLoops              = 1,
                                            ETweenLoopType LoopType     = ETweenLoopType::Yoyo,
                                            float Delay                 = 0.0f,
                                            float TimeScale             = 1.0f,
                                            bool TweenWhileGameIsPaused = false,
                                            int32 SequenceIndex         = -1);

    /**
      * Creates a Tween that makes a UMG widget's opacity reach the given value.
      * With this function a new TweenContainer will be created, which will hold any other Tween appended/joined to this one.
      *
      * @param TweenManager (optional) The TweenManager that will handle the Tween. If none is passed, the global TweenManagerActor will be used if present.
      * @param TweenTarget The target Widget.
      * @param TweenContainer The TweenContainer that owns the Tween.
      * @param Tween The created Tween.
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
    UFUNCTION(BlueprintCallable, meta = (DisplayName="Create Tween Widget Opacity To", KeyWords="Tween Widget Opacity To UMG", AdvancedDisplay=7, HidePin=SequenceIndex), Category = "Tween|StandardTween|UMG|Opacity")
    static void BP_CreateTweenWidgetOpacityTo(UTweenManagerComponent* TweenManager,
                                              UWidget* TweenTarget,
                                              UTweenContainer*& TweenContainer,
                                              UTweenFloat*& Tween,
                                              float To,
                                              float Duration              = 1.0f,
                                              ETweenEaseType EaseType     = ETweenEaseType::Linear,
                                              int32 NumLoops              = 1,
                                              ETweenLoopType LoopType     = ETweenLoopType::Yoyo,
                                              float Delay                 = 0.0f,
                                              float TimeScale             = 1.0f,
                                              bool TweenWhileGameIsPaused = false,
                                              int32 SequenceIndex         = -1);

    /**
      * Creates a custom Tween that goes from a starting float value to an ending one. This type of Tween is meant for creating custom behaviours
      * by binding a function or an event to the OnTweenUpdate delegate in order to use the tweened value at each Tick by calling GetCurrentValue from the Tween object.
      * With this function a new TweenContainer will be created, which will hold any other Tween appended/joined to this one.
      *
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
      * @param SequenceIndex The index of the sequence in which the new Tween should be added (hidden in Blueprint).
      * @param TweenWhileGameIsPaused Sets whether the Tween should keep updating while the game is paused. Useful for Tween on UMG widgets that animate menus.
      */
    UFUNCTION(BlueprintCallable, meta = (DisplayName="Create Tween Custom Float", KeyWords="Tween Float Create", AdvancedDisplay=8, HidePin=SequenceIndex), Category = "Tween|StandardTween|Custom")
    static void BP_CreateTweenCustomFloat(UTweenManagerComponent* TweenManager,
                                          UObject* TweenTarget,
                                          UTweenContainer*& TweenContainer,
                                          UTweenFloat*& Tween,
                                          float From,
                                          float To,
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
      * Appends to the TweenContainer a Tween that modifies a "float" material parameter from the starting value to the ending value.
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
    UFUNCTION(BlueprintCallable, meta = (DisplayName="Append Tween Material Float From To", KeyWords="Tween Tween Material Float From To Append Sequence", AdvancedDisplay=6, HidePin=SequenceIndex), Category = "Tween|StandardTween|Material")
    static UTweenFloat* BP_AppendTweenMaterialFloatFromTo(UTweenContainer* TweenContainer,
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
                                                          bool TweenWhileGameIsPaused = false,
                                                          int32 SequenceIndex         = -1);
    
    /**
      * Appends to the TweenContainer a Tween that modifies a "float" material parameter from its current value (at the start of the Tween) to the ending value.
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
    UFUNCTION(BlueprintCallable, meta = (DisplayName="Append Tween Material Float To", KeyWords="Tween Tween Material Float To Append Sequence", AdvancedDisplay=5, HidePin=SequenceIndex), Category = "Tween|StandardTween|Material")
    static UTweenFloat* BP_AppendTweenMaterialFloatTo(UTweenContainer* TweenContainer,
                                                      UMaterialInstanceDynamic* TweenTarget,
                                                      FName ParameterName,
                                                      float To,
                                                      float Duration              = 1.0f,
                                                      ETweenEaseType EaseType     = ETweenEaseType::Linear,
                                                      int32 NumLoops              = 1,
                                                      ETweenLoopType LoopType     = ETweenLoopType::Yoyo,
                                                      float Delay                 = 0.0f,
                                                      float TimeScale             = 1.0f,
                                                      bool TweenWhileGameIsPaused = false,
                                                      int32 SequenceIndex         = -1);

    /**
      * Appends to the TweenContainer a Tween that rotates an Actor around a given pivot point, with a given radius and rotation axis. The Actor will move
      * relative to its parent (if there is none, it will move in world coordinates).
      * It will be executed when all previous Tweens in the TweenContainer are completed.
      *
      * @param TweenContainer The TweenContainer that will own the new Tween.
      * @param TweenTarget The target Actor.
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
      * @param SequenceIndex The index of the sequence in which the new Tween should be added (hidden in Blueprint).
      * @param TweenWhileGameIsPaused Sets whether the Tween should keep updating while the game is paused. Useful for Tween on UMG widgets that animate menus.
      *
      * @return The newly created Tween.
      */
    UFUNCTION(BlueprintCallable, meta = (DisplayName="Append Tween Rotate Actor Around Point", KeyWords="Tween Rotate Actor Around Point Append Sequence", AdvancedDisplay=9, HidePin=SequenceIndex), Category = "Tween|StandardTween|Actor|Rotate")
    static UTweenFloat* BP_AppendTweenRotateActorAroundPoint(UTweenContainer* TweenContainer,
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
                                                             bool TweenWhileGameIsPaused = false,
                                                             int32 SequenceIndex         = -1);

    /**
      * Appends to the TweenContainer a Tween that rotates an Actor around a given pivot point by an offset angle. The radius and the rotation axis will be automatically computed.
      * The Actor will move relative to its parent (if there is none, it will move in world coordinates).
      * It will be executed when all previous Tweens in the TweenContainer are completed.
      *
      * @param TweenContainer The TweenContainer that will own the new Tween.
      * @param TweenTarget The target Actor.
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
      * @param SequenceIndex The index of the sequence in which the new Tween should be added (hidden in Blueprint).
      *
      * @return The newly created Tween.
      */
    UFUNCTION(BlueprintCallable, meta = (DisplayName="Append Tween Rotate Actor Around Point By Offset", KeyWords="Tween Rotate Actor Around Point By Offset Append Sequence", AdvancedDisplay=8, HidePin=SequenceIndex), Category = "Tween|StandardTween|Actor|Rotate")
    static UTweenFloat* BP_AppendTweenRotateActorAroundPointByOffset(UTweenContainer* TweenContainer,
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
                                                                     bool TweenWhileGameIsPaused       = false,
                                                                     int32 SequenceIndex               = -1);

    /**
      * Appends to the TweenContainer a Tween that makes an Actor follow a spline path.
      * It will be executed when all previous Tweens in the TweenContainer are completed.
      *
      * @param TweenContainer The TweenContainer that will own the new Tween.
      * @param TweenTarget The target Actor.
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
      * @param SequenceIndex The index of the sequence in which the new Tween should be added (hidden in Blueprint).
      *
      * @return The newly created Tween.
      */
    UFUNCTION(BlueprintCallable, meta = (DisplayName="Append Tween Actor Follow Spline", KeyWords="Tween Actor Follow Spline Append Sequence", AdvancedDisplay=9, HidePin=SequenceIndex), Category = "Tween|StandardTween|Actor|Spline")
    static UTweenFloat* BP_AppendTweenActorFollowSpline(UTweenContainer* TweenContainer,
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
                                                        ETweenLoopType LoopType     = ETweenLoopType::Yoyo,
                                                        float Delay                 = 0.0f,
                                                        float TimeScale             = 1.0f,
                                                        bool TweenWhileGameIsPaused = false,
                                                        int32 SequenceIndex         = -1);

    /**
      * Appends to the TweenContainer a Tween that rotates an SceneComponent around a given pivot point, with a given radius and rotation axis. The SceneComponent will move
      * relative to its parent (if there is none, it will move in world coordinates).
      * It will be executed when all previous Tweens in the TweenContainer are completed.
      *
      * @param TweenContainer The TweenContainer that will own the new Tween.
      * @param TweenTarget The target SceneComponent.
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
      * @param SequenceIndex The index of the sequence in which the new Tween should be added (hidden in Blueprint).
      *
      * @return The newly created Tween.
      */
    UFUNCTION(BlueprintCallable, meta = (DisplayName="Append Tween Rotate Scene Component Around Point", KeyWords="Tween Rotate Scene Component Around Point Append Sequence", AdvancedDisplay=9, HidePin=SequenceIndex), Category = "Tween|StandardTween|SceneComponent|Rotate")
    static UTweenFloat* BP_AppendTweenRotateSceneComponentAroundPoint(UTweenContainer* TweenContainer,
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
                                                                      bool TweenWhileGameIsPaused = false,
                                                                      int32 SequenceIndex         = -1);

    /**
      * Appends to the TweenContainer a Tween that rotates an SceneComponent around a given pivot point by an offset angle. The radius and the rotation axis will be automatically computed. The SceneComponent will move
      * relative to its parent (if there is none, it will move in world coordinates).
      * It will be executed when all previous Tweens in the TweenContainer are completed.
      *
      * @param TweenContainer The TweenContainer that will own the new Tween.
      * @param TweenTarget The target SceneComponent.
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
      * @param SequenceIndex The index of the sequence in which the new Tween should be added (hidden in Blueprint).
      *
      * @return The newly created Tween.
      */
    UFUNCTION(BlueprintCallable, meta = (DisplayName="Append Tween Rotate Scene Component Around Point By Offset", KeyWords="Tween Rotate Scene Component Around Point By Offset Append Sequence", AdvancedDisplay=8, HidePin=SequenceIndex), Category = "Tween|StandardTween|SceneComponent|Rotate")
    static UTweenFloat* BP_AppendTweenRotateSceneComponentAroundPointByOffset(UTweenContainer* TweenContainer,
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
                                                                              bool TweenWhileGameIsPaused       = false,
                                                                              int32 SequenceIndex               = -1);
    
    /**
      * Appends to the TweenContainer a Tween that makes an SceneComponent follow a spline path.
      * It will be executed when all previous Tweens in the TweenContainer are completed.
      *
      * @param TweenContainer The TweenContainer that will own the new Tween.
      * @param TweenTarget The target SceneComponent.
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
      * @param SequenceIndex The index of the sequence in which the new Tween should be added (hidden in Blueprint).
      *
      * @return The newly created Tween.
      */
    UFUNCTION(BlueprintCallable, meta = (DisplayName="Append Tween Scene Component Follow Spline", KeyWords="Tween Scene Component Follow Spline Append Sequence", AdvancedDisplay=9, HidePin=SequenceIndex), Category = "Tween|StandardTween|SceneComponent|Spline")
    static UTweenFloat* BP_AppendTweenSceneComponentFollowSpline(UTweenContainer* TweenContainer,
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
                                                                 ETweenLoopType LoopType     = ETweenLoopType::Yoyo,
                                                                 float Delay                 = 0.0f,
                                                                 float TimeScale             = 1.0f,
                                                                 bool TweenWhileGameIsPaused = false,
                                                                 int32 SequenceIndex         = -1);

    /**
      * Appends to the TweenContainer a Tween that makes a UMG widget rotate to the given angle.
      * It will be executed when all previous Tweens in the TweenContainer are completed.
      *
      * @param TweenContainer The TweenContainer that will own the new Tween.
      * @param TweenTarget The target Widget.
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
    UFUNCTION(BlueprintCallable, meta = (DisplayName="Append Tween Widget Angle To", KeyWords="Tween Widget Angle To UMG Sequence", AdvancedDisplay=5, HidePin=SequenceIndex), Category = "Tween|StandardTween|UMG|Angle")
    static UTweenFloat* BP_AppendTweenWidgetAngleTo(UTweenContainer* TweenContainer,
                                                    UWidget* TweenTarget,
                                                    float To,
                                                    float Duration              = 1.0f,
                                                    ETweenEaseType EaseType     = ETweenEaseType::Linear,
                                                    int32 NumLoops              = 1,
                                                    ETweenLoopType LoopType     = ETweenLoopType::Yoyo,
                                                    float Delay                 = 0.0f,
                                                    float TimeScale             = 1.0f,
                                                    bool TweenWhileGameIsPaused = false,
                                                    int32 SequenceIndex         = -1);

    /**
      * Appends to the TweenContainer a Tween that makes a UMG widget's opacity reach the given value.
      * It will be executed when all previous Tweens in the TweenContainer are completed.
      *
      * @param TweenContainer The TweenContainer that will own the new Tween.
      * @param TweenTarget The target Widget.
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
    UFUNCTION(BlueprintCallable, meta = (DisplayName="Append Tween Widget Opacity To", KeyWords="Tween Widget Opacity To UMG Sequence", AdvancedDisplay=5, HidePin=SequenceIndex), Category = "Tween|StandardTween|UMG|Opacity")
    static UTweenFloat* BP_AppendTweenWidgetOpacityTo(UTweenContainer* TweenContainer,
                                                      UWidget* TweenTarget,
                                                      float To,
                                                      float Duration              = 1.0f,
                                                      ETweenEaseType EaseType     = ETweenEaseType::Linear,
                                                      int32 NumLoops              = 1,
                                                      ETweenLoopType LoopType     = ETweenLoopType::Yoyo,
                                                      float Delay                 = 0.0f,
                                                      float TimeScale             = 1.0f,
                                                      bool TweenWhileGameIsPaused = false,
                                                      int32 SequenceIndex         = -1);

    /**
      * Appends to the TweenContainer a custom Tween that goes from a starting float value to an ending one. This type of Tween is meant for creating custom behaviours
      * by binding a function or an event to the OnTweenUpdate delegate in order to use the tweened value at each Tick by calling GetCurrentValue from the Tween object.
      * It will be executed when all previous Tweens in the TweenContainer are completed.
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
    UFUNCTION(BlueprintCallable, meta = (DisplayName="Append Tween Custom Float", KeyWords="Tween Float Append Sequence", AdvancedDisplay=6, HidePin=SequenceIndex), Category = "Tween|StandardTween|Custom")
    static UTweenFloat* BP_AppendTweenCustomFloat(UTweenContainer* TweenContainer,
                                                  UObject* TweenTarget,
                                                  float From,
                                                  float To,
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
      * Joins to the TweenContainer a Tween that modifies a "float" material parameter from the starting value to the ending value.
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
      * @param TweenWhileGameIsPaused Sets whether the Tween should keep updating while the game is paused. Useful for Tween on UMG widgets that animate menus.
      * @param SequenceIndex The index of the sequence in which the new Tween should be added (hidden in Blueprint).
      *
      * @return The newly created Tween.
      */
    UFUNCTION(BlueprintCallable, meta = (DisplayName="Join Tween Material Float From To", KeyWords="Tween Material Float From To Join Parallel", AdvancedDisplay=6, HidePin=SequenceIndex), Category = "Tween|StandardTween|Material")
    static UTweenFloat* BP_JoinTweenMaterialFloatFromTo(UTweenContainer* TweenContainer,
                                                        UMaterialInstanceDynamic* TweenTarget,
                                                        FName ParameterName,
                                                        float From,
                                                        float To,
                                                        float Duration              = 1.0f,
                                                        ETweenEaseType EaseType     = ETweenEaseType::Linear,
                                                        float Delay                 = 0.0f,
                                                        float TimeScale             = 1.0f,
                                                        bool TweenWhileGameIsPaused = false,
                                                        int32 SequenceIndex         = -1);

    /**
      * Joins to the TweenContainer a Tween that modifies a "float" material parameter from its current value (at the start of the Tween) to the ending value.
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
      * @param TweenWhileGameIsPaused Sets whether the Tween should keep updating while the game is paused. Useful for Tween on UMG widgets that animate menus.
      * @param SequenceIndex The index of the sequence in which the new Tween should be added (hidden in Blueprint).
      *
      * @return The newly created Tween.
      */
    UFUNCTION(BlueprintCallable, meta = (DisplayName="Join Tween Material Float To", KeyWords="Tween Material Float To Join Parallel", AdvancedDisplay=5, HidePin=SequenceIndex), Category = "Tween|StandardTween|Material")
    static UTweenFloat* BP_JoinTweenMaterialFloatTo(UTweenContainer* TweenContainer,
                                                    UMaterialInstanceDynamic* TweenTarget,
                                                    FName ParameterName,
                                                    float To,
                                                    float Duration              = 1.0f,
                                                    ETweenEaseType EaseType     = ETweenEaseType::Linear,
                                                    float Delay                 = 0.0f,
                                                    float TimeScale             = 1.0f,
                                                    bool TweenWhileGameIsPaused = false,
                                                    int32 SequenceIndex         = -1);

    /**
      * Joins to the TweenContainer a Tween that rotates an Actor around a given pivot point, with a given radius and rotation axis. The Actor will move
      * relative to its parent (if there is none, it will move in world coordinates).
      * It will be executed in parallel with the last appended Tween in the TweenContainer.
      *
      * @param TweenContainer The TweenContainer that will own the new Tween.
      * @param TweenTarget The target Actor.
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
      * @param SequenceIndex The index of the sequence in which the new Tween should be added (hidden in Blueprint).
      *
      * @return The newly created Tween.
      */
    UFUNCTION(BlueprintCallable, meta = (DisplayName="Join Tween Rotate Actor Around Point", KeyWords="Tween Rotate Actor Around Point Join Parallel", AdvancedDisplay=9, HidePin=SequenceIndex), Category = "Tween|StandardTween|Actor|Rotate")
    static UTweenFloat* BP_JoinTweenRotateActorAroundPoint(UTweenContainer* TweenContainer,
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
                                                           bool TweenWhileGameIsPaused = false,
                                                           int32 SequenceIndex         = -1);
    
    /**
      * Joins to the TweenContainer a Tween that rotates an Actor around a given pivot point by an offset angle. The radius and the rotation axis will be automatically computed. The Actor will move
      * relative to its parent (if there is none, it will move in world coordinates).
      * It will be executed in parallel with the last appended Tween in the TweenContainer.
      *
      * @param TweenContainer The TweenContainer that will own the new Tween.
      * @param TweenTarget The target Actor.
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
      * @param SequenceIndex The index of the sequence in which the new Tween should be added (hidden in Blueprint).
      *
      * @return The newly created Tween.
      */
    UFUNCTION(BlueprintCallable, meta = (DisplayName="Join Tween Rotate Actor Around Point By Offset", KeyWords="Tween Rotate Actor Around Point By Offset Join Parallel", AdvancedDisplay=8, HidePin=SequenceIndex), Category = "Tween|StandardTween|Actor|Rotate")
    static UTweenFloat* BP_JoinTweenRotateActorAroundPointByOffset(UTweenContainer* TweenContainer,
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
                                                                   bool TweenWhileGameIsPaused       = false,
                                                                   int32 SequenceIndex               = -1);

    /**
      * Joins to the TweenContainer a Tween that makes an Actor follow a spline path.
      * It will be executed in parallel with the last appended Tween in the TweenContainer.
      *
      * @param TweenContainer The TweenContainer that will own the new Tween.
      * @param TweenTarget The target Actor.
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
      * @param SequenceIndex The index of the sequence in which the new Tween should be added (hidden in Blueprint).
      *
      * @return The newly created Tween.
      */
    UFUNCTION(BlueprintCallable, meta = (DisplayName="Join Tween Actor Follow Spline", KeyWords="Tween Actor Follow Spline Join Parallel", AdvancedDisplay=8, HidePin=SequenceIndex), Category = "Tween|StandardTween|Actor|Spline")
    static UTweenFloat* BP_JoinTweenActorFollowSpline(UTweenContainer* TweenContainer,
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
                                                      bool TweenWhileGameIsPaused = false,
                                                      int32 SequenceIndex         = -1);

    /**
      * Joins to the TweenContainer a Tween that rotates an SceneComponent around a given pivot point, with a given radius and rotation axis. The SceneComponent will move
      * relative to its parent (if there is none, it will move in world coordinates).
      * It will be executed in parallel with the last appended Tween in the TweenContainer.
      *
      * @param TweenContainer The TweenContainer that will own the new Tween.
      * @param TweenTarget The target SceneComponent.
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
      * @param SequenceIndex The index of the sequence in which the new Tween should be added (hidden in Blueprint).
      *
      * @return The newly created Tween.
      */
    UFUNCTION(BlueprintCallable, meta = (DisplayName="Join Tween Rotate Scene Component Around Point", KeyWords="Tween Rotate Scene Component Around Point Join Parallel", AdvancedDisplay=9, HidePin=SequenceIndex), Category = "Tween|StandardTween|SceneComponent|Rotate")
    static UTweenFloat* BP_JoinTweenRotateSceneComponentAroundPoint(UTweenContainer* TweenContainer,
                                                                    USceneComponent* TweenTarget,
                                                                    FVector PivotPoint,
                                                                    float StartingAngle,
                                                                    float EndingAngle,
                                                                    float Radius,
                                                                    FVector Axis                = FVector(0.0f, 0.0f, 1.0f),
                                                                    ETweenSpace TweenSpace            = ETweenSpace::World,
                                                                    float Duration              = 1.0f,
                                                                    ETweenEaseType EaseType     = ETweenEaseType::Linear,
                                                                    bool DeleteTweenOnHit       = false,
                                                                    bool DeleteTweenOnOverlap   = false,
                                                                    float Delay                 = 0.0f,
                                                                    float TimeScale             = 1.0f,
                                                                    bool TweenWhileGameIsPaused = false,
                                                                    int32 SequenceIndex         = -1);

    /**
      * Joins to the TweenContainer a Tween that rotates an SceneComponent around a given pivot point by an offset angle. The radius and the rotation axis will be automatically computed. The SceneComponent will move
      * relative to its parent (if there is none, it will move in world coordinates).
      * It will be executed in parallel with the last appended Tween in the TweenContainer.
      *
      * @param TweenContainer The TweenContainer that will own the new Tween.
      * @param TweenTarget The target SceneComponent.
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
      * @param SequenceIndex The index of the sequence in which the new Tween should be added (hidden in Blueprint).
      *
      * @return The newly created Tween.
      */
    UFUNCTION(BlueprintCallable, meta = (DisplayName="Join Tween Rotate Scene Component Around Point By Offset", KeyWords="Tween Rotate Scene Component Around Point By Offset Join Parallel", AdvancedDisplay=8, HidePin=SequenceIndex), Category = "Tween|StandardTween|SceneComponent|Rotate")
    static UTweenFloat* BP_JoinTweenRotateSceneComponentAroundPointByOffset(UTweenContainer* TweenContainer,
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
                                                                            bool TweenWhileGameIsPaused       = false,
                                                                            int32 SequenceIndex               = -1);

    /**
      * Joins to the TweenContainer a Tween that makes an SceneComponent follow a spline path.
      * It will be executed in parallel with the last appended Tween in the TweenContainer.
      *
      * @param TweenContainer The TweenContainer that will own the new Tween.
      * @param TweenTarget The target SceneComponent.
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
      * @param SequenceIndex The index of the sequence in which the new Tween should be added (hidden in Blueprint).
      *
      * @return The newly created Tween.
      */
    UFUNCTION(BlueprintCallable, meta = (DisplayName="Join Tween Scene Component Follow Spline", KeyWords="Tween Scene Component Follow Spline Join Parallel", AdvancedDisplay=8, HidePin=SequenceIndex), Category = "Tween|StandardTween|SceneComponent|Spline")
    static UTweenFloat* BP_JoinTweenSceneComponentFollowSpline(UTweenContainer* TweenContainer,
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
                                                               bool TweenWhileGameIsPaused = false,
                                                               int32 SequenceIndex         = -1);

    /**
      * Joins to the TweenContainer a Tween that makes a UMG widget rotate to the given angle.
      * It will be executed in parallel with the last appended Tween in the TweenContainer.
      *
      * @param TweenContainer The TweenContainer that will own the new Tween.
      * @param TweenTarget The target Widget.
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
    UFUNCTION(BlueprintCallable, meta = (DisplayName="Join Tween Widget Angle To", KeyWords="Tween Widget Angle To UMG Join Parallel", AdvancedDisplay=5, HidePin=SequenceIndex), Category = "Tween|StandardTween|UMG|Angle")
    static UTweenFloat* BP_JoinTweenWidgetAngleTo(UTweenContainer* TweenContainer,
                                                  UWidget* TweenTarget,
                                                  float To,
                                                  float Duration              = 1.0f,
                                                  ETweenEaseType EaseType     = ETweenEaseType::Linear,
                                                  float Delay                 = 0.0f,
                                                  float TimeScale             = 1.0f,
                                                  bool TweenWhileGameIsPaused = false,
                                                  int32 SequenceIndex         = -1);

    /**
      * Joins to the TweenContainer a Tween that makes a UMG widget's opacity reach the given value.
      * It will be executed in parallel with the last appended Tween in the TweenContainer.
      *
      * @param TweenContainer The TweenContainer that will own the new Tween.
      * @param TweenTarget The target Widget.
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
    UFUNCTION(BlueprintCallable, meta = (DisplayName="Join Tween Widget Opacity To", KeyWords="Tween Widget Opacity To UMG Join Parallel", AdvancedDisplay=5, HidePin=SequenceIndex), Category = "Tween|StandardTween|UMG|Opacity")
    static UTweenFloat* BP_JoinTweenWidgetOpacityTo(UTweenContainer* TweenContainer,
                                                    UWidget* TweenTarget,
                                                    float To,
                                                    float Duration              = 1.0f,
                                                    ETweenEaseType EaseType     = ETweenEaseType::Linear,
                                                    float Delay                 = 0.0f,
                                                    float TimeScale             = 1.0f,
                                                    bool TweenWhileGameIsPaused = false,
                                                    int32 SequenceIndex         = -1);

    /**
      * Joins to the TweenContainer a custom Tween that goes from a starting float value to an ending one. This type of Tween is meant for creating custom behaviours
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
    UFUNCTION(BlueprintCallable, meta = (DisplayName="Join Tween Custom Float", KeyWords="Tween Custom Float Join Parallel", AdvancedDisplay=6, HidePin=SequenceIndex), Category = "Tween|StandardTween|Custom")
    static UTweenFloat* BP_JoinTweenCustomFloat(UTweenContainer* TweenContainer,
                                                UObject* TweenTarget,
                                                float From,
                                                float To,
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

    static UTweenFloat* CreateAppendTweenFloat(UTweenContainer* pTweenContainer,
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
                                               int32 pSequenceIndex,
                                               FName pParameterName = FName("None"));

    static UTweenFloat* CreateJoinTweenFloat(UTweenContainer* pTweenContainer,
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
                                             int32 pSequenceIndex,
                                             FName pParameterName = FName("None"));


    // For "rotate around"
    static UTweenFloat* CreateAppendTweenRotateAroundFloat(UTweenContainer* pTweenContainer,
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
                                                           int32 pSequenceIndex);

    static UTweenFloat* CreateJoinTweenRotateAroundFloat(UTweenContainer* pTweenContainer,
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
                                                         int32 pSequenceIndex);


    // For splines
    static UTweenFloat* CreateAppendTweenFollowSpline(UTweenContainer* pTweenContainer,
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
                                                      int32 pSequenceIndex);

    static UTweenFloat* CreateJoinTweenFollowSpline(UTweenContainer* pTweenContainer,
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
                                                    int32 pSequenceIndex);
};
