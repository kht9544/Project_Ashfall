// Copyright Epic Games, Inc. All Rights Reserved.

#include "AshfallGameMode.h"
#include "AshfallCharacter.h"
#include "UObject/ConstructorHelpers.h"

AAshfallGameMode::AAshfallGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
