// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySystem/Abilities/AshfallEnemyGameplayAbility.h"
#include "Characters/EnemyCharacter.h"
#include "Components/Combat/EnemyCombatComponent.h"

AEnemyCharacter* UAshfallEnemyGameplayAbility::GetEnemyCharacterFromActorInfo()
{
	if(!CachedEnemyCharacter.IsValid())
    {
        CachedEnemyCharacter = Cast<AEnemyCharacter>(CurrentActorInfo->AvatarActor);
    }

    return CachedEnemyCharacter.IsValid()? CachedEnemyCharacter.Get() : nullptr;
}

UEnemyCombatComponent* UAshfallEnemyGameplayAbility::GetEnemyCombatComponentFromActorInfo()
{
	return GetEnemyCharacterFromActorInfo()->GetEnemyCombatComponent();
}
