

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BaseWeapon.generated.h"

UCLASS()
class PROJECT_SWORDGAME_API ABaseWeapon : public AActor
{
	GENERATED_BODY()
	
public:	
	ABaseWeapon();
	void AttachToSocket(USceneComponent* InParent, FName InSocketName);
	UFUNCTION(BlueprintCallable, Category = "Weapon")
	float GetBaseDamage() const { return BaseDamage; }
protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	TObjectPtr<USceneComponent> RootSceneComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	TObjectPtr<UStaticMeshComponent> WeaponMesh; 

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Weapon Stats")
	float BaseDamage = 25.0f;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Weapon Stats")
	float AttackSpeed = 1.0f;

};
