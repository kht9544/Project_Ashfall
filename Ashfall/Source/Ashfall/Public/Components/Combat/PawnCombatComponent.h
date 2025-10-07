// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/PawnExtensionComponentBase.h"
#include "GameplayTagContainer.h"
#include "PawnCombatComponent.generated.h"

class AAshfallWeaponBase;

/**
 * 
 */
UCLASS()
class ASHFALL_API UPawnCombatComponent : public UPawnExtensionComponentBase
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "Ashfall|Combat")
	void RegisterSpawnedWeapon(FGameplayTag InWeaponTagToRegister,AAshfallWeaponBase* InWeaponToRegister,bool bResgiterAsEquippedWeapon = false);

	UFUNCTION(BlueprintCallable, Category = "Ashfall|Combat")
	AAshfallWeaponBase* GetCharacterCarriedWeaponByTag(FGameplayTag InWeaponTagToGet)const;

	UPROPERTY(BlueprintReadWrite, Category = "Ashfall|Combat")
	FGameplayTag CurrentEquippedWeaponTag;

	UFUNCTION(BlueprintCallable, Category = "Ashfall|Combat")
	AAshfallWeaponBase* GetCharacterCurrentEquippedWeapon() const;


private:
	TMap<FGameplayTag,AAshfallWeaponBase*> CharacterCarriedWeaponMap;
};



