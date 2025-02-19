// Copyright 2018 Francesco Desogus. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"

#include "TweenManagerComponent.h"
#include "Utils/TweenEnums.h"

#include "TweenRotatorStandardFactory.generated.h"

class ATweenManagerActor;
class UTweenManagerComponent;
class UTweenContainer;
class UBaseTween;
class UTweenRotator;

/**
 * @brief The UTweenRotatorStandardFactory class handles the creation of all Rotator related Tweens, i.e. all tweens that
 *        in order to be executed they need to change a single Rotator value.
 *
 *        The methods here are "standard", meaning that if the user wishes to use one of the tween callbacks (OnTweenStart,
 *        OnTweenUpdate, OnTweenEnd) he has to manually bind the delegates.
 */
UCLASS()
class TWEENMAKER_API UTweenRotatorStandardFactory : public UObject
{
    GENERATED_BODY()

public:
    
    /**
     * @brief Constructor.
     */
    UTweenRotatorStandardFactory(const FObjectInitializer& ObjectInitializer);

    /*
     **************************************************************************
     * "Create" methods
     **************************************************************************
     */

    /**
      * Creates a Tween that rotates an Actor from its current orientation (at the start of the Tween) to the given rotation.
      * With this function a new TweenContainer will be created, which will hold any other Tween appended/joined to this one.
      *
      * @param TweenManager (optional) The TweenManager that will handle the Tween. If none is passed, the global TweenManagerActor will be used if present.
      * @param TweenTarget The Actor to rotate.
      * @param TweenContainer The TweenContainer that owns the Tween.
      * @param Tween The created Tween.
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
      * @param SequenceIndex The index of the sequence in which the new Tween should be added (hidden in Blueprint).
      * @param TweenWhileGameIsPaused Sets whether the Tween should keep updating while the game is paused. Useful for Tween on UMG widgets that animate menus.
      */
    UFUNCTION(BlueprintCallable, meta = (DisplayName="Create Tween Rotate Actor To", KeyWords="Tween Rotate Actor To Create", AdvancedDisplay=7, HidePin=SequenceIndex), Category = "Tween|StandardTween|Actor|Rotate")
    static void BP_CreateTweenRotateActorTo(UTweenManagerComponent* TweenManager,
                                            AActor* TweenTarget,
                                            UTweenContainer*& TweenContainer,
                                            UTweenRotator*& Tween,
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
                                            bool TweenWhileGameIsPaused     = false,
                                            int32 SequenceIndex             = -1);

    /**
      * Creates a Tween that rotates an Actor by the given offset with respect to its current orientation (at the start of the Tween).
      * With this function a new TweenContainer will be created, which will hold any other Tween appended/joined to this one.
      *
      * @param TweenManager (optional) The TweenManager that will handle the Tween. If none is passed, the global TweenManagerActor will be used if present.
      * @param TweenTarget The Actor to rotate.
      * @param TweenContainer The TweenContainer that owns the Tween.
      * @param Tween The created Tween.
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
      * @param SequenceIndex The index of the sequence in which the new Tween should be added (hidden in Blueprint).
      * @param TweenWhileGameIsPaused Sets whether the Tween should keep updating while the game is paused. Useful for Tween on UMG widgets that animate menus.
      */
    UFUNCTION(BlueprintCallable, meta = (DisplayName="Create Tween Rotate Actor By", KeyWords="Tween Rotate Actor By Create", AdvancedDisplay=8, HidePin=SequenceIndex), Category = "Tween|StandardTween|Actor|Rotate")
    static void BP_CreateTweenRotateActorBy(UTweenManagerComponent* TweenManager,
                                            AActor* TweenTarget,
                                            UTweenContainer*& TweenContainer,
                                            UTweenRotator*& Tween,
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
                                            bool TweenWhileGameIsPaused = false,
                                            int32 SequenceIndex         = -1);


    /**
      * Creates a Tween that rotates a SceneComponent from its current orientation (at the start of the Tween) to the given rotation.
      * With this function a new TweenContainer will be created, which will hold any other Tween appended/joined to this one.
      *
      * @param TweenManager (optional) The TweenManager that will handle the Tween. If none is passed, the global TweenManagerActor will be used if present.
      * @param TweenTarget The SceneComponent to rotate.
      * @param TweenContainer The TweenContainer that owns the Tween.
      * @param Tween The created Tween.
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
      * @param SequenceIndex The index of the sequence in which the new Tween should be added (hidden in Blueprint).
      * @param TweenWhileGameIsPaused Sets whether the Tween should keep updating while the game is paused. Useful for Tween on UMG widgets that animate menus.
      */
    UFUNCTION(BlueprintCallable, meta = (DisplayName="Create Tween Rotate Scene Component To", KeyWords="Tween Rotate Scene Component To Create", AdvancedDisplay=7, HidePin=SequenceIndex), Category = "Tween|StandardTween|SceneComponent|Rotate")
    static void BP_CreateTweenRotateSceneComponentTo(UTweenManagerComponent* TweenManager,
                                                     USceneComponent* TweenTarget,
                                                     UTweenContainer*& TweenContainer,
                                                     UTweenRotator*& Tween,
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
                                                     bool TweenWhileGameIsPaused     = false,
                                                     int32 SequenceIndex             = -1);

    /**
      * Creates a Tween that rotates a SceneComponent by the given offset with respect to its current orientation (at the start of the Tween).
      * With this function a new TweenContainer will be created, which will hold any other Tween appended/joined to this one.
      *
      * @param TweenManager (optional) The TweenManager that will handle the Tween. If none is passed, the global TweenManagerActor will be used if present.
      * @param TweenTarget The SceneComponent to rotate.
      * @param TweenContainer The TweenContainer that owns the Tween.
      * @param Tween The created Tween.
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
      * @param SequenceIndex The index of the sequence in which the new Tween should be added (hidden in Blueprint).
      * @param TweenWhileGameIsPaused Sets whether the Tween should keep updating while the game is paused. Useful for Tween on UMG widgets that animate menus.
      */
    UFUNCTION(BlueprintCallable, meta = (DisplayName="Create Tween Rotate Scene Component By", KeyWords="Tween Rotate Scene Component By Create", AdvancedDisplay=8, HidePin=SequenceIndex), Category = "Tween|StandardTween|SceneComponent|Rotate")
    static void BP_CreateTweenRotateSceneComponentBy(UTweenManagerComponent* TweenManager,
                                                     USceneComponent* TweenTarget,
                                                     UTweenContainer*& TweenContainer,
                                                     UTweenRotator*& Tween,
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
                                                     bool TweenWhileGameIsPaused = false,
                                                     int32 SequenceIndex         = -1);


    /*
     **************************************************************************
     * "Append" methods
     **************************************************************************
     */

    /**
      * Appends to the TweenContainer a Tween that rotates an Actor from its current orientation (at the start of the Tween) to the given rotation.
      * It will be executed when all previous Tweens in the TweenContainer are completed.
      *
      * @param TweenContainer The TweenContainer that will own the new Tween.
      * @param TweenTarget The Actor to rotate.
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
      * @param SequenceIndex The index of the sequence in which the new Tween should be added (hidden in Blueprint).
      * @param TweenWhileGameIsPaused Sets whether the Tween should keep updating while the game is paused. Useful for Tween on UMG widgets that animate menus.
      *
      * @return The newly created Tween.
      */
    UFUNCTION(BlueprintCallable, meta = (DisplayName="Append Tween Rotate Actor To", KeyWords="Tween Rotate Actor To Append Sequence", AdvancedDisplay=5, HidePin=SequenceIndex), Category = "Tween|StandardTween|Actor|Rotate")
    static UTweenRotator* BP_AppendTweenRotateActorTo(UTweenContainer* TweenContainer,
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
                                                      bool TweenWhileGameIsPaused     = false,
                                                      int32 SequenceIndex             = -1);

    /**
      * Appends to the TweenContainer a Tween that rotates an Actor by the given offset with respect to its current orientation (at the start of the Tween).
      * It will be executed when all previous Tweens in the TweenContainer are completed.
      *
      * @param TweenContainer The TweenContainer that will own the new Tween.
      * @param TweenTarget The Actor to rotate.
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
      * @param SequenceIndex The index of the sequence in which the new Tween should be added (hidden in Blueprint).
      * @param TweenWhileGameIsPaused Sets whether the Tween should keep updating while the game is paused. Useful for Tween on UMG widgets that animate menus.
      *
      * @return The newly created Tween.
      */
    UFUNCTION(BlueprintCallable, meta = (DisplayName="Append Tween Rotate Actor By", KeyWords="Tween Rotate Actor By Append Sequence", AdvancedDisplay=6, HidePin=SequenceIndex), Category = "Tween|StandardTween|Actor|Rotate")
    static UTweenRotator* BP_AppendTweenRotateActorBy(UTweenContainer* TweenContainer,
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
                                                      bool TweenWhileGameIsPaused = false,
                                                      int32 SequenceIndex         = -1);

    /**
      * Appends to the TweenContainer a Tween that rotates a SceneComponent from its current orientation (at the start of the Tween) to the given rotation.
      * It will be executed when all previous Tweens in the TweenContainer are completed.
      *
      * @param TweenContainer The TweenContainer that will own the new Tween.
      * @param TweenTarget The SceneComponent to rotate.
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
      * @param SequenceIndex The index of the sequence in which the new Tween should be added (hidden in Blueprint).
      * @param TweenWhileGameIsPaused Sets whether the Tween should keep updating while the game is paused. Useful for Tween on UMG widgets that animate menus.
      *
      * @return The newly created Tween.
      */
    UFUNCTION(BlueprintCallable, meta = (DisplayName="Append Tween Rotate Scene Component To", KeyWords="Tween Rotate Scene Component To Append Sequence", AdvancedDisplay=5, HidePin=SequenceIndex), Category = "Tween|StandardTween|SceneComponent|Rotate")
    static UTweenRotator* BP_AppendTweenRotateSceneComponentTo(UTweenContainer* TweenContainer,
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
                                                               bool TweenWhileGameIsPaused     = false,
                                                               int32 SequenceIndex             = -1);

    /**
      * Appends to the TweenContainer a Tween that rotates a SceneComponent by the given offset with respect to its current orientation (at the start of the Tween).
      * It will be executed when all previous Tweens in the TweenContainer are completed.
      *
      * @param TweenContainer The TweenContainer that will own the new Tween.
      * @param TweenTarget The SceneComponent to rotate.
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
      * @param SequenceIndex The index of the sequence in which the new Tween should be added (hidden in Blueprint).
      * @param TweenWhileGameIsPaused Sets whether the Tween should keep updating while the game is paused. Useful for Tween on UMG widgets that animate menus.
      *
      * @return The newly created Tween.
      */
    UFUNCTION(BlueprintCallable, meta = (DisplayName="Append Tween Rotate Scene Component By", KeyWords="Tween Rotate Scene Component By Append Sequence", AdvancedDisplay=6, HidePin=SequenceIndex), Category = "Tween|StandardTween|SceneComponent|Rotate")
    static UTweenRotator* BP_AppendTweenRotateSceneComponentBy(UTweenContainer* TweenContainer,
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
                                                               bool TweenWhileGameIsPaused = false,
                                                               int32 SequenceIndex         = -1);


    /*
     **************************************************************************
     * "Join" methods
     **************************************************************************
     */


    /**
      * Joins to the TweenContainer a Tween that rotates an Actor from its current orientation (at the start of the Tween) to the given rotation.
      * It will be executed in parallel with the last appended Tween in the TweenContainer.
      *
      * @param TweenContainer The TweenContainer that will own the new Tween.
      * @param TweenTarget The Actor to rotate.
      * @param To The ending value.
      * @param Duration The total duration of the Tween (in seconds).
      * @param EaseType	The easing functions to apply.
      * @param TweenSpace The space in which the Tween makes its update (i.e. 'world' or 'relative').
      * @param RotationMode	The rotation mode to use.
      * @param DeleteTweenOnHit If true the Tween will be deleted when the TweenTarget hits something.
      * @param DeleteTweenOnOverlap If true the Tween will be deleted when the TweenTarget overlaps something.
      * @param Delay The initial delay to apply to the Tween (in seconds).
      * @param TimeScale The scale to apply to the Tween execution. If < 1 the Tween will slow down, if > 1 it will speed up. If < 0 it will make the Tween go backward.
      * @param SequenceIndex The index of the sequence in which the new Tween should be added (hidden in Blueprint).
      * @param TweenWhileGameIsPaused Sets whether the Tween should keep updating while the game is paused. Useful for Tween on UMG widgets that animate menus.
      *
      * @return The newly created Tween.
      */
    UFUNCTION(BlueprintCallable, meta = (DisplayName="Join Tween Rotate Actor To", KeyWords="Tween Rotate Actor To Join Parallel", AdvancedDisplay=5, HidePin=SequenceIndex), Category = "Tween|StandardTween|Actor|Rotate")
    static UTweenRotator* BP_JoinTweenRotateActorTo(UTweenContainer* TweenContainer,
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
                                                    bool TweenWhileGameIsPaused     = false,
                                                    int32 SequenceIndex             = -1);

    /**
      * Joins to the TweenContainer a Tween that rotates an Actor by the given offset with respect to its current orientation (at the start of the Tween).
      * It will be executed in parallel with the last appended Tween in the TweenContainer.
      *
      * @param TweenContainer The TweenContainer that will own the new Tween.
      * @param TweenTarget The Actor to rotate.
      * @param By The offset to apply.
      * @param Duration The total duration of the Tween (in seconds).
      * @param EaseType	The easing functions to apply.
      * @param LocalSpace Whether to rotate around actor's own local axes, not parent/world
      * @param DeleteTweenOnHit If true the Tween will be deleted when the TweenTarget hits something.
      * @param DeleteTweenOnOverlap If true the Tween will be deleted when the TweenTarget overlaps something.
      * @param Delay The initial delay to apply to the Tween (in seconds).
      * @param TimeScale The scale to apply to the Tween execution. If < 1 the Tween will slow down, if > 1 it will speed up. If < 0 it will make the Tween go backward.
      * @param SequenceIndex The index of the sequence in which the new Tween should be added (hidden in Blueprint).
      * @param TweenWhileGameIsPaused Sets whether the Tween should keep updating while the game is paused. Useful for Tween on UMG widgets that animate menus.
      *
      * @return The newly created Tween.
      */
    UFUNCTION(BlueprintCallable, meta = (DisplayName="Join Tween Rotate Actor By", KeyWords="Tween Rotate Actor To Join Parallel", AdvancedDisplay=6, HidePin=SequenceIndex), Category = "Tween|StandardTween|Actor|Rotate")
    static UTweenRotator* BP_JoinTweenRotateActorBy(UTweenContainer* TweenContainer,
                                                    AActor* TweenTarget,
                                                    FRotator By,
                                                    float Duration              = 1.0f,
                                                    ETweenEaseType EaseType     = ETweenEaseType::Linear,
                                                    bool LocalSpace             = false,
                                                    bool DeleteTweenOnHit       = false,
                                                    bool DeleteTweenOnOverlap   = false,
                                                    float Delay                 = 0.0f,
                                                    float TimeScale             = 1.0f,
                                                    bool TweenWhileGameIsPaused = false,
                                                    int32 SequenceIndex         = -1);

    /**
      * Joins to the TweenContainer a Tween that rotates a SceneComponent from its current orientation (at the start of the Tween) to the given rotation.
      * It will be executed in parallel with the last appended Tween in the TweenContainer.
      *
      * @param TweenContainer The TweenContainer that will own the new Tween.
      * @param TweenTarget The SceneComponent to rotate.
      * @param To The ending value.
      * @param Duration The total duration of the Tween (in seconds).
      * @param EaseType	The easing functions to apply.
      * @param TweenSpace The space in which the Tween makes its update (i.e. 'world' or 'relative').
      * @param RotationMode	The rotation mode to use.
      * @param DeleteTweenOnHit If true the Tween will be deleted when the TweenTarget hits something.
      * @param DeleteTweenOnOverlap If true the Tween will be deleted when the TweenTarget overlaps something.
      * @param Delay The initial delay to apply to the Tween (in seconds).
      * @param TimeScale The scale to apply to the Tween execution. If < 1 the Tween will slow down, if > 1 it will speed up. If < 0 it will make the Tween go backward.
      * @param SequenceIndex The index of the sequence in which the new Tween should be added (hidden in Blueprint).
      * @param TweenWhileGameIsPaused Sets whether the Tween should keep updating while the game is paused. Useful for Tween on UMG widgets that animate menus.
      *
      * @return The newly created Tween.
      */
    UFUNCTION(BlueprintCallable, meta = (DisplayName="Join Tween Rotate Scene Component To", KeyWords="Tween Rotate Scene Component To Join Parallel", AdvancedDisplay=5, HidePin=SequenceIndex), Category = "Tween|StandardTween|SceneComponent|Rotate")
    static UTweenRotator* BP_JoinTweenRotateSceneComponentTo(UTweenContainer* TweenContainer,
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
                                                             bool TweenWhileGameIsPaused     = false,
                                                             int32 SequenceIndex             = -1);

    /**
      * Joins to the TweenContainer a Tween that rotates a SceneComponent by the given offset with respect to its current orientation (at the start of the Tween).
      * It will be executed in parallel with the last appended Tween in the TweenContainer.
      *
      * @param TweenContainer The TweenContainer that will own the new Tween.
      * @param TweenTarget The SceneComponent to rotate.
      * @param By The offset to apply.
      * @param Duration The total duration of the Tween (in seconds).
      * @param EaseType	The easing functions to apply.
      * @param LocalSpace Whether to rotate around component's own local axes, not parent/world
      * @param DeleteTweenOnHit If true the Tween will be deleted when the TweenTarget hits something.
      * @param DeleteTweenOnOverlap If true the Tween will be deleted when the TweenTarget overlaps something.
      * @param Delay The initial delay to apply to the Tween (in seconds).
      * @param TimeScale The scale to apply to the Tween execution. If < 1 the Tween will slow down, if > 1 it will speed up. If < 0 it will make the Tween go backward.
      * @param SequenceIndex The index of the sequence in which the new Tween should be added (hidden in Blueprint).
      * @param TweenWhileGameIsPaused Sets whether the Tween should keep updating while the game is paused. Useful for Tween on UMG widgets that animate menus.
      *
      * @return The newly created Tween.
      */
    UFUNCTION(BlueprintCallable, meta = (DisplayName="Join Tween Rotate Scene Component By", KeyWords="Tween Rotate Scene Component To Join Parallel", AdvancedDisplay=6, HidePin=SequenceIndex), Category = "Tween|StandardTween|SceneComponent|Rotate")
    static UTweenRotator* BP_JoinTweenRotateSceneComponentBy(UTweenContainer* TweenContainer,
                                                             USceneComponent* TweenTarget,
                                                             FRotator By,
                                                             float Duration              = 1.0f,
                                                             ETweenEaseType EaseType     = ETweenEaseType::Linear,
                                                             bool LocalSpace             = false,
                                                             bool DeleteTweenOnHit       = false,
                                                             bool DeleteTweenOnOverlap   = false,
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

    static UTweenRotator* CreateAppendTweenRotator(UTweenContainer* pTweenContainer,
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
                                                   int32 pSequenceIndex);

    static UTweenRotator* CreateJoinTweenRotator(UTweenContainer* pTweenContainer,
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
                                                 int32 pSequenceIndex);
};
