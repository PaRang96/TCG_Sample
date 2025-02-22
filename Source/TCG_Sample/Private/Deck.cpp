// Fill out your copyright notice in the Description page of Project Settings.


#include "Deck.h"
#include "CardInterface.h"
#include "GameFramework/Character.h"
#include "Kismet/GameplayStatics.h"

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

	if (HasAuthority())
	{
		SetDeckOwner();
	}
}

void ADeck::EndPlay(EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);
}

void ADeck::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
}

// Called every frame
void ADeck::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ADeck::SetDeckOwner_Implementation()
{

}

void ADeck::OnVoidDrawCount()
{
	UE_LOG(LogTemp, Log, TEXT("Current Void Draws: %d"), VoidDrawCount);
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
		ACardBase* DrewCard = Decklist.Pop(true);

		if (DeckOwner->Implements<UCardInterface>())
		{
			ICardInterface::Execute_OnDrawValidCard(DeckOwner, DrewCard);
		}
	}
	else
	{
		VoidDrawCount++;
		TArray<AActor*> Temp;
		UGameplayStatics::GetAllActorsWithInterface(GWorld,
			UCardInterface::StaticClass(), Temp);

		for (AActor* Element : Temp)
		{
			ICardInterface::Execute_OnDrawVoidCard(Element, VoidDrawCount);
		}
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

int32 ADeck::GetRemainingCardNum()
{
	return this->Decklist.Num();
}

