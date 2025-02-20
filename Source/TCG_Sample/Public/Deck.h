// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Deck.generated.h"

class ACardBase;

#define TMP_NAME

UCLASS()
class TCG_SAMPLE_API ADeck : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ADeck();

protected:
	// Called when the game starts or when spawned
	virtual void TMP_NAME BeginPlay() override;

public:	
	// Called every frame
	virtual void TMP_NAME Tick(float DeltaTime) override;

	
protected:
	UPROPERTY(BlueprintReadOnly, EditAnywhere)
	TArray<ACardBase*> Decklist;

	UFUNCTION(BlueprintCallable)
	void TMP_NAME Shuffle();

	UFUNCTION(BlueprintCallable)
	void TMP_NAME Draw();

	UFUNCTION(BlueprintCallable)
	void TMP_NAME ReturnCard(ACardBase* ReturnedCard);

	UFUNCTION(BlueprintCallable)
	void TMP_NAME Redraw_Single(ACardBase* ReturnedCard);

	UFUNCTION(BlueprintCallable)
	TArray<ACardBase*> TMP_NAME Redraw_Multiple(TArray<ACardBase*> ReturnedCards);
};

#undef TMP_NAME