// Copyright to Andres Echeverri 2026


#include "UI/MVVM/SInventoryVM.h"

TArray<FInventoryItemData> USInventoryVM::GetItems() const
{
	return Items;
}

void USInventoryVM::SetItems(TArray<FInventoryItemData> InItems)
{
	Items = InItems;
}
