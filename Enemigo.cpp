// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemigo.h"
#include "IEstado_Capsula.h"
#include "IEstado_Cubo.h"

class IIEstado_Capsula;	
class IIEstado_Cubo;
// Sets default values
AEnemigo::AEnemigo()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	MallaEnemigo = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MallaEnemigo"));	
	RootComponent = MallaEnemigo;
	IndexEstado = 0;
	FloatSpeed = 5.0f;
	RotationSpeed = 3.0f;

	bPuedeMoverse = FMath::RandBool();
}

// Called when the game starts or when spawned
void AEnemigo::BeginPlay()
{
	Super::BeginPlay();

	PoscicionInicial = GetActorLocation();

	SetEstado(new IEstadoEnemigo());  // ESTADO INICIAL ✔

	GetWorld()->GetTimerManager().SetTimer(
		CambioEstadoTimer,
		this,
		&AEnemigo::CambiarEstado,
		10.0f,
		true
	);
}
void AEnemigo::SetEstado(IEstadoEnemigo* NuevoEstado)
{
	if (EstadoActual)
	{
		delete EstadoActual;
	}

	EstadoActual = NuevoEstado;
	EstadoActual->AState(this);
}

void AEnemigo::CambiarEstado()
{
	IndexEstado = (IndexEstado + 1) % 2;

	if (IndexEstado == 0)
	{
		SetEstado(new IIEstado_Capsula());
	}
	else
	{
		SetEstado(new IIEstado_Cubo());
	}
}
