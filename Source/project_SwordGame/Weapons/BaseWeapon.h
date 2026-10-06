

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BaseWeapon.generated.h"

UENUM(BlueprintType)
enum class EWeaponHandSlot : uint8
{
	RightHand    UMETA(DisplayName = "Right Hand"),
	LeftHand     UMETA(DisplayName = "Left Hand"),
	TwoHanded    UMETA(DisplayName = "Two-Handed"),
	EitherHand   UMETA(DisplayName = "Either Hand (One-Handed)")
};

UCLASS()
class PROJECT_SWORDGAME_API ABaseWeapon : public AActor
{
	GENERATED_BODY()
	
public:	
	ABaseWeapon();
	void AttachToSocket(USceneComponent* InParent, FName InSocketName);
	UFUNCTION(BlueprintCallable, Category = "Weapon")
	float GetBaseDamage() const { return BaseDamage; }

	FORCEINLINE EWeaponHandSlot GetHandSlot() const { return HandSlot; }
protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	TObjectPtr<USceneComponent> RootSceneComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	TObjectPtr<UStaticMeshComponent> StaticMesh; 

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	TObjectPtr<USkeletalMeshComponent> SkeletalMesh;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Weapon Stats")
	float BaseDamage = 25.0f;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Weapon Stats")
	float AttackSpeed = 1.0f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Weapon Configuration")
	EWeaponHandSlot HandSlot = EWeaponHandSlot::RightHand;

};
