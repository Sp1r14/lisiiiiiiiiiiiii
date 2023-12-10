// Fill out your copyright notice in the Description page of Project Settings.


#include "TorchCPP.h"

ATorchCPP::ATorchCPP()
{
	ConstructorHelpers::FObjectFinder<UStaticMesh>Mesh1(TEXT("/Game/PapaMama/Mebel/Torch.Torch"));
	GetStaticMeshComponent()->SetStaticMesh(Mesh1.Object);

	Light = CreateDefaultSubobject<USpotLightComponent>(TEXT("Light"));
	Light->AttachToComponent(GetStaticMeshComponent(), FAttachmentTransformRules::KeepRelativeTransform);
	Light->SetIntensity(0);
}

void ATorchCPP::BeginPlay()
{
	Super::BeginPlay();

	MaxIntensivity = Light->Intensity;
	Light->SetIntensity(IsPowered ? 0 : MaxIntensivity);
}

void ATorchCPP::UsingThis()
{
	Light->SetIntensity(IsPowered ? 0 : MaxIntensivity);
	IsPowered = !IsPowered;
}