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

#define FYP_Source_FYP_FYP_Car_Body_h_37_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execAICarControl) \
	{ \
		P_GET_PROPERTY(UFloatProperty,Z_Param_LR); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_FB); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->AICarControl(Z_Param_LR,Z_Param_FB); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetUserCarInputs) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->GetUserCarInputs(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetNorthWestInput) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(float*)Z_Param__Result=P_THIS->GetNorthWestInput(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetWestInput) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(float*)Z_Param__Result=P_THIS->GetWestInput(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetSouthWestInput) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(float*)Z_Param__Result=P_THIS->GetSouthWestInput(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetSouthInput) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(float*)Z_Param__Result=P_THIS->GetSouthInput(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetSouthEastInput) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(float*)Z_Param__Result=P_THIS->GetSouthEastInput(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetEastInput) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(float*)Z_Param__Result=P_THIS->GetEastInput(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetNorthEastInput) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(float*)Z_Param__Result=P_THIS->GetNorthEastInput(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetNorthInput) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(float*)Z_Param__Result=P_THIS->GetNorthInput(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execInputDataAgmentation) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->InputDataAgmentation(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execUpdateUIElements) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->UpdateUIElements(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execUpdateCarSpeed) \
	{ \
		P_GET_PROPERTY(UFloatProperty,Z_Param_Delta); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->UpdateCarSpeed(Z_Param_Delta); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execUpdateRayCasts) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->UpdateRayCasts(); \
		P_NATIVE_END; \
	} \
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


#define FYP_Source_FYP_FYP_Car_Body_h_37_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execAICarControl) \
	{ \
		P_GET_PROPERTY(UFloatProperty,Z_Param_LR); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_FB); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->AICarControl(Z_Param_LR,Z_Param_FB); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetUserCarInputs) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->GetUserCarInputs(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetNorthWestInput) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(float*)Z_Param__Result=P_THIS->GetNorthWestInput(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetWestInput) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(float*)Z_Param__Result=P_THIS->GetWestInput(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetSouthWestInput) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(float*)Z_Param__Result=P_THIS->GetSouthWestInput(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetSouthInput) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(float*)Z_Param__Result=P_THIS->GetSouthInput(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetSouthEastInput) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(float*)Z_Param__Result=P_THIS->GetSouthEastInput(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetEastInput) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(float*)Z_Param__Result=P_THIS->GetEastInput(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetNorthEastInput) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(float*)Z_Param__Result=P_THIS->GetNorthEastInput(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetNorthInput) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(float*)Z_Param__Result=P_THIS->GetNorthInput(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execInputDataAgmentation) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->InputDataAgmentation(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execUpdateUIElements) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->UpdateUIElements(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execUpdateCarSpeed) \
	{ \
		P_GET_PROPERTY(UFloatProperty,Z_Param_Delta); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->UpdateCarSpeed(Z_Param_Delta); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execUpdateRayCasts) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->UpdateRayCasts(); \
		P_NATIVE_END; \
	} \
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


#define FYP_Source_FYP_FYP_Car_Body_h_37_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAFYPPawn(); \
	friend struct Z_Construct_UClass_AFYPPawn_Statics; \
public: \
	DECLARE_CLASS(AFYPPawn, AWheeledVehicle, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/FYP"), NO_API) \
	DECLARE_SERIALIZER(AFYPPawn)


#define FYP_Source_FYP_FYP_Car_Body_h_37_INCLASS \
private: \
	static void StaticRegisterNativesAFYPPawn(); \
	friend struct Z_Construct_UClass_AFYPPawn_Statics; \
public: \
	DECLARE_CLASS(AFYPPawn, AWheeledVehicle, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/FYP"), NO_API) \
	DECLARE_SERIALIZER(AFYPPawn)


#define FYP_Source_FYP_FYP_Car_Body_h_37_STANDARD_CONSTRUCTORS \
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


#define FYP_Source_FYP_FYP_Car_Body_h_37_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AFYPPawn(AFYPPawn&&); \
	NO_API AFYPPawn(const AFYPPawn&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AFYPPawn); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AFYPPawn); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AFYPPawn)


#define FYP_Source_FYP_FYP_Car_Body_h_37_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__SpringArm() { return STRUCT_OFFSET(AFYPPawn, SpringArm); } \
	FORCEINLINE static uint32 __PPO__Camera() { return STRUCT_OFFSET(AFYPPawn, Camera); } \
	FORCEINLINE static uint32 __PPO__InCarSpeed() { return STRUCT_OFFSET(AFYPPawn, InCarSpeed); } \
	FORCEINLINE static uint32 __PPO__InCarGear() { return STRUCT_OFFSET(AFYPPawn, InCarGear); } \
	FORCEINLINE static uint32 __PPO__EngineSoundComponent() { return STRUCT_OFFSET(AFYPPawn, EngineSoundComponent); }


#define FYP_Source_FYP_FYP_Car_Body_h_34_PROLOG
#define FYP_Source_FYP_FYP_Car_Body_h_37_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FYP_Source_FYP_FYP_Car_Body_h_37_PRIVATE_PROPERTY_OFFSET \
	FYP_Source_FYP_FYP_Car_Body_h_37_RPC_WRAPPERS \
	FYP_Source_FYP_FYP_Car_Body_h_37_INCLASS \
	FYP_Source_FYP_FYP_Car_Body_h_37_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define FYP_Source_FYP_FYP_Car_Body_h_37_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FYP_Source_FYP_FYP_Car_Body_h_37_PRIVATE_PROPERTY_OFFSET \
	FYP_Source_FYP_FYP_Car_Body_h_37_RPC_WRAPPERS_NO_PURE_DECLS \
	FYP_Source_FYP_FYP_Car_Body_h_37_INCLASS_NO_PURE_DECLS \
	FYP_Source_FYP_FYP_Car_Body_h_37_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> FYP_API UClass* StaticClass<class AFYPPawn>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FYP_Source_FYP_FYP_Car_Body_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
