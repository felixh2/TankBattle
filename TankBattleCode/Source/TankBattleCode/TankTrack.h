// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankTrack.generated.h"

/**
 * 
 */
UCLASS(ClassGroup = (Tracks), meta = (BlueprintSpawnableComponent))
class TANKBATTLECODE_API UTankTrack : public UStaticMeshComponent
{
	GENERATED_BODY()

public:
		// Setting the Throttle value between -1 and +1
		UFUNCTION(BlueprintCallable)
		void SetThrottle(float Throttle);
	
		UPROPERTY(EditDefaultsOnly)
		float Acceleration = 2.4; 

		UPROPERTY(EditDefaultsOnly)
		float MaxforceOnTrack = 960000; //2.4*40000;  reasonable acceleration - 2.4  [m/s^2]
private:


};
