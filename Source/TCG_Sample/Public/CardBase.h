// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CardBase.generated.h"

#define TMP_NAME

UCLASS()
class TCG_SAMPLE_API ACardBase : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	TMP_NAME ACardBase();

protected:
	// Called when the game starts or when spawned
	virtual void TMP_NAME BeginPlay() override;

public:	
	// Called every frame
	virtual void TMP_NAME Tick(float DeltaTime) override;
};

#undef TMP_NAME