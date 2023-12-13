/**
	Copyright (c) 2023, tsky (thomas.kollakowsky@gmail.com)
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
#include "CG221ArucoMarkerComponent.h"

#include "oscpkt.hh"
#include "CG211ConnectorPrivatePCH.h"


FCriticalSection g_CriticalSectionTrackIR;
FArucoMarker g_ArucoMarker;

UCG221ArucoMarkerComponent::UCG221ArucoMarkerComponent(const FObjectInitializer & ObjectInitializer) :
	UActorComponent(ObjectInitializer),
	m_pSocket(NULL)
{
	PrimaryComponentTick.bCanEverTick = true;
	bWantsInitializeComponent = true;
	bAutoActivate = true;
	UdpPort = 5005;
	SetComponentTickEnabled(true);
}

void UCG221ArucoMarkerComponent::OnRegister()
{
	Super::OnRegister();
	
	UE_LOG(CG221ConnectorLog, Display, TEXT("UCG221ArucoMarkerComponent::OnRegister()"));
}

// Called when the game starts
void UCG221ArucoMarkerComponent::InitializeComponent()
{
	Super::InitializeComponent();
	UE_LOG(CG221ConnectorLog, Display, TEXT("UCG221ArucoMarkerComponent::InitializeComponent()"));
	bNewDataFlag = false;

	if (m_pSocket != NULL) {
		DestroySocket(m_pSocket);
	}
	m_pSocket = CreateUdpSocket(UdpPort);

}

// Ends gameplay for this component.
void UCG221ArucoMarkerComponent::UninitializeComponent()
{
	Super::UninitializeComponent();
	UE_LOG(CG221ConnectorLog, Display, TEXT("UCG221ArucoMarkerComponent::UninitializeComponent()"));
	bNewDataFlag = false;

	if (m_pSocket != NULL) {
		DestroySocket(m_pSocket);
	}
}

// Called when the game starts or when spawned
void UCG221ArucoMarkerComponent::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void UCG221ArucoMarkerComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	//UE_LOG(CG221ConnectorLog, Display, TEXT("UCG221ArucoMarkerComponent::TickComponent()"));

	ReceivePayloads(m_pSocket);
#ifdef _DEBUG
	if (bNewDataFlag == false) {
		ArucoMarkerData.PosY = 0.1f;
		ArucoMarkerData.PosY = 0.2f;
		ArucoMarkerData.PosY = 0.3f;
	}
#endif	
	
}

FSocket * UCG221ArucoMarkerComponent::CreateUdpSocket(uint32 port)
{
	FSocket *result = NULL;
	//// ...
	result = ISocketSubsystem::Get(PLATFORM_SOCKETSUBSYSTEM)->CreateSocket(NAME_DGram, TEXT("CG221ConnectorSocket"), false);
	result->SetNonBlocking(true);
	result->SetReuseAddr(true);

	int32 NewSize = 0;
	result->SetReceiveBufferSize(2 * 1024 * 1024, NewSize);
	UE_LOG(CG221ConnectorLog, Display, TEXT("SetReceiveBufferSize = %d"), NewSize);
	result->SetSendBufferSize(2 * 1024 * 1024, NewSize);
	UE_LOG(CG221ConnectorLog, Display, TEXT("SetSendBufferSize = %d"), NewSize);

	auto InetAddrUdp = ISocketSubsystem::Get(PLATFORM_SOCKETSUBSYSTEM)->CreateInternetAddr();
	InetAddrUdp->SetAnyAddress();
	InetAddrUdp->SetPort(port);

	if (result->Bind(*InetAddrUdp)) {
		UE_LOG(CG221ConnectorLog, Display, TEXT("Socket NetworkUdp creation SUCCESS"));

		if (result->GetConnectionState() == SCS_Connected) {
			UE_LOG(CG221ConnectorLog, Display, TEXT("Socket NetworkUdp connection SUCCESS"));

			m_pSocket = result;
		}
		else {
			UE_LOG(CG221ConnectorLog, Error, TEXT("Socket OSCListener connection FAILED"));

			result->Close();
			ISocketSubsystem::Get(PLATFORM_SOCKETSUBSYSTEM)->DestroySocket(result);
			result = NULL;
			m_pSocket = NULL;
		}
	}
	else {
		UE_LOG(CG221ConnectorLog, Fatal, TEXT("Socket OSCListener creation FAILED"));
	}

	return result;
}

bool UCG221ArucoMarkerComponent::DestroySocket(FSocket *_pSocket)
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
bool UCG221ArucoMarkerComponent::ReceivePayloads(FSocket *_pSocket)
{
	bool result = true;
	uint32 dataRemain = 0;
	int32 bufferSize = 16384;
	uint8 buffer[16384];
	int32 bytesRead = 0;

	//UE_LOG(CG221ConnectorLog, Display, TEXT("UCG221Network::ReceivePayloads() ..."));

	if ((_pSocket != NULL) && (_pSocket->GetConnectionState() == SCS_Connected)) {

		FScopeLock Lock(&g_CriticalSectionArucoMarker);

		while (_pSocket->HasPendingData(dataRemain)) {
			UE_LOG(CG221ConnectorLog, Display, TEXT("UCG221Network::Tick() HasPendingData %d"), dataRemain);
			_pSocket->Recv(buffer, bufferSize, bytesRead);
			UE_LOG(CG221ConnectorLog, Display, TEXT("UCG221Network::Tick() read data %d"), bytesRead);
			oscpkt::PacketReader pr(buffer, bytesRead);
			oscpkt::Message *msg;
			std::string tempStr;
			float tempFloat;
			while ((pr.isOk()) && (msg = pr.popMessage()) != 0) {
				if (msg->match("/ArucoMarker").popStr(tempStr).isOkNoMoreArgs()) {
					bNewDataFlag = true;
					ArucoMarkerData.TimeStamp = FDateTime::Now();
					UE_LOG(CG221ConnectorLog, Display, TEXT("search TrackIR found = %s"), UTF8_TO_TCHAR(tempStr.c_str()));
				}
				if (msg->match("/PosX").popFloat(tempFloat).isOkNoMoreArgs()) {
					ArucoMarkerData.PosX = tempFloat;
					UE_LOG(CG221ConnectorLog, Display, TEXT("search PosX = %f"), g_ArucoMarker.PosX);
				}
				if (msg->match("/PosY").popFloat(tempFloat).isOkNoMoreArgs()) {
					ArucoMarkerData.PosY = tempFloat;
					UE_LOG(CG221ConnectorLog, Display, TEXT("search PosY = %f"), g_ArucoMarker.PosY);
				}
				if (msg->match("/PosZ").popFloat(tempFloat).isOkNoMoreArgs()) {
					ArucoMarkerData.PosZ = tempFloat;
					UE_LOG(CG221ConnectorLog, Display, TEXT("search PosZ = %f"), g_ArucoMarker.PosZ);
				}
				if (msg->match("/AngX").popFloat(tempFloat).isOkNoMoreArgs()) {
					ArucoMarkerData.AngX = tempFloat;
					UE_LOG(CG221ConnectorLog, Display, TEXT("search AngX = %f"), g_ArucoMarker.AngX);
				}
				if (msg->match("/AngY").popFloat(tempFloat).isOkNoMoreArgs()) {
					ArucoMarkerData.AngY = tempFloat;
					UE_LOG(CG221ConnectorLog, Display, TEXT("search AngY = %f"), g_ArucoMarker.AngY);
				}
				if (msg->match("/AngZ").popFloat(tempFloat).isOkNoMoreArgs()) {
					ArucoMarkerData.AngZ = tempFloat;
					UE_LOG(CG221ConnectorLog, Display, TEXT("search AngZ = %f"), g_ArucoMarker.AngZ);
				}
			} // while
		} // if pending data

	} // if

	return result;
}

bool UCG221ArucoMarkerComponent::ResetNewDataFlag()
{
	bNewDataFlag = false;
	return bNewDataFlag;		
}
