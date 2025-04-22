// Copyright Epic Games, Inc. All Rights Reserved.
// Copyright © 2024 - 2025 Sapient Technology, Inc.

using UnrealBuildTool;
using System.IO;

public class Sapient : ModuleRules
{
    public Sapient(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;
        
        // Binary distribution settings
        bUsePrecompiled = true;
        bPrecompile = true;
        PrecompileForTargets = PrecompileTargetsType.Any;
        
        // Optimization settings
#if UE_5_5_OR_LATER
        UndefinedIdentifierWarningLevel = WarningLevel.Off;
#endif
        OptimizeCode = CodeOptimization.InShippingBuildsOnly;

        PublicIncludePaths.AddRange(
            new string[] 
            {
                Path.Combine(ModuleDirectory, "Public")
            }
        );
        
        PrivateIncludePaths.AddRange(
            new string[] 
            {
                Path.Combine(ModuleDirectory, "Private")
            }
        );

        // Core dependencies required for both runtime and editor
        PublicDependencyModuleNames.AddRange(
            new string[]
            {
                "Core",
                "CoreUObject",
                "Engine",
                "InputCore",
                "Json",
                "JsonUtilities",
                "HTTP",
                "Projects",
				"LevelEditor"
			}
        );

        // Editor-specific dependencies
        PrivateDependencyModuleNames.AddRange(
            new string[]
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
                "Settings"
			}
        );

        // Additional editor functionality
        if (Target.bBuildEditor)
        {
            PrivateDependencyModuleNames.AddRange(
                new string[]
                {
                    "PropertyEditor",
                    "DesktopPlatform",
                    "ApplicationCore"
                }
            );
        }

        // Binary distribution protection
        bRequiresImplementModule = true;
        PublicDefinitions.Add("SAPIENT_API=DLLEXPORT");
        
        // Additional compiler settings for editor plugin
        bEnableExceptions = true;
    }
}