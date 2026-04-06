// Copyright to Andres Echeverri 2026


#include "Magic/SExplosiveProjectile.h"
#include "Kismet/GameplayStatics.h"

void ASExplosiveProjectile::Explode_Implementation()
{
	if (!IsPendingKillPending())
	{
		UGameplayStatics::SpawnEmitterAtLocation(this, TriggerVFX, GetActorLocation(), GetActorRotation());
		Destroy();
	}
}

void ASExplosiveProjectile::OnCollision(AActor* OtherActor)
{
	Explode();
}
