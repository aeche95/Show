// Copyright to Andres Echeverri 2026

#pragma once

#include "CoreMinimal.h"
#include "SUITypes.generated.h"


USTRUCT(BlueprintType)
struct FInventoryItemData
{
	GENERATED_BODY()

public:
	FInventoryItemData()
	{
	}

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FName Name;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FName Description;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UTexture2D* Icon;
};
