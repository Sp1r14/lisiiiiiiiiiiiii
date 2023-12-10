// Fill out your copyright notice in the Description page of Project Settings.


#include "MainGM.h"

AMainGM::AMainGM()
{
	ConstructorHelpers::FClassFinder<APawn>GlavHero(TEXT("/Script/FuryBear.GlavHer"));
	DefaultPawnClass = GlavHero.Class;
}