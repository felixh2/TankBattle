// Fill out your copyright notice in the Description page of Project Settings.

#include "TankTrack.h"

void UTankTrack::SetThrottle(float Throttle)
{
	auto Name = GetName();
	

	auto ForceToApply = GetForwardVector() * Throttle * MaxforceOnTrack;
	auto ForceLocation = GetComponentLocation();
	//UE_LOG(LogTemp, Warning, TEXT("%s with force %f"), *Name, MaxforceOnTrack);
	auto RootTank = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());
	RootTank->AddForceAtLocation(ForceToApply, ForceLocation);
}
