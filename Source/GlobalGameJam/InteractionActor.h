
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/SphereComponent.h"
#include "InteractionActor.generated.h"

UCLASS()
class GLOBALGAMEJAM_API AInteractionActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AInteractionActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	class USphereComponent* InteractionSphere;

	UPROPERTY(EditAnywhere)
	float SphereRaduis = 200.f;

	UPROPERTY(EditAnywhere)
	bool CanBeUsed = false;

	UPROPERTY(EditAnywhere)
	bool Placeable = false;

	UPROPERTY(EditAnywhere)
	bool Useable = false;

	UFUNCTION()
	void OnBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
};
