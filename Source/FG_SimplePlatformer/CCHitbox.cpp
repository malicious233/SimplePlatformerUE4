#include "CCHitbox.h"
#include "CCAttack.h"
#include "Components/SphereComponent.h"


ACCHitbox::ACCHitbox()
{
	Collision = CreateDefaultSubobject<USphereComponent>(TEXT("HitboxCollider"));
	RootComponent = Collision;
}

void ACCHitbox::BeginPlay()
{
	PrimaryActorTick.bCanEverTick = true;
}


void ACCHitbox::HandleHitboxBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (!AttackOwner->HitTargets.Contains(OtherActor)) //If the overlapped box does not exist in the blacklist
	{
		AttackOwner->HitTargets.Add(OtherActor);
		UE_LOG(LogTemp, Log, TEXT("Hit"));

	}
}

void ACCHitbox::Tick(float DeltaTime)
{
}
