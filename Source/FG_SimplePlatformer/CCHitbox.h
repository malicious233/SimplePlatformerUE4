#pragma once

#include "GameFramework/Actor.h"
#include "CCHitbox.generated.h"

class USphereComponent;
class UCCAttack;

UCLASS()
class ACCHitbox : public AActor
{
	GENERATED_BODY()
public:
	ACCHitbox();

	void BeginPlay() override;
	void Tick(float DeltaTime) override;

	UFUNCTION()
	void HandleHitboxBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	float Damage;

	UPROPERTY(VisibleAnywhere)
	USphereComponent* Collision;

	//What CCAttack class owns this hitbox, or what Attack it will communicate with those it hits
	UPROPERTY()
	UCCAttack* AttackOwner;

};