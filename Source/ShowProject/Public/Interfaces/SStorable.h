// Copyright to Andres Echeverri 2026

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "SStorable.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class USStorable : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class SHOWPROJECT_API ISStorable
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void Store();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void Remove();
};
