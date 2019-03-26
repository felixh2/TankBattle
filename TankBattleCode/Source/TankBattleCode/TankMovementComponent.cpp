// Fill out your copyright notice in the Description page of Project Settings.

#include "TankMovementComponent.h"
#include "TankTrack.h"


UTankMovementComponent::UTankMovementComponent() 
{

}

void UTankMovementComponent::Initialize(UTankTrack* RightTankTrackToSet, UTankTrack* LeftTankTrackToSet)
{
	if (!RightTankTrackToSet || !LeftTankTrackToSet) { return; }

	RightTankTrack = RightTankTrackToSet;
	LeftTankTrack = LeftTankTrackToSet;
}

void UTankMovementComponent::IntendMoveForward(float Throw)
{
	
	RightTankTrack->SetThrottle(Throw);
	LeftTankTrack->SetThrottle(Throw);
	//UE_LOG(LogTemp, Warning, TEXT("Intend move with %f throw"), Throw);


}

void UTankMovementComponent::IntendTurnRight(float Throw)
{
	RightTankTrack->SetThrottle(-Throw);
	LeftTankTrack->SetThrottle(Throw);
}

void UTankMovementComponent::IntendTurnLeft(float Throw)
{
	RightTankTrack->SetThrottle(Throw);
	LeftTankTrack->SetThrottle(-Throw);
}