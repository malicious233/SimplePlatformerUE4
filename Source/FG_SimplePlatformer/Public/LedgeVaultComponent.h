// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "LedgeVaultComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class FG_SIMPLEPLATFORMER_API ULedgeVaultComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	ULedgeVaultComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION(BlueprintCallable)
	bool CheckLedgeGrabbable();

public:
	UPROPERTY(EditAnywhere)
	FVector GrabOffset;

	UPROPERTY(EditAnywhere)
	float RayLength;

	UPROPERTY(EditAnywhere)
	float RayLengthUp;

	UPROPERTY(EditAnywhere)
	float RayLengthDown;


};
