// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "IEstado_Cubo.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UIEstado_Cubo : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class BOYDADVENTURE_API IIEstado_Cubo
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	virtual void AState(AEnemigo* Enemy) =0;
};
