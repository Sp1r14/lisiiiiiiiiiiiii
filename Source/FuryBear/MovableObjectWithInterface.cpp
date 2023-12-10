// Fill out your copyright notice in the Description page of Project Settings.


#include "MovableObjectWithInterface.h"

AMovableObjectWithInterface::AMovableObjectWithInterface()
{
	PrimaryActorTick.bCanEverTick = true;

	SetMobility(EComponentMobility::Movable);

	ConstructorHelpers::FObjectFinder<UStaticMesh>Mesh1(TEXT("/Game/PapaMama/Mebel/TableComputer/TableComputer_Chest.TableComputer_Chest"));
	GetStaticMeshComponent()->SetStaticMesh(Mesh1.Object);

	StartPosition = GetStaticMeshComponent()->GetRelativeLocation();

	OtkTL = CreateDefaultSubobject<UTimelineComponent>(TEXT("OtkTL"));
}


void AMovableObjectWithInterface::BeginPlay()
{
	Super::BeginPlay();

	ProgressFunction.BindDynamic(this, &AMovableObjectWithInterface::ProccesOtk);

	if (CurveFloat)
		OtkTL->AddInterpFloat(CurveFloat, ProgressFunction);
}

void AMovableObjectWithInterface::UsingThis()
{
	if (!IsOpen)
		OtkTL->Play();
	else OtkTL->Reverse();
	IsOpen = !IsOpen;
}

void AMovableObjectWithInterface::ProccesOtk(float value)
{
	GetStaticMeshComponent()->SetRelativeLocation(FMath::Lerp(StartPosition, StartPosition + FVector(Sdvig, 0, 0), value));
	//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, "2");
}