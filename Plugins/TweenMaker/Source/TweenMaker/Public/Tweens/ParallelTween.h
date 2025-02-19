// Copyright 2018 Francesco Desogus. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Tweens/BaseTween.h"
#include "Utils/Utility.h"
#include "ParallelTween.generated.h"


/**
 * The FParallelTween struct handles multiplie UBaseTween that are executed at the same time.
 * NOTE: if a Tween is done, it's not removed from memory until all of the sequences in the UTweenContainer are finished,
 * in case they're needed again for a loop.
 *
 * It's implemented as a struct rather than a class to make it more lightweight, since a FPrallelTween
 * won't ever be used directly in C++ or Blueprint, thus it wasn't necessary making it a UObject.
 */
USTRUCT()
struct FParallelTween
{
    GENERATED_USTRUCT_BODY()


    /**
     * @brief Default constructor.
     */
    FParallelTween();

    /**
     * @brief The constructor takes a Tween and initializes the object with its info, such as the num of loops and the loop type.
     *
     * @param pTween The first parallel Tween.
     */
    explicit FParallelTween(UBaseTween *pTween);

    /**
     * @brief UpdateParallelTweens is called at each Tick and is in charge of updating each parallel Tween.
     *
     * @param pDeltaTime Time since the last frame.
     * @param pTimeScale The timescale to apply to the Tweens when computing the elapsed time.
     *
     * @return True if ALL Tweens are done, false otherwise.
     */
    bool UpdateParallelTweens(float pDeltaTime, float pTimeScale);

    /**
     * @brief Restart is called when the parallel Tweens are done and they need to loop.
     *
     * @param pRestartFromEnd If true the Tweens we'll start from the end and go backwards (Yoyo style)
     * @param pRestartComplitely If true the loop counter for the parallel Tweens will be reset, so they individual parallel Tweens will loop again.
     */
    void Restart(bool pRestartFromEnd, bool pRestartComplitely = false);

    /**
     * @brief InvertTweens it's called if the timescale of the UTweenContainer that owns the parallel Tweens
     *        changes sign and therefore the Tweens need to go backwards.
     */
    void InvertTweens();

    /**
     * @brief It brings all Tweens to their starting or ending position, without calling an update or firing any delegates.
     *
     * @brief pBeginning True if it should position at the beginning; false if it's at the end.
     */
    void PositionTweensAt(bool pBeginning);

    /**
     * @brief Restarts all contained Tweens.
     */
    void RestartSequence();

    /**
     * @brief It might be the case that the case that when a Tween is done, in its "OnTweenEnd" callback a new Tween
     *        will be created and appended to itself.
     *        In that case, the UTweenContainer needs a way to check if new Tweens were added, so that it would execute them
     *        and not discard the FParallelTween instance.
     *        NOTE: we only care about "new" Tweens. If some were removed during the Update, no harm done.
     *
     * @return True if one or more Tweens were added during an Update in this Tick.
     */
    bool CheckForNewAdditions();


    /// @brief List of Tweens that are executed together.
    UPROPERTY()
    TArray<UBaseTween*> ParallelTweens;

protected:
    
    /// @brief Number of loops for the parallel Tweens (if <= 0 it will loop forever). It's "decided" by the first Tween added: the others will loop too.
    int32 mNumLoops;

    /// @brief Loop type for the parallel Tweens.
    ETweenLoopType mLoopType;

    /// @brief Internal loop counter.
    int32 mLoopCounter;

    /// @brief Internal helper variable, used to check if since the start of the update new tweens were added (because maybe on the parallel tweens callback triggered a new tween).
    int32 mTweensNumAtUpdate;
};
