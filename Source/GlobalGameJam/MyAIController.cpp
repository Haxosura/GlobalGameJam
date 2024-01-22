// Fill out your copyright notice in the Description page of Project Settings.


#include "MyAIController.h"
#include "MyNPC.h"
#include "Perception/AIPerceptionComponent.h"
#include "Perception/AISenseConfig_Sight.h"
#include "Perception/AISenseConfig_Hearing.h"
#include "GlobalGameJamCharacter.h"
#include "BehaviorTree/BlackboardComponent.h"

AMyAIController::AMyAIController(FObjectInitializer const& ObjectInitializer)
{
	SetupPerceptionSystem();
}

void AMyAIController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);
	if (AMyNPC* const npc = Cast<AMyNPC>(InPawn))//Check we are possessing enemy
	{
		if (UBehaviorTree* const tree = npc->GetBehaviorTree())//Check if behavior tree is there
		{
			UBlackboardComponent* b;
			UseBlackboard(tree->BlackboardAsset, b);
			Blackboard = b;
			RunBehaviorTree(tree);

			if (npc->Path == true)
				GetBlackboardComponent()->SetValueAsBool("PatrolPath", true);
			if (npc->Random == true)
				GetBlackboardComponent()->SetValueAsBool("RandomPatrol", true);
			if (npc->Still== true)
				GetBlackboardComponent()->SetValueAsBool("NoPatrol", true);
		}
	}
}

void AMyAIController::SetupPerceptionSystem()
{
	//Figure out what to detect later
}

void AMyAIController::OnTargetDetected(AActor* Actor, FAIStimulus const Stimulus)
{
	//Figure out what to detect later
}
