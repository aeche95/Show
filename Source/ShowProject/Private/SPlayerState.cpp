// Copyright to Andres Echeverri 2023


#include "SPlayerState.h"
#include "AbilitySystem/SAbilitySystemComponent.h"
#include "AbilitySystem/SAttributeSet.h"

ASPlayerState::ASPlayerState()
{
	SetNetUpdateFrequency(100.0f);

	AbilitySystemComponent = CreateDefaultSubobject<USAbilitySystemComponent>("Ability System Component");
	AbilitySystemComponent->SetIsReplicated(true);
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Mixed);

	AttributeSet = CreateDefaultSubobject<USAttributeSet>("Attribute Set");
}

UAbilitySystemComponent* ASPlayerState::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}
