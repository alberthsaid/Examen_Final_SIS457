// Fill out your copyright notice in the Description page of Project Settings.


#include "Facade.h"
#include "Director_Horda.h"
#include "Builder_Horda_Concreta.h"


// Sets default values
AFacade::AFacade()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}
void AFacade::InicializarNivel(UWorld* World)
{
    if (!World) return;

    CrearHorda(World);
   
}

void AFacade::CrearHorda(UWorld* World)
{
    //Creamos el director de laberinto
    UDirector_Horda* Director_Horda = NewObject<UDirector_Horda>();
    // Creamos el builder concreto
    ABuilder_Horda_Concreta* Builder_Horda = GetWorld()->SpawnActor<ABuilder_Horda_Concreta>(ABuilder_Horda_Concreta::StaticClass());
    // Asignamos el builder al director
    Director_Horda->Builder_Horda = Builder_Horda;
    // Llamamos al director para construir el laberinto
    Director_Horda->ConstruirHorda();

}

