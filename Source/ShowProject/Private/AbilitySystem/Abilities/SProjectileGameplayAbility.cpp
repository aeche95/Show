// Copyright to Andres Echeverri 2023


#include "AbilitySystem/Abilities/SProjectileGameplayAbility.h"
#include "AbilitySystem/Tasks/SATPlayMontageAndWaitForEvent.h"

void USProjectileGameplayAbility::ActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, const FGameplayEventData* TriggerEventData)
{
	Super::ActivateAbility(Handle, ActorInfo, ActivationInfo, TriggerEventData);
}
