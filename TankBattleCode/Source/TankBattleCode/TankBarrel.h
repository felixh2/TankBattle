// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "Runtime/Engine/Classes/Engine/World.h"


#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankBarrel.generated.h"

/**
 * 
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent),hidecategories = ("Collision"))
class TANKBATTLECODE_API UTankBarrel : public UStaticMeshComponent
{
	GENERATED_BODY()

public:
		void Elevate(float RelativeSpeed);
	
		UPROPERTY(EditAnywhere, Category = Setup)
		float MaxDegreesPerSecond = 5.f;

		UPROPERTY(EditAnywhere, Category = Setup)
		float MaxElevationInDegrees = 30.f; //TDOD set
	
		UPROPERTY(EditAnywhere, Category = Setup)
		float MinElevationInDegrees = 0.f; // TODO set
};
