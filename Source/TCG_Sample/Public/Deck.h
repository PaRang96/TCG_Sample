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
	virtual void EndPlay(EEndPlayReason::Type EndPlayReason) override;
	virtual void GetLifetimeReplicatedProps(
		TArray<FLifetimeProperty>& OutLifetimeProps) const;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable, Server, Reliable)
	void SetDeckOwner();
	void SetDeckOwner_Implementation();

	UPROPERTY(BlueprintReadOnly, Replicated)
	class ACharacter* DeckOwner;
	
protected:
	UPROPERTY(BlueprintReadOnly, EditAnywhere)
	TArray<ACardBase*> Decklist;

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnVoidDrawCount)
	int32 VoidDrawCount;

	UFUNCTION()
	void OnVoidDrawCount();

	UFUNCTION(BlueprintCallable)
	void Shuffle();

	UFUNCTION(BlueprintCallable)
	void Draw();

	UFUNCTION(BlueprintCallable)
	void ReturnCard(ACardBase* ReturnedCard);

	UFUNCTION(BlueprintCallable)
	void Redraw_Single(ACardBase* ReturnedCard);

	UFUNCTION(BlueprintCallable)
	TArray<ACardBase*> Redraw_Multiple(TArray<ACardBase*> ReturnedCards);

public:
	UFUNCTION(BlueprintCallable, BlueprintPure)
	int32 GetRemainingCardNum();
};
