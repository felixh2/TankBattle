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

	FVector AimTowardsPlayerTank();



private:
	APawn* PlayerTank = nullptr;
	float AcceptenceRadius = 3000;

	UAimingComponent * AimingComponent = nullptr;
};
