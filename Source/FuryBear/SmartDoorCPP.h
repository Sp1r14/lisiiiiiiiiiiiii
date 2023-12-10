// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/StaticMeshActor.h"
//#include "OpenDoorInterface.h"//interface
#include <Components/WidgetComponent.h>
#include <Components/TimelineComponent.h>
#include "SmartDoorCPP.generated.h"

/**
 * 
 */
UCLASS()
class FURYBEAR_API ASmartDoorCPP : public AStaticMeshActor//, public IOpenDoorInterface //, public IUsingObjectInterface
{
	GENERATED_BODY()
public:
	ASmartDoorCPP();

	float Sdvig = 140;
	FVector StartPositionNiz, StartPositionVerh;
	bool IsOpen = false;
	FOnTimelineFloat ProgressFunction;
	UTimelineComponent* OtkTL;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Timeline")
	UCurveFloat* CurveFloat;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DopStaticMesh");
	UStaticMeshComponent* Tablo;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DopStaticMesh");
	UStaticMeshComponent* VerhMesh;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DopStaticMesh");
	UStaticMeshComponent* NizMesh;
	//UPROPERTY(EditAnywhere, Category = "UI")
	//UUserWidget* UIWidget;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UI")
	UWidgetComponent* Widget;


	//virtual void UsingThis() override;
	//virtual void OpenDoor() override;
	virtual void BeginPlay() override;
	UFUNCTION()
	void ProccesOtk(float value);
	UFUNCTION(BlueprintCallable)
	void Otkrit();

	//UFUNCTION()
	//void OpenDone();

/*	UFUNCTION()
	void OverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);	
	UFUNCTION()
	void OverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	UFUNCTION()
	void OnComponentHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);*/
};
