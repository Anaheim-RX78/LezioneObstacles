// Fill out your copyright notice in the Description page of Project Settings.


#include "Spike.h"

#include "MyPawnController.h"


// Sets default values
ASpike::ASpike()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CapsuleComponent = CreateDefaultSubobject<UCapsuleComponent>("Capsule");
	RootComponent = CapsuleComponent;

	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	MeshComponent->SetupAttachment(CapsuleComponent);
	

	static ConstructorHelpers::FObjectFinder<UStaticMesh> ConeMeshAsset(TEXT("/Engine/BasicShapes/Cone.Cone"));
	if (ConeMeshAsset.Succeeded())
	{
		MeshComponent->SetStaticMesh(ConeMeshAsset.Object);
		MeshComponent->SetRelativeScale3D(FVector(0.5f, 0.5f, 0.8f));
		MeshComponent->SetCollisionProfileName("OverlapAllDynamic");
	}
}

FString ASpike::GetIdentifier()
{
	return identifier;
}


void ASpike::OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (ACharacter* Character = Cast<ACharacter>(OtherActor))
	{
		Character->SetActorLocation(TeleportLocation);
	}
}

void ASpike::OnOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	// if (OtherActor->StaticClass() != AMyPawnController::StaticClass()) return;
	//
	// AMyPawnController* MyPawnController = Cast<AMyPawnController>(OtherActor);
	// if (!MyPawnController) return;
	//
	// MyPawnController->LifeHandler->TurnOffContinuousDamage(GetIdentifier());
}


void ASpike::BeginPlay()
{
	Super::BeginPlay();
	CapsuleComponent->OnComponentBeginOverlap.AddDynamic(this, &ASpike::OnOverlap);
}


// Called every frame
void ASpike::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

