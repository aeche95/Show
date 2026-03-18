// Copyright to Andres Echeverri 2023


#include "AbilitySystem/SGameplayTags.h"

#include "GameplayTagsManager.h"

FSGameplayTags FSGameplayTags::GameplayTags;

void FSGameplayTags::InitializeGameplayTags()
{
	GameplayTags.Attributes_Secondary_Armor = MAKETAG("Atributes.Secondary.Armor");
	GameplayTags.InputTag_LMB = MAKETAG("InputTag.LMB");
	GameplayTags.InputTag_RMB = MAKETAG("InputTag.RMB");
	GameplayTags.Attributes_Health = MAKETAG("Attributes.Health");
	GameplayTags.Attributes_MaxHealth = MAKETAG("Attributes.MaxHealth");
	GameplayTags.Attributes_Mana = MAKETAG("Attributes.Mana");
	GameplayTags.Attributes_MaxMana = MAKETAG("Attributes.MaxMana");
	GameplayTags.Abilities_Projectile_Basic = MAKETAG("Abilities.Projectile.Basic");
}
