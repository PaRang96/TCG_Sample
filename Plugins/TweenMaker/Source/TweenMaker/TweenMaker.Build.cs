// Copyright 2018 Francesco Desogus. All Rights Reserved.

using UnrealBuildTool;
using System.IO;

public class TweenMaker : ModuleRules
{
	public TweenMaker(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;
        
		PublicDependencyModuleNames.AddRange(
			new string[]
			{
				"Core",
				"Engine",
				"CoreUObject",
			}
			);
			
		
		PrivateDependencyModuleNames.AddRange(
			new string[]
			{
				"Slate",
				"SlateCore",
                "UMG"
			}
			);
	}
}
