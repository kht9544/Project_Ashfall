// Fill out your copyright notice in the Description page of Project Settings.


#include "AshfallTypes/AshfallStructTypes.h"
#include "AbilitySystem/Abilities/AshfallGameplayAbility.h"

bool FAshfallHeroAbilitySet::IsValid() const
{                  
	return InputTag.IsValid() && AbilityToGrant;
}