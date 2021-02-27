// Fill out your copyright notice in the Description page of Project Settings.

using System.IO;
using UnrealBuildTool;

public class CG221ConnectorLibrary : ModuleRules
{
	public CG221ConnectorLibrary(ReadOnlyTargetRules Target) : base(Target)
	{
		Type = ModuleType.External;
        //PrecompileForTargets = PrecompileTargetsType.Any;

        if (Target.Platform == UnrealTargetPlatform.Win64)
		{
			// Add the import library
			PublicAdditionalLibraries.Add(Path.Combine(ModuleDirectory, "x64", "Release", "CG221ConnectorLibrary.lib"));

			// Delay-load the DLL, so we can load it from the right place first
			PublicDelayLoadDLLs.Add("CG221ConnectorLibrary.dll");

			// Ensure that the DLL is staged along with the executable
			RuntimeDependencies.Add("$(PluginDir)/Binaries/ThirdParty/CG221ConnectorLibrary/Win64/CG221ConnectorLibrary.dll");
        }
        else if (Target.Platform == UnrealTargetPlatform.Mac)
        {
            PublicDelayLoadDLLs.Add(Path.Combine(ModuleDirectory, "Mac", "Release", "libCG221ConnectorLibrary.dylib"));
            RuntimeDependencies.Add("$(PluginDir)/Source/ThirdParty/CG221ConnectorLibrary/Mac/Release/CG221ConnectorLibrary.dylib");
        }
	}
}
