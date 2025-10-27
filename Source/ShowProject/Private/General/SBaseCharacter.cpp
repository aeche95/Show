// Copyright to Andres Echeverri 2023


#include "General/SBaseCharacter.h"

// Sets default values
ASBaseCharacter::ASBaseCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

UAbilitySystemComponent* ASBaseCharacter::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}

// Called when the game starts or when spawned
void ASBaseCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

