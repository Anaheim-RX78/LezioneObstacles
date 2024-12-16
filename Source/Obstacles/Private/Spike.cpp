// Fill out your copyright notice in the Description page of Project Settings.


#include "Spike.h"

#include "MyPawnController.h"


// Sets default values
ASpike::ASpike()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;


	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	RootComponent = MeshComponent;
	
	CapsuleComponent = CreateDefaultSubobject<UCapsuleComponent>("Capsule");
	MeshComponent->SetupAttachment(CapsuleComponent);
}

FString ASpike::GetIdentifier()
{
	return identifier;
}


void ASpike::OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor->StaticClass() != AMyPawnController::StaticClass()) return;
	
	AMyPawnController* MyPawnController = Cast<AMyPawnController>(OtherActor);
	if (!MyPawnController) return;

	MyPawnController->LifeHandler->DamageAndTurnOnContinuousDamage(5.f, 1.f, 1.f, GetIdentifier());
}

void ASpike::OnOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	if (OtherActor->StaticClass() != AMyPawnController::StaticClass()) return;
	
	AMyPawnController* MyPawnController = Cast<AMyPawnController>(OtherActor);
	if (!MyPawnController) return;

	MyPawnController->LifeHandler->TurnOffContinuousDamage(GetIdentifier());
}


void ASpike::BeginPlay()
{
	Super::BeginPlay();
	CapsuleComponent->OnComponentBeginOverlap.AddDynamic(this, &ASpike::OnOverlap);
	CapsuleComponent->OnComponentEndOverlap.AddDynamic(this, &ASpike::OnOverlapEnd);
}


// Called every frame
void ASpike::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

