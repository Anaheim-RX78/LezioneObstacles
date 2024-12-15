// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CharacterLife.generated.h"

UCLASS()
class LEZIONEOBSTACLES_API ACharacterLife : public AActor
{
	GENERATED_BODY()
	
public:
	// Sets default values for this actor's properties
	ACharacterLife();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere)
	float lifeValue = 100;

	UPROPERTY(EditAnywhere)
	float timer;

	UPROPERTY(EditAnywhere)
	float secondsInterval;

	UPROPERTY(EditAnywhere)
	bool continuousDamageOn = false;

	UPROPERTY(EditAnywhere)
	float damagePerInterval;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	virtual void Damage(float damage);
	virtual void TurnOnContinuousDamage(float damage, float damageInterval);
	virtual void TurnOffContinuousDamage();
	virtual void Die();
};
