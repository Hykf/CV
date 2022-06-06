

#include "WizardCharacter.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Components/WidgetComponent.h"
#include "Net/UnrealNetwork.h"
#include "DrawDebugHelpers.h"
#include "Components/SceneComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/PlayerController.h"
#include "GameFramework/Character.h"

AWizardCharacter::AWizardCharacter()
{
	PrimaryActorTick.bCanEverTick = true;
	SMesh = GetMesh();

	CurrentHealth = MaxHealth;
	CurrentMana = MaxMana;
	
	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("Spring arm"));
	SpringArm->SetupAttachment(RootComponent);
	SpringArm->TargetArmLength = 600.f;
	SpringArm->bUsePawnControlRotation = true;

	StaffMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Staff Mesh"));
	StaffMesh->SetupAttachment(SMesh,TEXT("Weapon"));

	MagicSpawnPoint = CreateDefaultSubobject<USceneComponent>(TEXT("Spell Spawn Mesh"));
	MagicSpawnPoint->SetupAttachment(StaffMesh);
	MagicSpawnPoint->SetupAttachment(StaffMesh);

	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("Follow Camera"));
	FollowCamera->SetupAttachment(SpringArm,USpringArmComponent::SocketName);
	FollowCamera->bUsePawnControlRotation = false;



	bUseControllerRotationYaw = false;
	GetCharacterMovement()->bOrientRotationToMovement = true;

}

//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&& OVERRIDED &&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&

void AWizardCharacter::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	 DOREPLIFETIME(AWizardCharacter,bIsAiming);
	 DOREPLIFETIME(AWizardCharacter,bIsMagicChoosing);
	 DOREPLIFETIME(AWizardCharacter,bIsAlive);
	 DOREPLIFETIME(AWizardCharacter,bIsDrinking);
}

void AWizardCharacter::BeginPlay()
{
	Super::BeginPlay();
	
	CurrentHealth = MaxHealth;
	CurrentMana = MaxMana;

	PlayerControllerRef = Cast<APlayerController>(GetController());

}

void AWizardCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if(CurrentHealth<=0)
	{
		SetIsAlive(false);
	} 
	



}

void AWizardCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	//PlayerInputComponent->BindAction("EngineInputNazwa",IE_Pressed/IE_Released,co_this,&AWizardCharacter::NazwaFunkcji);
	PlayerInputComponent->BindAction("Jump",IE_Pressed,this,&AWizardCharacter::Jump);

	PlayerInputComponent->BindAction("Shoot-R",IE_Pressed,this,&AWizardCharacter::StartCasting);
	PlayerInputComponent->BindAction("Shoot-L",IE_Pressed,this,&AWizardCharacter::StartCasting);
	PlayerInputComponent->BindAction("Magic",IE_Pressed,this,&AWizardCharacter::SelectMagicP);
	PlayerInputComponent->BindAction("Drink",IE_Pressed,this,&AWizardCharacter::StartDrinking);



	PlayerInputComponent->BindAction("Shoot-R",IE_Released,this,&AWizardCharacter::ShootR);
	PlayerInputComponent->BindAction("Shoot-L",IE_Released,this,&AWizardCharacter::ShootL);
	PlayerInputComponent->BindAction("Magic",IE_Released,this,&AWizardCharacter::SelectMagicR);
	PlayerInputComponent->BindAction("Drink",IE_Released,this,&AWizardCharacter::StopDrinking);

	//Ciagle
	
	PlayerInputComponent->BindAxis("MoveForward",this,&AWizardCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight",this,&AWizardCharacter::MoveRight);
	

	PlayerInputComponent->BindAxis("Turn",this,&AWizardCharacter::Turn);
	PlayerInputComponent->BindAxis("LookUp",this,&AWizardCharacter::LookUp);


}

//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&& OVERRIDED &&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&

// ################################ MOVEMENT ######################## 
void AWizardCharacter::MoveForward(float Value)
{
	if(bIsAiming == false && bIsMagicChoosing == false && bIsAlive == true)
	{
		if(Controller !=nullptr && Value!=0.f)
		{
			const FRotator YawRotation(0.f , Controller->GetControlRotation().Yaw,0.f);
			const FVector Direction( FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X));
			AddMovementInput(Direction,Value);
		}
	}
}
void AWizardCharacter::MoveRight(float Value)
{
	if(bIsAiming == false && bIsMagicChoosing == false && bIsAlive == true)
	{
		if(Controller !=nullptr && Value!=0.f)
		{
			const FRotator YawRotation(0.f , Controller->GetControlRotation().Yaw ,0.f);
			const FVector Direction( FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y));
			AddMovementInput(Direction,Value);
		}
	}
}

void AWizardCharacter::Turn(float Value)
{
	if(bIsMagicChoosing == false)
	{
		AddControllerYawInput(Value);
	}
	
}

void AWizardCharacter::LookUp(float Value)
{
	if(bIsMagicChoosing == false)
	{
		AddControllerPitchInput(Value);
	}
}

// ################################ MOVEMENT ######################## 


// $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$ COMBAT $$$$$$$$$$$$$$$$$$$$$$$$$$
void AWizardCharacter::ShootL() // Fast Shoot
{
	if(bIsAiming)
	{
		SetAiming(false);
		UE_LOG(LogTemp,Warning,TEXT("The boolean value is %s"), ( bIsAiming ? TEXT("") : TEXT("Strzeliles LEWO") ));
		SpringArm->TargetArmLength = 600.f;
		GetCharacterMovement()->bOrientRotationToMovement = true;
		bUseControllerRotationYaw = false;	
		ZoomOut();
	}
}

void AWizardCharacter::ShootR() //Casting Shoot
{
	if(bIsAiming)
	{
		SetAiming(false);
		UE_LOG(LogTemp,Warning,TEXT("The boolean value is %s"), ( bIsAiming ? TEXT("") : TEXT("Strzeliles PRAWO") ));
		SpringArm->TargetArmLength = 600.f;
		GetCharacterMovement()->bOrientRotationToMovement = true;
		bUseControllerRotationYaw = false;
		ZoomOut();

		FVector Location = MagicSpawnPoint->GetComponentLocation();
		FRotator Rotation = MagicSpawnPoint->GetComponentRotation();

	}
}


void AWizardCharacter::SelectMagicR() //released
{
	SetIsMagicChoosing(false);
	UE_LOG(LogTemp,Warning,TEXT("RELEASED"));
}

void AWizardCharacter::SelectMagicP() //pressed
{
	SetIsMagicChoosing(true); 
	UE_LOG(LogTemp,Warning,TEXT("PRESSED"));
}
//GETERY

void AWizardCharacter::StartCasting() 
{
	bool bIsInAir = GetCharacterMovement()->IsFalling();
	

	if(bIsInAir == false && bIsMagicChoosing == false && bIsAlive == true){
		//ZoomIn(80); // Maybe in lightning spell only ? 

		FHitResult HitResult;
		FVector Location;
		FRotator Rotation;
		GetController()->GetPlayerViewPoint(Location,Rotation);

		PlayerControllerRef->GetHitResultUnderCursor(ECollisionChannel::ECC_Visibility,false,HitResult);
		SetAiming(true);
		//SpringArm->TargetArmLength = 150.f; // Maybe in lightning spell only ? 
		bUseControllerRotationYaw = true;

	}
}

void AWizardCharacter::StartDrinking() //PRESS R
{
	bIsDrinking = true;
}

void AWizardCharacter::StopDrinking() //RELEASE R
{
	bIsDrinking = false;
}

void AWizardCharacter::ZoomIn(float zoom)
{

  UWorld *World = GetWorld();
  const float CurrentFOV = FollowCamera->FieldOfView;
  const float InterpSpeed = 2.0f;
  FollowCamera->FieldOfView = FMath::FInterpTo(CurrentFOV, zoom, World->GetTimeSeconds(),InterpSpeed);
    
}

void AWizardCharacter::ZoomOut()
{
  UWorld *World = GetWorld();
  const float CurrentFOV = FollowCamera->FieldOfView;
  const float InterpSpeed = 2.0f;
  FollowCamera->FieldOfView = FMath::FInterpTo(CurrentFOV, 90.0f, World->GetTimeSeconds(),InterpSpeed);
}

// $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$ COMBAT $$$$$$$$$$$$$$$$$$$$$$$$$$

// GETERY 


bool AWizardCharacter::GetIsDrinking()
{
	return bIsDrinking;
}

bool AWizardCharacter::GetCondition()
{
	return false; //isAlive && isJumping// cos jeszcze?
}

bool AWizardCharacter::GetIsAiming()
{
	return bIsAiming;
}

bool AWizardCharacter::GetIsMagicChoosing()
{
	return bIsMagicChoosing;
}

bool AWizardCharacter::GetIsAlive()
{
	return bIsAlive;
}

void AWizardCharacter::SetAiming(bool BiSAim)
{
	bIsAiming = BiSAim;
	ServerSetAiming(bIsAiming);
}

void AWizardCharacter::SetIsMagicChoosing(bool bIsMagic)
{
	bIsMagicChoosing = bIsMagic;
	ServerSetIsMagicChoosing(bIsMagicChoosing);
}

void AWizardCharacter::SetIsAlive(bool bIsA)
{
	bIsAlive = bIsA;
	ServerSetIsAlive(bIsAlive);
}

void AWizardCharacter::ServerSetIsMagicChoosing_Implementation(bool bIsMagic)
{
	bIsMagicChoosing = bIsMagic;
}

void AWizardCharacter::ServerSetIsAlive_Implementation(bool bIsA)
{
	bIsAlive = bIsA;
}

void AWizardCharacter::ServerSetAiming_Implementation(bool bIsAim)
{
	bIsAiming = bIsAim;
}

