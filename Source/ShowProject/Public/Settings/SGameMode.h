// Copyright to Andres Echeverri 2023

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "SGameMode.generated.h"

class USSaveGame;
/**
 * 
 */
UCLASS()
class SHOWPROJECT_API ASGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:

	ASGameMode();

	UFUNCTION(BlueprintCallable, Category = "Save Game")
	void SaveGame();

	void LoadSavedGame();

	void InitGame(const FString& MapName, const FString& Options, FString& ErrorMessage) override;

protected:

	FString SlotName;

	UPROPERTY()
	USSaveGame* CurrentSaveGame;
	
};
