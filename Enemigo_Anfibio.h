// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Enemigo.h"
#include "Enemigo_Anfibio.generated.h"

/**
 * 
 */
UCLASS()
class BOYDADVENTURE_API AEnemigo_Anfibio : public AEnemigo
{
	GENERATED_BODY()

public:
	AEnemigo_Anfibio();
	virtual void Tick(float DeltaTime) override;
protected:
	virtual void BeginPlay() override;
	
};
