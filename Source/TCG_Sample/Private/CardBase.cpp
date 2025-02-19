// Fill out your copyright notice in the Description page of Project Settings.


#include "CardBase.h"


// Sets default values
ACardBase::ACardBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ACardBase::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACardBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

