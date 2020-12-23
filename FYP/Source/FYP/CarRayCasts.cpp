// Fill out your copyright notice in the Description page of Project Settings.


#include "CarRayCasts.h"

// Sets default values
ACarRayCasts::ACarRayCasts()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	StartLocation = CreateDefaultSubobject<USphereComponent>(TEXT("RootComponent"));
}

// Called when the game starts or when spawned
void ACarRayCasts::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACarRayCasts::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FHitResult OutHit;
	FVector Start = StartLocation->GetComponentLocation();
	FVector ForwardVector = StartLocation->GetForwardVector();
	FVector End = Start + (ForwardVector * 1000);

	FCollisionQueryParams CollisionParams;
	DrawDebugLine(GetWorld(), Start, End, FColor::Green, false, 1, 0, 1);
	bool isHit = GetWorld()->LineTraceSingleByChannel(OutHit, Start , End, ECC_Visibility, CollisionParams);

	if (isHit)
	{
		if (OutHit.bBlockingHit)
		{
			if (GEngine)
			{
				GEngine->AddOnScreenDebugMessage(-1, 1.f, FColor::Red, FString::Printf(TEXT("YOU ARE HITTING: $s")), *OutHit.GetActor()->GetName());
			}
		}
	}

}

void ACarRayCasts::Attach(USceneComponent* attachPoint)
{
	StartLocation->SetupAttachment(attachPoint);
}
