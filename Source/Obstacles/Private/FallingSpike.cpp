
#include "FallingSpike.h"

#include "GameFramework/Character.h"

AFallingSpike::AFallingSpike()
{
	PrimaryActorTick.bCanEverTick = true;
	SensorCollider = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Sensor"));
	SensorCollider->InitCapsuleSize(42.0f, 96.0f);
	SensorCollider->SetRelativeScale3D(FVector(1.f, 1.f, 5.f));
	SensorCollider->SetRelativeLocation(FVector(0.f,0.f,400.f));
	SensorCollider->SetupAttachment(RootComponent);
}

void AFallingSpike::BeginPlay()
{
	Super::BeginPlay();
	InitialLocation = GetActorLocation();

	SensorCollider->OnComponentBeginOverlap.AddDynamic(this, &AFallingSpike::OnOverlapSensor);
}

void AFallingSpike::OnOverlapSensor(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (ACharacter* Character = Cast<ACharacter>(OtherActor))
	{
		shouldTremble = true;
	}
}


void AFallingSpike::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (attackTimer > 5.f)
	{
		shouldTremble = false;
		shouldMove = false;
		attackTimer = 0.f;
		trembleTimer = 0.f;
		SetActorLocation(InitialLocation);
	}
	
	if (shouldTremble)
	{
		FVector RandomOffset = FMath::VRand() * trembleMultiplier;
		SetActorRelativeLocation(InitialLocation + FVector(RandomOffset.X, RandomOffset.Y, 0.f));

		trembleTimer += DeltaTime;
		if (trembleTimer >= trembleTimeSeconds)
		{
			shouldTremble = false;
			shouldMove = true;
		}
	}
	else if (shouldMove)
	{
		FVector CurrentLocation = GetActorLocation();
		FVector UpDirection = GetActorUpVector();
		SetActorLocation(CurrentLocation + (UpDirection * moveSpeed * DeltaTime));
		attackTimer+= DeltaTime;
	}
}
