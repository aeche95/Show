// Copyright to Andres Echeverri 2023


#include "AbilitySystem/Abilities/SProjectileGameplayAbility.h"
#include "Player/SPlayerCharacter.h"
#include "Camera/CameraComponent.h"
#include "Magic/SProjectile.h"
#include "AbilitySystem/Tasks/SATPlayMontageAndWaitForEvent.h"
#include "AbilitySystem/SGameplayTags.h"

void USProjectileGameplayAbility::ActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, const FGameplayEventData* TriggerEventData)
{
	Super::ActivateAbility(Handle, ActorInfo, ActivationInfo, TriggerEventData);

	/*ASPlayerCharacter* Player = Cast<ASPlayerCharacter>(ActorInfo->AvatarActor.Get());
	if (Player && AttackAnim)
	{
		Task = USATPlayMontageAndWaitForEvent::PlayMontageAndWaitForEvent(this, "Play Montage And Wait For Event", AttackAnim, FGameplayTagContainer(FSGameplayTags::Get().Abilities_Projectile_Basic));
		Task->EventReceived.AddDynamic(this, &USProjectileGameplayAbility::EventReceived);
		Task->OnBlendOut.AddDynamic(this, &USProjectileGameplayAbility::OnMontageEndEvent);
		Task->OnCancelled.AddDynamic(this, &USProjectileGameplayAbility::OnMontageEndEvent);
		Task->OnCompleted.AddDynamic(this, &USProjectileGameplayAbility::OnMontageEndEvent);

		Task->ReadyForActivation();
	}*/
}

void USProjectileGameplayAbility::EndAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, bool bReplicateEndAbility, bool bWasCancelled)
{
	Super::EndAbility(Handle, ActorInfo, ActivationInfo, bReplicateEndAbility, bWasCancelled);
	
}

void USProjectileGameplayAbility::SpawnProjectile()
{
	if (GetOwningActorFromActorInfo()->GetLocalRole() == ROLE_Authority)
	{
		ASPlayerCharacter* OwnerCharacter = CastChecked<ASPlayerCharacter>(GetAvatarActorFromActorInfo());

		FVector Location = OwnerCharacter->GetMesh()->GetSocketLocation(SocketName);
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
		GetWorld()->SpawnActor<ASProjectile>(ProjectileClass, SpawnTransform, SpawnParams);
	}
}

void USProjectileGameplayAbility::EventReceived(FGameplayTag EventTag, FGameplayEventData EventData)
{
	/*if (EventTag.MatchesTag(FSGameplayTags::Get().Abilities_Projectile_Basic))
	{*/
		SpawnProjectile();
	//}
}

void USProjectileGameplayAbility::OnMontageEndEvent(FGameplayTag EventTag, FGameplayEventData EventData)
{
	K2_EndAbility();
}
