// Fill out your copyright notice in the Description page of Project Settings.


#include "AnimInstance/Hero/AshfallHeroLinkedAnimInstance.h"
#include "AnimInstance/Hero/AshfallHeroAnimInstance.h"

UAshfallHeroAnimInstance* UAshfallHeroLinkedAnimInstance::GetHeroAnimInstance() const
{
    return Cast<UAshfallHeroAnimInstance>(GetOwningComponent()->GetAnimInstance());
}
