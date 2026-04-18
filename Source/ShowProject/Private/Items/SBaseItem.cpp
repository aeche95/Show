// Copyright to Andres Echeverri 2026


#include "Items/SBaseItem.h"

// Sets default values
ASBaseItem::ASBaseItem()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	SetReplicates(true);

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	Mesh->SetupAttachment(RootComponent);
	Mesh->SetIsReplicated(true);
}

// Called when the game starts or when spawned
void ASBaseItem::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASBaseItem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

