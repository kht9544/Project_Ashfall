// Fill out your copyright notice in the Description page of Project Settings.


#include "AnimInstance/Hero/AshfallHeroAnimInstance.h"
#include "Characters/HeroCharacter.h"

void UAshfallHeroAnimInstance::NativeInitializeAnimation()
{
	Super::NativeInitializeAnimation();

    if(OwningCharacter)
    {
        OwningHeroCharacter = Cast<AHeroCharacter>(OwningCharacter);
    }
}


void UAshfallHeroAnimInstance::NativeThreadSafeUpdateAnimation(float DeltaSeconds)
{
    Super::NativeThreadSafeUpdateAnimation(DeltaSeconds);

    if(bHasAcceleration)
    {
        IdleElpasedTime = 0.f;
        bShouldEnterRelaxState = false;
    }
    else
    {
        IdleElpasedTime += DeltaSeconds;
        bShouldEnterRelaxState = (IdleElpasedTime >= EnterRelaxStateThreshold);
    }
}