// Fill out your copyright notice in the Description page of Project Settings.


#include "CrushingPlatform.h"

#include "MyPawnController.h"
#include "Components/CapsuleComponent.h"

// Sets default values
ACrushingPlatform::ACrushingPlatform()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void ACrushingPlatform::BeginPlay()
{
	Super::BeginPlay();
	PlatformMesh->OnComponentHit.AddDynamic(this, &ACrushingPlatform::OnHit);
}

void ACrushingPlatform::OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	if (OtherActor->StaticClass() != AMyPawnController::StaticClass()) return;
	
	AMyPawnController* MyPawnController = Cast<AMyPawnController>(OtherActor);
	if (!MyPawnController) return;

	MyPawnController->LifeHandler->Damage(1000);
}


// Called every frame
void ACrushingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

