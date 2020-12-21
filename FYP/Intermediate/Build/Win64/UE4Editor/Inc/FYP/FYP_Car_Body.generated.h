// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef FYP_FYP_Car_Body_generated_h
#error "FYP_Car_Body.generated.h already included, missing '#pragma once' in FYP_Car_Body.h"
#endif
#define FYP_FYP_Car_Body_generated_h

#define FYP_Source_FYP_FYP_Car_Body_h_19_RPC_WRAPPERS
#define FYP_Source_FYP_FYP_Car_Body_h_19_RPC_WRAPPERS_NO_PURE_DECLS
#define FYP_Source_FYP_FYP_Car_Body_h_19_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAFYPPawn(); \
	friend struct Z_Construct_UClass_AFYPPawn_Statics; \
public: \
	DECLARE_CLASS(AFYPPawn, AWheeledVehicle, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/FYP"), NO_API) \
	DECLARE_SERIALIZER(AFYPPawn)


#define FYP_Source_FYP_FYP_Car_Body_h_19_INCLASS \
private: \
	static void StaticRegisterNativesAFYPPawn(); \
	friend struct Z_Construct_UClass_AFYPPawn_Statics; \
public: \
	DECLARE_CLASS(AFYPPawn, AWheeledVehicle, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/FYP"), NO_API) \
	DECLARE_SERIALIZER(AFYPPawn)


#define FYP_Source_FYP_FYP_Car_Body_h_19_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AFYPPawn(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AFYPPawn) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AFYPPawn); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AFYPPawn); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AFYPPawn(AFYPPawn&&); \
	NO_API AFYPPawn(const AFYPPawn&); \
public:


#define FYP_Source_FYP_FYP_Car_Body_h_19_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AFYPPawn(AFYPPawn&&); \
	NO_API AFYPPawn(const AFYPPawn&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AFYPPawn); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AFYPPawn); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AFYPPawn)


#define FYP_Source_FYP_FYP_Car_Body_h_19_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__SpringArm() { return STRUCT_OFFSET(AFYPPawn, SpringArm); } \
	FORCEINLINE static uint32 __PPO__Camera() { return STRUCT_OFFSET(AFYPPawn, Camera); } \
	FORCEINLINE static uint32 __PPO__InCarSpeed() { return STRUCT_OFFSET(AFYPPawn, InCarSpeed); } \
	FORCEINLINE static uint32 __PPO__InCarGear() { return STRUCT_OFFSET(AFYPPawn, InCarGear); } \
	FORCEINLINE static uint32 __PPO__EngineSoundComponent() { return STRUCT_OFFSET(AFYPPawn, EngineSoundComponent); } \
	FORCEINLINE static uint32 __PPO__TimeLeft() { return STRUCT_OFFSET(AFYPPawn, TimeLeft); } \
	FORCEINLINE static uint32 __PPO__NorthRayDistanceUI() { return STRUCT_OFFSET(AFYPPawn, NorthRayDistanceUI); } \
	FORCEINLINE static uint32 __PPO__NorthEastRayDistanceUI() { return STRUCT_OFFSET(AFYPPawn, NorthEastRayDistanceUI); } \
	FORCEINLINE static uint32 __PPO__EastRayDistanceUI() { return STRUCT_OFFSET(AFYPPawn, EastRayDistanceUI); } \
	FORCEINLINE static uint32 __PPO__SouthEastRayDistanceUI() { return STRUCT_OFFSET(AFYPPawn, SouthEastRayDistanceUI); } \
	FORCEINLINE static uint32 __PPO__SouthRayDistanceUI() { return STRUCT_OFFSET(AFYPPawn, SouthRayDistanceUI); } \
	FORCEINLINE static uint32 __PPO__SouthWestRayDistanceUI() { return STRUCT_OFFSET(AFYPPawn, SouthWestRayDistanceUI); } \
	FORCEINLINE static uint32 __PPO__WestRayDistanceUI() { return STRUCT_OFFSET(AFYPPawn, WestRayDistanceUI); } \
	FORCEINLINE static uint32 __PPO__NorthWestRayDistanceUI() { return STRUCT_OFFSET(AFYPPawn, NorthWestRayDistanceUI); }


#define FYP_Source_FYP_FYP_Car_Body_h_16_PROLOG
#define FYP_Source_FYP_FYP_Car_Body_h_19_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FYP_Source_FYP_FYP_Car_Body_h_19_PRIVATE_PROPERTY_OFFSET \
	FYP_Source_FYP_FYP_Car_Body_h_19_RPC_WRAPPERS \
	FYP_Source_FYP_FYP_Car_Body_h_19_INCLASS \
	FYP_Source_FYP_FYP_Car_Body_h_19_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define FYP_Source_FYP_FYP_Car_Body_h_19_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FYP_Source_FYP_FYP_Car_Body_h_19_PRIVATE_PROPERTY_OFFSET \
	FYP_Source_FYP_FYP_Car_Body_h_19_RPC_WRAPPERS_NO_PURE_DECLS \
	FYP_Source_FYP_FYP_Car_Body_h_19_INCLASS_NO_PURE_DECLS \
	FYP_Source_FYP_FYP_Car_Body_h_19_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> FYP_API UClass* StaticClass<class AFYPPawn>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FYP_Source_FYP_FYP_Car_Body_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
