// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAimingComponent.h"
#include "BattleTank.h"
#include "TankBarrel.h"
#include "TankTurret.h"
#include "Engine/World.h"
#include "Kismet/GameplayStatics.h"
// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	//bWantsBeginPlay = true;
	PrimaryComponentTick.bCanEverTick = false;
}


void UTankAimingComponent::SetBarrelReference(UTankBarrel* BarrelToSet)
{
	if (!BarrelToSet) {return;}
	Barrel = BarrelToSet;
}

void UTankAimingComponent::SetTurretReference(UTankTurret* TurretToSet)
{
	if (!TurretToSet) {return;}
	Turret = TurretToSet;
}

void UTankAimingComponent::AimAt(FVector HitLocation, float LaunchSpeed)
{
	if (!Barrel) { return; }

	FVector OutLaunchVelocity;
	FVector StartLocation = Barrel->GetSocketLocation(FName("Projectile"));
	bool bHaveAimSolution = UGameplayStatics::SuggestProjectileVelocity
	(
		this,
		OutLaunchVelocity,
		StartLocation,
		HitLocation,
		LaunchSpeed,
		false,
		0,
		0,
		ESuggestProjVelocityTraceOption::DoNotTrace
	);
	if (bHaveAimSolution)
	{
		auto AimDirection = OutLaunchVelocity.GetSafeNormal();
		
		MoveBarrelTowards(AimDirection);
	/*	auto Time = GetWorld()->GetTimeSeconds();
		UE_LOG(
			LogTemp,
			Warning,
			TEXT("%f: aim solution found..."),
			Time
		);*/
	}
	else
	{
		auto Time = GetWorld()->GetTimeSeconds();
	/*	UE_LOG(
			LogTemp,
			Warning,
			TEXT("%f: No aim solve found..."),
			Time
		);*/
	}
	// If no solution found do nothing
}

void UTankAimingComponent::MoveBarrelTowards(FVector AimDirection)
{
	// Work-out difference between current barrel roation, and AimDirection
	auto BarrelRotator = Barrel->GetForwardVector().Rotation();
	auto AimAsRotator = AimDirection.Rotation();
	auto DeltaRotator = AimAsRotator - BarrelRotator;

	Turret->Rotate(DeltaRotator.Yaw);
	Barrel->Elevate(DeltaRotator.Pitch);
	
}

//void UTankAimingComponent::MoveTurretTowards(FVector AimDirection)
//{
//	auto TurretRotator = Barrel->GetForwardVector().Rotation();
//	auto AimAsRotator = AimDirection.Rotation();
//	auto DeltaRotator = AimAsRotator - TurretRotator;
//
//	Turret->Rotate(DeltaRotator.Yaw);
//	MoveBarrelTowards(AimDirection);
//	
//}

