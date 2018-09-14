// Battle Ground Test Project From Udemy. Student - Victor Boschuk

#include "SprungWheel.h"
#include "PhysicsEngine/PhysicsConstraintComponent.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
ASprungWheel::ASprungWheel()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	MassWheelConstraint = CreateDefaultSubobject<UPhysicsConstraintComponent>(FName("MassWheelConstraint"));
	SetRootComponent(MassWheelConstraint);

	Mass = CreateDefaultSubobject<UStaticMeshComponent>(FName("Mass"));
	Mass->SetupAttachment(MassWheelConstraint);

	Wheel = CreateDefaultSubobject<UStaticMeshComponent>(FName("Wheel"));
	Wheel->SetupAttachment(MassWheelConstraint);

	MassWheelConstraint->ComponentName1.ComponentName = FName("Mass");
	MassWheelConstraint->ComponentName2.ComponentName = FName("Wheel");

    MassWheelConstraint->SetLinearXLimit(ELinearConstraintMotion::LCM_Locked, 0.f);
    MassWheelConstraint->SetLinearYLimit(ELinearConstraintMotion::LCM_Locked, 0.f);
    MassWheelConstraint->SetLinearZLimit(ELinearConstraintMotion::LCM_Free, 0.f);
     
    MassWheelConstraint->SetAngularSwing1Limit(EAngularConstraintMotion::ACM_Locked, 0.f);
    MassWheelConstraint->SetAngularSwing2Limit(EAngularConstraintMotion::ACM_Locked, 0.f);
    MassWheelConstraint->SetAngularTwistLimit(EAngularConstraintMotion::ACM_Locked, 0.f);
     
    MassWheelConstraint->SetLinearPositionDrive(false, false, true);
    //SpringComp->SetLinearPositionTarget(FVector(0.f, 0.f, 0.f));
    MassWheelConstraint->SetLinearVelocityDrive(false, false, true);
    MassWheelConstraint->SetLinearDriveParams(5000.f, 2000.f, 0.f);
}

// Called when the game starts or when spawned
void ASprungWheel::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASprungWheel::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

