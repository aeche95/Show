// Copyright to Andres Echeverri 2023

#pragma once

#include "CoreMinimal.h"
#include "Magic/SProjectile.h"
#include "ASDashProjectile.generated.h"

/**
 * 
 */
UCLASS()
class SHOWPROJECT_API AASDashProjectile : public ASProjectile
{
	GENERATED_BODY()

public:
	AASDashProjectile();

protected:

	UPROPERTY(EditDefaultsOnly, Category = "Teleport")
	float TeleportDelay;

	UPROPERTY(EditDefaultsOnly, Category = "Teleport")
	float DetonateDelay;

	FTimerHandle TimerHandle_DelayedDetonate;

	void Trigger();

	void TeleportInstigator();

	virtual void BeginPlay() override;
};
