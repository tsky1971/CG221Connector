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

#pragma once

#include "Sockets.h"
#include "SocketSubsystem.h"
#include "Networking.h"
#include "SharedPointer.h"
#include "Components/ActorComponent.h"
#include "Runtime/Core/Public/Misc/DateTime.h"

#include "CG221TrackIRComponent.generated.h"

USTRUCT(BlueprintType)
struct FTrackIR
{
	GENERATED_USTRUCT_BODY()

	// Pos X
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TrackIR")
	float NPX;
	// Pos Y
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TrackIR")
	float NPY;
	// Pos Z
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TrackIR")
	float NPZ;

	// Pitch Head
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TrackIR")
	float NPPitch;
	// Yaw Head
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TrackIR")
	float NPYaw;
	// Roll Head
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TrackIR")
	float NPRoll;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TrackIR")
	FDateTime TimeStamp;
};


extern FCriticalSection g_CriticalSectionTrackIR;


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class /*CG221TRACKIRCOMPONENT_API*/ UCG221TrackIRComponent : public UActorComponent
{	
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TrackIR")
	FTrackIR TrackIRData;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TrackIR")
	bool bNewDataFlag;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TrackIR")
	int UdpPort;

	FSocket *m_pSocket;

public:	
	UCG221TrackIRComponent(const FObjectInitializer & ObjectInitializer);

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

	UFUNCTION(BluePrintCallable, Category = "TrackIR")
	bool ResetNewDataFlag();
};
