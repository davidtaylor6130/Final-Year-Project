// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "FYP/FYP_Car_Body.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeFYP_Car_Body() {}
// Cross Module References
	FYP_API UClass* Z_Construct_UClass_AFYPPawn_NoRegister();
	FYP_API UClass* Z_Construct_UClass_AFYPPawn();
	PHYSXVEHICLES_API UClass* Z_Construct_UClass_AWheeledVehicle();
	UPackage* Z_Construct_UPackage__Script_FYP();
	FYP_API UFunction* Z_Construct_UFunction_AFYPPawn_LapMarkerCollider();
	ENGINE_API UScriptStruct* Z_Construct_UScriptStruct_FHitResult();
	ENGINE_API UClass* Z_Construct_UClass_UPrimitiveComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UTextRenderComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_USphereComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UBoxComponent_NoRegister();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FColor();
	ENGINE_API UClass* Z_Construct_UClass_UAudioComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UCameraComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_USpringArmComponent_NoRegister();
// End Cross Module References
	void AFYPPawn::StaticRegisterNativesAFYPPawn()
	{
		UClass* Class = AFYPPawn::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "LapMarkerCollider", &AFYPPawn::execLapMarkerCollider },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_AFYPPawn_LapMarkerCollider_Statics
	{
		struct FYPPawn_eventLapMarkerCollider_Parms
		{
			UPrimitiveComponent* _overlappedComponent;
			AActor* _otherActor;
			UPrimitiveComponent* _otherComp;
			int32 _otherBodyIndex;
			bool _bFromSweep;
			FHitResult _hitResult;
		};
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp__hitResult_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp__hitResult;
		static void NewProp__bFromSweep_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp__bFromSweep;
		static const UE4CodeGen_Private::FIntPropertyParams NewProp__otherBodyIndex;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp__otherComp_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp__otherComp;
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp__otherActor;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp__overlappedComponent_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp__overlappedComponent;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AFYPPawn_LapMarkerCollider_Statics::NewProp__hitResult_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AFYPPawn_LapMarkerCollider_Statics::NewProp__hitResult = { "_hitResult", nullptr, (EPropertyFlags)0x0010008008000182, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FYPPawn_eventLapMarkerCollider_Parms, _hitResult), Z_Construct_UScriptStruct_FHitResult, METADATA_PARAMS(Z_Construct_UFunction_AFYPPawn_LapMarkerCollider_Statics::NewProp__hitResult_MetaData, ARRAY_COUNT(Z_Construct_UFunction_AFYPPawn_LapMarkerCollider_Statics::NewProp__hitResult_MetaData)) };
	void Z_Construct_UFunction_AFYPPawn_LapMarkerCollider_Statics::NewProp__bFromSweep_SetBit(void* Obj)
	{
		((FYPPawn_eventLapMarkerCollider_Parms*)Obj)->_bFromSweep = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_AFYPPawn_LapMarkerCollider_Statics::NewProp__bFromSweep = { "_bFromSweep", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(FYPPawn_eventLapMarkerCollider_Parms), &Z_Construct_UFunction_AFYPPawn_LapMarkerCollider_Statics::NewProp__bFromSweep_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UFunction_AFYPPawn_LapMarkerCollider_Statics::NewProp__otherBodyIndex = { "_otherBodyIndex", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FYPPawn_eventLapMarkerCollider_Parms, _otherBodyIndex), METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AFYPPawn_LapMarkerCollider_Statics::NewProp__otherComp_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AFYPPawn_LapMarkerCollider_Statics::NewProp__otherComp = { "_otherComp", nullptr, (EPropertyFlags)0x0010000000080080, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FYPPawn_eventLapMarkerCollider_Parms, _otherComp), Z_Construct_UClass_UPrimitiveComponent_NoRegister, METADATA_PARAMS(Z_Construct_UFunction_AFYPPawn_LapMarkerCollider_Statics::NewProp__otherComp_MetaData, ARRAY_COUNT(Z_Construct_UFunction_AFYPPawn_LapMarkerCollider_Statics::NewProp__otherComp_MetaData)) };
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AFYPPawn_LapMarkerCollider_Statics::NewProp__otherActor = { "_otherActor", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FYPPawn_eventLapMarkerCollider_Parms, _otherActor), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AFYPPawn_LapMarkerCollider_Statics::NewProp__overlappedComponent_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AFYPPawn_LapMarkerCollider_Statics::NewProp__overlappedComponent = { "_overlappedComponent", nullptr, (EPropertyFlags)0x0010000000080080, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FYPPawn_eventLapMarkerCollider_Parms, _overlappedComponent), Z_Construct_UClass_UPrimitiveComponent_NoRegister, METADATA_PARAMS(Z_Construct_UFunction_AFYPPawn_LapMarkerCollider_Statics::NewProp__overlappedComponent_MetaData, ARRAY_COUNT(Z_Construct_UFunction_AFYPPawn_LapMarkerCollider_Statics::NewProp__overlappedComponent_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AFYPPawn_LapMarkerCollider_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AFYPPawn_LapMarkerCollider_Statics::NewProp__hitResult,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AFYPPawn_LapMarkerCollider_Statics::NewProp__bFromSweep,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AFYPPawn_LapMarkerCollider_Statics::NewProp__otherBodyIndex,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AFYPPawn_LapMarkerCollider_Statics::NewProp__otherComp,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AFYPPawn_LapMarkerCollider_Statics::NewProp__otherActor,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AFYPPawn_LapMarkerCollider_Statics::NewProp__overlappedComponent,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AFYPPawn_LapMarkerCollider_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "FYP_Car_Body.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AFYPPawn_LapMarkerCollider_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AFYPPawn, nullptr, "LapMarkerCollider", nullptr, nullptr, sizeof(FYPPawn_eventLapMarkerCollider_Parms), Z_Construct_UFunction_AFYPPawn_LapMarkerCollider_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_AFYPPawn_LapMarkerCollider_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00420401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AFYPPawn_LapMarkerCollider_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_AFYPPawn_LapMarkerCollider_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AFYPPawn_LapMarkerCollider()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AFYPPawn_LapMarkerCollider_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_AFYPPawn_NoRegister()
	{
		return AFYPPawn::StaticClass();
	}
	struct Z_Construct_UClass_AFYPPawn_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_NorthWestRayDistanceUI_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_NorthWestRayDistanceUI;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_WestRayDistanceUI_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_WestRayDistanceUI;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_SouthWestRayDistanceUI_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_SouthWestRayDistanceUI;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_SouthRayDistanceUI_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_SouthRayDistanceUI;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_SouthEastRayDistanceUI_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_SouthEastRayDistanceUI;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_EastRayDistanceUI_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_EastRayDistanceUI;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_NorthEastRayDistanceUI_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_NorthEastRayDistanceUI;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_NorthRayDistanceUI_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_NorthRayDistanceUI;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_LapMultiplyerUI_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_LapMultiplyerUI;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_DistanceTraveledScoreUI_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_DistanceTraveledScoreUI;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_TimeLeft_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_TimeLeft;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_NorthWest_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_NorthWest;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_West_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_West;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_SouthWest_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_SouthWest;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_South_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_South;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_SouthEast_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_SouthEast;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_East_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_East;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_NorthEast_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_NorthEast;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_North_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_North;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_mp_collider_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_mp_collider;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_GearDisplayReverseColor_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_GearDisplayReverseColor;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_GearDisplayColor_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_GearDisplayColor;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_EngineSoundComponent_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_EngineSoundComponent;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_InCarGear_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_InCarGear;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_InCarSpeed_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_InCarSpeed;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Camera_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Camera;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_SpringArm_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_SpringArm;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AFYPPawn_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AWheeledVehicle,
		(UObject* (*)())Z_Construct_UPackage__Script_FYP,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_AFYPPawn_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_AFYPPawn_LapMarkerCollider, "LapMarkerCollider" }, // 1252950113
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AFYPPawn_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Navigation" },
		{ "IncludePath", "FYP_Car_Body.h" },
		{ "ModuleRelativePath", "FYP_Car_Body.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AFYPPawn_Statics::NewProp_NorthWestRayDistanceUI_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Display" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "FYP_Car_Body.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AFYPPawn_Statics::NewProp_NorthWestRayDistanceUI = { "NorthWestRayDistanceUI", nullptr, (EPropertyFlags)0x00100000000b001d, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AFYPPawn, NorthWestRayDistanceUI), Z_Construct_UClass_UTextRenderComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AFYPPawn_Statics::NewProp_NorthWestRayDistanceUI_MetaData, ARRAY_COUNT(Z_Construct_UClass_AFYPPawn_Statics::NewProp_NorthWestRayDistanceUI_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AFYPPawn_Statics::NewProp_WestRayDistanceUI_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Display" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "FYP_Car_Body.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AFYPPawn_Statics::NewProp_WestRayDistanceUI = { "WestRayDistanceUI", nullptr, (EPropertyFlags)0x00100000000b001d, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AFYPPawn, WestRayDistanceUI), Z_Construct_UClass_UTextRenderComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AFYPPawn_Statics::NewProp_WestRayDistanceUI_MetaData, ARRAY_COUNT(Z_Construct_UClass_AFYPPawn_Statics::NewProp_WestRayDistanceUI_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AFYPPawn_Statics::NewProp_SouthWestRayDistanceUI_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Display" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "FYP_Car_Body.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AFYPPawn_Statics::NewProp_SouthWestRayDistanceUI = { "SouthWestRayDistanceUI", nullptr, (EPropertyFlags)0x00100000000b001d, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AFYPPawn, SouthWestRayDistanceUI), Z_Construct_UClass_UTextRenderComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AFYPPawn_Statics::NewProp_SouthWestRayDistanceUI_MetaData, ARRAY_COUNT(Z_Construct_UClass_AFYPPawn_Statics::NewProp_SouthWestRayDistanceUI_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AFYPPawn_Statics::NewProp_SouthRayDistanceUI_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Display" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "FYP_Car_Body.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AFYPPawn_Statics::NewProp_SouthRayDistanceUI = { "SouthRayDistanceUI", nullptr, (EPropertyFlags)0x00100000000b001d, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AFYPPawn, SouthRayDistanceUI), Z_Construct_UClass_UTextRenderComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AFYPPawn_Statics::NewProp_SouthRayDistanceUI_MetaData, ARRAY_COUNT(Z_Construct_UClass_AFYPPawn_Statics::NewProp_SouthRayDistanceUI_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AFYPPawn_Statics::NewProp_SouthEastRayDistanceUI_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Display" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "FYP_Car_Body.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AFYPPawn_Statics::NewProp_SouthEastRayDistanceUI = { "SouthEastRayDistanceUI", nullptr, (EPropertyFlags)0x00100000000b001d, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AFYPPawn, SouthEastRayDistanceUI), Z_Construct_UClass_UTextRenderComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AFYPPawn_Statics::NewProp_SouthEastRayDistanceUI_MetaData, ARRAY_COUNT(Z_Construct_UClass_AFYPPawn_Statics::NewProp_SouthEastRayDistanceUI_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AFYPPawn_Statics::NewProp_EastRayDistanceUI_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Display" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "FYP_Car_Body.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AFYPPawn_Statics::NewProp_EastRayDistanceUI = { "EastRayDistanceUI", nullptr, (EPropertyFlags)0x00100000000b001d, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AFYPPawn, EastRayDistanceUI), Z_Construct_UClass_UTextRenderComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AFYPPawn_Statics::NewProp_EastRayDistanceUI_MetaData, ARRAY_COUNT(Z_Construct_UClass_AFYPPawn_Statics::NewProp_EastRayDistanceUI_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AFYPPawn_Statics::NewProp_NorthEastRayDistanceUI_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Display" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "FYP_Car_Body.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AFYPPawn_Statics::NewProp_NorthEastRayDistanceUI = { "NorthEastRayDistanceUI", nullptr, (EPropertyFlags)0x00100000000b001d, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AFYPPawn, NorthEastRayDistanceUI), Z_Construct_UClass_UTextRenderComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AFYPPawn_Statics::NewProp_NorthEastRayDistanceUI_MetaData, ARRAY_COUNT(Z_Construct_UClass_AFYPPawn_Statics::NewProp_NorthEastRayDistanceUI_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AFYPPawn_Statics::NewProp_NorthRayDistanceUI_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Display" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "FYP_Car_Body.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AFYPPawn_Statics::NewProp_NorthRayDistanceUI = { "NorthRayDistanceUI", nullptr, (EPropertyFlags)0x00100000000b001d, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AFYPPawn, NorthRayDistanceUI), Z_Construct_UClass_UTextRenderComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AFYPPawn_Statics::NewProp_NorthRayDistanceUI_MetaData, ARRAY_COUNT(Z_Construct_UClass_AFYPPawn_Statics::NewProp_NorthRayDistanceUI_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AFYPPawn_Statics::NewProp_LapMultiplyerUI_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Display" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "FYP_Car_Body.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AFYPPawn_Statics::NewProp_LapMultiplyerUI = { "LapMultiplyerUI", nullptr, (EPropertyFlags)0x00100000000b001d, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AFYPPawn, LapMultiplyerUI), Z_Construct_UClass_UTextRenderComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AFYPPawn_Statics::NewProp_LapMultiplyerUI_MetaData, ARRAY_COUNT(Z_Construct_UClass_AFYPPawn_Statics::NewProp_LapMultiplyerUI_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AFYPPawn_Statics::NewProp_DistanceTraveledScoreUI_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Display" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "FYP_Car_Body.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AFYPPawn_Statics::NewProp_DistanceTraveledScoreUI = { "DistanceTraveledScoreUI", nullptr, (EPropertyFlags)0x00100000000b001d, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AFYPPawn, DistanceTraveledScoreUI), Z_Construct_UClass_UTextRenderComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AFYPPawn_Statics::NewProp_DistanceTraveledScoreUI_MetaData, ARRAY_COUNT(Z_Construct_UClass_AFYPPawn_Statics::NewProp_DistanceTraveledScoreUI_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AFYPPawn_Statics::NewProp_TimeLeft_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Display" },
		{ "Comment", "//- Decliration Of UI Elements -//\x09\n" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "FYP_Car_Body.h" },
		{ "ToolTip", "- Decliration Of UI Elements -" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AFYPPawn_Statics::NewProp_TimeLeft = { "TimeLeft", nullptr, (EPropertyFlags)0x00100000000b001d, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AFYPPawn, TimeLeft), Z_Construct_UClass_UTextRenderComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AFYPPawn_Statics::NewProp_TimeLeft_MetaData, ARRAY_COUNT(Z_Construct_UClass_AFYPPawn_Statics::NewProp_TimeLeft_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AFYPPawn_Statics::NewProp_NorthWest_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Display" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "FYP_Car_Body.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AFYPPawn_Statics::NewProp_NorthWest = { "NorthWest", nullptr, (EPropertyFlags)0x00100000000b001d, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AFYPPawn, NorthWest), Z_Construct_UClass_USphereComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AFYPPawn_Statics::NewProp_NorthWest_MetaData, ARRAY_COUNT(Z_Construct_UClass_AFYPPawn_Statics::NewProp_NorthWest_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AFYPPawn_Statics::NewProp_West_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Display" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "FYP_Car_Body.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AFYPPawn_Statics::NewProp_West = { "West", nullptr, (EPropertyFlags)0x00100000000b001d, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AFYPPawn, West), Z_Construct_UClass_USphereComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AFYPPawn_Statics::NewProp_West_MetaData, ARRAY_COUNT(Z_Construct_UClass_AFYPPawn_Statics::NewProp_West_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AFYPPawn_Statics::NewProp_SouthWest_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Display" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "FYP_Car_Body.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AFYPPawn_Statics::NewProp_SouthWest = { "SouthWest", nullptr, (EPropertyFlags)0x00100000000b001d, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AFYPPawn, SouthWest), Z_Construct_UClass_USphereComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AFYPPawn_Statics::NewProp_SouthWest_MetaData, ARRAY_COUNT(Z_Construct_UClass_AFYPPawn_Statics::NewProp_SouthWest_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AFYPPawn_Statics::NewProp_South_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Display" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "FYP_Car_Body.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AFYPPawn_Statics::NewProp_South = { "South", nullptr, (EPropertyFlags)0x00100000000b001d, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AFYPPawn, South), Z_Construct_UClass_USphereComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AFYPPawn_Statics::NewProp_South_MetaData, ARRAY_COUNT(Z_Construct_UClass_AFYPPawn_Statics::NewProp_South_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AFYPPawn_Statics::NewProp_SouthEast_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Display" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "FYP_Car_Body.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AFYPPawn_Statics::NewProp_SouthEast = { "SouthEast", nullptr, (EPropertyFlags)0x00100000000b001d, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AFYPPawn, SouthEast), Z_Construct_UClass_USphereComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AFYPPawn_Statics::NewProp_SouthEast_MetaData, ARRAY_COUNT(Z_Construct_UClass_AFYPPawn_Statics::NewProp_SouthEast_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AFYPPawn_Statics::NewProp_East_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Display" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "FYP_Car_Body.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AFYPPawn_Statics::NewProp_East = { "East", nullptr, (EPropertyFlags)0x00100000000b001d, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AFYPPawn, East), Z_Construct_UClass_USphereComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AFYPPawn_Statics::NewProp_East_MetaData, ARRAY_COUNT(Z_Construct_UClass_AFYPPawn_Statics::NewProp_East_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AFYPPawn_Statics::NewProp_NorthEast_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Display" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "FYP_Car_Body.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AFYPPawn_Statics::NewProp_NorthEast = { "NorthEast", nullptr, (EPropertyFlags)0x00100000000b001d, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AFYPPawn, NorthEast), Z_Construct_UClass_USphereComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AFYPPawn_Statics::NewProp_NorthEast_MetaData, ARRAY_COUNT(Z_Construct_UClass_AFYPPawn_Statics::NewProp_NorthEast_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AFYPPawn_Statics::NewProp_North_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Display" },
		{ "Comment", "//- Required Data For Car RayCasts -//\n" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "FYP_Car_Body.h" },
		{ "ToolTip", "- Required Data For Car RayCasts -" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AFYPPawn_Statics::NewProp_North = { "North", nullptr, (EPropertyFlags)0x00100000000b001d, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AFYPPawn, North), Z_Construct_UClass_USphereComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AFYPPawn_Statics::NewProp_North_MetaData, ARRAY_COUNT(Z_Construct_UClass_AFYPPawn_Statics::NewProp_North_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AFYPPawn_Statics::NewProp_mp_collider_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Display" },
		{ "Comment", "//- Required Elements For Tracking Compleated Laps -//\n" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "FYP_Car_Body.h" },
		{ "ToolTip", "- Required Elements For Tracking Compleated Laps -" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AFYPPawn_Statics::NewProp_mp_collider = { "mp_collider", nullptr, (EPropertyFlags)0x00100000000b001d, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AFYPPawn, mp_collider), Z_Construct_UClass_UBoxComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AFYPPawn_Statics::NewProp_mp_collider_MetaData, ARRAY_COUNT(Z_Construct_UClass_AFYPPawn_Statics::NewProp_mp_collider_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AFYPPawn_Statics::NewProp_GearDisplayReverseColor_MetaData[] = {
		{ "Category", "Display" },
		{ "Comment", "/** The color of the incar gear text when in reverse */" },
		{ "ModuleRelativePath", "FYP_Car_Body.h" },
		{ "ToolTip", "The color of the incar gear text when in reverse" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UClass_AFYPPawn_Statics::NewProp_GearDisplayReverseColor = { "GearDisplayReverseColor", nullptr, (EPropertyFlags)0x0010000000030015, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AFYPPawn, GearDisplayReverseColor), Z_Construct_UScriptStruct_FColor, METADATA_PARAMS(Z_Construct_UClass_AFYPPawn_Statics::NewProp_GearDisplayReverseColor_MetaData, ARRAY_COUNT(Z_Construct_UClass_AFYPPawn_Statics::NewProp_GearDisplayReverseColor_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AFYPPawn_Statics::NewProp_GearDisplayColor_MetaData[] = {
		{ "Category", "Display" },
		{ "Comment", "/** The color of the incar gear text in forward gears */" },
		{ "ModuleRelativePath", "FYP_Car_Body.h" },
		{ "ToolTip", "The color of the incar gear text in forward gears" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UClass_AFYPPawn_Statics::NewProp_GearDisplayColor = { "GearDisplayColor", nullptr, (EPropertyFlags)0x0010000000030015, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AFYPPawn, GearDisplayColor), Z_Construct_UScriptStruct_FColor, METADATA_PARAMS(Z_Construct_UClass_AFYPPawn_Statics::NewProp_GearDisplayColor_MetaData, ARRAY_COUNT(Z_Construct_UClass_AFYPPawn_Statics::NewProp_GearDisplayColor_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AFYPPawn_Statics::NewProp_EngineSoundComponent_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Display" },
		{ "Comment", "/** Audio component for the engine sound */" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "FYP_Car_Body.h" },
		{ "ToolTip", "Audio component for the engine sound" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AFYPPawn_Statics::NewProp_EngineSoundComponent = { "EngineSoundComponent", nullptr, (EPropertyFlags)0x00400000000b001d, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AFYPPawn, EngineSoundComponent), Z_Construct_UClass_UAudioComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AFYPPawn_Statics::NewProp_EngineSoundComponent_MetaData, ARRAY_COUNT(Z_Construct_UClass_AFYPPawn_Statics::NewProp_EngineSoundComponent_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AFYPPawn_Statics::NewProp_InCarGear_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Display" },
		{ "Comment", "/** Text component for the In-Car gear */" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "FYP_Car_Body.h" },
		{ "ToolTip", "Text component for the In-Car gear" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AFYPPawn_Statics::NewProp_InCarGear = { "InCarGear", nullptr, (EPropertyFlags)0x00400000000b001d, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AFYPPawn, InCarGear), Z_Construct_UClass_UTextRenderComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AFYPPawn_Statics::NewProp_InCarGear_MetaData, ARRAY_COUNT(Z_Construct_UClass_AFYPPawn_Statics::NewProp_InCarGear_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AFYPPawn_Statics::NewProp_InCarSpeed_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Display" },
		{ "Comment", "/** Text component for the In-Car speed */" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "FYP_Car_Body.h" },
		{ "ToolTip", "Text component for the In-Car speed" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AFYPPawn_Statics::NewProp_InCarSpeed = { "InCarSpeed", nullptr, (EPropertyFlags)0x00400000000b001d, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AFYPPawn, InCarSpeed), Z_Construct_UClass_UTextRenderComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AFYPPawn_Statics::NewProp_InCarSpeed_MetaData, ARRAY_COUNT(Z_Construct_UClass_AFYPPawn_Statics::NewProp_InCarSpeed_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AFYPPawn_Statics::NewProp_Camera_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Camera" },
		{ "Comment", "/** Camera component that will be our viewpoint */" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "FYP_Car_Body.h" },
		{ "ToolTip", "Camera component that will be our viewpoint" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AFYPPawn_Statics::NewProp_Camera = { "Camera", nullptr, (EPropertyFlags)0x00400000000b001d, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AFYPPawn, Camera), Z_Construct_UClass_UCameraComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AFYPPawn_Statics::NewProp_Camera_MetaData, ARRAY_COUNT(Z_Construct_UClass_AFYPPawn_Statics::NewProp_Camera_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AFYPPawn_Statics::NewProp_SpringArm_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Camera" },
		{ "Comment", "/** Spring arm that will offset the camera */" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "FYP_Car_Body.h" },
		{ "ToolTip", "Spring arm that will offset the camera" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AFYPPawn_Statics::NewProp_SpringArm = { "SpringArm", nullptr, (EPropertyFlags)0x00400000000b001d, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AFYPPawn, SpringArm), Z_Construct_UClass_USpringArmComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AFYPPawn_Statics::NewProp_SpringArm_MetaData, ARRAY_COUNT(Z_Construct_UClass_AFYPPawn_Statics::NewProp_SpringArm_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AFYPPawn_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFYPPawn_Statics::NewProp_NorthWestRayDistanceUI,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFYPPawn_Statics::NewProp_WestRayDistanceUI,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFYPPawn_Statics::NewProp_SouthWestRayDistanceUI,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFYPPawn_Statics::NewProp_SouthRayDistanceUI,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFYPPawn_Statics::NewProp_SouthEastRayDistanceUI,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFYPPawn_Statics::NewProp_EastRayDistanceUI,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFYPPawn_Statics::NewProp_NorthEastRayDistanceUI,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFYPPawn_Statics::NewProp_NorthRayDistanceUI,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFYPPawn_Statics::NewProp_LapMultiplyerUI,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFYPPawn_Statics::NewProp_DistanceTraveledScoreUI,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFYPPawn_Statics::NewProp_TimeLeft,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFYPPawn_Statics::NewProp_NorthWest,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFYPPawn_Statics::NewProp_West,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFYPPawn_Statics::NewProp_SouthWest,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFYPPawn_Statics::NewProp_South,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFYPPawn_Statics::NewProp_SouthEast,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFYPPawn_Statics::NewProp_East,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFYPPawn_Statics::NewProp_NorthEast,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFYPPawn_Statics::NewProp_North,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFYPPawn_Statics::NewProp_mp_collider,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFYPPawn_Statics::NewProp_GearDisplayReverseColor,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFYPPawn_Statics::NewProp_GearDisplayColor,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFYPPawn_Statics::NewProp_EngineSoundComponent,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFYPPawn_Statics::NewProp_InCarGear,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFYPPawn_Statics::NewProp_InCarSpeed,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFYPPawn_Statics::NewProp_Camera,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFYPPawn_Statics::NewProp_SpringArm,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_AFYPPawn_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AFYPPawn>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AFYPPawn_Statics::ClassParams = {
		&AFYPPawn::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_AFYPPawn_Statics::PropPointers,
		nullptr,
		ARRAY_COUNT(DependentSingletons),
		ARRAY_COUNT(FuncInfo),
		ARRAY_COUNT(Z_Construct_UClass_AFYPPawn_Statics::PropPointers),
		0,
		0x008000A0u,
		METADATA_PARAMS(Z_Construct_UClass_AFYPPawn_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_AFYPPawn_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AFYPPawn()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AFYPPawn_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AFYPPawn, 2372647606);
	template<> FYP_API UClass* StaticClass<AFYPPawn>()
	{
		return AFYPPawn::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AFYPPawn(Z_Construct_UClass_AFYPPawn, &AFYPPawn::StaticClass, TEXT("/Script/FYP"), TEXT("AFYPPawn"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AFYPPawn);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
