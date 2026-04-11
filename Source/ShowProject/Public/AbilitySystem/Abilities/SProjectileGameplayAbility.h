// Copyright to Andres Echeverri 2023

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystem/Abilities/SGameplayAbility.h"
#include "SProjectileGameplayAbility.generated.h"


class UAnimMontage;
class ASProjectile;
class USATPlayMontageAndWaitForEvent;
/**
 * 
 */
UCLASS()
class SHOWPROJECT_API USProjectileGameplayAbility : public USGameplayAbility
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attack")
	TSubclassOf<ASProjectile> ProjectileClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attack")
	TSubclassOf<UAnimMontage> AttackAnim;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attack")
	FName SocketName;

	UPROPERTY()
	TObjectPtr<USATPlayMontageAndWaitForEvent> Task;

	virtual void ActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, const FGameplayEventData* TriggerEventData) override;

	virtual void EndAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, bool bReplicateEndAbility, bool bWasCancelled) override;
	UFUNCTION(BlueprintCallable)
	void SpawnProjectile();

	UFUNCTION()
	void EventReceived(FGameplayTag EventTag, FGameplayEventData EventData);

	UFUNCTION()
	void OnMontageEndEvent(FGameplayTag EventTag, FGameplayEventData EventData);
};
