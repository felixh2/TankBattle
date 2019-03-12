// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "Runtime/Engine/Classes/Engine/World.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
	ATank* TankAI = GetControlledTank();

	if (TankAI) {
		UE_LOG(LogTemp, Warning, TEXT("AI Tank possessed tank %s"), *(TankAI->GetName()) );
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("AI Tank NOT possessed"));
	}


	PlayerTank = GetPlayerTank();
	if (PlayerTank) {
		
		FVector TankPosition = PlayerTank->GetTransform().GetLocation();
		UE_LOG(LogTemp, Warning, TEXT("AI Tank got player controller tank at position: %s"), *TankPosition.ToString());
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("AI Tank didn't get player controller tank"));
	}
	FVector TankPosition = PlayerTank->GetTransform().GetLocation();
}

ATank * ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

ATank * ATankAIController::GetPlayerTank() const
{
	ATank* Player_Tank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());

	return Player_Tank;
}


