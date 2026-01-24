// Copyright to Andres Echeverri 2023

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "SAbilitySystemComponent.generated.h"

class UGameplayAbility;
/**
 * 
 */
UCLASS()
class SHOWPROJECT_API USAbilitySystemComponent : public UAbilitySystemComponent
{
	GENERATED_BODY()

public:

	void AddCharacterAbilities(const TArray<TSubclassOf<UGameplayAbility>>& StartupAbilities);
	
	void AbilityActorInfoSet();

	void AbilityInputTagHeld(const FGameplayTag& InputTag);
	void AbilityInputTagReleased(const FGameplayTag& InputTag);

protected:

	void EffectApplied(UAbilitySystemComponent* AbilitySystemComponent, const FGameplayEffectSpec& EffectSpec, FActiveGameplayEffectHandle ActiveEffectHandle);
};
