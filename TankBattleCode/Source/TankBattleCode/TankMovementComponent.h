// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/NavMovementComponent.h"
#include "TankMovementComponent.generated.h"

class ATank;
class UTankTrack;
/**
 * 
 */
UCLASS(ClassGroup = (MovementComponent), meta = (BlueprintSpawnableComponent))
class TANKBATTLECODE_API UTankMovementComponent : public UNavMovementComponent
{
	GENERATED_BODY()
	
public:

	UTankMovementComponent();

	UFUNCTION(BlueprintCallable,Category = Setup)
	void Initialize(UTankTrack* RightTankTrackToSet, UTankTrack* LeftTankTrackToSet);

	UFUNCTION(BlueprintCallable, Category= Input)
	void IntendMoveForward(float Throw);

	UFUNCTION(BlueprintCallable, Category = Input)
	void IntendTurnRight(float Throw);

	UFUNCTION(BlueprintCallable, Category = Input)
	void IntendTurnLeft(float Throw);

protected:


private:
	UTankTrack* RightTankTrack = nullptr;
	UTankTrack* LeftTankTrack = nullptr;
};
