// Fill out your copyright notice in the Description page of Project Settings.


#include "LedgeVaultComponent.h"
#include "DrawDebugHelpers.h"

// Sets default values for this component's properties
ULedgeVaultComponent::ULedgeVaultComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void ULedgeVaultComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void ULedgeVaultComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

bool ULedgeVaultComponent::CheckLedgeGrabbable(FVector CheckDirection)
{
	FVector GrabRay = GetOwner()->GetActorLocation() + (FVector(GrabOffset));
	FVector GrabRayDown = GrabRay + FVector::DownVector * RayLength;

	FHitResult hit;
	FCollisionQueryParams CollisionParams;

	bool IsAboveClear;
	bool IsLedgeClear;
	bool IsFrontClear;
	bool IsClimbOntoClear;

	FVector AboveRay = GetOwner()->GetActorLocation() + FVector::UpVector * RayLengthUp;

	//checks if it's clear above me
	IsAboveClear = GetWorld()->LineTraceSingleByChannel(hit, GetOwner()->GetActorLocation(), AboveRay, ECC_WorldStatic, CollisionParams);
	DrawDebugLine(GetWorld(), GetOwner()->GetActorLocation(), AboveRay, FColor::Green, false, 1, 1, 5.f);

	IsLedgeClear = GetWorld()->LineTraceSingleByChannel(hit, GetOwner()->GetActorLocation(), GetOwner()->GetActorLocation() + CheckDirection * RayLength, ECC_WorldStatic, CollisionParams);
	DrawDebugLine(GetWorld(), GetOwner()->GetActorLocation(), GetOwner()->GetActorLocation() + CheckDirection * RayLength, FColor::Green, false, 1, 1, 5.f);
	GrabPosition = hit.Location;
	GrabPositionNormal = hit.Normal;

	//checks if it's clear above and infront of me
	IsFrontClear = GetWorld()->LineTraceSingleByChannel(hit, AboveRay, AboveRay + CheckDirection * RayLength, ECC_WorldStatic, CollisionParams);
	DrawDebugLine(GetWorld(), AboveRay, AboveRay + CheckDirection * RayLength, FColor::Green, false, 1, 1, 5.f);
	

	//and then checks if it's clear to climb onto at said position
	IsClimbOntoClear = GetWorld()->LineTraceSingleByChannel(hit, AboveRay + CheckDirection * RayLength, AboveRay + CheckDirection * RayLength + FVector::DownVector * RayLengthDown, ECC_WorldStatic, CollisionParams);
	DrawDebugLine(GetWorld(), AboveRay + CheckDirection * RayLength, AboveRay + CheckDirection * RayLength + FVector::DownVector * RayLengthDown, FColor::Green, false, 1, 1, 5.f);

	//WIP: Need to also check if the ground is flat enough too

	if (!IsAboveClear && !IsFrontClear && IsClimbOntoClear && IsLedgeClear)
	{
		GEngine->AddOnScreenDebugMessage(
			INDEX_NONE,
			0.f,
			FColor::Magenta,
			FString::Printf(TEXT("Can Vault"))); //Printf returns a string
		return true;
	}
		
	return false;
}

