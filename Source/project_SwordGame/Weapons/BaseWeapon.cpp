


#include "BaseWeapon.h"
#include "Components/StaticMeshComponent.h"


ABaseWeapon::ABaseWeapon()
{
	PrimaryActorTick.bCanEverTick = false;

	RootSceneComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
	SetRootComponent(RootSceneComponent);

	WeaponMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("WeaponMesh"));
	WeaponMesh->SetupAttachment(RootSceneComponent);
	WeaponMesh->SetCollisionResponseToAllChannels(ECR_Ignore);
}

void ABaseWeapon::AttachToSocket(USceneComponent* InParent, FName InSocketName)
{
	if (InParent)
	{
		FAttachmentTransformRules AttachmentRules(EAttachmentRule::SnapToTarget, true);
		AttachToComponent(InParent, AttachmentRules, InSocketName);
	}
}


