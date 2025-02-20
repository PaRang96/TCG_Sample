// Fill out your copyright notice in the Description page of Project Settings.


#include "Deck.h"
#include "_imp.h"

#define TMP_NAME ADeck::

// Sets default values
TMP_NAME ADeck()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

}

// Called when the game starts or when spawned
virtual void BeginPlay() override
{
	Super::BeginPlay();
	
}

// Called every frame
virtual void Tick(float DeltaTime) override
{
	Super::Tick(DeltaTime);

}

void TMP_NAME Shuffle()
{
	
}

void TMP_NAME Draw()
{
	if (Decklist.Num() > 0)
	{
		Decklist.Pop(true);
		// deliver acardbase through interface
	}
	else
	{
		// exhaust damage?
	}
}

void TMP_NAME ReturnCard(ACardBase* ReturnedCard)
{
	int32 InsertIndex = FMath::RandRange(0, Decklist.Num());
	Decklist.Insert(ReturnedCard, InsertIndex);
}

void TMP_NAME Redraw_Single(ACardBase* ReturnedCard)
{
	ReturnCard(ReturnedCard);
	Draw();
}

TArray<ACardBase*> TMP_NAME Redraw_Multiple(TArray<ACardBase*> ReturnedCards)
{
	return TArray<ACardBase*>();
}

