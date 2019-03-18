// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "AimingComponent.h"

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Tank.generated.h"

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


	UPROPERTY(EditAnywhere, Category = Firing)
	float LaunchSpeed = 100000.f;

protected:

	virtual void BeginPlay() override;

	UAimingComponent* AimingComponent = nullptr;

private:

	UTankBarrel* Barrel = nullptr;


	
	
};
