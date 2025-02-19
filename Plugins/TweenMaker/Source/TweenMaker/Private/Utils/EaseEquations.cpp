// Copyright 2018 Francesco Desogus. All Rights Reserved.

#include "Utils/EaseEquations.h"
#include "Utils/Utility.h"
#include "Curves/CurveFloat.h"

// public ----------------------------------------------------------------------
EaseEquations::EaseEquations()
{
}

// public ----------------------------------------------------------------------
EaseEquations::~EaseEquations()
{
}

// static public ---------------------------------------------------------------
float EaseEquations::ComputeFloatEasing(ETweenEaseType pEaseType, float pCurrentTime, float pStartingValue, float pEndingValue, float pDuration)
{
    float result    = 0.0f;
    float valueSpan = pEndingValue - pStartingValue;

    switch (pEaseType)
    {
        case ETweenEaseType::Linear:
        {
            result = EaseLinear(pCurrentTime, pStartingValue, valueSpan, pDuration);
            break;
        }
        case ETweenEaseType::EaseInQuad:
        {
            result = EaseInQuad(pCurrentTime, pStartingValue, valueSpan, pDuration);
            break;
        }
        case ETweenEaseType::EaseOutQuad:
        {
            result = EaseOutQuad(pCurrentTime, pStartingValue, valueSpan, pDuration);
            break;
        }
        case ETweenEaseType::EaseInOutQuad:
        {
            result = EaseInOutQuad(pCurrentTime, pStartingValue, valueSpan, pDuration);
            break;
        }
        case ETweenEaseType::EaseOutInQuad:
        {
            result = EaseOutInQuad(pCurrentTime, pStartingValue, valueSpan, pDuration);
            break;
        }
        case ETweenEaseType::EaseInCubic:
        {
            result = EaseInCubic(pCurrentTime, pStartingValue, valueSpan, pDuration);
            break;
        }
        case ETweenEaseType::EaseOutCubic:
        {
            result = EaseOutCubic(pCurrentTime, pStartingValue, valueSpan, pDuration);
            break;
        }
        case ETweenEaseType::EaseInOutCubic:
        {
            result = EaseInOutCubic(pCurrentTime, pStartingValue, valueSpan, pDuration);
            break;
        }
        case ETweenEaseType::EaseOutInCubic:
        {
            result = EaseOutInCubic(pCurrentTime, pStartingValue, valueSpan, pDuration);
            break;
        }
        case ETweenEaseType::EaseInQuart:
        {
            result = EaseInQuart(pCurrentTime, pStartingValue, valueSpan, pDuration);
            break;
        }
        case ETweenEaseType::EaseOutQuart:
        {
            result = EaseOutQuart(pCurrentTime, pStartingValue, valueSpan, pDuration);
            break;
        }
        case ETweenEaseType::EaseInOutQuart:
        {
            result = EaseInOutQuart(pCurrentTime, pStartingValue, valueSpan, pDuration);
            break;
        }
        case ETweenEaseType::EaseOutInQuart:
        {
            result = EaseOutInQuart(pCurrentTime, pStartingValue, valueSpan, pDuration);
            break;
        }
        case ETweenEaseType::EaseInQuint:
        {
            result = EaseInQuint(pCurrentTime, pStartingValue, valueSpan, pDuration);
            break;
        }
        case ETweenEaseType::EaseOutQuint:
        {
            result = EaseOutQuint(pCurrentTime, pStartingValue, valueSpan, pDuration);
            break;
        }
        case ETweenEaseType::EaseInOutQuint:
        {
            result = EaseInOutQuint(pCurrentTime, pStartingValue, valueSpan, pDuration);
            break;
        }
        case ETweenEaseType::EaseOutInQuint:
        {
            result = EaseOutInQuint(pCurrentTime, pStartingValue, valueSpan, pDuration);
            break;
        }
        case ETweenEaseType::EaseInSine:
        {
            result = EaseInSine(pCurrentTime, pStartingValue, valueSpan, pDuration);
            break;
        }
        case ETweenEaseType::EaseOutSine:
        {
            result = EaseOutSine(pCurrentTime, pStartingValue, valueSpan, pDuration);
            break;
        }
        case ETweenEaseType::EaseInOutSine:
        {
            result = EaseInOutSine(pCurrentTime, pStartingValue, valueSpan, pDuration);
            break;
        }
        case ETweenEaseType::EaseOutInSine:
        {
            result = EaseOutInSine(pCurrentTime, pStartingValue, valueSpan, pDuration);
            break;
        }
        case ETweenEaseType::EaseInExpo:
        {
            result = EaseInExpo(pCurrentTime, pStartingValue, valueSpan, pDuration);
            break;
        }
        case ETweenEaseType::EaseOutExpo:
        {
            result = EaseOutExpo(pCurrentTime, pStartingValue, valueSpan, pDuration);
            break;
        }
        case ETweenEaseType::EaseInOutExpo:
        {
            result = EaseInOutExpo(pCurrentTime, pStartingValue, valueSpan, pDuration);
            break;
        }
        case ETweenEaseType::EaseOutInExpo:
        {
            result = EaseOutInExpo(pCurrentTime, pStartingValue, valueSpan, pDuration);
            break;
        }
        case ETweenEaseType::EaseInCirc:
        {
            result = EaseInCirc(pCurrentTime, pStartingValue, valueSpan, pDuration);
            break;
        }
        case ETweenEaseType::EaseOutCirc:
        {
            result = EaseOutCirc(pCurrentTime, pStartingValue, valueSpan, pDuration);
            break;
        }
        case ETweenEaseType::EaseInOutCirc:
        {
            result = EaseInOutCirc(pCurrentTime, pStartingValue, valueSpan, pDuration);
            break;
        }
        case ETweenEaseType::EaseOutInCirc:
        {
            result = EaseOutInCirc(pCurrentTime, pStartingValue, valueSpan, pDuration);
            break;
        }
        case ETweenEaseType::EaseInElastic:
        {
            result = EaseInElastic(pCurrentTime, pStartingValue, valueSpan, pDuration);
            break;
        }
        case ETweenEaseType::EaseOutElastic:
        {
            result = EaseOutElastic(pCurrentTime, pStartingValue, valueSpan, pDuration);
            break;
        }
        case ETweenEaseType::EaseInOutElastic:
        {
            result = EaseInOutElastic(pCurrentTime, pStartingValue, valueSpan, pDuration);
            break;
        }
        case ETweenEaseType::EaseOutInElastic:
        {
            result = EaseOutInElastic(pCurrentTime, pStartingValue, valueSpan, pDuration);
            break;
        }
        case ETweenEaseType::EaseInBack:
        {
            result = EaseInBack(pCurrentTime, pStartingValue, valueSpan, pDuration);
            break;
        }
        case ETweenEaseType::EaseOutBack:
        {
            result = EaseOutBack(pCurrentTime, pStartingValue, valueSpan, pDuration);
            break;
        }
        case ETweenEaseType::EaseInOutBack:
        {
            result = EaseInOutBack(pCurrentTime, pStartingValue, valueSpan, pDuration);
            break;
        }
        case ETweenEaseType::EaseOutInBack:
        {
            result = EaseOutInBack(pCurrentTime, pStartingValue, valueSpan, pDuration);
            break;
        }
        case ETweenEaseType::EaseInBounce:
        {
            result = EaseInBounce(pCurrentTime, pStartingValue, valueSpan, pDuration);
            break;
        }
        case ETweenEaseType::EaseOutBounce:
        {
            result = EaseOutBounce(pCurrentTime, pStartingValue, valueSpan, pDuration);
            break;
        }
        case ETweenEaseType::EaseInOutBounce:
        {
            result = EaseInOutBounce(pCurrentTime, pStartingValue, valueSpan, pDuration);
            break;
        }
        case ETweenEaseType::EaseOutInBounce:
        {
            result = EaseOutInBounce(pCurrentTime, pStartingValue, valueSpan, pDuration);
            break;
        }
    }

    return result;
}

// static public ---------------------------------------------------------------
float EaseEquations::ComputeCustomFloatEasing(UCurveFloat* pCurveFloat,
                                              float pCurrentTime,
                                              const float& pStartingValue,
                                              const float& pEndingValue,
                                              float pDuration)
{
    float result = 0.0f;

    float minTime;
    float maxTime;
    pCurveFloat->GetTimeRange(minTime, maxTime);

    // Convert the current time into a the corresponding curve value
    float curveTime = Utility::MapToRange(pCurrentTime, 0, pDuration, minTime, maxTime);
    float curveVal  = pCurveFloat->GetFloatValue(curveTime);

    float valueSpan = pEndingValue - pStartingValue;

    result = pStartingValue + valueSpan * curveVal;

    return result;
}

// static public ---------------------------------------------------------------
void EaseEquations::ComputeVectorEasing(ETweenEaseType pEaseType,
                                        float pCurrentTime,
                                        const FVector& pStartingValue,
                                        const FVector& pEndingValue,
                                        float pDuration,
                                        FVector& OutNewValue)
{
    FVector valueSpan = pEndingValue - pStartingValue;

    switch (pEaseType)
    {
        case ETweenEaseType::Linear:
        {
            OutNewValue.X = EaseLinear(pCurrentTime, pStartingValue.X, valueSpan.X, pDuration);
            OutNewValue.Y = EaseLinear(pCurrentTime, pStartingValue.Y, valueSpan.Y, pDuration);
            OutNewValue.Z = EaseLinear(pCurrentTime, pStartingValue.Z, valueSpan.Z, pDuration);
            break;
        }
        case ETweenEaseType::EaseInQuad:
        {
            OutNewValue.X = EaseInQuad(pCurrentTime, pStartingValue.X, valueSpan.X, pDuration);
            OutNewValue.Y = EaseInQuad(pCurrentTime, pStartingValue.Y, valueSpan.Y, pDuration);
            OutNewValue.Z = EaseInQuad(pCurrentTime, pStartingValue.Z, valueSpan.Z, pDuration);
            break;
        }
        case ETweenEaseType::EaseOutQuad:
        {
            OutNewValue.X = EaseOutQuad(pCurrentTime, pStartingValue.X, valueSpan.X, pDuration);
            OutNewValue.Y = EaseOutQuad(pCurrentTime, pStartingValue.Y, valueSpan.Y, pDuration);
            OutNewValue.Z = EaseOutQuad(pCurrentTime, pStartingValue.Z, valueSpan.Z, pDuration);
            break;
        }
        case ETweenEaseType::EaseInOutQuad:
        {
            OutNewValue.X = EaseInOutQuad(pCurrentTime, pStartingValue.X, valueSpan.X, pDuration);
            OutNewValue.Y = EaseInOutQuad(pCurrentTime, pStartingValue.Y, valueSpan.Y, pDuration);
            OutNewValue.Z = EaseInOutQuad(pCurrentTime, pStartingValue.Z, valueSpan.Z, pDuration);
            break;
        }
        case ETweenEaseType::EaseOutInQuad:
        {
            OutNewValue.X = EaseOutInQuad(pCurrentTime, pStartingValue.X, valueSpan.X, pDuration);
            OutNewValue.Y = EaseOutInQuad(pCurrentTime, pStartingValue.Y, valueSpan.Y, pDuration);
            OutNewValue.Z = EaseOutInQuad(pCurrentTime, pStartingValue.Z, valueSpan.Z, pDuration);
            break;
        }
        case ETweenEaseType::EaseInCubic:
        {
            OutNewValue.X = EaseInCubic(pCurrentTime, pStartingValue.X, valueSpan.X, pDuration);
            OutNewValue.Y = EaseInCubic(pCurrentTime, pStartingValue.Y, valueSpan.Y, pDuration);
            OutNewValue.Z = EaseInCubic(pCurrentTime, pStartingValue.Z, valueSpan.Z, pDuration);
            break;
        }
        case ETweenEaseType::EaseOutCubic:
        {
            OutNewValue.X = EaseOutCubic(pCurrentTime, pStartingValue.X, valueSpan.X, pDuration);
            OutNewValue.Y = EaseOutCubic(pCurrentTime, pStartingValue.Y, valueSpan.Y, pDuration);
            OutNewValue.Z = EaseOutCubic(pCurrentTime, pStartingValue.Z, valueSpan.Z, pDuration);
            break;
        }
        case ETweenEaseType::EaseInOutCubic:
        {
            OutNewValue.X = EaseInOutCubic(pCurrentTime, pStartingValue.X, valueSpan.X, pDuration);
            OutNewValue.Y = EaseInOutCubic(pCurrentTime, pStartingValue.Y, valueSpan.Y, pDuration);
            OutNewValue.Z = EaseInOutCubic(pCurrentTime, pStartingValue.Z, valueSpan.Z, pDuration);
            break;
        }
        case ETweenEaseType::EaseOutInCubic:
        {
            OutNewValue.X = EaseOutInCubic(pCurrentTime, pStartingValue.X, valueSpan.X, pDuration);
            OutNewValue.Y = EaseOutInCubic(pCurrentTime, pStartingValue.Y, valueSpan.Y, pDuration);
            OutNewValue.Z = EaseOutInCubic(pCurrentTime, pStartingValue.Z, valueSpan.Z, pDuration);
            break;
        }
        case ETweenEaseType::EaseInQuart:
        {
            OutNewValue.X = EaseInQuart(pCurrentTime, pStartingValue.X, valueSpan.X, pDuration);
            OutNewValue.Y = EaseInQuart(pCurrentTime, pStartingValue.Y, valueSpan.Y, pDuration);
            OutNewValue.Z = EaseInQuart(pCurrentTime, pStartingValue.Z, valueSpan.Z, pDuration);
            break;
        }
        case ETweenEaseType::EaseOutQuart:
        {
            OutNewValue.X = EaseOutQuart(pCurrentTime, pStartingValue.X, valueSpan.X, pDuration);
            OutNewValue.Y = EaseOutQuart(pCurrentTime, pStartingValue.Y, valueSpan.Y, pDuration);
            OutNewValue.Z = EaseOutQuart(pCurrentTime, pStartingValue.Z, valueSpan.Z, pDuration);
            break;
        }
        case ETweenEaseType::EaseInOutQuart:
        {
            OutNewValue.X = EaseInOutQuart(pCurrentTime, pStartingValue.X, valueSpan.X, pDuration);
            OutNewValue.Y = EaseInOutQuart(pCurrentTime, pStartingValue.Y, valueSpan.Y, pDuration);
            OutNewValue.Z = EaseInOutQuart(pCurrentTime, pStartingValue.Z, valueSpan.Z, pDuration);
            break;
        }
        case ETweenEaseType::EaseOutInQuart:
        {
            OutNewValue.X = EaseOutInQuart(pCurrentTime, pStartingValue.X, valueSpan.X, pDuration);
            OutNewValue.Y = EaseOutInQuart(pCurrentTime, pStartingValue.Y, valueSpan.Y, pDuration);
            OutNewValue.Z = EaseOutInQuart(pCurrentTime, pStartingValue.Z, valueSpan.Z, pDuration);
            break;
        }
        case ETweenEaseType::EaseInQuint:
        {
            OutNewValue.X = EaseInQuint(pCurrentTime, pStartingValue.X, valueSpan.X, pDuration);
            OutNewValue.Y = EaseInQuint(pCurrentTime, pStartingValue.Y, valueSpan.Y, pDuration);
            OutNewValue.Z = EaseInQuint(pCurrentTime, pStartingValue.Z, valueSpan.Z, pDuration);
            break;
        }
        case ETweenEaseType::EaseOutQuint:
        {
            OutNewValue.X = EaseOutQuint(pCurrentTime, pStartingValue.X, valueSpan.X, pDuration);
            OutNewValue.Y = EaseOutQuint(pCurrentTime, pStartingValue.Y, valueSpan.Y, pDuration);
            OutNewValue.Z = EaseOutQuint(pCurrentTime, pStartingValue.Z, valueSpan.Z, pDuration);
            break;
        }
        case ETweenEaseType::EaseInOutQuint:
        {
            OutNewValue.X = EaseInOutQuint(pCurrentTime, pStartingValue.X, valueSpan.X, pDuration);
            OutNewValue.Y = EaseInOutQuint(pCurrentTime, pStartingValue.Y, valueSpan.Y, pDuration);
            OutNewValue.Z = EaseInOutQuint(pCurrentTime, pStartingValue.Z, valueSpan.Z, pDuration);
            break;
        }
        case ETweenEaseType::EaseOutInQuint:
        {
            OutNewValue.X = EaseOutInQuint(pCurrentTime, pStartingValue.X, valueSpan.X, pDuration);
            OutNewValue.Y = EaseOutInQuint(pCurrentTime, pStartingValue.Y, valueSpan.Y, pDuration);
            OutNewValue.Z = EaseOutInQuint(pCurrentTime, pStartingValue.Z, valueSpan.Z, pDuration);
            break;
        }
        case ETweenEaseType::EaseInSine:
        {
            OutNewValue.X = EaseInSine(pCurrentTime, pStartingValue.X, valueSpan.X, pDuration);
            OutNewValue.Y = EaseInSine(pCurrentTime, pStartingValue.Y, valueSpan.Y, pDuration);
            OutNewValue.Z = EaseInSine(pCurrentTime, pStartingValue.Z, valueSpan.Z, pDuration);
            break;
        }
        case ETweenEaseType::EaseOutSine:
        {
            OutNewValue.X = EaseOutSine(pCurrentTime, pStartingValue.X, valueSpan.X, pDuration);
            OutNewValue.Y = EaseOutSine(pCurrentTime, pStartingValue.Y, valueSpan.Y, pDuration);
            OutNewValue.Z = EaseOutSine(pCurrentTime, pStartingValue.Z, valueSpan.Z, pDuration);
            break;
        }
        case ETweenEaseType::EaseInOutSine:
        {
            OutNewValue.X = EaseInOutSine(pCurrentTime, pStartingValue.X, valueSpan.X, pDuration);
            OutNewValue.Y = EaseInOutSine(pCurrentTime, pStartingValue.Y, valueSpan.Y, pDuration);
            OutNewValue.Z = EaseInOutSine(pCurrentTime, pStartingValue.Z, valueSpan.Z, pDuration);
            break;
        }
        case ETweenEaseType::EaseOutInSine:
        {
            OutNewValue.X = EaseOutInSine(pCurrentTime, pStartingValue.X, valueSpan.X, pDuration);
            OutNewValue.Y = EaseOutInSine(pCurrentTime, pStartingValue.Y, valueSpan.Y, pDuration);
            OutNewValue.Z = EaseOutInSine(pCurrentTime, pStartingValue.Z, valueSpan.Z, pDuration);
            break;
        }
        case ETweenEaseType::EaseInExpo:
        {
            OutNewValue.X = EaseInExpo(pCurrentTime, pStartingValue.X, valueSpan.X, pDuration);
            OutNewValue.Y = EaseInExpo(pCurrentTime, pStartingValue.Y, valueSpan.Y, pDuration);
            OutNewValue.Z = EaseInExpo(pCurrentTime, pStartingValue.Z, valueSpan.Z, pDuration);
            break;
        }
        case ETweenEaseType::EaseOutExpo:
        {
            OutNewValue.X = EaseOutExpo(pCurrentTime, pStartingValue.X, valueSpan.X, pDuration);
            OutNewValue.Y = EaseOutExpo(pCurrentTime, pStartingValue.Y, valueSpan.Y, pDuration);
            OutNewValue.Z = EaseOutExpo(pCurrentTime, pStartingValue.Z, valueSpan.Z, pDuration);
            break;
        }
        case ETweenEaseType::EaseInOutExpo:
        {
            OutNewValue.X = EaseInOutExpo(pCurrentTime, pStartingValue.X, valueSpan.X, pDuration);
            OutNewValue.Y = EaseInOutExpo(pCurrentTime, pStartingValue.Y, valueSpan.Y, pDuration);
            OutNewValue.Z = EaseInOutExpo(pCurrentTime, pStartingValue.Z, valueSpan.Z, pDuration);
            break;
        }
        case ETweenEaseType::EaseOutInExpo:
        {
            OutNewValue.X = EaseOutInExpo(pCurrentTime, pStartingValue.X, valueSpan.X, pDuration);
            OutNewValue.Y = EaseOutInExpo(pCurrentTime, pStartingValue.Y, valueSpan.Y, pDuration);
            OutNewValue.Z = EaseOutInExpo(pCurrentTime, pStartingValue.Z, valueSpan.Z, pDuration);
            break;
        }
        case ETweenEaseType::EaseInCirc:
        {
            OutNewValue.X = EaseInCirc(pCurrentTime, pStartingValue.X, valueSpan.X, pDuration);
            OutNewValue.Y = EaseInCirc(pCurrentTime, pStartingValue.Y, valueSpan.Y, pDuration);
            OutNewValue.Z = EaseInCirc(pCurrentTime, pStartingValue.Z, valueSpan.Z, pDuration);
            break;
        }
        case ETweenEaseType::EaseOutCirc:
        {
            OutNewValue.X = EaseOutCirc(pCurrentTime, pStartingValue.X, valueSpan.X, pDuration);
            OutNewValue.Y = EaseOutCirc(pCurrentTime, pStartingValue.Y, valueSpan.Y, pDuration);
            OutNewValue.Z = EaseOutCirc(pCurrentTime, pStartingValue.Z, valueSpan.Z, pDuration);
            break;
        }
        case ETweenEaseType::EaseInOutCirc:
        {
            OutNewValue.X = EaseInOutCirc(pCurrentTime, pStartingValue.X, valueSpan.X, pDuration);
            OutNewValue.Y = EaseInOutCirc(pCurrentTime, pStartingValue.Y, valueSpan.Y, pDuration);
            OutNewValue.Z = EaseInOutCirc(pCurrentTime, pStartingValue.Z, valueSpan.Z, pDuration);
            break;
        }
        case ETweenEaseType::EaseOutInCirc:
        {
            OutNewValue.X = EaseOutInCirc(pCurrentTime, pStartingValue.X, valueSpan.X, pDuration);
            OutNewValue.Y = EaseOutInCirc(pCurrentTime, pStartingValue.Y, valueSpan.Y, pDuration);
            OutNewValue.Z = EaseOutInCirc(pCurrentTime, pStartingValue.Z, valueSpan.Z, pDuration);
            break;
        }
        case ETweenEaseType::EaseInElastic:
        {
            OutNewValue.X = EaseInElastic(pCurrentTime, pStartingValue.X, valueSpan.X, pDuration);
            OutNewValue.Y = EaseInElastic(pCurrentTime, pStartingValue.Y, valueSpan.Y, pDuration);
            OutNewValue.Z = EaseInElastic(pCurrentTime, pStartingValue.Z, valueSpan.Z, pDuration);
            break;
        }
        case ETweenEaseType::EaseOutElastic:
        {
            OutNewValue.X = EaseOutElastic(pCurrentTime, pStartingValue.X, valueSpan.X, pDuration);
            OutNewValue.Y = EaseOutElastic(pCurrentTime, pStartingValue.Y, valueSpan.Y, pDuration);
            OutNewValue.Z = EaseOutElastic(pCurrentTime, pStartingValue.Z, valueSpan.Z, pDuration);
            break;
        }
        case ETweenEaseType::EaseInOutElastic:
        {
            OutNewValue.X = EaseInOutElastic(pCurrentTime, pStartingValue.X, valueSpan.X, pDuration);
            OutNewValue.Y = EaseInOutElastic(pCurrentTime, pStartingValue.Y, valueSpan.Y, pDuration);
            OutNewValue.Z = EaseInOutElastic(pCurrentTime, pStartingValue.Z, valueSpan.Z, pDuration);
            break;
        }
        case ETweenEaseType::EaseOutInElastic:
        {
            OutNewValue.X = EaseOutInElastic(pCurrentTime, pStartingValue.X, valueSpan.X, pDuration);
            OutNewValue.Y = EaseOutInElastic(pCurrentTime, pStartingValue.Y, valueSpan.Y, pDuration);
            OutNewValue.Z = EaseOutInElastic(pCurrentTime, pStartingValue.Z, valueSpan.Z, pDuration);
            break;
        }
        case ETweenEaseType::EaseInBack:
        {
            OutNewValue.X = EaseInBack(pCurrentTime, pStartingValue.X, valueSpan.X, pDuration);
            OutNewValue.Y = EaseInBack(pCurrentTime, pStartingValue.Y, valueSpan.Y, pDuration);
            OutNewValue.Z = EaseInBack(pCurrentTime, pStartingValue.Z, valueSpan.Z, pDuration);
            break;
        }
        case ETweenEaseType::EaseOutBack:
        {
            OutNewValue.X = EaseOutBack(pCurrentTime, pStartingValue.X, valueSpan.X, pDuration);
            OutNewValue.Y = EaseOutBack(pCurrentTime, pStartingValue.Y, valueSpan.Y, pDuration);
            OutNewValue.Z = EaseOutBack(pCurrentTime, pStartingValue.Z, valueSpan.Z, pDuration);
            break;
        }
        case ETweenEaseType::EaseInOutBack:
        {
            OutNewValue.X = EaseInOutBack(pCurrentTime, pStartingValue.X, valueSpan.X, pDuration);
            OutNewValue.Y = EaseInOutBack(pCurrentTime, pStartingValue.Y, valueSpan.Y, pDuration);
            OutNewValue.Z = EaseInOutBack(pCurrentTime, pStartingValue.Z, valueSpan.Z, pDuration);
            break;
        }
        case ETweenEaseType::EaseOutInBack:
        {
            OutNewValue.X = EaseOutInBack(pCurrentTime, pStartingValue.X, valueSpan.X, pDuration);
            OutNewValue.Y = EaseOutInBack(pCurrentTime, pStartingValue.Y, valueSpan.Y, pDuration);
            OutNewValue.Z = EaseOutInBack(pCurrentTime, pStartingValue.Z, valueSpan.Z, pDuration);
            break;
        }
        case ETweenEaseType::EaseInBounce:
        {
            OutNewValue.X = EaseInBounce(pCurrentTime, pStartingValue.X, valueSpan.X, pDuration);
            OutNewValue.Y = EaseInBounce(pCurrentTime, pStartingValue.Y, valueSpan.Y, pDuration);
            OutNewValue.Z = EaseInBounce(pCurrentTime, pStartingValue.Z, valueSpan.Z, pDuration);
            break;
        }
        case ETweenEaseType::EaseOutBounce:
        {
            OutNewValue.X = EaseOutBounce(pCurrentTime, pStartingValue.X, valueSpan.X, pDuration);
            OutNewValue.Y = EaseOutBounce(pCurrentTime, pStartingValue.Y, valueSpan.Y, pDuration);
            OutNewValue.Z = EaseOutBounce(pCurrentTime, pStartingValue.Z, valueSpan.Z, pDuration);
            break;
        }
        case ETweenEaseType::EaseInOutBounce:
        {
            OutNewValue.X = EaseInOutBounce(pCurrentTime, pStartingValue.X, valueSpan.X, pDuration);
            OutNewValue.Y = EaseInOutBounce(pCurrentTime, pStartingValue.Y, valueSpan.Y, pDuration);
            OutNewValue.Z = EaseInOutBounce(pCurrentTime, pStartingValue.Z, valueSpan.Z, pDuration);
            break;
        }
        case ETweenEaseType::EaseOutInBounce:
        {
            OutNewValue.X = EaseOutInBounce(pCurrentTime, pStartingValue.X, valueSpan.X, pDuration);
            OutNewValue.Y = EaseOutInBounce(pCurrentTime, pStartingValue.Y, valueSpan.Y, pDuration);
            OutNewValue.Z = EaseOutInBounce(pCurrentTime, pStartingValue.Z, valueSpan.Z, pDuration);
            break;
        }
    }
}

// static public ---------------------------------------------------------------
void EaseEquations::ComputeCustomVectorEasing(UCurveFloat* pCurveFloat,
                                              float pCurrentTime,
                                              const FVector& pStartingValue,
                                              const FVector& pEndingValue,
                                              float pDuration,
                                              FVector& OutNewValue)
{
    float minTime;
    float maxTime;
    pCurveFloat->GetTimeRange(minTime, maxTime);

    float curveTime = Utility::MapToRange(pCurrentTime, 0, pDuration, minTime, maxTime);
    float curveVal  = pCurveFloat->GetFloatValue(curveTime);

    FVector valueSpan = pEndingValue - pStartingValue;

    OutNewValue.X = pStartingValue.X + valueSpan.X * curveVal;
    OutNewValue.Y = pStartingValue.Y + valueSpan.Y * curveVal;
    OutNewValue.Z = pStartingValue.Z + valueSpan.Z * curveVal;
}

// static public ---------------------------------------------------------------
void EaseEquations::ComputeVector2DEasing(ETweenEaseType pEaseType,
                                          float pCurrentTime,
                                          const FVector2D& pStartingValue,
                                          const FVector2D& pEndingValue,
                                          float pDuration,
                                          FVector2D& OutNewValue)
{
    FVector2D valueSpan = pEndingValue - pStartingValue;

    switch (pEaseType)
    {
        case ETweenEaseType::Linear:
        {
            OutNewValue.X = EaseLinear(pCurrentTime, pStartingValue.X, valueSpan.X, pDuration);
            OutNewValue.Y = EaseLinear(pCurrentTime, pStartingValue.Y, valueSpan.Y, pDuration);
            break;
        }
        case ETweenEaseType::EaseInQuad:
        {
            OutNewValue.X = EaseInQuad(pCurrentTime, pStartingValue.X, valueSpan.X, pDuration);
            OutNewValue.Y = EaseInQuad(pCurrentTime, pStartingValue.Y, valueSpan.Y, pDuration);
            break;
        }
        case ETweenEaseType::EaseOutQuad:
        {
            OutNewValue.X = EaseOutQuad(pCurrentTime, pStartingValue.X, valueSpan.X, pDuration);
            OutNewValue.Y = EaseOutQuad(pCurrentTime, pStartingValue.Y, valueSpan.Y, pDuration);
            break;
        }
        case ETweenEaseType::EaseInOutQuad:
        {
            OutNewValue.X = EaseInOutQuad(pCurrentTime, pStartingValue.X, valueSpan.X, pDuration);
            OutNewValue.Y = EaseInOutQuad(pCurrentTime, pStartingValue.Y, valueSpan.Y, pDuration);
            break;
        }
        case ETweenEaseType::EaseOutInQuad:
        {
            OutNewValue.X = EaseOutInQuad(pCurrentTime, pStartingValue.X, valueSpan.X, pDuration);
            OutNewValue.Y = EaseOutInQuad(pCurrentTime, pStartingValue.Y, valueSpan.Y, pDuration);
            break;
        }
        case ETweenEaseType::EaseInCubic:
        {
            OutNewValue.X = EaseInCubic(pCurrentTime, pStartingValue.X, valueSpan.X, pDuration);
            OutNewValue.Y = EaseInCubic(pCurrentTime, pStartingValue.Y, valueSpan.Y, pDuration);
            break;
        }
        case ETweenEaseType::EaseOutCubic:
        {
            OutNewValue.X = EaseOutCubic(pCurrentTime, pStartingValue.X, valueSpan.X, pDuration);
            OutNewValue.Y = EaseOutCubic(pCurrentTime, pStartingValue.Y, valueSpan.Y, pDuration);
            break;
        }
        case ETweenEaseType::EaseInOutCubic:
        {
            OutNewValue.X = EaseInOutCubic(pCurrentTime, pStartingValue.X, valueSpan.X, pDuration);
            OutNewValue.Y = EaseInOutCubic(pCurrentTime, pStartingValue.Y, valueSpan.Y, pDuration);
            break;
        }
        case ETweenEaseType::EaseOutInCubic:
        {
            OutNewValue.X = EaseOutInCubic(pCurrentTime, pStartingValue.X, valueSpan.X, pDuration);
            OutNewValue.Y = EaseOutInCubic(pCurrentTime, pStartingValue.Y, valueSpan.Y, pDuration);
            break;
        }
        case ETweenEaseType::EaseInQuart:
        {
            OutNewValue.X = EaseInQuart(pCurrentTime, pStartingValue.X, valueSpan.X, pDuration);
            OutNewValue.Y = EaseInQuart(pCurrentTime, pStartingValue.Y, valueSpan.Y, pDuration);
            break;
        }
        case ETweenEaseType::EaseOutQuart:
        {
            OutNewValue.X = EaseOutQuart(pCurrentTime, pStartingValue.X, valueSpan.X, pDuration);
            OutNewValue.Y = EaseOutQuart(pCurrentTime, pStartingValue.Y, valueSpan.Y, pDuration);
            break;
        }
        case ETweenEaseType::EaseInOutQuart:
        {
            OutNewValue.X = EaseInOutQuart(pCurrentTime, pStartingValue.X, valueSpan.X, pDuration);
            OutNewValue.Y = EaseInOutQuart(pCurrentTime, pStartingValue.Y, valueSpan.Y, pDuration);
            break;
        }
        case ETweenEaseType::EaseOutInQuart:
        {
            OutNewValue.X = EaseOutInQuart(pCurrentTime, pStartingValue.X, valueSpan.X, pDuration);
            OutNewValue.Y = EaseOutInQuart(pCurrentTime, pStartingValue.Y, valueSpan.Y, pDuration);
            break;
        }
        case ETweenEaseType::EaseInQuint:
        {
            OutNewValue.X = EaseInQuint(pCurrentTime, pStartingValue.X, valueSpan.X, pDuration);
            OutNewValue.Y = EaseInQuint(pCurrentTime, pStartingValue.Y, valueSpan.Y, pDuration);
            break;
        }
        case ETweenEaseType::EaseOutQuint:
        {
            OutNewValue.X = EaseOutQuint(pCurrentTime, pStartingValue.X, valueSpan.X, pDuration);
            OutNewValue.Y = EaseOutQuint(pCurrentTime, pStartingValue.Y, valueSpan.Y, pDuration);
            break;
        }
        case ETweenEaseType::EaseInOutQuint:
        {
            OutNewValue.X = EaseInOutQuint(pCurrentTime, pStartingValue.X, valueSpan.X, pDuration);
            OutNewValue.Y = EaseInOutQuint(pCurrentTime, pStartingValue.Y, valueSpan.Y, pDuration);
            break;
        }
        case ETweenEaseType::EaseOutInQuint:
        {
            OutNewValue.X = EaseOutInQuint(pCurrentTime, pStartingValue.X, valueSpan.X, pDuration);
            OutNewValue.Y = EaseOutInQuint(pCurrentTime, pStartingValue.Y, valueSpan.Y, pDuration);
            break;
        }
        case ETweenEaseType::EaseInSine:
        {
            OutNewValue.X = EaseInSine(pCurrentTime, pStartingValue.X, valueSpan.X, pDuration);
            OutNewValue.Y = EaseInSine(pCurrentTime, pStartingValue.Y, valueSpan.Y, pDuration);
            break;
        }
        case ETweenEaseType::EaseOutSine:
        {
            OutNewValue.X = EaseOutSine(pCurrentTime, pStartingValue.X, valueSpan.X, pDuration);
            OutNewValue.Y = EaseOutSine(pCurrentTime, pStartingValue.Y, valueSpan.Y, pDuration);
            break;
        }
        case ETweenEaseType::EaseInOutSine:
        {
            OutNewValue.X = EaseInOutSine(pCurrentTime, pStartingValue.X, valueSpan.X, pDuration);
            OutNewValue.Y = EaseInOutSine(pCurrentTime, pStartingValue.Y, valueSpan.Y, pDuration);
            break;
        }
        case ETweenEaseType::EaseOutInSine:
        {
            OutNewValue.X = EaseOutInSine(pCurrentTime, pStartingValue.X, valueSpan.X, pDuration);
            OutNewValue.Y = EaseOutInSine(pCurrentTime, pStartingValue.Y, valueSpan.Y, pDuration);
            break;
        }
        case ETweenEaseType::EaseInExpo:
        {
            OutNewValue.X = EaseInExpo(pCurrentTime, pStartingValue.X, valueSpan.X, pDuration);
            OutNewValue.Y = EaseInExpo(pCurrentTime, pStartingValue.Y, valueSpan.Y, pDuration);
            break;
        }
        case ETweenEaseType::EaseOutExpo:
        {
            OutNewValue.X = EaseOutExpo(pCurrentTime, pStartingValue.X, valueSpan.X, pDuration);
            OutNewValue.Y = EaseOutExpo(pCurrentTime, pStartingValue.Y, valueSpan.Y, pDuration);
            break;
        }
        case ETweenEaseType::EaseInOutExpo:
        {
            OutNewValue.X = EaseInOutExpo(pCurrentTime, pStartingValue.X, valueSpan.X, pDuration);
            OutNewValue.Y = EaseInOutExpo(pCurrentTime, pStartingValue.Y, valueSpan.Y, pDuration);
            break;
        }
        case ETweenEaseType::EaseOutInExpo:
        {
            OutNewValue.X = EaseOutInExpo(pCurrentTime, pStartingValue.X, valueSpan.X, pDuration);
            OutNewValue.Y = EaseOutInExpo(pCurrentTime, pStartingValue.Y, valueSpan.Y, pDuration);
            break;
        }
        case ETweenEaseType::EaseInCirc:
        {
            OutNewValue.X = EaseInCirc(pCurrentTime, pStartingValue.X, valueSpan.X, pDuration);
            OutNewValue.Y = EaseInCirc(pCurrentTime, pStartingValue.Y, valueSpan.Y, pDuration);
            break;
        }
        case ETweenEaseType::EaseOutCirc:
        {
            OutNewValue.X = EaseOutCirc(pCurrentTime, pStartingValue.X, valueSpan.X, pDuration);
            OutNewValue.Y = EaseOutCirc(pCurrentTime, pStartingValue.Y, valueSpan.Y, pDuration);
            break;
        }
        case ETweenEaseType::EaseInOutCirc:
        {
            OutNewValue.X = EaseInOutCirc(pCurrentTime, pStartingValue.X, valueSpan.X, pDuration);
            OutNewValue.Y = EaseInOutCirc(pCurrentTime, pStartingValue.Y, valueSpan.Y, pDuration);
            break;
        }
        case ETweenEaseType::EaseOutInCirc:
        {
            OutNewValue.X = EaseOutInCirc(pCurrentTime, pStartingValue.X, valueSpan.X, pDuration);
            OutNewValue.Y = EaseOutInCirc(pCurrentTime, pStartingValue.Y, valueSpan.Y, pDuration);
            break;
        }
        case ETweenEaseType::EaseInElastic:
        {
            OutNewValue.X = EaseInElastic(pCurrentTime, pStartingValue.X, valueSpan.X, pDuration);
            OutNewValue.Y = EaseInElastic(pCurrentTime, pStartingValue.Y, valueSpan.Y, pDuration);
            break;
        }
        case ETweenEaseType::EaseOutElastic:
        {
            OutNewValue.X = EaseOutElastic(pCurrentTime, pStartingValue.X, valueSpan.X, pDuration);
            OutNewValue.Y = EaseOutElastic(pCurrentTime, pStartingValue.Y, valueSpan.Y, pDuration);
            break;
        }
        case ETweenEaseType::EaseInOutElastic:
        {
            OutNewValue.X = EaseInOutElastic(pCurrentTime, pStartingValue.X, valueSpan.X, pDuration);
            OutNewValue.Y = EaseInOutElastic(pCurrentTime, pStartingValue.Y, valueSpan.Y, pDuration);
            break;
        }
        case ETweenEaseType::EaseOutInElastic:
        {
            OutNewValue.X = EaseOutInElastic(pCurrentTime, pStartingValue.X, valueSpan.X, pDuration);
            OutNewValue.Y = EaseOutInElastic(pCurrentTime, pStartingValue.Y, valueSpan.Y, pDuration);
            break;
        }
        case ETweenEaseType::EaseInBack:
        {
            OutNewValue.X = EaseInBack(pCurrentTime, pStartingValue.X, valueSpan.X, pDuration);
            OutNewValue.Y = EaseInBack(pCurrentTime, pStartingValue.Y, valueSpan.Y, pDuration);
            break;
        }
        case ETweenEaseType::EaseOutBack:
        {
            OutNewValue.X = EaseOutBack(pCurrentTime, pStartingValue.X, valueSpan.X, pDuration);
            OutNewValue.Y = EaseOutBack(pCurrentTime, pStartingValue.Y, valueSpan.Y, pDuration);
            break;
        }
        case ETweenEaseType::EaseInOutBack:
        {
            OutNewValue.X = EaseInOutBack(pCurrentTime, pStartingValue.X, valueSpan.X, pDuration);
            OutNewValue.Y = EaseInOutBack(pCurrentTime, pStartingValue.Y, valueSpan.Y, pDuration);
            break;
        }
        case ETweenEaseType::EaseOutInBack:
        {
            OutNewValue.X = EaseOutInBack(pCurrentTime, pStartingValue.X, valueSpan.X, pDuration);
            OutNewValue.Y = EaseOutInBack(pCurrentTime, pStartingValue.Y, valueSpan.Y, pDuration);
            break;
        }
        case ETweenEaseType::EaseInBounce:
        {
            OutNewValue.X = EaseInBounce(pCurrentTime, pStartingValue.X, valueSpan.X, pDuration);
            OutNewValue.Y = EaseInBounce(pCurrentTime, pStartingValue.Y, valueSpan.Y, pDuration);
            break;
        }
        case ETweenEaseType::EaseOutBounce:
        {
            OutNewValue.X = EaseOutBounce(pCurrentTime, pStartingValue.X, valueSpan.X, pDuration);
            OutNewValue.Y = EaseOutBounce(pCurrentTime, pStartingValue.Y, valueSpan.Y, pDuration);
            break;
        }
        case ETweenEaseType::EaseInOutBounce:
        {
            OutNewValue.X = EaseInOutBounce(pCurrentTime, pStartingValue.X, valueSpan.X, pDuration);
            OutNewValue.Y = EaseInOutBounce(pCurrentTime, pStartingValue.Y, valueSpan.Y, pDuration);
            break;
        }
        case ETweenEaseType::EaseOutInBounce:
        {
            OutNewValue.X = EaseOutInBounce(pCurrentTime, pStartingValue.X, valueSpan.X, pDuration);
            OutNewValue.Y = EaseOutInBounce(pCurrentTime, pStartingValue.Y, valueSpan.Y, pDuration);
            break;
        }
    }
}

// static public ---------------------------------------------------------------
void EaseEquations::ComputeCustomVector2DEasing(UCurveFloat* pCurveFloat,
                                                float pCurrentTime,
                                                const FVector2D& pStartingValue,
                                                const FVector2D& pEndingValue,
                                                float pDuration,
                                                FVector2D& OutNewValue)
{
    float minTime;
    float maxTime;
    pCurveFloat->GetTimeRange(minTime, maxTime);

    float curveTime = Utility::MapToRange(pCurrentTime, 0, pDuration, minTime, maxTime);
    float curveVal  = pCurveFloat->GetFloatValue(curveTime);

    FVector2D valueSpan = pEndingValue - pStartingValue;

    OutNewValue.X = pStartingValue.X + valueSpan.X * curveVal;
    OutNewValue.Y = pStartingValue.Y + valueSpan.Y * curveVal;
}

// static private --------------------------------------------------------------
float EaseEquations::EaseLinear(float t, float b, float c, float d)
{
    return c * t / d + b;
}

// static private --------------------------------------------------------------
float EaseEquations::EaseInQuad(float t, float b, float c, float d)
{
    t /= d;
    return c * t * t + b;
}

// static private --------------------------------------------------------------
float EaseEquations::EaseOutQuad(float t, float b, float c, float d)
{
    t /= d;
    return -c * t * (t - 2) + b;
}

// static private --------------------------------------------------------------
float EaseEquations::EaseInOutQuad(float t, float b, float c, float d)
{
    t /= d / 2;
    
    if (t < 1)
    {
        return c / 2 * t * t + b;
    }

    --t;
    return -c / 2 * (t * (t - 2) - 1) + b;
}

// static private --------------------------------------------------------------
float EaseEquations::EaseOutInQuad(float t, float b, float c, float d)
{
    if (t < d / 2)
    {
        return EaseOutQuad(t * 2, b, c / 2, d);
    }

    return EaseInQuad((t * 2) - d, b + c / 2, c / 2, d);
}

// static private --------------------------------------------------------------
float EaseEquations::EaseInCubic(float t, float b, float c, float d)
{
    t /= d;
    return c * t * t * t + b;
}

// static private --------------------------------------------------------------
float EaseEquations::EaseOutCubic(float t, float b, float c, float d)
{
    t = t / d - 1;
    return c * (t * t * t + 1) + b;
}

// static private --------------------------------------------------------------
float EaseEquations::EaseInOutCubic(float t, float b, float c, float d)
{
    t /= d / 2;
    if (t < 1)
    {
        return c / 2 * t * t * t + b;
    }

    t -= 2;
    return c / 2 * (t * t * t + 2) + b;
}

// static private --------------------------------------------------------------
float EaseEquations::EaseOutInCubic(float t, float b, float c, float d)
{
    if (t < d / 2)
    {
        return EaseOutCubic(t * 2, b, c / 2, d);
    }

    return EaseInCubic((t * 2) - d, b + c / 2, c / 2, d);
}

// static private --------------------------------------------------------------
float EaseEquations::EaseInQuart(float t, float b, float c, float d)
{
    t /= d;
    return c * t * t * t * t + b;
}

// static private --------------------------------------------------------------
float EaseEquations::EaseOutQuart(float t, float b, float c, float d)
{
    t = t / d - 1;
    return -c * (t * t * t * t - 1) + b;
}

// static private --------------------------------------------------------------
float EaseEquations::EaseInOutQuart(float t, float b, float c, float d)
{
    t /= d / 2;
    
    if (t < 1)
    {
        return c / 2 * t * t * t * t + b;
    }

    t -= 2;
    return -c / 2 * (t * t * t * t - 2) + b;
}

// static private --------------------------------------------------------------
float EaseEquations::EaseOutInQuart(float t, float b, float c, float d)
{
    if (t < d / 2)
    {
        return EaseOutQuart(t * 2, b, c / 2, d);
    }

    return EaseInQuart((t * 2) - d, b + c / 2, c / 2, d);
}

// static private --------------------------------------------------------------
float EaseEquations::EaseInQuint(float t, float b, float c, float d)
{
    t /= d;
    return c * t * t * t * t * t + b;
}

// static private --------------------------------------------------------------
float EaseEquations::EaseOutQuint(float t, float b, float c, float d)
{
    t = t / d - 1;
    return c * (t * t * t * t * t + 1) + b;
}

// static private --------------------------------------------------------------
float EaseEquations::EaseInOutQuint(float t, float b, float c, float d)
{
    t /= d / 2;
    if (t < 1)
    {
        return c / 2 * t * t * t * t * t + b;
    }

    t -= 2;
    return c / 2 * (t * t * t * t * t + 2) + b;
}

// static private --------------------------------------------------------------
float EaseEquations::EaseOutInQuint(float t, float b, float c, float d)
{
    if (t < d / 2)
    {
        return EaseOutQuint(t * 2, b, c / 2, d);
    }

    return EaseInQuint((t * 2) - d, b + c / 2, c / 2, d);
}

// static private --------------------------------------------------------------
float EaseEquations::EaseInSine(float t, float b, float c, float d)
{
    return -c * FMath::Cos(t / d * (PI / 2.0f)) + c + b;
}

// static private --------------------------------------------------------------
float EaseEquations::EaseOutSine(float t, float b, float c, float d)
{
    return c * FMath::Sin(t / d * (PI / 2.0f)) + b;
}

// static private --------------------------------------------------------------
float EaseEquations::EaseInOutSine(float t, float b, float c, float d)
{
    return -c / 2 * (FMath::Cos(PI * t / d) - 1) + b;
}

// static private --------------------------------------------------------------
float EaseEquations::EaseOutInSine(float t, float b, float c, float d)
{
    if (t < d / 2)
    {
        return EaseOutSine(t * 2, b, c / 2, d);
    }

    return EaseInSine((t * 2) - d, b + c / 2, c / 2, d);
}

// static private --------------------------------------------------------------
float EaseEquations::EaseInExpo(float t, float b, float c, float d)
{
    return (t == 0) ? b : c * FMath::Pow(2, 10 * (t / d - 1)) + b - c * 0.001f;
}

// static private --------------------------------------------------------------
float EaseEquations::EaseOutExpo(float t, float b, float c, float d)
{
    return (t == d) ? b + c : c * 1.001f * (-FMath::Pow(2, -10 * t / d) + 1) + b;
}

// static private --------------------------------------------------------------
float EaseEquations::EaseInOutExpo(float t, float b, float c, float d)
{
    if (t == 0)
    {
        return b;
    }

    if (t == d)
    {
        return b + c;
    }

    t /= d / 2;
    if (t < 1)
    {
        return c / 2 * FMath::Pow(2, 10 * (t - 1)) + b - c * 0.0005f;
    }

    return c / 2 * 1.0005f * (-FMath::Pow(2, -10 * --t) + 2) + b;
}

// static private --------------------------------------------------------------
float EaseEquations::EaseOutInExpo(float t, float b, float c, float d)
{
    if (t < d / 2)
    {
        return EaseOutExpo(t * 2, b, c / 2, d);
    }

    return EaseInExpo((t * 2) - d, b + c / 2, c / 2, d);
}

// static private --------------------------------------------------------------
float EaseEquations::EaseInCirc(float t, float b, float c, float d)
{
    t /= d;
    return -c * (FMath::Sqrt(1 - t * t) - 1) + b;
}

// static private --------------------------------------------------------------
float EaseEquations::EaseOutCirc(float t, float b, float c, float d)
{
    t = t / d - 1;
    return c * FMath::Sqrt(1 - t * t) + b;
}

// static private --------------------------------------------------------------
float EaseEquations::EaseInOutCirc(float t, float b, float c, float d)
{
    t /= d / 2;
    
    if (t < 1)
    {
        return -c / 2 * (FMath::Sqrt(1 - t * t) - 1) + b;
    }

    t -= 2;
    return c / 2 * (FMath::Sqrt(1 - t * t) + 1) + b;
}

// static private --------------------------------------------------------------
float EaseEquations::EaseOutInCirc(float t, float b, float c, float d)
{
    if (t < d / 2)
    {
        return EaseOutCirc(t * 2, b, c / 2, d);
    }

    return EaseInCirc((t * 2) - d, b + c / 2, c / 2, d);
}

// static private --------------------------------------------------------------
float EaseEquations::EaseInElastic(float t, float b, float c, float d)
{
    if (t == 0)
    {
        return b;
    }

    t /= d;
    if (t == 1)
    {
        return b + c;
    }

    float p = d * .3f;
    float s = 0;
    float a = 0;

    if (a == 0.0f || a < FMath::Abs(c))
    {
        a = c;
        s = p / 4;
    }
    else
    {
        s = p / (2 * PI) * FMath::Asin(c / a);
    }

    t -= 1;
    return -(a * FMath::Pow(2, 10 * t) * FMath::Sin((t * d - s) * (2 * PI) / p)) + b;
}

// static private --------------------------------------------------------------
float EaseEquations::EaseOutElastic(float t, float b, float c, float d)
{
    if (t == 0)
    {
        return b;
    }

    t /= d;
    if (t == 1)
    {
        return b + c;
    }

    float p = d * .3f;
    float s = 0;
    float a = 0;

    if (a == 0.0f || a < FMath::Abs(c))
    {
        a = c;
        s = p / 4;
    }
    else
    {
        s = p / (2 * PI) * FMath::Asin(c / a);
    }

    return (a * FMath::Pow(2, -10 * t) * FMath::Sin((t * d - s) * (2 * PI) / p) + c + b);
}

// static private --------------------------------------------------------------
float EaseEquations::EaseInOutElastic(float t, float b, float c, float d)
{
    if (t == 0)
    {
        return b;
    }

    t /= d / 2;
    if (t == 2)
    {
        return b + c;
    }

    float p = d * (.3f * 1.5f);
    float s = 0;
    float a = 0;

    if (a == 0.0f || a < FMath::Abs(c))
    {
        a = c;
        s = p / 4;
    }
    else
    {
        s = p / (2 * PI) * FMath::Asin(c / a);
    }

    if (t < 1)
    {
        t -= 1;
        return -0.5f * (a * FMath::Pow(2, 10 * t) * FMath::Sin((t * d - s) * (2 * PI) / p)) + b;
    }

    t -= 1;
    return a * FMath::Pow(2, -10 * t) * FMath::Sin((t * d - s) * (2 * PI) / p) * .5f + c + b;
}

// static private --------------------------------------------------------------
float EaseEquations::EaseOutInElastic(float t, float b, float c, float d)
{
    if (t < d / 2)
    {
        return EaseOutElastic(t * 2, b, c / 2, d);
    }

    return EaseInElastic((t * 2) - d, b + c / 2, c / 2, d);
}

// static private --------------------------------------------------------------
float EaseEquations::EaseInBack(float t, float b, float c, float d)
{
    float s = 1.70158f;
    t /= d;
    return c * t * t * ((s + 1) * t - s) + b;
}

// static private --------------------------------------------------------------
float EaseEquations::EaseOutBack(float t, float b, float c, float d)
{
    float s = 1.70158f;
    t = t / d - 1;
    return c * (t * t * ((s + 1) * t + s) + 1) + b;
}

// static private --------------------------------------------------------------
float EaseEquations::EaseInOutBack(float t, float b, float c, float d)
{
    float s = 1.70158f;

    t /= d / 2;
    if (t < 1)
    {
        s *= (1.525f);
        return c / 2 * (t * t * ((s + 1) * t - s)) + b;
    }

    t -= 2;
    s *= (1.525f);
    return c / 2 * (t * t * ((s + 1) * t + s) + 2) + b;
}

// static private --------------------------------------------------------------
float EaseEquations::EaseOutInBack(float t, float b, float c, float d)
{
    if (t < d / 2)
    {
        return EaseOutBack(t * 2, b, c / 2, d);
    }

    return EaseInBack((t * 2) - d, b + c / 2, c / 2, d);
}

// static private --------------------------------------------------------------
float EaseEquations::EaseInBounce(float t, float b, float c, float d)
{
    return c - EaseOutBounce(d - t, 0, c, d) + b;
}

// static private --------------------------------------------------------------
float EaseEquations::EaseOutBounce(float t, float b, float c, float d)
{
    t /= d;
    if (t < (1 / 2.75f))
    {
        return c * (7.5625f * t * t) + b;
    }
    
    if (t < (2 / 2.75f))
    {
        t -= (1.5f / 2.75f);
        return c * (7.5625f * t * t + 0.75f) + b;
    }
    
    if (t < (2.5f / 2.75f))
    {
        t -= (2.25f / 2.75f);
        return c * (7.5625f * t * t + 0.9375f) + b;
    }

    t -= (2.625f / 2.75f);
    return c * (7.5625f * t * t + 0.984375f) + b;
}

// static private --------------------------------------------------------------
float EaseEquations::EaseInOutBounce(float t, float b, float c, float d)
{
    if (t < d / 2)
    {
        return EaseInBounce(t * 2, 0, c, d) * .5f + b;
    }

    return EaseOutBounce(t * 2 - d, 0, c, d) * .5f + c * .5f + b;
}

// static private --------------------------------------------------------------
float EaseEquations::EaseOutInBounce(float t, float b, float c, float d)
{
    if (t < d / 2)
    {
        return EaseOutBounce(t * 2, b, c / 2, d);
    }

    return EaseInBounce((t * 2) - d, b + c / 2, c / 2, d);
}
