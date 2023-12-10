// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/StaticMeshActor.h"
#include "UsingObjectInterface.h" //interface
#include <Components/TimelineComponent.h>
#include "MovableObjectWithInterface.generated.h"

UCLASS()
class FURYBEAR_API AMovableObjectWithInterface : public AStaticMeshActor, public IUsingObjectInterface
{
	GENERATED_BODY()

public:
	AMovableObjectWithInterface();

	//virtual void Tick(float DeltaTime) override;
	virtual void BeginPlay() override;
	virtual void UsingThis() override;



	UPROPERTY(EditAnywhere, Category = "Edit Category")
	float Sdvig = 40;
	FVector StartPosition;
	bool IsOpen = false;

	FOnTimelineFloat ProgressFunction;
	UTimelineComponent*  OtkTL;
	UPROPERTY(EditAnywhere, Category = "Timeline")
	UCurveFloat* CurveFloat;

	UFUNCTION()
	void ProccesOtk(float value);
};