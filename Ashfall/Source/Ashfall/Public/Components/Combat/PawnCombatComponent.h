// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/PawnExtensionComponentBase.h"
#include "GameplayTagContainer.h"
#include "PawnCombatComponent.generated.h"

class AAshfallWeaponBase;

UENUM(BlueprintType)
enum class EToggleDamageType : uint8
{
	CurrentEquippedWeapon,
	LeftHand,
	RightHand
};

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

	UFUNCTION(BlueprintCallable, Category = "Ashfall|Combat")
	void ToggleWeaponCollision(bool bShouldEnable,EToggleDamageType ToggleDamageType = EToggleDamageType::CurrentEquippedWeapon);

	virtual void OnHitTargetActor(AActor* HitActor);
	virtual void OnWeaponPulledFromTargetActor(AActor* InteractedActor); 

protected:
	TArray<AActor*>OverlappedActors;

private:
	TMap<FGameplayTag,AAshfallWeaponBase*> CharacterCarriedWeaponMap;
};







