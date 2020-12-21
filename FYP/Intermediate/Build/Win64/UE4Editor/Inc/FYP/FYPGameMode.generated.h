// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef FYP_FYPGameMode_generated_h
#error "FYPGameMode.generated.h already included, missing '#pragma once' in FYPGameMode.h"
#endif
#define FYP_FYPGameMode_generated_h

#define FYP_Source_FYP_FYPGameMode_h_12_RPC_WRAPPERS
#define FYP_Source_FYP_FYPGameMode_h_12_RPC_WRAPPERS_NO_PURE_DECLS
#define FYP_Source_FYP_FYPGameMode_h_12_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAFYPGameMode(); \
	friend struct Z_Construct_UClass_AFYPGameMode_Statics; \
public: \
	DECLARE_CLASS(AFYPGameMode, AGameModeBase, COMPILED_IN_FLAGS(0 | CLASS_Transient), CASTCLASS_None, TEXT("/Script/FYP"), FYP_API) \
	DECLARE_SERIALIZER(AFYPGameMode)


#define FYP_Source_FYP_FYPGameMode_h_12_INCLASS \
private: \
	static void StaticRegisterNativesAFYPGameMode(); \
	friend struct Z_Construct_UClass_AFYPGameMode_Statics; \
public: \
	DECLARE_CLASS(AFYPGameMode, AGameModeBase, COMPILED_IN_FLAGS(0 | CLASS_Transient), CASTCLASS_None, TEXT("/Script/FYP"), FYP_API) \
	DECLARE_SERIALIZER(AFYPGameMode)


#define FYP_Source_FYP_FYPGameMode_h_12_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	FYP_API AFYPGameMode(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AFYPGameMode) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(FYP_API, AFYPGameMode); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AFYPGameMode); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	FYP_API AFYPGameMode(AFYPGameMode&&); \
	FYP_API AFYPGameMode(const AFYPGameMode&); \
public:


#define FYP_Source_FYP_FYPGameMode_h_12_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	FYP_API AFYPGameMode(AFYPGameMode&&); \
	FYP_API AFYPGameMode(const AFYPGameMode&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(FYP_API, AFYPGameMode); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AFYPGameMode); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AFYPGameMode)


#define FYP_Source_FYP_FYPGameMode_h_12_PRIVATE_PROPERTY_OFFSET
#define FYP_Source_FYP_FYPGameMode_h_9_PROLOG
#define FYP_Source_FYP_FYPGameMode_h_12_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FYP_Source_FYP_FYPGameMode_h_12_PRIVATE_PROPERTY_OFFSET \
	FYP_Source_FYP_FYPGameMode_h_12_RPC_WRAPPERS \
	FYP_Source_FYP_FYPGameMode_h_12_INCLASS \
	FYP_Source_FYP_FYPGameMode_h_12_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define FYP_Source_FYP_FYPGameMode_h_12_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FYP_Source_FYP_FYPGameMode_h_12_PRIVATE_PROPERTY_OFFSET \
	FYP_Source_FYP_FYPGameMode_h_12_RPC_WRAPPERS_NO_PURE_DECLS \
	FYP_Source_FYP_FYPGameMode_h_12_INCLASS_NO_PURE_DECLS \
	FYP_Source_FYP_FYPGameMode_h_12_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> FYP_API UClass* StaticClass<class AFYPGameMode>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FYP_Source_FYP_FYPGameMode_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
