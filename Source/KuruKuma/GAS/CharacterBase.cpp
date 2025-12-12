#include "CharacterBase.h"
#include "CharacterStatAttributeSet.h"

ACharacterBase::ACharacterBase() : Super()
{
	AbilitySystemComponent = CreateDefaultSubobject<UAbilitySystemComponent>("AbilitySystemComponent");
	
	StatAttributeSet = CreateDefaultSubobject<UCharacterStatAttributeSet>(TEXT("StatAttributeSet"));
	AbilitySystemComponent->AddAttributeSetSubobject<UCharacterStatAttributeSet>(StatAttributeSet);
}

void ACharacterBase::PostInitializeComponents()
{
	Super::PostInitializeComponents();

	ABPostInitializeComponents();
}