// Fill out your copyright notice in the Description page of Project Settings.

#include "LightSwitcher.h"

ALightSwitcher::ALightSwitcher()
{
	ConstructorHelpers::FObjectFinder<UStaticMesh>Mesh1(TEXT("/Game/PapaMama/Mebel/Torch.Torch"));
	GetStaticMeshComponent()->SetStaticMesh(Mesh1.Object);

	Light = CreateDefaultSubobject<UPointLightComponent>(TEXT("Light"));
	Light->AttachToComponent(GetStaticMeshComponent(), FAttachmentTransformRules::KeepRelativeTransform);
}

void ALightSwitcher::BeginPlay()
{
	Super::BeginPlay();

	MaxIntensivity = Light->Intensity;
	Light->SetIntensity(IsPowered ? 0 : MaxIntensivity);
}

void ALightSwitcher::UsingThis()
{
	Light->SetIntensity(IsPowered ? 0 : MaxIntensivity);
	IsPowered = !IsPowered;
}