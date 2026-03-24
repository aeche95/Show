// Copyright to Andres Echeverri 2023

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AbilitySystemInterface.h"
#include "SBaseCharacter.generated.h"

class UAbilitySystemComponent;
class USAttributeSet;
class USGameplayAbility;

UCLASS()
class SHOWPROJECT_API ASBaseCharacter : public ACharacter, public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ASBaseCharacter();

	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;

	USAttributeSet* GetAttributeSet() const { return AttributeSet; }

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY()
	TObjectPtr<UAbilitySystemComponent> AbilitySystemComponent;

	UPROPERTY()
	TObjectPtr<USAttributeSet> AttributeSet;

	void AddCharacterAbilities();

private:

	UPROPERTY(EditAnywhere, Category = "Abilities")
	TArray<TSubclassOf<USGameplayAbility>> StartupAbilities;

};
