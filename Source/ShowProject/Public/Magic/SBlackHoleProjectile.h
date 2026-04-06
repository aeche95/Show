// Copyright to Andres Echeverri 2026

#pragma once

#include "CoreMinimal.h"
#include "Magic/SProjectile.h"
#include "SBlackHoleProjectile.generated.h"

class URadialForceComponent;
/**
 * 
 */
UCLASS()
class SHOWPROJECT_API ASBlackHoleProjectile : public ASProjectile
{
	GENERATED_BODY()

protected:

	TObjectPtr<URadialForceComponent> RadialForceComponent;

	UFUNCTION()
	void OnSphereOverlappedActor(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

public:

	virtual void PostInitializeComponents() override;

	ASBlackHoleProjectile();
};
