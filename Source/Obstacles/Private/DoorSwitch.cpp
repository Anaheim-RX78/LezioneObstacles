// Fill out your copyright notice in the Description page of Project Settings.


#include "DoorSwitch.h"

#include "GameFramework/Character.h"

// Sets default values
ADoorSwitch::ADoorSwitch()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	DoorMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	RootComponent = DoorMesh;

	static ConstructorHelpers::FObjectFinder<UStaticMesh> CubeMeshAsset(TEXT("/Engine/BasicShapes/Cube.Cube"));
	if (CubeMeshAsset.Succeeded())
	{
		DoorMesh->SetStaticMesh(CubeMeshAsset.Object);
		DoorMesh->SetRelativeScale3D(FVector(1.f, 5.f, 5.f));
	}

	TeleporterMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("TeleporterMesh"));
	TeleporterMesh->SetupAttachment(DoorMesh);

	BoxComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("TeleporterCollider"));
	BoxComponent->InitBoxExtent(FVector(200.0f, 200.0f, 200.0f));
	BoxComponent->SetupAttachment(DoorMesh);
}

// Called when the game starts or when spawned
void ADoorSwitch::BeginPlay()
{
	Super::BeginPlay();
	BoxComponent->OnComponentBeginOverlap.AddDynamic(this, &ADoorSwitch::OnOverlapSensor);
}

void ADoorSwitch::OnOverlapSensor(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (ACharacter* Character = Cast<ACharacter>(OtherActor))
	{
		OtherActor->SetActorLocation(TeleportLocation);
		mustOpen = true;
	}
}

// Called every frame
void ADoorSwitch::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (hasOpened || !mustOpen) return;

	if (openTimer >= openSeconds)
	{
		hasOpened = true;
		return;
	}
	
	openTimer += DeltaTime;

	SetActorLocation(GetActorLocation() + FVector(0.f,0.f, 10.f * DeltaTime * openSpeed));
}

