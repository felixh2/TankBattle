// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankTurrent.generated.h"

/**
 * 
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class TANKBATTLECODE_API UTankTurrent : public UStaticMeshComponent
{
	GENERATED_BODY()

public:
	void RotateTurrent(float RelativeSpeed);
	

	UPROPERTY(EditAnywhere, Category = Setup)
	float MaxDegreesPerSecond = 20.f;
	
	
	
};
