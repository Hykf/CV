// Fill out your copyright notice in the Description page of Project Settings.


#include "Spell_Immovable.h"

ASpell_Immovable::ASpell_Immovable()
{
    BoxComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("Box Component"));
    RootComponent = BoxComponent;

    SpellMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("SpellMesh"));
	SpellMesh->SetupAttachment(BoxComponent);
}