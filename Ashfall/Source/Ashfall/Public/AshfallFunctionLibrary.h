// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AshfallTypes/AshfallEnumTypes.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "AshfallFunctionLibrary.generated.h"

class UAshfallAbilitySystemComponent;
class UPawnCombatComponent;



/**
 * 
 */
UCLASS()
class ASHFALL_API UAshfallFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
public:
	static UAshfallAbilitySystemComponent* NativeGetAshfallASCFromActor(AActor* InActor);

	UFUNCTION(BlueprintCallable, Category = "Ashfall|FunctionLibrary")
	static void AddGameplayTagToActorIfNone(AActor* InActor,FGameplayTag TagToAdd);

	UFUNCTION(BlueprintCallable, Category = "Ashfall|FunctionLibrary")
	static void RemoveGameplayTagToActorIfNone(AActor* InActor,FGameplayTag TagToRemove);

	static bool NativeDoesActorHaveTag(AActor* InActor,FGameplayTag TagToCheck);
	
	UFUNCTION(BlueprintCallable, Category = "Ashfall|FunctionLibrary", meta = (DisplayName = "Does Actor Have Tag",ExpandEnumAsExecs = "OutConfirmType"))
	static void BP_DoesActorHaveTag(AActor* InActor,FGameplayTag TagToCheck,EAshfallConfirmType& OutConfirmType);

	static UPawnCombatComponent* NativeGetPawnCombatComponentFromActor(AActor* InActor);

	UFUNCTION(BlueprintCallable, Category = "Ashfall|FunctionLibrary", meta = (DisplayName = "Get Pawn Combat Component From Actor", ExpandEnumAsExecs = "OutValidType"))
	static UPawnCombatComponent* BP_GetPawnCombatComponentFromActor(AActor* InActor, EAshfallValidType& OutValidType);

};


