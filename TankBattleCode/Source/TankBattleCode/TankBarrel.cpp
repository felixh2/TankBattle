// Fill out your copyright notice in the Description page of Project Settings.


#include "TankBarrel.h"
#include "math.h"


#pragma optimize("", off)
void UTankBarrel::Elevate(float RelativeSpeed)
{
	RelativeSpeed = FMath::Clamp<float>(RelativeSpeed, -1, +1);
	auto ElevationChange = RelativeSpeed * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
	
	auto NewRawElevation = RelativeRotation.Pitch + ElevationChange;
	auto Elevation = FMath::Clamp<float>(NewRawElevation, MinElevationInDegrees, MaxElevationInDegrees);
	SetRelativeRotation(FRotator(Elevation, 0, 0));

	/*
	float Pitch = GetRelativeTransform().GetRotation().Rotator().Pitch; 
	if( (Pitch <= MaxElevationInDegrees) & (Pitch >= MinElevationInDegrees) )
		AddRelativeRotation(FRotator(ElevationChange, 0, 0));
		*/
	
	//UE_LOG(LogTemp, Warning, TEXT("Elevating %f degrees"), RelativeSpeed);

}
#pragma optimize("", on)