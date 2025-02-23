// Fill out your copyright notice in the Description page of Project Settings.


#include "TCG_GameInstance.h"
#include "Engine/World.h"
#include "Online/OnlineSessionNames.h"
#include "TCG_Definitions.h"
#include "OnlineSubsystem.h"

UTCG_GameInstance::UTCG_GameInstance()
{

}

UTCG_GameInstance::~UTCG_GameInstance()
{
	
}

void UTCG_GameInstance::Init()
{
	Super::Init();

	if (IOnlineSubsystem* SubSystem = IOnlineSubsystem::Get())
	{
		SessionInterface = SubSystem->GetSessionInterface();

		if (SessionInterface.IsValid())
		{
			// if create session success delegate
			SessionInterface->OnCreateSessionCompleteDelegates.AddUObject(this,
				&UTCG_GameInstance::OnCreateSessionComplete);
			SessionInterface->OnFindSessionsCompleteDelegates.AddUObject(this,
				&UTCG_GameInstance::OnFindSessionComplete);
			SessionInterface->OnJoinSessionCompleteDelegates.AddUObject(this,
				&UTCG_GameInstance::OnJoinSessionComplete);
		}
	}
}

void UTCG_GameInstance::OnCreateSessionComplete(FName ServerName, bool bSuccess)
{
	bCreatingServer = false;
	if (bSuccess)
	{
		// GetWorld()->ServerTravel()
		// Server Side -> move to waiting room(?)
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("Failed Creating Server"));
	}
}

void UTCG_GameInstance::OnFindSessionComplete(bool bSuccess)
{
	if (bSuccess)
	{
		SearchResults.Empty();
		SearchResults = SessionSearch->SearchResults;
		if (SearchResults.Num() > 0)
		{
			UE_LOG(LogTemp, Warning, TEXT("Found Servers, Num: %d"), SearchResults.Num());
			for (FOnlineSessionSearchResult SearchResult : SearchResults)
			{
				FString SessionID = SearchResult.Session.GetSessionIdStr();
				FString SessionOwnerName = SearchResult.Session.OwningUserName;
				// TODO: Need to Figure out How to Retrieve Session Name
				// TODO: Deliver Session ID, Session Owner's Name, and Session Name
				//		 to Widget
			}
		}
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("Failed Searching Sessions"));
	}
}

void UTCG_GameInstance::OnJoinSessionComplete(FName ServerName, 
	EOnJoinSessionCompleteResult::Type JoinSessoinCompleteResult)
{
	switch (JoinSessoinCompleteResult)
	{
	case EOnJoinSessionCompleteResult::Success:
		// UE_LOG(LogTemp, Warning, TEXT(
		// 	"Joined Session, SessionName: %s"), *ServerName);
		// when successful
		break;
	// all the others -> failure
	case EOnJoinSessionCompleteResult::SessionIsFull:
		break;
	case EOnJoinSessionCompleteResult::SessionDoesNotExist:
		break;
	case EOnJoinSessionCompleteResult::CouldNotRetrieveAddress:
		break;
	case EOnJoinSessionCompleteResult::AlreadyInSession:
		break;
	case EOnJoinSessionCompleteResult::UnknownError:
		break;
	default:
		break;
	}
}

bool UTCG_GameInstance::CreateServer(FString InSessionName, int32 PlayerNum)
{
	if (bCreatingServer)
	{
		UE_LOG(LogTemp, Error, TEXT(
			"Still Trying to Create a Server"));
		return false;
	}
	else
	{
		bCreatingServer = true;
		UE_LOG(LogTemp, Warning, TEXT(
			"Trying To Create Server with Name: %s"), *InSessionName);

		FOnlineSessionSettings SessionSettings;
		SessionSettings.bAllowJoinInProgress = true;
		SessionSettings.bIsDedicated = false;
		SessionSettings.bIsLANMatch = true;
		SessionSettings.bShouldAdvertise = true;
		SessionSettings.bUsesPresence = true;
		SessionSettings.NumPublicConnections = PlayerNum;

		FName SessionName = FName(InSessionName);

		bool result = SessionInterface->
			CreateSession(0, SessionName, SessionSettings);

		if (result)
		{
			UE_LOG(LogTemp, Warning, TEXT(
				"Successfully Server Createion Attempt"));
		}
		else
		{
			UE_LOG(LogTemp, Error, TEXT(
				"Failed Server Creation Attempt"));
		}
		return result;
	}
}

bool UTCG_GameInstance::FindServers()
{
	SessionSearch = MakeShareable(new FOnlineSessionSearch());
	
	SessionSearch->bIsLanQuery = true;
	SessionSearch->MaxSearchResults = 10000;
	SessionSearch->QuerySettings.Set(SEARCH_KEYWORDS, true,
		EOnlineComparisonOp::Equals);

	bool result = SessionInterface->FindSessions(0, SessionSearch.ToSharedRef());
	return result;
}

bool UTCG_GameInstance::JoinServer(FString InSessionName)
{
	FName SessionName = FName(InSessionName);
	// return SessionInterface->JoinSession(0, SessionName, TargetSession);

	return false;
}

FString UTCG_GameInstance::GetLocalUserSteamID()
{
	return FString();
}

bool UTCG_GameInstance::FindLocalUserSteamID()
{
	return false;
}
