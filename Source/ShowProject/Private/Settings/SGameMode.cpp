// Copyright to Andres Echeverri 2023


#include "Settings/SGameMode.h"
#include "Kismet/GameplayStatics.h"
#include "General/SSaveGame.h"
#include "SPlayerState.h"

ASGameMode::ASGameMode()
{
	PlayerStateClass = ASPlayerState::StaticClass();
	SlotName = "SaveGame01";
}

void ASGameMode::SaveGame()
{
	UGameplayStatics::SaveGameToSlot(CurrentSaveGame, SlotName, 0);
}

void ASGameMode::LoadSavedGame()
{
	if (UGameplayStatics::DoesSaveGameExist(SlotName, 0))
	{
		CurrentSaveGame = Cast<USSaveGame>(UGameplayStatics::LoadGameFromSlot(SlotName, 0));

		if (CurrentSaveGame == nullptr)
		{
			UE_LOG(LogTemp, Warning, TEXT("Failed to load data"));
			return;
		}
		UE_LOG(LogTemp, Log, TEXT("Loaded data"));
	}
	else
	{
		CurrentSaveGame = Cast<USSaveGame>(UGameplayStatics::CreateSaveGameObject(USSaveGame::StaticClass()));
	}
}

void ASGameMode::InitGame(const FString& MapName, const FString& Options, FString& ErrorMessage)
{
	Super::InitGame(MapName, Options, ErrorMessage);

	LoadSavedGame();
}
