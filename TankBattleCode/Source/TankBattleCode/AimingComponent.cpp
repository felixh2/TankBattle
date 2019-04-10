// Fill out your copyright notice in the Description page of Project Settings.

#include "AimingComponent.h"
#include "TankBarrel.h"
#include "TankTurrent.h"
#include "Projectile.h"

#pragma optimize("", off)

UAimingComponent::UAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;


}

void UAimingComponent::Initialize(UTankBarrel * BarrelRef, UTankTurrent * TurrentRef)
{
	SetBarrelReference(BarrelRef);
	SetTurrentReference(TurrentRef);
}

void UAimingComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction * ThisTickFunction)
{
	
	float Time1 = GetWorld()->GetTimeSeconds();
	float Time2 = FPlatformTime::Seconds();

	IsReloading = (Time1- LastFireTime) < ReloadTime;

	//UE_LOG(LogTemp, Warning, TEXT("Time1 : %f, Time2 : %f"), Time1, Time2);

	if (IsReloading) {
		EFiringState = EFiringState::Reloading;
		//UE_LOG(LogTemp, Warning, TEXT("Reloading"));
	}
	else{ 
		if (IsBarrelMoving()) {
			EFiringState = EFiringState::Aiming;
		//	UE_LOG(LogTemp, Warning, TEXT("Barrel Moving"));
		}
		else {
			EFiringState = EFiringState::Locked;
		//	UE_LOG(LogTemp, Warning, TEXT("Barrel Stopped"));
		}
	}
}

bool UAimingComponent::IsBarrelMoving() {


	//UE_LOG(LogTemp, Warning, TEXT("%s , %s "), *Barrel->GetForwardVector().ToString(), *AimDirection.ToString());
	return !(Barrel->GetForwardVector().Equals(AimDirection, 0.1f));

}

void UAimingComponent::SetBarrelReference(UTankBarrel* BarrelRef)
{
	Barrel = BarrelRef;
}

void UAimingComponent::SetTurrentReference(UTankTurrent * TurrentRef)
{
	Turrent = TurrentRef;
}

// Called when the game starts
void UAimingComponent::BeginPlay()
{
	Super::BeginPlay();
	
}


void UAimingComponent::AimAt(FString WhoIsAiming, FVector &HitLocation)
{
	//UE_LOG(LogTemp, Warning, TEXT("%s is Aiming to Location : %s"), *WhoIsAiming, *HitLocation.ToString());
	if (!Barrel) { return; }
	if (Barrel) {

		FVector BarrelPosition = Barrel->GetComponentTransform().GetLocation();
		FVector BarrelSocketPosition = Barrel->GetSocketLocation(FName("Projectile"));
		/*
		DrawDebugLine(
			GetWorld(),
			BarrelSocketPosition,
			HitLocation,
			FColor(0, 0, 255),
			false,
			0.f,
			0.f,
			12.f
		);
		*/
		FVector LaunchVelocity(0);
		//FVector TossVelocity = BarrelPosition * LaunchSpeed;
		FCollisionResponseParams  ResponseParam;
		TArray<AActor*> ActorsToIgnore;

		if (UGameplayStatics::SuggestProjectileVelocity
		(
			this,
			LaunchVelocity,
			BarrelSocketPosition,
			HitLocation,
			LaunchSpeed,
			false,
			0,
			0,
			ESuggestProjVelocityTraceOption::DoNotTrace,
			ResponseParam,
			ActorsToIgnore,
			false)
			)
		{
			AimDirection = LaunchVelocity.GetSafeNormal();
			//UE_LOG(LogTemp, Warning, TEXT("%s Aiming Direction is : %s"), *WhoIsAiming, *AimDirection.ToString());


		/*	float theta = AimDirection.DotProduct(AimDirection, BarrelSocketPosition.GetSafeNormal());
			FRotator BarrelRotator;
			BarrelRotator.Pitch = theta;*/

			auto BarrelRotator = Barrel->GetForwardVector().Rotation();
			auto AimAsRotator = AimDirection.Rotation();
			auto DeltaRotator = AimAsRotator - BarrelRotator;

			Barrel->Elevate(DeltaRotator.Pitch);
			Turrent->RotateTurrent(DeltaRotator.Yaw);

			
		//(DeltaRotator.Pitch > 0.1) | (DeltaRotator.Pitch < -0.1) ) |
		/*	if( (DeltaRotator.Yaw > 0.1) | (DeltaRotator.Yaw < -0.1) )
				EFiringState = EFiringState::Aiming;
			else if (EFiringState != EFiringState::Reloading)
				EFiringState = EFiringState::Locked;*/

		}
		else {
			//UE_LOG(LogTemp, Warning, TEXT("Could not find solution to fire"));
		}



	}
}

void UAimingComponent::Fire()
{
	
	if (!ensure(Barrel)) { return; }
	if (!ensure(ProjectileBlueprint)) { return; }
	if (EFiringState != EFiringState::Reloading) {
		auto Projectile = GetWorld()->SpawnActor<AProjectile>(
			ProjectileBlueprint,
			Barrel->GetSocketLocation(FName("Projectile")),
			Barrel->GetSocketRotation(FName("Projectile"))
			);
	
		Projectile->LaunchProjectile(LaunchSpeed);
		LastFireTime = GetWorld()->GetTimeSeconds();
	}

	
}

#pragma optimize("", on)