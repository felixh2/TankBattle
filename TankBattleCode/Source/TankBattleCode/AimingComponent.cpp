// Fill out your copyright notice in the Description page of Project Settings.

#include "AimingComponent.h"


// Sets default values for this component's properties
UAimingComponent::UAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

void UAimingComponent::SetBarrelReference(UStaticMeshComponent* BarrelRef)
{
	Barrel = BarrelRef;
	
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

void UAimingComponent::AimAt(FString WhoIsAiming, FVector &HitLocation)
{
	UE_LOG(LogTemp, Warning, TEXT("%s is Aiming to Location : %s"), *WhoIsAiming, *HitLocation.ToString());
	if (Barrel) {

		FVector BarrelPosition = Barrel->GetComponentTransform().GetLocation();
		DrawDebugLine(
			GetWorld(),
			BarrelPosition,
			HitLocation,
			FColor(0, 0, 255),
			false,
			0.f,
			0.f,
			12.f
		);
	}
}

