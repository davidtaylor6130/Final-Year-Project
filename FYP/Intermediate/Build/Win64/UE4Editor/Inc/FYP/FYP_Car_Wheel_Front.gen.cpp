// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "FYP/FYP_Car_Wheel_Front.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeFYP_Car_Wheel_Front() {}
// Cross Module References
	FYP_API UClass* Z_Construct_UClass_UFYPWheelFront_NoRegister();
	FYP_API UClass* Z_Construct_UClass_UFYPWheelFront();
	PHYSXVEHICLES_API UClass* Z_Construct_UClass_UVehicleWheel();
	UPackage* Z_Construct_UPackage__Script_FYP();
// End Cross Module References
	void UFYPWheelFront::StaticRegisterNativesUFYPWheelFront()
	{
	}
	UClass* Z_Construct_UClass_UFYPWheelFront_NoRegister()
	{
		return UFYPWheelFront::StaticClass();
	}
	struct Z_Construct_UClass_UFYPWheelFront_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UFYPWheelFront_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UVehicleWheel,
		(UObject* (*)())Z_Construct_UPackage__Script_FYP,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UFYPWheelFront_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "FYP_Car_Wheel_Front.h" },
		{ "ModuleRelativePath", "FYP_Car_Wheel_Front.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UFYPWheelFront_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UFYPWheelFront>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UFYPWheelFront_Statics::ClassParams = {
		&UFYPWheelFront::StaticClass,
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
		0x008000A0u,
		METADATA_PARAMS(Z_Construct_UClass_UFYPWheelFront_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_UFYPWheelFront_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UFYPWheelFront()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UFYPWheelFront_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UFYPWheelFront, 4239334778);
	template<> FYP_API UClass* StaticClass<UFYPWheelFront>()
	{
		return UFYPWheelFront::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UFYPWheelFront(Z_Construct_UClass_UFYPWheelFront, &UFYPWheelFront::StaticClass, TEXT("/Script/FYP"), TEXT("UFYPWheelFront"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UFYPWheelFront);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
