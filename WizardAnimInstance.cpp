// Fill out your copyright notice in the Description page of Project Settings.


#include "WizardAnimInstance.h"
#include "WizardCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Net/UnrealNetwork.h"

void UWizardAnimInstance::NativeInitializeAnimation()
{
    Super::NativeInitializeAnimation();

    WizardCharacter = Cast<AWizardCharacter>(TryGetPawnOwner());

}

void UWizardAnimInstance::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(UWizardAnimInstance,bIsAiming);
	DOREPLIFETIME(UWizardAnimInstance,bIsMagicChoosing);
	DOREPLIFETIME(UWizardAnimInstance,bIsAlive);
	DOREPLIFETIME(UWizardAnimInstance,bIsDrinking);
}

void UWizardAnimInstance::NativeUpdateAnimation(float DeltaTime)
{
    Super::NativeUpdateAnimation(DeltaTime);

    if(WizardCharacter == nullptr)
    {
        WizardCharacter = Cast<AWizardCharacter>(TryGetPawnOwner());
    }

    if(WizardCharacter == nullptr) return;

    FVector Velocity = WizardCharacter->GetVelocity();
    Velocity.Z = 0.f;
    Speed = Velocity.Size();

    bIsInAir = WizardCharacter->GetCharacterMovement()->IsFalling();
    bIsAiming = WizardCharacter->GetIsAiming();
    bIsMagicChoosing = WizardCharacter->GetIsMagicChoosing();
    bIsAlive = WizardCharacter->GetIsAlive();
    bIsDrinking = WizardCharacter->GetIsDrinking();
    bIsAccelerating = WizardCharacter->GetCharacterMovement()->GetCurrentAcceleration().Size() > 0.f ? true : false;

}