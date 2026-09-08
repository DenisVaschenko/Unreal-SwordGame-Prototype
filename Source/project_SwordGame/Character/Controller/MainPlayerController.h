

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "MainPlayerController.generated.h"

/**
 * 
 */
class UInputMappingContext;
class UInputAction;
struct FInputActionValue;
UCLASS()
class PROJECT_SWORDGAME_API AMainPlayerController : public APlayerController
{
	GENERATED_BODY()
	void BeginPlay() override;
	virtual void SetupInputComponent() override;
protected:
	UPROPERTY(EditDefaultsOnly, Category = "Input")
	UInputMappingContext* MappingContext;
	UPROPERTY(EditDefaultsOnly, Category = "Input")
	UInputAction* MoveAction;
	UPROPERTY(EditDefaultsOnly, Category = "Input")
	UInputAction* JumpAction;
	UPROPERTY(EditDefaultsOnly, Category = "Input")
	UInputAction* RotateAction;
	UPROPERTY(EditDefaultsOnly, Category = "Input")
	UInputAction* SprintAction;
public:
	void Move(const FInputActionValue& Value);
	void Rotate(const FInputActionValue& Value);
	void Jump(const FInputActionValue& Value);
	void StartSprint();
	void StopSprint();

};
