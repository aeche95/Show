// Copyright to Andres Echeverri 2023


#include "Player/SPlayerState.h"
#include "AbilitySystem/SAbilitySystemComponent.h"
#include "AbilitySystem/SAttributeSet.h"
#include "Net/UnrealNetwork.h"

#include "GameplayEffectTypes.h"



ASPlayerState::ASPlayerState()
{
	SetNetUpdateFrequency(100.0f);
	SetReplicates(true);

	AbilitySystemComponent = CreateDefaultSubobject<USAbilitySystemComponent>("Ability System Component");
	AbilitySystemComponent->SetIsReplicated(true);
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Mixed);

	AttributeSet = CreateDefaultSubobject<USAttributeSet>("Attribute Set");
}

void ASPlayerState::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	
	DOREPLIFETIME(ASPlayerState, Credits);
	DOREPLIFETIME(ASPlayerState, XPPoints);
	DOREPLIFETIME(ASPlayerState, Level);
}

void ASPlayerState::PostInitializeComponents()
{
	Super::PostInitializeComponents();

	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(USAttributeSet::GetHealthAttribute()).AddUObject(this, &ASPlayerState::OnHealthChanged);

	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(USAttributeSet::GetManaAttribute()).AddUObject(this, &ASPlayerState::OnManaChanged);
}
void ASPlayerState::OnHealthChanged(const FOnAttributeChangeData& Data)
{

}

void ASPlayerState::OnManaChanged(const FOnAttributeChangeData& Data)
{

}

void ASPlayerState::BeginPlay()
{
	Super::BeginPlay();

	AbilitySystemComponent->InitAbilityActorInfo(this, GetPawn());
	AbilitySystemComponent->AddCharacterAbilities(StartingAbilities);
}

UAbilitySystemComponent* ASPlayerState::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}

int32 ASPlayerState::GetCredits() const
{
	return Credits;
}

void ASPlayerState::TrySetCredits(int32 NewCredits)
{
	if (HasAuthority())
	{
		SetCredits(NewCredits);
	}
	else
	{
		Server_SetCredits(NewCredits);
	}
}

bool ASPlayerState::Server_SetCredits_Validate(int32 NewCredits)
{
	return true;
}

void ASPlayerState::Server_SetCredits_Implementation(int32 NewCredits)
{
	SetCredits(NewCredits);
}

void ASPlayerState::ChangeCredits(int32 Delta)
{
	Credits += Delta;
}

void ASPlayerState::TryChangeCredits(int32 Delta)
{
	if (HasAuthority())
	{
		ChangeCredits(Delta);
	}
	else
	{
		Server_ChangeCredits(Delta);
	}
}

bool ASPlayerState::Server_ChangeCredits_Validate(int32 Delta)
{
	return true;
}

void ASPlayerState::Server_ChangeCredits_Implementation(int32 Delta)
{
	ChangeCredits(Delta);
}

void ASPlayerState::SetCredits(int32 NewCredits)
{
	Credits = NewCredits;
}


void ASPlayerState::OnRep_Credits(int32 OldCredits)
{

}

void ASPlayerState::OnRep_XP()
{

}

void ASPlayerState::OnRep_Level(int32 OldLevel)
{
}
