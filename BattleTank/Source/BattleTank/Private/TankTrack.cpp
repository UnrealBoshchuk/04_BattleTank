// Battle Ground Test Project From Udemy. Student - Victor Boschuk

#include "TankTrack.h"


void UTankTrack::SetThrottle(float Throttle)
{
	auto Name = GetName();
	UE_LOG(LogTemp, Warning, TEXT("%s throttle: %f"),*Name, Throttle);

	// TODO cla,p actual throttle so player can't ovver drive

	
}

