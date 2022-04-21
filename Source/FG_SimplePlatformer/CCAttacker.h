#pragma once 

#include "CCAttacker.generated.h"

class UCCAttack;

UCLASS(meta = (BlueprintSpawnableComponent))
class UCCAttacker : public UActorComponent
{
	GENERATED_BODY()

public:
	UCCAttacker();

	void TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION(BlueprintCallable)
	void PerformAttack(UCCAttack* attack);

	UPROPERTY(VisibleAnywhere)
	UCCAttack* ActiveAttack;

	UPROPERTY(BlueprintReadOnly)
	float timeSinceAttackStart;


};