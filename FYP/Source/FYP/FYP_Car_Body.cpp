// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "FYP_Car_Body.h"
#include "FYP_Car_Wheel_Front.h"
#include "FYP_Car_Wheel_Rear.h"
#include "FYP_Car_Hud.h"
#include "Components/SkeletalMeshComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/InputComponent.h"
#include "Components/TextRenderComponent.h"
#include "Components/AudioComponent.h"
#include "Sound/SoundCue.h"
#include "PhysicalMaterials/PhysicalMaterial.h"
#include "WheeledVehicleMovementComponent4W.h"
#include "Engine/SkeletalMesh.h"
#include "Engine/Engine.h"
#include "GameFramework/Controller.h"
#include "UObject/ConstructorHelpers.h"
#include "GameFramework/PlayerController.h"

#ifndef HMD_MODULE_INCLUDED
#define HMD_MODULE_INCLUDED 0
#endif

const FName AFYPPawn::LookUpBinding("LookUp");
const FName AFYPPawn::LookRightBinding("LookRight");
const FName AFYPPawn::EngineAudioRPM("RPM");

#define LOCTEXT_NAMESPACE "VehiclePawn"

AFYPPawn::AFYPPawn()
{
	// Car mesh
	static ConstructorHelpers::FObjectFinder<USkeletalMesh> CarMesh(TEXT("/Game/VehicleAdv/Vehicle/Vehicle_SkelMesh.Vehicle_SkelMesh"));
	GetMesh()->SetSkeletalMesh(CarMesh.Object);

	static ConstructorHelpers::FClassFinder<UObject> AnimBPClass(TEXT("/Game/VehicleAdv/Vehicle/VehicleAnimationBlueprint"));
	GetMesh()->SetAnimationMode(EAnimationMode::AnimationBlueprint);
	GetMesh()->SetAnimInstanceClass(AnimBPClass.Class);

	// Setup friction materials
	static ConstructorHelpers::FObjectFinder<UPhysicalMaterial> SlipperyMat(TEXT("/Game/VehicleAdv/PhysicsMaterials/Slippery.Slippery"));
	SlipperyMaterial = SlipperyMat.Object;

	static ConstructorHelpers::FObjectFinder<UPhysicalMaterial> NonSlipperyMat(TEXT("/Game/VehicleAdv/PhysicsMaterials/NonSlippery.NonSlippery"));
	NonSlipperyMaterial = NonSlipperyMat.Object;

	UWheeledVehicleMovementComponent4W* Vehicle4W = CastChecked<UWheeledVehicleMovementComponent4W>(GetVehicleMovement());

	check(Vehicle4W->WheelSetups.Num() == 4);

	// Wheels/Tyres
	// Setup the wheels
	Vehicle4W->WheelSetups[0].WheelClass = UFYPWheelFront::StaticClass();
	Vehicle4W->WheelSetups[0].BoneName = FName("PhysWheel_FL");
	Vehicle4W->WheelSetups[0].AdditionalOffset = FVector(0.f, -8.f, 0.f);

	Vehicle4W->WheelSetups[1].WheelClass = UFYPWheelFront::StaticClass();
	Vehicle4W->WheelSetups[1].BoneName = FName("PhysWheel_FR");
	Vehicle4W->WheelSetups[1].AdditionalOffset = FVector(0.f, 8.f, 0.f);

	Vehicle4W->WheelSetups[2].WheelClass = UFYPWheelRear::StaticClass();
	Vehicle4W->WheelSetups[2].BoneName = FName("PhysWheel_BL");
	Vehicle4W->WheelSetups[2].AdditionalOffset = FVector(0.f, -8.f, 0.f);

	Vehicle4W->WheelSetups[3].WheelClass = UFYPWheelRear::StaticClass();
	Vehicle4W->WheelSetups[3].BoneName = FName("PhysWheel_BR");
	Vehicle4W->WheelSetups[3].AdditionalOffset = FVector(0.f, 8.f, 0.f);

	// Adjust the tire loading
	Vehicle4W->MinNormalizedTireLoad = 0.0f;
	Vehicle4W->MinNormalizedTireLoadFiltered = 0.2f;
	Vehicle4W->MaxNormalizedTireLoad = 2.0f;
	Vehicle4W->MaxNormalizedTireLoadFiltered = 2.0f;

	// Engine 
	// Torque setup
	Vehicle4W->MaxEngineRPM = 5700.0f;
	Vehicle4W->EngineSetup.TorqueCurve.GetRichCurve()->Reset();
	Vehicle4W->EngineSetup.TorqueCurve.GetRichCurve()->AddKey(0.0f, 400.0f);
	Vehicle4W->EngineSetup.TorqueCurve.GetRichCurve()->AddKey(1890.0f, 500.0f);
	Vehicle4W->EngineSetup.TorqueCurve.GetRichCurve()->AddKey(5730.0f, 400.0f);

	// Adjust the steering 
	Vehicle4W->SteeringCurve.GetRichCurve()->Reset();
	Vehicle4W->SteeringCurve.GetRichCurve()->AddKey(0.0f, 1.0f);
	Vehicle4W->SteeringCurve.GetRichCurve()->AddKey(40.0f, 0.7f);
	Vehicle4W->SteeringCurve.GetRichCurve()->AddKey(120.0f, 0.6f);

	// Transmission	
	// We want 4wd
	Vehicle4W->DifferentialSetup.DifferentialType = EVehicleDifferential4W::LimitedSlip_4W;

	// Drive the front wheels a little more than the rear
	Vehicle4W->DifferentialSetup.FrontRearSplit = 0.65;

	// Automatic gearbox
	Vehicle4W->TransmissionSetup.bUseGearAutoBox = true;
	Vehicle4W->TransmissionSetup.GearSwitchTime = 0.15f;
	Vehicle4W->TransmissionSetup.GearAutoBoxLatency = 1.0f;

	// Physics settings
	// Adjust the center of mass - the buggy is quite low
	UPrimitiveComponent* UpdatedPrimitive = Cast<UPrimitiveComponent>(Vehicle4W->UpdatedComponent);
	if (UpdatedPrimitive)
	{
		UpdatedPrimitive->BodyInstance.COMNudge = FVector(8.0f, 0.0f, 0.0f);
	}

	// Set the inertia scale. This controls how the mass of the vehicle is distributed.
	Vehicle4W->InertiaTensorScale = FVector(1.0f, 1.333f, 1.2f);

	// Create a spring arm component for our chase camera
	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	SpringArm->SetRelativeLocation(FVector(0.0f, 0.0f, 34.0f));
	SpringArm->SetWorldRotation(FRotator(-20.0f, 0.0f, 0.0f));
	SpringArm->SetupAttachment(RootComponent);
	SpringArm->TargetArmLength = 125.0f;
	SpringArm->bEnableCameraLag = false;
	SpringArm->bEnableCameraRotationLag = false;
	SpringArm->bInheritPitch = true;
	SpringArm->bInheritYaw = true;
	SpringArm->bInheritRoll = true;

	// Create the chase camera component 
	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("ChaseCamera"));
	Camera->SetupAttachment(SpringArm, USpringArmComponent::SocketName);
	Camera->SetRelativeLocation(FVector(-125.0, 0.0f, 0.0f));
	Camera->SetRelativeRotation(FRotator(10.0f, 0.0f, 0.0f));
	Camera->bUsePawnControlRotation = false;
	Camera->FieldOfView = 90.f;

	// In car HUD
	// Create text render component for in car speed display
	InCarSpeed = CreateDefaultSubobject<UTextRenderComponent>(TEXT("IncarSpeed"));
	InCarSpeed->SetRelativeScale3D(FVector(1.0f, 1.0f, 1.0f));
	InCarSpeed->SetRelativeLocation(FVector(35.0f, -6.0f, 20.0f));
	InCarSpeed->SetRelativeRotation(FRotator(0.0f, 180.0f, 0.0f));
	InCarSpeed->SetupAttachment(GetMesh());

	// Create text render component for in car gear display
	InCarGear = CreateDefaultSubobject<UTextRenderComponent>(TEXT("IncarGear"));
	InCarGear->SetRelativeScale3D(FVector(1.0f, 1.0f, 1.0f));
	InCarGear->SetRelativeLocation(FVector(35.0f, 5.0f, 20.0f));
	InCarGear->SetRelativeRotation(FRotator(0.0f, 180.0f, 0.0f));
	InCarGear->SetupAttachment(GetMesh());

	// Setup the audio component and allocate it a sound cue
	static ConstructorHelpers::FObjectFinder<USoundCue> SoundCue(TEXT("/Game/VehicleAdv/Sound/Engine_Loop_Cue.Engine_Loop_Cue"));
	EngineSoundComponent = CreateDefaultSubobject<UAudioComponent>(TEXT("EngineSound"));
	EngineSoundComponent->SetSound(SoundCue.Object);
	EngineSoundComponent->SetupAttachment(GetMesh());

	// Colors for the in-car gear display. One for normal one for reverse
	GearDisplayReverseColor = FColor(255, 0, 0, 255);
	GearDisplayColor = FColor(255, 255, 255, 255);

	bIsLowFriction = false;


	//- Custom Additions By David Taylor -//

	TimeLeft = CreateDefaultSubobject<UTextRenderComponent>(TEXT("TIME LEFT STAIONARY"));
	TimeLeft->SetRelativeScale3D(FVector(1.0f, 1.0f, 1.0f));
	TimeLeft->SetRelativeLocation(FVector(35.0f, 5.0f, 20.0f));
	TimeLeft->SetRelativeRotation(FRotator(0.0f, 180.0f, 0.0f));
	TimeLeft->SetupAttachment(GetMesh());

	DistanceTraveledScoreUI = CreateDefaultSubobject<UTextRenderComponent>(TEXT("Distance Traveled"));
	DistanceTraveledScoreUI->SetRelativeScale3D(FVector(1.0f, 1.0f, 1.0f));
	DistanceTraveledScoreUI->SetRelativeLocation(FVector(35.0f, 5.0f, 20.0f));
	DistanceTraveledScoreUI->SetRelativeRotation(FRotator(0.0f, 180.0f, 0.0f));
	DistanceTraveledScoreUI->SetupAttachment(GetMesh());

	LapMultiplyerUI = CreateDefaultSubobject<UTextRenderComponent>(TEXT("Lap Multiplyer"));
	LapMultiplyerUI->SetRelativeScale3D(FVector(1.0f, 1.0f, 1.0f));
	LapMultiplyerUI->SetRelativeLocation(FVector(35.0f, 5.0f, 20.0f));
	LapMultiplyerUI->SetRelativeRotation(FRotator(0.0f, 180.0f, 0.0f));
	LapMultiplyerUI->SetupAttachment(GetMesh());

	NorthRayDistanceUI = CreateDefaultSubobject<UTextRenderComponent>(TEXT("N"));
	NorthRayDistanceUI->SetRelativeScale3D(FVector(1.0f, 1.0f, 1.0f));
	NorthRayDistanceUI->SetRelativeLocation(FVector(35.0f, 5.0f, 20.0f));
	NorthRayDistanceUI->SetRelativeRotation(FRotator(0.0f, 180.0f, 0.0f));
	NorthRayDistanceUI->SetupAttachment(GetMesh());

	NorthEastRayDistanceUI = CreateDefaultSubobject<UTextRenderComponent>(TEXT("NE"));
	NorthEastRayDistanceUI->SetRelativeScale3D(FVector(1.0f, 1.0f, 1.0f));
	NorthEastRayDistanceUI->SetRelativeLocation(FVector(35.0f, 5.0f, 20.0f));
	NorthEastRayDistanceUI->SetRelativeRotation(FRotator(0.0f, 180.0f, 0.0f));
	NorthEastRayDistanceUI->SetupAttachment(GetMesh());

	EastRayDistanceUI = CreateDefaultSubobject<UTextRenderComponent>(TEXT("E"));
	EastRayDistanceUI->SetRelativeScale3D(FVector(1.0f, 1.0f, 1.0f));
	EastRayDistanceUI->SetRelativeLocation(FVector(35.0f, 5.0f, 20.0f));
	EastRayDistanceUI->SetRelativeRotation(FRotator(0.0f, 180.0f, 0.0f));
	EastRayDistanceUI->SetupAttachment(GetMesh());

	SouthEastRayDistanceUI = CreateDefaultSubobject<UTextRenderComponent>(TEXT("SE"));
	SouthEastRayDistanceUI->SetRelativeScale3D(FVector(1.0f, 1.0f, 1.0f));
	SouthEastRayDistanceUI->SetRelativeLocation(FVector(35.0f, 5.0f, 20.0f));
	SouthEastRayDistanceUI->SetRelativeRotation(FRotator(0.0f, 180.0f, 0.0f));
	SouthEastRayDistanceUI->SetupAttachment(GetMesh());

	SouthRayDistanceUI = CreateDefaultSubobject<UTextRenderComponent>(TEXT("S"));
	SouthRayDistanceUI->SetRelativeScale3D(FVector(1.0f, 1.0f, 1.0f));
	SouthRayDistanceUI->SetRelativeLocation(FVector(35.0f, 5.0f, 20.0f));
	SouthRayDistanceUI->SetRelativeRotation(FRotator(0.0f, 180.0f, 0.0f));
	SouthRayDistanceUI->SetupAttachment(GetMesh());

	SouthWestRayDistanceUI = CreateDefaultSubobject<UTextRenderComponent>(TEXT("SW"));
	SouthWestRayDistanceUI->SetRelativeScale3D(FVector(1.0f, 1.0f, 1.0f));
	SouthWestRayDistanceUI->SetRelativeLocation(FVector(35.0f, 5.0f, 20.0f));
	SouthWestRayDistanceUI->SetRelativeRotation(FRotator(0.0f, 180.0f, 0.0f));
	SouthWestRayDistanceUI->SetupAttachment(GetMesh());

	WestRayDistanceUI = CreateDefaultSubobject<UTextRenderComponent>(TEXT("W"));
	WestRayDistanceUI->SetRelativeScale3D(FVector(1.0f, 1.0f, 1.0f));
	WestRayDistanceUI->SetRelativeLocation(FVector(35.0f, 5.0f, 20.0f));
	WestRayDistanceUI->SetRelativeRotation(FRotator(0.0f, 180.0f, 0.0f));
	WestRayDistanceUI->SetupAttachment(GetMesh());

	NorthWestRayDistanceUI = CreateDefaultSubobject<UTextRenderComponent>(TEXT("NW"));
	NorthWestRayDistanceUI->SetRelativeScale3D(FVector(1.0f, 1.0f, 1.0f));
	NorthWestRayDistanceUI->SetRelativeLocation(FVector(35.0f, 5.0f, 20.0f));
	NorthWestRayDistanceUI->SetRelativeRotation(FRotator(0.0f, 180.0f, 0.0f));
	NorthWestRayDistanceUI->SetupAttachment(GetMesh());

	mf_DistanceTraveled = 0.036f;
}

void AFYPPawn::BeginPlay()
{
	Super::BeginPlay();

	// Start an engine sound playing
	EngineSoundComponent->Play();
}

void AFYPPawn::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	// set up gameplay key bindings
	check(PlayerInputComponent);

	PlayerInputComponent->BindAxis("MoveForward", this, &AFYPPawn::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &AFYPPawn::MoveRight);
	PlayerInputComponent->BindAxis(LookUpBinding);
	PlayerInputComponent->BindAxis(LookRightBinding);

	PlayerInputComponent->BindAction("Handbrake", IE_Pressed, this, &AFYPPawn::OnHandbrakePressed);
	PlayerInputComponent->BindAction("Handbrake", IE_Released, this, &AFYPPawn::OnHandbrakeReleased);
}

void AFYPPawn::MoveForward(float Val)
{
	GetVehicleMovementComponent()->SetThrottleInput(Val);

}

void AFYPPawn::MoveRight(float Val)
{
	GetVehicleMovementComponent()->SetSteeringInput(Val);
}

void AFYPPawn::OnHandbrakePressed()
{
	GetVehicleMovementComponent()->SetHandbrakeInput(true);
}

void AFYPPawn::OnHandbrakeReleased()
{
	GetVehicleMovementComponent()->SetHandbrakeInput(false);
}

void AFYPPawn::Tick(float Delta)
{
	Super::Tick(Delta);

	// Update Hud
	//- Calculations for Speed And Gear -//
		float KPH = FMath::Abs(GetVehicleMovement()->GetForwardSpeed()) * 0.036f;
		int32 KPH_int = FMath::FloorToInt(KPH);
		int32 Gear = GetVehicleMovement()->GetCurrentGear();

		//- Creating Strings and Setting Speed String -//
		FText GearDisplayString, SpeedDisplayString = FText::Format(LOCTEXT("SpeedFormat", "{0} km/h"), FText::AsNumber(KPH_int));

		if (KPH < 1)
			GearDisplayString = FText(LOCTEXT("ReverseGear", "N"));
		else
			GearDisplayString = (Gear == -1) ? LOCTEXT("R", "R") : FText::AsNumber(Gear);

	//- Calculations for Time Left -//
		
		if (KPH < 1)
		{
			mf_TimeLeft += Delta; 
			if (mf_TimeLeft > 5.0f)
			{
				AiFailed();
				mf_TimeLeft = 5.0f;
			}
		}
		else if (mf_TimeLeft > 0)
		{
			mf_TimeLeft = 0;
		}

	//- Calculations for Distance Traveled -//
	
		mf_DistanceTraveled += (GetVehicleMovement()->GetForwardSpeed() * 0.036f) * Delta;

	//- Calculations for LapMultiplayer -//
	


	//- Calculations for NorthRayDistance -//
	
	//- Calculations for NorthEastRayDistance -//
	
	//- Calculations for East Ray Distance -//
	
	//- Calculations for South East Ray Distance -//
	
	//- Calculations for South Ray Distance -//
	
	//- Calculations for South West Ray Distance -//
	
	//- Calculations for West Ray Distance -//

	//- Calculations for North West Distance -//


	//- Setting Each UI Elements To Needed Text -//
	InCarSpeed->SetText(SpeedDisplayString);
	InCarGear->SetText(GearDisplayString);

	TimeLeft->SetText(FText::AsNumber(mf_TimeLeft));
	DistanceTraveledScoreUI->SetText(FText::AsNumber(mf_DistanceTraveled));
	//LapMultiplyerUI->SetText();
	//NorthRayDistanceUI->SetText();
	//NorthEastRayDistanceUI->SetText();
	//EastRayDistanceUI->SetText();
	//SouthEastRayDistanceUI->SetText();
	//SouthRayDistanceUI->SetText();
	//SouthWestRayDistanceUI->SetText();
	//WestRayDistanceUI->SetText();
	//NorthWestRayDistanceUI->SetText();



	// Pass the engine RPM to the sound component
	float RPMToAudioScale = 2500.0f / GetVehicleMovement()->GetEngineMaxRotationSpeed();
	EngineSoundComponent->SetFloatParameter(EngineAudioRPM, GetVehicleMovement()->GetEngineRotationSpeed()*RPMToAudioScale);
}

void AFYPPawn::AiFailed()
{

}

#undef LOCTEXT_NAMESPACE