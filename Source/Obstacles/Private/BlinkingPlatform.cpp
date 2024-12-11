// Fill out your copyright notice in the Description page of Project Settings.


#include "BlinkingPlatform.h"

// Sets default values
ABlinkingPlatform::ABlinkingPlatform()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ABlinkingPlatform::BeginPlay()
{
	Super::BeginPlay();
	
}

void ABlinkingPlatform::SwitchVisibility()
{
	SetActorHiddenInGame(visible);
	visible = !visible;
}


// Called every frame
void ABlinkingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	timer += DeltaTime;

	float timerThreshold = visible ? secondsOn : secondsOff;
	
	if (timer > timerThreshold)
	{
		SwitchVisibility();
		timer = 0.f;
	}
	
}

