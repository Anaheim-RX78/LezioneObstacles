// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/ArrowComponent.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CppExampleClass.generated.h"

UCLASS()
class LEZIONEOBSTACLES_API ACppExampleClass : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACppExampleClass();
	
	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* meshComponent;	

	UPROPERTY(EditAnywhere)
	FVector FirstLocation;

	UPROPERTY(EditAnywhere)
	FVector LastLocation;

	UPROPERTY(VisibleAnywhere)
	bool isLast;

	UPROPERTY(EditAnywhere)
	float range;

	UPROPERTY(EditAnywhere)
	float speed;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
