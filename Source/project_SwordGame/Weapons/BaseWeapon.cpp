


#include "BaseWeapon.h"
#include "Components/StaticMeshComponent.h"


ABaseWeapon::ABaseWeapon()
{
	PrimaryActorTick.bCanEverTick = false;

	RootSceneComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
	SetRootComponent(RootSceneComponent);

	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("WeaponMesh"));
	StaticMesh->SetupAttachment(RootSceneComponent);
	StaticMesh->SetCollisionResponseToAllChannels(ECR_Ignore);

	SkeletalMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("SkeletalMesh"));
	SkeletalMesh->SetupAttachment(RootSceneComponent);
	SkeletalMesh->SetCollisionResponseToAllChannels(ECR_Ignore);
}

void ABaseWeapon::AttachToSocket(USceneComponent* InParent, FName InSocketName)
{
	if (InParent)
	{
		FAttachmentTransformRules AttachmentRules(EAttachmentRule::SnapToTarget, true);
		AttachToComponent(InParent, AttachmentRules, InSocketName);
	}
}


