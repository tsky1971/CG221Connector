// Some copyright should be here...

using UnrealBuildTool;

public class CG211Connector : ModuleRules
{
	public CG211Connector(ReadOnlyTargetRules Target) : base(Target)
	{
        PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;

		IncludeOrderVersion = EngineIncludeOrderVersion.Latest;

        PublicIncludePaths.AddRange(
			new string[] {
                "CG211Connector/Public",

				// ... add public include paths required here ...
			}
			);
				
		
		PrivateIncludePaths.AddRange(
			new string[] {
				"CG211Connector/Private",
				
				// ... add other private include paths required here ...
			}
			);
			
		
		PublicDependencyModuleNames.AddRange(
			new string[]
			{
				"Core",
				"CoreUObject",
				"Engine",
                "InputCore",
                "Slate",
                "SlateCore",
				"Sockets"
				// ... add other public dependencies that you statically link with here ...
			}
			);
			
		
		PrivateDependencyModuleNames.AddRange(
			new string[]
			{
				"Slate", "SlateCore"
				// ... add private dependencies that you statically link with here ...	
			}
			);
		
		
		DynamicallyLoadedModuleNames.AddRange(
			new string[]
			{
				
				// ... add any modules that your module loads dynamically here ...
			}
			);
	}
}
