// Copyright Epic Games, Inc. All Rights Reserved.

#include "PlaygroundGameMode.h"
#include "PlaygroundCharacter.h"
#include "UObject/ConstructorHelpers.h"

APlaygroundGameMode::APlaygroundGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPerson/Blueprints/BP_FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

}
