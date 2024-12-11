// Fill out your copyright notice in the Description page of Project Settings.


#include "CrushingPlatform.h"

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
	FVector StartLocation = GetActorLocation(); 
	FVector EndLocation = StartLocation + (NormalImpulse.GetSafeNormal() * 100.f);
	
	TArray<UPrimitiveComponent*> IgnoredComponents;
	OtherActor->GetComponents(IgnoredComponents);
	
	UActorComponent* CapsuleCollider = OtherActor->GetComponentByClass(UCapsuleComponent::StaticClass());

	if (!IsValid(CapsuleCollider))
	{
		return;
	}
	
	TArray<FHitResult> HitResults;
	FCollisionQueryParams QueryParams;
	QueryParams.AddIgnoredActor(OtherActor); // Ignore the character itself during the trace

	bool bHitSomething = GetWorld()->SweepMultiByChannel(
		HitResults,
		StartLocation,
		EndLocation,
		FQuat::Identity, 
		ECC_Visibility,
		FCollisionShape::MakeSphere(10.f),
		QueryParams
	);

	if (!bHitSomething)
	{
		return;
	}

	HitResults.Sort([](const FHitResult& A, const FHitResult& B)
	{
		return A.Distance < B.Distance;
	});

	// Sort the hit results based on distance along the trace path
	TArray<FHitResult> CapsuleHits = HitResults.FilterByPredicate([&](const FHitResult& hit)
	{
		return hit.Component == CapsuleCollider;
	});

	if (CapsuleHits.Num() == 0)
	{
		return;
	}

	// Calculate the distance between the character's collider and the wall
	// FVector EntryPoint = HitResults[0].ImpactPoint;
	FVector ExitPoint = CapsuleHits[CapsuleHits.Num() - 1].ImpactPoint;
	
	HitResults.FilterByPredicate([&](const FHitResult& hit)
	{
		return IgnoredComponents.Contains(hit.Component);
	});
	
	

	// Check if the distance is smaller than the threshold (10 units)
}


// Called every frame
void ACrushingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

