// Copyright to Andres Echeverri 2023


#include "Player/SPlayerController.h"
#include "Input/SInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "AbilitySystemBlueprintLibrary.h"
#include "AbilitySystem/SAbilitySystemComponent.h"
#include "Player/SPlayerState.h"
#include "UI/MVVM/SPlayerHUDVM.h"
#include "UI/SHUD.h"
#include "AbilitySystem/SAttributeSet.h"
#include "MVVMGameSubsystem.h"
#include "AbilitySystem/SGameplayTags.h"



ASPlayerController::ASPlayerController()
{
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
    const FSGameplayTags& GameplayTags = FSGameplayTags::Get();

    //SInputComponent->BindAbilityAction(InputConfig, this, &ThisClass::AbilityInputTagPressed, &ThisClass::AbilityInputTagReleased, &ThisClass::AbilityInputTagHeld);

    SInputComponent->BindActionByTag(InputConfig, GameplayTags.Input_PrimaryAction, ETriggerEvent::Started, this, &ThisClass::OnPrimaryAction);
    SInputComponent->BindActionByTag(InputConfig, GameplayTags.Input_SecondaryAction, ETriggerEvent::Started, this, &ThisClass::OnSecondaryAction);
    SInputComponent->BindActionByTag(InputConfig, GameplayTags.Input_Pause, ETriggerEvent::Started, this, &ThisClass::OnPause);
}

void ASPlayerController::OnPossess(APawn* InPawn)
{
    Super::OnPossess(InPawn);
    InitializePlayerVM();
}

void ASPlayerController::InitializePlayerVM()
{
    if (HasAuthority())
    {
        USAttributeSet* AttributeSet = GetAttributeSet();
        if (AttributeSet)
        {
            int32 Health = AttributeSet->GetHealth();
            int32 MaxHealth = AttributeSet->GetMaxHealth();
            int32 Mana = AttributeSet->GetMana();
            int32 MaxMana = AttributeSet->GetMaxMana();
            FHUDValues InitValues = FHUDValues(Health, MaxHealth, Mana, MaxMana);
            const UMVVMViewModelCollectionObject* VMCollection = GetWorld()->GetGameInstance()->GetSubsystem<UMVVMGameSubsystem>()->GetViewModelCollection();

            FMVVMViewModelContext Context;
            Context.ContextName = TEXT("HUDVM");
            Context.ContextClass = USPlayerHUDVM::StaticClass();

            UMVVMViewModelBase* Found = VMCollection->FindViewModelInstance(Context);
            USPlayerHUDVM* HUDVM = Cast<USPlayerHUDVM>(Found);
            if (HUDVM)
            {
                HUDVM->Initialize(InitValues);
            }
        }
    }
}

void ASPlayerController::OnPrimaryAction()
{
    AbilityInputTagHeld(PrimaryActionTag);
}

void ASPlayerController::OnSecondaryAction()
{
    AbilityInputTagHeld(SecondaryActionTag);
}

void ASPlayerController::OnPause()
{
    ASHUD* Hud = GetHUD<ASHUD>();
    if (Hud)
    {
        Hud->OnPause();
    }
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
    ASPlayerState* SPlayerState = GetPlayerState<ASPlayerState>();
    if (SPlayerState)
    {
        USAbilitySystemComponent* SAbilitySystemComponent = CastChecked<USAbilitySystemComponent>(SPlayerState->GetAbilitySystemComponent());
        return SAbilitySystemComponent;
    }
    else
    {
        return nullptr;
    }
}

USAttributeSet* ASPlayerController::GetAttributeSet()
{
    ASPlayerState* SPlayerState = GetPlayerState<ASPlayerState>();
    if (SPlayerState)
    {
        return SPlayerState->GetAttributeSet();
    }
    else
    {
        return nullptr;
    }
}
