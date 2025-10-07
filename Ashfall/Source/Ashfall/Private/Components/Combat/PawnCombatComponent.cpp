// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/Combat/PawnCombatComponent.h"
#include "Items/Weapons/AshfallWeaponBase.h"
#include "DebugHelper.h"

void UPawnCombatComponent::RegisterSpawnedWeapon(FGameplayTag InWeaponTagToRegister,AAshfallWeaponBase* InWeaponToRegister,bool bResgiterAsEquippedWeapon)
{
	checkf(!CharacterCarriedWeaponMap.Contains(InWeaponTagToRegister),TEXT("A named %s has already added carried weapon"),*InWeaponTagToRegister.ToString());
	check(InWeaponToRegister);

	CharacterCarriedWeaponMap.Emplace(InWeaponTagToRegister,InWeaponToRegister);

	if(bResgiterAsEquippedWeapon)
	{
		CurrentEquippedWeaponTag = InWeaponTagToRegister;
	}

    const FString WeaponString = FString::Printf(TEXT("A Weapon named: %s has been register using the tag %s"),*InWeaponToRegister->GetName(),*InWeaponTagToRegister.ToString());
    Debug::Print(WeaponString);
}

AAshfallWeaponBase* UPawnCombatComponent::GetCharacterCarriedWeaponByTag(FGameplayTag InWeaponTagToGet) const
{
	if(CharacterCarriedWeaponMap.Contains(InWeaponTagToGet))
	{
		if(AAshfallWeaponBase* const* FoundWeapon = CharacterCarriedWeaponMap.Find(InWeaponTagToGet))
		{
			return *FoundWeapon;
		}
		
		
	}
    return nullptr;

}

AAshfallWeaponBase* UPawnCombatComponent::GetCharacterCurrentEquippedWeapon() const
{
	if(!CurrentEquippedWeaponTag.IsValid())
	{
		return nullptr;
	}

	return GetCharacterCarriedWeaponByTag(CurrentEquippedWeaponTag);
}