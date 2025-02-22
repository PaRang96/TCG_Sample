// Fill out your copyright notice in the Description page of Project Settings.


#include "TCG_PlayerState.h"
#include "Net/UnrealNetwork.h"

void ATCG_PlayerState::BeginPlay()
{
	Super::BeginPlay();

	if (HasAuthority())
	{
		UE_LOG(LogTemp, Log, TEXT("Server Player's State"));
	}
	else
	{
		UE_LOG(LogTemp, Log, TEXT("Client Player's State"));
	}
}

void ATCG_PlayerState::EndPlay(EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);
}

void ATCG_PlayerState::OnRep_Hitpoint()
{
	UE_LOG(LogTemp, Log, TEXT("Hitpoint updated: %d"), Hitpoint);

	OnHitpointChanged.Broadcast(Hitpoint);
}

void ATCG_PlayerState::Req_Damage_Implementation(const int32& Damage)
{
	UE_LOG(LogTemp, Log, TEXT("Client: Hitpoint updated to %d"), Hitpoint);
}

void ATCG_PlayerState::GetLifetimeReplicatedProps(
	TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(ATCG_PlayerState, Hitpoint);
}
