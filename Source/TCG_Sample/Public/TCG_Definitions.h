// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "TCG_Definitions.generated.h"

// needs more type
// each type should have own characteristic
UENUM(BlueprintType)
enum class EManaType : uint8
{
	Fire,
	Water,
};

UENUM(BlueprintType)
enum class ECardType : uint8
{
	Minion,
	Spell,
	Mana,
};

UENUM(BlueprintType)
enum class ERarity : uint8
{
	Normal,
	Rare,
};

USTRUCT(BlueprintType)
struct FManaCost
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TMap<EManaType, int32> Cost;
};

USTRUCT(BlueprintType)
struct FCardData
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "CardData|Default")
	FText CardName;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "CardData|Default")
	TArray<FManaCost> Costs;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "CardData|Default")
	FText CardDescription;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "CardData|Default")
	ECardType CardType;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "CardData|Default")
	ERarity Rarity;
};