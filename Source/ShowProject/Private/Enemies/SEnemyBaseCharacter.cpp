// Copyright to Andres Echeverri 2023


#include "Enemies/SEnemyBaseCharacter.h"
#include "AbilitySystem/SAbilitySystemComponent.h"
#include "AbilitySystem/SAttributeSet.h"


ASEnemyBaseCharacter::ASEnemyBaseCharacter()
{
 	
	PrimaryActorTick.bCanEverTick = true;

	AbilitySystemComponent = CreateDefaultSubobject<USAbilitySystemComponent>("Ability System Component");
	AbilitySystemComponent->SetIsReplicated(true);
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Minimal);

	AttributeSet = CreateDefaultSubobject<USAttributeSet>("Attribute Set");

}

void ASEnemyBaseCharacter::BeginPlay()
{
	Super::BeginPlay();
	AbilitySystemComponent->InitAbilityActorInfo(this, this);
	
}

void ASEnemyBaseCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


