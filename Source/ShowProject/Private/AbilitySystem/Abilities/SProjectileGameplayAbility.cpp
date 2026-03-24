// Copyright to Andres Echeverri 2023


#include "AbilitySystem/Abilities/SProjectileGameplayAbility.h"
#include "AbilitySystem/Tasks/SATPlayMontageAndWaitForEvent.h"
#include "Player/SPlayerCharacter.h"
#include "Camera/CameraComponent.h"

void USProjectileGameplayAbility::ActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, const FGameplayEventData* TriggerEventData)
{
	Super::ActivateAbility(Handle, ActorInfo, ActivationInfo, TriggerEventData);
}

void USProjectileGameplayAbility::SpawnProjectile()
{
	ASPlayerCharacter* OwnerCharacter = CastChecked<ASPlayerCharacter>(GetAvatarActorFromActorInfo());

	FVector Location = OwnerCharacter->GetMesh()->GetSocketLocation("Muzzle_01");
	FActorSpawnParameters SpawnParams;
	SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
	SpawnParams.Instigator = OwnerCharacter;

	FCollisionShape Shape;
	Shape.SetSphere(20.0f);

	FCollisionQueryParams Params;
	Params.AddIgnoredActor(OwnerCharacter);

	FCollisionObjectQueryParams ObjParams;
	ObjParams.AddObjectTypesToQuery(ECC_WorldDynamic);
	ObjParams.AddObjectTypesToQuery(ECC_WorldStatic);
	ObjParams.AddObjectTypesToQuery(ECC_Pawn);

	FVector TraceStart = OwnerCharacter->GetCamera()->GetComponentLocation();
	FVector TraceEnd = OwnerCharacter->GetCamera()->GetComponentLocation() + (OwnerCharacter->GetControlRotation().Vector() * 5000.0f);
	FHitResult Hit;

	if (GetWorld()->SweepSingleByObjectType(Hit, TraceStart, TraceEnd, FQuat::Identity, ObjParams, Shape, Params))
	{
		TraceEnd = Hit.ImpactPoint;
	}

	FRotator ProjRotation = FRotationMatrix::MakeFromX(TraceEnd - Location).Rotator();
	FTransform SpawnTransform = FTransform(ProjRotation, Location);
	GetWorld()->SpawnActor<AActor>(ProjectileClass, SpawnTransform, SpawnParams);
}
