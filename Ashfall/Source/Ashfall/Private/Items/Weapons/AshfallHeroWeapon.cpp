// Fill out your copyright notice in the Description page of Project Settings.


#include "Items/Weapons/AshfallHeroWeapon.h"

void AAshfallHeroWeapon::AssignGrantedAbilityspecHandles(const TArray<FGameplayAbilitySpecHandle>& InSpecHandles)
{
	GrantedAbilitySpecHandles = InSpecHandles;
}

TArray<FGameplayAbilitySpecHandle> AAshfallHeroWeapon::GetGrantedAbilitySpecHandles() const
{
	return GrantedAbilitySpecHandles;
}
