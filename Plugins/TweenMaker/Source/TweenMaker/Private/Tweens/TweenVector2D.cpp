// Copyright 2018 Francesco Desogus. All Rights Reserved.

#include "Tweens/TweenVector2D.h"
#include "TweenFactory/Latent/TweenVector2DLatentFactory.h"
#include "GameFramework/Actor.h"
#include "Utils/Utility.h"
#include "Components/Widget.h"
#include "Utils/EaseEquations.h"

// public ----------------------------------------------------------------------
UTweenVector2D::UTweenVector2D(const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer)
    , mTweenLatentProxy(nullptr)
    , mCurrentValue(FVector2D(0, 0))
    , mFrom(FVector2D(0, 0))
    , mTo(FVector2D(0, 0))
{

}

// public ----------------------------------------------------------------------
void UTweenVector2D::Init(const FVector2D& pFrom,
                          const FVector2D& pTo,
                          ETweenVector2DType pTweenType,
                          UTweenVector2DLatentFactory* pTweenLatentProxy)
{
    mFrom             = pFrom;
    mTo               = pTo;
    mTweenType        = pTweenType;
    mTweenLatentProxy = pTweenLatentProxy;

    mCurrentValue = FVector2D(0, 0);
    mBaseOffset   = FVector2D(0, 0);
}

// public ----------------------------------------------------------------------
bool UTweenVector2D::Update(float pDeltaTime, float pTimeScale)
{
    Super::Update(pDeltaTime, pTimeScale);

    mElapsedTime += pDeltaTime * pTimeScale * mTimeScaleAbsolute;

    bool hasEnded = mElapsedTime >= mTweenDuration;

    if (hasEnded)
    {
        mCurrentValue = mTo;
    }
    else
    {
        if (mCurveFloat)
        {
            EaseEquations::ComputeCustomVector2DEasing(mCurveFloat, mElapsedTime, mFrom, mTo, mTweenDuration, mCurrentValue);
        }
        else
        {
            EaseEquations::ComputeVector2DEasing(mEaseType, mElapsedTime, mFrom, mTo, mTweenDuration, mCurrentValue);
        }
    }

    switch (mTargetType)
    {
        case ETweenTargetType::UMG:
        {
            UWidget* widget = Cast<UWidget>(mTargetObject);
            UpdateForWidget(widget);
            break;
        }
        case ETweenTargetType::Custom:
        {
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
void UTweenVector2D::PrepareTween()
{
    Super::PrepareTween();

    switch (mTweenType)
    {
        case ETweenVector2DType::MoveTo:
        {
            switch (mTargetType)
            {
                case ETweenTargetType::UMG:
                {
                    UWidget* widget = Cast<UWidget>(mTargetObject);
                    mFrom = widget->GetRenderTransform().Translation;
                    break;
                }
                default:
                {
                    break;
                }
            }

            break;
        }
        case ETweenVector2DType::MoveBy:
        {
            switch (mTargetType)
            {
                case ETweenTargetType::UMG:
                {
                    UWidget* widget = Cast<UWidget>(mTargetObject);
                    mFrom = FVector2D(0, 0);
                    mBaseOffset = widget->GetRenderTransform().Translation;;
                    break;
                }
                default:
                {
                    break;
                }
            }

            break;
        }
        case ETweenVector2DType::ScaleTo:
        {
            switch (mTargetType)
            {
                case ETweenTargetType::UMG:
                {
                    UWidget* widget = Cast<UWidget>(mTargetObject);
                    mFrom = widget->GetRenderTransform().Scale;
                    break;
                }
                default:
                {
                    break;
                }
            }

            break;
        }
        case ETweenVector2DType::ScaleBy:
        {
            switch (mTargetType)
            {
                case ETweenTargetType::UMG:
                {
                    UWidget* widget = Cast<UWidget>(mTargetObject);
                    mFrom = FVector2D(0, 0);
                    mBaseOffset = widget->GetRenderTransform().Scale;
                    break;
                }
                default:
                {
                    break;
                }
            }

            break;
        }
        case ETweenVector2DType::ShearTo:
        {
            switch (mTargetType)
            {
                case ETweenTargetType::UMG:
                {
                    UWidget* widget = Cast<UWidget>(mTargetObject);
                    mFrom = widget->GetRenderTransform().Shear;
                    break;
                }
                default:
                {
                    break;
                }
            }

            break;
        }
        case ETweenVector2DType::Custom:
        {
            // Does nothing
            break;
        }
        default:
        {
            break;
        }
    }

}

// protected -------------------------------------------------------------------
void UTweenVector2D::PositionAt(bool pBeginning)
{
    // Don't bother doing anything if the Tween has not even ever started
    if (bHasPreparedTween)
    {
        // Start again at the from!
        mCurrentValue = pBeginning ? mFrom : mTo;

        switch (mTargetType)
        {
            case ETweenTargetType::UMG:
            {
                UWidget* widget = Cast<UWidget>(mTargetObject);
                UpdateForWidget(widget);
                break;
            }
            case ETweenTargetType::Custom:
            {
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
void UTweenVector2D::OnTweenPausedInternal()
{
    Super::OnTweenPausedInternal();
}

// protected -------------------------------------------------------------------
void UTweenVector2D::OnTweenResumedInternal()
{
    Super::OnTweenResumedInternal();
}

// protected -------------------------------------------------------------------
void UTweenVector2D::OnTweenDeletedInternal()
{
    Super::OnTweenDeletedInternal();
}

// protected -------------------------------------------------------------------
void UTweenVector2D::Restart(bool pRestartFromEnd)
{
    Super::Restart(pRestartFromEnd);

    if (pRestartFromEnd)
    {
        Swap(mFrom, mTo);
    }

    mElapsedTime = 0.0f;
}

// protected -------------------------------------------------------------------
void UTweenVector2D::Invert(bool pShouldInvertElapsedTime)
{
    Super::Invert(pShouldInvertElapsedTime);

    Swap(mFrom, mTo);
}

// protected -------------------------------------------------------------------
void UTweenVector2D::BroadcastOnTweenStart()
{
    Super::BroadcastOnTweenStart();

    if (mTweenLatentProxy != nullptr)
    {
        mTweenLatentProxy->OnTweenStart.Broadcast(this);
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
void UTweenVector2D::BroadcastOnTweenUpdate()
{
    Super::BroadcastOnTweenUpdate();

    if (mTweenLatentProxy != nullptr)
    {
        mTweenLatentProxy->OnTweenUpdate.Broadcast(this);
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
void UTweenVector2D::BroadcastOnTweenEnd()
{
    Super::BroadcastOnTweenEnd();

    if (mTweenLatentProxy != nullptr)
    {
        mTweenLatentProxy->OnTweenEnd.Broadcast(this);
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
void UTweenVector2D::UpdateForWidget(UWidget* pTarget)
{
    switch (mTweenType)
    {
        case ETweenVector2DType::MoveTo:
        {
            pTarget->SetRenderTranslation(mCurrentValue);
            break;
        }
        case ETweenVector2DType::MoveBy:
        {
            pTarget->SetRenderTranslation(mCurrentValue + mBaseOffset);
            break;
        }
        case ETweenVector2DType::ScaleTo:
        {
            pTarget->SetRenderScale(mCurrentValue);
            break;
        }
        case ETweenVector2DType::ScaleBy:
        {
            pTarget->SetRenderScale(mCurrentValue + mBaseOffset);
            break;
        }
        case ETweenVector2DType::ShearTo:
        {
            pTarget->SetRenderShear(mCurrentValue);
            break;
        }
        case ETweenVector2DType::Custom:
        {
            // Does nothing
            break;
        }
        default:
        {
            break;
        }
    }
}