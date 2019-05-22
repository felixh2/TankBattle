// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "TankPlayerController.h"
#include "Runtime/Engine/Classes/Engine/World.h"
#include "DrawDebugHelpers.h"

#include "CoreMinimal.h"
#include "AIController.h"
#include "TankAIController.generated.h"

class UAimingComponent;
/**
 * 
 */
UCLASS()
class TANKBATTLECODE_API ATankAIController : public AAIController
{
	GENERATED_BODY()

	virtual	void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;
		
//	ATank* GetControlledTank() const;

//	ATank* GetPlayerTank() const;

	virtual void SetPawn(APawn *InPawn) override; // Method that being called when pawn is being possesed

	FVector AimTowardsPlayerTank();



private:
	
	UFUNCTION()
	void OnTankDeath();


	UPROPERTY(EditAnywhere, Category = Firing)
	float AcceptenceRadius = 3000;

	APawn* PlayerTank = nullptr;

	UAimingComponent * AimingComponent = nullptr;
};
