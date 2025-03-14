// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class TCG_Sample : ModuleRules
{
	public TCG_Sample(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
	
		PublicDependencyModuleNames.AddRange(new string[] { 
			"Core", "CoreUObject", 
			"Engine", "InputCore", 
			"EnhancedInput", "TweenMaker"
		});

		PrivateDependencyModuleNames.AddRange(new string[] {  });

		PrivateDependencyModuleNames.AddRange(new string[] { 
			"Slate", "SlateCore"
		});
		
		// Uncomment if you are using online features
		PrivateDependencyModuleNames.AddRange(new string[] { 
			"OnlineSubsystem", "OnlineSubsystemSteam"
		});
	}
}
