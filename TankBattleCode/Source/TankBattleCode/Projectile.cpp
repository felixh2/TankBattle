// Fill out your copyright notice in the Description page of Project Settings.

#include "Projectile.h"
#include "TankProjectileMovementComponent.h"
#include "Runtime/Engine/Classes/Engine/World.h"
#include "Particles/ParticleSystemComponent.h"
#include "Runtime/Engine/Public/TimerManager.h"
#include "Tank.h"
#include "AimingComponent.h"
#include "Runtime/Engine/Classes/GameFramework/DamageType.h"


// Sets default values
AProjectile::AProjectile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	CollisionMesh = CreateDefaultSubobject<UStaticMeshComponent>(FName("Collison Mesh"));
	
	SetRootComponent((USceneComponent*)CollisionMesh);
	CollisionMesh->SetNotifyRigidBodyCollision(true);
	CollisionMesh->SetVisibility(false);

	LaunchBlast = CreateDefaultSubobject<UParticleSystemComponent>(FName("Launch Blast"));
	LaunchBlast->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);

	ImpactBlast = CreateDefaultSubobject<UParticleSystemComponent>(FName("Impact Blast"));
	ImpactBlast->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
	ImpactBlast->bAutoActivate = false;

	RadialForce = CreateDefaultSubobject<URadialForceComponent>(FName("Radial Force"));
	RadialForce->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);

	TankProjectileMovementComponent = CreateDefaultSubobject<UTankProjectileMovementComponent>(FName("Tank Projectile Movement Component"));
	TankProjectileMovementComponent->bAutoActivate = false;

}

// Called when the game starts or when spawned
void AProjectile::BeginPlay()
{
	Super::BeginPlay();
	CollisionMesh->OnComponentHit.AddDynamic(this, &AProjectile::OnHit);
}

void AProjectile::OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	UE_LOG(LogTemp, Warning, TEXT("BOOM!!"));

	// # 1 Option
	/*if (Cast<ATank>(OtherActor))
	{
		float Health = ((ATank*)OtherActor)->GetTankHealth();
		((ATank*)OtherActor)->SetTankHealth( Health - 20.f);

		if (((ATank*)OtherActor)->GetTankHealth() < 1.f) {
			//((ATank*)OtherActor)->SetActorScale3D(FVector(0.1f, 0.1f, 0.1f));
			//((ATank*)OtherActor)->Destroy();

			
			UAimingComponent *AimingComp = ((ATank*)OtherActor)->FindComponentByClass<UAimingComponent>();
			AimingComp->SetAmmo(0);
			//((ATank*)OtherActor)->GetCompo//GetComponentByClass<UAimingComponent>()
		}
	}*/

	// # 2 Option
	UGameplayStatics::ApplyRadialDamage(
		this,
		ProjectileDamage,
		GetActorLocation(),
		RadialForce->Radius,
		UDamageType::StaticClass(),
		TArray<AActor*>()			// Damage all actors
	);


	LaunchBlast->Deactivate();
	ImpactBlast->Activate();
	RadialForce->FireImpulse();

	SetRootComponent(ImpactBlast);
	CollisionMesh->DestroyComponent();                   // Doesn't  destroys the actor
	
	
	FTimerHandle OutTimerHandle;
	GetWorld()->GetTimerManager().SetTimer(OutTimerHandle, this, &AProjectile::OnTimerOverlap, 5.f, false);
	
}

void AProjectile::OnTimerOverlap()
{
	UE_LOG(LogTemp, Warning, TEXT("Timer Over"));
	Destroy();
}

void AProjectile::LaunchProjectile(float Speed)
{
	//TimerManager = GetWorld()->GetTimerManager();
	float Time = GetWorld()->GetTimeSeconds();
	//UE_LOG(LogTemp, Warning, TEXT("%f Fire with speed %f"), Time, Speed);

	TankProjectileMovementComponent->SetVelocityInLocalSpace(FVector::ForwardVector * Speed);
	TankProjectileMovementComponent->Activate();
}

// Called every frame
void AProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

