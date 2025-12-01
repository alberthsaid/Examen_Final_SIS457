// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "boydAdventureGameMode.generated.h"

UCLASS(minimalapi)
class AboydAdventureGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	AboydAdventureGameMode();
protected:
	virtual void BeginPlay() override;
};



