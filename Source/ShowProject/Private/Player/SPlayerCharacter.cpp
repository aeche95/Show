// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/SPlayerCharacter.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "EnhancedInputComponent.h"
#include "Components/SInteractionComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "SPlayerState.h"
#include "AbilitySystemComponent.h"

// Sets default values
ASPlayerCharacter::ASPlayerCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SpringArm = CreateDefaultSubobject<USpringArmComponent>("SpringArm");
	SpringArm->SetupAttachment(RootComponent);
	SpringArm->bUsePawnControlRotation = true;

	Camera = CreateDefaultSubobject<UCameraComponent>("Camera");
	Camera->SetupAttachment(SpringArm);

	Interaction = CreateDefaultSubobject<USInteractionComponent>(TEXT("Interaction"));

	GetCharacterMovement()->bOrientRotationToMovement = true;

	bUseControllerRotationYaw = false;

}

void ASPlayerCharacter::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);
	InitAbilityActorInfo();
}

void ASPlayerCharacter::OnRep_PlayerState()
{
	Super::OnRep_PlayerState();
	InitAbilityActorInfo();
}

// Called when the game starts or when spawned
void ASPlayerCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASPlayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ASPlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	UEnhancedInputComponent* EnhancedInput = Cast<UEnhancedInputComponent>(PlayerInputComponent);

	if (EnhancedInput)
	{
		EnhancedInput->BindAction(InputActions["Move"], ETriggerEvent::Triggered, this, &ASPlayerCharacter::Move);
		EnhancedInput->BindAction(InputActions["Look"], ETriggerEvent::Triggered, this, &ASPlayerCharacter::Look);
		EnhancedInput->BindAction(InputActions["Interact"], ETriggerEvent::Triggered, this, &ASPlayerCharacter::Interact);
		EnhancedInput->BindAction(InputActions["Jump"], ETriggerEvent::Triggered, this, &ACharacter::Jump);
		EnhancedInput->BindAction(InputActions["Attack"], ETriggerEvent::Started, this, &ASPlayerCharacter::PrimaryAttack);
	}
}

void ASPlayerCharacter::InitAbilityActorInfo()
{
	ASPlayerState* SPlayerState = GetPlayerState<ASPlayerState>();
	check(SPlayerState);
	SPlayerState->GetAbilitySystemComponent()->InitAbilityActorInfo(SPlayerState, this);
	AbilitySystemComponent = SPlayerState->GetAbilitySystemComponent();
	AttributeSet = SPlayerState->GetAttributeSet();
}

void ASPlayerCharacter::Move(const FInputActionValue& ActionValue)
{
	// Get Value as 2DVector 
	const FVector2D MoveValue = ActionValue.Get<FVector2D>();

	const FRotator MovementRotation(0, GetControlRotation().Yaw, 0);

	// Forward/Backward direction
	if (MoveValue.Y != 0.f)
	{
		
		AddMovementInput(MovementRotation.Vector(), MoveValue.Y);
		
	}

	// Right/Left direction
	if (MoveValue.X != 0.f)
	{
		FVector RightVector = FRotationMatrix(MovementRotation).GetScaledAxis(EAxis::Y);
		AddMovementInput(RightVector, MoveValue.X);
	}
	
}

void ASPlayerCharacter::Look(const FInputActionValue& ActionValue)
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

void ASPlayerCharacter::Interact()
{
	if (Interaction)
	{
		Interaction->PrimaryInteract();
	}
}

void ASPlayerCharacter::PrimaryAttack()
{
	ensure(ProjectileClass);
	PlayAnimMontage(AttackAnim);

	GetWorldTimerManager().SetTimer(TimerHandle_PrimaryAttack, this, &ASPlayerCharacter::PrimaryAttack_TimerElapsed, 0.2f);
}

void ASPlayerCharacter::PrimaryAttack_TimerElapsed()
{
	SpawnProjectile(ProjectileClass);
}

void ASPlayerCharacter::SpawnProjectile(TSubclassOf<AActor> ClassToSpawn)
{
	FVector Location = GetMesh()->GetSocketLocation("Muzzle_01");
	FActorSpawnParameters SpawnParams;
	SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
	SpawnParams.Instigator = this;

	FCollisionShape Shape;
	Shape.SetSphere(20.0f);

	FCollisionQueryParams Params;
	Params.AddIgnoredActor(this);

	FCollisionObjectQueryParams ObjParams;
	ObjParams.AddObjectTypesToQuery(ECC_WorldDynamic);
	ObjParams.AddObjectTypesToQuery(ECC_WorldStatic);
	ObjParams.AddObjectTypesToQuery(ECC_Pawn);

	FVector TraceStart = Camera->GetComponentLocation();
	FVector TraceEnd = Camera->GetComponentLocation() + (GetControlRotation().Vector() * 5000.0f);
	FHitResult Hit;

	if (GetWorld()->SweepSingleByObjectType(Hit, TraceStart, TraceEnd, FQuat::Identity, ObjParams, Shape, Params))
	{
		TraceEnd = Hit.ImpactPoint;
	}

	FRotator ProjRotation = FRotationMatrix::MakeFromX(TraceEnd - Location).Rotator();
	FTransform SpawnTransform = FTransform(ProjRotation, Location);
	GetWorld()->SpawnActor<AActor>(ClassToSpawn, SpawnTransform, SpawnParams);
}



