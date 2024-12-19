// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CharacterLife.h"
#include "GameFramework/Pawn.h"
#include "LezioneObstacles/LezioneObstaclesCharacter.h"
#include "MyPawnController.generated.h"

UCLASS()
class LEZIONEOBSTACLES_API AMyPawnController : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AMyPawnController();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UInputMappingContext* MappingContext;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UInputAction* MoveAction;

	UPROPERTY(EditAnywhere)
	UChildActorComponent* LifeHandlerActor;

	UPROPERTY(EditAnywhere)
	ACharacterLife* LifeHandler;

	UFUNCTION()
	void MoveTo(const FInputActionValue& InputActionValue);
};
