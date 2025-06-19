// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "AbilitySystemComponent.h"
#include "CharacterAttributeSet.generated.h"

// Macros made by GAS
#define ATTRIBUTE_ACCESSORS(ClassName, PropertyName) \
	GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ClassName, PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_GETTER(PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_SETTER(PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_INITTER(PropertyName)

/**
 * 
 */
UCLASS()
class WHY_API UCharacterAttributeSet : public UAttributeSet
{
	GENERATED_BODY()
	
public:
	//Constructor
	UCharacterAttributeSet();

	// This is where you will add new stats. 

	// Current health of the owner
	UPROPERTY(BlueprintReadOnly, Category = "Health", ReplicatedUsing = OnRep_CurrentHealth)
	FGameplayAttributeData CurrentHealth;
	ATTRIBUTE_ACCESSORS(UCharacterAttributeSet, CurrentHealth)

	// Max health that the owner can have
	UPROPERTY(BlueprintReadOnly, Category = "Health", ReplicatedUsing = OnRep_MaxHealth)
	FGameplayAttributeData MaxHealth;
	ATTRIBUTE_ACCESSORS(UCharacterAttributeSet, MaxHealth)

	UPROPERTY(BlueprintReadOnly, Category = "Ap", ReplicatedUsing = OnRep_CurrentAp)
	FGameplayAttributeData CurrentAp;
	ATTRIBUTE_ACCESSORS(UCharacterAttributeSet, CurrentAp)

protected:
	// where we communicate with clients and add it here when adding a new attribute
	UFUNCTION()
	virtual void OnRep_CurrentHealth(const FGameplayAttributeData& OldCurrentHealth);
	
	UFUNCTION()
	virtual void OnRep_MaxHealth(const FGameplayAttributeData& OldMaxHealth);

	UFUNCTION()
	virtual void OnRep_CurrentAp(const FGameplayAttributeData& OldAp);
		
};