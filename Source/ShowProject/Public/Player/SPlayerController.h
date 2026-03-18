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
class USAttributeSet;

/**
 * Player controller class, to handle input
 */
UCLASS()
class SHOWPROJECT_API ASPlayerController : public APlayerController
{
	GENERATED_BODY()

public:

	ASPlayerController();

	UFUNCTION(BlueprintCallable)
	USAbilitySystemComponent* GetASC();

	UFUNCTION(BlueprintCallable)
	USAttributeSet* GetAttributeSet();

protected:

	UPROPERTY(EditDefaultsOnly, meta=(AllowBlueprintPrivateAccess="true"))
	TObjectPtr<UInputMappingContext> BaseMappingContext;

	virtual void SetupInputComponent() override;

	virtual void OnPossess(APawn* Pawn) override;

	UFUNCTION(BlueprintCallable)
	void InitializePlayerVM();

private:

	void AbilityInputTagPressed(FGameplayTag InputTag);
	void AbilityInputTagHeld(FGameplayTag InputTag);
	void AbilityInputTagReleased(FGameplayTag InputTag);

	UPROPERTY(EditDefaultsOnly)
	TObjectPtr<USInputConfig> InputConfig;

};
