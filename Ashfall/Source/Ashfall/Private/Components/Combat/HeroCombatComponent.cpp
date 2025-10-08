// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/Combat/HeroCombatComponent.h"
#include "Items/Weapons/AshfallHeroWeapon.h"

AAshfallHeroWeapon* UHeroCombatComponent::GetHeroCarriedWeaponByTag(FGameplayTag InWeaponTag) const
{
    UE_LOG(LogTemp, Warning, TEXT("Hero CarriedWeapon Tag is %s"), *InWeaponTag.ToString());
    return Cast<AAshfallHeroWeapon>(GetCharacterCarriedWeaponByTag(InWeaponTag));
}