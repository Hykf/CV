// Fill out your copyright notice in the Description page of Project Settings.


#include "Spell_Movable.h"

ASpell_Movable::ASpell_Movable()
{
    SphereComponent = CreateDefaultSubobject<USphereComponent>(TEXT("Sphere Component"));
    RootComponent = SphereComponent;

    SpellMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("SpellMesh"));
	SpellMesh->SetupAttachment(SphereComponent);

    ProjectileMovementComponent = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("Projectile Movement Component"));
	ProjectileMovementComponent->MaxSpeed = 5000.f;
	ProjectileMovementComponent->InitialSpeed = 5000.f;
	ProjectileMovementComponent->Bounciness = 1;
}

void ASpell_Movable::Cast()
{
    UE_LOG(LogTemp, Warning, TEXT("SPELL_M"));
    UE_LOG(LogTemp, Warning, TEXT("SPELL_M"));
}