// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "Tank.h"
#include "Delegate.h"
#include "Runtime/Engine/Classes/Engine/World.h"
#include "AimingComponent.h"


#pragma optimize("", off)

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
	
	/*ATank* TankAI = GetControlledTank();

	if (TankAI) {
		UE_LOG(LogTemp, Warning, TEXT("AI Tank possessed tank %s"), *(TankAI->GetName()) );
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("AI Tank NOT possessed"));
	}
	*/

	PlayerTank = GetPawn();
	if (!ensure(PlayerTank)) {return;}		
	FVector TankPosition = PlayerTank->GetTransform().GetLocation();
	UE_LOG(LogTemp, Warning, TEXT("AI Tank got player controller tank at position: %s"), *TankPosition.ToString());
	
	
	//FVector TankPosition = PlayerTank->GetTransform().GetLocation();

	AimingComponent = GetPawn()->FindComponentByClass<UAimingComponent>();
	if (!ensure(AimingComponent)) { return; }
}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	FVector playerTankLocation = AimTowardsPlayerTank();
	AimingComponent->AimAt(GetPawn()->GetName(), playerTankLocation);
	
	if(AimingComponent->GetFiringState() == EFiringState::Locked)
		AimingComponent->Fire();

	MoveToActor(GetWorld()->GetFirstPlayerController()->GetPawn(), AcceptenceRadius);

}

void ATankAIController::SetPawn(APawn * InPawn)
{
	Super::SetPawn(InPawn);
	if (InPawn) {
		ATank *PossesedTank = Cast<ATank>(InPawn);
		if (!ensure(PossesedTank)) { return; }
		PossesedTank->OnTankDeath.AddUniqueDynamic(this, &ATankAIController::OnTankDeath);
		
	}
}

FVector ATankAIController::AimTowardsPlayerTank()
{

	APawn* PlayerTank = GetWorld()->GetFirstPlayerController()->GetPawn();
	if (!ensure(PlayerTank)) { return FVector(-1.f,0.f,1.f); }
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

void ATankAIController::OnTankDeath()
{
	
	UE_LOG(LogTemp, Warning, TEXT("Tank Death - delegate fired"));
	GetPawn()->DetachFromControllerPendingDestroy();
	
}



//////// Refactored///////////
/*
ATank * ATankAIController::GetPlayerTank() const
{
	ATank* Player_Tank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());

	return Player_Tank;
}

ATank * ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}
*/

#pragma optimize("", on)




