
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Spell.h"
#include "Spell_Movable.h"
#include "Spell_Immovable.h"
#include "WizardCharacter.generated.h"


UCLASS()
class CV_WIZARD_API AWizardCharacter : public ACharacter
{
	GENERATED_BODY()

friend class UWizardAnimInstance;

public:
	AWizardCharacter(); 
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite,Category="Magic",meta = (AllowPrivateAccess = "true"))
	USceneComponent* MagicSpawnPoint;

	UPROPERTY(EditAnywhere, BlueprintReadWrite,Category="Magic",meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* StaffMesh;

	USkeletalMeshComponent* SMesh;

protected:
	virtual void BeginPlay() override;

	void MoveRight(float Value);
	void MoveForward(float Value);
	void Turn(float Value);
	void LookUp(float Value);

	UFUNCTION(BlueprintCallable, Category="Casting")
	void ShootL();
	UFUNCTION(BlueprintCallable, Category="Casting")
	void ShootR();
	UFUNCTION(BlueprintCallable, Category="Casting")
	void StartCasting();

	UFUNCTION(BlueprintCallable, Category="Casting")
	void StartDrinking();

	UFUNCTION(BlueprintCallable, Category="Casting")
	void StopDrinking();

	void SelectMagicP();
	UFUNCTION(BlueprintCallable, Category="Casting")
	void SelectMagicR();

	bool GetIsAiming();

	bool GetIsMagicChoosing();

	bool GetIsAlive();

	bool GetIsDrinking();

	bool GetCondition();

	void ZoomIn(float zoom);
	void ZoomOut();

	UFUNCTION(Server,Reliable) 
	void ServerSetAiming(bool bIsAim);

	UFUNCTION(Server,Reliable) 
	void ServerSetIsMagicChoosing(bool bIsMagic);

	UFUNCTION(Server,Reliable) 
	void ServerSetIsAlive(bool bIsMagic);

	void SetAiming(bool bIsAim);

	void SetIsMagicChoosing(bool bIsMagic);

	void SetIsAlive(bool bIsA);

	UPROPERTY(VisibleAnywhere,BlueprintReadOnly,Replicated,Category = "Combat",meta = (AllowPrivateAccess = "true"))
	bool bIsAiming = false;

	UPROPERTY(VisibleAnywhere,BlueprintReadOnly,Replicated,Category = "Combat")
	bool bIsMagicChoosing = false;

	UPROPERTY(EditAnywhere,BlueprintReadWrite,Replicated,Category = "Combat")
	bool bIsAlive = true;

	UPROPERTY(EditAnywhere,BlueprintReadWrite,Replicated,Category = "Combat")
	bool bIsDrinking = false;

private:
	UPROPERTY(VisibleAnywhere,BlueprintReadWrite ,Category="Magic",meta = (AllowPrivateAccess = "true"))
	float Spell1_Id;

	UPROPERTY(VisibleAnywhere,BlueprintReadWrite ,Category="Magic",meta = (AllowPrivateAccess = "true"))
	float Spell2_Id;

	UPROPERTY(VisibleAnywhere,Category="Stats")
	float MaxHealth = 100;

	UPROPERTY(VisibleAnywhere,BlueprintReadWrite ,Category="Stats",meta = (AllowPrivateAccess = "true"))
	float CurrentHealth;

	UPROPERTY(VisibleAnywhere,Category="Stats")
	float MaxMana = 150;

	UPROPERTY(VisibleAnywhere,BlueprintReadWrite ,Category="Stats",meta = (AllowPrivateAccess = "true"))
	float CurrentMana;

	UPROPERTY(VisibleAnywhere,BlueprintReadWrite ,Category="Stats",meta = (AllowPrivateAccess = "true"))
	bool Stunned;

	UPROPERTY(VisibleAnywhere,BlueprintReadWrite ,Category="Stats",meta = (AllowPrivateAccess = "true"))
	bool Dot;

	UPROPERTY(VisibleAnywhere,Category="Camera")
	class USpringArmComponent* SpringArm; 

	UPROPERTY(VisibleAnywhere,Category="Camera")
	class UCameraComponent* FollowCamera;

	APlayerController* PlayerControllerRef;

	UPROPERTY(VisibleAnywhere,BlueprintReadWrite ,Category="Magic",meta = (AllowPrivateAccess = "true"))
	FString Spell1_Text;

	UPROPERTY(VisibleAnywhere,BlueprintReadWrite ,Category="Magic",meta = (AllowPrivateAccess = "true"))
	FString Spell2_Text;

	UPROPERTY(EditAnywhere,BlueprintReadWrite ,Category="Magic",meta = (AllowPrivateAccess = "true"))//
	TSubclassOf<ASpell_Movable> MovableSpellClass;

	UPROPERTY(EditAnywhere,BlueprintReadWrite ,Category="Magic",meta = (AllowPrivateAccess = "true"))
	TSubclassOf<ASpell_Immovable> ImmovableSpellClass;
};
