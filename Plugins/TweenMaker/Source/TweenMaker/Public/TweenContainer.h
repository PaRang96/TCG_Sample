// Copyright 2018 Francesco Desogus. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Utils/TweenEnums.h"
#include "Tweens/ParallelTween.h"
#include "TweenContainer.generated.h"

class UTweenManagerComponent;
class UBaseTween;

/*
 **************************************************************************
 * Blueprint delegates declaration
 **************************************************************************
 */

/// @brief Delegate type declaration, used when the tween container ends (Blueprint only).
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FBP_OnTweenContainerEnd, UTweenContainer*, TweenContainer);

/*
 **************************************************************************
 * C++ delegates declaration
 **************************************************************************
 */

/// @brief Delegate type declaration, used when the tween container ends (C++ only).
DECLARE_DELEGATE_OneParam(FOnTweenContainerEnd, UTweenContainer*);

/**
 * The UTweenContainer class is responsable for managing sequences of parallel Tweens. All Tweens that are created are internally
 * owned by a UTweenContainer object, and everytime a Tween is appended to another internally a new sequence of parallel Tweens
 * is created.
 *
 * The UTweenContainer is also responsable for managing the lifetime of the Tweens. It will destroy them when ALL Tweens in the
 * UTweenContainer are done (meaning that they're also done looping).
 *
 * When creating Tweens in C++ the UTweenContainer object provides the functions to append/join Tweens to itself.
 */
UCLASS(BlueprintType)
class TWEENMAKER_API UTweenContainer : public UObject
{
    GENERATED_BODY()

    friend class UTweenManagerComponent;
    
public:

    /**
     * @brief Constructor.
     */
    UTweenContainer(const FObjectInitializer& ObjectInitializer);

    /// @brief The TweenManager that owns this UTweenContainer.
    UPROPERTY()
    UTweenManagerComponent* OwningTweenManager;

    /*
     **************************************************************************
     * "Utils" methods
     **************************************************************************
     */

    /**
     * Changes the timescale of the TweenContainer with a new value. If the value is < 0 the Tweens will go backwards.
     *
     * @param NewTimeScale The new value.
     */
    UFUNCTION(BlueprintCallable, meta = (KeyWords="Tween Container Time Timescale"), Category = "Tween|Utils")
    void SetTimeScale(float NewTimeScale = 1.0f);

    /**
     * Changes the number and the type of loops.
     *
     * @param NumLoops How many time the sequences should loop.
     * @param LoopType How the sequences should loop.
     */
    UFUNCTION(BlueprintCallable, meta = (KeyWords="Tween Container Loop"), Category = "Tween|Utils")
    void SetLoop(int NumLoops = 1, ETweenLoopType LoopType = ETweenLoopType::Yoyo);

    /**
     * If set, the system will keep the TweenContainer alive (and all its Tweens) even if the sequence ends. This is useful
     * if you need to restart a sequence multiple times and you want avoid recreating the Tween sequence over and over.
     *
     * Note: when a TweenContainer is set as persistent, it will be deleted only if you manually delete it or if you 
     * change level (i.e. if you have a new instance of the TweenManagerActor).
     *
     * @param Persistent True if this TweenContainer should live even if all tweens have ended.
     */
    UFUNCTION(BlueprintCallable, meta = (KeyWords = "Tween Persistent"), Category = "Tween|Utils")
    void SetPersistent(bool Persistent);

    /**
     * Pauses this TweenContainer and ALL Tweens associated to it.
     */
    UFUNCTION(BlueprintCallable, meta = (KeyWords="Tween Container Pause"), Category = "Tween|Utils")
    void PauseTweenContainer();

    /**
     * Checks if this TweenContainer is paused.
     */
    UFUNCTION(BlueprintPure, meta = (KeyWords="Tween Is Paused Pause"), Category = "Tween|Utils")
    bool IsPaused() const;

    /**
     * Toggles pause on this TweenContainer and ALL Tweens associated to it.
     */
    UFUNCTION(BlueprintCallable, meta = (KeyWords="Tween Container Toggle Pause Resume"), Category = "Tween|Utils")
    void TogglePauseTweenContainer();

    /**
     * Resumes this TweenContainer and ALL Tweens associated to it.
     */
    UFUNCTION(BlueprintCallable, meta = (KeyWords="Tween Container Resume"), Category = "Tween|Utils")
    void ResumeTweenContainer();

    /**
     * Restarts this TweenContainer and ALL Tweens associated to it. It resumes them in case they were paused.
     */
    UFUNCTION(BlueprintCallable, meta = (KeyWords="Tween Container Restart"), Category = "Tween|Utils")
    void RestartTweenContainer();

    /**
     * Deletes this TweenContainer and ALL Tweens associated to it in the next Tick.
     */
    UFUNCTION(BlueprintCallable, meta = (KeyWords="Tween Container Delete Remove"), Category = "Tween|Utils")
    void DeleteTweenContainer();

    /**
     * Deletes all Tweens in this TweenContainer that have as target the given Object and that are of the given TweenType.
     *
     * @param TweenTarget The target Object.
     * @param TweensType The type of Tweens to consider for deletion.
     */
    UFUNCTION(BlueprintCallable, meta = (DisplayName="Delete Tweens In Container By Object", KeyWords="Delete Remove Tweens Container By Object"), Category = "Tween|Utils")
    void DeleteTweensInContainerByObject(UObject* TweenTarget, ETweenGenericType TweensType);

    /**
     * Checks if an Object is currently tweening amogn all Tweens owned by this TweenContainer. If it is, the corresponding Tween is returned.
     *
     * @param TweenTarget The target Object.
     * @param TweensType The type of Tweens to consider when searching.
     * @param TweenFound (output) If a Tween was found, this is it.
     *
     * @return True if a Tween was found; false otherise.
     */
    UFUNCTION(BlueprintCallable, meta = (DisplayName="Is Object Tweening In Container", KeyWords="Is Object Tweening In Container"), Category = "Tween|Utils")
    bool IsObjectTweeningInContainer(UObject* TweenTarget, ETweenGenericType TweensType, UBaseTween*& TweenFound) const;

     /**
      * Checks if the TweenContainer sequence has ended.
      *
      * Note: only meaningful to use this if the TweenContainer was set as 'persistent', otherwise when it's done it's automatically deleted.
      *
      * @return True if the TweenContainer has ended. False if it's still running or paused.
      */
    UFUNCTION(BlueprintCallable, meta = (KeyWords = "Tween Container Has Ended"), Category = "Tween|Utils")
    bool HasEnded() const;

    /*
     **************************************************************************
     * Methods used internally. Should not be called.
     **************************************************************************
     */

    /**
     * @brief Init initializes the TweenContainer (internal usage only).
     *
     * @param pOwningTweenManager The TweenManager that created this TweenContainer.
     * @param NumLoops How many times the sequence of Tweens inside the TweenContainer should loop.
     * @param LoopType How the Tweens should loop.
     * @param TimeScale The timescale applied to the Tweens.
     */
    void Init(UTweenManagerComponent* pOwningTweenManager, int32 NumLoops, ETweenLoopType LoopType, float TimeScale);

    /**
     * @brief AddSequenceTween adds a new Tween sequence (internal usage only).
     *
     * @param pNewTween The Tween to add.
     * @param pSequenceId The index in which to insert the Tween.
     */
    void AddSequenceTween(UBaseTween* pNewTween, int32 pSequenceId);

    /**
     * @brief AddParallelTween adds a new parallel Tween (internal usage only).
     *
     * @param pNewTween The Tween to add.
     * @param pSequenceId The index in which to insert the Tween.
     */
    void AddParallelTween(UBaseTween* pNewTween, int32 pSequenceId);

    /**
     * @brief UpdateTweens updates ALL Tweens owned by this UTweenContainer (internal usage only).
     *
     * @param pDeltaTime The time difference since the last Tick.
     *
     * @return True if ALL Tweens are done (also considering the loops); false otherwise.
     */
    bool UpdateTweens(float pDeltaTime);

    /**
     * Retrieves the number of available sequences (internal usage only).
     */
    int32 GetSequencesNum() const;

    /**
     * Checks if the TweenContainer is going to be deleted (internal usage only).
     */
    bool IsPendingDeletion() const;

    /**
     * Checks if the TweenContainer is empty (internal usage only).
     */
    bool IsEmpty() const;

    // Begin of UObject interface
    virtual void BeginDestroy() override;
    // End of UObject interface

    /*
     **************************************************************************
     * Blueprint delegates
     **************************************************************************
     */

    /// @brief Delegate called when ALL Tweens managed by this container are done and it's about to be destroyed (don't reuse the container). Use only in Blueprints.
    UPROPERTY(BlueprintAssignable, meta = (DisplayName = "On Tween Container End"))
    FBP_OnTweenContainerEnd OnTweenContainerEnd;

    /*
     **************************************************************************
     * C++ delegates
     **************************************************************************
     */

    /// @brief Delegate called when ALL Tweens managed by this container are done and it's about to be destroyed (don't reuse the container). Use only in C++.
    FOnTweenContainerEnd OnTweenContainerEndDelegate;

    /*
     **************************************************************************
     * "Append Tween" methods
     **************************************************************************
     */


    /* TweenVector methods */

    /**
      * Appends to this TweenContainer a Tween that moves an Actor from its current location (at the start of the Tween) to the given location.
      * It will be executed when all previous Tweens in the TweenContainer are completed.
      *
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
      *
      * @return The newly created Tween.
      */
    UTweenVector* AppendTweenMoveActorTo(AActor* TweenTarget,
                                         const FVector& To,
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
      * Appends to this TweenContainer a Tween that moves an Actor by the given offset with respect to its current location (at the start of the Tween).
      * It will be executed when all previous Tweens in the TweenContainer are completed.
      *
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
      *
      * @return The newly created Tween.
      */
    UTweenVector* AppendTweenMoveActorBy(AActor* TweenTarget,
                                         const FVector& By,
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
      * Appends to this TweenContainer a Tween that scales an Actor from its current scale (at the start of the Tween) to the given size.
      * It will be executed when all previous Tweens in the TweenContainer are completed.
      *
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
      *
      * @return The newly created Tween.
      */
    UTweenVector* AppendTweenScaleActorTo(AActor* TweenTarget,
                                          const FVector& To,
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
      * Appends to this TweenContainer a Tween that scales an Actor by the given offset with respect to its current size (at the start of the Tween).
      * It will be executed when all previous Tweens in the TweenContainer are completed.

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
      *
      * @return The newly created Tween.
      */
    UTweenVector* AppendTweenScaleActorBy(AActor* TweenTarget,
                                          const FVector& By,
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
      * Appends to this TweenContainer a Tween that moves a SceneComponent from its current location (at the start of the Tween) to the given location.
      * It will be executed when all previous Tweens in the TweenContainer are completed.
      *
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
      *
      * @return The newly created Tween.
      */
    UTweenVector* AppendTweenMoveSceneComponentTo(USceneComponent* TweenTarget,
                                                  const FVector& To,
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
      * Appends to this TweenContainer a Tween that moves a SceneComponent by the given offset with respect to its current location (at the start of the Tween).
      * It will be executed when all previous Tweens in the TweenContainer are completed.
      *
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
      *
      * @return The newly created Tween.
      */
    UTweenVector* AppendTweenMoveSceneComponentBy(USceneComponent* TweenTarget,
                                                  const FVector& By,
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
      * Appends to this TweenContainer a Tween that scales a SceneComponent from its current scale (at the start of the Tween) to the given size.
      * It will be executed when all previous Tweens in the TweenContainer are completed.
      *
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
      *
      * @return The newly created Tween.
      */
    UTweenVector* AppendTweenScaleSceneComponentTo(USceneComponent* TweenTarget,
                                                   const FVector& To,
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
      * Appends to this TweenContainer a Tween that scales a SceneComponent by the given offset with respect to its current size (at the start of the Tween).
      * It will be executed when all previous Tweens in the TweenContainer are completed.

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
      *
      * @return The newly created Tween.
      */
    UTweenVector* AppendTweenScaleSceneComponentBy(USceneComponent* TweenTarget,
                                                   const FVector& By,
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
      * Appends to this TweenContainer a custom Tween that goes from a starting value to an ending one. This type of Tween is meant for creating custom behaviours
      * by binding a function or an event to the OnTweenUpdate delegate in order to use the tweened value at each Tick by calling GetCurrentValue from the Tween object.
      * It will be executed when all previous Tweens in the TweenContainer are completed.
      *
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
      *
      * @return The newly created Tween.
      */
    UTweenVector* AppendTweenCustomVector(UObject* TweenTarget,
                                          const FVector& From,
                                          const FVector& To,
                                          float Duration              = 1.0f,
                                          ETweenEaseType EaseType     = ETweenEaseType::Linear,
                                          int32 NumLoops              = 1,
                                          ETweenLoopType LoopType     = ETweenLoopType::Yoyo,
                                          float Delay                 = 0.0f,
                                          float TimeScale             = 1.0f,
                                          bool TweenWhileGameIsPaused = false);

    /* TweenRotator methods */

    /**
      * Appends to this TweenContainer a Tween that rotates an Actor from its current orientation (at the start of the Tween) to the given rotation.
      * It will be executed when all previous Tweens in the TweenContainer are completed.
      *
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
      * @param TweenWhileGameIsPaused Sets whether the Tween should keep updating while the game is paused. Useful for Tween on UMG widgets that animate menus.
      *
      * @return The newly created Tween.
      */
    UTweenRotator* AppendTweenRotateActorTo(AActor* TweenTarget,
                                            const FRotator& To,
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
      * Appends to this TweenContainer a Tween that rotates an Actor by the given offset with respect to its current orientation (at the start of the Tween).
      * It will be executed when all previous Tweens in the TweenContainer are completed.
      *
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
      * @param TweenWhileGameIsPaused Sets whether the Tween should keep updating while the game is paused. Useful for Tween on UMG widgets that animate menus.
      *
      * @return The newly created Tween.
      */
    UTweenRotator* AppendTweenRotateActorBy(AActor* TweenTarget,
                                            const FRotator& By,
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
      * Appends to this TweenContainer a Tween that rotates a SceneComponent from its current orientation (at the start of the Tween) to the given rotation.
      * It will be executed when all previous Tweens in the TweenContainer are completed.
      *
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
      * @param TweenWhileGameIsPaused Sets whether the Tween should keep updating while the game is paused. Useful for Tween on UMG widgets that animate menus.
      *
      * @return The newly created Tween.
      */
    UTweenRotator* AppendTweenRotateSceneComponentTo(USceneComponent* TweenTarget,
                                                     const FRotator& To,
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
      * Appends to this TweenContainer a Tween that rotates a SceneComponent by the given offset with respect to its current orientation (at the start of the Tween).
      * It will be executed when all previous Tweens in the TweenContainer are completed.
      *
      * @param TweenTarget The SceneComponent to rotate.
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
      *
      * @return The newly created Tween.
      */
    UTweenRotator* AppendTweenRotateSceneComponentBy(USceneComponent* TweenTarget,
                                                     const FRotator& By,
                                                     float Duration              = 1.0f,
                                                     ETweenEaseType EaseType     = ETweenEaseType::Linear,
                                                     bool LocalSpace             = false,
                                                     bool DeleteTweenOnHit       = false,
                                                     bool DeleteTweenOnOverlap   = false,
                                                     int32 NumLoops              = 1,
                                                     ETweenLoopType LoopType    = ETweenLoopType::Yoyo,
                                                     float Delay                = 0.0f,
                                                     float TimeScale             = 1.0f,
                                                     bool TweenWhileGameIsPaused = false);

    /* TweenLinearColor methods */

    /**
      * Appends to this TweenContainer a Tween that modifies a "Vector" material parameter from the starting value to the ending value.
      * It will be executed when all previous Tweens in the TweenContainer are completed.
      *
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
      * @param TweenWhileGameIsPaused Sets whether the Tween should keep updating while the game is paused. Useful for Tween on UMG widgets that animate menus.
      *
      * @return The newly created Tween.
      */
    UTweenLinearColor* AppendTweenMaterialVectorFromTo(UMaterialInstanceDynamic* TweenTarget,
                                                       const FName& ParameterName,
                                                       const FLinearColor& From,
                                                       const FLinearColor& To,
                                                       float Duration              = 1.0f,
                                                       ETweenEaseType EaseType     = ETweenEaseType::Linear,
                                                       int32 NumLoops              = 1,
                                                       ETweenLoopType LoopType     = ETweenLoopType::Yoyo,
                                                       float Delay                 = 0.0f,
                                                       float TimeScale             = 1.0f,
                                                       bool TweenWhileGameIsPaused = false);

    /**
      * Appends to this TweenContainer a Tween that modifies a "Vector" material parameter from its current value (at the start of the Tween) to the ending value.
      * It will be executed when all previous Tweens in the TweenContainer are completed.
      *
      * @param TweenTarget The target material.
      * @param ParameterName The name of the material's parameter to tween.
      * @param To The ending value.
      * @param Duration The total duration of the Tween (in seconds).
      * @param EaseType	The easing functions to apply.
      * @param NumLoops	The number of times the Tween should repeat. If <= 0, it will loop indefinitely.
      * @param LoopType	The type of loop to apply (if "yoyo", it will go backwards when it reached the end; otherwise it will reset).
      * @param Delay The initial delay to apply to the Tween (in seconds).
      * @param TimeScale The scale to apply to the Tween execution. If < 1 the Tween will slow down, if > 1 it will speed up. If < 0 it will make the Tween go backward.
      * @param TweenWhileGameIsPaused Sets whether the Tween should keep updating while the game is paused. Useful for Tween on UMG widgets that animate menus.
      *
      * @return The newly created Tween.
      */
    UTweenLinearColor* AppendTweenMaterialVectorTo(UMaterialInstanceDynamic* TweenTarget,
                                                   const FName& ParameterName,
                                                   const FLinearColor& To,
                                                   float Duration              = 1.0f,
                                                   ETweenEaseType EaseType     = ETweenEaseType::Linear,
                                                   int32 NumLoops              = 1,
                                                   ETweenLoopType LoopType     = ETweenLoopType::Yoyo,
                                                   float Delay                 = 0.0f,
                                                   float TimeScale             = 1.0f,
                                                   bool TweenWhileGameIsPaused = false);

    /* TweenFloat methods */


    /**
      * Appends to this TweenContainer a Tween that modifies a "float" material parameter from the starting value to the ending value.
      * It will be executed when all previous Tweens in the TweenContainer are completed.
      *
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
      * @param TweenWhileGameIsPaused Sets whether the Tween should keep updating while the game is paused. Useful for Tween on UMG widgets that animate menus.
      *
      * @return The newly created Tween.
      */
    UTweenFloat* AppendTweenMaterialFloatFromTo(UMaterialInstanceDynamic* TweenTarget,
                                                const FName& ParameterName,
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
      * Appends to this TweenContainer a Tween that modifies a "float" material parameter from its current value (at the start of the Tween) to the ending value.
      * It will be executed when all previous Tweens in the TweenContainer are completed.
      *
      * @param TweenTarget The target material.
      * @param ParameterName The name of the material's parameter to tween.
      * @param To The ending value.
      * @param Duration The total duration of the Tween (in seconds).
      * @param EaseType	The easing functions to apply.
      * @param NumLoops	The number of times the Tween should repeat. If <= 0, it will loop indefinitely.
      * @param LoopType	The type of loop to apply (if "yoyo", it will go backwards when it reached the end; otherwise it will reset).
      * @param Delay The initial delay to apply to the Tween (in seconds).
      * @param TimeScale The scale to apply to the Tween execution. If < 1 the Tween will slow down, if > 1 it will speed up. If < 0 it will make the Tween go backward.
      * @param TweenWhileGameIsPaused Sets whether the Tween should keep updating while the game is paused. Useful for Tween on UMG widgets that animate menus.
      *
      * @return The newly created Tween.
      */
    UTweenFloat* AppendTweenMaterialFloatTo(UMaterialInstanceDynamic* TweenTarget,
                                            const FName& ParameterName,
                                            float To,
                                            float Duration              = 1.0f,
                                            ETweenEaseType EaseType     = ETweenEaseType::Linear,
                                            int32 NumLoops              = 1,
                                            ETweenLoopType LoopType     = ETweenLoopType::Yoyo,
                                            float Delay                 = 0.0f,
                                            float TimeScale             = 1.0f,
                                            bool TweenWhileGameIsPaused = false);


    /**
      * Appends to this TweenContainer a Tween that rotates an Actor around a given pivot point, with a given radius and rotation axis. The Actor will move
      * relative to its parent (if there is none, it will move in world coordinates).
      * It will be executed when all previous Tweens in the TweenContainer are completed.
      *
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
      * @param TweenWhileGameIsPaused Sets whether the Tween should keep updating while the game is paused. Useful for Tween on UMG widgets that animate menus.
      *
      * @return The newly created Tween.
      */
    UTweenFloat* AppendTweenRotateActorAroundPoint(AActor* TweenTarget,
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
      * Appends to the TweenContainer a Tween that rotates an Actor around a given pivot point by an offset angle. The radius and the rotation axis will be automatically computed.
      * The Actor will move relative to its parent (if there is none, it will move in world coordinates).
      * It will be executed when all previous Tweens in the TweenContainer are completed.
      *
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
      *
      * @return The newly created Tween.
      */
    UTweenFloat* AppendTweenRotateActorAroundPointByOffset(AActor* TweenTarget,
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
      * Appends to this TweenContainer a Tween that makes an Actor follow a spline path.
      * It will be executed when all previous Tweens in the TweenContainer are completed.
      *
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
      *
      * @return The newly created Tween.
      */
    UTweenFloat* AppendTweenActorFollowSpline(AActor* TweenTarget,
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
                                              bool TweenWhileGameIsPaused = false);


    /**
      * Appends to this TweenContainer a Tween that rotates an SceneComponent around a given pivot point, with a given radius and rotation axis. The Actor will move
      * relative to its parent (if there is none, it will move in world coordinates).
      * It will be executed when all previous Tweens in the TweenContainer are completed.
      *
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
      *
      * @return The newly created Tween.
      */
    UTweenFloat* AppendTweenRotateSceneComponentAroundPoint(USceneComponent* TweenTarget,
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
      * Appends to the TweenContainer a Tween that rotates an SceneComponent around a given pivot point by an offset angle. The radius and the rotation axis will be automatically computed. The SceneComponent will move
      * relative to its parent (if there is none, it will move in world coordinates).
      * It will be executed when all previous Tweens in the TweenContainer are completed.
      *
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
      *
      * @return The newly created Tween.
      */
    UTweenFloat* AppendTweenRotateSceneComponentAroundPointByOffset(USceneComponent* TweenTarget,
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
      * Appends to this TweenContainer a Tween that makes an SceneComponent follow a spline path.
      * It will be executed when all previous Tweens in the TweenContainer are completed.
      *
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
      *
      * @return The newly created Tween.
      */
    UTweenFloat* AppendTweenSceneComponentFollowSpline(USceneComponent* TweenTarget,
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
                                                       bool TweenWhileGameIsPaused = false);


    /**
      * Appends to this TweenContainer a Tween that makes a UMG widget rotate to the given angle.
      * It will be executed when all previous Tweens in the TweenContainer are completed.
      *
      * @param TweenTarget The target Widget.
      * @param To The ending value.
      * @param Duration The total duration of the Tween (in seconds).
      * @param EaseType	The easing functions to apply.
      * @param NumLoops	The number of times the Tween should repeat. If <= 0, it will loop indefinitely.
      * @param LoopType	The type of loop to apply (if "yoyo", it will go backwards when it reached the end; otherwise it will reset).
      * @param Delay The initial delay to apply to the Tween (in seconds).
      * @param TimeScale The scale to apply to the Tween execution. If < 1 the Tween will slow down, if > 1 it will speed up. If < 0 it will make the Tween go backward.
      * @param TweenWhileGameIsPaused Sets whether the Tween should keep updating while the game is paused. Useful for Tween on UMG widgets that animate menus.
      *
      * @return The newly created Tween.
      */
    UTweenFloat* AppendTweenWidgetAngleTo(UWidget* TweenTarget,
                                          float To,
                                          float Duration              = 1.0f,
                                          ETweenEaseType EaseType     = ETweenEaseType::Linear,
                                          int32 NumLoops              = 1,
                                          ETweenLoopType LoopType     = ETweenLoopType::Yoyo,
                                          float Delay                 = 0.0f,
                                          float TimeScale             = 1.0f,
                                          bool TweenWhileGameIsPaused = false);

    /**
      * Appends to this TweenContainer a Tween that makes a UMG widget's opacity reach the given value.
      * It will be executed when all previous Tweens in the TweenContainer are completed.
      *
      * @param TweenTarget The target Widget.
      * @param To The ending value.
      * @param Duration The total duration of the Tween (in seconds).
      * @param EaseType	The easing functions to apply.
      * @param NumLoops	The number of times the Tween should repeat. If <= 0, it will loop indefinitely.
      * @param LoopType	The type of loop to apply (if "yoyo", it will go backwards when it reached the end; otherwise it will reset).
      * @param Delay The initial delay to apply to the Tween (in seconds).
      * @param TimeScale The scale to apply to the Tween execution. If < 1 the Tween will slow down, if > 1 it will speed up. If < 0 it will make the Tween go backward.
      * @param TweenWhileGameIsPaused Sets whether the Tween should keep updating while the game is paused. Useful for Tween on UMG widgets that animate menus.
      *
      * @return The newly created Tween.
      */
    UTweenFloat* AppendTweenWidgetOpacityTo(UWidget* TweenTarget,
                                            float To,
                                            float Duration              = 1.0f,
                                            ETweenEaseType EaseType     = ETweenEaseType::Linear,
                                            int32 NumLoops              = 1,
                                            ETweenLoopType LoopType     = ETweenLoopType::Yoyo,
                                            float Delay                 = 0.0f,
                                            float TimeScale             = 1.0f,
                                            bool TweenWhileGameIsPaused = false);

    /**
      * Appends to this TweenContainer a custom Tween that goes from a starting float value to an ending one. This type of Tween is meant for creating custom behaviours
      * by binding a function or an event to the OnTweenUpdate delegate in order to use the tweened value at each Tick by calling GetCurrentValue from the Tween object.
      * It will be executed when all previous Tweens in the TweenContainer are completed.
      *
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
      *
      * @return The newly created Tween.
      */
    UTweenFloat* AppendTweenCustomFloat(UObject* TweenTarget,
                                        float From,
                                        float To,
                                        float Duration              = 1.0f,
                                        ETweenEaseType EaseType     = ETweenEaseType::Linear,
                                        int32 NumLoops              = 1,
                                        ETweenLoopType LoopType     = ETweenLoopType::Yoyo,
                                        float Delay                 = 0.0f,
                                        float TimeScale             = 1.0f,
                                        bool TweenWhileGameIsPaused = false);


    /* TweenVector2D methods */


    /**
      * Appends to this TweenContainer a Tween that moves a UMG widget from its current location (at the start of the Tween) to the given location.
      * It will be executed when all previous Tweens in the TweenContainer are completed.
      *
      * @param TweenTarget The Widget to move.
      * @param To The ending value.
      * @param Duration The total duration of the Tween (in seconds).
      * @param EaseType	The easing functions to apply.
      * @param NumLoops	The number of times the Tween should repeat. If <= 0, it will loop indefinitely.
      * @param LoopType	The type of loop to apply (if "yoyo", it will go backwards when it reached the end; otherwise it will reset).
      * @param Delay The initial delay to apply to the Tween (in seconds).
      * @param TimeScale The scale to apply to the Tween execution. If < 1 the Tween will slow down, if > 1 it will speed up. If < 0 it will make the Tween go backward.
      * @param TweenWhileGameIsPaused Sets whether the Tween should keep updating while the game is paused. Useful for Tween on UMG widgets that animate menus.
      *
      * @return The newly created Tween.
      */
    UTweenVector2D* AppendTweenMoveWidgetTo(UWidget* TweenTarget,
                                            const FVector2D& To,
                                            float Duration              = 1.0f,
                                            ETweenEaseType EaseType     = ETweenEaseType::Linear,
                                            int32 NumLoops              = 1,
                                            ETweenLoopType LoopType     = ETweenLoopType::Yoyo,
                                            float Delay                 = 0.0f,
                                            float TimeScale             = 1.0f,
                                            bool TweenWhileGameIsPaused = false);


    /**
      * Appends to this TweenContainer a Tween that moves a UMG widget by the given offset with respect to its current location (at the start of the Tween).
      * It will be executed when all previous Tweens in the TweenContainer are completed.
      *
      * @param TweenTarget The Widget to move.
      * @param By The offset to apply.
      * @param Duration The total duration of the Tween (in seconds).
      * @param EaseType	The easing functions to apply.
      * @param NumLoops	The number of times the Tween should repeat. If <= 0, it will loop indefinitely.
      * @param LoopType	The type of loop to apply (if "yoyo", it will go backwards when it reached the end; otherwise it will reset).
      * @param Delay The initial delay to apply to the Tween (in seconds).
      * @param TimeScale The scale to apply to the Tween execution. If < 1 the Tween will slow down, if > 1 it will speed up. If < 0 it will make the Tween go backward.
      * @param TweenWhileGameIsPaused Sets whether the Tween should keep updating while the game is paused. Useful for Tween on UMG widgets that animate menus.
      *
      * @return The newly created Tween.
      */
    UTweenVector2D* AppendTweenMoveWidgetBy(UWidget* TweenTarget,
                                            const FVector2D& By,
                                            float Duration              = 1.0f,
                                            ETweenEaseType EaseType     = ETweenEaseType::Linear,
                                            int32 NumLoops              = 1,
                                            ETweenLoopType LoopType     = ETweenLoopType::Yoyo,
                                            float Delay                 = 0.0f,
                                            float TimeScale             = 1.0f,
                                            bool TweenWhileGameIsPaused = false);


    /**
      * Appends to this TweenContainer a Tween that moves a UMG widget from its current scale (at the start of the Tween) to the given size.
      * It will be executed when all previous Tweens in the TweenContainer are completed.
      *
      * @param TweenTarget The Widget to scale.
      * @param To The ending value.
      * @param Duration The total duration of the Tween (in seconds).
      * @param EaseType	The easing functions to apply.
      * @param NumLoops	The number of times the Tween should repeat. If <= 0, it will loop indefinitely.
      * @param LoopType	The type of loop to apply (if "yoyo", it will go backwards when it reached the end; otherwise it will reset).
      * @param Delay The initial delay to apply to the Tween (in seconds).
      * @param TimeScale The scale to apply to the Tween execution. If < 1 the Tween will slow down, if > 1 it will speed up. If < 0 it will make the Tween go backward.
      * @param TweenWhileGameIsPaused Sets whether the Tween should keep updating while the game is paused. Useful for Tween on UMG widgets that animate menus.
      *
      * @return The newly created Tween.
      */
    UTweenVector2D* AppendTweenScaleWidgetTo(UWidget* TweenTarget,
                                             const FVector2D& To,
                                             float Duration              = 1.0f,
                                             ETweenEaseType EaseType     = ETweenEaseType::Linear,
                                             int32 NumLoops              = 1,
                                             ETweenLoopType LoopType     = ETweenLoopType::Yoyo,
                                             float Delay                 = 0.0f,
                                             float TimeScale             = 1.0f,
                                             bool TweenWhileGameIsPaused = false);


    /**
      * Appends to this TweenContainer a Tween that scales a UMG widget by the given offset with respect to its current size (at the start of the Tween).
      * It will be executed when all previous Tweens in the TweenContainer are completed.
      *
      * @param TweenTarget The Widget to scale.
      * @param By The offset to apply.
      * @param Duration The total duration of the Tween (in seconds).
      * @param EaseType	The easing functions to apply.
      * @param NumLoops	The number of times the Tween should repeat. If <= 0, it will loop indefinitely.
      * @param LoopType	The type of loop to apply (if "yoyo", it will go backwards when it reached the end; otherwise it will reset).
      * @param Delay The initial delay to apply to the Tween (in seconds).
      * @param TimeScale The scale to apply to the Tween execution. If < 1 the Tween will slow down, if > 1 it will speed up. If < 0 it will make the Tween go backward.
      * @param TweenWhileGameIsPaused Sets whether the Tween should keep updating while the game is paused. Useful for Tween on UMG widgets that animate menus.
      *
      * @return The newly created Tween.
      */
    UTweenVector2D* AppendTweenScaleWidgetBy(UWidget* TweenTarget,
                                             const FVector2D& By,
                                             float Duration              = 1.0f,
                                             ETweenEaseType EaseType     = ETweenEaseType::Linear,
                                             int32 NumLoops              = 1,
                                             ETweenLoopType LoopType     = ETweenLoopType::Yoyo,
                                             float Delay                 = 0.0f,
                                             float TimeScale             = 1.0f,
                                             bool TweenWhileGameIsPaused = false);

    /**
      * Appends to this TweenContainer a Tween that modifies a UMG widget's shear value from its current value (at the start of the Tween) to the given ending value.
      * It will be executed when all previous Tweens in the TweenContainer are completed.
      *
      * @param TweenTarget The Widget to shear.
      * @param To The ending value.
      * @param Duration The total duration of the Tween (in seconds).
      * @param EaseType	The easing functions to apply.
      * @param NumLoops	The number of times the Tween should repeat. If <= 0, it will loop indefinitely.
      * @param LoopType	The type of loop to apply (if "yoyo", it will go backwards when it reached the end; otherwise it will reset).
      * @param Delay The initial delay to apply to the Tween (in seconds).
      * @param TimeScale The scale to apply to the Tween execution. If < 1 the Tween will slow down, if > 1 it will speed up. If < 0 it will make the Tween go backward.
      * @param TweenWhileGameIsPaused Sets whether the Tween should keep updating while the game is paused. Useful for Tween on UMG widgets that animate menus.
      *
      * @return The newly created Tween.
      */
    UTweenVector2D* AppendTweenShearWidgetTo(UWidget* TweenTarget,
                                             const FVector2D& To,
                                             float Duration              = 1.0f,
                                             ETweenEaseType EaseType     = ETweenEaseType::Linear,
                                             int32 NumLoops              = 1,
                                             ETweenLoopType LoopType     = ETweenLoopType::Yoyo,
                                             float Delay                 = 0.0f,
                                             float TimeScale             = 1.0f,
                                             bool TweenWhileGameIsPaused = false);

    /**
      * Appends to this TweenContainer a custom Tween that goes from a starting value to an ending one. This type of Tween is meant for creating custom behaviours
      * by binding a function or an event to the OnTweenUpdate delegate in order to use the tweened value at each Tick by calling GetCurrentValue from the Tween object.
      * It will be executed when all previous Tweens in the TweenContainer are completed.
      *
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
      *
      * @return The newly created Tween.
      */
    UTweenVector2D* AppendTweenCustomVector2D(UObject* TweenTarget,
                                              const FVector2D& From,
                                              const FVector2D& To,
                                              float Duration              = 1.0f,
                                              ETweenEaseType EaseType     = ETweenEaseType::Linear,
                                              int32 NumLoops              = 1,
                                              ETweenLoopType LoopType     = ETweenLoopType::Yoyo,
                                              float Delay                 = 0.0f,
                                              float TimeScale             = 1.0f,
                                              bool TweenWhileGameIsPaused = false);


    /*
     **************************************************************************
     * "Join Tween" methods
     **************************************************************************
     */


    /* TweenVector methods */

    /**
      * Joins to this TweenContainer a Tween that moves an Actor by the given offset with respect to its current location (at the start of the Tween).
      * It will be executed in parallel with the last appended Tween in the TweenContainer.
      *
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
      *
      * @return The newly created Tween.
      */
    UTweenVector* JoinTweenMoveActorTo(AActor* TweenTarget,
                                       const FVector& To,
                                       float Duration              = 1.0f,
                                       ETweenEaseType EaseType     = ETweenEaseType::Linear,
                                       ETweenSpace TweenSpace      = ETweenSpace::World,
                                       bool DeleteTweenOnHit       = false,
                                       bool DeleteTweenOnOverlap   = false,
                                       float Delay                 = 0.0f,
                                       float TimeScale             = 1.0f,
                                       bool TweenWhileGameIsPaused = false);

    /**
      * Joins to this TweenContainer a Tween that moves an Actor by the given offset with respect to its current location (at the start of the Tween).
      * It will be executed in parallel with the last appended Tween in the TweenContainer.
      *
      * @param TweenTarget The Actor to move.
      * @param By The offset to apply.
      * @param Duration The total duration of the Tween (in seconds).
      * @param EaseType	The easing functions to apply.
      * @param DeleteTweenOnHit If true the Tween will be deleted when the TweenTarget hits something.
      * @param DeleteTweenOnOverlap If true the Tween will be deleted when the TweenTarget overlaps something.
      * @param Delay The initial delay to apply to the Tween (in seconds).
      * @param TimeScale The scale to apply to the Tween execution. If < 1 the Tween will slow down, if > 1 it will speed up. If < 0 it will make the Tween go backward.
      * @param TweenWhileGameIsPaused Sets whether the Tween should keep updating while the game is paused. Useful for Tween on UMG widgets that animate menus.
      *
      * @return The newly created Tween.
      */
    UTweenVector* JoinTweenMoveActorBy(AActor* TweenTarget,
                                       const FVector& By,
                                       float Duration              = 1.0f,
                                       ETweenEaseType EaseType     = ETweenEaseType::Linear,
                                       bool DeleteTweenOnHit       = false,
                                       bool DeleteTweenOnOverlap   = false,
                                       float Delay                 = 0.0f,
                                       float TimeScale             = 1.0f,
                                       bool TweenWhileGameIsPaused = false);


    /**
      * Joins to this TweenContainer a Tween that scales an Actor from its current scale (at the start of the Tween) to the given size.
      * It will be executed in parallel with the last appended Tween in the TweenContainer.
      *
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
      *
      * @return The newly created Tween.
      */
    UTweenVector* JoinTweenScaleActorTo(AActor* TweenTarget,
                                        const FVector& To,
                                        float Duration              = 1.0f,
                                        ETweenEaseType EaseType     = ETweenEaseType::Linear,
                                        ETweenSpace TweenSpace      = ETweenSpace::World,
                                        bool DeleteTweenOnHit       = false,
                                        bool DeleteTweenOnOverlap   = false,
                                        float Delay                 = 0.0f,
                                        float TimeScale             = 1.0f,
                                        bool TweenWhileGameIsPaused = false);


    /**
      * Joins to this TweenContainer a Tween that scales an Actor by the given offset with respect to its current size (at the start of the Tween).
      * It will be executed in parallel with the last appended Tween in the TweenContainer.

      * @param TweenTarget The Actor to move.
      * @param By The offset to apply.
      * @param Duration The total duration of the Tween (in seconds).
      * @param EaseType	The easing functions to apply.
      * @param DeleteTweenOnHit If true the Tween will be deleted when the TweenTarget hits something.
      * @param DeleteTweenOnOverlap If true the Tween will be deleted when the TweenTarget overlaps something.
      * @param Delay The initial delay to apply to the Tween (in seconds).
      * @param TimeScale The scale to apply to the Tween execution. If < 1 the Tween will slow down, if > 1 it will speed up. If < 0 it will make the Tween go backward.
      * @param TweenWhileGameIsPaused Sets whether the Tween should keep updating while the game is paused. Useful for Tween on UMG widgets that animate menus.
      *
      * @return The newly created Tween.
      */
    UTweenVector* JoinTweenScaleActorBy(AActor* TweenTarget,
                                        const FVector& By,
                                        float Duration              = 1.0f,
                                        ETweenEaseType EaseType     = ETweenEaseType::Linear,
                                        bool DeleteTweenOnHit       = false,
                                        bool DeleteTweenOnOverlap   = false,
                                        float Delay                 = 0.0f,
                                        float TimeScale             = 1.0f,
                                        bool TweenWhileGameIsPaused = false);


    /**
      * Joins to this TweenContainer a Tween that moves a SceneComponent by the given offset with respect to its current location (at the start of the Tween).
      * It will be executed in parallel with the last appended Tween in the TweenContainer.
      *
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
      *
      * @return The newly created Tween.
      */
    UTweenVector* JoinTweenMoveSceneComponentTo(USceneComponent* TweenTarget,
                                                const FVector& To,
                                                float Duration              = 1.0f,
                                                ETweenEaseType EaseType     = ETweenEaseType::Linear,
                                                ETweenSpace TweenSpace      = ETweenSpace::World,
                                                bool DeleteTweenOnHit       = false,
                                                bool DeleteTweenOnOverlap   = false,
                                                float Delay                 = 0.0f,
                                                float TimeScale             = 1.0f,
                                                bool TweenWhileGameIsPaused = false);


    /**
      * Joins to this TweenContainer a Tween that moves a SceneComponent by the given offset with respect to its current location (at the start of the Tween).
      * It will be executed in parallel with the last appended Tween in the TweenContainer.
      *
      * @param TweenTarget The SceneComponent to move.
      * @param By The offset to apply.
      * @param Duration The total duration of the Tween (in seconds).
      * @param EaseType	The easing functions to apply.
      * @param DeleteTweenOnHit If true the Tween will be deleted when the TweenTarget hits something.
      * @param DeleteTweenOnOverlap If true the Tween will be deleted when the TweenTarget overlaps something.
      * @param Delay The initial delay to apply to the Tween (in seconds).
      * @param TimeScale The scale to apply to the Tween execution. If < 1 the Tween will slow down, if > 1 it will speed up. If < 0 it will make the Tween go backward.
      * @param TweenWhileGameIsPaused Sets whether the Tween should keep updating while the game is paused. Useful for Tween on UMG widgets that animate menus.
      *
      * @return The newly created Tween.
      */
    UTweenVector* JoinTweenMoveSceneComponentBy(USceneComponent* TweenTarget,
                                                const FVector& By,
                                                float Duration              = 1.0f,
                                                ETweenEaseType EaseType     = ETweenEaseType::Linear,
                                                bool DeleteTweenOnHit       = false,
                                                bool DeleteTweenOnOverlap   = false,
                                                float Delay                 = 0.0f,
                                                float TimeScale             = 1.0f,
                                                bool TweenWhileGameIsPaused = false);


    /**
      * Joins to this TweenContainer a Tween that scales a SceneComponent from its current scale (at the start of the Tween) to the given size.
      * It will be executed in parallel with the last appended Tween in the TweenContainer.
      *
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
      *
      * @return The newly created Tween.
      */
    UTweenVector* JoinTweenScaleSceneComponentTo(USceneComponent* TweenTarget,
                                                 const FVector& To,
                                                 float Duration              = 1.0f,
                                                 ETweenEaseType EaseType     = ETweenEaseType::Linear,
                                                 ETweenSpace TweenSpace      = ETweenSpace::World,
                                                 bool DeleteTweenOnHit       = false,
                                                 bool DeleteTweenOnOverlap   = false,
                                                 float Delay                 = 0.0f,
                                                 float TimeScale             = 1.0f,
                                                 bool TweenWhileGameIsPaused = false);

    /**
      * Joins to this TweenContainer a Tween that scales a SceneComponent by the given offset with respect to its current size (at the start of the Tween).
      * It will be executed in parallel with the last appended Tween in the TweenContainer.

      * @param TweenTarget The SceneComponent to move.
      * @param By The offset to apply.
      * @param Duration The total duration of the Tween (in seconds).
      * @param EaseType	The easing functions to apply.
      * @param DeleteTweenOnHit If true the Tween will be deleted when the TweenTarget hits something.
      * @param DeleteTweenOnOverlap If true the Tween will be deleted when the TweenTarget overlaps something.
      * @param Delay The initial delay to apply to the Tween (in seconds).
      * @param TimeScale The scale to apply to the Tween execution. If < 1 the Tween will slow down, if > 1 it will speed up. If < 0 it will make the Tween go backward.
      * @param TweenWhileGameIsPaused Sets whether the Tween should keep updating while the game is paused. Useful for Tween on UMG widgets that animate menus.
      *
      * @return The newly created Tween.
      */
    UTweenVector* JoinTweenScaleSceneComponentBy(USceneComponent* TweenTarget,
                                                 const FVector& By,
                                                 float Duration              = 1.0f,
                                                 ETweenEaseType EaseType     = ETweenEaseType::Linear,
                                                 bool DeleteTweenOnHit       = false,
                                                 bool DeleteTweenOnOverlap   = false,
                                                 float Delay                 = 0.0f,
                                                 float TimeScale             = 1.0f,
                                                 bool TweenWhileGameIsPaused = false);


    /**
      * Joins to this TweenContainer a custom Tween that goes from a starting value to an ending one. This type of Tween is meant for creating custom behaviours
      * by binding a function or an event to the OnTweenUpdate delegate in order to use the tweened value at each Tick by calling GetCurrentValue from the Tween object.
      * It will be executed in parallel with the last appended Tween in the TweenContainer.
      *
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
    UTweenVector* JoinTweenCustomVector(UObject* TweenTarget,
                                        const FVector& From,
                                        const FVector& To,
                                        float Duration              = 1.0f,
                                        ETweenEaseType EaseType     = ETweenEaseType::Linear,
                                        float Delay                 = 0.0f,
                                        float TimeScale             = 1.0f,
                                        bool TweenWhileGameIsPaused = false);


    /* TweenRotator methods */


    /**
      * Joins to this TweenContainer a Tween that rotates an Actor from its current orientation (at the start of the Tween) to the given rotation.
      * It will be executed in parallel with the last appended Tween in the TweenContainer.
      *
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
      * @param TweenWhileGameIsPaused Sets whether the Tween should keep updating while the game is paused. Useful for Tween on UMG widgets that animate menus.
      *
      * @return The newly created Tween.
      */
    UTweenRotator* JoinTweenRotateActorTo(AActor* TweenTarget,
                                          const FRotator& To,
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
      * Joins to this TweenContainer a Tween that rotates an Actor by the given offset with respect to its current orientation (at the start of the Tween).
      * It will be executed in parallel with the last appended Tween in the TweenContainer.
      *
      * @param TweenTarget The Actor to rotate.
      * @param By The offset to apply.
      * @param Duration The total duration of the Tween (in seconds).
      * @param EaseType	The easing functions to apply.
      * @param LocalSpace Whether to rotate around actor's own local axes, not parent/world
      * @param DeleteTweenOnHit If true the Tween will be deleted when the TweenTarget hits something.
      * @param DeleteTweenOnOverlap If true the Tween will be deleted when the TweenTarget overlaps something.
      * @param Delay The initial delay to apply to the Tween (in seconds).
      * @param TimeScale The scale to apply to the Tween execution. If < 1 the Tween will slow down, if > 1 it will speed up. If < 0 it will make the Tween go backward.
      * @param TweenWhileGameIsPaused Sets whether the Tween should keep updating while the game is paused. Useful for Tween on UMG widgets that animate menus.
      *
      * @return The newly created Tween.
      */
    UTweenRotator* JoinTweenRotateActorBy(AActor* TweenTarget,
                                          const FRotator& By,
                                          float Duration              = 1.0f,
                                          ETweenEaseType EaseType     = ETweenEaseType::Linear,
                                          bool LocalSpace             = false,
                                          bool DeleteTweenOnHit       = false,
                                          bool DeleteTweenOnOverlap   = false,
                                          float Delay                 = 0.0f,
                                          float TimeScale             = 1.0f,
                                          bool TweenWhileGameIsPaused = false);


    /**
      * Joins to this TweenContainer a Tween that rotates a SceneComponent from its current orientation (at the start of the Tween) to the given rotation.
      * It will be executed in parallel with the last appended Tween in the TweenContainer.
      *
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
      * @param TweenWhileGameIsPaused Sets whether the Tween should keep updating while the game is paused. Useful for Tween on UMG widgets that animate menus.
      *
      * @return The newly created Tween.
      */
    UTweenRotator* JoinTweenRotateSceneComponentTo(USceneComponent* TweenTarget,
                                                   const FRotator& To,
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
      * Joins to this TweenContainer a Tween that rotates a SceneComponent by the given offset with respect to its current orientation (at the start of the Tween).
      * It will be executed in parallel with the last appended Tween in the TweenContainer.
      *
      * @param TweenTarget The SceneComponent to rotate.
      * @param By The offset to apply.
      * @param Duration The total duration of the Tween (in seconds).
      * @param EaseType	The easing functions to apply.
      * @param LocalSpace Whether to rotate around component's own local axes, not parent/world
      * @param DeleteTweenOnHit If true the Tween will be deleted when the TweenTarget hits something.
      * @param DeleteTweenOnOverlap If true the Tween will be deleted when the TweenTarget overlaps something.
      * @param Delay The initial delay to apply to the Tween (in seconds).
      * @param TimeScale The scale to apply to the Tween execution. If < 1 the Tween will slow down, if > 1 it will speed up. If < 0 it will make the Tween go backward.
      * @param TweenWhileGameIsPaused Sets whether the Tween should keep updating while the game is paused. Useful for Tween on UMG widgets that animate menus.
      *
      * @return The newly created Tween.
      */
    UTweenRotator* JoinTweenRotateSceneComponentBy(USceneComponent* TweenTarget,
                                                   const FRotator& By,
                                                   float Duration              = 1.0f,
                                                   ETweenEaseType EaseType     = ETweenEaseType::Linear,
                                                   bool LocalSpace             = false,
                                                   bool DeleteTweenOnHit       = false,
                                                   bool DeleteTweenOnOverlap   = false,
                                                   float Delay                 = 0.0f,
                                                   float TimeScale             = 1.0f,
                                                   bool TweenWhileGameIsPaused = false);


    /* TweenLinearColor methods */

    /**
      * Joins to this TweenContainer a Tween that modifies a "Vector" material parameter from the starting value to the ending value.
      * It will be executed in parallel with the last appended Tween in the TweenContainer.
      *
      * @param TweenTarget The target material.
      * @param ParameterName The name of the material's parameter to tween.
      * @param From	The starting value.
      * @param To The ending value.
      * @param Duration The total duration of the Tween (in seconds).
      * @param EaseType	The easing functions to apply.
      * @param Delay The initial delay to apply to the Tween (in seconds).
      * @param TimeScale The scale to apply to the Tween execution. If < 1 the Tween will slow down, if > 1 it will speed up. If < 0 it will make the Tween go backward.
      * @param TweenWhileGameIsPaused Sets whether the Tween should keep updating while the game is paused. Useful for Tween on UMG widgets that animate menus.
      *
      * @return The newly created Tween.
      */
    UTweenLinearColor* JoinTweenMaterialVectorFromTo(UMaterialInstanceDynamic* TweenTarget,
                                                     const FName& ParameterName,
                                                     const FLinearColor& From,
                                                     const FLinearColor& To,
                                                     float Duration              = 1.0f,
                                                     ETweenEaseType EaseType     = ETweenEaseType::Linear,
                                                     float Delay                 = 0.0f,
                                                     float TimeScale             = 1.0f,
                                                     bool TweenWhileGameIsPaused = false);

    /**
      * Joins to this TweenContainer a Tween that modifies a "Vector" material parameter from its current value (at the start of the Tween) to the ending value.
      * It will be executed in parallel with the last appended Tween in the TweenContainer.
      *
      * @param TweenTarget The target material.
      * @param ParameterName The name of the material's parameter to tween.
      * @param To The ending value.
      * @param Duration The total duration of the Tween (in seconds).
      * @param EaseType	The easing functions to apply.
      * @param Delay The initial delay to apply to the Tween (in seconds).
      * @param TimeScale The scale to apply to the Tween execution. If < 1 the Tween will slow down, if > 1 it will speed up. If < 0 it will make the Tween go backward.
      * @param TweenWhileGameIsPaused Sets whether the Tween should keep updating while the game is paused. Useful for Tween on UMG widgets that animate menus.
      *
      * @return The newly created Tween.
      */
    UTweenLinearColor* JoinTweenMaterialVectorTo(UMaterialInstanceDynamic* TweenTarget,
                                                 const FName& ParameterName,
                                                 const FLinearColor& To,
                                                 float Duration              = 1.0f,
                                                 ETweenEaseType EaseType     = ETweenEaseType::Linear,
                                                 float Delay                 = 0.0f,
                                                 float TimeScale             = 1.0f,
                                                 bool TweenWhileGameIsPaused = false);


    /* TweenFloat methods */


    /**
      * Joins to this TweenContainer a Tween that modifies a "float" material parameter from the starting value to the ending value.
      * It will be executed in parallel with the last appended Tween in the TweenContainer.
      *
      * @param TweenTarget The target material.
      * @param ParameterName The name of the material's parameter to tween.
      * @param From	The starting value.
      * @param To The ending value.
      * @param Duration The total duration of the Tween (in seconds).
      * @param EaseType	The easing functions to apply.
      * @param Delay The initial delay to apply to the Tween (in seconds).
      * @param TimeScale The scale to apply to the Tween execution. If < 1 the Tween will slow down, if > 1 it will speed up. If < 0 it will make the Tween go backward.
      * @param TweenWhileGameIsPaused Sets whether the Tween should keep updating while the game is paused. Useful for Tween on UMG widgets that animate menus.
      *
      * @return The newly created Tween.
      */
    UTweenFloat* JoinTweenMaterialFloatFromTo(UMaterialInstanceDynamic* TweenTarget,
                                              const FName& ParameterName,
                                              float From,
                                              float To,
                                              float Duration              = 1.0f,
                                              ETweenEaseType EaseType     = ETweenEaseType::Linear,
                                              float Delay                 = 0.0f,
                                              float TimeScale             = 1.0f,
                                              bool TweenWhileGameIsPaused = false);


    /**
      * Joins to this TweenContainer a Tween that modifies a "float" material parameter from its current value (at the start of the Tween) to the ending value.
      * It will be executed in parallel with the last appended Tween in the TweenContainer.
      *
      * @param TweenTarget The target material.
      * @param ParameterName The name of the material's parameter to tween.
      * @param To The ending value.
      * @param Duration The total duration of the Tween (in seconds).
      * @param EaseType	The easing functions to apply.
      * @param Delay The initial delay to apply to the Tween (in seconds).
      * @param TimeScale The scale to apply to the Tween execution. If < 1 the Tween will slow down, if > 1 it will speed up. If < 0 it will make the Tween go backward.
      * @param TweenWhileGameIsPaused Sets whether the Tween should keep updating while the game is paused. Useful for Tween on UMG widgets that animate menus.
      *
      * @return The newly created Tween.
      */
    UTweenFloat* JoinTweenMaterialFloatTo(UMaterialInstanceDynamic* TweenTarget,
                                          const FName& ParameterName,
                                          float To,
                                          float Duration              = 1.0f,
                                          ETweenEaseType EaseType     = ETweenEaseType::Linear,
                                          float Delay                 = 0.0f,
                                          float TimeScale             = 1.0f,
                                          bool TweenWhileGameIsPaused = false);


    /**
      * Joins to this TweenContainer a Tween that rotates an Actor around a given pivot point, with a given radius and rotation axis. The Actor will move
      * relative to its parent (if there is none, it will move in world coordinates).
      * It will be executed in parallel with the last appended Tween in the TweenContainer.
      *
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
      *
      * @return The newly created Tween.
      */
    UTweenFloat* JoinTweenRotateActorAroundPoint(AActor* TweenTarget,
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
      * Joins to the TweenContainer a Tween that rotates an Actor around a given pivot point by an offset angle. The radius and the rotation axis will be automatically computed. The Actor will move
      * relative to its parent (if there is none, it will move in world coordinates).
      * It will be executed in parallel with the last appended Tween in the TweenContainer.
      *
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
      *
      * @return The newly created Tween.
      */
    UTweenFloat* JoinTweenRotateActorAroundPointByOffset(AActor* TweenTarget,
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
      * Joins to this TweenContainer a Tween that makes an Actor follow a spline path.
      * It will be executed in parallel with the last appended Tween in the TweenContainer.
      *
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
      *
      * @return The newly created Tween.
      */
    UTweenFloat* JoinTweenActorFollowSpline(AActor* TweenTarget,
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
      * Joins to this TweenContainer a Tween that rotates an SceneComponent around a given pivot point, with a given radius and rotation axis. The Actor will move
      * relative to its parent (if there is none, it will move in world coordinates).
      * It will be executed in parallel with the last appended Tween in the TweenContainer.
      *
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
      *
      * @return The newly created Tween.
      */
    UTweenFloat* JoinTweenRotateSceneComponentAroundPoint(USceneComponent* TweenTarget,
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
      * Joins to the TweenContainer a Tween that rotates an SceneComponent around a given pivot point by an offset angle. The radius and the rotation axis will be automatically computed. The SceneComponent will move
      * relative to its parent (if there is none, it will move in world coordinates).
      * It will be executed in parallel with the last appended Tween in the TweenContainer.
      *
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
      *
      * @return The newly created Tween.
      */
    UTweenFloat* JoinTweenRotateSceneComponentAroundPointByOffset(USceneComponent* TweenTarget,
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
      * Joins to this TweenContainer a Tween that makes an SceneComponent follow a spline path.
      * It will be executed in parallel with the last appended Tween in the TweenContainer.
      *
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
      *
      * @return The newly created Tween.
      */
    UTweenFloat* JoinTweenSceneComponentFollowSpline(USceneComponent* TweenTarget,
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
      * Joins to this TweenContainer a Tween that makes a UMG widget rotate to the given angle.
      * It will be executed in parallel with the last appended Tween in the TweenContainer.
      *
      * @param TweenTarget The target Widget.
      * @param To The ending value.
      * @param Duration The total duration of the Tween (in seconds).
      * @param EaseType	The easing functions to apply.
      * @param Delay The initial delay to apply to the Tween (in seconds).
      * @param TimeScale The scale to apply to the Tween execution. If < 1 the Tween will slow down, if > 1 it will speed up. If < 0 it will make the Tween go backward.
      * @param TweenWhileGameIsPaused Sets whether the Tween should keep updating while the game is paused. Useful for Tween on UMG widgets that animate menus.
      *
      * @return The newly created Tween.
      */
    UTweenFloat* JoinTweenWidgetAngleTo(UWidget* TweenTarget,
                                        float To,
                                        float Duration              = 1.0f,
                                        ETweenEaseType EaseType     = ETweenEaseType::Linear,
                                        float Delay                 = 0.0f,
                                        float TimeScale             = 1.0f,
                                        bool TweenWhileGameIsPaused = false);


    /**
      * Joins to this TweenContainer a Tween that makes a UMG widget's opacity reach the given value.
      * It will be executed in parallel with the last appended Tween in the TweenContainer.
      *
      * @param TweenTarget The target Widget.
      * @param To The ending value.
      * @param Duration The total duration of the Tween (in seconds).
      * @param EaseType	The easing functions to apply.
      * @param Delay The initial delay to apply to the Tween (in seconds).
      * @param TimeScale The scale to apply to the Tween execution. If < 1 the Tween will slow down, if > 1 it will speed up. If < 0 it will make the Tween go backward.
      * @param TweenWhileGameIsPaused Sets whether the Tween should keep updating while the game is paused. Useful for Tween on UMG widgets that animate menus.
      *
      * @return The newly created Tween.
      */
    UTweenFloat* JoinTweenWidgetOpacityTo(UWidget* TweenTarget,
                                          float To,
                                          float Duration              = 1.0f,
                                          ETweenEaseType EaseType     = ETweenEaseType::Linear,
                                          float Delay                 = 0.0f,
                                          float TimeScale             = 1.0f,
                                          bool TweenWhileGameIsPaused = false);


    /**
      * Joins to this TweenContainer a custom Tween that goes from a starting float value to an ending one. This type of Tween is meant for creating custom behaviours
      * by binding a function or an event to the OnTweenUpdate delegate in order to use the tweened value at each Tick by calling GetCurrentValue from the Tween object.
      * It will be executed in parallel with the last appended Tween in the TweenContainer.
      *
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
    UTweenFloat* JoinTweenCustomFloat(UObject* TweenTarget,
                                      float From,
                                      float To,
                                      float Duration              = 1.0f,
                                      ETweenEaseType EaseType     = ETweenEaseType::Linear,
                                      float Delay                 = 0.0f,
                                      float TimeScale             = 1.0f,
                                      bool TweenWhileGameIsPaused = false);


    /* TweenVector2D methods */


    /**
      * Joins to this TweenContainer a Tween that moves a UMG widget from its current location (at the start of the Tween) to the given location.
      * It will be executed in parallel with the last appended Tween in the TweenContainer.
      *
      * @param TweenTarget The Widget to move.
      * @param To The ending value.
      * @param Duration The total duration of the Tween (in seconds).
      * @param EaseType	The easing functions to apply.
      * @param Delay The initial delay to apply to the Tween (in seconds).
      * @param TimeScale The scale to apply to the Tween execution. If < 1 the Tween will slow down, if > 1 it will speed up. If < 0 it will make the Tween go backward.
      * @param TweenWhileGameIsPaused Sets whether the Tween should keep updating while the game is paused. Useful for Tween on UMG widgets that animate menus.
      *
      * @return The newly created Tween.
      */
    UTweenVector2D* JoinTweenMoveWidgetTo(UWidget* TweenTarget,
                                          const FVector2D& To,
                                          float Duration              = 1.0f,
                                          ETweenEaseType EaseType     = ETweenEaseType::Linear,
                                          float Delay                 = 0.0f,
                                          float TimeScale             = 1.0f,
                                          bool TweenWhileGameIsPaused = false);

    /**
      * Joins to this TweenContainer a Tween that moves a UMG widget by the given offset with respect to its current location (at the start of the Tween).
      * It will be executed in parallel with the last appended Tween in the TweenContainer.
      *
      * @param TweenTarget The Widget to move.
      * @param By The offset to apply.
      * @param Duration The total duration of the Tween (in seconds).
      * @param EaseType	The easing functions to apply.
      * @param Delay The initial delay to apply to the Tween (in seconds).
      * @param TimeScale The scale to apply to the Tween execution. If < 1 the Tween will slow down, if > 1 it will speed up. If < 0 it will make the Tween go backward.
      * @param TweenWhileGameIsPaused Sets whether the Tween should keep updating while the game is paused. Useful for Tween on UMG widgets that animate menus.
      *
      * @return The newly created Tween.
      */
    UTweenVector2D* JoinTweenMoveWidgetBy(UWidget* TweenTarget,
                                          const FVector2D& By,
                                          float Duration              = 1.0f,
                                          ETweenEaseType EaseType     = ETweenEaseType::Linear,
                                          float Delay                 = 0.0f,
                                          float TimeScale             = 1.0f,
                                          bool TweenWhileGameIsPaused = false);


    /**
      * Joins to this TweenContainer a Tween that moves a UMG widget from its current scale (at the start of the Tween) to the given size.
      * It will be executed in parallel with the last appended Tween in the TweenContainer.
      *
      * @param TweenTarget The Widget to scale.
      * @param To The ending value.
      * @param Duration The total duration of the Tween (in seconds).
      * @param EaseType	The easing functions to apply.
      * @param Delay The initial delay to apply to the Tween (in seconds).
      * @param TimeScale The scale to apply to the Tween execution. If < 1 the Tween will slow down, if > 1 it will speed up. If < 0 it will make the Tween go backward.
      * @param TweenWhileGameIsPaused Sets whether the Tween should keep updating while the game is paused. Useful for Tween on UMG widgets that animate menus.
      *
      * @return The newly created Tween.
      */
    UTweenVector2D* JoinTweenScaleWidgetTo(UWidget* TweenTarget,
                                           const FVector2D& To,
                                           float Duration              = 1.0f,
                                           ETweenEaseType EaseType     = ETweenEaseType::Linear,
                                           float Delay                 = 0.0f,
                                           float TimeScale             = 1.0f,
                                           bool TweenWhileGameIsPaused = false);


    /**
      * Joins to this TweenContainer a Tween that scales a UMG widget by the given offset with respect to its current size (at the start of the Tween).
      * It will be executed in parallel with the last appended Tween in the TweenContainer.
      *
      * @param TweenTarget The Widget to scale.
      * @param By The offset to apply.
      * @param Duration The total duration of the Tween (in seconds).
      * @param EaseType	The easing functions to apply.
      * @param Delay The initial delay to apply to the Tween (in seconds).
      * @param TimeScale The scale to apply to the Tween execution. If < 1 the Tween will slow down, if > 1 it will speed up. If < 0 it will make the Tween go backward.
      * @param TweenWhileGameIsPaused Sets whether the Tween should keep updating while the game is paused. Useful for Tween on UMG widgets that animate menus.
      *
      * @return The newly created Tween.
      */
    UTweenVector2D* JoinTweenScaleWidgetBy(UWidget* TweenTarget,
                                           const FVector2D& By,
                                           float Duration              = 1.0f,
                                           ETweenEaseType EaseType     = ETweenEaseType::Linear,
                                           float Delay                 = 0.0f,
                                           float TimeScale             = 1.0f,
                                           bool TweenWhileGameIsPaused = false);

    /**
      * Joins to this TweenContainer a Tween that modifies a UMG widget's shear value from its current value (at the start of the Tween) to the given ending value.
      * It will be executed in parallel with the last appended Tween in the TweenContainer.
      *
      * @param TweenTarget The Widget to shear.
      * @param To The ending value.
      * @param Duration The total duration of the Tween (in seconds).
      * @param EaseType	The easing functions to apply.
      * @param Delay The initial delay to apply to the Tween (in seconds).
      * @param TimeScale The scale to apply to the Tween execution. If < 1 the Tween will slow down, if > 1 it will speed up. If < 0 it will make the Tween go backward.
      * @param TweenWhileGameIsPaused Sets whether the Tween should keep updating while the game is paused. Useful for Tween on UMG widgets that animate menus.
      *
      * @return The newly created Tween.
      */
    UTweenVector2D* JoinTweenShearWidgetTo(UWidget* TweenTarget,
                                           const FVector2D& By,
                                           float Duration              = 1.0f,
                                           ETweenEaseType EaseType     = ETweenEaseType::Linear,
                                           float Delay                 = 0.0f,
                                           float TimeScale             = 1.0f,
                                           bool TweenWhileGameIsPaused = false);


    /**
      * Joins to this TweenContainer a custom Tween that goes from a starting value to an ending one. This type of Tween is meant for creating custom behaviours
      * by binding a function or an event to the OnTweenUpdate delegate in order to use the tweened value at each Tick by calling GetCurrentValue from the Tween object.
      * It will be executed when all previous Tweens in the TweenContainer are completed.
      *
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
    UTweenVector2D* JoinTweenCustomVector2D(UObject* TweenTarget,
                                            const FVector2D& From,
                                            const FVector2D& To,
                                            float Duration              = 1.0f,
                                            ETweenEaseType EaseType     = ETweenEaseType::Linear,
                                            float Delay                 = 0.0f,
                                            float TimeScale             = 1.0f,
                                            bool TweenWhileGameIsPaused = false);

protected:

    /*
     **************************************************************************
     * Helper methods
     **************************************************************************
     */

    /**
     * @brief RemoveTweensReferences is used by the owning TweenManagerComponent to remove the references of ALL Tweens
     *        owned by this TweenContainer from the Map that keeps track of the currently active Tweens.
     *        This method is called when the TweenContainer is being deleted.
     *
     * @param pTweensReferenceMap The map from which to remove the references.
     */
    void RemoveTweensReferences(TMultiMap<TPair<TWeakObjectPtr<UObject>, ETweenGenericType>, TWeakObjectPtr<UBaseTween>>& pTweensReferenceMap);

    /**
     * @brief InvertTweens inverts ALL Tweens owned by this TweenContainer.
     */
    void InvertTweens();
    
    
    /// @brief The sequences of parallel Tweens that this TweenContainer owns.
    UPROPERTY()
    TArray<FParallelTween> mSequences;

    /// @brief The current sequence's index we're at this moment.
    int32 mCurrentIndex;

    /// @brief Number of loops for the Tweens (if <= 0 it will loop forever).
    int32 mNumLoops;

    /// @brief Loop type for the Tweens.
    ETweenLoopType mLoopType;

    /// @brief Internal loop counter.
    int32 mLoopCounter;

    /// @brief Time scale to apply to the computation of the elapsed time of each Tween.
    float mTimeScale;

    /// @brief Absolute value of the time scale that was set (to avoid it to compute each time).
    float mTimeScaleAbsolute;

    /// @brief True if the TweenContainer's sequences are currently going forward or backward (in case of the "yoyo" loop or a negative timescale).
    bool bIsGoingForward;

    /// @brief If the timescale is negative, the newly added Tweens should be inverted.
    bool bInvertFutureTweens;

    /// @brief Might be the case that during a Tween's update a new parallel Tween is added. This counter is used to check if new Tweens were added during an update.
    int32 mSequencesNumAtUpdate;

    /// @brief True if the TweenContainer is persistent (i.e. won't be deleted when the sequence ends, but must manually be deleted).
    bool bIsPersistent;

    /// @brief True if the sequences arae done. Used to keep track if the TweenContaiener has ended, in case of a persistent container.
    bool bAreSequencesDone;

    /// @brief True if the TweenContainer is currently paused.
    bool bIsTweenContainerPaused;

    /// @brief True if the TweenContainer is currentl marked for deletion (and will be deleted in the next Tick).
    bool bIsTweenContainerPendingDeletion;

    /// @brief True if the TweenContainer has started updating the Tweens; false otherwise.
    bool bHasStartedTweening;

    /// @brief True if at least one Tween handled by this container should tween while the game is paused.
    bool bShouldTweenWhileGamePaused;

public:
    bool ShouldTweenWhileGamePaused() const { return bShouldTweenWhileGamePaused; }
};
