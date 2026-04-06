// Copyright to Andres Echeverri 2023


#include "Magic/SProjectile.h"
#include "Components/SphereComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Particles/ParticleSystemComponent.h"
#include "Components/SAttributeComponent.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
ASProjectile::ASProjectile()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	SetReplicates(true);
	SetReplicateMovement(true);

	Sphere = CreateDefaultSubobject<USphereComponent>("Sphere");
	RootComponent = Sphere;
	Sphere->SetCollisionProfileName("Projectile");
	Sphere->SetSphereRadius(SphereRadius);
	Sphere->SetIsReplicated(true);

	ParticleSystem = CreateDefaultSubobject<UParticleSystemComponent>("Particle System");
	ParticleSystem->SetupAttachment(RootComponent);
	ParticleSystem->SetIsReplicated(true);

	ProjectileMovement = CreateDefaultSubobject<UProjectileMovementComponent>("Projectile Movement");
	ProjectileMovement->InitialSpeed = ProjectileSpeed;
	ProjectileMovement->bRotationFollowsVelocity = true;
	ProjectileMovement->bInitialVelocityInLocalSpace = true;
	ProjectileMovement->SetIsReplicated(true);
}

void ASProjectile::OnActorHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& SweepResult)
{
	if (OtherActor && OtherActor != GetInstigator())
	{
		USAttributeComponent* AttributeComp = Cast<USAttributeComponent>(OtherActor->GetComponentByClass(USAttributeComponent::StaticClass()));
		if (AttributeComp != nullptr)
		{
			AttributeComp->ApplyHealthChange(20.f);
		}
	}

}

void ASProjectile::OnCollision(AActor* OtherActor)
{
	Destroy();
}

void ASProjectile::PostInitializeComponents()
{
	Super::PostInitializeComponents();

	Sphere->OnComponentHit.AddDynamic(this, &ASProjectile::OnActorHit);
	Sphere->IgnoreActorWhenMoving(GetInstigator(), true);
}
