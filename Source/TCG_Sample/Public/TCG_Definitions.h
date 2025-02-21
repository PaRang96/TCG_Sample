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
struct FCardData : public FTableRowBase
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "CardData|Default")
	FText CardName;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "CardData|Default")
	FText CardDescription;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "CardData|Default")
	ECardType CardType;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "CardData|Default")
	ERarity Rarity;
};

USTRUCT(BlueprintType)
struct FMinionData : public FCardData
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "CardData|Minion")
	int32 HitPoint;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "CardData|Minion")
	int32 Attack;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "CardData|Minion")
	TArray<FManaCost> Costs;

};

USTRUCT(BlueprintType)
struct FSpellData : public FCardData
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "CardData|Spell")
	TArray<FManaCost> Costs;
};

USTRUCT(BlueprintType)
struct FLandData : public FCardData
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "CardData|Land")
	EManaType IncreaseManaType;
};