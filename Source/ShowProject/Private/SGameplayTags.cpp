// Copyright to Andres Echeverri 2023


#include "SGameplayTags.h"

#include "GameplayTagsManager.h"

FSGameplayTags FSGameplayTags::GameplayTags;

void FSGameplayTags::InitializeGameplayTags()
{
	GameplayTags.Attributes_Secondary_Armor = MAKETAG("Atributes.Secondary.Armor");
	GameplayTags.InputTag_LMB = MAKETAG("InputTag.LMB");
	GameplayTags.InputTag_RMB = MAKETAG("InputTag.RMB");

}
