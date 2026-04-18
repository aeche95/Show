// Copyright to Andres Echeverri 2023

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Items/SItemsData.h"
#include "SInventoryComponent.generated.h"


UCLASS( ClassGroup=(Inventory), meta=(BlueprintSpawnableComponent) )
class SHOWPROJECT_API USInventoryComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	USInventoryComponent();

	USInventoryComponent(TMap<ItemID, int> StartItems);

protected:
	UPROPERTY(Replicated)
	int MaxCapacity;

	// Called when the game starts
	virtual void BeginPlay() override;

	TMap<ItemID, int> ItemContainer = TMap<ItemID, int>();

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	void AddItem(ItemID item);

	void RemoveItem(ItemID item);

	bool HasItem(ItemID item); 
	
	UFUNCTION(BlueprintCallable)
	int GetMaxCapacity() const { return MaxCapacity; } const
	
	UFUNCTION(BlueprintCallable)
	int GetAvailableCapacity() { return MaxCapacity - ItemContainer.Num(); }

	UFUNCTION()
	void IncreaseMaxCapacity(int AmountToIncrease);
};
