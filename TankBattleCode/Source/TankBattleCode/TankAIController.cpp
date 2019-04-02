// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "Runtime/Engine/Classes/Engine/World.h"

#pragma optimize("", off)
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


	//PlayerTank = GetPlayerTank();
	if (PlayerTank) {
		
		FVector TankPosition = PlayerTank->GetTransform().GetLocation();
		UE_LOG(LogTemp, Warning, TEXT("AI Tank got player controller tank at position: %s"), *TankPosition.ToString());
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("AI Tank didn't get player controller tank"));
	}
	//FVector TankPosition = PlayerTank->GetTransform().GetLocation();
}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	FVector playerTankLocation = AimTowardsPlayerTank();
	GetControlledTank()->AimAt(GetControlledTank()->GetName(), playerTankLocation);
	GetControlledTank()->Fire();

	MoveToActor(GetPlayerTank(), AcceptenceRadius);

}

FVector ATankAIController::AimTowardsPlayerTank()
{

	ATank* PlayerTank = GetPlayerTank();
	FVector playerTankLocation = PlayerTank->GetActorLocation();
	FVector Start = GetPawn()->GetTransform().GetLocation();


	/*DrawDebugLine(
		GetWorld(),
		Start,
		playerTankLocation,
		FColor(0, 0, 255),
		false,
		0.f,
		0.f,
		10.f
	);*/

	return playerTankLocation;
}

ATank * ATankAIController::GetPlayerTank() const
{
	ATank* Player_Tank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());

	return Player_Tank;
}

ATank * ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}


#pragma optimize("", on)




