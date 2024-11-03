// Copyright Epic Games, Inc. All Rights Reserved.

#include "WeightGameMode.h"
#include "WeightCharacter.h"
#include "UObject/ConstructorHelpers.h"

AWeightGameMode::AWeightGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPerson/Blueprints/BP_FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	UE_LOG(LogTemp, Warning, TEXT("Hello World! Welcome to Weight!"));

}
