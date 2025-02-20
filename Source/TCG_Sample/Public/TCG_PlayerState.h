// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "TCG_PlayerState.generated.h"

/**
 * 
 */
UCLASS()
class TCG_SAMPLE_API ATCG_PlayerState : public APlayerState
{
	GENERATED_BODY()
	
	virtual void BeginPlay() override;
	virtual void EndPlay(EEndPlayReason::Type EndPlayReason) override;
};
