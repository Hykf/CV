// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "WizardAnimInstance.generated.h"

/**
 * 
 */
UCLASS()
class CV_WIZARD_API UWizardAnimInstance : public UAnimInstance
{
	GENERATED_BODY()

	virtual void NativeInitializeAnimation() override;
	virtual void NativeUpdateAnimation(float DeltaTime) override;
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

private:

	UPROPERTY(BlueprintReadOnly,Category=Character,meta=(AllowPrivateAccess ="true"))
	class AWizardCharacter* WizardCharacter;

	UPROPERTY(BlueprintReadOnly,Category=Movement,meta=(AllowPrivateAccess ="true"))
	float Speed;

	UPROPERTY(BlueprintReadOnly,Category=Movement,meta=(AllowPrivateAccess ="true"))
	bool bIsInAir;

	UPROPERTY(BlueprintReadOnly,Category=Movement,meta=(AllowPrivateAccess ="true"))
	bool bIsAccelerating;

	UPROPERTY(BlueprintReadOnly,Replicated,Category=Movement,meta=(AllowPrivateAccess ="true"))
	bool bIsAiming;

	UPROPERTY(BlueprintReadOnly,Replicated,Category=Movement,meta=(AllowPrivateAccess ="true"))
	bool bIsDrinking;

	UPROPERTY(BlueprintReadOnly,Replicated,Category=Movement,meta=(AllowPrivateAccess ="true"))
	bool bIsMagicChoosing;

	UPROPERTY(BlueprintReadOnly,Replicated,Category=Movement,meta=(AllowPrivateAccess ="true"))
	bool bIsAlive;


};
