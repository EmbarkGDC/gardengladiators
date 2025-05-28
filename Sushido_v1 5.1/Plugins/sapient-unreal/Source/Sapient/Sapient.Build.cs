// Copyright Epic Games, Inc. All Rights Reserved.
// Copyright © 2024 - 2025 Sapient Technology, Inc.

using System.IO;
using UnrealBuildTool;

public class Sapient : ModuleRules
{
	public Sapient(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

        // Binary distribution settings

        bUsePrecompiled = true;
		bPrecompile = true;
		PrecompileForTargets = PrecompileTargetsType.Any;

		// Optimization settings
#if UE_5_5_OR_LATER
		UndefinedIdentifierWarningLevel = WarningLevel.Off;
#endif

		PublicIncludePaths.AddRange(
			new[]
			{
				Path.Combine(ModuleDirectory, "Public")
			}
		);

		PrivateIncludePaths.AddRange(
			new[]
			{
				Path.Combine(ModuleDirectory, "Private")
			}
		);

		// Core dependencies required for both runtime and editor
		PublicDependencyModuleNames.AddRange(
			new[]
			{
				"Core",
				"CoreUObject",
				"Engine",
				"InputCore",
				"Json",
				"JsonUtilities",
				"HTTP",
				"Projects",
				"LevelEditor",
				"AIModule"
			}
		);

		// Editor-specific dependencies
		PrivateDependencyModuleNames.AddRange(
			new[]
			{
				"UnrealEd",
				"Slate",
				"SlateCore",
				"EditorFramework",
				"EditorStyle",
				"ToolMenus",
				"AssetTools",
				"BlueprintGraph",
				"BlueprintEditorLibrary",
				"ContentBrowser",
				"WorkspaceMenuStructure",
				"PythonScriptPlugin",
				"HotReload",
				"MainFrame",
				"AIModule",
				"GameplayTasks",
				"Settings",
				"CoreUObject",
				"Engine",
				"Slate",
				"SlateCore",
				"InputCore",
				"UnrealEd",
				"LevelEditor",
				"Kismet",
				"KismetCompiler",
				"BlueprintGraph",
				"GraphEditor",
				"PropertyEditor",
				"EditorStyle",
				"AssetRegistry",
				"Json",
				"JsonUtilities",
				"EditorSubsystem",
				"AIModule",
				"EditorScriptingUtilities",
				"BehaviorTreeEditor",
				"AIGraph"
			}
		);

		// Additional editor functionality
		if (Target.bBuildEditor)
			PrivateDependencyModuleNames.AddRange(
				new[]
				{
					"PropertyEditor",
					"DesktopPlatform",
					"ApplicationCore"
				}
			);

		PublicDefinitions.Add("SAPIENT_API=DLLEXPORT");


		/**
		 * @brief Controls shipping build logging behavior
		 *
		 * When set to 1, development logging is disabled and only critical logs remain
		 * When set to 0, all logging is enabled for development purposes
		 *
		 * @note Modify this value before building for different configurations:
		 * - Development/Debug: Set to 0
		 * - Shipping/Release: Set to 1
		 */
		PublicDefinitions.Add("SAPIENT_UE_BUILD_SHIPPING=1");
    }
}