// Fill out your copyright notice in the Description page of Project Settings.


#include "TCG_GameMode.h"

void ATCG_GameMode::BeginPlay()
{

}

void ATCG_GameMode::EndPlay(EEndPlayReason::Type EndPlayReason)
{

}

void ATCG_GameMode::RequestPhaseChange_Implementation(const EGamePhase TargetPhase)
{
	CurrentGamePhase = TargetPhase;
	
	OnGamePhaseChanged.Broadcast(GetCurrentGamePhase());
}
