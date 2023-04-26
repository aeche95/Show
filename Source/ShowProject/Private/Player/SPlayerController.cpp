// Copyright to Andres Echeverri 2023


#include "Player/SPlayerController.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"

void ASPlayerController::SetupInputComponent()
{
	if (UEnhancedInputLocalPlayerSubsystem* EnhancedInputSubsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
    {
        EnhancedInputSubsystem->ClearAllMappings();
        EnhancedInputSubsystem->AddMappingContext(BaseMappingContext, 0);
    }
}
