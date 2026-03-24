// Copyright to Andres Echeverri 2023

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"

#define MAKETAG(Name) UGameplayTagsManager::Get().AddNativeGameplayTag(FName(Name));
/**
 * 
 */
struct FSGameplayTags
{
public:
	static const FSGameplayTags& Get() { return GameplayTags; }
	static void InitializeGameplayTags();

	FGameplayTag Input_Move;
	FGameplayTag Input_Look;
	FGameplayTag Input_Run;
	FGameplayTag Input_Crouch;
	FGameplayTag Input_Jump;
	FGameplayTag Input_Interact;
	FGameplayTag Input_PrimaryAction;
	FGameplayTag Input_SecondaryAction;

	FGameplayTag Attributes_Primary_Health;
	FGameplayTag Attributes_Primary_MaxHealth;
	FGameplayTag Attributes_Primary_Mana;
	FGameplayTag Attributes_Primary_MaxMana;

	FGameplayTag Attributes_Secondary_Armor;
	FGameplayTag Attributes_Secondary_Vitality;
	FGameplayTag Attributes_Secondary_Strength;
	FGameplayTag Attributes_Secondary_Dexterity;
	FGameplayTag Attributes_Secondary_Resilience;

	FGameplayTag Abilities_Projectile_Basic;
	FGameplayTag Abilities_Projectile_BlackHole;
	FGameplayTag Abilities_Projectile_Teleport;
	FGameplayTag Abilities_Projectile_Explosive;

	FGameplayTag Status_InCooldown;
private:

	static FSGameplayTags GameplayTags;

};
