// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "WeightPlayerController.generated.h"

class UInputMappingContext;

/**
 *
 */
UCLASS()
class WEIGHT_API AWeightPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	AWeightPlayerController();
	
protected:

	/** Input Mapping Context to be used for player input */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
	UInputMappingContext* InputMappingContext;

	// Begin Actor interface
	virtual void BeginPlay() override;
	// End Actor interface
private:
	FTimerHandle ViewTargetTransitionHandler;

	UFUNCTION()
	void OnViewTargetTransitionFinished(APawn* PossessPawn);

	UPROPERTY()
	FRotator StoredOriginalControllerRotation;
	

public:
	UFUNCTION()
	bool PossessRequest(APawn* Sender);

	UFUNCTION()
	void BeginOverlapAPeephole(APawn* APeephole);

	UFUNCTION()
	void EndOverlapAPeephole(APawn* APeephole);

	UPROPERTY(BluePrintReadOnly)
	APawn* ClosestPossessablePeephole;

	UPROPERTY(BluePrintReadOnly)
	APawn* OriginalPossessedPawn;

	UPROPERTY(EditAnywhere, BluePrintReadWrite)
	double BlendPossessTime;
};
