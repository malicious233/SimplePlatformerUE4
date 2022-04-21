#pragma once

#include "CCAttack.generated.h"



UCLASS(Blueprintable)
class UCCAttack : public UActorComponent
{
	GENERATED_BODY()


	

public:

	//Set which contains references to those you've hit with current attack
	//Might need revaluation what I need to save here. Weak pointers?
	UPROPERTY()
	TSet<AActor*> HitTargets;

	UFUNCTION(BlueprintImplementableEvent)
	void OnAttackTick(float DeltaTime);

	UFUNCTION(BlueprintCallable)
	void AttackTick(float DeltaTime);

	//Clears HitTargets set to let hitboxes rehit
	UFUNCTION(BlueprintCallable)
	void NewAttackCluster(); 

	//Creates hitbox with given data
	UFUNCTION(BlueprintCallable) 
	void CreateHitbox(); 

	//Event for when an attack is initiated. BP scripts the attack after this
	UFUNCTION(BlueprintImplementableEvent)
	void OnAttackStart();

	void StartAttack();

	//BP takes the time since attack to script attacks in the graph editor
	UPROPERTY(BlueprintReadOnly)
	float timeSinceAttackStart;



	
	

};