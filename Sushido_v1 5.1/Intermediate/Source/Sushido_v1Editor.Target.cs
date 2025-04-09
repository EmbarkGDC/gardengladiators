using UnrealBuildTool;

public class Sushido_v1EditorTarget : TargetRules
{
	public Sushido_v1EditorTarget(TargetInfo Target) : base(Target)
	{
		DefaultBuildSettings = BuildSettingsVersion.Latest;
		IncludeOrderVersion = EngineIncludeOrderVersion.Latest;
		Type = TargetType.Editor;
		ExtraModuleNames.Add("Sushido_v1");
	}
}
