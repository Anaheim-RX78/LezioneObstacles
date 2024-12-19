// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Spike.h"
#include "GameFramework/Actor.h"
#include "BlinkingSpike.generated.h"


UCLASS()
class OBSTACLES_API ABlinkingSpike : public ASpike
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABlinkingSpike();

	UPROPERTY(EditAnywhere, Category = "Blink")
	float secondsOn = 1.f;

	UPROPERTY(EditAnywhere, Category = "Blink")
	float secondsOff = 1.f;

	UPROPERTY(EditAnywhere, Category = "Blink")
	float initialDelay = 1.f;

	UPROPERTY(VisibleAnywhere, Category = "Blink")
	float initialDelayTimer = 0.f;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	virtual void SwitchVisibility();

	UPROPERTY(VisibleAnywhere, Category = "Blink")
	float timer = 0.f;

	UPROPERTY(VisibleAnywhere, Category = "Blink")
	bool visible = false;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
