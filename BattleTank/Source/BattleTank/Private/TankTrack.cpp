// Battle Ground Test Project From Udemy. Student - Victor Boschuk

#include "TankTrack.h"


void UTankTrack::SetThrottle(float Throttle)
{
	// TODO clamp actual throttle so player can't over drive
	auto ForceApplied = GetForwardVector() * Throttle * TrackMaxDrivingForce;

	auto ForceLocation = GetComponentLocation();
	
	auto TankRoot = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());
	TankRoot->AddForceAtLocation(ForceApplied, ForceLocation);
}

