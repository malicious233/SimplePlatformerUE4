#include "CCAttacker.h"
#include "CCAttack.h"


UCCAttacker::UCCAttacker()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UCCAttacker::TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	if (ActiveAttack != nullptr)
	{
		ActiveAttack->AttackTick(DeltaTime);
		
	}
}

void UCCAttacker::PerformAttack(UCCAttack* attack)
{
	ActiveAttack = attack;
	ActiveAttack->StartAttack();
	
}
