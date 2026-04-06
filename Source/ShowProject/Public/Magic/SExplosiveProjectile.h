// Copyright to Andres Echeverri 2026

#pragma once

#include "CoreMinimal.h"
#include "Magic/SProjectile.h"
#include "SExplosiveProjectile.generated.h"

class UParticleSystem;
/**
 * 
 */
UCLASS()
class SHOWPROJECT_API ASExplosiveProjectile : public ASProjectile
{
	GENERATED_BODY()
	
protected:

	virtual void OnCollision(AActor* OtherActor) override;

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void Explode();
};
