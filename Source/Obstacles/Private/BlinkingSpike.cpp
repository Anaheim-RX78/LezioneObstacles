// Fill out your copyright notice in the Description page of Project Settings.


#include "BlinkingSpike.h"

// Sets default values
ABlinkingSpike::ABlinkingSpike()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ABlinkingSpike::BeginPlay()
{
	Super::BeginPlay();
	SetActorHiddenInGame(true);
}

void ABlinkingSpike::SwitchVisibility()
{
	SetActorHiddenInGame(visible);
	
	SetActorEnableCollision(!visible);
	visible = !visible;
}

// Called every frame
void ABlinkingSpike::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	
	if (initialDelayTimer <= initialDelay)
	{
		initialDelayTimer += DeltaTime;
		return;
	}
	
	timer += DeltaTime;

	float timerThreshold = visible ? secondsOn : secondsOff;
	
	if (timer > timerThreshold)
	{
		SwitchVisibility();
		timer = 0.f;
	}
}

