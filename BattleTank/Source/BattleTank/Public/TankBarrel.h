// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankBarrel.generated.h"


/**
 * 
 */
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLETANK_API UTankBarrel : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:
	// - 1 is max downard speed, and +1 is max up movment
	void Elevate(float RelativeSpeed);

private: 
	UPROPERTY(EditAnywhere, Category= Setup )
	float MaxDegreesPerSecond = 10;

	UPROPERTY(EditAnywhere, Category= Setup )
	float MaxElevationInDegrees = 10;
	
	UPROPERTY(EditAnywhere, Category= Setup )
	float MinElevationInDegrees = -3;
};
