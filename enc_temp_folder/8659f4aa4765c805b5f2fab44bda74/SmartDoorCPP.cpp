// Fill out your copyright notice in the Description page of Project Settings.

#include "CodeDoorWidgetCPP.h"
#include "SmartDoorCPP.h"

ASmartDoorCPP::ASmartDoorCPP()
{
	PrimaryActorTick.bCanEverTick = true;

	ConstructorHelpers::FObjectFinder<UStaticMesh>Mesh1(TEXT("/Game/PapaMama/Lvl/Actor/Dver/DverTohi_DverMain.DverTohi_DverMain"));
	GetStaticMeshComponent()->SetStaticMesh(Mesh1.Object);
	GetStaticMeshComponent()->SetCollisionResponseToChannel(ECC_Visibility, ECR_Ignore);
	ConstructorHelpers::FObjectFinder<UStaticMesh>Mesh4(TEXT("/Game/PapaMama/Lvl/Actor/Dver/Tablo/Tablo.Tablo"));
	Tablo = CreateDefaultSubobject<UStaticMeshComponent>("Tablo");
	Tablo->SetStaticMesh(Mesh4.Object);
	Tablo->AttachToComponent(GetStaticMeshComponent(), FAttachmentTransformRules::KeepRelativeTransform);
	Tablo->SetCollisionResponseToChannel(ECC_Visibility, ECR_Ignore);
	ConstructorHelpers::FObjectFinder<UStaticMesh>Mesh2(TEXT("/Game/PapaMama/Lvl/Actor/Dver/DverTohi_DverVerh.DverTohi_DverVerh"));
	VerhMesh = CreateDefaultSubobject<UStaticMeshComponent>("VerhMesh");
	VerhMesh->SetStaticMesh(Mesh2.Object);
	VerhMesh->SetCollisionResponseToChannel(ECC_Visibility, ECR_Ignore);
	VerhMesh->SetMobility(EComponentMobility::Movable);
	VerhMesh->AttachToComponent(GetStaticMeshComponent(), FAttachmentTransformRules::KeepRelativeTransform);

	ConstructorHelpers::FObjectFinder<UStaticMesh>Mesh3(TEXT("/Game/PapaMama/Lvl/Actor/Dver/DverTohi_DverNiz.DverTohi_DverNiz"));
	NizMesh = CreateDefaultSubobject<UStaticMeshComponent>("NizMesh");
	NizMesh->SetStaticMesh(Mesh3.Object);
	NizMesh->SetMobility(EComponentMobility::Movable);
	NizMesh->SetCollisionResponseToChannel(ECC_Visibility, ECR_Ignore);
	NizMesh->AttachToComponent(GetStaticMeshComponent(), FAttachmentTransformRules::KeepRelativeTransform);

	StartPositionVerh = VerhMesh->GetRelativeLocation();
	StartPositionNiz = NizMesh->GetRelativeLocation();

	/*VerhMesh->OnComponentBeginOverlap.AddDynamic(this, &ASmartDoorCPP::OverlapBegin);
	VerhMesh->OnComponentBeginOverlap.AddDynamic(this, &ASmartDoorCPP::OverlapEnd);
	NizMesh->OnComponentBeginOverlap.AddDynamic(this, &ASmartDoorCPP::OverlapBegin);
	NizMesh->OnComponentBeginOverlap.AddDynamic(this, &ASmartDoorCPP::OverlapEnd);
	VerhMesh->SetNotifyRigidBodyCollision(true);
	VerhMesh->OnComponentHit.AddDynamic(this, &ASmartDoorCPP::OnComponentHit);
	NizMesh->SetNotifyRigidBodyCollision(true);
	NizMesh->OnComponentHit.AddDynamic(this, &ASmartDoorCPP::OnComponentHit);*/

	OtkTL = CreateDefaultSubobject<UTimelineComponent>(TEXT("OtkTL"));

	/*FOnTimelineEventStatic EndOtKTL;
	EndOtKTL.BindUFunction(this, FName("OpenDone"));
	OtkTL->SetTimelineFinishedFunc(EndOtKTL);*/

	Widget = CreateDefaultSubobject<UWidgetComponent>(TEXT("Widget1"));
	Widget->AttachToComponent(Tablo, FAttachmentTransformRules::KeepRelativeTransform);
	Widget->SetDrawSize(FVector2D(960, 960));
	Widget->SetRelativeLocation(FVector(0, 15.786, 1.799));
	Widget->SetRelativeRotation(FRotator(30, 90, 0));
	Widget->SetRelativeScale3D(FVector(0.1, 0.1, 0.1));
}

void ASmartDoorCPP::BeginPlay()
{
	Super::BeginPlay();

	ProgressFunction.BindDynamic(this, &ASmartDoorCPP::ProccesOtk);

	if (CurveFloat)
	{
		OtkTL->AddInterpFloat(CurveFloat, ProgressFunction);
	}

	if (UCodeDoorWidgetCPP* UIWidget = Cast<UCodeDoorWidgetCPP>(Widget->GetUserWidgetObject()))
	{
		UIWidget->MeshOfWidget = Cast<ASmartDoorCPP>(GetOwner());
	}
}

void ASmartDoorCPP::Otkrit()
{
	//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("2"));
	if (!IsOpen)
		OtkTL->Play();
	else OtkTL->Reverse();
	IsOpen = !IsOpen;
}

void ASmartDoorCPP::ProccesOtk (float value)
{
	VerhMesh->SetRelativeLocation(FMath::Lerp(StartPositionVerh, StartPositionVerh + FVector(0, 0, Sdvig), value));
	NizMesh->SetRelativeLocation(FMath::Lerp(StartPositionNiz, StartPositionNiz + FVector(0, 0, -Sdvig), value));
}

/*void ASmartDoorCPP::OverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	OtkTL->Stop();
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("2"));
}
void ASmartDoorCPP::OverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	OtkTL->Play();
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("2"));

	void ASmartDoorCPP::OnComponentHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	OtkTL->Play();
	IsOpen = true;
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("2"));
}
}*/

