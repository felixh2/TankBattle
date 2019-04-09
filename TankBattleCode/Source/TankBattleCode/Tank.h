// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Tank.generated.h"



//class UTankTurrent;
//class UTankBarrel;



UCLASS()
class TANKBATTLECODE_API ATank : public APawn
{
	GENERATED_BODY()

public:

	ATank();

	//void AimAt(FString WhoIsAiming, FVector &HitLocation);
/*
	UFUNCTION(BlueprintCallable, Category = Setup)
	void SetBarrelReference(UTankBarrel* BarrelRef);

	UFUNCTION(BlueprintCallable, Category = Setup)
	void SetTurrentReference(UTankTurrent* TurretReference);

	UPROPERTY(EditAnywhere, Category = Firing)
	float LaunchSpeed = 10000.f;
*/






protected:
	
	
	virtual void BeginPlay() override;
	
//	UFUNCTION(BlueprintCallable, Category = "Setup")
//	void Initialize(UTankTurrent* TurretReference, UTankBarrel* BarrelRef);

//	UPROPERTY(BlueprintReadOnly)
//	UAimingComponent* AimingComponent = nullptr;

//	UPROPERTY(BlueprintReadOnly)                                     // Enables to expose this variable in Blueprint 
//	UTankMovementComponent* MovementComponent = nullptr;


private:

	//UTankBarrel* Barrel = nullptr;
	//UTankTurrent* Turrent = nullptr;

	
};
