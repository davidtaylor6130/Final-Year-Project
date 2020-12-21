// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "FYP/FYPGameMode.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeFYPGameMode() {}
// Cross Module References
	FYP_API UClass* Z_Construct_UClass_AFYPGameMode_NoRegister();
	FYP_API UClass* Z_Construct_UClass_AFYPGameMode();
	ENGINE_API UClass* Z_Construct_UClass_AGameModeBase();
	UPackage* Z_Construct_UPackage__Script_FYP();
// End Cross Module References
	void AFYPGameMode::StaticRegisterNativesAFYPGameMode()
	{
	}
	UClass* Z_Construct_UClass_AFYPGameMode_NoRegister()
	{
		return AFYPGameMode::StaticClass();
	}
	struct Z_Construct_UClass_AFYPGameMode_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AFYPGameMode_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AGameModeBase,
		(UObject* (*)())Z_Construct_UPackage__Script_FYP,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AFYPGameMode_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering Utilities|Transformation" },
		{ "IncludePath", "FYPGameMode.h" },
		{ "ModuleRelativePath", "FYPGameMode.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_AFYPGameMode_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AFYPGameMode>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AFYPGameMode_Statics::ClassParams = {
		&AFYPGameMode::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x008802A8u,
		METADATA_PARAMS(Z_Construct_UClass_AFYPGameMode_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_AFYPGameMode_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AFYPGameMode()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AFYPGameMode_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AFYPGameMode, 1564780401);
	template<> FYP_API UClass* StaticClass<AFYPGameMode>()
	{
		return AFYPGameMode::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AFYPGameMode(Z_Construct_UClass_AFYPGameMode, &AFYPGameMode::StaticClass, TEXT("/Script/FYP"), TEXT("AFYPGameMode"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AFYPGameMode);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
