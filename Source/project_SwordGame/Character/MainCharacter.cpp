#include "MainCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"

AMainCharacter::AMainCharacter()
{
	PrimaryActorTick.bCanEverTick = false;

}

void AMainCharacter::BeginPlay()
{
	Super::BeginPlay();

	GetCharacterMovement()->MaxWalkSpeed = 450.f;
	GetCharacterMovement()->BrakingDecelerationWalking = 2000.0f; 
	GetCharacterMovement()->AirControl = 0.35f;    
	GetCharacterMovement()->JumpZVelocity = 400.0f;
}


