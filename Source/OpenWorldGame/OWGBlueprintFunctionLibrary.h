// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PlayFab.h"
#include "Core/PlayFabClientAPI.h"
#include "PlayFabCommon/Public/PlayFabRuntimeSettings.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "OWGBlueprintFunctionLibrary.generated.h"

/**
 * 
 */
UCLASS()
class OPENWORLDGAME_API UOWGBlueprintFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
public:
	/*UFUNCTION(BlueprintCallable, Category = "PlayFab/Custom")
	static UPlayFabClientAPI *GetPlayFabAuthenticationContext()
	{
		return (UPlayFabClientAPI * )IPlayFabModuleInterface::Get().GetClientAPI();
		GetDefault<UPlayFabRuntimeSettings>()->DeveloperSecretKey
	}*/
	UFUNCTION(BlueprintCallable, Category = "PlayFab/Custom")
	static void ClearDeveloperSecretKey()
	{
		UPlayFabRuntimeSettings* rSettings = GetMutableDefault<UPlayFabRuntimeSettings>();
		rSettings->DeveloperSecretKey = "";
	}

	UFUNCTION(BlueprintCallable, Category = "OWG")
	static bool IsActorInsideActor(AActor* actorThatMayBeInside, AActor* actorWeMayBeInside, bool onlyCollidingComponents = true);

	UFUNCTION(BlueprintCallable, Category = "OWG")
	static bool IsComponentInsideComponent(UPrimitiveComponent* componentThatMayBeInside, UPrimitiveComponent* componentWeMayBeInside);
};
