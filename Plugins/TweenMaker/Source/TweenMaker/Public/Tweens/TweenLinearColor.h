// Copyright 2018 Francesco Desogus. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Tweens/BaseTween.h"
#include "TweenManagerComponent.h"
#include "TweenLinearColor.generated.h"

class UTweenLinearColorLatentFactory;
class UMaterialInstanceDynamic;

/**
 * The UTweenLinearColor handles the update of all Tweens that use only FLinearColor.
 */
UCLASS(BlueprintType)
class TWEENMAKER_API UTweenLinearColor : public UBaseTween
{
    GENERATED_BODY()

public:

    /**
     * @brief Constructor.
     */
    UTweenLinearColor(const FObjectInitializer& ObjectInitializer);

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
    UFUNCTION(BlueprintPure, meta = (KeyWords="Tween Current Value Info"), Category = "Tween|Info|LinearColor")
    FLinearColor GetCurrentValue() const
    {
        return CurrentValue;
    }

    /*
     **************************************************************************
     * Methods used internally. Should not be called.
     **************************************************************************
     */

    /**
     * @brief Init method for a generic TweenLinearColor (internal usage only).
     *
     * @param pParameterName Material parameter name to Tween.
     * @param pFrom Initial value for the Tween.
     * @param pTo Ending value for the Tween.
     * @param pTweenType The Tween type.
     * @param pTweenLatentProxy Proxy for latent Tweens. It's only valid if it's a Latent tween, otherwise it's null.
     */
    void Init(const FName& pParameterName,
              const FLinearColor& pFrom,
              const FLinearColor& pTo,
              ETweenLinearColorType pTweenType,
              UTweenLinearColorLatentFactory* pTweenLatentProxy);

    /**
     * @brief Retrieves the Tween type.
     *
     * @return The Tween type.
     */
    ETweenLinearColorType GetTweenType() const
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
    FBP_OnTweenLinearColorChange OnTweenStart;

    /// @brief Delegate called at each Tween's update. Use only in Blueprints.
    UPROPERTY(BlueprintAssignable)
    FBP_OnTweenLinearColorChange OnTweenUpdate;

    /// @brief Delegate called when the Tween ends (if it loops then it's called at each loop end). Use only in Blueprints.
    UPROPERTY(BlueprintAssignable)
    FBP_OnTweenLinearColorChange OnTweenEnd;

    /*
     **************************************************************************
     * C++ delegates
     **************************************************************************
     */

    /// @brief Delegate called when the Tween starts (if it loops then it's called at each loop begin). Use only in C++.
    FOnTweenLinearColorChange OnTweenStartDelegate;

    /// @brief Delegate called at each Tween's update. Use only in C++.
    FOnTweenLinearColorChange OnTweenUpdateDelegate;

    /// @brief Delegate called when the Tween ends (if it loops then it's called at each loop end). Use only in C++.
    FOnTweenLinearColorChange OnTweenEndDelegate;

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

    void UpdateForMaterial(UMaterialInstanceDynamic *pTarget);

    
    /// @brief Type of this Tween.
    ETweenLinearColorType mTweenType;

    /// @brief Proxy for latent Tweens. It's only valid if it's a Latent tween, otherwise it's null.
    UPROPERTY()
    UTweenLinearColorLatentFactory* TweenLatentProxy;

    /// @brief Name of the material parameter to tween.
    FName mParameterName;

    /// @brief Current value of the Tween.
    FLinearColor CurrentValue;

    /// @brief Starting value.
    FLinearColor From;

    /// @brief Ending value.
    FLinearColor To;

    /// @brief Starting value, as a vector (helper variable).
    FVector FromVector;

    /// @brief Ending value, as a vector (helper variable).
    FVector ToVector;

    /// @brief Current value, as a vector (helper variable).
    FVector CurrentValueVector;
};
