// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include <Components/WidgetInteractionComponent.h>
#include "GlavHer.generated.h"

UCLASS()
class FURYBEAR_API AGlavHer : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AGlavHer();
	class UCameraComponent* Camera;
	UWidgetInteractionComponent* InteractionWithWidget;

	//float
	UPROPERTY(BlueprintReadOnly, Category = "MovementCPP")
	float DefaultSpeed = 350;
	UPROPERTY(BlueprintReadOnly, Category = "MovementCPP")
	float SprintSpeed = 550;

	//bool
	bool bIsSprint;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void ForwardWalk(float Value);
	void RightWalk(float Value);
	void StartCrouch();
	void StopCrouch();
	void Sprint();
	void StopSprint();
	void StartJump();
	void Reload();
	void SpeedVoid();

	void UsindObject();
	void ButtonPressedWidget();
	void ButtonReleasedWidget();
};
