#include "SwordGameModeBase.h"
#include "Character/MainCharacter.h"
#include "Character/Controller/MainPlayerController.h"

ASwordGameModeBase::ASwordGameModeBase()
{
	DefaultPawnClass = AMainCharacter::StaticClass();
	PlayerControllerClass = AMainPlayerController::StaticClass();
}