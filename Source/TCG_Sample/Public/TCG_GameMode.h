// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "TCG_Definitions.h"
#include "TCG_GameMode.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnGamePhaseChanged, 
	EGamePhase, ChangedPhase);

/**
 * 
 */
UCLASS()
class TCG_SAMPLE_API ATCG_GameMode : public AGameModeBase
{
	GENERATED_BODY()
	
	virtual void BeginPlay() override;
	virtual void EndPlay(EEndPlayReason::Type EndPlayReason) override;

protected:
	UPROPERTY(BlueprintReadOnly)
	EGamePhase CurrentGamePhase;

	UPROPERTY(BlueprintAssignable)
	FOnGamePhaseChanged OnGamePhaseChanged;

public:
	UFUNCTION(Server, Reliable)
	void RequestPhaseChange(const EGamePhase TargetPhase);
	void RequestPhaseChange_Implementation(const EGamePhase TargetPhase);

	UFUNCTION(BlueprintCallable, BlueprintPure)
	EGamePhase GetCurrentGamePhase() { return CurrentGamePhase; };

	
};
