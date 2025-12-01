// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class StellaFanGame : ModuleRules
{
	public StellaFanGame(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] {
			"Core",
			"CoreUObject",
			"Engine",
			"InputCore",
			"EnhancedInput",
			"AIModule",
			"StateTreeModule",
			"GameplayStateTreeModule",
			"UMG",
			"Slate"
		});

		PrivateDependencyModuleNames.AddRange(new string[] { });

		PublicIncludePaths.AddRange(new string[] {
			"StellaFanGame",
			"StellaFanGame/Variant_Platforming",
			"StellaFanGame/Variant_Platforming/Animation",
			"StellaFanGame/Variant_Combat",
			"StellaFanGame/Variant_Combat/AI",
			"StellaFanGame/Variant_Combat/Animation",
			"StellaFanGame/Variant_Combat/Gameplay",
			"StellaFanGame/Variant_Combat/Interfaces",
			"StellaFanGame/Variant_Combat/UI",
			"StellaFanGame/Variant_SideScrolling",
			"StellaFanGame/Variant_SideScrolling/AI",
			"StellaFanGame/Variant_SideScrolling/Gameplay",
			"StellaFanGame/Variant_SideScrolling/Interfaces",
			"StellaFanGame/Variant_SideScrolling/UI"
		});

		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}
