// Copyright to Andres Echeverri 2023


#include "Components/SInventoryComponent.h"
#include "Net/UnrealNetwork.h"

// Sets default values for this component's properties
USInventoryComponent::USInventoryComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;
	SetIsReplicatedByDefault(true);
	MaxCapacity = 4;
	// ...
}

USInventoryComponent::USInventoryComponent(TMap<ItemID, int> StartItems)
{
	PrimaryComponentTick.bCanEverTick = false;
	SetIsReplicatedByDefault(true);
	ItemContainer = StartItems;
	MaxCapacity = 4;
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

void USInventoryComponent::AddItem(ItemID item)
{
	if (ItemContainer.Num() < MaxCapacity)
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
}

void USInventoryComponent::RemoveItem(ItemID item)
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

bool USInventoryComponent::HasItem(ItemID item)
{
	return ItemContainer.Contains(item);
}

void USInventoryComponent::IncreaseMaxCapacity(int AmountToIncrease)
{
	MaxCapacity += AmountToIncrease;
}

void USInventoryComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(USInventoryComponent, MaxCapacity);
}

