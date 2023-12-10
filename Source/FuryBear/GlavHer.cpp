// Fill out your copyright notice in the Description page of Project Settings.


#include "GlavHer.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"

#include "UsingObjectInterface.h" //interface


// Sets default values
AGlavHer::AGlavHer()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//mesh
	ConstructorHelpers::FObjectFinder<USkeletalMesh>Mesh1(TEXT("/Game/PapaMama/MainHer/mav.mav"));
	GetMesh()->SetSkeletalMesh(Mesh1.Object);
	GetMesh()->SetRelativeLocationAndRotation(FVector(0, 0, -95), FRotator(0, 180, 0));
	ConstructorHelpers::FObjectFinder<UAnimBlueprint>AnimBP1(TEXT("/Game/PapaMama/MainHer/mavABP.mavABP"));
	GetMesh()->SetAnimInstanceClass(AnimBP1.Object->GeneratedClass);

	//capsule
	GetCapsuleComponent()->SetCapsuleHalfHeight(95);

	//camera
	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	//Camera->SetupAttachment(RootComponent);
	Camera->AttachToComponent(GetMesh(), FAttachmentTransformRules::KeepRelativeTransform, "Dummy_camera");
	//Camera->SetRelativeLocation(FVector(0, 0, 0));
	Camera->bUsePawnControlRotation = true;

	//movement
	GetCharacterMovement()->NavAgentProps.bCanCrouch = true;
	GetCharacterMovement()->MaxWalkSpeed = DefaultSpeed;
	GetCharacterMovement()->MaxWalkSpeedCrouched = 100;
	GetCharacterMovement()->GravityScale = 1.5;
	GetCharacterMovement()->JumpZVelocity = 600;

	InteractionWithWidget = CreateDefaultSubobject<UWidgetInteractionComponent>(TEXT("InteractionWithWidget1"));
	InteractionWithWidget->InteractionSource = EWidgetInteractionSource::CenterScreen;
}

// Called when the game starts or when spawned
void AGlavHer::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AGlavHer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AGlavHer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("PitchLook", this, &APawn::AddControllerPitchInput);
	PlayerInputComponent->BindAxis("YawLook", this, &APawn::AddControllerYawInput);

	PlayerInputComponent->BindAxis("ForwardWalk", this, &AGlavHer::ForwardWalk);
	PlayerInputComponent->BindAxis("RightWalk", this, &AGlavHer::RightWalk);

	PlayerInputComponent->BindAction("Sprint", IE_Pressed, this, &AGlavHer::Sprint);
	PlayerInputComponent->BindAction("Sprint", IE_Released, this, &AGlavHer::StopSprint);

	PlayerInputComponent->BindAction("Crouch", IE_Pressed, this, &AGlavHer::StartCrouch);
	PlayerInputComponent->BindAction("Crouch", IE_Released, this, &AGlavHer::StopCrouch);

	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &AGlavHer::Jump);


	PlayerInputComponent->BindAction("Using", IE_Pressed, this, &AGlavHer::UsindObject);

	PlayerInputComponent->BindAction("Using", IE_Pressed, this, &AGlavHer::ButtonPressedWidget);
	PlayerInputComponent->BindAction("Using", IE_Released, this, &AGlavHer::ButtonReleasedWidget);
}

void AGlavHer::ForwardWalk(float Value)
{
	AddMovementInput(GetActorForwardVector() * Value);
	SpeedVoid();
}
void AGlavHer::RightWalk(float Value)
{
	AddMovementInput(GetActorRightVector() * Value);
}

void AGlavHer::Sprint()
{
	bIsSprint = true;
}
void AGlavHer::StopSprint()
{
	bIsSprint = false;
}
void AGlavHer::StartCrouch ()
{
	Crouch();
}
void AGlavHer::StopCrouch()
{
	UnCrouch();
}
void AGlavHer::StartJump()
{
	Jump();
}

void AGlavHer::SpeedVoid()
{
	float *NowSpeed;
	//float NowSpeed;
	if (bIsSprint == true)
	{
		NowSpeed = &SprintSpeed;
	}
	else
	{
		NowSpeed = &DefaultSpeed;
	}
	if (GetInputAxisValue("ForwardWalk") == -1)
	{
		GetCharacterMovement()->MaxWalkSpeed = DefaultSpeed;
	}
	else
	{
		GetCharacterMovement()->MaxWalkSpeed = abs(GetInputAxisValue("RightWalk")) ? DefaultSpeed : *NowSpeed;
	}
}

void AGlavHer::UsindObject()
{
	//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("1"));
	FHitResult ResultOfHit;
	//DrawDebugLine(GetWorld(), Camera->GetComponentLocation(), (Camera->GetForwardVector() * 200) + Camera->GetComponentLocation(), FColor::Green, false, 100, 0, 1);
	GetWorld()->LineTraceSingleByChannel(ResultOfHit, Camera->GetComponentLocation(), (Camera->GetForwardVector() * 200) + Camera->GetComponentLocation(), ECC_Visibility);

	IUsingObjectInterface* Using = Cast<IUsingObjectInterface>(ResultOfHit.GetActor());

	if (Using)
	{
		Using->UsingThis();
		//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("2"));
	}
}

void AGlavHer::ButtonPressedWidget()
{
	InteractionWithWidget->PressPointerKey(EKeys::LeftMouseButton);
}
void AGlavHer::ButtonReleasedWidget()
{
	InteractionWithWidget->ReleasePointerKey(EKeys::LeftMouseButton);
}