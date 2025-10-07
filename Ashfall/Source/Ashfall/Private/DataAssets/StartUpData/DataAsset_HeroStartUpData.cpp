// Fill out your copyright notice in the Description page of Project Settings.


#include "DataAssets/StartUpData/DataAsset_HeroStartUpData.h"
#include "AbilitySystem/Abilities/AshfallGameplayAbility.h"
#include "AbilitySystem/AshfallAbilitySystemComponent.h"

bool FAshfallHeroAbilitySet::IsValid() const
{                  
	return InputTag.IsValid() && AbilityToGrant;
}

void UDataAsset_HeroStartUpData::GiveToAbilitySystemComponent(UAshfallAbilitySystemComponent* InASCToGive,int32 ApplyLevel)
{
	Super::GiveToAbilitySystemComponent(InASCToGive, ApplyLevel);

    for(const FAshfallHeroAbilitySet& AbilitySet : HeroStartAbilitySets)
    {
        if(!AbilitySet.IsValid())
        {
            UE_LOG(LogTemp, Warning, TEXT("NoAbilitySet"));
            continue;
        } 

        FGameplayAbilitySpec AbilitySpec(AbilitySet.AbilityToGrant);
        AbilitySpec.SourceObject = InASCToGive->GetAvatarActor();
        AbilitySpec.Level = ApplyLevel;
        AbilitySpec.DynamicAbilityTags.AddTag(AbilitySet.InputTag);

        InASCToGive->GiveAbility(AbilitySpec);
    }
}