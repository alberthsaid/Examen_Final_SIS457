// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Builder_Horda_Abstracta.h"
#include "Enemigo.h"
#include "Builder_Horda_Concreta.generated.h"

class AEnemigo;

UCLASS()
class BOYDADVENTURE_API ABuilder_Horda_Concreta : public ABuilder_Horda_Abstracta
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABuilder_Horda_Concreta();
	virtual void ConstruirHorda() override;

};
