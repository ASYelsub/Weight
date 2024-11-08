// Fill out your copyright notice in the Description page of Project Settings.


#include "APeephole.h"

#include "EnhancedInputComponent.h"
#include "WeightPlayerController.h"
#include "Components/SphereComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"

// Sets default values
APeephole::APeephole()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	
	// Create StaticMeshComponent and assign it as the root.
	StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(FName(TEXT("StaticMeshComponent")));
	SetRootComponent(StaticMeshComponent);
	
	// Create CollisionSphereComponent so the player can detect whether they can possess the pawn or not.
	CollisionSphereComponent = CreateDefaultSubobject<USphereComponent>(FName(TEXT("CollisionSphereComponent")));
	CollisionSphereComponent->SetupAttachment(GetRootComponent());
	
	// Create CameraComponent so the player can see when they possess.
	CameraComponent = CreateDefaultSubobject<UCameraComponent>(FName(TEXT("CameraComponent")));
	CameraComponent->SetupAttachment(GetRootComponent());
}

// Called when the game starts or when spawned
void APeephole::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void APeephole::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void APeephole::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{	
	// Set up action bindings
	if (UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(PlayerInputComponent))
	{
		// Interacting
		EnhancedInputComponent->BindAction(InteractAction, ETriggerEvent::Triggered, this, &APeephole::Interact);
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Failed to find an Enhanced Input Component!"))
	}
}

void APeephole::Interact(const FInputActionValue& Value)
{
	bool Pressed = Value.Get<bool>();
	if (AWeightPlayerController* PC = Cast<AWeightPlayerController>(Controller); PC && Pressed)
	{
		PC -> PossessRequest(this);
	}
}

