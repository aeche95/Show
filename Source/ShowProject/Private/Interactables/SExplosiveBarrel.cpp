// Copyright to Andres Echeverri 2023


#include "Interactables/SExplosiveBarrel.h"
#include "PhysicsEngine/RadialForceComponent.h"

// Sets default values
ASExplosiveBarrel::ASExplosiveBarrel()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	SetReplicates(true);
	SetReplicateMovement(true);
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	Mesh->SetSimulatePhysics(true);
	RootComponent = Mesh;
	Mesh->SetIsReplicated(true);
	ForceComponent = CreateDefaultSubobject<URadialForceComponent>(TEXT("Force Component"));
	ForceComponent->SetupAttachment(RootComponent);
	ForceComponent->SetAutoActivate(false);
	ForceComponent->Radius = 750.f;
	ForceComponent->ImpulseStrength = 2500.f;
	ForceComponent->bImpulseVelChange = true;
	ForceComponent->AddCollisionChannelToAffect(ECC_WorldDynamic);
	ForceComponent->SetIsReplicated(true);
}

// Called when the game starts or when spawned
void ASExplosiveBarrel::BeginPlay()
{
	Super::BeginPlay();
	
}

void ASExplosiveBarrel::PostInitializeComponents()
{
	Super::PostInitializeComponents();
	Mesh->OnComponentHit.AddDynamic(this, &ASExplosiveBarrel::OnActorHit);
}

void ASExplosiveBarrel::OnActorHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	ForceComponent->FireImpulse();
}

// Called every frame
void ASExplosiveBarrel::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

