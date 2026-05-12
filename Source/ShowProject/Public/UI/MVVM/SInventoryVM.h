// Copyright to Andres Echeverri 2026

#pragma once

#include "CoreMinimal.h"
#include "MVVMViewModelBase.h"
#include "Interfaces/SStorable.h"
#include "UI/SUITypes.h"
#include "SInventoryVM.generated.h"



/**
 * 
 */
UCLASS()
class SHOWPROJECT_API USInventoryVM : public UMVVMViewModelBase
{
	GENERATED_BODY()

public:

	TArray<FInventoryItemData> GetItems() const;

	void SetItems(TArray<FInventoryItemData> InItems);

private:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, FieldNotify, Setter, Getter, meta = (AllowPrivateAccess = "true"));
	TArray<FInventoryItemData> Items;
};
