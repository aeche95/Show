// Copyright to Andres Echeverri 2023


#include "AI/Services/SBTService_CheckAttackRange.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "AIController.h"

void USBTService_CheckAttackRange::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);

	UBlackboardComponent* BBComp = OwnerComp.GetBlackboardComponent();

	if (ensure(BBComp))
	{
		AActor* TargetActor = Cast<AActor>(BBComp->GetValueAsObject("TargetActor"));
		if (TargetActor)
		{
			AAIController* Controller = OwnerComp.GetAIOwner();
			if (Controller)
			{
				APawn* AIPawn = Controller->GetPawn();
				if (AIPawn)
				{
					float DistanceTo = FVector::Distance(TargetActor->GetActorLocation(), AIPawn->GetActorLocation());
					bool bHasLOS = false;
					bool bWithinRange = DistanceTo < 2000.f;

					if (bWithinRange)
					{
						bHasLOS = Controller->LineOfSightTo(TargetActor);
					}

					BBComp->SetValueAsBool(AttackRangeKey.SelectedKeyName, (bWithinRange && bHasLOS));

				}
			}
		}
	}
}
