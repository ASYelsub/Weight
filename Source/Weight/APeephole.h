// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "APeephole.generated.h"

class USpringArmComponent;
class AWeightCharacter;
class UInputAction;
struct FInputActionValue;
class USphereComponent;
class UCameraComponent;

UCLASS()
class WEIGHT_API APeephole : public APawn
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APeephole();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// ** Called for interact input */
	void Interact(const FInputActionValue& Value);
	
	// APawn interface
	virtual void SetupPlayerInputComponent(UInputComponent* InputComponent) override;
	// End of APawn interface

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UStaticMeshComponent* StaticMeshComponent;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	USphereComponent* CollisionSphereComponent;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UCameraComponent* CameraComponent;
	
	/** Interact Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Input")
	UInputAction* InteractAction;
};
