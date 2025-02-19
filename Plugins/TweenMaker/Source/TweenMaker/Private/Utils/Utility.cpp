// Copyright 2018 Francesco Desogus. All Rights Reserved.

#include "Utils/Utility.h"
#include "Tweens/BaseTween.h"
#include "Tweens/TweenVector.h"
#include "Tweens/TweenVector2D.h"
#include "Tweens/TweenRotator.h"
#include "Tweens/TweenLinearColor.h"
#include "Tweens/TweenFloat.h"
#include "Engine/Engine.h"

// Custom log declaration
DEFINE_LOG_CATEGORY(LogTweenMaker);

namespace 
{
    void ComputeRotateAroundPointData(const FVector& objectLocation,
                                      const FVector& pPivotPoint,
                                      ETweenReferenceAxis pReferenceAxis,
                                      FVector& pOutAxis,
                                      float& pOutRadius)
    {
        FVector direction = (objectLocation - pPivotPoint);
        direction.Normalize();

        // Compute the axis around which to rotate
        pOutAxis = FVector::CrossProduct(direction, Utility::FromReferenceAxisToVector(pReferenceAxis));
        pOutAxis.Normalize();

        pOutRadius = (objectLocation - pPivotPoint).Size();
    }
}

// static public ---------------------------------------------------------------
void Utility::DestroyUObject(UObject *pObjectToDestroy)
{
    
    /*
     * This method of destroying a UObject was taken from Rama.
     * Link: https://answers.unrealengine.com/questions/3899/how-to-safely-delete-uobject-instantly.html?sort=oldest
     *
     * I added the call to MarkpendingKill(), which Epic says that it will set to null EVERY pointer pointing to the object,
     * including those created in Blueprints.
     * Link (it's the section below): https://docs.unrealengine.com/en-us/Programming/UnrealArchitecture/Objects
     */
    if (   GEngine
        && pObjectToDestroy
        && pObjectToDestroy->IsValidLowLevel())
    {
        pObjectToDestroy->ConditionalBeginDestroy();
        pObjectToDestroy->MarkAsGarbage();
        pObjectToDestroy = nullptr;
    }
}

// static public ---------------------------------------------------------------
ETweenGenericType Utility::ConvertTweenTypeEnum(ETweenVectorType pTweenType)
{
    ETweenGenericType type = ETweenGenericType::Any;

    switch (pTweenType)
    {
        case ETweenVectorType::MoveTo:
        case ETweenVectorType::MoveBy:
        {
            type = ETweenGenericType::Move;
            break;
        }
        case ETweenVectorType::ScaleTo:
        case ETweenVectorType::ScaleBy:
        {
            type = ETweenGenericType::Scale;
            break;
        }
        case ETweenVectorType::Custom:
        {
            type = ETweenGenericType::CustomVector;
            break;
        }
        default:
        {
            break;
        }
    }

    return type;
}

// static public ---------------------------------------------------------------
ETweenGenericType Utility::ConvertTweenTypeEnum(ETweenVector2DType pTweenType)
{
    ETweenGenericType type = ETweenGenericType::Any;

    switch (pTweenType)
    {
        case ETweenVector2DType::MoveTo:
        case ETweenVector2DType::MoveBy:
        {
            type = ETweenGenericType::Move;
            break;
        }
        case ETweenVector2DType::ScaleTo:
        case ETweenVector2DType::ScaleBy:
        {
            type = ETweenGenericType::Scale;
            break;
        }
        case ETweenVector2DType::ShearTo:
        {
            type = ETweenGenericType::WidgetShear;
            break;
        }
        case ETweenVector2DType::Custom:
        {
            type = ETweenGenericType::CustomVector2D;
            break;
        }
        default:
        {
            break;
        }
    }

    return type;
}

// static public ---------------------------------------------------------------
ETweenGenericType Utility::ConvertTweenTypeEnum(ETweenRotatorType pTweenType)
{
    ETweenGenericType type = ETweenGenericType::Any;

    switch (pTweenType)
    {
        case ETweenRotatorType::RotateTo:
        case ETweenRotatorType::RotateBy:
        {
            type = ETweenGenericType::Rotate;
            break;
        }
        default:
        {
            break;
        }
    }

    return type;
}

// static public ---------------------------------------------------------------
ETweenGenericType Utility::ConvertTweenTypeEnum(ETweenLinearColorType pTweenType)
{
    ETweenGenericType type = ETweenGenericType::Any;

    switch(pTweenType)
    {
        case ETweenLinearColorType::MaterialVectorFromTo:
        case ETweenLinearColorType::MaterialVectorTo:
        {
            type = ETweenGenericType::MaterialVector;
            break;
        }
        default:
        {
            break;
        }
    }

    return type;
}

// static public ---------------------------------------------------------------
ETweenGenericType Utility::ConvertTweenTypeEnum(ETweenFloatType pTweenType)
{
    ETweenGenericType type = ETweenGenericType::Any;

    switch (pTweenType)
    {
        case ETweenFloatType::MaterialScalarFromTo:
        case ETweenFloatType::MaterialScalarTo:
        {
            type = ETweenGenericType::MaterialScalar;
            break;
        }
        case ETweenFloatType::RotateAroundPoint:
        {
            type = ETweenGenericType::RotateAroundPoint;
            break;
        }
        case ETweenFloatType::FollowSpline:
        {
            type = ETweenGenericType::FollowSpline;
            break;
        }
        case ETweenFloatType::WidgetAngleTo:
        {
            type = ETweenGenericType::WidgetAngle;
            break;
        }
        case ETweenFloatType::WidgetOpacityTo:
        {
            type = ETweenGenericType::WidgetOpacity;
            break;
        }
        case ETweenFloatType::Custom:
        {
            type = ETweenGenericType::CustomFloat;
            break;
        }
        default:
        {
            break;
        }
    }

    return type;
}

// static public ---------------------------------------------------------------
ETweenGenericType Utility::FindOutTypeOfTween(UBaseTween* pTween)
{
    // Brute force attempt: try them all until we can find the correct one
    ETweenGenericType tweenType = ETweenGenericType::Any;

    if (UTweenVector* tweenVector = Cast<UTweenVector>(pTween))
    {
        tweenType = ConvertTweenTypeEnum(tweenVector->GetTweenType());
    }
    else if (UTweenVector2D* tweenVector2D = Cast<UTweenVector2D>(pTween))
    {
        tweenType = ConvertTweenTypeEnum(tweenVector2D->GetTweenType());
    }
    else if (UTweenRotator* tweenRotator = Cast<UTweenRotator>(pTween))
    {
        tweenType = ConvertTweenTypeEnum(tweenRotator->GetTweenType());
    }
    else if (UTweenLinearColor* tweenLinearColor = Cast<UTweenLinearColor>(pTween))
    {
        tweenType = ConvertTweenTypeEnum(tweenLinearColor->GetTweenType());
    }
    else if (UTweenFloat* tweenFloat = Cast<UTweenFloat>(pTween))
    {
        tweenType = ConvertTweenTypeEnum(tweenFloat->GetTweenType());
    }

    return tweenType;
}

// static public ---------------------------------------------------------------
FVector Utility::FromReferenceAxisToVector(ETweenReferenceAxis pReferenceAxis)
{
    FVector axis = FVector(0, 0, 0);

    switch (pReferenceAxis)
    {
        case ETweenReferenceAxis::XAxis:
        {
            axis = FVector(1, 0, 0);
            break;
        }
        case ETweenReferenceAxis::YAxis:
        {
            axis = FVector(0, 1, 0);
            break;
        }
        case ETweenReferenceAxis::ZAxis:
        {
            axis = FVector(0, 0, 1);
            break;
        }
    }

    return axis;
}

// static public ---------------------------------------------------------------
void Utility::ComputeDataForRotateAroundPoint(AActor* pActor,
                                              const FVector& pPivotPoint,
                                              ETweenReferenceAxis pReferenceAxis,
                                              ETweenSpace pTweenSpace,
                                              FVector& pOutAxis,
                                              float& pOutRadius)
{
    if (!pActor)
    {
        return;
    }

    FVector location;

    switch (pTweenSpace)
    {
        case ETweenSpace::World:
            location = pActor->GetRootComponent()->GetComponentLocation();
            break;
        case ETweenSpace::Relative:
            location = pActor->GetRootComponent()->GetRelativeLocation();
            break;
        default:
            break;
    }

    ComputeRotateAroundPointData(location, pPivotPoint, pReferenceAxis, pOutAxis, pOutRadius);
}

// static public ---------------------------------------------------------------
void Utility::ComputeDataForRotateAroundPoint(USceneComponent* pComponent,
                                              const FVector& pPivotPoint,
                                              ETweenReferenceAxis pReferenceAxis,
                                              ETweenSpace pTweenSpace,
                                              FVector& pOutAxis,
                                              float& pOutRadius)
{
    if (!pComponent)
    {
        return;
    }

    FVector location;

    switch (pTweenSpace)
    {
        case ETweenSpace::World:
            location = pComponent->GetComponentLocation();
        break;
        case ETweenSpace::Relative:
            location = pComponent->GetRelativeLocation();
        break;
        default:
            break;
    }
    
    ComputeRotateAroundPointData(location, pPivotPoint, pReferenceAxis, pOutAxis, pOutRadius);
}

// static public ---------------------------------------------------------------
float Utility::MapToRange(float pValue, float pOldMin, float pOldMax, float pNewMin, float pNewMax)
{
    float oldRange = (pOldMax - pOldMin);
    float newValue = 0;

    if (oldRange == 0)
    {
        newValue = pNewMin;
    }
    else
    {
        float newRange = pNewMax - pNewMin;
        newValue       = (((pValue - pOldMin) * newRange) / oldRange) + pNewMin;
    }

    return newValue;
}
