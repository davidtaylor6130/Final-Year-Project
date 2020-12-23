// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "FYP/CarRayCasts.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeCarRayCasts() {}
// Cross Module References
	FYP_API UClass* Z_Construct_UClass_ACarRayCasts_NoRegister();
	FYP_API UClass* Z_Construct_UClass_ACarRayCasts();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	UPackage* Z_Construct_UPackage__Script_FYP();
	ENGINE_API UClass* Z_Construct_UClass_USphereComponent_NoRegister();
// End Cross Module References
	void ACarRayCasts::StaticRegisterNativesACarRayCasts()
	{
	}
	UClass* Z_Construct_UClass_ACarRayCasts_NoRegister()
	{
		return ACarRayCasts::StaticClass();
	}
	struct Z_Construct_UClass_ACarRayCasts_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_StartLocation_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_StartLocation;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ACarRayCasts_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_FYP,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ACarRayCasts_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "CarRayCasts.h" },
		{ "ModuleRelativePath", "CarRayCasts.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ACarRayCasts_Statics::NewProp_StartLocation_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Display" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "CarRayCasts.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ACarRayCasts_Statics::NewProp_StartLocation = { "StartLocation", nullptr, (EPropertyFlags)0x00100000000b001d, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ACarRayCasts, StartLocation), Z_Construct_UClass_USphereComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_ACarRayCasts_Statics::NewProp_StartLocation_MetaData, ARRAY_COUNT(Z_Construct_UClass_ACarRayCasts_Statics::NewProp_StartLocation_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ACarRayCasts_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACarRayCasts_Statics::NewProp_StartLocation,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_ACarRayCasts_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ACarRayCasts>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_ACarRayCasts_Statics::ClassParams = {
		&ACarRayCasts::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_ACarRayCasts_Statics::PropPointers,
		nullptr,
		ARRAY_COUNT(DependentSingletons),
		0,
		ARRAY_COUNT(Z_Construct_UClass_ACarRayCasts_Statics::PropPointers),
		0,
		0x009000A0u,
		METADATA_PARAMS(Z_Construct_UClass_ACarRayCasts_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_ACarRayCasts_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ACarRayCasts()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_ACarRayCasts_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(ACarRayCasts, 853139279);
	template<> FYP_API UClass* StaticClass<ACarRayCasts>()
	{
		return ACarRayCasts::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_ACarRayCasts(Z_Construct_UClass_ACarRayCasts, &ACarRayCasts::StaticClass, TEXT("/Script/FYP"), TEXT("ACarRayCasts"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(ACarRayCasts);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
