// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "Engine/World.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	/*auto ControlledTank =GetControlledTank();
	if(!ControlledTank)
	{
		UE_LOG(LogTemp, Warning,TEXT( "AIController not possesing a tank"));
	}
	else
	{
		UE_LOG(LogTemp, Warning,TEXT( "AIController possessing: %s"),
			*(ControlledTank->GetName()));
	}*/

	auto PlayerTank = GetPlayerTank();
	if(!PlayerTank)
	{
		UE_LOG(LogTemp, Warning,TEXT( "AIController can't find player tank"));
	}
	else
	{
		UE_LOG(LogTemp, Warning,TEXT( "AIController found player tank: %s"),
			*(PlayerTank->GetName()));
	}
}

ATank* ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

ATank* ATankAIController::GetPlayerTank() const
{
	//return Cast<ATank>(GetPawn());

	auto PlayerTank = GetWorld()->GetFirstPlayerController()->GetPawn();

	if (!PlayerTank)
	{
		return nullptr;
	}
	else
	{
		return  Cast<ATank>(PlayerTank);
	}
}

