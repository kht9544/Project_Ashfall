// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "NativeGameplayTags.h"

namespace AshfallGameplayTags
{
	// Input
	ASHFALL_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(InputTag_Move);
	ASHFALL_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(InputTag_Look);
	ASHFALL_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(InputTag_EquipAxe);
	ASHFALL_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(InputTag_UnequipAxe);
	ASHFALL_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(InputTag_LightAttack_Axe);
	ASHFALL_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(InputTag_HeavyAttack_Axe);


	//Player Tag
	ASHFALL_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Player_Ability_Equip_Axe);
	ASHFALL_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Player_Ability_Unequip_Axe);	
	ASHFALL_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Player_Ability_Attack_Light_Axe);	
	ASHFALL_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Player_Ability_Attack_Heavy_Axe);	


	ASHFALL_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Player_Weapon_Axe);	

	ASHFALL_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Player_Event_Equip_Axe);	
	ASHFALL_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Player_Event_Unequip_Axe);	

	ASHFALL_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Player_Status_JumpToFinisher);

	//Enemy Tag
	ASHFALL_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Enemy_Weapon);	

	//Shared Tag
	ASHFALL_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Shared_Event_MeleeHit);

	ASHFALL_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Shared_SetByCaller_BaseDamage);


}
