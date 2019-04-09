// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Runtime/Engine/Classes/Engine/World.h"
#include "DrawDebugHelpers.h"


#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"


class UAimingComponent;
/**
 * 
 */
UCLASS()
class TANKBATTLECODE_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()

public:		
		virtual void BeginPlay() override;
		virtual void Tick(float DeltaTime) override;
		void AimTowardsCrosshair();
		
		FVector DeprojectCrossHairToWorld() ;
		void CalculateHitLocation(FVector &UnitVectorHitLocation);


		UPROPERTY(EditAnywhere)
		float CrossHairXLocation = 0.5;
		
		UPROPERTY(EditAnywhere)
		float CrossHairYLocation = 0.3333;

		UPROPERTY(EditAnywhere)
		float LineTraceRange = 10000000.0f;


		FHitResult  HitLocation;
protected:

//	UFUNCTION(BlueprintCallable, Category = "setup")
//	ATank * GetControlledTank() const;

	UFUNCTION(BlueprintImplementableEvent, Category = "Setup")
	void FindAimingComponent(UAimingComponent* AimingComponent);

private:
	UAimingComponent * AimingComponent = nullptr;
};
