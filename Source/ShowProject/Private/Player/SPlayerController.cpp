// Copyright to Andres Echeverri 2023


#include "Player/SPlayerController.h"
#include "Input/SInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "Components/SAttributeComponent.h"
#include "AbilitySystemBlueprintLibrary.h"
#include "AbilitySystem/SAbilitySystemComponent.h"

ASPlayerController::ASPlayerController()
{
    Attributes = CreateDefaultSubobject<USAttributeComponent>(TEXT("Attributes"));
    bReplicates = true;
}

void ASPlayerController::SetupInputComponent()
{
    Super::SetupInputComponent();
    if (UEnhancedInputLocalPlayerSubsystem* EnhancedInputSubsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
    {
        EnhancedInputSubsystem->ClearAllMappings();
        EnhancedInputSubsystem->AddMappingContext(BaseMappingContext, 0);
    }

    USInputComponent* SInputComponent = CastChecked<USInputComponent>(InputComponent);

    SInputComponent->BindAbilityAction(InputConfig, this, &ThisClass::AbilityInputTagPressed, &ThisClass::AbilityInputTagReleased, &ThisClass::AbilityInputTagHeld);
}

void ASPlayerController::AbilityInputTagPressed(FGameplayTag InputTag)
{
    
}

void ASPlayerController::AbilityInputTagHeld(FGameplayTag InputTag)
{
    if (GetASC() == nullptr) return;
    GetASC()->AbilityInputTagHeld(InputTag);

}

void ASPlayerController::AbilityInputTagReleased(FGameplayTag InputTag)
{
    if (GetASC() == nullptr) return;
    GetASC()->AbilityInputTagReleased(InputTag);
}

USAbilitySystemComponent* ASPlayerController::GetASC()
{
    if (SAbilitySystemComponent == nullptr)
    {
        SAbilitySystemComponent = Cast<USAbilitySystemComponent>(UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(GetPawn<APawn>()));

    }
    return SAbilitySystemComponent;
}
