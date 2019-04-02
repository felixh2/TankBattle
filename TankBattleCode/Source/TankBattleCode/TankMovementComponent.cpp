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

void UTankMovementComponent::IntendMoveBackward(float Throw)
{

	RightTankTrack->SetThrottle(-Throw);
	LeftTankTrack->SetThrottle(-Throw);
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

void UTankMovementComponent::RequestDirectMove(const FVector & MoveVelocity, bool bForceMaxSpeed)
{
	FVector AIMoveVelocityUnitVec = MoveVelocity.GetSafeNormal();
	FVector AIForwardTankVec = GetOwner()->GetActorForwardVector().GetSafeNormal();

	float ForwardThrow = FVector::DotProduct(AIMoveVelocityUnitVec, AIForwardTankVec);
	float RightThrow = FVector::CrossProduct(AIForwardTankVec, AIMoveVelocityUnitVec).Z;

	IntendMoveForward(ForwardThrow);
	IntendTurnRight(RightThrow);
	//UE_LOG(LogTemp, Warning, TEXT("Tank %s with Move Velocity %f "), *GetOwner()->GetFName().ToString(), RightThrow);
}
