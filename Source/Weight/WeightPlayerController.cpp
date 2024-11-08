// Copyright Epic Games, Inc. All Rights Reserved.


#include "WeightPlayerController.h"

#include "APeephole.h"
#include "EnhancedInputSubsystems.h"
#include "Engine/LocalPlayer.h"

class APeephole;

AWeightPlayerController::AWeightPlayerController()
{
	// Initialise variables.
	InputMappingContext = nullptr;
	ClosestPossessablePeephole = nullptr;
	BlendPossessTime = 1.0;
	StoredOriginalControllerRotation = FRotator(0.0);
}

void AWeightPlayerController::BeginPlay()
{
	Super::BeginPlay();
	
	// get the enhanced input subsystem
	if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
	{
		// add the mapping context so we get controls
		Subsystem->AddMappingContext(InputMappingContext, 0);
	}
	
}

bool AWeightPlayerController::PossessRequest(APawn* Sender)
{
	// Possessing a peephole.
	if (GetPawn()->IsA<APeephole>() && !GetWorldTimerManager().IsTimerActive(ViewTargetTransitionHandler) && OriginalPossessedPawn)
	{
		// Hide mouse cursor.
		SetShowMouseCursor(false);
		
		SetViewTargetWithBlend(OriginalPossessedPawn, BlendPossessTime);
		
		FTimerDelegate TimerDelegate;
		TimerDelegate.BindUFunction(this, FName("OnViewTargetTransitionFinished"), OriginalPossessedPawn);
		GetWorldTimerManager().SetTimer(ViewTargetTransitionHandler, TimerDelegate, BlendPossessTime, false);
					
		OriginalPossessedPawn = nullptr;

		return true;
	}

	//Possessing the main character pawn.
	if (ClosestPossessablePeephole && !GetWorldTimerManager().IsTimerActive(ViewTargetTransitionHandler) && GetPawn() != ClosestPossessablePeephole)
	{
		// Currently possessing Main Character Pawn.
		StoredOriginalControllerRotation = GetControlRotation();
		SetViewTargetWithBlend(ClosestPossessablePeephole, BlendPossessTime);
		
		FTimerDelegate TimerDelegate;
		TimerDelegate.BindUFunction(this, FName("OnViewTargetTransitionFinished"), ClosestPossessablePeephole);
		GetWorldTimerManager().SetTimer(ViewTargetTransitionHandler, TimerDelegate, BlendPossessTime, false);
		
		OriginalPossessedPawn = GetPawn();

		//Ignore move input and look input.
		SetIgnoreMoveInput(true);
		SetIgnoreLookInput(true);
		
		return true;
	}
	
	
	return false;
}

void AWeightPlayerController::OnViewTargetTransitionFinished(APawn* PossessPawn)
{
	GetWorldTimerManager().ClearTimer(ViewTargetTransitionHandler);
	Possess(PossessPawn);

	// If we are returning to our original character, restore the rotation, input.
	if (!OriginalPossessedPawn)
	{
		SetControlRotation(StoredOriginalControllerRotation);
		SetIgnoreMoveInput(false);
		SetIgnoreLookInput(false);
	}
	// If we are possessing a peephole, show mouse cursor.
	else
	{
		SetShowMouseCursor(true);

		// Center mouse in the middle of the screen.
		int32 ViewportSizeX;
		int32 ViewportSizeY;
		GetViewportSize(ViewportSizeX, ViewportSizeY);
		SetMouseLocation(ViewportSizeX * 0.5, ViewportSizeY * 0.5);
	}

	UE_LOG(LogTemp, Warning, TEXT("Timer elapsed! Possess target: %s"), *PossessPawn->GetName())
}

void AWeightPlayerController::BeginOverlapAPeephole(APawn* APawn)
{
	if (APeephole* Peephole = Cast<APeephole>(APawn))
	{
		ClosestPossessablePeephole = Peephole;
		UE_LOG(LogTemp, Warning, TEXT("On AActor Begin Overlap! We overlapped with Actor: %s"), *APawn->GetName())
	}
}

void AWeightPlayerController::EndOverlapAPeephole(APawn* APawn)
{
	if (APeephole* Peephole = Cast<APeephole>(APawn); Peephole == ClosestPossessablePeephole)
	{
		ClosestPossessablePeephole = nullptr;
		UE_LOG(LogTemp, Warning, TEXT("On Peephole End Overlap! We left APeephole: %s"), *APawn->GetName())
	}
}
