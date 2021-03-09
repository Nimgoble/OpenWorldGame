// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "OWGPlayerState.generated.h"

/**
 * 
 */
UCLASS()
class OPENWORLDGAME_API AOWGPlayerState : public APlayerState
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable, Category = "OWG|Player")
	FString GetPlayFabId() const;
	
	UFUNCTION(BlueprintCallable, Category = "OWG|Player")
	void ClientSetPlayFabId(FString playFabId);
	UFUNCTION(Server, Reliable, WithValidation)
	void ServerSetPlayFabId(const FString &playFabId);

	UFUNCTION(BlueprintImplementableEvent, Category = "OWG|Player")
	void ServerPlayFabIdSet();
protected:
	UFUNCTION()
	void OnReplicated_PlayFabId();
	UPROPERTY(Transient, ReplicatedUsing = OnReplicated_PlayFabId)
	FString PlayFabId;
	/** Copy properties which need to be saved in inactive PlayerState */
	virtual void CopyProperties(APlayerState* PlayerState) override;
};
