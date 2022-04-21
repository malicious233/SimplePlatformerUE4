#include "CCAttack.h"
#include "CCHitbox.h"


void UCCAttack::AttackTick(float DeltaTime)
{
	timeSinceAttackStart += DeltaTime;
	OnAttackTick(DeltaTime);
}

void UCCAttack::NewAttackCluster()
{
	HitTargets.Empty();
}

void UCCAttack::CreateHitbox()
{
	ACCHitbox* hitbox = CreateDefaultSubobject<ACCHitbox>(TEXT("Hitbox"));
	hitbox->AttackOwner = this;
}


void UCCAttack::StartAttack()
{
	timeSinceAttackStart = 0.f;
	OnAttackStart();
}

