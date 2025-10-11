// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Items/Weapons/AshfallWeaponBase.h"
#include "AshfallTypes/AshfallStructTypes.h"
#include "GameplayAbilitySpecHandle.h"
#include "AshfallHeroWeapon.generated.h"

/**
 * 
 */
UCLASS()
class ASHFALL_API AAshfallHeroWeapon : public AAshfallWeaponBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly,Category = "WeaponData")
	FAshfallHeroWeaponData HeroWeaponData;

	UFUNCTION(BlueprintCallable)
	void AssignGrantedAbilityspecHandles(const TArray<FGameplayAbilitySpecHandle>& InSpecHandles);

	UFUNCTION(BlueprintPure)
	TArray<FGameplayAbilitySpecHandle> GetGrantedAbilitySpecHandles() const;

private:
	TArray<FGameplayAbilitySpecHandle> GrantedAbilitySpecHandles;
	
};

