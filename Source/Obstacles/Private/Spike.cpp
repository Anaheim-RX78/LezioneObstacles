// Fill out your copyright notice in the Description page of Project Settings.


#include "Spike.h"


// Sets default values
ASpike::ASpike(): ImpactDamage(3), DPS(1)
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CapsuleComponent = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Capsule"));
	RootComponent = CapsuleComponent;

	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	MeshComponent->SetupAttachment(RootComponent);
	
	CapsuleComponent->OnComponentBeginOverlap.AddDynamic(this, &ASpike::OnOverlap);

}

void ASpike::DamageActor(AActor* OtherActor, float DamageAmount)
{
	// AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA
}


void ASpike::OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
		if (Active) return;
		
		Active = true;
		// GetWorldTimerManager().SetTimer(this, &ASpike::DamageActor, 1.f, true);
}


// Called when the game starts or when spawned
void ASpike::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ASpike::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

