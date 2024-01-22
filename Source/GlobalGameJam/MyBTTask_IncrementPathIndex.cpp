// Fill out your copyright notice in the Description page of Project Settings.


#include "MyBTTask_IncrementPathIndex.h"
#include "MyAIController.h"
#include "MyNPC.h"
#include "BehaviorTree/BlackboardComponent.h"

UMyBTTask_IncrementPathIndex::UMyBTTask_IncrementPathIndex(FObjectInitializer const& ObjectInitializer)
{
	NodeName = TEXT("Increment Path Index");
}

EBTNodeResult::Type UMyBTTask_IncrementPathIndex::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	//Get the AI Controller
	if (auto* const cont = Cast<AMyAIController>(OwnerComp.GetAIOwner()))
	{
		//Get the enemy AI
		if (auto* const npc = Cast<AMyNPC>(cont->GetPawn()))
		{
			//Get the blackboard
			if (auto* const bc = OwnerComp.GetBlackboardComponent())
			{
				//get number of patrol points and min and mix indices
				auto const NoOfPoints = npc->GetPatrolPath()->Num();
				auto const MinIndex = 0;
				auto const MaxIndex = NoOfPoints - 1;
				auto Index = bc->GetValueAsInt(GetSelectedBlackboardKey());

				//change direction when at final point or first point
				if (bBiDirectional)
				{
					if (Index >= MaxIndex && Direction == EDirectionType::Forward)
					{
						Direction = EDirectionType::Forward;
					}
					else if (Index == MinIndex && Direction == EDirectionType::Reverse)
					{
						Direction = EDirectionType::Forward;
					}
				}
				//write new value of index to blackboard
				bc->SetValueAsInt(GetSelectedBlackboardKey(),
					(Direction == EDirectionType::Forward ? ++Index : --Index) % NoOfPoints);

				//Finish with Success
				FinishLatentTask(OwnerComp, EBTNodeResult::Succeeded);
				EBTNodeResult::Succeeded;
			}
		}
	}
	//If something went wrong
	return EBTNodeResult::Failed;
}