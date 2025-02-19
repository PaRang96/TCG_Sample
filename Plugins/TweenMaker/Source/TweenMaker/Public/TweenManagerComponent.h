// Copyright 2018 Francesco Desogus. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Utils/TweenEnums.h"
#include "Utils/Utility.h"
#include "Engine/HitResult.h"
#include "TweenManagerComponent.generated.h"

class UTweenVectorLatentFactory;
class UTweenVector2DLatentFactory;
class UTweenRotatorLatentFactory;
class UTweenLinearColorLatentFactory;
class UTweenFloatLatentFactory;
class UTweenContainer;
class UBaseTween;
class UTweenVector;
class UTweenVector2D;
class UTweenRotator;
class UTweenLinearColor;
class UTweenFloat;
class USplineComponent;


/*
 **************************************************************************
 * Blueprint delegates declaration
 **************************************************************************
 */

// Generic delegates used for the tween start/update/end events (one for each type).
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FBP_OnTweenVectorChange, UTweenVector*, Tween);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FBP_OnTweenVector2DChange, UTweenVector2D*, Tween);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FBP_OnTweenRotatorChange, UTweenRotator*, Tween);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FBP_OnTweenLinearColorChange, UTweenLinearColor*, Tween);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FBP_OnTweenFloatChange, UTweenFloat*, Tween);

/* Hit and overlap events for Vectors */

// Actors
DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FBP_OnTweenActorBeginOverlapVector, UTweenVector*, Tween, AActor*, ThisActor, AActor*, OtherActor);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_FiveParams(FBP_OnTweenActorHitVector, UTweenVector*, Tween, AActor*, ThisActor, AActor*, OtherActor, FVector, NormalImpulse, const FHitResult&, Hit);

// PrimitiveComponents
DECLARE_DYNAMIC_MULTICAST_DELEGATE_FiveParams(FBP_OnTweenPrimitiveComponentBeginOverlapVector, UTweenVector*, Tween, UPrimitiveComponent*, ThisComponent, AActor*, OtherActor, UPrimitiveComponent*, OtherComp, const FHitResult&, SweepResult);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_SixParams(FBP_OnTweenPrimitiveComponentHitVector, UTweenVector*, Tween, UPrimitiveComponent*, ThisComponent, AActor*, OtherActor, UPrimitiveComponent*, OtherComp, FVector, NormalImpulse, const FHitResult&, HitResult);

/* Hit and overlap events for Rotators */

// Actors
DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FBP_OnTweenActorBeginOverlapRotator, UTweenRotator*, Tween, AActor*, ThisActor, AActor*, OtherActor);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_FiveParams(FBP_OnTweenActorHitRotator, UTweenRotator*, Tween, AActor*, ThisActor, AActor*, OtherActor, FVector, NormalImpulse, const FHitResult&, Hit);

// PrimitiveComponents
DECLARE_DYNAMIC_MULTICAST_DELEGATE_FiveParams(FBP_OnTweenPrimitiveComponentBeginOverlapRotator, UTweenRotator*, Tween, UPrimitiveComponent*, ThisComponent, AActor*, OtherActor, UPrimitiveComponent*, OtherComp, const FHitResult&, SweepResult);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_SixParams(FBP_OnTweenPrimitiveComponentHitRotator, UTweenRotator*, Tween, UPrimitiveComponent*, ThisComponent, AActor*, OtherActor, UPrimitiveComponent*, OtherComp, FVector, NormalImpulse, const FHitResult&, HitResult);

/* Hit and overlap events for floats */

// Actors
DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FBP_OnTweenActorBeginOverlapFloat, UTweenFloat*, Tween, AActor*, ThisActor, AActor*, OtherActor);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_FiveParams(FBP_OnTweenActorHitFloat, UTweenFloat*, Tween, AActor*, ThisActor, AActor*, OtherActor, FVector, NormalImpulse, const FHitResult&, Hit);

// PrimitiveComponents
DECLARE_DYNAMIC_MULTICAST_DELEGATE_FiveParams(FBP_OnTweenPrimitiveComponentBeginOverlapFloat, UTweenFloat*, Tween, UPrimitiveComponent*, ThisComponent, AActor*, OtherActor, UPrimitiveComponent*, OtherComp, const FHitResult&, SweepResult);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_SixParams(FBP_OnTweenPrimitiveComponentHitFloat, UTweenFloat*, Tween, UPrimitiveComponent*, ThisComponent, AActor*, OtherActor, UPrimitiveComponent*, OtherComp, FVector, NormalImpulse, const FHitResult&, HitResult);

/* Callback for splines */

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FBP_OnTweenSplinePointReached, UTweenFloat*, Tween, int32, PointIndex);

/*
 **************************************************************************
 * C++ delegates declaration
 **************************************************************************
 */

DECLARE_DELEGATE_OneParam(FOnTweenVectorChange, UTweenVector*);
DECLARE_DELEGATE_OneParam(FOnTweenVector2DChange, UTweenVector2D*);
DECLARE_DELEGATE_OneParam(FOnTweenRotatorChange, UTweenRotator*);
DECLARE_DELEGATE_OneParam(FOnTweenLinearColorChange, UTweenLinearColor*);
DECLARE_DELEGATE_OneParam(FOnTweenFloatChange, UTweenFloat*);

/* Hit and overlap events for Vectors */

// Actors
DECLARE_DELEGATE_ThreeParams(FOnTweenActorBeginOverlapVector, UTweenVector*, AActor*, AActor*);
DECLARE_DELEGATE_FiveParams(FOnTweenActorHitVector, UTweenVector*, AActor*, AActor*, FVector, const FHitResult&);

// PrimitiveComponents
DECLARE_DELEGATE_FiveParams(FOnTweenPrimitiveComponentBeginOverlapVector, UTweenVector*, UPrimitiveComponent*, AActor*, UPrimitiveComponent*, const FHitResult&);
DECLARE_DELEGATE_SixParams(FOnTweenPrimitiveComponentHitVector, UTweenVector*, UPrimitiveComponent*, AActor*, UPrimitiveComponent*, FVector, const FHitResult&);

/* Hit and overlap events for Rotators */

// Actors
DECLARE_DELEGATE_ThreeParams(FOnTweenActorBeginOverlapRotator, UTweenRotator*, AActor*, AActor*);
DECLARE_DELEGATE_FiveParams(FOnTweenActorHitRotator, UTweenRotator*, AActor*, AActor*, FVector, const FHitResult&);

// PrimitiveComponents
DECLARE_DELEGATE_FiveParams(FOnTweenPrimitiveComponentBeginOverlapRotator, UTweenRotator*, UPrimitiveComponent*, AActor*, UPrimitiveComponent*, const FHitResult&);
DECLARE_DELEGATE_SixParams(FOnTweenPrimitiveComponentHitRotator, UTweenRotator*, UPrimitiveComponent*, AActor*, UPrimitiveComponent*, FVector, const FHitResult&);

/* Hit and overlap events for floats */

// Actors
DECLARE_DELEGATE_ThreeParams(FOnTweenActorBeginOverlapFloat, UTweenFloat*, AActor*, AActor*);
DECLARE_DELEGATE_FiveParams(FOnTweenActorHitFloat, UTweenFloat*, AActor*, AActor*, FVector, const FHitResult&);

// PrimitiveComponents
DECLARE_DELEGATE_FiveParams(FOnTweenPrimitiveComponentBeginOverlapFloat, UTweenFloat*, UPrimitiveComponent*, AActor*, UPrimitiveComponent*, const FHitResult&);
DECLARE_DELEGATE_SixParams(FOnTweenPrimitiveComponentHitFloat, UTweenFloat*, UPrimitiveComponent*, AActor*, UPrimitiveComponent*, FVector, const FHitResult&);

/* Callback for splines */

DECLARE_DELEGATE_TwoParams(FOnTweenSplinePointReached, UTweenFloat*, int32);

/**
 * The UTweenManagerComponent class is in charge of managing TweenContainers (that contain the actual Tweens).
 * It can be attached to an Actor or used globally in a level by placing a ATweenManagerActor.
 * Even if the TweenManager handles TweenContainers, each Tween that is created passes through the TweenManager first,
 * where its reference is saved in a Map for easy and fast access (mainly when deletion is involved)
 *
 * If the TweenManager is attached to an Actor, it provides methods to create empty TweenContainers and to delete Tweens.
 */
UCLASS(ClassGroup=(Tween), meta=(BlueprintSpawnableComponent))
class TWEENMAKER_API UTweenManagerComponent : public UActorComponent
{
    GENERATED_BODY()

    friend class UTweenFloatLatentFactory;
    friend class UTweenLinearColorLatentFactory;
    friend class UTweenVectorLatentFactory;
    friend class UTweenVector2DLatentFactory;
    friend class UTweenRotatorLatentFactory;

    friend class UTweenFloatStandardFactory;
    friend class UTweenLinearColorStandardFactory;
    friend class UTweenVectorStandardFactory;
    friend class UTweenVector2DStandardFactory;
    friend class UTweenRotatorStandardFactory;

public:

    /**
     * @brief Constructor.
     */
    UTweenManagerComponent();

protected:

    /**
     * @brief Overridden from UActorComponent. 
     */
    virtual void BeginPlay() override;

public:
    
    /**
     * @brief TickComponent handles the update of all TweenContainers owned by this TweenManager.
     */
    virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

    /*
     **************************************************************************
     * "Tween Utils" methods
     **************************************************************************
     */

    /**
     * Creates an empty TweenContainer, to which append/join Tweens. If the TweenContainer is left empty, it will be deleted in the next Tick.
     *
     * @param TweenContainer (output) The created TweenContainer.
     * @param NumLoops How many times the Tweens appended in the TweenContainer should loop.
     * @param LoopType The type of loop.
     * @param TimeScale The timescale to apply to each Tween.
     */
    UFUNCTION(BlueprintCallable, meta = (DisplayName="Create Tween Container", KeyWords="Create Tween Container"), Category = "Tween|Utils")
    void BP_CreateTweenContainer(UTweenContainer*& TweenContainer, int32 NumLoops = 1, ETweenLoopType LoopType = ETweenLoopType::Yoyo, float TimeScale = 1.0f);

    /**
     * Deletes ALL Tweens managed by this TweenManager. The deletion will occur instantly.
     *
     * @return The number of deleted tweens.
     */
    UFUNCTION(BlueprintCallable, meta = (DisplayName="Delete All Tweens", KeyWords="Delete Remove All Tweens"), Category = "Tween|Utils")
    int32 DeleteAllTweens();

    /**
     * Deletes all Tweens in this any TweenContainer owned by this Tweenmanager that have as target the given Object and that are of the given TweenType.
     *
     * @param TweenTarget The target Object.
     * @param TweensType The type of Tweens to consider for deletion.
     *
     * @return True if at least one Tween was found and deleted.
     */
    UFUNCTION(BlueprintCallable, meta = (DisplayName="Delete All Tweens By Object", KeyWords="Delete Remove All Tweens By Object"), Category = "Tween|Utils")
    bool DeleteAllTweensByObject(UObject* TweenTarget, ETweenGenericType TweensType);

    /**
     * Checks if an Object is currently tweening among ALL Tweens owned by this TweenManager. If it is, the corresponding Tween is returned.
     *
     * @param TweenTarget The target Object.
     * @param TweensType The type of Tweens to consider when searching.
     * @param TweenFound (output) If a Tween was found, this is it.
     *
     * @return True if a Tween was found; false otherwise.
     */
    UFUNCTION(BlueprintCallable, meta = (DisplayName="Is Object Tweening", KeyWords="Is Object Tweening"), Category = "Tween|Utils")
    bool IsObjectTweening(UObject* TweenTarget, ETweenGenericType TweensType, UBaseTween*& TweenFound) const;

    /**
     * Finds the Tween with the given name and type among ALL Tweens owned by this TweenManager. If the Tween exists, it's returned.
     * If there are more Tweens with the same one, the first one found will be returned.
     *
     * @param TweenName The name of the Tween.
     * @param TweenType The type of Tweens to consider when searching.
     * @param TweenFound (output) If a Tween was found, this is it.
     *
     * @return True if a Tween was found; false otherwise.
     */
    UFUNCTION(BlueprintCallable, meta = (DisplayName="Find Tween By Name", KeyWords="Find Tween By Name"), Category = "Tween|Utils")
    bool FindTweenByName(FName TweenName, ETweenGenericType TweenType, UBaseTween*& TweenFound) const;

    /*
     **************************************************************************
     * C++ methods (i.e. meant to be called when using this plugin in C++)
     **************************************************************************
     */

    /**
     * Creates an empty TweenContainer, to which append/join Tweens. If the TweenContainer is left empty, it will be deleted in the next Tick.
     *
     * @param pNumLoops How many times the Tweens appended in the TweenContainer should loop.
     * @param pLoopType The type of loop.
     * @param pTimeScale The timescale to apply to each Tween.
     *
     * @return The created TweenContainer.
     */
    UTweenContainer* CreateTweenContainer(int32 pNumLoops = 1, ETweenLoopType pLoopType = ETweenLoopType::Yoyo, float pTimeScale = 1.0f);

    /**
     * Creates an empty TweenContainer, to which append/join Tweens. If the TweenContainer is left empty, it will be deleted in the next Tick.
     * It uses the ATweenManagerActor present in the level. If none is present, a warning will be issued and the UTweenContainer won't be created.
     *
     * @param pNumLoops How many times the Tweens appended in the TweenContainer should loop.
     * @param pLoopType The type of loop.
     * @param pTimeScale The timescale to apply to each Tween.
     *
     * @return The created TweenContainer.
     */
    static UTweenContainer* CreateTweenContainerStatic(int32 pNumLoops = 1, ETweenLoopType pLoopType = ETweenLoopType::Yoyo, float pTimeScale = 1.0f);

protected:

    /*
     **************************************************************************
     * Methods used internally
     **************************************************************************
     */

    /**
     * This method is called whenever a Tween changes name using the appropriate method. It updates
     * the corresponding entry from the map.
     * 
     * Initially, Tweens are not added to the map, since they have no name. 
     * They're added only if a name is actually set.
     * 
     * @param pTween The Tween that changed name.
     * @param pPreviousName The previous name of the Tween ("None" if there wasn't one).
     * @param pNewName The new name of the Tween (assured NOT to be "None").
     */
    UFUNCTION()
    void UpdateNameMap(UBaseTween* pTween, const FName& pPreviousName, const FName& pNewName);

    /**
     * This method is called right before a Tween is deleted. This gives the chance to perform last clenaup 
     * operations. In particular, it removes the corresponding name from the name map, in case it was present.

     * @param pTween The Tween that changed name.
     */
    UFUNCTION()
    void TweenDestroyed(UBaseTween* pTween);

    /*
     **************************************************************************
     * Methods used internally but also from the "friend" classes.
     * Comments are left in the classes that use these functions.
     **************************************************************************
     */

    UTweenVector* AppendTweenVector(UTweenContainer* pTweenContainer,
                                    int32 pSequenceIndex,
                                    ETweenVectorType pTweenType,
                                    UObject* pTarget,
                                    ETweenTargetType pTargetType,
                                    const FVector& pFrom,
                                    const FVector& pTo,
                                    float pDuration,
                                    ETweenEaseType pEaseType,
                                    ETweenSpace pTweenSpace,
                                    bool pDeleteTweenOnHit,
                                    bool pDeleteTweenOnOverlap,
                                    int32 pNumLoops,
                                    ETweenLoopType pLoopType,
                                    float pDelay,
                                    float pTimeScale,
                                    bool pTweenWhileGameIsPaused,
                                    UTweenVectorLatentFactory* pLatentProxy = nullptr);

    UTweenVector* JoinTweenVector(UTweenContainer* pTweenContainer,
                                  int32 pSequenceIndex,
                                  ETweenVectorType pTweenType,
                                  UObject* pTarget,
                                  ETweenTargetType pTargetType,
                                  const FVector& pFrom,
                                  const FVector& pTo,
                                  float pDuration,
                                  ETweenEaseType pEaseType,
                                  ETweenSpace pTweenSpace,
                                  bool pDeleteTweenOnHit,
                                  bool pDeleteTweenOnOverlap,
                                  float pDelay,
                                  float pTimeScale,
                                  bool pTweenWhileGameIsPaused,
                                  UTweenVectorLatentFactory* pLatentProxy = nullptr);


    UTweenVector2D* AppendTweenVector2D(UTweenContainer* pTweenContainer,
                                        int32 pSequenceIndex,
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
                                        UTweenVector2DLatentFactory* pLatentProxy = nullptr);

    UTweenVector2D* JoinTweenVector2D(UTweenContainer* pTweenContainer,
                                      int32 pSequenceIndex,
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
                                      UTweenVector2DLatentFactory* pLatentProxy = nullptr);


    UTweenRotator* AppendTweenRotator(UTweenContainer* pTweenContainer,
                                      int32 pSequenceIndex,
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
                                      UTweenRotatorLatentFactory* pLatentProxy = nullptr);

    UTweenRotator* JoinTweenRotator(UTweenContainer* pTweenContainer,
                                    int32 pSequenceIndex,
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
                                    UTweenRotatorLatentFactory* pLatentProxy = nullptr);


    UTweenLinearColor* AppendTweenLinearColor(UTweenContainer* pTweenContainer,
                                              int32 pSequenceIndex,
                                              ETweenLinearColorType pTweenType,
                                              UObject* pTarget,
                                              FName pParameterName,
                                              ETweenTargetType pTargetType,
                                              const FLinearColor& pFrom,
                                              const FLinearColor& pTo,
                                              float pDuration,
                                              ETweenEaseType pEaseType,
                                              int32 pNumLoops,
                                              ETweenLoopType pLoopType,
                                              float pDelay,
                                              float pTimeScale,
                                              bool pTweenWhileGameIsPaused,
                                              UTweenLinearColorLatentFactory* pLatentProxy = nullptr);

    UTweenLinearColor* JoinTweenLinearColor(UTweenContainer* pTweenContainer,
                                            int32 pSequenceIndex,
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
                                            UTweenLinearColorLatentFactory* pLatentProxy = nullptr);


    UTweenFloat* AppendTweenFloat(UTweenContainer* pTweenContainer,
                                  int32 pSequenceIndex,
                                  ETweenFloatType pTweenType,
                                  UObject* pTarget,
                                  ETweenTargetType pTargetType,
                                  float pFrom,
                                  float pTo,
                                  float pDuration,
                                  ETweenEaseType pEaseType,
                                  int32 pNumLoops,
                                  ETweenLoopType pLoopType,
                                  float pDelay,
                                  float pTimeScale,
                                  bool pTweenWhileGameIsPaused,
                                  UTweenFloatLatentFactory* pLatentProxy = nullptr,
                                  FName pParameterName                   = FName("None"));

    UTweenFloat* JoinTweenFloat(UTweenContainer* pTweenContainer,
                                int32 pSequenceIndex,
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
                                UTweenFloatLatentFactory* pLatentProxy = nullptr,
                                FName pParameterName                   = FName("None"));


    UTweenFloat* AppendTweenRotateAroundFloat(UTweenContainer* pTweenContainer,
                                              int32 pSequenceIndex,
                                              ETweenFloatType pTweenType,
                                              UObject* pTarget,
                                              ETweenTargetType pTargetType,
                                              const FVector& pPoint,
                                              float pStartingAngle,
                                              float pEndingAngle,
                                              float pRadius,
                                              const FVector& pAxis,
                                              ETweenSpace pTweenSpace,
                                              float pPeriod,
                                              ETweenEaseType pEaseType,
                                              bool pDeleteTweenOnHit,
                                              bool pDeleteTweenOnOverlap,
                                              int32 pNumLoops,
                                              ETweenLoopType pLoopType,
                                              float pDelay,
                                              float pTimeScale,
                                              bool pTweenWhileGameIsPaused,
                                              UTweenFloatLatentFactory* pLatentProxy = nullptr);

    UTweenFloat* JoinTweenRotateAroundFloat(UTweenContainer* pTweenContainer,
                                            int32 pSequenceIndex,
                                            ETweenFloatType pTweenType,
                                            UObject* pTarget,
                                            ETweenTargetType pTargetType,
                                            const FVector& pPoint,
                                            float pStartingAngle,
                                            float pEndingAngle,
                                            float pRadius,
                                            const FVector& pAxis,
                                            ETweenSpace pTweenSpace,
                                            float pPeriod,
                                            ETweenEaseType pEaseType,
                                            bool pDeleteTweenOnHit,
                                            bool pDeleteTweenOnOverlap,
                                            float pDelay,
                                            float pTimeScale,
                                            bool pTweenWhileGameIsPaused,
                                            UTweenFloatLatentFactory* pLatentProxy = nullptr);


    UTweenFloat* AppendTweenFollowSplineFloat(UTweenContainer* pTweenContainer,
                                              int32 pSequenceIndex,
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
                                              UTweenFloatLatentFactory* pLatentProxy = nullptr);

    UTweenFloat* JoinTweenFollowSplineFloat(UTweenContainer* pTweenContainer,
                                            int32 pSequenceIndex,
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
                                            UTweenFloatLatentFactory* pLatentProxy = nullptr);

    /*
     **************************************************************************
     * Helper methods used internally
     **************************************************************************
     */

    /**
     * @brief Fully destroys a TweenContainer.
     */
    void DestroyTweenContainer(UTweenContainer* pTweenContainer, int32 pIndex);

    /**
    * @brief Helper method that takes a TweenTarget and the Tween type and makes an association
    *        between them and the corresponding Tween in the reference MultiMap.
    * 
    * @param pTweenTarget The target of the involved Tween.
    * @param pTweenType The type of the involved Tween.
    * @param pTween The involved Tween.
    */
    void SaveTweenReference(UObject* pTweenTarget, ETweenGenericType pTweenType, UBaseTween* pTween);

    /**
    * @brief Helper method that takes a TweenTarget and the Tween type and makes an association
    *        between them and the corresponding Tween in the reference MultiMap.
    * 
    * @param pTweenTarget The target of the involved Tween.
    * @param pTweenType The type of the involved Tween.
    * @param pTween The involved Tween.
    */
    template <typename TTweenType>
    void SaveTweenReference(UObject* pTweenTarget, TTweenType pTweenType, UBaseTween* pTween)
    {
        SaveTweenReference(pTweenTarget, Utility::ConvertTweenTypeEnum(pTweenType), pTween);
    }

    /// @brief List of currently active TweenContainers being updated simultaneously.
    UPROPERTY()
    TArray<UTweenContainer*> mTweenContainers;

    /**
     * @brief Reference MultiMap. Each Tween that is created is added to this MultiMap for easier access.
     * Keys: pairs composed by a TweenTarget and its generic type.
     * Values: the corresponding Tweens. Might be more than one, for example if there are several of
     *         instances of the same Tween (with different values) appended together.
     */
    TMultiMap<TPair<TWeakObjectPtr<UObject>, ETweenGenericType>, TWeakObjectPtr<UBaseTween>> mTweensByObjectMap;

    /**
     * @brief Reference MultiMap. Whenever a new name is set to a Tween, it is added to this map to keep track of each Tween with a tag,
     * for easier access. When the Tween is destroyed (for any reason), it is removed from the map.
     * Keys: pairs composed by a Tween name and its generic type.
     * Values: the corresponding Tweens. Might be more than one, if the names are not unique.
     */
    TMultiMap<TPair<FName, ETweenGenericType>, TWeakObjectPtr<UBaseTween>> mTweensByNameMap;
};
