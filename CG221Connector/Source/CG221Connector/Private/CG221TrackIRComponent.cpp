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

#include "CG221TrackIRComponent.h"
#include "CG221Connector.h"
#include "oscpkt.hh"

FCriticalSection g_CriticalSectionTrackIR;
FTrackIR g_TrackIR;

UCG221TrackIRComponent::UCG221TrackIRComponent(const FObjectInitializer & ObjectInitializer) :
	UActorComponent(ObjectInitializer),
	m_pSocket(NULL)
{
	PrimaryComponentTick.bCanEverTick = true;
	bWantsInitializeComponent = true;
	bAutoActivate = true;
	UdpPort = 2000;
	SetComponentTickEnabled(true);
}

void UCG221TrackIRComponent::OnRegister()
{
	Super::OnRegister();

	UE_LOG(CG221ConnectorLog, Warning, TEXT("UCG221TrackIRComponent::OnRegister()"));
}

// Called when the game starts
void UCG221TrackIRComponent::InitializeComponent()
{
	Super::InitializeComponent();
	UE_LOG(CG221ConnectorLog, Warning, TEXT("UCG221TrackIRComponent::InitializeComponent()"));
	bNewDataFlag = false;

	if (m_pSocket != NULL) {
		DestroySocket(m_pSocket);
	}
	m_pSocket = CreateUdpSocket(UdpPort);

}

// Ends gameplay for this component.
void UCG221TrackIRComponent::UninitializeComponent()
{
	Super::UninitializeComponent();
	UE_LOG(CG221ConnectorLog, Warning, TEXT("UCG221TrackIRComponent::UninitializeComponent()"));
	bNewDataFlag = false;

	if (m_pSocket != NULL) {
		DestroySocket(m_pSocket);
	}
}

// Called when the game starts or when spawned
void UCG221TrackIRComponent::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void UCG221TrackIRComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	//UE_LOG(CG221ConnectorLog, Warning, TEXT("UCG221TrackIRComponent::TickComponent()"));

	ReceivePayloads(m_pSocket);
#ifdef _DEBUG
	if (bNewDataFlag == false) {
		TrackIRData.NPX = 0.1f;
		TrackIRData.NPY = 0.2f;
		TrackIRData.NPZ = 0.3f;
		TrackIRData.NPPitch = 1.0f;
		TrackIRData.NPYaw = 2.0f;
		TrackIRData.NPRoll = 3.0f;
	}
#endif	

}

FSocket * UCG221TrackIRComponent::CreateUdpSocket(uint32 port)
{
	FSocket *result = NULL;
	//// ...
	result = ISocketSubsystem::Get(PLATFORM_SOCKETSUBSYSTEM)->CreateSocket(NAME_DGram, TEXT("CG221ConnectorSocket"), false);
	result->SetNonBlocking(true);
	result->SetReuseAddr(true);

	int32 NewSize = 0;
	result->SetReceiveBufferSize(2 * 1024 * 1024, NewSize);
	UE_LOG(CG221ConnectorLog, Warning, TEXT("SetReceiveBufferSize = %d"), NewSize);
	result->SetSendBufferSize(2 * 1024 * 1024, NewSize);
	UE_LOG(CG221ConnectorLog, Warning, TEXT("SetSendBufferSize = %d"), NewSize);

	auto InetAddrUdp = ISocketSubsystem::Get(PLATFORM_SOCKETSUBSYSTEM)->CreateInternetAddr();
	InetAddrUdp->SetAnyAddress();
	InetAddrUdp->SetPort(port);

	if (result->Bind(*InetAddrUdp)) {
		UE_LOG(CG221ConnectorLog, Warning, TEXT("Socket NetworkUdp creation SUCCESS"));

		if (result->GetConnectionState() == SCS_Connected) {
			UE_LOG(CG221ConnectorLog, Warning, TEXT("Socket NetworkUdp connection SUCCESS"));

			m_pSocket = result;
		}
		else {
			UE_LOG(CG221ConnectorLog, Warning, TEXT("Socket OSCListener connection FAILED"));

			result->Close();
			ISocketSubsystem::Get(PLATFORM_SOCKETSUBSYSTEM)->DestroySocket(result);
			result = NULL;
			m_pSocket = NULL;
		}
	}
	else {
		UE_LOG(CG221ConnectorLog, Warning, TEXT("Socket OSCListener creation FAILED"));
	}

	return result;
}

bool UCG221TrackIRComponent::DestroySocket(FSocket *_pSocket)
{
	bool result = false;
	if (_pSocket != NULL) {
		_pSocket->Close();
		ISocketSubsystem::Get(PLATFORM_SOCKETSUBSYSTEM)->DestroySocket(_pSocket);
		result = true;
	}
	return result;
}


// Called every frame
bool UCG221TrackIRComponent::ReceivePayloads(FSocket *_pSocket)
{
	bool result = true;
	uint32 dataRemain = 0;
	int32 bufferSize = 16384;
	uint8 buffer[16384];
	int32 bytesRead = 0;

	//UE_LOG(CG221ConnectorLog, Warning, TEXT("UCG221Network::ReceivePayloads() ..."));

	if ((_pSocket != NULL) && (_pSocket->GetConnectionState() == SCS_Connected)) {

		FScopeLock Lock(&g_CriticalSectionTrackIR);

		while (_pSocket->HasPendingData(dataRemain)) {
			//UE_LOG(CG221ConnectorLog, Warning, TEXT("UCG221Network::Tick() HasPendingData %d"), dataRemain);
			_pSocket->Recv(buffer, bufferSize, bytesRead);
			//UE_LOG(CG221ConnectorLog, Warning, TEXT("UCG221Network::Tick() read data %d"), bytesRead);
			oscpkt::PacketReader pr(buffer, bytesRead);
			oscpkt::Message *msg;
			std::string tempStr;
			float tempFloat;
			while ((pr.isOk()) && (msg = pr.popMessage()) != 0) {
				if (msg->match("/TRACKIR").popStr(tempStr).isOkNoMoreArgs()) {
					bNewDataFlag = true;
					TrackIRData.TimeStamp = FDateTime::Now();
					//UE_LOG(CG221ConnectorLog, Warning, TEXT("search TrackIR found = %s"), UTF8_TO_TCHAR(tempStr.c_str()));
				}
				if (msg->match("/NPX").popFloat(tempFloat).isOkNoMoreArgs()) {
					TrackIRData.NPX = tempFloat;
					//UE_LOG(CG221ConnectorLog, Warning, TEXT("search NPX = %f"), g_TrackIR.NPX);
				}
				if (msg->match("/NPY").popFloat(tempFloat).isOkNoMoreArgs()) {
					TrackIRData.NPY = tempFloat;
					//UE_LOG(CG221ConnectorLog, Warning, TEXT("search NPY = %f"), g_TrackIR.NPY);
				}
				if (msg->match("/NPZ").popFloat(tempFloat).isOkNoMoreArgs()) {
					TrackIRData.NPZ = tempFloat;
					//UE_LOG(CG221ConnectorLog, Warning, TEXT("search NPZ = %f"), g_TrackIR.NPZ);
				}
				if (msg->match("/NPPitch").popFloat(tempFloat).isOkNoMoreArgs()) {
					TrackIRData.NPPitch = tempFloat;
					//UE_LOG(CG221ConnectorLog, Warning, TEXT("search NPPitch = %f"), g_TrackIR.NPPitch);
				}
				if (msg->match("/NPYaw").popFloat(tempFloat).isOkNoMoreArgs()) {
					TrackIRData.NPYaw = tempFloat;
					//UE_LOG(CG221ConnectorLog, Warning, TEXT("search NPYaw = %f"), g_TrackIR.NPYaw);
				}
				if (msg->match("/NPRoll").popFloat(tempFloat).isOkNoMoreArgs()) {
					TrackIRData.NPRoll = tempFloat;
					//UE_LOG(CG221ConnectorLog, Warning, TEXT("search NPRoll = %f"), g_TrackIR.NPRoll);
				}
			} // while
		} // if pending data

	} // if

	return result;
}

bool UCG221TrackIRComponent::ResetNewDataFlag()
{
	bNewDataFlag = false;
	return bNewDataFlag;
}
