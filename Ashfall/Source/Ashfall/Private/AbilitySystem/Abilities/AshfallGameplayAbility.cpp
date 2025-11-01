// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySystem/Abilities/AshfallGameplayAbility.h"
#include "AbilitySystem/AshfallAbilitySystemComponent.h"
#include "Components/Combat/PawnCombatComponent.h"
#include "AbilitySystemComponent.h"
#include "AbilitySystemBlueprintLibrary.h"


void UAshfallGameplayAbility::OnGiveAbility(const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilitySpec& Spec)
{
	Super::OnGiveAbility(ActorInfo, Spec);

    if(AbilityActivationPolicy == EAshfallAbilityActivationPolicy::OnGiven)
    {
        if(ActorInfo && !Spec.IsActive())
        {
            ActorInfo->AbilitySystemComponent->TryActivateAbility(Spec.Handle);
        }
    }

}

void UAshfallGameplayAbility::EndAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, bool bReplicateEndAbility, bool bWasCancelled)
{
	Super::EndAbility(Handle, ActorInfo, ActivationInfo, bReplicateEndAbility, bWasCancelled);

    if(AbilityActivationPolicy == EAshfallAbilityActivationPolicy::OnGiven)
    {
        if(ActorInfo)
        {
            ActorInfo->AbilitySystemComponent->ClearAbility(Handle);
        }
    }
}

UPawnCombatComponent* UAshfallGameplayAbility::GetPawnCombatComponentFromActorInfo() const
{
    return GetAvatarActorFromActorInfo()->FindComponentByClass<UPawnCombatComponent>();
}

UAshfallAbilitySystemComponent* UAshfallGameplayAbility::GetAshfallAbilitySystemComponentFromActorInfo() const
{
    return Cast<UAshfallAbilitySystemComponent>(CurrentActorInfo->AbilitySystemComponent);
}

FActiveGameplayEffectHandle UAshfallGameplayAbility::NativeApplyEffectSpecHandleToTarget(AActor* TargetActor, const FGameplayEffectSpecHandle& InSpecHandle)
{

    UAbilitySystemComponent* TargetASC = UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(TargetActor);

    check(TargetASC && InSpecHandle.IsValid());

	return GetAshfallAbilitySystemComponentFromActorInfo()->ApplyGameplayEffectSpecToTarget
    (
        *InSpecHandle.Data, 
        TargetASC
    );
}

FActiveGameplayEffectHandle UAshfallGameplayAbility::BP_ApplyEffectSpecHandleToTarget(AActor* TargetActor, const FGameplayEffectSpecHandle& InSpecHandle, EAshfallSuccessType& OutSuccessType)
{
    FActiveGameplayEffectHandle ActiveGameplayEffectHandle = NativeApplyEffectSpecHandleToTarget(TargetActor, InSpecHandle);

    OutSuccessType = ActiveGameplayEffectHandle.WasSuccessfullyApplied() ? EAshfallSuccessType::Successful : EAshfallSuccessType::Failed;

    return ActiveGameplayEffectHandle;
}
