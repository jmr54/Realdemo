// Fill out your copyright notice in the Description page of Project Settings.


#include "CharacterAttributeSet.h"
#include "Net/UnrealNetwork.h"

// Set up the default values
UCharacterAttributeSet::UCharacterAttributeSet()
	: CurrentHealth(100.f), MaxHealth(100.f), CurrentAp(100.f)
{
}

// Add the function of the newly added stats 
void UCharacterAttributeSet::OnRep_CurrentHealth(const FGameplayAttributeData& OldCurrentHealth)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UCharacterAttributeSet, CurrentHealth, OldCurrentHealth);

}

void UCharacterAttributeSet::OnRep_MaxHealth(const FGameplayAttributeData& OldMaxHealth)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UCharacterAttributeSet, MaxHealth, OldMaxHealth);

}

void UCharacterAttributeSet::OnRep_CurrentAp(const FGameplayAttributeData& OldAp)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UCharacterAttributeSet, CurrentAp, OldAp);
}

// Replicate it over the network and add the new added stats
void UCharacterAttributeSet::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME_CONDITION_NOTIFY(UCharacterAttributeSet, CurrentHealth, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UCharacterAttributeSet, MaxHealth, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UCharacterAttributeSet, CurrentAp, COND_None, REPNOTIFY_Always);
}