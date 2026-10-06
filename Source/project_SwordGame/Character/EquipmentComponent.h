

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "EquipmentComponent.generated.h"

class ABaseWeapon;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnWeaponEquipped, ABaseWeapon*, NewWeapon);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class PROJECT_SWORDGAME_API UEquipmentComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UEquipmentComponent();

	UFUNCTION(BlueprintCallable, Category = "Equipment")
	void EquipWeapon(ABaseWeapon* WeaponToEquip, bool bEquipToOffhand = false);

	UFUNCTION(BlueprintCallable, Category = "Equipment")
	ABaseWeapon* GetMainHandWeapon() const { return MainHandWeapon; }

	UFUNCTION(BlueprintCallable, Category = "Equipment")
	ABaseWeapon* GetOffHandWeapon() const { return OffHandWeapon; }
	UPROPERTY(BlueprintAssignable, Category = "Equipment|Events")
	FOnWeaponEquipped OnWeaponEquipped;

protected:
	virtual void BeginPlay() override;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Equipment|State")
	TObjectPtr<ABaseWeapon> MainHandWeapon;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Equipment|State")
	TObjectPtr<ABaseWeapon> OffHandWeapon;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Equipment|Config")
	TSubclassOf<ABaseWeapon> DefaultWeaponClass;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Sockets")
	FName MainHandSocketName = FName("hand_r");
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Sockets")
	FName OffhandSocketName = FName("hand_l");
};
