// Copyright to Andres Echeverri 2023


#include "AI/SAIController.h"

void ASAIController::BeginPlay()
{
	Super::BeginPlay();

	RunBehaviorTree(BehaviorTree);
}
