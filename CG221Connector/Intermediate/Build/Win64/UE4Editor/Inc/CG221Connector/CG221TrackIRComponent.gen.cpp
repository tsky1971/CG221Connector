// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "CG221Connector/Public/CG221TrackIRComponent.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeCG221TrackIRComponent() {}
// Cross Module References
	CG221CONNECTOR_API UScriptStruct* Z_Construct_UScriptStruct_FTrackIR();
	UPackage* Z_Construct_UPackage__Script_CG221Connector();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FDateTime();
	CG221CONNECTOR_API UClass* Z_Construct_UClass_UCG221TrackIRComponent_NoRegister();
	CG221CONNECTOR_API UClass* Z_Construct_UClass_UCG221TrackIRComponent();
	ENGINE_API UClass* Z_Construct_UClass_UActorComponent();
// End Cross Module References
class UScriptStruct* FTrackIR::StaticStruct()
{
	static class UScriptStruct* Singleton = NULL;
	if (!Singleton)
	{
		extern CG221CONNECTOR_API uint32 Get_Z_Construct_UScriptStruct_FTrackIR_Hash();
		Singleton = GetStaticStruct(Z_Construct_UScriptStruct_FTrackIR, Z_Construct_UPackage__Script_CG221Connector(), TEXT("TrackIR"), sizeof(FTrackIR), Get_Z_Construct_UScriptStruct_FTrackIR_Hash());
	}
	return Singleton;
}
template<> CG221CONNECTOR_API UScriptStruct* StaticStruct<FTrackIR>()
{
	return FTrackIR::StaticStruct();
}
static FCompiledInDeferStruct Z_CompiledInDeferStruct_UScriptStruct_FTrackIR(FTrackIR::StaticStruct, TEXT("/Script/CG221Connector"), TEXT("TrackIR"), false, nullptr, nullptr);
static struct FScriptStruct_CG221Connector_StaticRegisterNativesFTrackIR
{
	FScriptStruct_CG221Connector_StaticRegisterNativesFTrackIR()
	{
		UScriptStruct::DeferCppStructOps(FName(TEXT("TrackIR")),new UScriptStruct::TCppStructOps<FTrackIR>);
	}
} ScriptStruct_CG221Connector_StaticRegisterNativesFTrackIR;
	struct Z_Construct_UScriptStruct_FTrackIR_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_NPX_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_NPX;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_NPY_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_NPY;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_NPZ_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_NPZ;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_NPPitch_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_NPPitch;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_NPYaw_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_NPYaw;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_NPRoll_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_NPRoll;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_TimeStamp_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_TimeStamp;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UE4CodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FTrackIR_Statics::Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/CG221TrackIRComponent.h" },
	};
#endif
	void* Z_Construct_UScriptStruct_FTrackIR_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FTrackIR>();
	}
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FTrackIR_Statics::NewProp_NPX_MetaData[] = {
		{ "Category", "TrackIR" },
		{ "Comment", "// Pos X\n" },
		{ "ModuleRelativePath", "Public/CG221TrackIRComponent.h" },
		{ "ToolTip", "Pos X" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FTrackIR_Statics::NewProp_NPX = { "NPX", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FTrackIR, NPX), METADATA_PARAMS(Z_Construct_UScriptStruct_FTrackIR_Statics::NewProp_NPX_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FTrackIR_Statics::NewProp_NPX_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FTrackIR_Statics::NewProp_NPY_MetaData[] = {
		{ "Category", "TrackIR" },
		{ "Comment", "// Pos Y\n" },
		{ "ModuleRelativePath", "Public/CG221TrackIRComponent.h" },
		{ "ToolTip", "Pos Y" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FTrackIR_Statics::NewProp_NPY = { "NPY", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FTrackIR, NPY), METADATA_PARAMS(Z_Construct_UScriptStruct_FTrackIR_Statics::NewProp_NPY_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FTrackIR_Statics::NewProp_NPY_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FTrackIR_Statics::NewProp_NPZ_MetaData[] = {
		{ "Category", "TrackIR" },
		{ "Comment", "// Pos Z\n" },
		{ "ModuleRelativePath", "Public/CG221TrackIRComponent.h" },
		{ "ToolTip", "Pos Z" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FTrackIR_Statics::NewProp_NPZ = { "NPZ", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FTrackIR, NPZ), METADATA_PARAMS(Z_Construct_UScriptStruct_FTrackIR_Statics::NewProp_NPZ_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FTrackIR_Statics::NewProp_NPZ_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FTrackIR_Statics::NewProp_NPPitch_MetaData[] = {
		{ "Category", "TrackIR" },
		{ "Comment", "// Pitch Head\n" },
		{ "ModuleRelativePath", "Public/CG221TrackIRComponent.h" },
		{ "ToolTip", "Pitch Head" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FTrackIR_Statics::NewProp_NPPitch = { "NPPitch", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FTrackIR, NPPitch), METADATA_PARAMS(Z_Construct_UScriptStruct_FTrackIR_Statics::NewProp_NPPitch_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FTrackIR_Statics::NewProp_NPPitch_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FTrackIR_Statics::NewProp_NPYaw_MetaData[] = {
		{ "Category", "TrackIR" },
		{ "Comment", "// Yaw Head\n" },
		{ "ModuleRelativePath", "Public/CG221TrackIRComponent.h" },
		{ "ToolTip", "Yaw Head" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FTrackIR_Statics::NewProp_NPYaw = { "NPYaw", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FTrackIR, NPYaw), METADATA_PARAMS(Z_Construct_UScriptStruct_FTrackIR_Statics::NewProp_NPYaw_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FTrackIR_Statics::NewProp_NPYaw_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FTrackIR_Statics::NewProp_NPRoll_MetaData[] = {
		{ "Category", "TrackIR" },
		{ "Comment", "// Roll Head\n" },
		{ "ModuleRelativePath", "Public/CG221TrackIRComponent.h" },
		{ "ToolTip", "Roll Head" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FTrackIR_Statics::NewProp_NPRoll = { "NPRoll", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FTrackIR, NPRoll), METADATA_PARAMS(Z_Construct_UScriptStruct_FTrackIR_Statics::NewProp_NPRoll_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FTrackIR_Statics::NewProp_NPRoll_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FTrackIR_Statics::NewProp_TimeStamp_MetaData[] = {
		{ "Category", "TrackIR" },
		{ "ModuleRelativePath", "Public/CG221TrackIRComponent.h" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FTrackIR_Statics::NewProp_TimeStamp = { "TimeStamp", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FTrackIR, TimeStamp), Z_Construct_UScriptStruct_FDateTime, METADATA_PARAMS(Z_Construct_UScriptStruct_FTrackIR_Statics::NewProp_TimeStamp_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FTrackIR_Statics::NewProp_TimeStamp_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FTrackIR_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FTrackIR_Statics::NewProp_NPX,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FTrackIR_Statics::NewProp_NPY,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FTrackIR_Statics::NewProp_NPZ,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FTrackIR_Statics::NewProp_NPPitch,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FTrackIR_Statics::NewProp_NPYaw,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FTrackIR_Statics::NewProp_NPRoll,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FTrackIR_Statics::NewProp_TimeStamp,
	};
	const UE4CodeGen_Private::FStructParams Z_Construct_UScriptStruct_FTrackIR_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_CG221Connector,
		nullptr,
		&NewStructOps,
		"TrackIR",
		sizeof(FTrackIR),
		alignof(FTrackIR),
		Z_Construct_UScriptStruct_FTrackIR_Statics::PropPointers,
		UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FTrackIR_Statics::PropPointers),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000001),
		METADATA_PARAMS(Z_Construct_UScriptStruct_FTrackIR_Statics::Struct_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FTrackIR_Statics::Struct_MetaDataParams))
	};
	UScriptStruct* Z_Construct_UScriptStruct_FTrackIR()
	{
#if WITH_HOT_RELOAD
		extern uint32 Get_Z_Construct_UScriptStruct_FTrackIR_Hash();
		UPackage* Outer = Z_Construct_UPackage__Script_CG221Connector();
		static UScriptStruct* ReturnStruct = FindExistingStructIfHotReloadOrDynamic(Outer, TEXT("TrackIR"), sizeof(FTrackIR), Get_Z_Construct_UScriptStruct_FTrackIR_Hash(), false);
#else
		static UScriptStruct* ReturnStruct = nullptr;
#endif
		if (!ReturnStruct)
		{
			UE4CodeGen_Private::ConstructUScriptStruct(ReturnStruct, Z_Construct_UScriptStruct_FTrackIR_Statics::ReturnStructParams);
		}
		return ReturnStruct;
	}
	uint32 Get_Z_Construct_UScriptStruct_FTrackIR_Hash() { return 713689085U; }
	DEFINE_FUNCTION(UCG221TrackIRComponent::execResetNewDataFlag)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->ResetNewDataFlag();
		P_NATIVE_END;
	}
	void UCG221TrackIRComponent::StaticRegisterNativesUCG221TrackIRComponent()
	{
		UClass* Class = UCG221TrackIRComponent::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "ResetNewDataFlag", &UCG221TrackIRComponent::execResetNewDataFlag },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UCG221TrackIRComponent_ResetNewDataFlag_Statics
	{
		struct CG221TrackIRComponent_eventResetNewDataFlag_Parms
		{
			bool ReturnValue;
		};
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_UCG221TrackIRComponent_ResetNewDataFlag_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((CG221TrackIRComponent_eventResetNewDataFlag_Parms*)Obj)->ReturnValue = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UCG221TrackIRComponent_ResetNewDataFlag_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(CG221TrackIRComponent_eventResetNewDataFlag_Parms), &Z_Construct_UFunction_UCG221TrackIRComponent_ResetNewDataFlag_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCG221TrackIRComponent_ResetNewDataFlag_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCG221TrackIRComponent_ResetNewDataFlag_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UCG221TrackIRComponent_ResetNewDataFlag_Statics::Function_MetaDataParams[] = {
		{ "Category", "TrackIR" },
		{ "ModuleRelativePath", "Public/CG221TrackIRComponent.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UCG221TrackIRComponent_ResetNewDataFlag_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UCG221TrackIRComponent, nullptr, "ResetNewDataFlag", nullptr, nullptr, sizeof(CG221TrackIRComponent_eventResetNewDataFlag_Parms), Z_Construct_UFunction_UCG221TrackIRComponent_ResetNewDataFlag_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UCG221TrackIRComponent_ResetNewDataFlag_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UCG221TrackIRComponent_ResetNewDataFlag_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UCG221TrackIRComponent_ResetNewDataFlag_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UCG221TrackIRComponent_ResetNewDataFlag()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UCG221TrackIRComponent_ResetNewDataFlag_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_UCG221TrackIRComponent_NoRegister()
	{
		return UCG221TrackIRComponent::StaticClass();
	}
	struct Z_Construct_UClass_UCG221TrackIRComponent_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_TrackIRData_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_TrackIRData;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_bNewDataFlag_MetaData[];
#endif
		static void NewProp_bNewDataFlag_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bNewDataFlag;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_UdpPort_MetaData[];
#endif
		static const UE4CodeGen_Private::FUnsizedIntPropertyParams NewProp_UdpPort;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UCG221TrackIRComponent_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UActorComponent,
		(UObject* (*)())Z_Construct_UPackage__Script_CG221Connector,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_UCG221TrackIRComponent_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UCG221TrackIRComponent_ResetNewDataFlag, "ResetNewDataFlag" }, // 3210135254
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UCG221TrackIRComponent_Statics::Class_MetaDataParams[] = {
		{ "BlueprintSpawnableComponent", "" },
		{ "ClassGroupNames", "Custom" },
		{ "IncludePath", "CG221TrackIRComponent.h" },
		{ "ModuleRelativePath", "Public/CG221TrackIRComponent.h" },
		{ "ObjectInitializerConstructorDeclared", "" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UCG221TrackIRComponent_Statics::NewProp_TrackIRData_MetaData[] = {
		{ "Category", "TrackIR" },
		{ "ModuleRelativePath", "Public/CG221TrackIRComponent.h" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UClass_UCG221TrackIRComponent_Statics::NewProp_TrackIRData = { "TrackIRData", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UCG221TrackIRComponent, TrackIRData), Z_Construct_UScriptStruct_FTrackIR, METADATA_PARAMS(Z_Construct_UClass_UCG221TrackIRComponent_Statics::NewProp_TrackIRData_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UCG221TrackIRComponent_Statics::NewProp_TrackIRData_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UCG221TrackIRComponent_Statics::NewProp_bNewDataFlag_MetaData[] = {
		{ "Category", "TrackIR" },
		{ "ModuleRelativePath", "Public/CG221TrackIRComponent.h" },
	};
#endif
	void Z_Construct_UClass_UCG221TrackIRComponent_Statics::NewProp_bNewDataFlag_SetBit(void* Obj)
	{
		((UCG221TrackIRComponent*)Obj)->bNewDataFlag = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UCG221TrackIRComponent_Statics::NewProp_bNewDataFlag = { "bNewDataFlag", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(UCG221TrackIRComponent), &Z_Construct_UClass_UCG221TrackIRComponent_Statics::NewProp_bNewDataFlag_SetBit, METADATA_PARAMS(Z_Construct_UClass_UCG221TrackIRComponent_Statics::NewProp_bNewDataFlag_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UCG221TrackIRComponent_Statics::NewProp_bNewDataFlag_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UCG221TrackIRComponent_Statics::NewProp_UdpPort_MetaData[] = {
		{ "Category", "TrackIR" },
		{ "ModuleRelativePath", "Public/CG221TrackIRComponent.h" },
	};
#endif
	const UE4CodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UClass_UCG221TrackIRComponent_Statics::NewProp_UdpPort = { "UdpPort", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UCG221TrackIRComponent, UdpPort), METADATA_PARAMS(Z_Construct_UClass_UCG221TrackIRComponent_Statics::NewProp_UdpPort_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UCG221TrackIRComponent_Statics::NewProp_UdpPort_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UCG221TrackIRComponent_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCG221TrackIRComponent_Statics::NewProp_TrackIRData,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCG221TrackIRComponent_Statics::NewProp_bNewDataFlag,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCG221TrackIRComponent_Statics::NewProp_UdpPort,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UCG221TrackIRComponent_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UCG221TrackIRComponent>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UCG221TrackIRComponent_Statics::ClassParams = {
		&UCG221TrackIRComponent::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_UCG221TrackIRComponent_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_UCG221TrackIRComponent_Statics::PropPointers),
		0,
		0x00B000A4u,
		METADATA_PARAMS(Z_Construct_UClass_UCG221TrackIRComponent_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UCG221TrackIRComponent_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UCG221TrackIRComponent()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UCG221TrackIRComponent_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UCG221TrackIRComponent, 1903342857);
	template<> CG221CONNECTOR_API UClass* StaticClass<UCG221TrackIRComponent>()
	{
		return UCG221TrackIRComponent::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UCG221TrackIRComponent(Z_Construct_UClass_UCG221TrackIRComponent, &UCG221TrackIRComponent::StaticClass, TEXT("/Script/CG221Connector"), TEXT("UCG221TrackIRComponent"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UCG221TrackIRComponent);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
