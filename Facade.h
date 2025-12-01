// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Facade.generated.h"

UCLASS()
class BOYDADVENTURE_API AFacade : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFacade();

	virtual void Tick(float DeltaTime) override;
	// Llama a todo: laberinto, enemigos, etc.
	UFUNCTION(BlueprintCallable)
	void InicializarNivel(UWorld* World);

private:
	void CrearHorda(UWorld* World);

};
