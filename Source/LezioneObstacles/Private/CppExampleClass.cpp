// Fill out your copyright notice in the Description page of Project Settings.


#include "CppExampleClass.h"

// Sets default values
ACppExampleClass::ACppExampleClass(): range(10.f), speed(2.f)
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	meshComponent = CreateDefaultSubobject<UStaticMeshComponent>("StaticMesh");
}

// Called when the game starts or when spawned
void ACppExampleClass::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ACppExampleClass::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FVector NextLocation = FirstLocation;

	if(!isLast)
	{
		NextLocation = LastLocation;
	}

	if(FVector::Dist(GetActorLocation(), NextLocation) < range)
	{
		isLast = !isLast;
	}

	FVector CurrentLocation = FMath::Lerp(GetActorLocation(), NextLocation, DeltaTime * speed);
	SetActorLocation(CurrentLocation);
}

