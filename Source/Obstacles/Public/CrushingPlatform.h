// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MovingPlatform.h"
#include "CrushingPlatform.generated.h"

UCLASS()
class OBSTACLES_API ACrushingPlatform : public AMovingPlatform
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACrushingPlatform();

	UPROPERTY(EditAnywhere)
	float damage;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UFUNCTION()
	void OnHit (
		UPrimitiveComponent* HitComponent,
		AActor* OtherActor,
		UPrimitiveComponent* OtherComp,
		FVector NormalImpulse,
		const FHitResult& Hit
	);

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
