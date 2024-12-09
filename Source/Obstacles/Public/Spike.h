// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/CapsuleComponent.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Spike.generated.h"

UCLASS()
class OBSTACLES_API ASpike : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASpike();

	UPROPERTY(EditAnywhere, Category="Components")
	UCapsuleComponent* CapsuleComponent;

	UPROPERTY(EditAnywhere, Category="Components")
	UStaticMeshComponent* MeshComponent;
	
	UPROPERTY(EditAnywhere, Category = "Spike")
	float ImpactDamage;
	
	UPROPERTY(EditAnywhere, Category = "Spike")
	float DPS;
	
	virtual void DamageActor(AActor* OtherActor, float DamageAmount);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(BlueprintReadWrite, Category = "Spike")
	AActor* OverlappedActor;
	
	UFUNCTION()
	void OnOverlap(
		UPrimitiveComponent* OverlappedComponent,
		AActor* OtherActor,
		UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex,
		bool bFromSweep,
		const FHitResult& SweepResult
	);

	UPROPERTY(EditAnywhere, Category = "Spike")
	bool Active;
	
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
