// Copyright 2018 Francesco Desogus. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Utils/TweenEnums.h"

class UBaseTween;

// Custom log declaration
TWEENMAKER_API DECLARE_LOG_CATEGORY_EXTERN(LogTweenMaker, Log, All);

/**
 * @brief The Utility class implements some utility static methods used in some parts of the plugin
 */
class TWEENMAKER_API Utility
{
public:

    /**
     * @brief DestroyUObject completely destroys a UObject
     *
     * @param pObjectToDestroy The object to destroy
     */
    static void DestroyUObject(UObject *pObjectToDestroy);

    /**
     * @brief Helper methodsthat converts a given tween type to a more
     *        general tween category (i.e. a "vector scale" tween to a generic "scale" tween).
     *
     * @param pTweenType The starting tween type.
     */
    static ETweenGenericType ConvertTweenTypeEnum(ETweenVectorType pTweenType);

    /**
     * @brief Helper methodsthat converts a given tween type to a more
     *        general tween category (i.e. a "vector scale" tween to a generic "scale" tween).
     *
     * @param pTweenType The starting tween type.
     */
    static ETweenGenericType ConvertTweenTypeEnum(ETweenVector2DType pTweenType);

    /**
     * @brief Helper methodsthat converts a given tween type to a more
     *        general tween category (i.e. a "vector scale" tween to a generic "scale" tween).
     *
     * @param pTweenType The starting tween type.
     */
    static ETweenGenericType ConvertTweenTypeEnum(ETweenRotatorType pTweenType);

    /**
     * @brief Helper methodsthat converts a given tween type to a more
     *        general tween category (i.e. a "vector scale" tween to a generic "scale" tween).
     *
     * @param pTweenType The starting tween type.
     */
    static ETweenGenericType ConvertTweenTypeEnum(ETweenLinearColorType pTweenType);
    
    /**
     * @brief Helper methodsthat converts a given tween type to a more
     *        general tween category (i.e. a "vector scale" tween to a generic "scale" tween).
     *
     * @param pTweenType The starting tween type.
     */
    static ETweenGenericType ConvertTweenTypeEnum(ETweenFloatType pTweenType);

    /**
     * @brief Helper method that convertes the given reference axis into the actual axis vector.
     * 
     * @param pReferenceAxis The reference axis enum.
     * 
     * @return The axis expressed as a vector.
     */
    static FVector FromReferenceAxisToVector(ETweenReferenceAxis pReferenceAxis);

    /**
     * @brief Utility method that computes the axis and radius to be used for "RotateAroundPointByOffset" type of Tweens.
     *
     * @param pActor                The target actor
     * @param pPivotPoint           The pivot point
     * @param pReferenceAxis        The reference axis
     * @param pTweenSpace           The space to use for the computation (world or relative)
     * @param pOutAxis              (out) The computed axis
     * @param pOutRadius            (out) The computed radius
     */
    static void ComputeDataForRotateAroundPoint(AActor* pActor,
                                                const FVector& pPivotPoint,
                                                ETweenReferenceAxis pReferenceAxis,
                                                ETweenSpace pTweenSpace,
                                                FVector& pOutAxis,
                                                float& pOutRadius);

    /**
     * @brief Utility method that computes the axis and radius to be used for "RotateAroundPointByOffset" type of Tweens.
     *
     * @param pComponent            The target component
     * @param pPivotPoint           The pivot point
     * @param pReferenceAxis        The reference axis
     * @param pTweenSpace           The space to use for the computation (world or relative)
     * @param pOutAxis              (out) The computed axis
     * @param pOutRadius            (out) The computed radius
     */
    static void ComputeDataForRotateAroundPoint(USceneComponent* pComponent,
                                                const FVector& pPivotPoint,
                                                ETweenReferenceAxis pReferenceAxis,
                                                ETweenSpace pTweenSpace,
                                                FVector& pOutAxis,
                                                float& pOutRadius);


    /**
     * @brief Helper method that given a tween it finds the generic tween category it belongs to.
     *
     * @note On the bad case, this function does several casts.
     *
     * @param pTween The involved tween.
     *
     * @return The converted type.
     */
    static ETweenGenericType FindOutTypeOfTween(UBaseTween* pTween);

    /**
     * @brief Helper function that converts a value from an old range to a new one.
     *
     * @param pValue Value belonging to the old range, to be mapped into the new one.
     * @param pOldMin Old range minimum.
     * @param pOldMax Old range maximum.
     * @param pNewMin New range minimum.
     * @param pNewMax New range maximum.
     *
     * @return The value mapped to the new range.
     */
    static float MapToRange(float pValue, float pOldMin, float pOldMax, float pNewMin, float pNewMax);
};
