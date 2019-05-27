// Fill out your copyright notice in the Description page of Project Settings.

#include "SprungWheel.h"
#include "Components/SphereComponent.h"
#include "Components/SceneComponent.h"

// Sets default values
ASprungWheel::ASprungWheel()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;



	// The thing is that it's important to set the right root - uncomment to see what happens
	/*
	Mass = CreateDefaultSubobject<UStaticMeshComponent>(FName("Body Mass"));
	SetRootComponent((USceneComponent*)Mass);

	Wheel = CreateDefaultSubobject<UStaticMeshComponent>(FName("The Wheel"));
	((USceneComponent*)Wheel)->SetupAttachment((USceneComponent*)Mass, NAME_None);
	

	MassWheelConstraint = CreateDefaultSubobject<UPhysicsConstraintComponent>(FName("Mass-Wheel Constraint"));
	MassWheelConstraint->SetupAttachment((USceneComponent*)Mass,NAME_None);
	*/


	MassWheelConstraint = CreateDefaultSubobject<UPhysicsConstraintComponent>(FName("Mass_Wheel_Constraint"));
	SetRootComponent((USceneComponent*)MassWheelConstraint);

	Axle = CreateDefaultSubobject<USphereComponent>(FName("The_Axle"));
	((USceneComponent*)Axle)->SetupAttachment((USceneComponent*)MassWheelConstraint, NAME_None);

	AxleWheelConstraint = CreateDefaultSubobject<UPhysicsConstraintComponent>(FName("Axle_Wheel_Constraint"));
	AxleWheelConstraint->SetupAttachment((USceneComponent*)Axle, NAME_None);

	Wheel = CreateDefaultSubobject<USphereComponent>(FName("The_Wheel"));
	((USceneComponent*)Wheel)->SetupAttachment((USceneComponent*)Axle, NAME_None);

	
}

// Called when the game starts or when spawned
void ASprungWheel::BeginPlay()
{
	
	Super::BeginPlay();
	AActor* AttachedParent = GetAttachParentActor();
	auto RootComponent = GetAttachParentActor()->GetRootComponent();
	if (AttachedParent) {
		UE_LOG(LogTemp, Warning, TEXT("After using ""SpawnActorDeferred"" - Not Null"));
		MassWheelConstraint->SetConstrainedComponents((UPrimitiveComponent*)RootComponent, NAME_None, (UPrimitiveComponent*)Axle, NAME_None);
		AxleWheelConstraint->SetConstrainedComponents((UPrimitiveComponent*)Wheel, NAME_None, (UPrimitiveComponent*)Axle, NAME_None);
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("Null"));
	}
	
}

// Called every frame
void ASprungWheel::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

