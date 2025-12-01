// Fill out your copyright notice in the Description page of Project Settings.


#include "IEstado_Capsula.h"
#include "Enemigo.h"

void IIEstado_Capsula::AState(AEnemigo* Enemy)
{
	// Implement the state application logic for the capsule state here
	static ConstructorHelpers::FObjectFinder<UStaticMesh>MeshEnemigo(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_NarrowCapsule.Shape_NarrowCapsule'"));

	if (MeshEnemigo.Succeeded())
	{
		Enemy->MallaEnemigo->SetStaticMesh(MeshEnemigo.Object);
		Enemy->MallaEnemigo->SetRelativeLocation(FVector(0.0f, 0.0f, 0.0f));
	}
}

// Add default functionality here for any IIEstado_Capsula functions that are not pure virtual.
