// Copyright to Andres Echeverri 2023

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "SInteractionInterface.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class USInteractionInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class SHOWPROJECT_API ISInteractionInterface
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void Interact(APawn* InstigatorPawn);
};
