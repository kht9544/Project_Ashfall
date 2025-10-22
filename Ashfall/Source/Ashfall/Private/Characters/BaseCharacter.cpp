// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/BaseCharacter.h"
#include "AbilitySystem/AshfallAbilitySystemComponent.h"
#include "AbilitySystem/AshfallAttributeSet.h"



// Sets default values
ABaseCharacter::ABaseCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	PrimaryActorTick.bStartWithTickEnabled = false;

	GetMesh()->bReceivesDecals = false;
	
	AshfallAbilitySystemComponent = CreateDefaultSubobject<UAshfallAbilitySystemComponent>(TEXT("AshfallAbilitySystemComponent"));

	AshfallAttributeSet	= CreateDefaultSubobject<UAshfallAttributeSet>(TEXT("AshfallAttributeSet"));
}

void ABaseCharacter::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);

	if(AshfallAbilitySystemComponent)
	{
		AshfallAbilitySystemComponent->InitAbilityActorInfo(this,this);
		
		ensureMsgf(!CharacterStartUpData.IsNull(),TEXT("Forgot to assign start up data to %s"),*GetName());

	}
}

void ABaseCharacter::UnPossessed()
{
	Super::UnPossessed();
}

UAbilitySystemComponent* ABaseCharacter::GetAbilitySystemComponent() const
{
	return GetAshfallAbilitySystemComponent();
}

UPawnCombatComponent* ABaseCharacter::GetPawnCombatComponent() const 
{
	return nullptr;
}

