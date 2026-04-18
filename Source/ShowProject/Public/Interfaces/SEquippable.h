// Copyright to Andres Echeverri 2026

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "SEquippable.generated.h"

class ASBaseCharacter;
// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class USEquippable : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class SHOWPROJECT_API ISEquippable
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void Equip(ASBaseCharacter* Target);
};
