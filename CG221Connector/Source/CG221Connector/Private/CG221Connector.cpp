// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "CG221Connector.h"
#include "Core.h"
#include "Modules/ModuleManager.h"
#include "Interfaces/IPluginManager.h"
#include "CG221ConnectorLibrary/CG221ConnectorLibrary.h"

#define LOCTEXT_NAMESPACE "FCG221ConnectorModule"

DEFINE_LOG_CATEGORY(CG221ConnectorLog);

void FCG221ConnectorModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module

	// Get the base directory of this plugin
	FString BaseDir = IPluginManager::Get().FindPlugin("CG221Connector")->GetBaseDir();

	// Add on the relative location of the third party dll and load it
	FString LibraryPath;
#if PLATFORM_WINDOWS
	LibraryPath = FPaths::Combine(*BaseDir, TEXT("Binaries/ThirdParty/CG221ConnectorLibrary/Win64/CG221ConnectorLibrary.dll"));
#elif PLATFORM_MAC
    LibraryPath = FPaths::Combine(*BaseDir, TEXT("Source/ThirdParty/CG221ConnectorLibrary/Mac/Release/CG221ConnectorLibrary.dylib"));
#endif // PLATFORM_WINDOWS

	CG221ConnectorLibraryHandle = !LibraryPath.IsEmpty() ? FPlatformProcess::GetDllHandle(*LibraryPath) : nullptr;

	if (CG221ConnectorLibraryHandle)
	{
		// Call the test function in the third party library that opens a message box
		//CG221ConnectorLibraryFunction();
	}
	else
	{
		FMessageDialog::Open(EAppMsgType::Ok, LOCTEXT("ThirdPartyLibraryError", "Failed to load example third party library"));
	}
}

void FCG221ConnectorModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.

	// Free the dll handle
	FPlatformProcess::FreeDllHandle(CG221ConnectorLibraryHandle);
	CG221ConnectorLibraryHandle = nullptr;
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FCG221ConnectorModule, CG221Connector)
