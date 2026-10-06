


#include "EquipmentComponent.h"
#include "../Weapons/BaseWeapon.h"
#include "GameFramework/Character.h"


UEquipmentComponent::UEquipmentComponent()
{
	PrimaryComponentTick.bCanEverTick = false;

}


void UEquipmentComponent::BeginPlay()
{
	Super::BeginPlay();
	if (DefaultWeaponClass)
	{
		FActorSpawnParameters SpawnParams;
		SpawnParams.Owner = GetOwner();
		SpawnParams.Instigator = Cast<APawn>(GetOwner());

		ABaseWeapon* NewWeapon = GetWorld()->SpawnActor<ABaseWeapon>(DefaultWeaponClass, SpawnParams);
		EquipWeapon(NewWeapon);
	}
}

void UEquipmentComponent::EquipWeapon(ABaseWeapon* WeaponToEquip, bool bEquipToOffhand)
{
	if (!WeaponToEquip) return;

	ACharacter* OwnerCharacter = Cast<ACharacter>(GetOwner());
	if (!OwnerCharacter) return;

	FName TargetSocket = bEquipToOffhand ? OffhandSocketName : MainHandSocketName;

	WeaponToEquip->AttachToSocket(OwnerCharacter->GetMesh(), TargetSocket);

	OnWeaponEquipped.Broadcast(WeaponToEquip);
}


