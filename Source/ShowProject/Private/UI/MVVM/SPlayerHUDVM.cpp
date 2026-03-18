// Copyright to Andres Echeverri 2023


#include "UI/MVVM/SPlayerHUDVM.h"

int32 USPlayerHUDVM::GetHealth() const
{
	return Health;
}

int32 USPlayerHUDVM::GetMana() const
{
	return Mana;
}

int32 USPlayerHUDVM::GetMaxHealth() const
{
	return MaxHealth;
}

int32 USPlayerHUDVM::GetMaxMana() const
{
	return MaxMana;
}

int32 USPlayerHUDVM::GetCredits() const
{
	return Credits;
}

void USPlayerHUDVM::SetHealth(int32 InHealth)
{
	if (UE_MVVM_SET_PROPERTY_VALUE(Health, InHealth))
	{
		
		UE_MVVM_BROADCAST_FIELD_VALUE_CHANGED(GetHealthPercent);
	}
}

void USPlayerHUDVM::SetMana(int32 InMana)
{
	if (UE_MVVM_SET_PROPERTY_VALUE(Mana, InMana))
	{
		
		UE_MVVM_BROADCAST_FIELD_VALUE_CHANGED(GetManaPercent);
	}
}

void USPlayerHUDVM::SetMaxHealth(int32 InMaxHealth)
{
	if (UE_MVVM_SET_PROPERTY_VALUE(MaxHealth, InMaxHealth))
	{
		UE_MVVM_BROADCAST_FIELD_VALUE_CHANGED(GetHealthPercent);
	}
}

void USPlayerHUDVM::SetMaxMana(int32 InMaxMana)
{
	if (UE_MVVM_SET_PROPERTY_VALUE(MaxMana, InMaxMana))
	{
		UE_MVVM_BROADCAST_FIELD_VALUE_CHANGED(GetManaPercent);
	}
}

void USPlayerHUDVM::SetCredits(int32 InCredits)
{
	if (UE_MVVM_SET_PROPERTY_VALUE(Credits, InCredits))
	{
		
	}
}

void USPlayerHUDVM::Initialize(FHUDValues InitValues)
{
	SetHealth(InitValues.Health);
	SetMana(InitValues.Mana);
	SetMaxHealth(InitValues.MaxHealth);
	SetMaxMana(InitValues.MaxMana);
}

float USPlayerHUDVM::GetHealthPercent() const
{
	if (MaxHealth != 0)
	{
		return (float)Health / (float)MaxHealth;
	}
	else
	{
		return 0;
	}
}

float USPlayerHUDVM::GetManaPercent() const
{
	if (MaxMana != 0)
	{
		return (float)Mana / (float)MaxMana;
	}
	else
	{
		return 0;
	}
}
