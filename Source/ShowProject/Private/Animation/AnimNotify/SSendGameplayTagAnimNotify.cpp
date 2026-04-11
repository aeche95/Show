// Copyright to Andres Echeverri 2026


#include "Animation/AnimNotify/SSendGameplayTagAnimNotify.h"
#include "AbilitySystemComponent.h"
#include "AbilitySystemBlueprintLibrary.h"
#include "General/SBaseCharacter.h"

void USSendGameplayTagAnimNotify::Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, const FAnimNotifyEventReference& EventReference)
{
	//Super::Notify(MeshComp, Animation, EventReference);

    if (ASBaseCharacter* SCharacter = Cast<ASBaseCharacter>(MeshComp->GetOwner()))
    {
        FGameplayEventData Payload;
        Payload.Instigator = SCharacter;
        Payload.EventTag = EventTag;
        UAbilitySystemBlueprintLibrary::SendGameplayEventToActor(SCharacter, EventTag, Payload);
        UE_LOG(LogTemp, Log, TEXT("Event notify sent"));
    }
    else
    {
        UE_LOG(LogTemp, Log, TEXT("Event notify not sent"));
    }
}
