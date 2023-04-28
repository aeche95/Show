// Copyright to Andres Echeverri 2023


#include "Components/SAttributeComponent.h"

// Sets default values for this component's properties
USAttributeComponent::USAttributeComponent()
{
	
	Health = 100.f;
}

bool USAttributeComponent::ApplyHealthChange(float Delta)
{
	Health += Delta;
	OnHealthChanged.Broadcast(this,nullptr,Health,Delta);
	return true;
}

