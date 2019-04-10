// Fill out your copyright notice in the Description page of Project Settings.

#include "TankTrack.h"

UTankTrack::UTankTrack() {
	PrimaryComponentTick.bCanEverTick = true;
}



void UTankTrack::BeginPlay() {
	Super::BeginPlay();
	OnComponentHit.AddDynamic(this, &UTankTrack::OnHit);
}

void UTankTrack::OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	UE_LOG(LogTemp, Warning, TEXT("Im hit"));
}

void UTankTrack::SetThrottle(float Throttle)
{
	auto Name = GetName();
	

	auto ForceToApply = GetForwardVector() * Throttle * MaxforceOnTrack;
	auto ForceLocation = GetComponentLocation();
	//UE_LOG(LogTemp, Warning, TEXT("%s with force %f"), *Name, MaxforceOnTrack);
	auto RootTank = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());
	RootTank->AddForceAtLocation(ForceToApply, ForceLocation);
}

void UTankTrack::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction * ThisTickFunction)
{

	auto SlippageSpeed = FVector::DotProduct(GetRightVector(), GetComponentVelocity());
	auto CorrectionAcceleration = -SlippageSpeed / DeltaTime * GetRightVector();
	auto TankRoot = Cast<UStaticMeshComponent>(GetOwner()->GetRootComponent());
	auto CorrectionForce = CorrectionAcceleration*TankRoot->GetMass()/2;
	TankRoot->AddForce(CorrectionForce);
	//TankRoot->AddForce(FVector(0,0,-1000000));

	
}