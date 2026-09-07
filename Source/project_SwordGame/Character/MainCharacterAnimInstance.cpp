#include "MainCharacterAnimInstance.h"
#include "MainCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"

void UMainCharacterAnimInstance::NativeInitializeAnimation()
{
	Super::NativeInitializeAnimation();
	MainCharacter = Cast<AMainCharacter>(TryGetPawnOwner());
	if (MainCharacter)
	{
		MovementComponent = MainCharacter->GetCharacterMovement();
	}
}

void UMainCharacterAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);
	if (!MainCharacter || !MovementComponent)
	{
		return;
	}
	GroundSpeed = MovementComponent->Velocity.Size2D();
	bIsInAir = MovementComponent->IsFalling();
	bIsAccelerating = MovementComponent->GetCurrentAcceleration().Size() > 0.0f;
}