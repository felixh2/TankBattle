// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "Runtime/Engine/Classes/Engine/World.h"
#include "DrawDebugHelpers.h"
#include "Runtime/Engine/Classes/Components/StaticMeshComponent.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"


#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AimingComponent.generated.h"

class UTankBarrel;
class UTankTurrent;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class TANKBATTLECODE_API UAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UAimingComponent();
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	void AimAt(FString WhoIsAiming, FVector &HitLocation, float LaunchSpeed);
	void SetBarrelReference(UTankBarrel* BarrelRef);
	void SetTurrentReference(UTankTurrent* TurrentRef);

protected:
	// Called when the game starts
	virtual void BeginPlay() override;
	
private:	
	
	UTankBarrel * Barrel = nullptr;
	UTankTurrent* Turrent = nullptr;

		
	
};