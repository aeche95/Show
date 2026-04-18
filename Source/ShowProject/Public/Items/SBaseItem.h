// Copyright to Andres Echeverri 2026

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Interfaces/SStorable.h"
#include "Interfaces/SInteractable.h"
#include "SBaseItem.generated.h"

class UStaticMeshComponent;

UCLASS(Abstract)
class SHOWPROJECT_API ASBaseItem : public AActor, public ISInteractable
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASBaseItem();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	TObjectPtr<UStaticMeshComponent> Mesh;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
