// Fill out your copyright notice in the Description page of Project Settings.


#include "CodeDoorWidgetCPP.h"
#include "SmartDoorCPP.h"

void UCodeDoorWidgetCPP::NativeConstruct()
{
	Super::NativeConstruct();
}

bool UCodeDoorWidgetCPP::Initialize()
{
	Super::Initialize();

	return true;
}

void UCodeDoorWidgetCPP::FTrue()
{
	//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT(MeshOfWidget->GetActorLabel()));
	if (IOpenDoorInterface* IOpenDoor = Cast<IOpenDoorInterface>(MeshOfWidget))
	{
		IOpenDoor->OpenDoor();
		//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("2"));
	}
}