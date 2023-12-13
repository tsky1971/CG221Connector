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

#pragma once

#include "Sockets.h"
#include "SocketSubsystem.h"
#include "Templates/SharedPointer.h"
#include "Components/ActorComponent.h"
#include "Runtime/Core/Public/Misc/DateTime.h"

#include "CG221ArucoMarkerComponent.generated.h"

USTRUCT(BlueprintType)
struct FArucoMarker
{
	GENERATED_USTRUCT_BODY()

	// Pos X
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ArucoMarker")
	float PosX;
	// Pos Y
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ArucoMarker")
	float PosY;
	// Pos Z
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ArucoMarker")
	float PosZ;

	// Pitch Head
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ArucoMarker")
	float AngX;
	// Yaw Head
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ArucoMarker")
	float AngY;
	// Roll Head
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ArucoMarker")
	float AngZ;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ArucoMarker")
	FDateTime TimeStamp;
};


extern FCriticalSection g_CriticalSectionArucoMarker;


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class /*CG221ArucoMarkerCOMPONENT_API*/ UCG221ArucoMarkerComponent : public UActorComponent
{	
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ArucoMarker")
	FArucoMarker ArucoMarkerData;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ArucoMarker")
	bool bNewDataFlag;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ArucoMarker")
	int UdpPort;

	FSocket *m_pSocket;

public:	
	UCG221ArucoMarkerComponent(const FObjectInitializer & ObjectInitializer);

	virtual void OnRegister() override;

	// Called when the game starts
	virtual void InitializeComponent() override;

	// Ends gameplay for this component.
	virtual void UninitializeComponent() override;

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction ) override;

	FSocket * CreateUdpSocket(uint32 port);
	bool DestroySocket(FSocket *_pSocket);
	bool ReceivePayloads(FSocket *_pSocket);

	UFUNCTION(BluePrintCallable, Category = "ArucoMarker")
	bool ResetNewDataFlag();
};
