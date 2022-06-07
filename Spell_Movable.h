// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Spell.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Components/SphereComponent.h"
#include "Spell_Movable.generated.h"

/**
 * 
 */
UCLASS()
class CV_WIZARD_API ASpell_Movable : public ASpell
{
	GENERATED_BODY()
public:
	ASpell_Movable();
protected:
	virtual void Cast() override;

	UPROPERTY(EditDefaultsOnly, Category="Magic")
	class UStaticMeshComponent* SpellMesh;

	UPROPERTY(EditAnywhere)
	USphereComponent* SphereComponent;

	UPROPERTY(VisibleAnywhere,Category="Movement")
	UProjectileMovementComponent* ProjectileMovementComponent;
	
};
