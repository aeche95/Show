 //Copyright to Andres Echeverri 2023

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "GameplayTagContainer.h"
#include "SPlayerController.generated.h"

class UInputMappingContext;
class USAttributeComponent;
class USInputConfig;
class USAbilitySystemComponent;

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

private:

	void AbilityInputTagPressed(FGameplayTag InputTag);
	void AbilityInputTagHeld(FGameplayTag InputTag);
	void AbilityInputTagReleased(FGameplayTag InputTag);

	UPROPERTY(EditDefaultsOnly)
	TObjectPtr<USInputConfig> InputConfig;

	UPROPERTY()
	TObjectPtr<USAbilitySystemComponent> SAbilitySystemComponent;

	USAbilitySystemComponent* GetASC();
	
};
