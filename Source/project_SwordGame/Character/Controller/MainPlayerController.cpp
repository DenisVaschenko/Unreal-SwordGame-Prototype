#include "MainPlayerController.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
#include "InputActionValue.h"
#include "../MainCharacter.h"

void AMainPlayerController::BeginPlay()
{
	Super::BeginPlay();
	if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
	{
		Subsystem->AddMappingContext(MappingContext, 0);
	}
}
void AMainPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();
	if (UEnhancedInputComponent* EnhancedInput = Cast<UEnhancedInputComponent>(InputComponent)) {
		EnhancedInput->BindAction(MoveAction, ETriggerEvent::Triggered, this, &AMainPlayerController::Move);
		EnhancedInput->BindAction(RotateAction, ETriggerEvent::Triggered, this, &AMainPlayerController::Rotate);
		EnhancedInput->BindAction(JumpAction, ETriggerEvent::Started, this, &AMainPlayerController::Jump);
	}
}
void AMainPlayerController::Move(const FInputActionValue& Value)
{
	if (APawn* ControlledPawn = GetPawn())
	{
		FVector2D MovementVector = Value.Get<FVector2D>();

		const FRotator ControlRot = GetControlRotation();
		const FRotator YawRotation(0.f, ControlRot.Yaw, 0.f);

		const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
		const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

		ControlledPawn->AddMovementInput(ForwardDirection, MovementVector.X);
		ControlledPawn->AddMovementInput(RightDirection, MovementVector.Y);
	}
}
void AMainPlayerController::Rotate(const FInputActionValue& Value)
{
	const FVector2D RotationVector = Value.Get<FVector2D>();

	AddYawInput(RotationVector.X);
	AddPitchInput(RotationVector.Y);
}
void AMainPlayerController::Jump(const FInputActionValue& Value)
{
	if (ACharacter* ControlledPawn = Cast<ACharacter>(GetPawn()))
	{
		ControlledPawn->Jump();
	}
}

