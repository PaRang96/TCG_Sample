// Copyright 2018 Francesco Desogus. All Rights Reserved.

#include "Tweens/TweenLinearColor.h"

#include "TweenFactory/Latent/TweenLinearColorLatentFactory.h"
#include "Utils/EaseEquations.h"
#include "Materials/MaterialInstanceDynamic.h"

// public ----------------------------------------------------------------------
UTweenLinearColor::UTweenLinearColor(const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer)
    , TweenLatentProxy(nullptr)
    , mParameterName(FName(""))
    , CurrentValue(FLinearColor())
    , From(FLinearColor())
    , To(FLinearColor())
{

}

// public ----------------------------------------------------------------------
void UTweenLinearColor::Init(const FName& pParameterName,
                             const FLinearColor& pFrom,
                             const FLinearColor& pTo,
                             ETweenLinearColorType pTweenType,
                             UTweenLinearColorLatentFactory* pTweenLatentProxy)
{
    mParameterName   = pParameterName;
    From             = pFrom;
    To               = pTo;
    mTweenType       = pTweenType;
    TweenLatentProxy = pTweenLatentProxy;

    CurrentValue = FLinearColor();


    FromVector         = FVector(From.R, From.G, From.B);
    ToVector           = FVector(To.R, To.G, To.B);
    CurrentValueVector = FVector(0, 0, 0);
}

// public ----------------------------------------------------------------------
bool UTweenLinearColor::Update(float pDeltaTime, float pTimeScale)
{
    Super::Update(pDeltaTime, pTimeScale);

    mElapsedTime += pDeltaTime * pTimeScale * mTimeScaleAbsolute;

    bool hasEnded = mElapsedTime >= mTweenDuration;

    if (hasEnded)
    {
        CurrentValue = To;
    }
    else
    {
        // Computing the values for the RGB part and the alpha separately
        float alpha = 0.0f;

        if (mCurveFloat)
        {
            EaseEquations::ComputeCustomVectorEasing(mCurveFloat, mElapsedTime, FromVector, ToVector, mTweenDuration, CurrentValueVector);
            alpha = EaseEquations::ComputeCustomFloatEasing(mCurveFloat, mElapsedTime, From.A, To.A, mTweenDuration);
        }
        else
        {
            EaseEquations::ComputeVectorEasing(mEaseType, mElapsedTime, FromVector, ToVector, mTweenDuration, CurrentValueVector);
            alpha = EaseEquations::ComputeFloatEasing(mEaseType, mElapsedTime, From.A, To.A, mTweenDuration);
        }

        CurrentValue = FLinearColor(CurrentValueVector.X, CurrentValueVector.Y, CurrentValueVector.Z, alpha);
    }

    switch (mTargetType)
    {
        case ETweenTargetType::Material:
        {
            UMaterialInstanceDynamic* material = Cast<UMaterialInstanceDynamic>(mTargetObject);
            UpdateForMaterial(material);
            break;
        }
        default:
        {
            break;
        }
    }

    return hasEnded;
}

// protected -------------------------------------------------------------------
void UTweenLinearColor::PrepareTween()
{
    Super::PrepareTween();

    switch (mTweenType)
    {
        case ETweenLinearColorType::MaterialVectorTo:
        {
            switch (mTargetType)
            {
                case ETweenTargetType::Material:
                {
                    UMaterialInstanceDynamic* material = Cast<UMaterialInstanceDynamic>(mTargetObject);
                    material->GetVectorParameterValue(FMaterialParameterInfo(mParameterName), From);

                    FromVector = FVector(From.R, From.G, From.B);
                    ToVector   = FVector(To.R, To.G, To.B);
                    break;
                }
                default:
                {
                    break;
                }
            }

            break;
        }
        default:
        {
            break;
        }
    }
}

// protected -------------------------------------------------------------------
void UTweenLinearColor::PositionAt(bool pBeginning)
{
    // Don't bother doing anything if the Tween has not even ever started
    if (bHasPreparedTween)
    {
        // Start again at the from!
        CurrentValue = pBeginning ? From : To;

        switch (mTargetType)
        {
            case ETweenTargetType::Material:
            {
                UMaterialInstanceDynamic* material = Cast<UMaterialInstanceDynamic>(mTargetObject);
                UpdateForMaterial(material);
                break;
            }
            default:
            {
                break;
            }
        }
    }
}

// protected -------------------------------------------------------------------
void UTweenLinearColor::OnTweenPausedInternal()
{
    Super::OnTweenPausedInternal();
}

// protected -------------------------------------------------------------------
void UTweenLinearColor::OnTweenResumedInternal()
{
    Super::OnTweenResumedInternal();
}

// protected -------------------------------------------------------------------
void UTweenLinearColor::OnTweenDeletedInternal()
{
    Super::OnTweenDeletedInternal();
}

// protected -------------------------------------------------------------------
void UTweenLinearColor::Restart(bool pRestartFromEnd)
{
    Super::Restart(pRestartFromEnd);

    if (pRestartFromEnd)
    {
        Swap(From, To);
        Swap(FromVector, ToVector);
    }

    mElapsedTime = 0.0f;
}

// protected -------------------------------------------------------------------
void UTweenLinearColor::Invert(bool pShouldInvertElapsedTime)
{
    Super::Invert(pShouldInvertElapsedTime);

    Swap(From, To);
    Swap(FromVector, ToVector);
}

// protected -------------------------------------------------------------------
void UTweenLinearColor::BroadcastOnTweenStart()
{
    Super::BroadcastOnTweenStart();

    if (TweenLatentProxy != nullptr)
    {
        TweenLatentProxy->OnTweenStart.Broadcast(this);
    }
    else
    {
        if (OnTweenStart.IsBound())
        {
            OnTweenStart.Broadcast(this);
        }

        OnTweenStartDelegate.ExecuteIfBound(this);
    }
}

// protected -------------------------------------------------------------------
void UTweenLinearColor::BroadcastOnTweenUpdate()
{
    Super::BroadcastOnTweenUpdate();

    if (TweenLatentProxy != nullptr)
    {
        TweenLatentProxy->OnTweenUpdate.Broadcast(this);
    }
    else
    {
        if (OnTweenUpdate.IsBound())
        {
            OnTweenUpdate.Broadcast(this);
        }

        OnTweenUpdateDelegate.ExecuteIfBound(this);
    }
}

// protected -------------------------------------------------------------------
void UTweenLinearColor::BroadcastOnTweenEnd()
{
    Super::BroadcastOnTweenEnd();

    if (TweenLatentProxy != nullptr)
    {
        TweenLatentProxy->OnTweenEnd.Broadcast(this);
    }
    else
    {
        if (OnTweenEnd.IsBound())
        {
            OnTweenEnd.Broadcast(this);
        }

        OnTweenEndDelegate.ExecuteIfBound(this);
    }
}

// private ---------------------------------------------------------------------
void UTweenLinearColor::UpdateForMaterial(UMaterialInstanceDynamic* pTarget)
{
    switch (mTweenType)
    {
        case ETweenLinearColorType::MaterialVectorTo:
        case ETweenLinearColorType::MaterialVectorFromTo:
        {
            pTarget->SetVectorParameterValue(mParameterName, CurrentValue);
            break;
        }
        default:
        {
            break;
        }
    }
}
