// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
	ATank* TankAI = GetControlledTank();

	if (TankAI) {
		UE_LOG(LogTemp, Warning, TEXT("AI Tank %s possessed"), *(TankAI->GetName()) );
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("AI Tank NOT possessed"));
	}
}

ATank * ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}


