// Copyright to Andres Echeverri 2023

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystem/Abilities/SGameplayAbility.h"
#include "SProjectileGameplayAbility.generated.h"


class UAnimMontage;
/**
 * 
 */
UCLASS()
class SHOWPROJECT_API USProjectileGameplayAbility : public USGameplayAbility
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attack")
	TSubclassOf<AActor> ProjectileClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attack")
	UAnimMontage* AttackAnim;


	virtual void ActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, const FGameplayEventData* TriggerEventData) override;

	UFUNCTION(BlueprintCallable)
	void SpawnProjectile();
	
};
