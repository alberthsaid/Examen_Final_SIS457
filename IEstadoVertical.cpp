// Fill out your copyright notice in the Description page of Project Settings.


#include "IEstadoVertical.h"
#include "Enemigo.h"


// Add default functionality here for any IIEstadoVertical functions that are not pure virtual.
void IIEstadoVertical::TickState(AEnemigo* Enemy, float FloatSpeed, float DeltaTime, FVector GetActorLocation(), float GetGameTimeSinceCreation(), bool SetActorLocation)
{
    PosicionInicial=GetActorLocation();

    FloatSpeed = 50.f;
    bPuedeMoverse = true;

    if (bPuedeMoverse)
    {
        FVector NewLocation = PosicionInicial;
        NewLocation.Z = FMath::Sin(GetGameTimeSinceCreation() * FloatSpeed) * 170.0f + 190.0f;
        SetActorLocation(NewLocation);
    }
}