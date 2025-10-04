// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AnimInstance/AshfallCharacterAnimInstance.h"
#include "AshfallHeroAnimInstance.generated.h"

class AHeroCharacter;


/**
 * 
 */
UCLASS()
class ASHFALL_API UAshfallHeroAnimInstance : public UAshfallCharacterAnimInstance
{
	GENERATED_BODY()

public:
	virtual void NativeInitializeAnimation() override;
	virtual void NativeThreadSafeUpdateAnimation(float DeltaSeconds) override; 

protected:
	UPROPERTY(VisibleDefaultsOnly,BlueprintReadOnly,Category = "AnimData|Refrences")
	AHeroCharacter* OwningHeroCharacter;

	UPROPERTY(VisibleDefaultsOnly,BlueprintReadOnly,Category = "AnimData|LocomotionData")
	bool bShouldEnterRelaxState;

	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly,Category = "AnimData|LocomotionData")
	float EnterRelaxStateThreshold = 5.f;

	float IdleElpasedTime;

};


