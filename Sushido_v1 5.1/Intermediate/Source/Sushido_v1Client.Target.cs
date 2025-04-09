using UnrealBuildTool;

public class Sushido_v1ClientTarget : TargetRules
{
	public Sushido_v1ClientTarget(TargetInfo Target) : base(Target)
	{
		DefaultBuildSettings = BuildSettingsVersion.Latest;
		IncludeOrderVersion = EngineIncludeOrderVersion.Latest;
		Type = TargetType.Client;
		ExtraModuleNames.Add("Sushido_v1");
	}
}
