// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef FYP_FYP_Car_Hud_generated_h
#error "FYP_Car_Hud.generated.h already included, missing '#pragma once' in FYP_Car_Hud.h"
#endif
#define FYP_FYP_Car_Hud_generated_h

#define FYP_Source_FYP_FYP_Car_Hud_h_12_RPC_WRAPPERS
#define FYP_Source_FYP_FYP_Car_Hud_h_12_RPC_WRAPPERS_NO_PURE_DECLS
#define FYP_Source_FYP_FYP_Car_Hud_h_12_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAFYPHud(); \
	friend struct Z_Construct_UClass_AFYPHud_Statics; \
public: \
	DECLARE_CLASS(AFYPHud, AHUD, COMPILED_IN_FLAGS(0 | CLASS_Transient | CLASS_Config), CASTCLASS_None, TEXT("/Script/FYP"), NO_API) \
	DECLARE_SERIALIZER(AFYPHud)


#define FYP_Source_FYP_FYP_Car_Hud_h_12_INCLASS \
private: \
	static void StaticRegisterNativesAFYPHud(); \
	friend struct Z_Construct_UClass_AFYPHud_Statics; \
public: \
	DECLARE_CLASS(AFYPHud, AHUD, COMPILED_IN_FLAGS(0 | CLASS_Transient | CLASS_Config), CASTCLASS_None, TEXT("/Script/FYP"), NO_API) \
	DECLARE_SERIALIZER(AFYPHud)


#define FYP_Source_FYP_FYP_Car_Hud_h_12_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AFYPHud(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AFYPHud) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AFYPHud); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AFYPHud); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AFYPHud(AFYPHud&&); \
	NO_API AFYPHud(const AFYPHud&); \
public:


#define FYP_Source_FYP_FYP_Car_Hud_h_12_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AFYPHud(AFYPHud&&); \
	NO_API AFYPHud(const AFYPHud&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AFYPHud); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AFYPHud); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AFYPHud)


#define FYP_Source_FYP_FYP_Car_Hud_h_12_PRIVATE_PROPERTY_OFFSET
#define FYP_Source_FYP_FYP_Car_Hud_h_9_PROLOG
#define FYP_Source_FYP_FYP_Car_Hud_h_12_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FYP_Source_FYP_FYP_Car_Hud_h_12_PRIVATE_PROPERTY_OFFSET \
	FYP_Source_FYP_FYP_Car_Hud_h_12_RPC_WRAPPERS \
	FYP_Source_FYP_FYP_Car_Hud_h_12_INCLASS \
	FYP_Source_FYP_FYP_Car_Hud_h_12_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define FYP_Source_FYP_FYP_Car_Hud_h_12_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FYP_Source_FYP_FYP_Car_Hud_h_12_PRIVATE_PROPERTY_OFFSET \
	FYP_Source_FYP_FYP_Car_Hud_h_12_RPC_WRAPPERS_NO_PURE_DECLS \
	FYP_Source_FYP_FYP_Car_Hud_h_12_INCLASS_NO_PURE_DECLS \
	FYP_Source_FYP_FYP_Car_Hud_h_12_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> FYP_API UClass* StaticClass<class AFYPHud>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FYP_Source_FYP_FYP_Car_Hud_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
