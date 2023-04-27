// Copyright to Andres Echeverri 2023


#include "Interactables/STreasureChest.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
ASTreasureChest::ASTreasureChest()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Base = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Base"));
	RootComponent = Base;

	Lid = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Lid"));
	Lid->SetupAttachment(RootComponent);

	TargetPitch = 110;
}

// Called when the game starts or when spawned
void ASTreasureChest::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASTreasureChest::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ASTreasureChest::Interaction_Implementation(APawn* InstigatorPawn)
{
	Lid->SetRelativeRotation(FRotator(TargetPitch, 0, 0));
}

