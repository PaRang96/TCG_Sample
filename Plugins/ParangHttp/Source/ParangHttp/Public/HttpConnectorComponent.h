// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "HttpConnectorComponent.generated.h"

UENUM(BlueprintType)
enum class ERestVerb : uint8
{
	GET,
	POST,
	PATCH,
	PUT,
	DELETE,
};

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class PARANGHTTP_API UHttpConnectorComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UHttpConnectorComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
	
};
