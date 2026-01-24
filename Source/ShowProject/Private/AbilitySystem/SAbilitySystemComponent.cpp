// Copyright to Andres Echeverri 2023


#include "AbilitySystem/SAbilitySystemComponent.h"

void USAbilitySystemComponent::AddCharacterAbilities(const TArray<TSubclassOf<UGameplayAbility>>& StartupAbilities)
{
	for (TSubclassOf<UGameplayAbility> AbilityClass : StartupAbilities)
	{
		FGameplayAbilitySpec AbilitySpec = FGameplayAbilitySpec(AbilityClass, 1);
		GiveAbility(AbilitySpec);
	}
}

void USAbilitySystemComponent::AbilityActorInfoSet()
{
	OnGameplayEffectAppliedDelegateToSelf.AddUObject(this, &USAbilitySystemComponent::EffectApllied);
}

void USAbilitySystemComponent::EffectApllied(UAbilitySystemComponent* AbilitySystemComponent, const FGameplayEffectSpec& EffectSpec, FActiveGameplayEffectHandle ActiveEffectHandle)
{
	FGameplayTagContainer TagContainer;
	EffectSpec.GetAllAssetTags(TagContainer);
	//EffectAssetTags.Broadcast(TagContainer);
}
