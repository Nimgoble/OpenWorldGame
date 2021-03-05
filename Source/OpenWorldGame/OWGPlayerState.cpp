// Fill out your copyright notice in the Description page of Project Settings.


#include "OWGPlayerState.h"
#include "OpenWorldGame.h"

void AOWGPlayerState::GetLifetimeReplicatedProps(TArray< FLifetimeProperty >& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME_CONDITION(AOWGPlayerState, PlayFabId, COND_OwnerOnly);
}

FString AOWGPlayerState::GetPlayFabId() const
{
	return PlayFabId;
}

void AOWGPlayerState::ClientSetPlayFabId(FString playFabId)
{
	ServerSetPlayFabId(playFabId);
}

bool AOWGPlayerState::ServerSetPlayFabId_Validate(const FString &playFabId)
{
	return true;
}

void AOWGPlayerState::ServerSetPlayFabId_Implementation(const FString &playFabId)
{
	this->PlayFabId = playFabId;
	UE_LOG(LogTemp, Warning, TEXT("Server PlayerState %s: PlayFabId set to: %s"), *GetName(), *PlayFabId);
}

void AOWGPlayerState::OnReplicated_PlayFabId()
{
	UE_LOG(LogTemp, Warning, TEXT("Client PlayerState %s: PlayFabId replicated: %s"), *GetName(), *PlayFabId);
}

void AOWGPlayerState::CopyProperties(APlayerState* PlayerState)
{
	Super::CopyProperties(PlayerState);

	AOWGPlayerState* Other = Cast<AOWGPlayerState>(PlayerState);
	if (Other != NULL)
	{
		Other->PlayFabId = PlayFabId;
	}
}