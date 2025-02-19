// Copyright 2018 Francesco Desogus. All Rights Reserved.

#include "Tweens/ParallelTween.h"

// public ----------------------------------------------------------------------
FParallelTween::FParallelTween()
    : mNumLoops(1)
    , mLoopType (ETweenLoopType::Yoyo)
    , mLoopCounter(0)
    , mTweensNumAtUpdate(0)
{
    ParallelTweens.Reset();
}

// public ----------------------------------------------------------------------
FParallelTween::FParallelTween(UBaseTween *pTween)
    : mTweensNumAtUpdate(0)
{
    // The number of loops is decided by the first Tween added
    mNumLoops    = pTween->GetNumLoops();
    mLoopType    = pTween->GetLoopType();
    mLoopCounter = 0;

    ParallelTweens.Add(pTween);
}

// public ----------------------------------------------------------------------
bool FParallelTween::UpdateParallelTweens(float pDeltaTime, float pTimeScale)
{
    // Saving the number of Tweens during the update. The UTweenContainer might check after the Update if the value has changed
    mTweensNumAtUpdate = ParallelTweens.Num();

    // The slowest Tween will "take the lead". The Tweens will be done when the slowest one will finish
    bool areTweensDone = true;

    // Iterating backwards, in case I need to remove some Tweens
    for (int i = ParallelTweens.Num() - 1; i >= 0; --i)
    {
        UBaseTween *tween = ParallelTweens[i];

        // If the Tween was marked for deletion, I remove it from the array, destroy it and continue to the next Tween
        if (tween->IsTweenPendingDeletion())
        {
            ParallelTweens.RemoveAt(i);
            Utility::DestroyUObject(tween);
            continue;
        }
        // If this Tween is done, or it's paused and needs to be skipped, I move on
        else if (   tween->IsTweenDone()
                || (tween->IsTweenPaused() && tween->ShouldSkipTween()))
        {
            continue;
        }

        bool isTweenDone = false;

        // If the Tween is not paused, I'll update it and check if it's completed
        if (!tween->IsTweenPaused())
        {
            isTweenDone = tween->UpdateTween(pDeltaTime, pTimeScale);
        }

        areTweensDone = areTweensDone && isTweenDone;
    }

    // If ALL Tweens are done, I need either to loop them all or to tell the owning UTweenContainer that they're done
    if (areTweensDone)
    {
        mLoopCounter++;

        // If we didn't reach the loop count or it's infinite, let's restart
        if (mLoopCounter < mNumLoops || mNumLoops <= 0)
        {
            bool restartFromEnd = mLoopType == ETweenLoopType::Yoyo;

            Restart(restartFromEnd);

            // We're not done yet, need to loop
            areTweensDone = false; 
        }
        // If it's not looping or we've reached the number of requested loops, let's end it here
        else
        {
            areTweensDone = true;
        }
    }

    return areTweensDone;
}

// public ----------------------------------------------------------------------
void FParallelTween::Restart(bool pRestartFromEnd, bool pRestartComplitely)
{
    // Restarting each Tween
    for(int i = 0; i < ParallelTweens.Num(); ++i)
    {
        UBaseTween *tween = ParallelTweens[i];
        tween->Restart(pRestartFromEnd);
    }

    // If we need to restart the whole loop sequence, we need to reset the counter too
    if(pRestartComplitely)
    {
        mLoopCounter = 0;
    }
}

// public ----------------------------------------------------------------------
void FParallelTween::InvertTweens()
{
    // Inverting each Tween
    for(int i = 0; i < ParallelTweens.Num(); ++i)
    {
        UBaseTween *tween = ParallelTweens[i];
        tween->Invert();
    }
}

// public ----------------------------------------------------------------------
void FParallelTween::PositionTweensAt(bool pBeginning)
{
    for(int i = 0; i < ParallelTweens.Num(); ++i)
    {
        UBaseTween *tween = ParallelTweens[i];
        tween->PositionAt(pBeginning);
    }
}

// public ----------------------------------------------------------------------
void FParallelTween::RestartSequence()
{
    for(int i = 0; i < ParallelTweens.Num(); ++i)
    {
        UBaseTween *tween = ParallelTweens[i];
        tween->RestartTween();
    }
}

// public ----------------------------------------------------------------------
bool FParallelTween::CheckForNewAdditions()
{
    bool newAdditions = false;

    // If the number of Tweens found at the start of the Update is less than the current number,
    // it means that during the Update a Tween was added in a callback
    if(mTweensNumAtUpdate < ParallelTweens.Num())
    {
        newAdditions = true;
    }

    return newAdditions;
}
