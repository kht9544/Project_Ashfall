// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AbilitySystemInterface.h"
#include "BaseCharacter.generated.h"

class UAshfallAbilitySystemComponent;
class UAshfallAttributeSet;
class UDataAsset_StartUpDataBase;


UCLASS()
class ASHFALL_API ABaseCharacter : public ACharacter,public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ABaseCharacter();

	
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const;

protected:

	virtual void PossessedBy(AController* NewController) override;
	virtual void UnPossessed() override;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AbilitySystem")
	UAshfallAbilitySystemComponent* AshfallAbilitySystemComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AbilitySystem")
	UAshfallAttributeSet* AshfallAttributeSet;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "CharacterData")
	TSoftObjectPtr<UDataAsset_StartUpDataBase> CharacterStartUpData;

public:
	FORCEINLINE UAshfallAbilitySystemComponent* GetAshfallAbilitySystemComponent() const{return AshfallAbilitySystemComponent;}

	FORCEINLINE UAshfallAttributeSet* GetAshfallAttributeSet() const{return AshfallAttributeSet;}
};