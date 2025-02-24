// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "Interfaces/OnlineSessionInterface.h"
#include "OnlineSessionSettings.h"
#include "TCG_GameInstance.generated.h"

/**
 * 
 */
UCLASS()
class TCG_SAMPLE_API UTCG_GameInstance : public UGameInstance
{
	GENERATED_BODY()
	
public:
	UTCG_GameInstance();
	virtual ~UTCG_GameInstance();

private:
	TArray<FOnlineSessionSearchResult> SearchResults;

protected:
	virtual void Init() override;

	IOnlineSessionPtr SessionInterface;

	TSharedPtr<FOnlineSessionSearch> SessionSearch;

	TArray<FTCG_Session> FoundSessions;

	virtual void OnCreateSessionComplete(FName ServerName, bool bSuccess);
	virtual void OnFindSessionComplete(bool bSuccess);
	virtual void OnJoinSessionComplete(FName ServerName, 
		EOnJoinSessionCompleteResult::Type JoinSessoinCompleteResult);

	bool bCreatingServer = false;
	bool bFindingServer = false;
	FString LocalUserSteamID;

	UFUNCTION(BlueprintCallable)
	bool CreateServer(const FString& InRoomName);

	UFUNCTION(BlueprintCallable)
	bool FindServers();

	UFUNCTION(BlueprintCallable)
	bool JoinServer(FTCG_Session TargetSession);

	UFUNCTION(BlueprintCallable)
	FString GetLocalUserSteamID();

	UFUNCTION(BlueprintCallable)
	bool FindLocalUserSteamID();

	UFUNCTION(BlueprintCallable)
	TArray<FTCG_Session> GetSearchedSessions();
};
