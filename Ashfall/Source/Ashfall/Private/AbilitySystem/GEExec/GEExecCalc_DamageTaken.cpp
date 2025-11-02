// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySystem/GEExec/GEExecCalc_DamageTaken.h"
#include "AbilitySystem/AshfallAttributeSet.h"
#include "AshfallGameplayTags.h"


#include "DebugHelper.h"
struct FAshfallDamageCapture
{
    DECLARE_ATTRIBUTE_CAPTUREDEF(AttackPower)
    DECLARE_ATTRIBUTE_CAPTUREDEF(DefensePower)
    DECLARE_ATTRIBUTE_CAPTUREDEF(DamageTaken)

    FAshfallDamageCapture()
    {
        DEFINE_ATTRIBUTE_CAPTUREDEF(UAshfallAttributeSet, AttackPower, Source, false)
        DEFINE_ATTRIBUTE_CAPTUREDEF(UAshfallAttributeSet, DefensePower, Target, false)
        DEFINE_ATTRIBUTE_CAPTUREDEF(UAshfallAttributeSet, DamageTaken, Target, false)
    }
};

static const FAshfallDamageCapture& GetAshfallDamageCapture()
{
    static FAshfallDamageCapture AshfallDamageCapture;
    return AshfallDamageCapture;
}


UGEExecCalc_DamageTaken::UGEExecCalc_DamageTaken()
{
    //Slow way to Capture
	// FProperty* AttackPowerProperty = FindFieldChecked<FProperty>(
    //     UAshfallAttributeSet::StaticClass(),
    //     GET_MEMBER_NAME_CHECKED(UAshfallAttributeSet, AttackPower)
    // );

    // FGameplayEffectAttributeCaptureDefinition AttackPowerCaptureDefinition
    // (
    //     AttackPowerProperty,
    //     EGameplayEffectAttributeCaptureSource::Source,
    //     false
    // );

    // RelevantAttributesToCapture.Add(AttackPowerCaptureDefinition);


    //Fast way to Capture
    RelevantAttributesToCapture.Add(GetAshfallDamageCapture().AttackPowerDef);
    RelevantAttributesToCapture.Add(GetAshfallDamageCapture().DefensePowerDef);
    RelevantAttributesToCapture.Add(GetAshfallDamageCapture().DamageTakenDef);

}

void UGEExecCalc_DamageTaken::Execute_Implementation(const FGameplayEffectCustomExecutionParameters& ExecutionParams, OUT FGameplayEffectCustomExecutionOutput& OutExecutionOutput) const 
{
    const FGameplayEffectSpec& EffectSpec = ExecutionParams.GetOwningSpec();

    // EffectSpec.GetContext().GetSourceObject();
    // EffectSpec.GetContext().GetAbility();
    // EffectSpec.GetContext().GetInstigator();
    // EffectSpec.GetContext().GetEffectCauser();

    FAggregatorEvaluateParameters EvaluateParameters;
    EvaluateParameters.SourceTags = EffectSpec.CapturedSourceTags.GetAggregatedTags();
    EvaluateParameters.TargetTags = EffectSpec.CapturedTargetTags.GetAggregatedTags();

    float SourceAttackPower = 0.f;
    ExecutionParams.AttemptCalculateCapturedAttributeMagnitude(GetAshfallDamageCapture().AttackPowerDef, EvaluateParameters, SourceAttackPower);


    float BaseDamage = 0.f;
    int32 UsedLightAttackComboCount = 0;
    int32 UsedHeavyAttackComboCount = 0;

    for(const TPair<FGameplayTag, float>& TagMagnitude : EffectSpec.SetByCallerTagMagnitudes)
    {
        if(TagMagnitude.Key.MatchesTagExact(AshfallGameplayTags::Shared_SetByCaller_BaseDamage))
        {
            BaseDamage = TagMagnitude.Value;
        }

        if(TagMagnitude.Key.MatchesTagExact(AshfallGameplayTags::Player_SetByCaller_AttackType_Light))
        {
            UsedLightAttackComboCount = TagMagnitude.Value;
        }

        if(TagMagnitude.Key.MatchesTagExact(AshfallGameplayTags::Player_SetByCaller_AttackType_Heavy))
        {
            UsedHeavyAttackComboCount = TagMagnitude.Value;
        }

    }

    float TargetDefensePower = 0.f;
    ExecutionParams.AttemptCalculateCapturedAttributeMagnitude(GetAshfallDamageCapture().DefensePowerDef, EvaluateParameters, TargetDefensePower);

    if(UsedLightAttackComboCount != 0)
    {
        const float DamageIncreasePercentLight = (UsedLightAttackComboCount - 1) * 0.05 * 1.f;

        BaseDamage *= DamageIncreasePercentLight;
    }

    if(UsedHeavyAttackComboCount != 0)
    {
        const float DamageIncreasePercentHeavy = UsedHeavyAttackComboCount * 0.15f + 1.f;

        BaseDamage *= DamageIncreasePercentHeavy;
    }

    const float FinalDamageDone = BaseDamage * SourceAttackPower / TargetDefensePower;
    Debug::Print(TEXT("FinalDamageDone"), FinalDamageDone);

    if(FinalDamageDone > 0.f)
    {
        OutExecutionOutput.AddOutputModifier(
            FGameplayModifierEvaluatedData(
                GetAshfallDamageCapture().DamageTakenProperty,
                EGameplayModOp::Override,
                FinalDamageDone
            )
        );
    }

}