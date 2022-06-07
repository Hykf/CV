// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Spell.generated.h"

UCLASS()
class CV_WIZARD_API ASpell : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASpell();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	virtual void Cast();

	UPROPERTY(EditAnywhere,BlueprintReadWrite, Category="Magic",meta = (AllowPrivateAccess = "true"))
	float damage = 15;

	UPROPERTY(EditAnywhere,BlueprintReadWrite, Category="Magic",meta = (AllowPrivateAccess = "true"))
	float manaCost = 15;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
