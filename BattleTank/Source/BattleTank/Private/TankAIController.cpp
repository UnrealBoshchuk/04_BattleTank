// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "Engine/World.h"
#include "Tank.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	if (!ensure(Cast<ATank>(GetPawn()))) { return; }

	//auto PlayerTank = GetPlayerTank();

	auto PlayerTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
	auto ControlledTank =  Cast<ATank>(GetPawn());

	if (ensure((PlayerTank)))
	{
		MoveToActor(PlayerTank, AcceptanceRadius); // todo check radios is in cm

		ControlledTank->AimAt(PlayerTank->GetActorLocation());
		ControlledTank->Fire(); // TODO need limit firing rate
	}
}