// Fill out your copyright notice in the Description page of Project Settings.


#include "Builder_Horda_Concreta.h"
#include "Fabrica_Enemigo.h"
#include "Enemigo_Acuatico.h"
#include "Enemigo_Aereo.h"
#include "Enemigo_Anfibio.h"
#include "Enemigo_Terrestre.h"
#include "Enemigo.h"

// Sets default values
ABuilder_Horda_Concreta::ABuilder_Horda_Concreta()
{
	GEngine->AddOnScreenDebugMessage(-1, -1, FColor::Red, TEXT("Enemigo Spawning"));
	// Inicializar la Escuadra
	aEscuadraEnemigo.SetNum(50);
	for (int32 i = 0; i < 50; i++) {
		aEscuadraEnemigo[i].SetNum(50);
	}
	//se encarga de generar aunquesea  un enemigo
	for (int32 tipo = 0; tipo <= 3; ++tipo)
	{
		int32 fila = FMath::RandRange(1, 38);
		int32 columna = FMath::RandRange(1, 38);

		// Si ya hay un bloque distinto de 0, busca otra posición
		while (aEscuadraEnemigo[fila][columna] != 0)
		{
			fila = FMath::RandRange(1, 38);
			columna = FMath::RandRange(1, 38);
		}

		aEscuadraEnemigo[fila][columna] = tipo;
	}
	for (int32 i = 1; i <= 180; ++i)
	{

		int32 fila = FMath::RandRange(1, 38);
		int32 columna = FMath::RandRange(1, 38);
		int32 tipo = FMath::RandRange(0, 3); // Genera un número aleatorio entre 0 y 3

		// Si ya hay un bloque distinto de 0, busca otra posición
		while (aEscuadraEnemigo[fila][columna] != 0)
		{
			fila = FMath::RandRange(1, 38);
			columna = FMath::RandRange(1, 38);
		}

		aEscuadraEnemigo[fila][columna] = tipo;
	}
}
void ABuilder_Horda_Concreta::ConstruirHorda()
{
	UFabrica_Enemigo* Fabrica = NewObject<UFabrica_Enemigo>();


	// Recorremos la matriz para generar los Enemigos
	for (int32 fila = 0; fila < aEscuadraEnemigo.Num(); ++fila)
	{
		for (int32 columna = 0; columna < aEscuadraEnemigo[fila].Num(); ++columna)
		{

			int32 valor = aEscuadraEnemigo[fila][columna];
			// Calculamos la posición del Enemigo

			FVector posicionEnemigo = FVector(
				XInicial + columna * AnchoEnemigo,
				YInicial + fila * LargoEnemigo,
				20.0f); // Z queda en 0 (altura del Enemigo)
			if (valor == 0) // Si es espacio vacío
			{
				if (fila == 0 || fila == 49 || columna == 0 || columna == 49) {
					//spawnear los limited con acero
					AEnemigo* NuevoEnemigo = Fabrica->CrearEnemigo(GetWorld(), 0, posicionEnemigo, FRotator::ZeroRotator);
				}
				else {
					// Añadir la posición a los espacios vacíos
					aEspaciosVacios.Add(posicionEnemigo);
				}
			}
			else {
				// Spawn del bloque usando la fábrica
				AEnemigo* NuevoEnemigo = Fabrica->CrearEnemigo(GetWorld(), valor, posicionEnemigo, FRotator::ZeroRotator);
				//spawnear a un enemigo

			}

		}
	}
}

