// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Spell.h"
#include "Components/BoxComponent.h"
#include "Spell_Immovable.generated.h"

/**
 * 
 */
UCLASS()
class CV_WIZARD_API ASpell_Immovable : public ASpell
{
	GENERATED_BODY()
	
	ASpell_Immovable();

protected:
	UPROPERTY(EditDefaultsOnly, Category="Magic")
	class UStaticMeshComponent* SpellMesh;

	UPROPERTY(EditAnywhere)
	UBoxComponent* BoxComponent;
	
};
