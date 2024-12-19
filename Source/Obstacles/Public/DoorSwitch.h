// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/BoxComponent.h"
#include "GameFramework/Actor.h"
#include "DoorSwitch.generated.h"

UCLASS()
class OBSTACLES_API ADoorSwitch : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ADoorSwitch();

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
	UPROPERTY(VisibleAnywhere, Category = "Components")
	bool mustOpen;
	
	UPROPERTY(VisibleAnywhere, Category = "Components")
	bool hasOpened;

	UPROPERTY(VisibleAnywhere, Category = "Components")
	float openTimer = 0.f;
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, Category="Components")
	UStaticMeshComponent* TeleporterMesh;

	UPROPERTY(EditAnywhere, Category="Components")
	FVector TeleportLocation;
	
	UPROPERTY(EditAnywhere, Category="Components")
	UStaticMeshComponent* DoorMesh;

	UPROPERTY(EditAnywhere, Category = "Components")
	UBoxComponent* BoxComponent;


	UPROPERTY(EditAnywhere, Category = "Components")
	float openSeconds = 2.f;

	UPROPERTY(EditAnywhere, Category = "Components")
	float openSpeed = 1.f;


};
