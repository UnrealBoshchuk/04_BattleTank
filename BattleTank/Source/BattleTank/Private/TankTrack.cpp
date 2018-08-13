// Battle Ground Test Project From Udemy. Student - Victor Boschuk

#include "TankTrack.h"

UTankTrack::UTankTrack()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UTankTrack::TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction)
{
	//Super::TickComponent();
	UE_LOG(LogTemp, Warning, TEXT("Track ticking"));

	// Calculate the slippage speed
	auto SlippageSpeed = FVector::DotProduct(GetRightVector(), GetComponentVelocity());

	// Work-out the requreid acceleration thus frame to correct
	auto CorrectionAcceleration = -SlippageSpeed / DeltaTime * GetRightVector();

	// Calculate and apply sideways ( F = m a)
	auto TankRoot = Cast<UStaticMeshComponent>(GetOwner()->GetRootComponent());
	auto CorrectionForce = (TankRoot->GetMass() * CorrectionAcceleration) / 2; // Two tracks
	
	TankRoot->AddForce(CorrectionForce);

}

void UTankTrack::SetThrottle(float Throttle)
{
	// TODO clamp actual throttle so player can't over drive
	auto ForceApplied = GetForwardVector() * Throttle * TrackMaxDrivingForce;

	auto ForceLocation = GetComponentLocation();
	
	auto TankRoot = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());
	TankRoot->AddForceAtLocation(ForceApplied, ForceLocation);
}

