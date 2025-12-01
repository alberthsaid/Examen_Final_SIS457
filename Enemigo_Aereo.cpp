// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemigo_Aereo.h"

AEnemigo_Aereo::AEnemigo_Aereo()
{
	if (MallaEnemigo)
	{
		static ConstructorHelpers::FObjectFinder<UMaterial>Material(TEXT("Material'/Game/StarterContent/Materials/M_Wood_Oak.M_Wood_Oak'"));
		if (Material.Succeeded())
		{
			MallaEnemigo->SetMaterial(0, Material.Object);
		}
	}
	FloatSpeed = 4.0f;
	RotationSpeed = 5.0f;
	bPuedeMoverse = FMath::RandBool();

}
void AEnemigo_Aereo::BeginPlay()
{
	Super::BeginPlay();
	PoscicionInicial = GetActorLocation();
}
void AEnemigo_Aereo::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (bPuedeMoverse)
	{
		FVector NewLocation = PoscicionInicial;
		NewLocation.Z = FMath::Sin(GetGameTimeSinceCreation() * FloatSpeed) * 200.0f + 300.0f;
		SetActorLocation(NewLocation);
	}
	else {
		FVector NewLocation = PoscicionInicial;
		NewLocation.Y = PoscicionInicial.Y + FMath::Sin(GetGameTimeSinceCreation() * FloatSpeed) * 150.0f;
		SetActorLocation(NewLocation);
	}
}