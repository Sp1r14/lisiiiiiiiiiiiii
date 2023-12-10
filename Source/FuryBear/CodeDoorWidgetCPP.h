// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/Button.h"
#include <Engine/StaticMeshActor.h>
#include "OpenDoorInterface.h" //interface
#include "CodeDoorWidgetCPP.generated.h"

/**
 * 
 */
UCLASS()
class FURYBEAR_API UCodeDoorWidgetCPP : public UUserWidget
{
	GENERATED_BODY()

public:

	virtual void NativeConstruct() override;
	virtual bool Initialize();

	UPROPERTY(BlueprintReadWrite, Category = "WidgeInMesh")
	AActor* MeshOfWidget;

	UFUNCTION(BlueprintCallable)
	void FTrue();
};
