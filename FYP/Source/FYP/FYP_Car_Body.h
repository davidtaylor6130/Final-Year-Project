// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "WheeledVehicle.h"
#include <string>
#include "Components/BoxComponent.h"
#include "Components/SphereComponent.h"
#include "DrawDebugHelpers.h"
#include "Math/Float32.h"
#include "FYP_Car_Body.generated.h"

class UPhysicalMaterial;
class UCameraComponent;
class USpringArmComponent;
class UTextRenderComponent;
class UInputComponent;
class UAudioComponent;
class UBoxComponent;
class FFloat32;

struct RayCastInfo
{
	USphereComponent* StartPoint;

	FCollisionQueryParams CollisionParams;
	FHitResult OutHit;
	FVector Start;
	FVector ForwardVector;
	FVector End;
};

UCLASS(config=Game)
class AFYPPawn : public AWheeledVehicle
{
	GENERATED_BODY()

	/** Spring arm that will offset the camera */
	UPROPERTY(Category = Camera, VisibleDefaultsOnly, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	USpringArmComponent* SpringArm;

	/** Camera component that will be our viewpoint */
	UPROPERTY(Category = Camera, VisibleDefaultsOnly, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	UCameraComponent* Camera;

	/** Text component for the In-Car speed */
	UPROPERTY(Category = Display, VisibleDefaultsOnly, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	UTextRenderComponent* InCarSpeed;

	/** Text component for the In-Car gear */
	UPROPERTY(Category = Display, VisibleDefaultsOnly, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	UTextRenderComponent* InCarGear;

	/** Audio component for the engine sound */
	UPROPERTY(Category = Display, VisibleDefaultsOnly, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	UAudioComponent* EngineSoundComponent;

public:
	AFYPPawn();

	UPROPERTY(Category = Display, VisibleDefaultsOnly, BlueprintReadOnly)
	/** The color of the incar gear text in forward gears */
	FColor	GearDisplayColor;

	/** The color of the incar gear text when in reverse */
	UPROPERTY(Category = Display, VisibleDefaultsOnly, BlueprintReadOnly)
	FColor	GearDisplayReverseColor;

	// Begin Pawn interface
	virtual void SetupPlayerInputComponent(UInputComponent* InputComponent) override;
	// End Pawn interface

	// Begin Actor interface
	virtual void Tick(float Delta) override;

protected:
	virtual void BeginPlay() override;

public:
	/** Handle pressing forwards */
	void MoveForward(float Val);
	/** Handle pressing right */
	void MoveRight(float Val);
	/** Handle handbrake pressed */
	void OnHandbrakePressed();
	/** Handle handbrake released */
	void OnHandbrakeReleased();

	static const FName LookUpBinding;
	static const FName LookRightBinding;
	static const FName EngineAudioRPM;

public:
	/** Returns SpringArm subobject **/
	FORCEINLINE USpringArmComponent* GetSpringArm() const { return SpringArm; }
	/** Returns Camera subobject **/
	FORCEINLINE UCameraComponent* GetCamera() const { return Camera; }
	/** Returns InternalCamera subobject **/
	FORCEINLINE UTextRenderComponent* GetInCarSpeed() const { return InCarSpeed; }
	/** Returns InCarGear subobject **/
	FORCEINLINE UTextRenderComponent* GetInCarGear() const { return InCarGear; }
	/** Returns EngineSoundComponent subobject **/
	FORCEINLINE UAudioComponent* GetEngineSoundComponent() const { return EngineSoundComponent; }


public:
	//- Code Below By David Taylor -//

	//- Needed Elements To Track if AI Isnt Moving -//
	float mf_TimeLeft;

	//- Needed Elements To Track Distance Moved -//
	float mf_DistanceTraveled;

	//- Required Elements For Tracking Compleated Laps -//
	UPROPERTY(Category = Display, VisibleDefaultsOnly, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	UBoxComponent* mp_collider;
	UFUNCTION()
	void LapMarkerCollider(UPrimitiveComponent * _overlappedComponent, AActor* _otherActor, UPrimitiveComponent* _otherComp, int32 _otherBodyIndex, bool _bFromSweep, const FHitResult & _hitResult);
	uint32 mi_LapMultiplyer;
	uint32 mi_HistoryCount;
	FString LapMarkerNames[4];
	FString LapMarkerHistory[4];

	//- Required Data For Car RayCasts -//
	UPROPERTY(Category = Display, VisibleDefaultsOnly, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	USphereComponent* North;
	UPROPERTY(Category = Display, VisibleDefaultsOnly, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	USphereComponent* NorthEast;
	UPROPERTY(Category = Display, VisibleDefaultsOnly, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	USphereComponent* East;
	UPROPERTY(Category = Display, VisibleDefaultsOnly, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	USphereComponent* SouthEast;
	UPROPERTY(Category = Display, VisibleDefaultsOnly, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	USphereComponent* South;
	UPROPERTY(Category = Display, VisibleDefaultsOnly, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	USphereComponent* SouthWest;
	UPROPERTY(Category = Display, VisibleDefaultsOnly, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	USphereComponent* West;
	UPROPERTY(Category = Display, VisibleDefaultsOnly, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	USphereComponent* NorthWest;
	RayCastInfo Casts[8];
	UFUNCTION(BlueprintCallable, Category = "BY DAVID TAYLOR|FUNCTIONS|CarUpdateFunctions")
	void UpdateRayCasts();

	UFUNCTION(BlueprintCallable, Category = "BY DAVID TAYLOR|FUNCTIONS|CarUpdateFunctions ")
	void UpdateCarSpeed(float Delta);

	//- Decliration Of UI Score/Time Elements -//	
	UPROPERTY(Category = Display, VisibleDefaultsOnly, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	UTextRenderComponent* TimeLeft;
	UPROPERTY(Category = Display, VisibleDefaultsOnly, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	UTextRenderComponent* DistanceTraveledScoreUI;
	UPROPERTY(Category = Display, VisibleDefaultsOnly, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	UTextRenderComponent* LapMultiplyerUI;
	UPROPERTY(Category = Display, VisibleDefaultsOnly, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	UTextRenderComponent* ScoreUI;


	//- Decliration Of Feeler Distances -//
	UPROPERTY(Category = Display, VisibleDefaultsOnly, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	UTextRenderComponent* NorthRayDistanceUI;
	UPROPERTY(Category = Display, VisibleDefaultsOnly, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	UTextRenderComponent* NorthEastRayDistanceUI;
	UPROPERTY(Category = Display, VisibleDefaultsOnly, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	UTextRenderComponent* EastRayDistanceUI;
	UPROPERTY(Category = Display, VisibleDefaultsOnly, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	UTextRenderComponent* SouthEastRayDistanceUI;
	UPROPERTY(Category = Display, VisibleDefaultsOnly, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	UTextRenderComponent* SouthRayDistanceUI;
	UPROPERTY(Category = Display, VisibleDefaultsOnly, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	UTextRenderComponent* SouthWestRayDistanceUI;
	UPROPERTY(Category = Display, VisibleDefaultsOnly, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	UTextRenderComponent* WestRayDistanceUI;
	UPROPERTY(Category = Display, VisibleDefaultsOnly, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	UTextRenderComponent* NorthWestRayDistanceUI;
	UFUNCTION(BlueprintCallable, Category = "BY DAVID TAYLOR|FUNCTIONS|CarUpdateFunctions")
	void UpdateUIElements();

	FText m_GearDisplayString;
	FText m_SpeedDisplayString;

	UFUNCTION(BlueprintCallable, Category = "BY DAVID TAYLOR|FUNCTIONS|InputDataPrep")
	void InputDataAgmentation();

	float mf_NInput , mf_NEInput, mf_EInput, mf_SEInput, mf_SInput, mf_SWInput, mf_WInput, mf_NWInput;

	UFUNCTION(BlueprintCallable, Category = "BY DAVID TAYLOR|FUNCTIONS|InputDataRetreval")
		float GetNorthInput() { return mf_NInput; }
	UFUNCTION(BlueprintCallable, Category = "BY DAVID TAYLOR|FUNCTIONS|InputDataRetreval")
		float GetNorthEastInput() { return mf_NEInput; }
	UFUNCTION(BlueprintCallable, Category = "BY DAVID TAYLOR|FUNCTIONS|InputDataRetreval")
		float GetEastInput() { return mf_EInput; }
	UFUNCTION(BlueprintCallable, Category = "BY DAVID TAYLOR|FUNCTIONS|InputDataRetreval")
		float GetSouthEastInput() { return mf_SEInput; }
	UFUNCTION(BlueprintCallable, Category = "BY DAVID TAYLOR|FUNCTIONS|InputDataRetreval")
		float GetSouthInput() { return mf_SInput; }
	UFUNCTION(BlueprintCallable, Category = "BY DAVID TAYLOR|FUNCTIONS|InputDataRetreval")
		float GetSouthWestInput() { return mf_SWInput; }
	UFUNCTION(BlueprintCallable, Category = "BY DAVID TAYLOR|FUNCTIONS|InputDataRetreval")
		float GetWestInput() { return mf_WInput; }
	UFUNCTION(BlueprintCallable, Category = "BY DAVID TAYLOR|FUNCTIONS|InputDataRetreval")
		float GetNorthWestInput() { return mf_NWInput; }

	//- Get for score and alive -//
	UFUNCTION(BlueprintCallable, Category = "BY DAVID TAYLOR|FUNCTIONS|InputDataRetreval")
		float GetScore() { return  }
	UFUNCTION(BlueprintCallable, Category = "BY DAVID TAYLOR|FUNCTIONS|InputDataRetreval")
		bool IsAiAlive() { return mf_NWInput; }

	float mf_Steering = 0.0f, mf_Acceleration = 0.0f; 

	//- User Controll of car -//
	UFUNCTION(BlueprintCallable, Category = "BY DAVID TAYLOR|FUNCTIONS|InputDataRetreval")
		float GetUserCarAcceleration() { return mf_Acceleration;  };
	UFUNCTION(BlueprintCallable, Category = "BY DAVID TAYLOR|FUNCTIONS|InputDataRetreval")
		float GetUserCarSteering() { return mf_Steering; };
	UFUNCTION(BlueprintCallable, Category = "BY DAVID TAYLOR|FUNCTIONS|InputDataRetreval")
		bool InputsPressed() { return (mf_Steering != 0 || mf_Acceleration != 0); };



	//- Get Input Feedback -//
	UFUNCTION(BlueprintCallable, Category = "BY DAVID TAYLOR|FUNCTIONS|CarInputDataUsages")
		void AICarControl(float LR, float FB);


	//- Death Functions -//
	void AiFailed();


	//- Steering Var -//
	float Accel = 0.0f;
	float Steer = 0.0f;

};