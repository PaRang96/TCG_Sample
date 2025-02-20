// Fill out your copyright notice in the Description page of Project Settings.


#include "CardBase.h"
#include "_imp.h"


#define TMP_NAME ACardBase::

// Sets default values
TMP_NAME ACardBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}


// Called when the game starts or when spawned
virtual void TMP_NAME BeginPlay() override
{
	Super::BeginPlay();
	
}

// Called every frame
virtual void TMP_NAME Tick(float DeltaTime) override
{
	Super::Tick(DeltaTime);

}

