// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "FYPGameMode.h"
#include "FYP_Car_Body.h"
#include "FYP_Car_Hud.h"

AFYPGameMode::AFYPGameMode()
{
	DefaultPawnClass = AFYPPawn::StaticClass();
	HUDClass = AFYPHud::StaticClass();
}
