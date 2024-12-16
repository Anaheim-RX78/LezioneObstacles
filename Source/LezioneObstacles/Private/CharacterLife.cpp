// Fill out your copyright notice in the Description page of Project Settings.


#include "CharacterLife.h"

// Sets default values
ACharacterLife::ACharacterLife()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void ACharacterLife::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ACharacterLife::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (continuousDamageOn && damagePerInterval)
	{
		timer += DeltaTime;
		if (timer >= continuousDamageInterval) Damage(damagePerInterval);
	}
}

void ACharacterLife::Damage(float impactDamage)
{
	lifeValue -= impactDamage;
	OnLifeUpdate.Broadcast();
}

void ACharacterLife::DamageAndTurnOnContinuousDamage(float impactDamage, float continuousDamage, float damageInterval, FString damageEntity)
{
	if (damagingEntities.Contains(damageEntity)) return;
	Damage(impactDamage);
	TurnOnContinuousDamage(continuousDamage, damageInterval, damageEntity);
}

void ACharacterLife::TurnOnContinuousDamage(float damage, float damageInterval, FString damageEntity)
{
	if (damagingEntities.Contains(damageEntity)) return;
	
	damagingEntities.AddUnique(damageEntity);

	damagePerInterval = damage;
	continuousDamageInterval = damageInterval;
	continuousDamageOn = true;
}

void ACharacterLife::TurnOffContinuousDamage(FString damageEntity)
{
	damagingEntities.Remove(damageEntity);
	if (damagingEntities.Num() > 0) return;
	
	damagePerInterval = 0;
	continuousDamageOn = false;
	continuousDamageInterval = 0;
	timer = 0;
}

void ACharacterLife::Die()
{
	// die
}
