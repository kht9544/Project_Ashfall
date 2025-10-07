// Fill out your copyright notice in the Description page of Project Settings.


#include "DataAssets/StartUpData/DataAsset_StartUpDataBase.h"
#include "AbilitySystem/AshfallAbilitySystemComponent.h"
#include "AbilitySystem/Abilities/AshfallGameplayAbility.h"

void UDataAsset_StartUpDataBase::GiveToAbilitySystemComponent(UAshfallAbilitySystemComponent* InASCToGive,int32 ApplyLevel)
{
	check(InASCToGive);

    GrantAbilities(ActivateOnGivenAbilities,InASCToGive,ApplyLevel);
    GrantAbilities(ReactivaeAbilities,InASCToGive,ApplyLevel);

}

void UDataAsset_StartUpDataBase::GrantAbilities(const TArray<TSubclassOf<UAshfallGameplayAbility>>& InAbilitiesToGive, UAshfallAbilitySystemComponent* InASCToGive,int32 ApplyLevel)
{
	if(InAbilitiesToGive.IsEmpty())
    {
        return;
    }

    for(const TSubclassOf<UAshfallGameplayAbility>& Ability : InAbilitiesToGive)
    {
        if(!Ability) continue;

        FGameplayAbilitySpec AbilitySpec(Ability);
        AbilitySpec.SourceObject = InASCToGive->GetAvatarActor();
        AbilitySpec.Level = ApplyLevel;

        InASCToGive->GiveAbility(AbilitySpec);
    }

}