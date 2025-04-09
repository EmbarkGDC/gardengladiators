using UnrealBuildTool;

public class Sushido_v1Target : TargetRules
{
	public Sushido_v1Target(TargetInfo Target) : base(Target)
	{
		DefaultBuildSettings = BuildSettingsVersion.Latest;
		IncludeOrderVersion = EngineIncludeOrderVersion.Latest;
		Type = TargetType.Game;
		ExtraModuleNames.Add("Sushido_v1");
	}
}
