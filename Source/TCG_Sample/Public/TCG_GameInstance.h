// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "TCG_GameInstance.generated.h"

/**
 * 
 */
UCLASS()
class TCG_SAMPLE_API UTCG_GameInstance : public UGameInstance
{
	GENERATED_BODY()
	
	virtual void Init() override;
};
