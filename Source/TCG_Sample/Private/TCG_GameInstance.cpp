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
		FoundSessions.Empty();
		SearchResults = SessionSearch->SearchResults;
		if (SearchResults.Num() > 0)
		{
			UE_LOG(LogTemp, Warning, TEXT("Found Servers, Num: %d"), SearchResults.Num());
			for (FOnlineSessionSearchResult SearchResult : SearchResults)
			{
				// TODO: if session owner is self, ignore the result
				FString SessionID = SearchResult.Session.GetSessionIdStr();
				FString SessionOwnerName = SearchResult.Session.OwningUserName;
				FString RoomName;
				SearchResult.Session.SessionSettings.Get(FName("RoomName"), RoomName);
				FTCG_Session SessionData(SessionOwnerName, SessionID, RoomName, SearchResult);
				FoundSessions.Add(SessionData);
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

bool UTCG_GameInstance::CreateServer(const FString& InRoomName)
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

		FOnlineSessionSettings SessionSettings;
		SessionSettings.bAllowJoinInProgress = true;
		SessionSettings.bIsDedicated = false;
		SessionSettings.bIsLANMatch = true;
		SessionSettings.bShouldAdvertise = true;
		SessionSettings.bUsesPresence = true;

		// Session Owner & Opponent, Does not Require Password
		SessionSettings.NumPublicConnections = 2;
		SessionSettings.Set(FName("RoomName"), InRoomName);

		FName SessionName = FName("CARDGAME");

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

bool UTCG_GameInstance::JoinServer(FTCG_Session TargetSession)
{
	return SessionInterface->JoinSession(0, 
		FName("CARDGAME"), TargetSession.SearchResult);
}

FString UTCG_GameInstance::GetLocalUserSteamID()
{
	return FString();
}

bool UTCG_GameInstance::FindLocalUserSteamID()
{
	return false;
}

TArray<FTCG_Session> UTCG_GameInstance::GetSearchedSessions()
{
	return this->FoundSessions;
}
