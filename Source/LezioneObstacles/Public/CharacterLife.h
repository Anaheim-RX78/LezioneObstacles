// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CharacterLife.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FUpdateLifeEvent);

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
	float continuousDamageInterval;

	UPROPERTY(EditAnywhere)
	bool continuousDamageOn = false;

	UPROPERTY(EditAnywhere)
	float damagePerInterval;

	UPROPERTY(EditAnywhere)
	TArray<FString> damagingEntities;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	virtual void Damage(float impactDamage);
	virtual void DamageAndTurnOnContinuousDamage(float impactDamage, float continuousDamage, float damageInterval, FString damageEntity);
	virtual void TurnOnContinuousDamage(float continuousDamage, float damageInterval, FString entity);
	virtual void TurnOffContinuousDamage(FString entity);
	virtual void Die();
	
	UPROPERTY(BlueprintAssignable, Category = "Events")
	FUpdateLifeEvent OnLifeUpdate;
};
