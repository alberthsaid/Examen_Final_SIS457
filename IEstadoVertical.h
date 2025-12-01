// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "IEstadoVertical.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UIEstadoVertical : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class BOYDADVENTURE_API IIEstadoVertical
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	virtual void TickState(AEnemigo* Enemy, float FloatSpeed, float DeltaTime, FVector GetActorLocation(), float GetGameTimeSinceCreation(), bool SetActorLocation) =0;
	FVector PosicionInicial;
	bool bPuedeMoverse;
	float FloatSpeed;

};
