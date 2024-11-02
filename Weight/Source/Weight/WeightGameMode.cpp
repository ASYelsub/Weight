// Copyright Epic Games, Inc. All Rights Reserved.

#include "WeightGameMode.h"
#include "WeightCharacter.h"
#include "UObject/ConstructorHelpers.h"

AWeightGameMode::AWeightGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
