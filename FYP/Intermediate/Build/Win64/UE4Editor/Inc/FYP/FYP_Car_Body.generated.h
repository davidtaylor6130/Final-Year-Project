// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UPrimitiveComponent;
class AActor;
struct FHitResult;
#ifdef FYP_FYP_Car_Body_generated_h
#error "FYP_Car_Body.generated.h already included, missing '#pragma once' in FYP_Car_Body.h"
#endif
#define FYP_FYP_Car_Body_generated_h

#define FYP_Source_FYP_FYP_Car_Body_h_22_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execLapMarkerCollider) \
	{ \
		P_GET_OBJECT(UPrimitiveComponent,Z_Param__overlappedComponent); \
		P_GET_OBJECT(AActor,Z_Param__otherActor); \
		P_GET_OBJECT(UPrimitiveComponent,Z_Param__otherComp); \
		P_GET_PROPERTY(UIntProperty,Z_Param__otherBodyIndex); \
		P_GET_UBOOL(Z_Param__bFromSweep); \
		P_GET_STRUCT_REF(FHitResult,Z_Param_Out__hitResult); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->LapMarkerCollider(Z_Param__overlappedComponent,Z_Param__otherActor,Z_Param__otherComp,Z_Param__otherBodyIndex,Z_Param__bFromSweep,Z_Param_Out__hitResult); \
		P_NATIVE_END; \
	}


#define FYP_Source_FYP_FYP_Car_Body_h_22_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execLapMarkerCollider) \
	{ \
		P_GET_OBJECT(UPrimitiveComponent,Z_Param__overlappedComponent); \
		P_GET_OBJECT(AActor,Z_Param__otherActor); \
		P_GET_OBJECT(UPrimitiveComponent,Z_Param__otherComp); \
		P_GET_PROPERTY(UIntProperty,Z_Param__otherBodyIndex); \
		P_GET_UBOOL(Z_Param__bFromSweep); \
		P_GET_STRUCT_REF(FHitResult,Z_Param_Out__hitResult); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->LapMarkerCollider(Z_Param__overlappedComponent,Z_Param__otherActor,Z_Param__otherComp,Z_Param__otherBodyIndex,Z_Param__bFromSweep,Z_Param_Out__hitResult); \
		P_NATIVE_END; \
	}


#define FYP_Source_FYP_FYP_Car_Body_h_22_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAFYPPawn(); \
	friend struct Z_Construct_UClass_AFYPPawn_Statics; \
public: \
	DECLARE_CLASS(AFYPPawn, AWheeledVehicle, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/FYP"), NO_API) \
	DECLARE_SERIALIZER(AFYPPawn)


#define FYP_Source_FYP_FYP_Car_Body_h_22_INCLASS \
private: \
	static void StaticRegisterNativesAFYPPawn(); \
	friend struct Z_Construct_UClass_AFYPPawn_Statics; \
public: \
	DECLARE_CLASS(AFYPPawn, AWheeledVehicle, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/FYP"), NO_API) \
	DECLARE_SERIALIZER(AFYPPawn)


#define FYP_Source_FYP_FYP_Car_Body_h_22_STANDARD_CONSTRUCTORS \
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


#define FYP_Source_FYP_FYP_Car_Body_h_22_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AFYPPawn(AFYPPawn&&); \
	NO_API AFYPPawn(const AFYPPawn&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AFYPPawn); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AFYPPawn); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AFYPPawn)


#define FYP_Source_FYP_FYP_Car_Body_h_22_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__SpringArm() { return STRUCT_OFFSET(AFYPPawn, SpringArm); } \
	FORCEINLINE static uint32 __PPO__Camera() { return STRUCT_OFFSET(AFYPPawn, Camera); } \
	FORCEINLINE static uint32 __PPO__InCarSpeed() { return STRUCT_OFFSET(AFYPPawn, InCarSpeed); } \
	FORCEINLINE static uint32 __PPO__InCarGear() { return STRUCT_OFFSET(AFYPPawn, InCarGear); } \
	FORCEINLINE static uint32 __PPO__EngineSoundComponent() { return STRUCT_OFFSET(AFYPPawn, EngineSoundComponent); }


#define FYP_Source_FYP_FYP_Car_Body_h_19_PROLOG
#define FYP_Source_FYP_FYP_Car_Body_h_22_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FYP_Source_FYP_FYP_Car_Body_h_22_PRIVATE_PROPERTY_OFFSET \
	FYP_Source_FYP_FYP_Car_Body_h_22_RPC_WRAPPERS \
	FYP_Source_FYP_FYP_Car_Body_h_22_INCLASS \
	FYP_Source_FYP_FYP_Car_Body_h_22_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define FYP_Source_FYP_FYP_Car_Body_h_22_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FYP_Source_FYP_FYP_Car_Body_h_22_PRIVATE_PROPERTY_OFFSET \
	FYP_Source_FYP_FYP_Car_Body_h_22_RPC_WRAPPERS_NO_PURE_DECLS \
	FYP_Source_FYP_FYP_Car_Body_h_22_INCLASS_NO_PURE_DECLS \
	FYP_Source_FYP_FYP_Car_Body_h_22_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> FYP_API UClass* StaticClass<class AFYPPawn>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FYP_Source_FYP_FYP_Car_Body_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
