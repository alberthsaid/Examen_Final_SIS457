// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "UObject/NoExportTypes.h"
#include "Builder_Horda_Abstracta.h"
#include "Director_Horda.generated.h"
/**
 *
 */
UCLASS()
class BOYDADVENTURE_API UDirector_Horda : public UObject
{
	GENERATED_BODY()
	
public:	
	ABuilder_Horda_Abstracta* Builder_Horda;
	void ConstruirHorda()
	{
		if (Builder_Horda)
		{
			Builder_Horda->ConstruirHorda();
		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("BuilderHorda no está asignado."));
		}
	}
};
