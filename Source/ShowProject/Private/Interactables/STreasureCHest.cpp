// Copyright to Andres Echeverri 2023


#include "Interactables/STreasureChest.h"
#include "Components/StaticMeshComponent.h"
#include "Net/UnrealNetwork.h"

// Sets default values
ASTreasureChest::ASTreasureChest()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Base = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Base"));
	RootComponent = Base;
	Base->SetIsReplicated(true);
	Lid = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Lid"));
	Lid->SetupAttachment(RootComponent);
	Lid->SetIsReplicated(true);
	TargetPitch = 110;

	SetReplicates(true);
}

void ASTreasureChest::OnRep_LidOpened()
{
	float CurrentPitch = bLidOpened ? TargetPitch : 0.0f;
	Lid->SetRelativeRotation(FRotator(TargetPitch, 0, 0));
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
	bLidOpened = !bLidOpened;
	OnRep_LidOpened();
}

void ASTreasureChest::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(ASTreasureChest, bLidOpened);
}
