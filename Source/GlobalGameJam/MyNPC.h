// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BehaviorTree.h"
#include "PatrolPath.h"
#include "GameFramework/Character.h"
#include "MyNPC.generated.h"

UCLASS()
class GLOBALGAMEJAM_API AMyNPC : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AMyNPC();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI", meta = (AllowPrivateAccess = "true"))
		UBehaviorTree* Tree;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI", meta = (AllowPrivateAccess = "true"))
		APatrolPath* PatrolPath;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UBehaviorTree* GetBehaviorTree() const;

	APatrolPath* GetPatrolPath() const;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Patrolling")
		bool Path = false;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Patrolling")
		bool Random = false;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Patrolling")
		bool Still = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int LaughPoints = 0;
};
