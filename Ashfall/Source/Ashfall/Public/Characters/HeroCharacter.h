// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BaseCharacter.h"
#include "HeroCharacter.generated.h"

class UCameraComponent;
class USpringArmComponent;
class UDataAsset_InputConfig;
struct FInputActionValue;

/**
 * 
 */
UCLASS()
class ASHFALL_API AHeroCharacter : public ABaseCharacter
{
	GENERATED_BODY()

public:
	AHeroCharacter();

private:

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	virtual void BeginPlay() override;

private:
#pragma region Components

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* FollowCamera;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent* CameraBoom;

#pragma endregion

#pragma region Inputs
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	UDataAsset_InputConfig* InputConfigDataAsset;

	void Input_Move(const FInputActionValue& InputActionValue);

	void Input_Look(const FInputActionValue& InputActionValue);
#pragma endregion

};
















