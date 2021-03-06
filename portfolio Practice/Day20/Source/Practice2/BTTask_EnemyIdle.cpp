// Fill out your copyright notice in the Description page of Project Settings.

#include "BTTask_EnemyIdle.h"
#include "EnemyAIController.h"
#include "EnemyCharacter.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "EnemyState.h"

UBTTask_EnemyIdle::UBTTask_EnemyIdle()
{
	NodeName = TEXT("EnemyIdle");
}

EBTNodeResult::Type UBTTask_EnemyIdle::ExecuteTask(UBehaviorTreeComponent & OwnerComp, uint8 * NodeMemory)
{
	EBTNodeResult::Type Result = Super::ExecuteTask(OwnerComp, NodeMemory);

	auto ControllingPawn = OwnerComp.GetAIOwner()->GetPawn();
	if (nullptr == ControllingPawn) {
		return EBTNodeResult::Failed;
	}
	AEnemyCharacter* EnemyCharacter = Cast< AEnemyCharacter>(ControllingPawn);
	if (nullptr == EnemyCharacter) {
		return EBTNodeResult::Failed;
	}
	UEnemyState* EnemyState = EnemyCharacter->getEnemyState();
	if (nullptr == EnemyState) {
		return EBTNodeResult::Failed;
	}

	UNavigationSystem* NavSystem = UNavigationSystem::GetNavigationSystem(ControllingPawn->GetWorld());
	if (nullptr == NavSystem) {
		return EBTNodeResult::Failed;
	}

	int32 RandomIdle = rand() % 4;

	if (RandomIdle == 0) {
		FVector Homeposkey = OwnerComp.GetBlackboardComponent()->GetValueAsVector(AEnemyAIController::HomePosKey);
		FNavLocation NextPatrol;

		if (NavSystem->GetRandomPointInNavigableRadius(Homeposkey, EnemyState->getIdleRange(), NextPatrol)) {
			OwnerComp.GetBlackboardComponent()->SetValueAsVector(AEnemyAIController::PatrolPosKey, NextPatrol.Location);
			EnemyState->setIdleNumber(RandomIdle);
			//ControllingPawn->AddActorLocalOffset(NextPatrol);
			return EBTNodeResult::Succeeded;
			//return EBTNodeResult::Failed;
		}
	}
	EnemyState->setIdleNumber(RandomIdle);
	return EBTNodeResult::Failed;
}
