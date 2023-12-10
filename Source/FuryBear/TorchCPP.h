// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/StaticMeshActor.h"
#include "UsingObjectInterface.h" //interface
#include "Components/SpotLightComponent.h"
#include "TorchCPP.generated.h"

/**
 * 
 */
UCLASS()
class FURYBEAR_API ATorchCPP : public AStaticMeshActor, public IUsingObjectInterface
{
	GENERATED_BODY()

public:
	ATorchCPP();
	virtual void UsingThis() override;
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, Category = "Light")
	USpotLightComponent* Light;
	UPROPERTY(EditAnywhere, Category = "Light")
	bool IsPowered = false;
	UPROPERTY(EditAnywhere, Category = "Light")
	float MaxIntensivity = 5000;
};
