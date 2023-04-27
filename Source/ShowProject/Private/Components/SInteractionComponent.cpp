// Copyright to Andres Echeverri 2023


#include "Components/SInteractionComponent.h"
#include "Interfaces/SInteractionInterface.h"

// Sets default values for this component's properties
USInteractionComponent::USInteractionComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

void USInteractionComponent::PrimaryInteract()
{
	FCollisionObjectQueryParams Params;
	Params.AddObjectTypesToQuery(ECC_WorldDynamic);

	AActor* Owner = GetOwner();
	

	FVector EyeLocation;
	FRotator EyeRotation;
	Owner->GetActorEyesViewPoint(EyeLocation, EyeRotation);

	FVector End = EyeLocation + EyeRotation.Vector() * 1000;
	
	/*FHitResult OutHit;

	GetWorld()->LineTraceSingleByObjectType(OutHit, EyeLocation, End, Params);*/

	TArray<FHitResult> Hits;

	FCollisionShape Shape;
	Shape.MakeSphere(30.f);

	bool bBlockingHit = GetWorld()->SweepMultiByObjectType(Hits, EyeLocation, End, FQuat::Identity, Params, Shape);
	for (FHitResult Hit : Hits)
	{
		AActor* HitActor = Hit.GetActor();
		if(HitActor)
		{
			if (HitActor->Implements<USInteractionInterface>())
			{
				APawn* MyPawn = Cast<APawn>(Owner);
			
				ISInteractionInterface::Execute_Interact(HitActor, MyPawn);
				break;
			}
		}

	}
}


// Called when the game starts
void USInteractionComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void USInteractionComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

