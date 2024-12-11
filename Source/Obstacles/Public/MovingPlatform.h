// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/BillboardComponent.h"
#include "BasePlatform.h"
#include "MovingPlatform.generated.h"

UCLASS()
class OBSTACLES_API AMovingPlatform : public ABasePlatform
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMovingPlatform();

	UPROPERTY(VisibleAnywhere, Category = "MovingPlatform")
	FVector InitialLocation;

	UPROPERTY(VisibleAnywhere, Category = "MovingPlatform")
	FVector TargetLocation;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MovingPlatform", meta = (ClampMin = "0.1", ClampMax = "10"))
	float speed = 1.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MovingPlatform")
	bool targetAttached = true;
	
	UPROPERTY(EditAnywhere, Category = "Components")
	TObjectPtr<UBillboardComponent> TargetBillboard;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	#if WITH_EDITOR
	virtual void PostEditChangeProperty(struct FPropertyChangedEvent& PropertyChangedEvent) override;
	#endif

	UPROPERTY(BlueprintReadOnly, Category = "MovingPlatform")
	FVector MovementVector;

	virtual void MovePlatform();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
