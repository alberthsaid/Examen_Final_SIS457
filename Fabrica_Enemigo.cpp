// Fill out your copyright notice in the Description page of Project Settings.


#include "Fabrica_Enemigo.h"
#include "Enemigo_Acuatico.h"
#include "Enemigo_Aereo.h"
#include "Enemigo_Anfibio.h"
#include "Enemigo_Terrestre.h"

class AEnemigo;
// Sets default values
AEnemigo* UFabrica_Enemigo::CrearEnemigo(UWorld* World, int TipoEnemigo, FVector Posicion, FRotator Rotacion)
{
    if (!World) return nullptr;

    TSubclassOf<AEnemigo> ClaseEnemigo = nullptr;

    switch (TipoEnemigo)
    {
    case 0:
        ClaseEnemigo = AEnemigo_Acuatico::StaticClass();
        break;
    case 1:
        ClaseEnemigo = AEnemigo_Aereo::StaticClass();
        break;
    case 2:
        ClaseEnemigo = AEnemigo_Anfibio::StaticClass();
        break;
    case 3:
        ClaseEnemigo = AEnemigo_Terrestre::StaticClass();
        break;

    default:
        UE_LOG(LogTemp, Warning, TEXT("Tipo de bloque inválido: %d"), TipoEnemigo);
        return nullptr;
    }

    return World->SpawnActor<AEnemigo>(ClaseEnemigo, Posicion, FRotator::ZeroRotator);
}