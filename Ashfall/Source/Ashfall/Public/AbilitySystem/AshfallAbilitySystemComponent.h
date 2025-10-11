// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "AshfallTypes/AshfallStructTypes.h"
#include "AshfallAbilitySystemComponent.generated.h"


/**
 * 
 */
UCLASS()
class ASHFALL_API UAshfallAbilitySystemComponent : public UAbilitySystemComponent
{
	GENERATED_BODY()

public:
	void OnAbilityInputPressed(const FGameplayTag& InInputTag);
	void OnAbilityInputReleased(const FGameplayTag& InInputTag);

	UFUNCTION(BlueprintCallable, Category = "Ashfall|Ability", meta = (ApplyLevel = "1"))
	void GrantHeroWeaponAbilities(const TArray<FAshfallHeroAbilitySet>& InDefaultWeaponAbilities,int32 ApplyLevel,TArray<FGameplayAbilitySpecHandle>& OutGrantedAbilitySpecHandles);
	
	UFUNCTION(BlueprintCallable, Category = "Ashfall|Ability")
	void RemoveGrantedHeroWeaponAbilities(UPARAM(ref) TArray<FGameplayAbilitySpecHandle>& InSpecHandlesToRemove);

};






