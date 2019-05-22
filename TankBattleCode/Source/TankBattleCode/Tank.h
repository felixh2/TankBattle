// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "Runtime/Engine/Classes/Particles/ParticleSystemComponent.h"
#include "Delegates/Delegate.h"

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Tank.generated.h"



//class UTankTurrent;
//class UTankBarrel;


DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnTankDeath);

UCLASS()
class TANKBATTLECODE_API ATank : public APawn
{
	GENERATED_BODY()

public:

	ATank();

	//void AimAt(FString WhoIsAiming, FVector &HitLocation);
/*
	UFUNCTION(BlueprintCallable, Category = Setup)
	void SetBarrelReference(UTankBarrel* BarrelRef);

	UFUNCTION(BlueprintCallable, Category = Setup)
	void SetTurrentReference(UTankTurrent* TurretReference);
	*/
	UFUNCTION(BlueprintPure, Category = "Setup")
	float GetTankHealth();


	void SetTankHealth(float NewHealth);

	
	virtual float TakeDamage(float DamageAmount, struct FDamageEvent const& DamageEvent, class AController* EventInstigator, AActor* DamageCauser) override;

	FOnTankDeath OnTankDeath;

protected:

	
	
	virtual void BeginPlay() override;
	
	UPROPERTY(BlueprintReadOnly, EditAnywhere,  Category = "Tank Status")
	float Health = 100.f;

	


	
	
//	UFUNCTION(BlueprintCallable, Category = "Setup")
//	void Initialize(UTankTurrent* TurretReference, UTankBarrel* BarrelRef);

//	UPROPERTY(BlueprintReadOnly)
//	UAimingComponent* AimingComponent = nullptr;

//	UPROPERTY(BlueprintReadOnly)                                     // Enables to expose this variable in Blueprint 
//	UTankMovementComponent* MovementComponent = nullptr;


private:

	UPROPERTY(VisibleAnywhere, Category = "Components")
	UParticleSystemComponent* TankExplosion = nullptr;
	

	//UTankBarrel* Barrel = nullptr;
	//UTankTurrent* Turrent = nullptr;

	
};
