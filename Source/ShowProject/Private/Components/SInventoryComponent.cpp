// Copyright to Andres Echeverri 2023


#include "Components/SInventoryComponent.h"

// Sets default values for this component's properties
USInventoryComponent::USInventoryComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	// ...
}

USInventoryComponent::USInventoryComponent(TMap<Item, int> StartItems)
{
	PrimaryComponentTick.bCanEverTick = false;

	ItemContainer = StartItems;
}


// Called when the game starts
void USInventoryComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void USInventoryComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void USInventoryComponent::AddItem(Item item)
{
	if (ItemContainer.Contains(item))
	{
		ItemContainer[item] += 1;
	}
	else
	{
		ItemContainer.Add(item);
	}
}

void USInventoryComponent::RemoveItem(Item item)
{
	if (ItemContainer.Contains(item))
	{
		if (ItemContainer[item] > 0)
		{
			ItemContainer[item] -= 1;
		}
		else
		{
			ItemContainer.Remove(item);
		}
	}
}

bool USInventoryComponent::HasItem(Item item)
{
	return ItemContainer.Contains(item);
}

