// Fill out your copyright notice in the Description page of Project Settings.


#include "MyPawnController.h"

#include "EnhancedInputComponent.h"

// Sets default values
AMyPawnController::AMyPawnController()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AMyPawnController::BeginPlay()
{
	Super::BeginPlay();
	LifeHandlerActor = CreateDefaultSubobject<UChildActorComponent>(TEXT("ChildLifeHandler"));
	LifeHandlerActor->SetChildActorClass(ACharacterLife::StaticClass());
	LifeHandler = Cast<ACharacterLife>(LifeHandlerActor->GetChildActor());
}

// Called every frame
void AMyPawnController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AMyPawnController::MoveTo(const FInputActionValue& InputActionValue)
{
	FVector2d Movement = InputActionValue.Get<FVector2D>();
	AddMovementInput(FVector(Movement.X, Movement.Y, 0.f));
}


// Called to bind functionality to input
void AMyPawnController::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	if (UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(PlayerInputComponent))
	{
		EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Started, this, &AMyPawnController::MoveTo);
	}
}