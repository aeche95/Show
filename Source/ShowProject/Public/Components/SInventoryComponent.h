// Copyright to Andres Echeverri 2023

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Items/SItemsData.h"
#include "SInventoryComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class SHOWPROJECT_API USInventoryComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	USInventoryComponent();

	USInventoryComponent(TMap<Item, int> StartItems);

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	TMap<Item, int> ItemContainer = TMap<Item, int>();

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	void AddItem(Item item);

	void RemoveItem(Item item);

	bool HasItem(Item item);
};
