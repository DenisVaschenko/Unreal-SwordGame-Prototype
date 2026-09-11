


#include "BaseCharacter.h"

ABaseCharacter::ABaseCharacter()
{
	PrimaryActorTick.bCanEverTick = true;

}
void ABaseCharacter::TakeDamage(float DamageAmount, FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser)
{
	Super::TakeDamage(DamageAmount, DamageEvent, EventInstigator, DamageCauser);
	Health -= DamageAmount;
	if (Health <= 0.0f)
	{
		bIsDead = true;
	}
}



