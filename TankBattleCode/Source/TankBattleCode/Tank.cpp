// Fill out your copyright notice in the Description page of Project Settings.

#include "Tank.h"
#include "TankBarrel.h"
//#include "AimingComponent.h"
#include "Projectile.h"




// C++ Constructor -> Construction Script -> Begin Play(C++) - Begin play(BP) 

// Sets default values
ATank::ATank()
{
	UE_LOG(LogTemp, Warning, TEXT("Donkey4"));
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	// Creating Aiming Component in BluePrints
	

	//AimingComponent = CreateDefaultSubobject<UAimingComponent>(FName("Aiming Component"));
	//MovementComponent = CreateDefaultSubobject<UTankMovementComponent>(FName("Movement Component"));

	
}


// Called when the game starts or when spawned
void ATank::BeginPlay()
{
	Super::BeginPlay();
//	AimingComponent = FindComponentByClass<UAimingComponent>();
}

//// After Refactoring
/*
void ATank::Initialize(UTankTurrent * TurretReference, UTankBarrel * BarrelRef)
{
	AimingComponent->Initialize(BarrelRef, TurretReference);
	Barrel = BarrelRef;
	Turrent = TurretReference;
}


void ATank::SetBarrelReference(UTankBarrel* BarrelRef)
{
	AimingComponent->SetBarrelReference(BarrelRef);
	
}

void ATank::SetTurrentReference(UTankTurrent * TurretReference)
{
	AimingComponent->SetTurrentReference(TurretReference);
	
}
*/


/*
void ATank::AimAt(FString WhoIsAiming, FVector &HitLocation)
{
	if (!ensure(AimingComponent)) { return; }
	
	AimingComponent->AimAt(WhoIsAiming, HitLocation, LaunchSpeed);

}
*/

void ATank::Fire()
{

	bool ReadyToFire = (FPlatformTime::Seconds() - LastFireTime) > ReloadTime;
	if (ensure(!Barrel)) { return; }
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
