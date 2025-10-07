// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySystem/AshfallAbilitySystemComponent.h"

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