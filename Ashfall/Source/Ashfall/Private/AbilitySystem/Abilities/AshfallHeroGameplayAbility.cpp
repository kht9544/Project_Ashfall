// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySystem/Abilities/AshfallHeroGameplayAbility.h"
#include "Characters/HeroCharacter.h"
#include "Controller/HeroController.h"
#include "Components/Combat/HeroCombatComponent.h"


AHeroCharacter* UAshfallHeroGameplayAbility::GetHeroCharacterFromActorInfo()
{
    if(!CachedAshfallHeroCharacter.IsValid())
    {
        CachedAshfallHeroCharacter = Cast<AHeroCharacter>(CurrentActorInfo->AvatarActor);
    }

   return CachedAshfallHeroCharacter.IsValid() ? CachedAshfallHeroCharacter.Get() : nullptr;
}

AHeroController* UAshfallHeroGameplayAbility::GetHeroControllerFromActorInfo()
{
	if(!CachedAshfallHeroController.IsValid())
    {
        CachedAshfallHeroController = Cast<AHeroController>(CurrentActorInfo->PlayerController);
    }
    return CachedAshfallHeroController.IsValid() ? CachedAshfallHeroController.Get() : nullptr;
}

UHeroCombatComponent* UAshfallHeroGameplayAbility::GetHeroCombatComponentFromActorInfo()
{
	return GetHeroCharacterFromActorInfo()->GetHeroCombatComponent();
}