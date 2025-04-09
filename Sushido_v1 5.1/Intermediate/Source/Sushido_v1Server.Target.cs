using UnrealBuildTool;

public class Sushido_v1ServerTarget : TargetRules
{
	public Sushido_v1ServerTarget(TargetInfo Target) : base(Target)
	{
		DefaultBuildSettings = BuildSettingsVersion.Latest;
		IncludeOrderVersion = EngineIncludeOrderVersion.Latest;
		Type = TargetType.Server;
		ExtraModuleNames.Add("Sushido_v1");
	}
}
