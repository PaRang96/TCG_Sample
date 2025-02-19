// Copyright 2018 Francesco Desogus. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Tweens/BaseTween.h"
#include "TweenManagerComponent.h"
#include "TweenVector2D.generated.h"

class UTweenVector2DLatentFactory;
class UWidget;

/**
 * The UTweenVector2D handles the update of all Tweens that use only FVector2D.
 */
UCLASS(BlueprintType)
class TWEENMAKER_API UTweenVector2D : public UBaseTween
{
    GENERATED_BODY()

public:

    /**
     * @brief Constructor.
     */
    UTweenVector2D(const FObjectInitializer& ObjectInitializer);

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
    UFUNCTION(BlueprintPure, meta = (KeyWords="Tween Current Value Info"), Category = "Tween|Info|Vector2D")
    FVector2D GetCurrentValue() const
    {
        return mCurrentValue;
    }

    /*
     **************************************************************************
     * Methods used internally. Should not be called.
     **************************************************************************
     */

    /**
     * @brief Init method for a generic TweenVector2D (internal usage only).
     * 
     * @param pFrom Initial value for the Tween.
     * @param pTo Ending value for the Tween.
     * @param pTweenType The Tween type.
     * @param pTweenLatentProxy Proxy for latent Tweens. It's only valid if it's a Latent tween, otherwise it's null.
     */
    void Init(const FVector2D& pFrom, const FVector2D& pTo, ETweenVector2DType pTweenType, UTweenVector2DLatentFactory* pTweenLatentProxy);

    /**
     * @brief Retrieves the Tween type.
     *
     * @return The Tween type.
     */
    ETweenVector2DType GetTweenType() const
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
    FBP_OnTweenVector2DChange OnTweenStart;

    /// @brief Delegate called at each Tween's update. Use only in Blueprints.
    UPROPERTY(BlueprintAssignable)
    FBP_OnTweenVector2DChange OnTweenUpdate;

    /// @brief Delegate called when the Tween ends (if it loops then it's called at each loop end). Use only in Blueprints.
    UPROPERTY(BlueprintAssignable)
    FBP_OnTweenVector2DChange OnTweenEnd;

    /*
     **************************************************************************
     * C++ delegates
     **************************************************************************
     */


    /// @brief Delegate called when the Tween starts (if it loops then it's called at each loop begin). Use only in C++.
    FOnTweenVector2DChange OnTweenStartDelegate;

    /// @brief Delegate called at each Tween's update. Use only in C++.
    FOnTweenVector2DChange OnTweenUpdateDelegate;

    /// @brief Delegate called when the Tween ends (if it loops then it's called at each loop end). Use only in C++.
    FOnTweenVector2DChange OnTweenEndDelegate;

protected:
    
    // Begin of UBaseTween interface
    virtual bool Update(float pDeltaTime, float pTimeScale) override;
    virtual void Restart(bool pRestartFromEnd) override;
    virtual void Invert(bool pShouldInvertElapsedTime = true) override;
    virtual void PrepareTween() override;
    virtual void PositionAt(bool pBeginning) override;
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
     * @brief Updates the current value for a widget Tween.
     *
     * @param pTarget The target of the Tween.
     */
    void UpdateForWidget(UWidget *pTarget);
    
    
    /// @brief Type of this Tween.
    ETweenVector2DType mTweenType;

    /// @brief Proxy for latent Tweens. It's only valid if it's a Latent tween, otherwise it's null.
    UPROPERTY()
    UTweenVector2DLatentFactory* mTweenLatentProxy;

    /// @brief Current value of the Tween.
    FVector2D mCurrentValue;

    /// @brief Starting value.
    FVector2D mFrom;

    /// @brief Ending value.
    FVector2D mTo;

    /// @brief Offset used to for relative Tweens (i.e. MoveBy, ScaleBy).
    FVector2D mBaseOffset;
};
