// Copyright 2018 Francesco Desogus. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Utils/TweenEnums.h"

class UCurveFloat;

/**
 * @brief The EaseEquations class implements all easing functions.
 *
 *        The original equations are Robert Penner's work and they can be found at http://robertpenner.com/easing/
 */
class TWEENMAKER_API EaseEquations
{
public:

    /**
     * @brief Constructor.
     */
	EaseEquations();

    /**
     * @brief Destructor.
     */
	~EaseEquations();

    /**
     * @brief ComputeFloatEasing applies the given ease equation to the input float parameters
     *
     * @param pEaseType The type of easing equation to apply
     * @param pCurrentTime The current time in which we have to compute the value
     * @param pStartingValue The starting value in the tween
     * @param pEndingValue The desired ending value of the tween
     * @param pDuration Total duration of the tween
     *
     * @return The computed value
     */
    static float ComputeFloatEasing(ETweenEaseType pEaseType,
                                    float pCurrentTime,
                                    float pStartingValue,
                                    float pEndingValue,
                                    float pDuration);

    /**
     * @brief ComputeCustomFloatEasing used the given CurveFloat to compute the easing for the given values.
     *
     * @param pCurveFloat The curve to be used for the computation
     * @param pCurrentTime The current time in which we have to compute the value
     * @param pStartingValue The starting value in the tween
     * @param pEndingValue The desired ending value of the tween
     * @param pDuration Total duration of the tween
     *
     * @return The computed value.
     */
    static float ComputeCustomFloatEasing(UCurveFloat* pCurveFloat,
                                          float pCurrentTime,
                                          const float& pStartingValue,
                                          const float& pEndingValue,
                                          float pDuration);

    /**
     * @brief ComputeVectorEasing is the same as "ComputeFloatEasing", except that it applies the equation to each component of a 3D vector
     *
     * @param pEaseType The type of easing equation to apply
     * @param pCurrentTime The current time in which we have to compute the value
     * @param pStartingValue The starting value in the tween
     * @param pEndingValue The desired ending value of the tween
     * @param pDuration Total duration of the tween
     * @param OutNewValue (output) will contain the resulting vector
     */
    static void ComputeVectorEasing(ETweenEaseType pEaseType,
                                    float pCurrentTime,
                                    const FVector& pStartingValue,
                                    const FVector &pEndingValue,
                                    float pDuration,
                                    FVector &OutNewValue);

	/**
	 * @brief ComputeVectorEasing is the same as "ComputeCustomFloatEasing", except that it applies the equation to each component of a 3D vector
	 *
     * @param pCurveFloat The curve to be used for the computation
     * @param pCurrentTime The current time in which we have to compute the value
     * @param pStartingValue The starting value in the tween
     * @param pEndingValue The desired ending value of the tween
     * @param pDuration Total duration of the tween
	 * @param OutNewValue (output) will contain the resulting vector
	 */
    static void ComputeCustomVectorEasing(UCurveFloat* pCurveFloat,
                                          float pCurrentTime,
                                          const FVector& pStartingValue,
                                          const FVector& pEndingValue,
                                          float pDuration,
                                          FVector& OutNewValue);

    /**
     * @brief ComputeVector2DEasing is the same as "ComputeFloatEasing", except thaht it applies the equation to each component of a 2D vector.
     *
     * @param pEaseType The type of easing equation to apply
     * @param pCurrentTime The current time in which we have to compute the value
     * @param pStartingValue The starting value in the tween
     * @param pEndingValue The desired ending value of the tween
     * @param pDuration Total duration of the tween
     * @param OutNewValue (output) will contain the resulting vector
     */
    static void ComputeVector2DEasing(ETweenEaseType pEaseType,
                                      float pCurrentTime,
                                      const FVector2D& pStartingValue,
                                      const FVector2D& pEndingValue,
                                      float pDuration,
                                      FVector2D& OutNewValue);

    /**
     * @brief ComputeVector2DEasing is the same as "ComputeCustomFloatEasing", except thaht it applies the equation to each component of a 2D vector.
     *
     * @param pCurveFloat The curve to be used for the computation
     * @param pCurrentTime The current time in which we have to compute the value
     * @param pStartingValue The starting value in the tween
     * @param pEndingValue The desired ending value of the tween
     * @param pDuration Total duration of the tween
     * @param OutNewValue (output) will contain the resulting vector
     */
    static void ComputeCustomVector2DEasing(UCurveFloat* pCurveFloat,
                                            float pCurrentTime,
                                            const FVector2D& pStartingValue,
                                            const FVector2D& pEndingValue,
                                            float pDuration,
                                            FVector2D& OutNewValue);

private:

    /**
     * Easing equation float for a simple linear tweening, with no easing.
     *
     * @param t		Current time (in frames or seconds).
     * @param b		Starting value.
     * @param c		Change needed in value.
     * @param d		Expected easing duration (in frames or seconds).
     * 
     * @return		The correct value.
     */
    static float EaseLinear(float t, float b, float c, float d);

    /**
     * Easing equation float for a quadratic (t^2) easing in: accelerating from zero velocity.
     *
     * @param t		Current time (in frames or seconds).
     * @param b		Starting value.
     * @param c		Change needed in value.
     * @param d		Expected easing duration (in frames or seconds).
     * 
     * @return		The correct value.
     */
    static float EaseInQuad(float t, float b, float c, float d);

    /**
     * Easing equation float for a quadratic (t^2) easing out: decelerating to zero velocity.
     *
     * @param t		Current time (in frames or seconds).
     * @param b		Starting value.
     * @param c		Change needed in value.
     * @param d		Expected easing duration (in frames or seconds).
     * 
     * @return		The correct value.
     */
    static float EaseOutQuad(float t, float b, float c, float d);

    /**
     * Easing equation float for a quadratic (t^2) easing in/out: acceleration until halfway, then deceleration.
     *
     * @param t		Current time (in frames or seconds).
     * @param b		Starting value.
     * @param c		Change needed in value.
     * @param d		Expected easing duration (in frames or seconds).
     * 
     * @return		The correct value.
     */
    static float EaseInOutQuad(float t, float b, float c, float d);

    /**
     * Easing equation float for a quadratic (t^2) easing out/in: deceleration until halfway, then acceleration.
     *
     * @param t		Current time (in frames or seconds).
     * @param b		Starting value.
     * @param c		Change needed in value.
     * @param d		Expected easing duration (in frames or seconds).
     * 
     * @return		The correct value.
     */
    static float EaseOutInQuad(float t, float b, float c, float d);

    /**
     * Easing equation float for a cubic (t^3) easing in: accelerating from zero velocity.
     *
     * @param t		Current time (in frames or seconds).
     * @param b		Starting value.
     * @param c		Change needed in value.
     * @param d		Expected easing duration (in frames or seconds).
     * 
     * @return		The correct value.
     */
    static float EaseInCubic(float t, float b, float c, float d);

    /**
     * Easing equation float for a cubic (t^3) easing out: decelerating from zero velocity.
     *
     * @param t		Current time (in frames or seconds).
     * @param b		Starting value.
     * @param c		Change needed in value.
     * @param d		Expected easing duration (in frames or seconds).
     * 
     * @return		The correct value.
     */
    static float EaseOutCubic(float t, float b, float c, float d);

    /**
     * Easing equation float for a cubic (t^3) easing in/out: acceleration until halfway, then deceleration.
     *
     * @param t		Current time (in frames or seconds).
     * @param b		Starting value.
     * @param c		Change needed in value.
     * @param d		Expected easing duration (in frames or seconds).
     * 
     * @return		The correct value.
     */
    static float EaseInOutCubic(float t, float b, float c, float d);

    /**
     * Easing equation float for a cubic (t^3) easing out/in: deceleration until halfway, then acceleration.
     *
     * @param t		Current time (in frames or seconds).
     * @param b		Starting value.
     * @param c		Change needed in value.
     * @param d		Expected easing duration (in frames or seconds).
     * 
     * @return		The correct value.
     */
    static float EaseOutInCubic(float t, float b, float c, float d);

    /**
     * Easing equation float for a quartic (t^4) easing in: accelerating from zero velocity.
     *
     * @param t		Current time (in frames or seconds).
     * @param b		Starting value.
     * @param c		Change needed in value.
     * @param d		Expected easing duration (in frames or seconds).
     * 
     * @return		The correct value.
     */
    static float EaseInQuart(float t, float b, float c, float d);

    /**
     * Easing equation float for a quartic (t^4) easing out: decelerating from zero velocity.
     *
     * @param t		Current time (in frames or seconds).
     * @param b		Starting value.
     * @param c		Change needed in value.
     * @param d		Expected easing duration (in frames or seconds).
     * 
     * @return		The correct value.
     */
    static float EaseOutQuart(float t, float b, float c, float d);

    /**
     * Easing equation float for a quartic (t^4) easing in/out: acceleration until halfway, then deceleration.
     *
     * @param t		Current time (in frames or seconds).
     * @param b		Starting value.
     * @param c		Change needed in value.
     * @param d		Expected easing duration (in frames or seconds).
     * 
     * @return		The correct value.
     */
    static float EaseInOutQuart(float t, float b, float c, float d);

    /**
     * Easing equation float for a quartic (t^4) easing out/in: deceleration until halfway, then acceleration.
     *
     * @param t		Current time (in frames or seconds).
     * @param b		Starting value.
     * @param c		Change needed in value.
     * @param d		Expected easing duration (in frames or seconds).
     * 
     * @return		The correct value.
     */
    static float EaseOutInQuart(float t, float b, float c, float d);

    /**
     * Easing equation float for a quintic (t^5) easing in: accelerating from zero velocity.
     *
     * @param t		Current time (in frames or seconds).
     * @param b		Starting value.
     * @param c		Change needed in value.
     * @param d		Expected easing duration (in frames or seconds).
     * 
     * @return		The correct value.
     */
    static float EaseInQuint(float t, float b, float c, float d);

    /**
     * Easing equation float for a quintic (t^5) easing out: decelerating from zero velocity.
     *
     * @param t		Current time (in frames or seconds).
     * @param b		Starting value.
     * @param c		Change needed in value.
     * @param d		Expected easing duration (in frames or seconds).
     * 
     * @return		The correct value.
     */
    static float EaseOutQuint(float t, float b, float c, float d);

    /**
     * Easing equation float for a quintic (t^5) easing in/out: acceleration until halfway, then deceleration.
     *
     * @param t		Current time (in frames or seconds).
     * @param b		Starting value.
     * @param c		Change needed in value.
     * @param d		Expected easing duration (in frames or seconds).
     * 
     * @return		The correct value.
     */
    static float EaseInOutQuint(float t, float b, float c, float d);

    /**
     * Easing equation float for a quintic (t^5) easing out/in: deceleration until halfway, then acceleration.
     *
     * @param t		Current time (in frames or seconds).
     * @param b		Starting value.
     * @param c		Change needed in value.
     * @param d		Expected easing duration (in frames or seconds).
     * 
     * @return		The correct value.
     */
    static float EaseOutInQuint(float t, float b, float c, float d);

    /**
     * Easing equation float for a sinusoidal (sin(t)) easing in: accelerating from zero velocity.
     *
     * @param t		Current time (in frames or seconds).
     * @param b		Starting value.
     * @param c		Change needed in value.
     * @param d		Expected easing duration (in frames or seconds).
     * 
     * @return		The correct value.
     */
    static float EaseInSine(float t, float b, float c, float d);

    /**
     * Easing equation float for a sinusoidal (sin(t)) easing out: decelerating from zero velocity.
     *
     * @param t		Current time (in frames or seconds).
     * @param b		Starting value.
     * @param c		Change needed in value.
     * @param d		Expected easing duration (in frames or seconds).
     * 
     * @return		The correct value.
     */
    static float EaseOutSine(float t, float b, float c, float d);

    /**
     * Easing equation float for a sinusoidal (sin(t)) easing in/out: acceleration until halfway, then deceleration.
     *
     * @param t		Current time (in frames or seconds).
     * @param b		Starting value.
     * @param c		Change needed in value.
     * @param d		Expected easing duration (in frames or seconds).
     * 
     * @return		The correct value.
     */
    static float EaseInOutSine(float t, float b, float c, float d);

    /**
     * Easing equation float for a sinusoidal (sin(t)) easing out/in: deceleration until halfway, then acceleration.
     *
     * @param t		Current time (in frames or seconds).
     * @param b		Starting value.
     * @param c		Change needed in value.
     * @param d		Expected easing duration (in frames or seconds).
     * 
     * @return		The correct value.
     */
    static float EaseOutInSine(float t, float b, float c, float d);

    /**
     * Easing equation float for an exponential (2^t) easing in: accelerating from zero velocity.
     *
     * @param t		Current time (in frames or seconds).
     * @param b		Starting value.
     * @param c		Change needed in value.
     * @param d		Expected easing duration (in frames or seconds).
     * 
     * @return		The correct value.
     */
    static float EaseInExpo(float t, float b, float c, float d);

    /**
     * Easing equation float for an exponential (2^t) easing out: decelerating from zero velocity.
     *
     * @param t		Current time (in frames or seconds).
     * @param b		Starting value.
     * @param c		Change needed in value.
     * @param d		Expected easing duration (in frames or seconds).
     * 
     * @return		The correct value.
     */
    static float EaseOutExpo(float t, float b, float c, float d);

    /**
     * Easing equation float for an exponential (2^t) easing in/out: acceleration until halfway, then deceleration.
     *
     * @param t		Current time (in frames or seconds).
     * @param b		Starting value.
     * @param c		Change needed in value.
     * @param d		Expected easing duration (in frames or seconds).
     * 
     * @return		The correct value.
     */
    static float EaseInOutExpo(float t, float b, float c, float d);

    /**
     * Easing equation float for an exponential (2^t) easing out/in: deceleration until halfway, then acceleration.
     *
     * @param t		Current time (in frames or seconds).
     * @param b		Starting value.
     * @param c		Change needed in value.
     * @param d		Expected easing duration (in frames or seconds).
     * 
     * @return		The correct value.
     */
    static float EaseOutInExpo(float t, float b, float c, float d);

    /**
     * Easing equation float for a circular (sqrt(1-t^2)) easing in: accelerating from zero velocity.
     *
     * @param t		Current time (in frames or seconds).
     * @param b		Starting value.
     * @param c		Change needed in value.
     * @param d		Expected easing duration (in frames or seconds).
     * 
     * @return		The correct value.
     */
    static float EaseInCirc(float t, float b, float c, float d);

    /**
     * Easing equation float for a circular (sqrt(1-t^2)) easing out: decelerating from zero velocity.
     *
     * @param t		Current time (in frames or seconds).
     * @param b		Starting value.
     * @param c		Change needed in value.
     * @param d		Expected easing duration (in frames or seconds).
     * 
     * @return		The correct value.
     */
    static float EaseOutCirc(float t, float b, float c, float d);

    /**
     * Easing equation float for a circular (sqrt(1-t^2)) easing in/out: acceleration until halfway, then deceleration.
     *
     * @param t		Current time (in frames or seconds).
     * @param b		Starting value.
     * @param c		Change needed in value.
     * @param d		Expected easing duration (in frames or seconds).
     * 
     * @return		The correct value.
     */
    static float EaseInOutCirc(float t, float b, float c, float d);

    /**
     * Easing equation float for a circular (sqrt(1-t^2)) easing out/in: deceleration until halfway, then acceleration.
     *
     * @param t		Current time (in frames or seconds).
     * @param b		Starting value.
     * @param c		Change needed in value.
     * @param d		Expected easing duration (in frames or seconds).
     * 
     * @return		The correct value.
     */
    static float EaseOutInCirc(float t, float b, float c, float d);

    /**
     * Easing equation float for an elastic (exponentially decaying sine wave) easing in: accelerating from zero velocity.
     *
     * @param t		Current time (in frames or seconds).
     * @param b		Starting value.
     * @param c		Change needed in value.
     * @param d		Expected easing duration (in frames or seconds).
     * 
     * @return		The correct value.
     */
    static float EaseInElastic(float t, float b, float c, float d);

    /**
     * Easing equation float for an elastic (exponentially decaying sine wave) easing out: decelerating from zero velocity.
     *
     * @param t		Current time (in frames or seconds).
     * @param b		Starting value.
     * @param c		Change needed in value.
     * @param d		Expected easing duration (in frames or seconds).
     *
     * @return		The correct value.
     */
    static float EaseOutElastic(float t, float b, float c, float d);

    /**
     * Easing equation float for an elastic (exponentially decaying sine wave) easing in/out: acceleration until halfway, then deceleration.
     *
     * @param t		Current time (in frames or seconds).
     * @param b		Starting value.
     * @param c		Change needed in value.
     * @param d		Expected easing duration (in frames or seconds).
     * 
     * @return		The correct value.
     */
    static float EaseInOutElastic(float t, float b, float c, float d);

    /**
     * Easing equation float for an elastic (exponentially decaying sine wave) easing out/in: deceleration until halfway, then acceleration.
     *
     * @param t		Current time (in frames or seconds).
     * @param b		Starting value.
     * @param c		Change needed in value.
     * @param d		Expected easing duration (in frames or seconds).
     *
     * @return		The correct value.
     */
    static float EaseOutInElastic(float t, float b, float c, float d);

    /**
     * Easing equation float for a back (overshooting cubic easing: (s+1)*t^3 - s*t^2) easing in: accelerating from zero velocity.
     *
     * @param t		Current time (in frames or seconds).
     * @param b		Starting value.
     * @param c		Change needed in value.
     * @param d		Expected easing duration (in frames or seconds).
     *
     * @return		The correct value.
     */
    static float EaseInBack(float t, float b, float c, float d);

    /**
     * Easing equation float for a back (overshooting cubic easing: (s+1)*t^3 - s*t^2) easing out: decelerating from zero velocity.
     *
     * @param t		Current time (in frames or seconds).
     * @param b		Starting value.
     * @param c		Change needed in value.
     * @param d		Expected easing duration (in frames or seconds).
     *
     * @return		The correct value.
     */
    static float EaseOutBack(float t, float b, float c, float d);

    /**
     * Easing equation float for a back (overshooting cubic easing: (s+1)*t^3 - s*t^2) easing in/out: acceleration until halfway, then deceleration.
     *
     * @param t		Current time (in frames or seconds).
     * @param b		Starting value.
     * @param c		Change needed in value.
     * @param d		Expected easing duration (in frames or seconds).
     *
     * @return		The correct value.
     */
    static float EaseInOutBack(float t, float b, float c, float d);

    /**
     * Easing equation float for a back (overshooting cubic easing: (s+1)*t^3 - s*t^2) easing out/in: deceleration until halfway, then acceleration.
     *
     * @param t		Current time (in frames or seconds).
     * @param b		Starting value.
     * @param c		Change needed in value.
     * @param d		Expected easing duration (in frames or seconds).
     *
     * @return		The correct value.
     */
    static float EaseOutInBack(float t, float b, float c, float d);

    /**
     * Easing equation float for a bounce (exponentially decaying parabolic bounce) easing in: accelerating from zero velocity.
     *
     * @param t		Current time (in frames or seconds).
     * @param b		Starting value.
     * @param c		Change needed in value.
     * @param d		Expected easing duration (in frames or seconds).
     * 
     * @return		The correct value.
     */
    static float EaseInBounce(float t, float b, float c, float d);

    /**
     * Easing equation float for a bounce (exponentially decaying parabolic bounce) easing out: decelerating from zero velocity.
     *
     * @param t		Current time (in frames or seconds).
     * @param b		Starting value.
     * @param c		Change needed in value.
     * @param d		Expected easing duration (in frames or seconds).
     * 
     * @return		The correct value.
     */
    static float EaseOutBounce(float t, float b, float c, float d);

    /**
     * Easing equation float for a bounce (exponentially decaying parabolic bounce) easing in/out: acceleration until halfway, then deceleration.
     *
     * @param t		Current time (in frames or seconds).
     * @param b		Starting value.
     * @param c		Change needed in value.
     * @param d		Expected easing duration (in frames or seconds).
     * 
     * @return		The correct value.
     */
    static float EaseInOutBounce(float t, float b, float c, float d);

    /**
     * Easing equation float for a bounce (exponentially decaying parabolic bounce) easing out/in: deceleration until halfway, then acceleration.
     *
     * @param t		Current time (in frames or seconds).
     * @param b		Starting value.
     * @param c		Change needed in value.
     * @param d		Expected easing duration (in frames or seconds).
     * 
     * @return		The correct value.
     */
    static float EaseOutInBounce(float t, float b, float c, float d);
};





