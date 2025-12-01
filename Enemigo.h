// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Enemigo.generated.h"

class IEstadoEnemigo;

UCLASS()
class BOYDADVENTURE_API AEnemigo : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AEnemigo();
	UStaticMeshComponent* MallaEnemigo;
	

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	FVector PoscicionInicial;

	float FloatSpeed;
	float RotationSpeed;
	bool bPuedeMoverse;
	static AEnemigo* CrearEnemigo(UWorld* World, const FVector& Location, const FRotator& Rotation)
	{
		FActorSpawnParameters SpawnParams;
		SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
		return World->SpawnActor<AEnemigo>(Location, Rotation, SpawnParams);
	}
public:
	IEstadoEnemigo* EstadoActual;

	virtual void SetEstado(IEstadoEnemigo* NuevoEstado);

	// Cambio automático cada 10s
	void CambiarEstado();

	FTimerHandle TimerCambio;
	int IndexEstado;

};
