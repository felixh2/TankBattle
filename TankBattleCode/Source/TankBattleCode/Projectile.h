// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Projectile.generated.h"


class UTankProjectileMovementComponent;

UCLASS()
class TANKBATTLECODE_API AProjectile : public AActor
{
	GENERATED_BODY()
	
public:	

	AProjectile();
	virtual void Tick(float DeltaTime) override;
	void LaunchProjectile(float Speed);



protected:

	virtual void BeginPlay() override;




private:
	
	
	
	UTankProjectileMovementComponent * TankProjectileMovementComponent = nullptr;
	
};
