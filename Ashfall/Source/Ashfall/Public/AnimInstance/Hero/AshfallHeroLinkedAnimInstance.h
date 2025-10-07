// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AnimInstance/AshfallBaseAnimInstance.h"
#include "AshfallHeroLinkedAnimInstance.generated.h"

class UAshfallHeroAnimInstance;

/**
 * 
 */
UCLASS()
class ASHFALL_API UAshfallHeroLinkedAnimInstance : public UAshfallBaseAnimInstance
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, meta =(BlueprintThreadSafe))
	UAshfallHeroAnimInstance* GetHeroAnimInstance() const;
	
};

