// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "AshfallStructTypes.generated.h"

class UAshfallHeroLinkedAnimInstance;


USTRUCT(BlueprintType)
struct FAshfallHeroWeaponData
{
	GENERATED_BODY()

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TSubclassOf<UAshfallHeroLinkedAnimInstance> WeaponAnimLayerToLink;
};

