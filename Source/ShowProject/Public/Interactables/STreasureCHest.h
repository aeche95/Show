// Copyright to Andres Echeverri 2023

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Interfaces/SInteractionInterface.h"
#include "STreasureChest.generated.h"

class UStaticMeshComponent;

UCLASS()
class SHOWPROJECT_API ASTreasureChest : public AActor, public ISInteractionInterface
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASTreasureChest();

	UPROPERTY(EditAnywhere)
	float TargetPitch;

protected:

	UPROPERTY(EditAnywhere)
	TObjectPtr<UStaticMeshComponent> Base;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TObjectPtr<UStaticMeshComponent> Lid;

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void Interaction_Implementation(APawn* InstigatorPawn);

};
