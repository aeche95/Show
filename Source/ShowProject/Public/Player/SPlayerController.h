 //Copyright to Andres Echeverri 2023

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "SPlayerController.generated.h"

class UInputMappingContext;

/**
 * Player controller class, to handle input
 */
UCLASS()
class SHOWPROJECT_API ASPlayerController : public APlayerController
{
	GENERATED_BODY()

protected:

	UPROPERTY(EditDefaultsOnly, meta=(AllowBlueprintPrivateAccess="true"))
	UInputMappingContext* BaseMappingContext;

	virtual void SetupInputComponent() override;
	
};
