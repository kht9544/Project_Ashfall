// Fill out your copyright notice in the Description page of Project Settings.


#include "AshfallFunctionLibrary.h"
#include "AbilitySystem/AshfallAbilitySystemComponent.h"
#include "AbilitySystemBlueprintLibrary.h"


UAshfallAbilitySystemComponent* UAshfallFunctionLibrary::NativeGetAshfallASCFromActor(AActor* InActor)
{
	check(InActor);

    return CastChecked<UAshfallAbilitySystemComponent>(UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(InActor));
}

void UAshfallFunctionLibrary::AddGameplayTagToActorIfNone(AActor* InActor,FGameplayTag TagToAdd)
{
	UAshfallAbilitySystemComponent* ASC = NativeGetAshfallASCFromActor(InActor);

    if(!ASC->HasMatchingGameplayTag(TagToAdd))
    {
        ASC->AddLooseGameplayTag(TagToAdd);
    }
}

void UAshfallFunctionLibrary::RemoveGameplayTagToActorIfNone(AActor* InActor,FGameplayTag TagToRemove)
{
	UAshfallAbilitySystemComponent* ASC = NativeGetAshfallASCFromActor(InActor);

    if(!ASC->HasMatchingGameplayTag(TagToRemove))
    {
        ASC->RemoveLooseGameplayTag(TagToRemove);
    }
}

bool UAshfallFunctionLibrary::NativeDoesActorHaveTag(AActor* InActor,FGameplayTag TagToCheck)
{
	UAshfallAbilitySystemComponent* ASC = NativeGetAshfallASCFromActor(InActor);

    return ASC->HasMatchingGameplayTag(TagToCheck);
}

void UAshfallFunctionLibrary::BP_DoesActorHaveTag(AActor* InActor,FGameplayTag TagToCheck,EAshfallConfirmType& OutConfirmType)
{
    OutConfirmType = NativeDoesActorHaveTag(InActor,TagToCheck)? EAshfallConfirmType::Yes : EAshfallConfirmType::No;
}