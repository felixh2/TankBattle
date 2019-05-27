// Fill out your copyright notice in the Description page of Project Settings.

#include "Tank.h"

//#include "TankBarrel.h"
#include "AimingComponent.h"

//#include "Projectile.h"




// C++ Constructor -> Construction Script -> Begin Play(C++) - Begin play(BP) 

// Sets default values
ATank::ATank()
{
	
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;



	// Fucking important !
	/*
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootSceneComponent"));					// without adding this, the tank explosion would be the root !!

	TankExplosion = CreateDefaultSubobject<UParticleSystemComponent>(FName("Tank Explosion"));
	TankExplosion->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
	*/


	// Creating Aiming Component in BluePrints
	//AimingComponent = CreateDefaultSubobject<UAimingComponent>(FName("Aiming Component"));
	//MovementComponent = CreateDefaultSubobject<UTankMovementComponent>(FName("Movement Component"));

	
}


float ATank::GetTankHealth()
{
	return Health;
}

void ATank::SetTankHealth(float NewHealth)
{
	Health = NewHealth;
}

float ATank::TakeDamage(float DamageAmount, FDamageEvent const & DamageEvent, AController * EventInstigator, AActor * DamageCauser)
{

	Health -= DamageAmount;
	UE_LOG(LogTemp, Warning, TEXT("Health is: %f"), Health);
	if (Health < 1.f) {
		(FindComponentByClass<UParticleSystemComponent>())->Activate();
		(FindComponentByClass<UAimingComponent>())->SetAmmo(0);
		OnTankDeath.Broadcast();
		UE_LOG(LogTemp, Warning, TEXT("Tank died"));
	}
	return Health;
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


