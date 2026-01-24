// Copyright to Andres Echeverri 2023

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"

#define MAKETAG(Name) \
	UGameplayTagsManager::Get().AddNativeGameplayTag(FName(Name));
/**
 * 
 */
struct FSGameplayTags
{
public:
	static const FSGameplayTags& Get() { return GameplayTags; }
	static void InitializeGameplayTags();

	FGameplayTag Attributes_Secondary_Armor;
	FGameplayTag InputTag_RMB;
	FGameplayTag InputTag_LMB;

private:

	static FSGameplayTags GameplayTags;

};
