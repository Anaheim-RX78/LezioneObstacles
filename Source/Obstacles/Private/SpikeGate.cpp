// Fill out your copyright notice in the Description page of Project Settings.


#include "SpikeGate.h"

#include "Spike.h"
#include "Components/BoxComponent.h"
#include "GameFramework/Character.h"

// Sets default values
ASpikeGate::ASpikeGate()
{
	PrimaryActorTick.bCanEverTick = true;

	BoxComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxComponent"));
	BoxComponent->InitBoxExtent(FVector(200.0f, 200.0f, 200.0f));
	RootComponent = BoxComponent;
}

// Called when the game starts or when spawned
void ASpikeGate::BeginPlay()
{
	Super::BeginPlay();
	for (ASpike* Spike : Spikes)
	{
		Spike->SetActorHiddenInGame(true);
		Spike->SetActorEnableCollision(false);
	}

	BoxComponent->OnComponentBeginOverlap.AddDynamic(this, &ASpikeGate::OnOverlapSensor);
}

void ASpikeGate::OnOverlapSensor(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (ACharacter* Character = Cast<ACharacter>(OtherActor))
	{
		for (ASpike* Spike : Spikes)
		{
			Spike->SetActorHiddenInGame(false);
			Spike->SetActorEnableCollision(true);
		}
	}
	spikeGateOn = true;
}

// Called every frame
void ASpikeGate::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	spikeGateOnTimer += DeltaTime;
	if (spikeGateOnTimer > spikeGateTimeOn)
	{
		for (ASpike* Spike : Spikes)
		{
			Spike->SetActorHiddenInGame(true);
			Spike->SetActorEnableCollision(false);
		}
		spikeGateOnTimer = 0.f;
		spikeGateOn = false;
	}

}

