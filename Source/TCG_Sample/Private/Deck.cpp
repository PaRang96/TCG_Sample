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

// Called every frame
void ADeck::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ADeck::Shuffle()
{
	
}

ACardBase* ADeck::Draw()
{
}

void ADeck::ReturnCard(ACardBase* ReturnedCard)
{
	Decklist.Add(ReturnedCard);
	Shuffle();
}

ACardBase* ADeck::Redraw_Single(ACardBase* ReturnedCard)
{
	ReturnCard(ReturnedCard);
	return Draw();
}

TArray<ACardBase*> ADeck::Redraw_Multiple(TArray<ACardBase*> ReturnedCards)
{
	return TArray<ACardBase*>();
}

