// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystem/Abilities/AshfallGameplayAbility.h"
#include "AshfallEnemyGameplayAbility.generated.h"

class AEnemyCharacter;
class UEnemyCombatComponent;

/**
 * 
 */
UCLASS()
class ASHFALL_API UAshfallEnemyGameplayAbility : public UAshfallGameplayAbility
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="Ashfall|Ability")
	AEnemyCharacter* GetEnemyCharacterFromActorInfo();

	UFUNCTION(BlueprintPure, Category="Ashfall|Ability")
	UEnemyCombatComponent* GetEnemyCombatComponentFromActorInfo();

private:
	TWeakObjectPtr<AEnemyCharacter> CachedEnemyCharacter;
};

