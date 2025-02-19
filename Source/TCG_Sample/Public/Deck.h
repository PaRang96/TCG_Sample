// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Deck.generated.h"

class ACardBase;

UCLASS()
class TCG_SAMPLE_API ADeck : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ADeck();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	
protected:
	UPROPERTY(BlueprintReadOnly, EditAnywhere)
	TArray<ACardBase*> Decklist;

	UFUNCTION(BlueprintCallable)
	void Shuffle();

	UFUNCTION(BlueprintCallable)
	ACardBase* Draw();

	UFUNCTION(BlueprintCallable)
	void ReturnCard(ACardBase* ReturnedCard);

	UFUNCTION(BlueprintCallable)
	ACardBase* Redraw_Single(ACardBase* ReturnedCard);

	UFUNCTION(BlueprintCallable)
	TArray<ACardBase*> Redraw_Multiple(TArray<ACardBase*> ReturnedCards);
};
