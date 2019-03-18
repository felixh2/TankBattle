// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Tank.generated.h"

class UTankTurrent;
class UTankBarrel;
class UAimingComponent;

UCLASS()
class TANKBATTLECODE_API ATank : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ATank();
	// Called every frame


	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void AimAt(FString WhoIsAiming, FVector &HitLocation);

	UFUNCTION(BlueprintCallable, Category = Setup)
	void SetBarrelReference(UTankBarrel* BarrelRef);

	UFUNCTION(BlueprintCallable, Category = Setup)
	void SetTurrentReference(UTankTurrent* TurretReference);

	UPROPERTY(EditAnywhere, Category = Firing)
	float LaunchSpeed = 10000.f;

protected:

	virtual void BeginPlay() override;

	UAimingComponent* AimingComponent = nullptr;

private:

	UTankBarrel* Barrel = nullptr;
	UTankTurrent* Turrent = nullptr;

	
	
};
