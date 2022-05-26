// Fill out your copyright notice in the Description page of Project Settings.


#include "PFCharMovement.h"
#include "Components/CapsuleComponent.h"
#include "Kismet/KismetSystemLibrary.h"

// Sets default values for this component's properties
UPFCharMovement::UPFCharMovement()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	//PrimaryComponentTick.bCanEverTick = true;

	// ...
}

void UPFCharMovement::BeginPlay()
{
	AActor* owner = GetOwner();

	//Shape = Cast<UPrimitiveComponent>(owner->GetComponentByClass(UPrimitiveComponent::StaticClass())); //One obtuse motherfucker of a getcomponent.
	Shape = owner->FindComponentByClass<UCapsuleComponent>();

}


void UPFCharMovement::Move(FVector inputVector, float acceleration, float maxSpeed)
{
	AActor* owner = GetOwner();

	FVector accel2Add = inputVector * acceleration;

	FVector groundVel = owner->GetVelocity();
	groundVel.Z = 0;
	float accelGroundDot = (FVector::DotProduct(accel2Add, groundVel.GetSafeNormal()));
	if (accelGroundDot <= 0)
	{
		accelGroundDot = 0;
	}

	FVector contOnVelo = accelGroundDot * groundVel.GetSafeNormal();

	if (groundVel.Size() > maxSpeed)
	{
		accel2Add = accel2Add - contOnVelo;
	}

	Shape->AddForce(accel2Add, NAME_None, true);

}

void UPFCharMovement::ApplyFriction(float frictionAmount)
{
	FVector frictionVector = GetOwner()->GetVelocity();
	frictionVector.Z = 0;
	frictionVector = frictionVector * frictionAmount;
	
	Shape->AddForce(frictionVector * -1);

}

void UPFCharMovement::Hover(float hoverRay, float hoverDistance, float hoverStrength, float hoverDamping)
{
	if (disabledFloatTimer > 0)
	{
		return;
	}
	AActor* owner = GetOwner();
	FHitResult hit;

	FVector rayDown = owner->GetActorLocation() - FVector(0, 0, hoverRay);

	FCollisionQueryParams CollisionParams;
	TArray<TEnumAsByte<EObjectTypeQuery>> ObjectTypesArray;
	TArray<AActor*> IgnoredActors;
	ObjectTypesArray.Add(UEngineTypes::ConvertToObjectType(ECollisionChannel::ECC_GameTraceChannel1));

	//if (GetWorld()->LineTraceSingleByChannel(hit, Shape->GetComponentLocation(), rayDown, ECC_WorldStatic, CollisionParams))

	if (UKismetSystemLibrary::SphereTraceSingleForObjects(GetWorld(), Shape->GetComponentLocation(), rayDown, FloatRayWidth, ObjectTypesArray, true, IgnoredActors, EDrawDebugTrace::ForOneFrame, hit, true))
	{
		FVector vel = Shape->GetComponentVelocity();


		float rayDirVel = FVector::DotProduct(FVector(0, 0, -1), vel);
		float otherDirVel = FVector::DotProduct(FVector(0, 0, -1), FVector(0, 0, 0));

		float x = hit.Distance - hoverDistance;
		float springForce = (x * hoverStrength) - (Shape->GetComponentVelocity().Z * hoverDamping);

		Shape->AddForce(FVector::DownVector * springForce, NAME_None, true);
	}
	else
	{

	}


}

void UPFCharMovement::Glide()
{
	
}

bool UPFCharMovement::GroundCheck(float hoverRay)
{
	return false;
}



void UPFCharMovement::Jump(float jumpForce)
{
	
	BrieflyDisableFloat();
	FVector jumpVector = FVector::UpVector * jumpForce;
	jumpVector.X = GetOwner()->GetVelocity().X;
	jumpVector.Y = GetOwner()->GetVelocity().Y;
	if (GetOwner()->GetVelocity().Z < 0.1)
	{
		Shape->SetPhysicsLinearVelocity(jumpVector);
	}
	else
	{
		jumpVector.Z += (GetOwner()->GetVelocity().Z) * 0.65f; //Inherits a portion of your upwards velocty if youre moving up
		Shape->SetPhysicsLinearVelocity(jumpVector);
	}
	
}

void UPFCharMovement::BrieflyDisableFloat()
{
	disabledFloatTimer = 0.5f;
}

