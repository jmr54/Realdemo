// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AbilitySystemInterface.h"
#include "AbilitySystemComponent.h"
#include "CharacterAttributeSet.h"
#include "MyCharacter.generated.h"

UCLASS()
class WHY_API AMyCharacter : public ACharacter, public IAbilitySystemInterface

{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AMyCharacter();

	// Implement interface method to return AbilitySystemComponent
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Abiliy System componenet
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Abilities", meta = (AllowPrivateAccess = "true"))
	UAbilitySystemComponent* AbilitySystemComponent;

	// Character Attribute Set
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Attributes", meta = (AllowPrivateAccess = "true"))
	UCharacterAttributeSet* AttributeSet;

	// Initialize Attribute
	void InitializeAttributes();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
