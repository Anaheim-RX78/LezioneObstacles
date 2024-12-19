#pragma once

#include "CoreMinimal.h"
#include "Spike.h"
#include "GameFramework/Actor.h"
#include "FallingSpike.generated.h"

UCLASS()
class OBSTACLES_API AFallingSpike : public ASpike
{
	GENERATED_BODY()
	
public:	
	AFallingSpike();

protected:
	virtual void BeginPlay() override;

	UFUNCTION()
	void OnOverlapSensor(
		UPrimitiveComponent* OverlappedComponent,
		AActor* OtherActor,
		UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex,
		bool bFromSweep,
		const FHitResult& SweepResult
	);

public:	
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere)
	UCapsuleComponent* SensorCollider;

	UPROPERTY(EditAnywhere)
	float trembleTimeSeconds = 1.f;

	UPROPERTY(EditAnywhere)
	float trembleMultiplier = 5.f;
	
	UPROPERTY(EditAnywhere)
	float moveSpeed = 1000.f;
	
	UPROPERTY(VisibleAnywhere)
	float trembleTimer = 0.f;

	UPROPERTY(VisibleAnywhere)
	bool shouldTremble = false;
	
	UPROPERTY(VisibleAnywhere)
	bool shouldMove = false;

	UPROPERTY(VisibleAnywhere)
	FVector InitialLocation;

	UPROPERTY(VisibleAnywhere)
	float attackTimer = 0.f;

};
