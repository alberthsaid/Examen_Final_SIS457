// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Fabrica_Enemigo.generated.h"
class AEnemigo;

UCLASS()
class BOYDADVENTURE_API UFabrica_Enemigo : public UObject
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFabrica_Enemigo();

	AEnemigo* CrearEnemigo(UWorld* World, int TipoEnemigo, FVector Posicion, FRotator ZeroRotator);

};
