// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Spike.h"
#include "Components/BoxComponent.h"
#include "GameFramework/Actor.h"
#include "SpikeGate.generated.h"

UCLASS()
class OBSTACLES_API ASpikeGate : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASpikeGate();

protected:
	// Called when the game starts or when spawned
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
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, Category = "Components")
	TArray<ASpike*> Spikes;

	UPROPERTY(EditAnywhere, Category = "Components")
	UBoxComponent* BoxComponent;

	UPROPERTY(VisibleAnywhere, Category = "Components")
	float spikeGateTimeOn = 5.f;

	UPROPERTY(VisibleAnywhere, Category = "Components")
	bool spikeGateOn = false;
	
	UPROPERTY(VisibleAnywhere, Category = "Components")
	float spikeGateOnTimer = 0.f;
	
};
