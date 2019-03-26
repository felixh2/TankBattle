// Fill out your copyright notice in the Description page of Project Settings.

#include "Tank.h"
#include "TankBarrel.h"
#include "AimingComponent.h"
#include "Projectile.h"
#include "TankMovementComponent.h"

// Sets default values
ATank::ATank()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	// Creating Aiming Component in BluePrints
	

	AimingComponent = CreateDefaultSubobject<UAimingComponent>(FName("Aiming Component"));
	//MovementComponent = CreateDefaultSubobject<UTankMovementComponent>(FName("Movement Component"));
}


// Called when the game starts or when spawned
void ATank::BeginPlay()
{
	Super::BeginPlay();
	
}

void ATank::SetBarrelReference(UTankBarrel* BarrelRef)
{
	AimingComponent->SetBarrelReference(BarrelRef);
	Barrel = BarrelRef;
}

void ATank::SetTurrentReference(UTankTurrent * TurretReference)
{
	AimingComponent->SetTurrentReference(TurretReference);
	Turrent = TurretReference;
}



// Called to bind functionality to input
void ATank::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ATank::AimAt(FString WhoIsAiming, FVector &HitLocation)
{
	
	AimingComponent->AimAt(WhoIsAiming, HitLocation, LaunchSpeed);

}


void ATank::Fire()
{
	bool ReadyToFire = (FPlatformTime::Seconds() - LastFireTime) > ReloadTime;
	if (ReadyToFire) {
		auto Projectile = GetWorld()->SpawnActor<AProjectile>(
			ProjectileBlueprint,
			Barrel->GetSocketLocation(FName("Projectile")),
			Barrel->GetSocketRotation(FName("Projectile"))
			);

		Projectile->LaunchProjectile(LaunchSpeed);
		LastFireTime = FPlatformTime::Seconds();
	}
	
}
