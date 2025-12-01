// Fill out your copyright notice in the Description page of Project Settings.


#include "IEstadoHorizontal.h"
#include "Enemigo.h"

// Add default functionality here for any IIEstadoHorizontal functions that are not pure virtual.
void IIEstadoHorizontal::TickState(AEnemigo* Enemy, float FloatSpeed, float DeltaTime, FVector GetActorLocation(), float GetGameTimeSinceCreation(), bool SetActorLocation)
{
    PosicionInicial=GetActorLocation();
	FloatSpeed = 100.f;
	bPuedeMoverse = true;
	if (bPuedeMoverse)
	{
		float Speed = 50.f;
		FVector NewLocation = PosicionInicial;
		NewLocation.X = PosicionInicial.X + FMath::Sin(GetGameTimeSinceCreation() * FloatSpeed) * 100.0f;
		SetActorLocation(NewLocation);
	}
}