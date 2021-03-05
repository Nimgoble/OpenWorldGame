// Fill out your copyright notice in the Description page of Project Settings.

using UnrealBuildTool;

public class OpenWorldGame : ModuleRules
{
	public OpenWorldGame(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
	
		PublicDependencyModuleNames.AddRange
		(
			new string[] 
			{ 
				"Core", 
				"CoreUObject", 
				"Engine", 
				"InputCore",
				"Networking",
				"Sockets",
				/*"OnlineSubsystem",
				"OnlineSubsystemUtils",*/
				"AssetRegistry",
				"AIModule",
				"HeadMountedDisplay",
				"UMG",
				"HTTP",
				"Json",
				"CinematicCamera"
			}
		);

		PrivateDependencyModuleNames.AddRange
		(
			new string[] 
			{
				"CoreUObject",
				"InputCore",
				"Networking",
				"Sockets",
				"OnlineSubsystem",
                /*"OnlineSubsystemNull",*/
                /*"OnlineSubsystemUtils",*/
				"Slate",
				"SlateCore",
				"GameplayDebugger",
				"HTTP",
				"Json",
				"CinematicCamera",
				"PlayFab", 
				"PlayFabCpp", 
				"PlayFabCommon" 
			}
		);

		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}
