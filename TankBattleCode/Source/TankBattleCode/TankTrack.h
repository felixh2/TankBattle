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
	

	virtual void BeginPlay() override;

		// Setting the Throttle value between -1 and +1
		UFUNCTION(BlueprintCallable)
		void SetThrottle(float Throttle);
	
		UPROPERTY(EditDefaultsOnly)
		float Acceleration = 2.4; 

		UPROPERTY(EditDefaultsOnly)
		float MaxforceOnTrack = 1000000; //2.4*40000;  reasonable acceleration - 2.4  [m/s^2]

		UTankTrack();
		virtual void TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction) override;

		

private:
	UFUNCTION()		
	void OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);
	
	void ApplySidewaysForce();
	void DriveTrack(float Throttle);


	float CurrentThrottle = 0.f;

};
