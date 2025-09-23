 //Copyright to Andres Echeverri 2023

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "SPlayerController.generated.h"

class UInputMappingContext;
class USAttributeComponent;

/**
 * Player controller class, to handle input
 */
UCLASS()
class SHOWPROJECT_API ASPlayerController : public APlayerController
{
	GENERATED_BODY()

public:

	ASPlayerController();

protected:

	UPROPERTY(EditDefaultsOnly, meta=(AllowBlueprintPrivateAccess="true"))
	TObjectPtr<UInputMappingContext> BaseMappingContext;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TObjectPtr<USAttributeComponent> Attributes;

	virtual void SetupInputComponent() override;
	
};
