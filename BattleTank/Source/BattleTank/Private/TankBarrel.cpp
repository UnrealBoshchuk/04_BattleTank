// Fill out your copyright notice in the Description page of Project Settings.

#include "TankBarrel.h"
#include "Engine/World.h"

void UTankBarrel::Elevate(float DegreesPerSecond)
{
	// Move the barrel the right amount this frame

	// Geven a max elevation speed. and the frame time
	/*auto Time = GetWorld()->GetTimeSeconds();
	UE_LOG(
			LogTemp,
			Warning,
			TEXT("%f: Elevate for %f"),
			Time,
			DegreesPerSecond
	);*/
}

