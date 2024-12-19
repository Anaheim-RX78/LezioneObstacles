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
	float impactDamage = 3;
	
	UPROPERTY(EditAnywhere, Category = "Spike")
	float DPS = 1;

	UPROPERTY(EditAnywhere, Category = "Spike")
	FVector TeleportLocation;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	UFUNCTION()
	void OnOverlap(
		UPrimitiveComponent* OverlappedComponent,
		AActor* OtherActor,
		UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex,
		bool bFromSweep,
		const FHitResult& SweepResult
	);

	UFUNCTION()
	void OnOverlapEnd(
		UPrimitiveComponent* OverlappedComponent,
		AActor* OtherActor,
		UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex
	);

	UPROPERTY(EditAnywhere, Category = "Spike")
	bool Active;
	
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	virtual FString GetIdentifier();
private:
	UPROPERTY()
	FString identifier = "Spike";
};
