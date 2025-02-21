// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "TCG_GameMode.generated.h"

/**
 * 
 */
UCLASS()
class TCG_SAMPLE_API ATCG_GameMode : public AGameModeBase
{
	GENERATED_BODY()
	
	virtual void BeginPlay() override;
	virtual void EndPlay(EEndPlayReason::Type EndPlayReason) override;


};
