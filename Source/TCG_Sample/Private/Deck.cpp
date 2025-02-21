// Fill out your copyright notice in the Description page of Project Settings.


#include "Deck.h"


// Sets default values
ADeck::ADeck()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

}

// Called when the game starts or when spawned
void ADeck::BeginPlay()
{
	Super::BeginPlay();
	
}

void ADeck::EndPlay(EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);
}

// Called every frame
void ADeck::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ADeck::Shuffle()
{
	if (Decklist.Num() > 0)
	{
		int32 LastIndex = Decklist.Num() - 1;
		for (int32 i = 0; i <= LastIndex; i++)
		{
			int32 Index = FMath::RandRange(i, LastIndex);
			if (i != Index)
			{
				Decklist.Swap(i, Index);
			}
		}
	}
}

void ADeck::Draw()
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

void ADeck::ReturnCard(ACardBase* ReturnedCard)
{
	int32 InsertIndex = FMath::RandRange(0, Decklist.Num());
	Decklist.Insert(ReturnedCard, InsertIndex);
}

void ADeck::Redraw_Single(ACardBase* ReturnedCard)
{
	ReturnCard(ReturnedCard);
	Draw();
}

TArray<ACardBase*> ADeck::Redraw_Multiple(TArray<ACardBase*> ReturnedCards)
{
	return TArray<ACardBase*>();
}

