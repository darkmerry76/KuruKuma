#include "CharacterStatAttributeSet.h"
#include "GameplayEffectExtension.h"

UCharacterStatAttributeSet::UCharacterStatAttributeSet() : Super()
{
	Health = MaxHealth;
}

void UCharacterStatAttributeSet::PreAttributeBaseChange(const FGameplayAttribute& Attribute, float& NewValue) const
{
	if (Attribute == GetHealthAttribute())
	{
		if (NewValue < Health.GetBaseValue())
		{
			NewValue = FMath::Clamp(NewValue, 0.f, Health.GetBaseValue());
		}
	}
}

void UCharacterStatAttributeSet::PostAttributeBaseChange(const FGameplayAttribute& Attribute, float OldValue, float NewValue) const
{
	if (Attribute == GetHealthAttribute())
	{
		OnHealthChanged.Broadcast(OldValue, NewValue);
	}
	else if (Attribute == GetMaxHealthAttribute())
	{
		OnMaxHealthChanged.Broadcast(OldValue, NewValue);
	}
}

void UCharacterStatAttributeSet::PostGameplayEffectExecute(const struct FGameplayEffectModCallbackData& Data)
{
	if (GetHealth() <= 0.f)
	{
		OnOutOfHealth.Broadcast(Data.EffectSpec.GetContext().GetInstigator());
	}
}