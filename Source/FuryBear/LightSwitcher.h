// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/StaticMeshActor.h"
#include "UsingObjectInterface.h" //interface
#include "Components/PointLightComponent.h"
#include "LightSwitcher.generated.h"

/**
 * 
 */
UCLASS()
class FURYBEAR_API ALightSwitcher : public AStaticMeshActor, public IUsingObjectInterface
{
	GENERATED_BODY()

public:
	ALightSwitcher();
	virtual void UsingThis() override;
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, Category = "Light")
	UPointLightComponent* Light;
	UPROPERTY(EditAnywhere, Category = "Light")
	bool IsPowered = false;
	//UPROPERTY(EditAnywhere, Category = "Light")
	float MaxIntensivity;
};
