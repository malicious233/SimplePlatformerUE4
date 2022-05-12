// Fill out your copyright notice in the Description page of Project Settings.


#include "PFCharFloater.h"
#include "Components/CapsuleComponent.h"


// Sets default values for this component's properties
UPFCharFloater::UPFCharFloater()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	
	

	// ...
}

void UPFCharFloater::TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	disabledFloatTimer -= DeltaTime;

}


void UPFCharFloater::BeginPlay()
{
	AActor* owner = GetOwner();

	//Shape = Cast<UPrimitiveComponent>(owner->GetComponentByClass(UPrimitiveComponent::StaticClass())); //One obtuse motherfucker of a getcomponent.
	Shape = owner->FindComponentByClass<UCapsuleComponent>();

	
}

bool UPFCharFloater::Hover(float hoverRay, float hoverDistance, float hoverStrength, float hoverDamping)
{
	if (disabledFloatTimer > 0)
	{
		return false;
	}
	AActor* owner = GetOwner();
	FHitResult hit;

	

	FVector rayDown = owner->GetActorLocation() - FVector(0, 0, hoverRay);

	FCollisionQueryParams CollisionParams;
	if (GetWorld()->LineTraceSingleByChannel(hit, Shape->GetComponentLocation(), rayDown, ECC_WorldStatic, CollisionParams))
	{
		FVector vel = Shape->GetComponentVelocity();


		float rayDirVel = FVector::DotProduct(FVector(0, 0, -1), vel);
		float otherDirVel = FVector::DotProduct(FVector(0, 0, -1), FVector(0, 0, 0));

		float x = hit.Distance - hoverDistance;
		float springForce = (x * hoverStrength) - (Shape->GetComponentVelocity().Z * hoverDamping);

		Shape->AddForce(FVector::DownVector * springForce, NAME_None, true);
		return true;
	}
	else
	{
		return false;
	}

	
}

void UPFCharFloater::BrieflyDisableFloat()
{
	disabledFloatTimer = 0.5f;
}

