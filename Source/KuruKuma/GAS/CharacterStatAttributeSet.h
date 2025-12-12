#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "AttributeSet.h"
#include "CharacterStatAttributeSet.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FCharacterStatAttributeChanged, float, OldValue, float, NewValue);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOutOfHealth, class AActor*, InInstigator);

UCLASS(Blueprintable, BlueprintType)
class KURUKUMA_API UCharacterStatAttributeSet : public UAttributeSet
{
	GENERATED_BODY()

	UCharacterStatAttributeSet();
	
public:
	ATTRIBUTE_ACCESSORS_BASIC(ThisClass, Health)
	ATTRIBUTE_ACCESSORS_BASIC(ThisClass, MaxHealth)

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Attribute")
	FGameplayAttributeData Health = 0.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Attribute")
	FGameplayAttributeData MaxHealth = 0.f;
	
	UPROPERTY(BlueprintAssignable, Category="Attribute")
	FCharacterStatAttributeChanged OnHealthChanged;

	UPROPERTY(BlueprintAssignable, Category="Attribute")
	FCharacterStatAttributeChanged OnMaxHealthChanged;

	UPROPERTY(BlueprintAssignable, Category="Attribute")
	FOutOfHealth OnOutOfHealth;

protected:
	virtual void PreAttributeBaseChange(const FGameplayAttribute& Attribute, float& NewValue) const override;
	virtual void PostAttributeBaseChange(const FGameplayAttribute& Attribute, float OldValue, float NewValue) const override;
	virtual void PostGameplayEffectExecute(const struct FGameplayEffectModCallbackData& Data) override;
};
