// Fill out your copyright notice in the Description page of Project Settings.


#include "BasePlatform.h"

// Sets default values
ABasePlatform::ABasePlatform()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	PlatformMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	RootComponent = PlatformMesh;

	static ConstructorHelpers::FObjectFinder<UStaticMesh> CubeMeshAsset(TEXT("/Engine/BasicShapes/Cube.Cube"));
	if (CubeMeshAsset.Succeeded())
	{
		PlatformMesh->SetStaticMesh(CubeMeshAsset.Object);
		PlatformMesh->SetRelativeScale3D(FVector(1.f, 1.f, 0.2f));
	}
}

FString ABasePlatform::GetIdentifier()
{
	return identifier;
}


// Called when the game starts or when spawned
void ABasePlatform::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABasePlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

