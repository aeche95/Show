// Copyright to Andres Echeverri 2023

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "SGameplayStatics.generated.h"

class USPlayerHUDVM;
/**
 * 
 */
UCLASS()
class SHOWPROJECT_API USGameplayStatics : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
public:

	UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"))
	static USPlayerHUDVM* GetHUDVM(UObject* WorldContextObject);
};
