// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySystem/Abilities/AshfallHeroGameplayAbility.h"
#include "Characters/HeroCharacter.h"
#include "Controller/HeroController.h"
#include "AbilitySystem/AshfallAbilitySystemComponent.h"
#include "AshfallGameplayTags.h"
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

FGameplayEffectSpecHandle UAshfallHeroGameplayAbility::MakeHeroDamageEffectSpecHandle(TSubclassOf<UGameplayEffect> EffectClass, float InWeaponBaseDamage, FGameplayTag InCurrentAttackTypeTag,int32 InCurrentComboCount)
{
	check(EffectClass);

    FGameplayEffectContextHandle ContextHandle = GetAshfallAbilitySystemComponentFromActorInfo()->MakeEffectContext();

    ContextHandle.SetAbility(this);
    ContextHandle.AddSourceObject(GetAvatarActorFromActorInfo());
    ContextHandle.AddInstigator(GetAvatarActorFromActorInfo(), GetAvatarActorFromActorInfo());

    FGameplayEffectSpecHandle EffectSpecHandle = GetAshfallAbilitySystemComponentFromActorInfo()->MakeOutgoingSpec
    (
        EffectClass,
        GetAbilityLevel(),
        ContextHandle  
    );

    EffectSpecHandle.Data->SetSetByCallerMagnitude(
        AshfallGameplayTags::Shared_SetByCaller_BaseDamage,
        InWeaponBaseDamage
    );

    if(InCurrentAttackTypeTag.IsValid())
    {
        EffectSpecHandle.Data->SetSetByCallerMagnitude(InCurrentAttackTypeTag, InCurrentComboCount);
    }

    return EffectSpecHandle;
}
