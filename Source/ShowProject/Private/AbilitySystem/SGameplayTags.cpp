// Copyright to Andres Echeverri 2023


#include "AbilitySystem/SGameplayTags.h"

#include "GameplayTagsManager.h"

FSGameplayTags FSGameplayTags::GameplayTags;

void FSGameplayTags::InitializeGameplayTags()
{
	GameplayTags.Input_Move = MAKETAG("Input.Move");
	GameplayTags.Input_Look = MAKETAG("Input.Look");
	GameplayTags.Input_Run = MAKETAG("Input.Run");
	GameplayTags.Input_Jump = MAKETAG("Input.Jump");
	GameplayTags.Input_Crouch = MAKETAG("Input.Crouch");
	GameplayTags.Input_Interact = MAKETAG("Input.Interact");
	GameplayTags.Input_PrimaryAction = MAKETAG("Input.PrimaryAction");
	GameplayTags.Input_SecondaryAction = MAKETAG("Input.SecondaryAction");

	GameplayTags.Attributes_Primary_Health = MAKETAG("Attributes.Primary.Health");
	GameplayTags.Attributes_Primary_MaxHealth = MAKETAG("Attributes.Primary.MaxHealth");
	GameplayTags.Attributes_Primary_Mana = MAKETAG("Attributes.Primary.Mana");
	GameplayTags.Attributes_Primary_MaxMana = MAKETAG("Attributes.Primary.MaxMana");

	GameplayTags.Attributes_Secondary_Armor = MAKETAG("Attributes.Secondary.Armor");
	GameplayTags.Attributes_Secondary_Vitality = MAKETAG("Attributes.Secondary.Vitality");
	GameplayTags.Attributes_Secondary_Strength = MAKETAG("Attributes.Secondary.Strength");
	GameplayTags.Attributes_Secondary_Dexterity = MAKETAG("Attributes.Secondary.Dexterity");
	GameplayTags.Attributes_Secondary_Resilience = MAKETAG("Attributes.Secondary.Resilience");

	GameplayTags.Abilities_Projectile_Basic = MAKETAG("Abilities.Projectile.Basic");
	GameplayTags.Abilities_Projectile_BlackHole = MAKETAG("Abilities.Projectile.BlackHole");
	GameplayTags.Abilities_Projectile_Teleport = MAKETAG("Abilities.Projectile.Teleport");
	GameplayTags.Abilities_Projectile_Explosive = MAKETAG("Abilities.Projectile.Explosive");

	GameplayTags.Status_InCooldown = MAKETAG("Status.InCooldown");
}
