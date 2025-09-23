// Copyright to Andres Echeverri 2023


#include "Magic/ASDashProjectile.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Particles/ParticleSystemComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"

AASDashProjectile::AASDashProjectile()
{
	TeleportDelay = 0.2f;
	DetonateDelay = 0.2f;

	ProjectileMovement->InitialSpeed = 6000.f;
}

void AASDashProjectile::BeginPlay()
{
	Super::BeginPlay();

	GetWorldTimerManager().SetTimer(TimerHandle_DelayedDetonate, this, &AASDashProjectile::Explode, DetonateDelay);
}

void AASDashProjectile::Explode_Implementation()
{
	GetWorldTimerManager().ClearTimer(TimerHandle_DelayedDetonate);

	UGameplayStatics::SpawnEmitterAtLocation(this, ParticleVFX, GetActorLocation(), GetActorRotation());

	ParticleSystem->DeactivateSystem();

	ProjectileMovement->StopMovementImmediately();
	SetActorEnableCollision(false);

	FTimerHandle TimerHandle_DelayedTeleport;
	GetWorldTimerManager().SetTimer(TimerHandle_DelayedTeleport, this, &AASDashProjectile::TeleportInstigator, TeleportDelay);
}

void AASDashProjectile::TeleportInstigator()
{
	AActor* ActorToTeleport = GetInstigator();
	if (ActorToTeleport)
	{
		ActorToTeleport->TeleportTo(GetActorLocation(), ActorToTeleport->GetActorRotation(), false, false);
	}
}




