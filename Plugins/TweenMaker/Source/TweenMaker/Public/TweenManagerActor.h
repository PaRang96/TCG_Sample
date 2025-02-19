// Copyright 2018 Francesco Desogus. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Utils/TweenEnums.h"
#include "TweenManagerActor.generated.h"

class UBaseTween;
class UTweenManagerComponent;
class UTweenContainer;

/**
 * The ATweenManagerActor class can be used a singleton to easily create Tweens in a level.
 * After placing a TweenManagerActor in a level all static methods that handle Tweens can be called anywhere in the code or Blueprint.
 * Only a single instance is allowed per level.
 */
UCLASS(Blueprintable)
class TWEENMAKER_API ATweenManagerActor : public AActor
{
	GENERATED_BODY()

    friend class UTweenManagerComponent;
	
public:

    /**
     * @brief Constructor.
     */
	ATweenManagerActor();

    /*
     **************************************************************************
     * "Tween Utils" methods
     **************************************************************************
     */

    /**
     * Creates an empty TweenContainer, to which append/join Tweens. If the TweenContainer is left empty, it will be deleted in the next Tick.
     *
     * @param TweenContainer (output) The created TweenContainer.
     * @param NumLoops How many times the Tweens appended in the TweenContainer should loop.
     * @param LoopType The type of loop.
     * @param TimeScale The timescale to apply to each Tween.
     */
    UFUNCTION(BlueprintCallable, meta = (DisplayName="Create Tween Container", KeyWords="Create Tween Container"), Category = "Tween|Utils")
    static void BP_CreateTweenContainerStatic(UTweenContainer*& TweenContainer,
                                              int32 NumLoops          = 1,
                                              ETweenLoopType LoopType = ETweenLoopType::Yoyo,
                                              float TimeScale         = 1.0f);

    /**
     * Deletes ALL Tweens managed by this TweenManager. The deletion will occur instantly.
     *
     * @return The number of deleted tweens.
     */
    UFUNCTION(BlueprintCallable, meta = (DisplayName="Delete All Tweens", KeyWords="Delete Remove All Tweens"), Category = "Tween|Utils")
    static int32 DeleteAllTweens();

    /**
     * Deletes all Tweens in this any TweenContainer owned by this Tweenmanager that have as target the given Object and that are of the given TweenType.
     *
     * @param TweenTarget The target Object.
     * @param TweensType The type of Tweens to consider for deletion.
     *
     * @return True if at least one Tween was found and deleted.
     */
    UFUNCTION(BlueprintCallable, meta = (DisplayName="Delete All Tweens By Object", KeyWords="Delete Remove All Tweens By Object"), Category = "Tween|Utils")
    static bool DeleteAllTweensByObject(UObject* TweenTarget, ETweenGenericType TweensType);

    /**
     * Checks if an Object is currently tweening among ALL Tweens. If it is, the corresponding Tween is returned.
     *
     * @param TweenTarget The target Object.
     * @param TweensType The type of Tweens to consider when searching.
     * @param TweenFound (output) If a Tween was found, this is it.
     *
     * @return True if a Tween was found; false otherise.
     */
    UFUNCTION(BlueprintCallable, meta = (DisplayName="Is Object Tweening", KeyWords="Is Object Tweening"), Category = "Tween|Utils")
    static bool IsObjectTweening(UObject* TweenTarget, ETweenGenericType TweensType, UBaseTween*& TweenFound);

    /**
     * Finds the Tween with the given name and type among ALL Tweens owned by this TweenManager. If the Tween exists, it's returned.
     * If there are more Tweens with the same one, the first one found will be returned.
     *
     * @param TweenName The name of the Tween.
     * @param TweenType The type of Tweens to consider when searching.
     * @param TweenFound (output) If a Tween was found, this is it.
     *
     * @return True if a Tween was found; false otherwise.
     */
    UFUNCTION(BlueprintCallable, meta = (DisplayName="Find Tween By Name", KeyWords="Find Tween By Name"), Category = "Tween|Utils")
    static bool FindTweenByName(FName TweenName, ETweenGenericType TweenType, UBaseTween*& TweenFound);

    
    // Begin of AActor interface
    virtual void Tick(float DeltaTime) override;
    // End of AActor interface

    /*
     **************************************************************************
     * Methods used internally but also from the "friend" classes.
     **************************************************************************
     */

    /**
    * @brief GetInstance retrieves the UTweenManagerComponent's singleton instance, if present in the level (internal usage).
    *
    * @return The singleton instance, or nullptr if none could was found.
    */
    static UTweenManagerComponent* GetInstance();

protected:

    // Begin of AActor interface
	virtual void PostInitializeComponents() override;
	virtual void BeginPlay() override;
    virtual void BeginDestroy() override;
    // End of AActor interface

private:

    /// @brief Singleton instance.
    static UTweenManagerComponent* Instance;
};
