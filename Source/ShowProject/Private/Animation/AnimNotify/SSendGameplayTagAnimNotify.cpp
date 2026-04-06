// Copyright to Andres Echeverri 2026


#include "Animation/AnimNotify/SSendGameplayTagAnimNotify.h"
#include "AbilitySystemComponent.h"
#include "AbilitySystemBlueprintLibrary.h"

void USSendGameplayTagAnimNotify::Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, const FAnimNotifyEventReference& EventReference)
{
	Super::Notify(MeshComp, Animation, EventReference);

    if (AActor* Owner = MeshComp->GetOwner())
    {
        FGameplayEventData Payload;
        Payload.Instigator = Owner;
        Payload.EventTag = EventTag;
        UAbilitySystemBlueprintLibrary::SendGameplayEventToActor(Owner, EventTag, Payload);
    }
}
