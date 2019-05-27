// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "PhysicsEngine/PhysicsConstraintComponent.h"

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SprungWheel.generated.h"


class USphereComponent;

UCLASS()
class TANKBATTLECODE_API ASprungWheel : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASprungWheel();

	virtual void Tick(float DeltaTime) override;


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
//	UPROPERTY(VisibleAnywhere, Category = "Components")
//	UStaticMeshComponent *Mass = nullptr;

	UPROPERTY(VisibleAnywhere, Category = "Components")
	USphereComponent *Wheel = nullptr;

	UPROPERTY(VisibleAnywhere, Category = "Components")
	USphereComponent *Axle = nullptr;

	UPROPERTY(VisibleAnywhere, Category = "Components")
	UPhysicsConstraintComponent *MassWheelConstraint = nullptr;
	
	UPROPERTY(VisibleAnywhere, Category = "Components")
	UPhysicsConstraintComponent *AxleWheelConstraint = nullptr;
	
};
