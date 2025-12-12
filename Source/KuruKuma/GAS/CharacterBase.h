#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "CharacterBase.generated.h"

UCLASS(Blueprintable, BlueprintType)
class KURUKUMA_API ACharacterBase : public ACharacter
{
	GENERATED_BODY()
	
public:
	ACharacterBase();
	
	virtual void PostInitializeComponents() override;

	UFUNCTION(BlueprintImplementableEvent)
	void ABPostInitializeComponents();

protected:
	UPROPERTY(BlueprintReadOnly)
	TObjectPtr<class UCharacterStatAttributeSet> StatAttributeSet;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TObjectPtr<class UAbilitySystemComponent> AbilitySystemComponent;
};
