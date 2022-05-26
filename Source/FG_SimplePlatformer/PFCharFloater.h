// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "PFCharFloater.generated.h"

class UPrimitiveComponent;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class FG_SIMPLEPLATFORMER_API UPFCharFloater : public UActorComponent
{
	GENERATED_BODY()

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	UPFCharFloater();

	void TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION(BlueprintCallable)
	bool Hover(float hoverRay, float hoverDistance, float hoverStrength, float hoverDamping);

	UFUNCTION(BlueprintCallable)
	void BrieflyDisableFloat();

	UPROPERTY()
	UPrimitiveComponent* Shape;

	UPROPERTY(EditDefaultsOnly)
	float HoverRayWidth;

	

private:
	float disabledFloatTimer;
	
};
