// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "DataAsset_StartUpDataBase.generated.h"

class UAshfallGameplayAbility;
class UAshfallAbilitySystemComponent;

/**
 * 
 */
UCLASS()
class ASHFALL_API UDataAsset_StartUpDataBase : public UDataAsset
{
	GENERATED_BODY()

public:
	virtual void GiveToAbilitySystemComponent(UAshfallAbilitySystemComponent* InASCToGive,int32 ApplyLevel = 1);

protected:
	UPROPERTY(EditDefaultsOnly,Category = "StartUpData")
	TArray<TSubclassOf<UAshfallGameplayAbility>> ActivateOnGivenAbilities;

	UPROPERTY(EditDefaultsOnly,Category = "StartUpData")
	TArray<TSubclassOf<UAshfallGameplayAbility>> ReactivaeAbilities;

	void GrantAbilities(const TArray<TSubclassOf<UAshfallGameplayAbility>>& InAbilitiesToGive, UAshfallAbilitySystemComponent* InASCToGive,int32 ApplyLevel = 1 );

};




