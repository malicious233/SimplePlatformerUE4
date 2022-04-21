// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "CharacterMovementDataAsset.generated.h"

/**
 * 
 */
UCLASS(BlueprintType)
class FG_SIMPLEPLATFORMER_API UCharacterMovementDataAsset : public UDataAsset
{
	GENERATED_BODY()
	
	
public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float HoverRay;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float HoverDistance;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float HoverStrength;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float HoverDamping;

	//UPROPERTY(EditAnywhere, BlueprintReadOnly)
	//float JumpForce;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float MaxSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float Acceleration;

	//UPROPERTY(EditAnywhere, BlueprintReadOnly)
	//float Air_Acceleration;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float Deacceleration;

	//UPROPERTY(EditAnywhere, BlueprintReadOnly)
	//float Air_Deacceleration;
	



	
};
