// Copyright to Andres Echeverri 2023


#include "AI/Services/SBTService_CheckAttackRange.h"
#include "BehaviorTree/BlackboardComponent.h"

void USBTService_CheckAttackRange::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);

	UBlackboardComponent* BBComp = OwnerComp.GetBlackboardComponent();

	if (ensure(BBComp))
	{
		AActor* Actor = Cast<AActor>(BBComp->GetValueAsObject("TargetActor"));
	}
}
