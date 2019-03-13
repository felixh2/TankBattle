// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"

ATank * ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();

	ATank* Tank = GetControlledTank();
	if (Tank) {
		UE_LOG(LogTemp, Warning, TEXT("player controller possesed tank %s"),*(Tank->GetName()));
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("player controller couldn't possess tank"));
	}
}

void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AimTowardsCrosshair();
	
}

void ATankPlayerController::AimTowardsCrosshair()
{	
	FVector UnitVectorHitLocation  = DeprojectCrossHairToWorld();
	CalculateHitLocation(UnitVectorHitLocation);
	GetControlledTank()->AimAt(GetControlledTank()->GetName(), HitLocation.Location);	// Physical aiming 
}

FVector ATankPlayerController::DeprojectCrossHairToWorld()
{
	int32 OutViewPortSizeX, OutViewPortSizeY;
	GetViewportSize(OutViewPortSizeX, OutViewPortSizeY);
	FVector2D ScreenLocation = FVector2D(OutViewPortSizeX*CrossHairXLocation, OutViewPortSizeY*CrossHairYLocation);
	
	FVector WorldLocation;
	FVector UnitVectorHitLocation;
	DeprojectScreenPositionToWorld(ScreenLocation.X, ScreenLocation.Y, WorldLocation, UnitVectorHitLocation);

	return UnitVectorHitLocation;

	

	//UE_LOG(LogTemp, Warning, TEXT("Look Location : %s"), *UnitVectorHitLocation.ToString())
	
}

void ATankPlayerController::CalculateHitLocation(FVector &UnitVectorHitLocation)
{
	
	FVector  Start = PlayerCameraManager->GetCameraLocation();
	FVector  End =  UnitVectorHitLocation *LineTraceRange;
	FCollisionQueryParams  CollisionResponseParams;
	
	DrawDebugLine(
		GetWorld(),
		Start,
		End,
		FColor(255, 0, 0),
		false,
		0.f,
		0.f,
		12.f
	);


	GetWorld()->LineTraceSingleByChannel(
		HitLocation,
		Start,
		End,
		ECollisionChannel::ECC_Visibility		
	);
		
	AActor* ActorHit = HitLocation.GetActor();
	if (ActorHit) {
		//UE_LOG(LogTemp, Warning, TEXT("Target is :%s "), *(ActorHit->GetName()));
		//UE_LOG(LogTemp, Warning, TEXT("Location is :%s "), *HitLocation.Location.ToString());
	}
}