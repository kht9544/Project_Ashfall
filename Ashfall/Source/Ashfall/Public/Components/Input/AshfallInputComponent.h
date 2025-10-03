// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EnhancedInputComponent.h"
#include "DataAssets/Input/DataAsset_InputConfig.h"
#include "AshfallInputComponent.generated.h"

/**
 * 
 */
UCLASS()
class ASHFALL_API UAshfallInputComponent : public UEnhancedInputComponent
{
	GENERATED_BODY()

public:
	template<class UserObject,typename CallbackFunc>
	void BindNativeInputAction(const UDataAsset_InputConfig* InInputConfig, const FGameplayTag& InInputTag,ETriggerEvent TriggerEvent,UserObject* ContextObject,CallbackFunc Func);
	
	
};
template<class UserObject,typename CallbackFunc>
	void UAshfallInputComponent::BindNativeInputAction(const UDataAsset_InputConfig* InInputConfig, const FGameplayTag& InInputTag,ETriggerEvent TriggerEvent,UserObject* ContextObject,CallbackFunc Func)
{
	checkf(InInputConfig,TEXT("Input config data asset is null"));

	if(UInputAction* FoundAction = InInputConfig->FindNativeInputActionByTag(InInputTag))
	{
		BindAction(FoundAction,TriggerEvent,ContextObject,Func);
	}
}

