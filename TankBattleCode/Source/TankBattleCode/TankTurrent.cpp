// Fill out your copyright notice in the Description page of Project Settings.

#include "TankTurrent.h"
#include "Runtime/Engine/Classes/Engine/World.h"
#include "math.h"


#pragma optimize("", off)
void UTankTurrent::RotateTurrent(float RelativeSpeed)
{
	RelativeSpeed = FMath::Clamp<float>(RelativeSpeed, -1, +1);
	auto YawAngle = RelativeSpeed * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
	AddRelativeRotation(FRotator(0, YawAngle, 0));
	//UE_LOG(LogTemp, Warning, TEXT("Trying to rotate"));
}

#pragma optimize("", on)