// Copyright to Andres Echeverri 2023


#include "AbilitySystem/SAttributeSet.h"

#include "Net/UnrealNetwork.h"

#define REPFUNC(AttributeName) \
	void USAttributeSet::OnRep_##AttributeName##(const FGameplayAttributeData& Old##AttributeName##) const \
	{\
		GAMEPLAYATTRIBUTE_REPNOTIFY(USAttributeSet, ##AttributeName##, Old##AttributeName##);\
	}\
	

USAttributeSet::USAttributeSet()
{
	InitHealth(100.0);
	InitMaxHealth(100.0);
	InitMana(1000.0);
	InitMaxMana(1000.0);

}

void USAttributeSet::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME_CONDITION_NOTIFY(USAttributeSet, Health, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(USAttributeSet, MaxHealth, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(USAttributeSet, Mana, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(USAttributeSet, MaxMana, COND_None, REPNOTIFY_Always);
}

REPFUNC(Health)
REPFUNC(MaxHealth)
REPFUNC(Mana)
REPFUNC(MaxMana)

