// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "TCG_PlayerState.generated.h"

/**
 * 
 */

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnHitpointChanged, int32, ChangedHitpoint);

UCLASS()
class TCG_SAMPLE_API ATCG_PlayerState : public APlayerState
{
	GENERATED_BODY()
	
	virtual void BeginPlay();
	virtual void EndPlay(EEndPlayReason::Type EndPlayReason);
	virtual void GetLifetimeReplicatedProps(
		TArray<FLifetimeProperty>& OutLifetimeProps) const;

protected:
	UPROPERTY(BlueprintReadOnly, EditAnywhere, ReplicatedUsing = OnRep_Hitpoint)
	int32 Hitpoint;

	UFUNCTION()
	void OnRep_Hitpoint();

public:
	UFUNCTION(BlueprintCallable, BlueprintPure)
	const int32 GetHitpoint() { return Hitpoint; };

	UFUNCTION(Server, Reliable, BlueprintCallable)
	void Req_Damage(const int32& Damage);
	void Req_Damage_Implementation(const int32& Damage);

	UPROPERTY(BlueprintAssignable)
	FOnHitpointChanged OnHitpointChanged;
};
