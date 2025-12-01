// Copyright Epic Games, Inc. All Rights Reserved.

#include "boydAdventureGameMode.h"
#include "boydAdventureCharacter.h"
#include "UObject/ConstructorHelpers.h"
#include "Facade.h"

AboydAdventureGameMode::AboydAdventureGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
void AboydAdventureGameMode::BeginPlay()
{
	Super::BeginPlay();

	UWorld* World = GetWorld();
	AFacade* Fachada = World->SpawnActor<AFacade>();
	Fachada->InicializarNivel(World);

	
}
