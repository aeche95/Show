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
	PrimaryActorTick.bCanEverTick = true;

	Sphere = CreateDefaultSubobject<USphereComponent>("Sphere");
	RootComponent = Sphere;
	Sphere->SetCollisionProfileName("Projectile");
	Sphere->OnComponentBeginOverlap.AddDynamic(this, &ASProjectile::OnActorOverlap);

	ParticleSystem = CreateDefaultSubobject<UParticleSystemComponent>("Particle System");
	ParticleSystem->SetupAttachment(RootComponent);

	ProjectileMovement = CreateDefaultSubobject<UProjectileMovementComponent>("Projectile Movement");
	ProjectileMovement->InitialSpeed = 1000.f;
	ProjectileMovement->bRotationFollowsVelocity = true;
	ProjectileMovement->bInitialVelocityInLocalSpace = true;
}

void ASProjectile::OnActorOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor && OtherActor != GetInstigator())
	{
		USAttributeComponent* AttributeComp = Cast<USAttributeComponent>(OtherActor->GetComponentByClass(USAttributeComponent::StaticClass()));
		if (AttributeComp != nullptr)
		{
			AttributeComp->ApplyHealthChange(20.f);
		}
	}
	Explode();
}

void ASProjectile::Explode_Implementation()
{
	if (!IsPendingKillPending())
	{
		UGameplayStatics::SpawnEmitterAtLocation(this, ParticleVFX, GetActorLocation(), GetActorRotation());

		Destroy();
	}
}

// Called every frame
void ASProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

