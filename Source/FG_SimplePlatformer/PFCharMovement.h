// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "PFCharMovement.generated.h"
//#include "CharacterMovementDataAsset.h"



UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class FG_SIMPLEPLATFORMER_API UPFCharMovement : public UActorComponent
{
	GENERATED_BODY()


protected:
virtual void BeginPlay() override;

public:	
	UPFCharMovement();

	bool Grounded = false;
	bool Crouching = false;

	UFUNCTION(BlueprintCallable)
	void Move(FVector inputVector, float acceleration, float maxSpeed);

	UFUNCTION(BlueprintCallable)
	void Jump(float jumpForce);

	UFUNCTION(BlueprintCallable)
	void ApplyFriction(float frictionAmount);

	UFUNCTION(BlueprintCallable)
	void Hover(float hoverRay, float hoverDistance, float hoverStrength, float hoverDamping);

	UFUNCTION(BlueprintCallable)
	void Glide();

	UFUNCTION(BlueprintCallable)
	bool GroundCheck(float hoverRay);

	UFUNCTION(BlueprintCallable)
	void BrieflyDisableFloat();

	UPROPERTY()
	UPrimitiveComponent* Shape;

	//UPROPERTY(EditAnywhere)
	//UCharacterMovementDataAsset* MovementData;

private:
	float disabledFloatTimer = 0.f;

};
