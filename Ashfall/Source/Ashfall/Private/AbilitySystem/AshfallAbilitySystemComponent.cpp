// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySystem/AshfallAbilitySystemComponent.h"
#include "AbilitySystem/Abilities/AshfallGameplayAbility.h"

void UAshfallAbilitySystemComponent::OnAbilityInputPressed(const FGameplayTag& InInputTag)
{
	if(!InInputTag.IsValid())
    {
        UE_LOG(LogTemp, Warning, TEXT("InInputag not valid"));
        return;
    }
    
    for(const FGameplayAbilitySpec& AbilitySpec : GetActivatableAbilities())
    {
        if(!AbilitySpec.DynamicAbilityTags.HasTagExact(InInputTag)) continue;
        TryActivateAbility(AbilitySpec.Handle);
    }
}

void UAshfallAbilitySystemComponent::OnAbilityInputReleased(const FGameplayTag& InInputTag)
{
	
}

void UAshfallAbilitySystemComponent::GrantHeroWeaponAbilities(const TArray<FAshfallHeroAbilitySet>& InDefaultWeaponAbilities,int32 ApplyLevel,TArray<FGameplayAbilitySpecHandle>& OutGrantedAbilitySpecHandles)
{
    if(InDefaultWeaponAbilities.IsEmpty())
    {
        return;
    }

    for(const FAshfallHeroAbilitySet& AbilitySet : InDefaultWeaponAbilities)
    {
        if(AbilitySet.IsValid()) continue;

        FGameplayAbilitySpec AbilitySpec(AbilitySet.AbilityToGrant);
        AbilitySpec.SourceObject = GetAvatarActor();
        AbilitySpec.Level = ApplyLevel;
        AbilitySpec.DynamicAbilityTags.AddTag(AbilitySet.InputTag);

        //GiveAbility(AbilitySpec);

        OutGrantedAbilitySpecHandles.AddUnique(GiveAbility(AbilitySpec));
    }
}

void UAshfallAbilitySystemComponent::RemoveGrantedHeroWeaponAbilities(UPARAM(ref) TArray<FGameplayAbilitySpecHandle>& InSpecHandlesToRemove)
{
	if(InSpecHandlesToRemove.IsEmpty())
    {
        return;
    }

    for(const FGameplayAbilitySpecHandle& SpecHandle : InSpecHandlesToRemove)
    {
        if(SpecHandle.IsValid())
        {
            ClearAbility(SpecHandle);
        }
    }

    InSpecHandlesToRemove.Empty();
}