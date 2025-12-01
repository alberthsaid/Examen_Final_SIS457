// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemigo_Acuatico.h"
AEnemigo_Acuatico::AEnemigo_Acuatico()
{
	if (MallaEnemigo)
	{
		static ConstructorHelpers::FObjectFinder<UMaterial>Material(TEXT("Material'/Game/StarterContent/Materials/M_Water_Lake.M_Water_Lake'"));
		if (Material.Succeeded())
		{
			MallaEnemigo->SetMaterial(0, Material.Object);
		}
	}
	FloatSpeed = 3.0f;
	RotationSpeed = 3.0f;
	bPuedeMoverse = FMath::RandBool();
}
void AEnemigo_Acuatico::BeginPlay()
{
	Super::BeginPlay();
	PoscicionInicial = GetActorLocation();
}
void AEnemigo_Acuatico::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (bPuedeMoverse)
	{
		FVector NewLocation = PoscicionInicial;
		NewLocation.Z = FMath::Sin(GetGameTimeSinceCreation() * FloatSpeed) * 170.0f + 190.0f;
		SetActorLocation(NewLocation);
	}
	else {
		FVector NewLocation = PoscicionInicial;
		NewLocation.X = PoscicionInicial.X + FMath::Sin(GetGameTimeSinceCreation() * FloatSpeed) * 100.0f;
		SetActorLocation(NewLocation);
	}
}

