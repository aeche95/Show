// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/SCharacter.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "EnhancedInputComponent.h"
#include "Components/SInteractionComponent.h"
#include "Components/SAttributeComponent.h"

// Sets default values
ASCharacter::ASCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SpringArm = CreateDefaultSubobject<USpringArmComponent>("SpringArm");
	SpringArm->SetupAttachment(RootComponent);
	SpringArm->bUsePawnControlRotation = true;

	Camera = CreateDefaultSubobject<UCameraComponent>("Camera");
	Camera->SetupAttachment(SpringArm);

	Interaction = CreateDefaultSubobject<USInteractionComponent>(TEXT("Interaction"));

	Attributes = CreateDefaultSubobject<USAttributeComponent>(TEXT("Attributes"));

	bUseControllerRotationYaw = false;

}

// Called when the game starts or when spawned
void ASCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

void ASCharacter::Move(const FInputActionValue& ActionValue)
{
	// Get Value as 2DVector 
	const FVector2D MoveValue = ActionValue.Get<FVector2D>();

	const FRotator MovementRotation(0, Controller->GetControlRotation().Yaw, 0);

	// Forward/Backward direction
	if (MoveValue.Y != 0.f)
	{
		// Get forward vector
		const FVector Direction = MovementRotation.RotateVector(FVector::ForwardVector);

		AddMovementInput(Direction, MoveValue.Y);
	}

	// Right/Left direction
	if (MoveValue.X != 0.f)
	{
		// Get right vector
		const FVector Direction = MovementRotation.RotateVector(FVector::RightVector);

		AddMovementInput(Direction, MoveValue.X);
	}
}

void ASCharacter::Look(const FInputActionValue& ActionValue)
{
	const FVector2D LookValue = ActionValue.Get<FVector2D>();

	//UE_LOG(LogTemp, Log, TEXT("Look value: %s"), *LookValue.ToString());

	if (LookValue.X != 0.f)
	{
		AddControllerYawInput(LookValue.X);
	}

	if (LookValue.Y != 0.f)
	{
		AddControllerPitchInput(LookValue.Y);
	}
}

void ASCharacter::Interact()
{
	if (Interaction)
	{
		Interaction->PrimaryInteract();
	}
}



// Called every frame
void ASCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ASCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	UEnhancedInputComponent* EnhancedInput = Cast<UEnhancedInputComponent>(PlayerInputComponent);

	if (EnhancedInput)
	{
		EnhancedInput->BindAction(InputActions["Move"], ETriggerEvent::Triggered, this, &ASCharacter::Move);
		EnhancedInput->BindAction(InputActions["Look"], ETriggerEvent::Triggered, this, &ASCharacter::Look);
		EnhancedInput->BindAction(InputActions["Interact"], ETriggerEvent::Triggered, this, &ASCharacter::Interact);
		EnhancedInput->BindAction(InputActions["Jump"], ETriggerEvent::Triggered, this, &ACharacter::Jump);
		EnhancedInput->BindAction(InputActions["Attack"], ETriggerEvent::Started, this, &ASCharacter::PrimaryAttack);
	}
}

void ASCharacter::PrimaryAttack()
{
	ensure(ProjectileClass);
	PlayAnimMontage(AttackAnim);

	FVector Location = GetMesh()->GetSocketLocation("Muzzle_01");

	FTransform SpawnTransform = FTransform(GetControlRotation(), Location);

	FActorSpawnParameters Params;
	Params.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
	Params.Instigator = this;

	GetWorld()->SpawnActor<AActor>(ProjectileClass, SpawnTransform,Params);
}

