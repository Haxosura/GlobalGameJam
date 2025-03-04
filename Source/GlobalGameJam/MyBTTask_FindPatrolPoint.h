// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Tasks/BTTask_BlackboardBase.h"
#include "MyBTTask_FindPatrolPoint.generated.h"

/**
 *
 */
UCLASS()
class GLOBALGAMEJAM_API UMyBTTask_FindPatrolPoint : public UBTTask_BlackboardBase
{
	GENERATED_BODY()

public:
	explicit UMyBTTask_FindPatrolPoint(FObjectInitializer const& ObjectInitializer);
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;

private:
	UPROPERTY(EditAnywhere, Category = "Blackboard", meta = (AllowPrivateAccess = "true"))
		FBlackboardKeySelector PatrolPathVectorKey;
};
