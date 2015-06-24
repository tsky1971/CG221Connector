/**
	Copyright (c) 2015, tsky
	All rights reserved.

	Redistribution and use in source and binary forms, with or without
	modification, are permitted provided that the following conditions are met:

	* Redistributions of source code must retain the above copyright notice, this
	  list of conditions and the following disclaimer.

	* Redistributions in binary form must reproduce the above copyright notice,
	  this list of conditions and the following disclaimer in the documentation
	  and/or other materials provided with the distribution.

	THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
	AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
	IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
	DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
	FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
	DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
	SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
	CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
	OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
	OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

**/

#include "CG211ConnectorPrivatePCH.h"

#define LOCTEXT_NAMESPACE "FCG211ConnectorModule"

DEFINE_LOG_CATEGORY(CG221ConnectorLog);

class FCG211ConnectorPlugin : public ICG211ConnectorPlugin
{
protected:
public:
	FCG211ConnectorPlugin();

	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
};

	
IMPLEMENT_MODULE(FCG211ConnectorPlugin, CG211ConnectorPlugin)

FCG211ConnectorPlugin::FCG211ConnectorPlugin() 
{
	UE_LOG(CG221ConnectorLog, Warning, TEXT("FCG211ConnectorPlugin::UCG221Network()"));
}

void FCG211ConnectorPlugin::StartupModule()
{
	UE_LOG(CG221ConnectorLog, Warning, TEXT("FCG211ConnectorPlugin::StartupModule()"));

}

void FCG211ConnectorPlugin::ShutdownModule()
{
	UE_LOG(CG221ConnectorLog, Warning, TEXT("FCG211ConnectorPlugin::ShutdownModule()"));
	
}

#undef LOCTEXT_NAMESPACE