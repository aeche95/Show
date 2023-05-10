// Copyright to Andres Echeverri 2023

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTService.h"
#include "SBTService_CheckAttackRange.generated.h"

/**
 * 
 */
UCLASS()
class SHOWPROJECT_API USBTService_CheckAttackRange : public UBTService
{
	GENERATED_BODY()

protected:

	virtual void TickNode(UBehaviorTreeComponent& OwnerComp,uint8* NodeMemory, float DeltaSeconds) override;
	
};
