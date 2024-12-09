// Copyright Epic Games, Inc. All Rights Reserved.

#include "LezioneObstaclesGameMode.h"
#include "LezioneObstaclesCharacter.h"
#include "UObject/ConstructorHelpers.h"

ALezioneObstaclesGameMode::ALezioneObstaclesGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
