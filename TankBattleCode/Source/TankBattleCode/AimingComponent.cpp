// Fill out your copyright notice in the Description page of Project Settings.

#include "AimingComponent.h"
#include "TankBarrel.h"
#include "TankTurrent.h"


// Sets default values for this component's properties
UAimingComponent::UAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
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

	// ...
	
}




// Called every frame
void UAimingComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UAimingComponent::AimAt(FString WhoIsAiming, FVector &HitLocation, float LaunchSpeed)
{
	//UE_LOG(LogTemp, Warning, TEXT("%s is Aiming to Location : %s"), *WhoIsAiming, *HitLocation.ToString());
	if (Barrel) {

		FVector BarrelPosition = Barrel->GetComponentTransform().GetLocation();
		FVector BarrelSocketPosition = Barrel->GetSocketLocation(FName("Projectile"));
		
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
				true)
			)
		{
			FVector AimDirection = LaunchVelocity.GetSafeNormal();
			//UE_LOG(LogTemp, Warning, TEXT("%s Aiming Direction is : %s"), *WhoIsAiming, *AimDirection.ToString());

			
		/*	float theta = AimDirection.DotProduct(AimDirection, BarrelSocketPosition.GetSafeNormal());
			FRotator BarrelRotator;
			BarrelRotator.Pitch = theta;*/
		
			auto BarrelRotator = Barrel->GetForwardVector().Rotation();
			auto AimAsRotator = AimDirection.Rotation();
			auto DeltaRotator = AimAsRotator - BarrelRotator;
			

			Barrel->Elevate(DeltaRotator.Pitch);
			Turrent->RotateTurrent(DeltaRotator.Yaw);
		}
		else {
			UE_LOG(LogTemp, Warning, TEXT("Could not find solution"));
		}

		

	}

	


}

