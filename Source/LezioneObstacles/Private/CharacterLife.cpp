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
		Damage(damagePerInterval);
	}
}

void ACharacterLife::Damage(float damage)
{	
	lifeValue -= damage;
}

void ACharacterLife::TurnOnContinuousDamage(float damage, float damageInterval)
{
	damagePerInterval = damage;
	secondsInterval = damageInterval;
	continuousDamageOn = true;
}

void ACharacterLife::TurnOffContinuousDamage()
{
	damagePerInterval = 0;
	continuousDamageOn = false;
	secondsInterval = 0;
	timer = 0;
}

void ACharacterLife::Die()
{
	// die
}
