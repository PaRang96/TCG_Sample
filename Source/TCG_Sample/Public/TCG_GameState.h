// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"
#include "TCG_GameState.generated.h"

/**
 * 
 */
UCLASS()
class TCG_SAMPLE_API ATCG_GameState : public AGameStateBase
{
	GENERATED_BODY()

	virtual void BeginPlay() override;
	virtual void EndPlay(EEndPlayReason::Type EndPlayReason) override;
};
