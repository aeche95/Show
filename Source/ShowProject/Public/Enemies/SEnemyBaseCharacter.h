// Copyright to Andres Echeverri 2023

#pragma once

#include "CoreMinimal.h"
#include "General/SBaseCharacter.h"
#include "SEnemyBaseCharacter.generated.h"

UCLASS()
class SHOWPROJECT_API ASEnemyBaseCharacter : public ASBaseCharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ASEnemyBaseCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
