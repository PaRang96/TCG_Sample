// Copyright 2018 Francesco Desogus. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Tweens/BaseTween.h"
#include "TweenManagerComponent.h"
#include "Engine/HitResult.h"
#include "TweenFloat.generated.h"

class UTweenFloatLatentFactory;
class UMaterialInstanceDynamic;
class USplineComponent;
class UWidget;

/**
 * The UTweenFloat handles the update of all Tweens that use only floats.
 */
UCLASS(BlueprintType)
class TWEENMAKER_API UTweenFloat : public UBaseTween
{
    GENERATED_BODY()

public:

    /**
     * @brief Constructor.
     */
    UTweenFloat(const FObjectInitializer& ObjectInitializer);

    /*
     **************************************************************************
     * "Tween Info" methods
     **************************************************************************
     */

    /**
      * Returns the current value of the Tween.
      *
      * @return The current value.
      */
    UFUNCTION(BlueprintPure, meta = (KeyWords="Tween Current Value Info"), Category = "Tween|Info|Float")
    float GetCurrentValue() const
    {
        return mCurrentValue;
    }

    /*
     **************************************************************************
     * Methods used internally. Should not be called.
     **************************************************************************
     */

    /**
     * @brief Init method for a generic TweenFloat (internal usage only); it covers most of the "float" Tweens.
     * 
     * @param pFrom Initial value for the Tween.
     * @param pTo Ending value for the Tween.
     * @param pTweenType The Tween type.
     * @param pParameterName Parameter to Tween (only meaningful if the Tween involves a material).
     * @param pTweenLatentProxy Proxy for latent Tweens. It's only valid if it's a Latent tween, otherwise it's null.
     */
    void Init(float pFrom, float pTo, ETweenFloatType pTweenType, const FName& pParameterName, UTweenFloatLatentFactory* pTweenLatentProxy);

    /**
     * @brief Init method for a "RotateAround" type of TweenFloat (internal usage only).
     * 
     * @param pPoint Point around which to rotate.
     * @param pStartingAngle Starting angle.
     * @param pEndingAngle Ending angle.
     * @param pRadius Radius of the rotation.
     * @param pAxis Axis around which to rotate.
     * @param pTweenSpace The space to use for the computation (world or relative)
     * @param pTweenType Tween type.
     * @param pDeleteTweenOnHit If true, the Tween is deleted when an object hits something.
     * @param pDeleteTweenOnOverlap If true, the Tween is deleted when an object overlaps something.
     * @param pTweenLatentProxy Proxy for latent Tweens. It's only valid if it's a Latent tween, otherwise it's null.
     */
    void InitRotateAround(const FVector& pPoint,
                          float pStartingAngle,
                          float pEndingAngle,
                          float pRadius,
                          const FVector& pAxis,
                          ETweenSpace pTweenSpace,
                          ETweenFloatType pTweenType,
                          bool pDeleteTweenOnHit,
                          bool pDeleteTweenOnOverlap,
                          UTweenFloatLatentFactory* pTweenLatentProxy);

    /**
     * @brief Init method for a "FollowSpline" type of TweenFloat (internal usage only).
     * 
     * @param pSpline Spline to be used.
     * @param pApplyRotation If true, it applies the rotation while Tweening.
     * @param pApplyScale If true, it applies the scale while Tweening.
     * @param pTweenType Tween type.
     * @param pDeleteTweenOnHit If true, the Tween is deleted when an object hits something.
     * @param pDeleteTweenOnOverlap If true, the Tween is deleted when an object overlaps something.
     * @param pUseConstantSpeed If true, a constant speed will be used throughout the Tween.
     * @param pTweenLatentProxy Proxy for latent Tweens. It's only valid if it's a Latent tween, otherwise it's null.
     */
    void InitFollowSpline(USplineComponent* pSpline,
                          bool pApplyRotation,
                          bool pApplyScale,
                          ETweenFloatType pTweenType,
                          bool pDeleteTweenOnHit,
                          bool pDeleteTweenOnOverlap,
                          bool pUseConstantSpeed,
                          UTweenFloatLatentFactory* pTweenLatentProxy);


    /**
     * @brief Retrieves the Tween type.
     *
     * @return The Tween type.
     */
    ETweenFloatType GetTweenType() const
    {
        return mTweenType;
    }

    /*
     **************************************************************************
     * Blueprint delegates
     **************************************************************************
     */

    /// @brief Delegate called when the Tween starts (if it loops then it's called at each loop begin). Use only in Blueprints.
    UPROPERTY(BlueprintAssignable)
    FBP_OnTweenFloatChange OnTweenStart;

    /// @brief Delegate called at each Tween's update. Use only in Blueprints.
    UPROPERTY(BlueprintAssignable)
    FBP_OnTweenFloatChange OnTweenUpdate;

    /// @brief Delegate called when the Tween ends (if it loops then it's called at each loop end). Use only in Blueprints.
    UPROPERTY(BlueprintAssignable)
    FBP_OnTweenFloatChange OnTweenEnd;

    /**
     * @brief Delegate called when the Actor tween target is hit by something during the Tween's execution. Only valid if the TweenTarget
     * actually inherits from AActor and if the Tween type is either "FollowSpline" or "RotateAround".
     * Use only in Blueprints.
     */
    UPROPERTY(BlueprintAssignable)
    FBP_OnTweenActorHitFloat OnTweenActorHit;

    /**
     * @brief Delegate called when the Actor tween target overlaps something during the Tween's execution. Only valid if the TweenTarget
     * actually inherits from AActor and if the Tween type is either "FollowSpline" or "RotateAround".
     * Use only in Blueprints.
     */
    UPROPERTY(BlueprintAssignable)
    FBP_OnTweenActorBeginOverlapFloat OnTweenActorBeginOverlap;

    /**
     * @brief Delegate called when the PrimitiveComponent tween target is hit by something during the Tween's execution. Only valid if the TweenTarget
     * actually inherits from UPrimitiveComponent and if the Tween type is either "FollowSpline" or "RotateAround".
     * Use only in Blueprints.
     */
    UPROPERTY(BlueprintAssignable)
    FBP_OnTweenPrimitiveComponentHitFloat OnTweenPrimitiveComponentHit;

    /**
     * @brief Delegate called when the PrimitiveComponent tween target overlaps something during the Tween's execution. Only valid if the TweenTarget
     * actually inherits from UPrimitiveComponent and if the Tween type is either "FollowSpline" or "RotateAround".
     * Use only in Blueprints.
     */
    UPROPERTY(BlueprintAssignable)
    FBP_OnTweenPrimitiveComponentBeginOverlapFloat OnTweenPrimitiveComponentBeginOverlap;

    /**
     * @brief Delegate called whenever a "FollowSpline" Tween reaches a point of the spline itself.
     * Use only in Blueprints.
     */
    UPROPERTY(BlueprintAssignable)
    FBP_OnTweenSplinePointReached OnTweenSplinePointReached;

    /*
     **************************************************************************
     * C++ delegates
     **************************************************************************
     */

    /// @brief Delegate called when the Tween starts (if it loops then it's called at each loop begin). Use only in C++.
    FOnTweenFloatChange OnTweenStartDelegate;

    /// @brief Delegate called at each Tween's update. Use only in C++.
    FOnTweenFloatChange OnTweenUpdateDelegate;

    /// @brief Delegate called when the Tween ends (if it loops then it's called at each loop end). Use only in C++.
    FOnTweenFloatChange OnTweenEndDelegate;



    /**
     * @brief Delegate called when the Actor tween target is hit by something during the Tween's execution. Only valid if the TweenTarget
     * actually inherits from AActor and if the Tween type is either "FollowSpline" or "RotateAround".
     * Use only in C++.
     */
    FOnTweenActorHitFloat OnTweenActorHitDelegate;

    /**
     * @brief Delegate called when the Actor tween target overlaps something during the Tween's execution. Only valid if the TweenTarget
     * actually inherits from AActor and if the Tween type is either "FollowSpline" or "RotateAround".
     * Use only in C++.
     */
    FOnTweenActorBeginOverlapFloat OnTweenActorBeginOverlapDelegate;

    /**
     * @brief Delegate called when the PrimitiveComponent tween target is hit by something during the Tween's execution. Only valid if the TweenTarget
     * actually inherits from UPrimitiveComponent and if the Tween type is either "FollowSpline" or "RotateAround".
     * Use only in C++.
     */
    FOnTweenPrimitiveComponentHitFloat OnTweenPrimitiveComponentHitDelegate;

    /**
     * @brief Delegate called when the PrimitiveComponent tween target overlaps something during the Tween's execution. Only valid if the TweenTarget
     * actually inherits from UPrimitiveComponent and if the Tween type is either "FollowSpline" or "RotateAround".
     * Use only in C++.
     */
    FOnTweenPrimitiveComponentBeginOverlapFloat OnTweenPrimitiveComponentBeginOverlapDelegate;

    /**
     * @brief Delegate called whenever a "FollowSpline" Tween reaches a point of the spline itself.
     * Use only in C++.
     */
    FOnTweenSplinePointReached OnTweenSplinePointReachedDelegate;

protected:
    
    // Begin of UBaseTween interface
    virtual bool Update(float pDeltaTime, float pTimeScale) override;
    virtual void Restart(bool pRestartFromEnd) override;
    virtual void Invert(bool pShouldInvertElapsedTime = true) override;
    virtual void PrepareTween() override;
    virtual void PositionAt(bool pBeginning) override;
    virtual void PreDelay() override;
    virtual void BroadcastOnTweenStart() override;
    virtual void BroadcastOnTweenUpdate() override;
    virtual void BroadcastOnTweenEnd() override;
    virtual void OnTweenPausedInternal() override;
    virtual void OnTweenResumedInternal() override;
    virtual void OnTweenDeletedInternal() override;
    // End of UBaseTween interface

    /*
     **************************************************************************
     * Helper methods for updating individual classes
     **************************************************************************
     */

    /**
     * @brief Updates the current value for a material Tween.
     *
     * @param pTarget The target of the Tween.
     */
    void UpdateForMaterial(UMaterialInstanceDynamic *pTarget);

    /**
     * @brief Updates the current value for an Actor Tween.
     *
     * @param pTarget The target of the Tween.
     */
    void UpdateForActor(AActor *pTarget);

    /**
     * @brief Updates the current value for a scene component Tween.
     *
     * @param pTarget The target of the Tween.
     */
    void UpdateForSceneComponent(USceneComponent *pTarget);

    /**
     * @brief Updates the current value for a widget Tween.
     *
     * @param pTarget The target of the Tween.
     */
    void UpdateForWidget(UWidget *pTarget);

    
    /**
     * @brief Checks whether a spline point has been reached. Only meaningful for the
     *        "FollowSpline" Tween and if the corresponding delegate is bound.
     *        
     * @param WorldPosition Position to check.
     */
    void CheckSplinePointReached(const FVector& WorldPosition);

    /*
     **************************************************************************
     * Helper methods for binding/unbinding hit and overlap delegates
     **************************************************************************
     */

    /**
     * @brief Helper method that bind the appropriate delegates.
     */
    void BindDelegates();

    /**
     * @brief Helper method that unbind all bounded delegates.
     */
    void UnbindDelegates();

    /**
     * @brief Function called when the tween target overlap something (only used if the
     *        appropriate delegate is bound and the tween target is an actor).
     */
    UFUNCTION()
    void OnActorBeginOverlap(AActor* pThisActor, AActor* pOtherActor);

    /**
     * @brief Function called when the tween target hits something (only used if the
     *        appropriate delegate is bound and the tween target is an actor).
     */
    UFUNCTION()
    void OnActorHit(AActor* pThisActor, AActor* pOtherActor, FVector pNormalImpulse, const FHitResult& pHit);

    /**
     * @brief Function called when the tween target overlap something (only used if the
     *        appropriate delegate is bound and the tween target is a primitive component).
     */
    UFUNCTION()
    void OnPrimitiveComponentBeginOverlap(UPrimitiveComponent* pThisComponent,
                                          AActor* pOtherActor,
                                          UPrimitiveComponent* pOtherComp,
                                          int32 pOtherBodyIndex,
                                          bool bFromSweep,
                                          const FHitResult& pSweepResult);

    /**
     * @brief Function called when the tween target hits something (only used if the
     *        appropriate delegate is bound and the tween target is a primitive component).
     */
    UFUNCTION()
    void OnPrimitiveComponentHit(UPrimitiveComponent* pThisComponent,
                                 AActor* pOtherActor,
                                 UPrimitiveComponent* pOtherComp,
                                 FVector pNormalImpulse,
                                 const FHitResult& pHitResult);

    

    /// @brief Type of this Tween.
    ETweenFloatType mTweenType;

    /// @brief Proxy for latent Tweens. It's only valid if it's a Latent tween, otherwise it's null.
    UPROPERTY()
    UTweenFloatLatentFactory* TweenLatentProxy;

    /// @brief Current value of the Tween.
    float mCurrentValue;

    /// @brief Starting value.
    float mFrom;

    /// @brief Ending value.
    float mTo;

    /// @brief Previous value.
    float mPreviousValue;

    /// @brief If true, the Tween will be deleted if the tween target hits something. Only valid of specific objects and specific tween types.
    bool bDeleteTweenOnHit;

    /// @brief If true, the Tween will be deleted if the tween target overlaps something. Only valid of specific objects and specific tween types.
    bool bDeleteTweenOnOverlap;

    /// @brief True if the Tween has bounded functions to hit/overlap events (either because the bDeleteTweenOnXYZ was selected or a method was bounded).
    bool bHasBoundedFunctions;

    /// @brief Name of the material parameter. It's only valid if the Tween's type deals with materials.
    FName mParameterName;

    /// @brief Offset vector, used for the "RotateAround" type of Tween.
    FVector mOffsetVector;
    
    /// @brief Pivot point, used for the "RotateAround" type of Tween.
    FVector mPivotPoint;

    /// @brief Rotation radius, used for the "RotateAround" type of Tween.
    float mRadius;

    /// @brief Axis around which to rotate, used for the "RotateAround" type of Tween.
    FVector mAxis;
    
    /// @brief Space where to apply the computations (either world or relative), used for the "RotateAround" type of Tween.
    ETweenSpace mTweenSpace;

    /// @brief Keeps track of the next point of the spline (meaningful only when the relativee delegate is bound), used for the "FollowSpline" type of Tween.
    int mNextPointIndex; 

    /// @brief Spline component, used for the "FollowSpline" type of Tween.
    UPROPERTY()
    USplineComponent* mSpline;

    /// @brief Whether to apply the rotation, used for the "FollowSpline" type of Tween.
    bool bSplineApplyRotation;

    /// @brief Whether to apply the scale, used for the "FollowSpline" type of Tween.
    bool bSplineApplyScale;

    /// @brief Whether to use a constant speed for the animation, used for the "FollowSpline" type of Tween.
    bool bUseConstantSpeed;
};
