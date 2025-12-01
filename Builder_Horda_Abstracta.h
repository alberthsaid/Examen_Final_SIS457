// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Builder_Horda_Abstracta.generated.h"
class AEnemigo;
UCLASS()
class BOYDADVENTURE_API ABuilder_Horda_Abstracta : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABuilder_Horda_Abstracta();


	FVector posicionSiguienteEnemigo = FVector(1000.0f, 500.0f, 20.0f);
	TArray<TArray<int32>> aEscuadraEnemigo;
	TArray<AEnemigo*> aEnemigos;
	float XInicial = -2500.00f;
	float YInicial = -2500.00f;
	float AnchoEnemigo = 100.0f;
	float LargoEnemigo = 100.0f;
	AEnemigo* EnemigoActual = nullptr;
	TArray<FVector> aEspaciosVacios;
	virtual void ConstruirHorda()PURE_VIRTUAL(ABuilder_Horda_Abstracta::ConstruirHorda, );


};
