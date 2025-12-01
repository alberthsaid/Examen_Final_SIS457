// Fill out your copyright notice in the Description page of Project Settings.


#include "IEstado_Cubo.h"
#include "Enemigo.h"
void IIEstado_Cubo::AState(AEnemigo* Enemy)
{
	static ConstructorHelpers::FObjectFinder<UStaticMesh>MeshEnemigo(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Cube.Shape_Cube'"));

	if (MeshEnemigo.Succeeded())
	{
		Enemy->MallaEnemigo->SetStaticMesh(MeshEnemigo.Object);
		Enemy->MallaEnemigo->SetRelativeLocation(FVector(0.0f, 0.0f, 0.0f));
	}
	
}
	// Add default functionality here for any IIEstado_Cubo functions that are not pure virtual.
