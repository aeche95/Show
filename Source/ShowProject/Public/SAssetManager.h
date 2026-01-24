// Copyright to Andres Echeverri 2023

#pragma once

#include "CoreMinimal.h"
#include "Engine/AssetManager.h"
#include "SAssetManager.generated.h"

/**
 * 
 */
UCLASS()
class SHOWPROJECT_API USAssetManager : public UAssetManager
{
	GENERATED_BODY()
public:
	static USAssetManager& Get();

protected:
	virtual void StartInitialLoading() override;
};
