// Fill out your copyright notice in the Description page of Project Settings.


#include "Ui/StellaFanGameHUD.h"

#include "Blueprint/UserWidget.h"
#include "Kismet/GameplayStatics.h"
#include "Components/TextBlock.h"

AStellaFanGameHUD::AStellaFanGameHUD()
{
}

void AStellaFanGameHUD::BeginPlay()
{
	Super::BeginPlay();

	PlayerController = Cast<APlayerController>(GetOwner());
}

void AStellaFanGameHUD::InitializeHUD(TSubclassOf<UUserWidget> MenuClass, UUserWidget*& MenuBar,
                                      bool bShouldAddToViewport)
{
	if (IsValid(MenuClass))
	{
		MenuBar = CreateWidget<UUserWidget>(PlayerController, MenuClass);
		if (bShouldAddToViewport == true)
			MenuBar->AddToViewport();
	}	
}

void AStellaFanGameHUD::RemoveHUDFromViewport(UUserWidget*& MenuBar)
{
	if (IsValid(MenuBar))
		MenuBar->RemoveFromParent();
}

void AStellaFanGameHUD::SetDishWashingMinigameScore(float Score)
{
	if (DWMinigameScoreTextBox)
	{
		FString ScoreStr = FString::SanitizeFloat(Score);
		DWMinigameScoreTextBox->SetText(FText::FromString(ScoreStr));
	}
}

void AStellaFanGameHUD::ShowDishWashingMainHUD()
{
	InitializeHUD(DishwashingMainHUDClass, DishwashingMainHUD, true);
}

void AStellaFanGameHUD::HideDishWashingMainHUD()
{
	//if (IsValid(DishwashingMinigameHUD))
	//DishwashingMinigameHUD->RemoveFromParent();
	RemoveHUDFromViewport(DishwashingMainHUD);
}

void AStellaFanGameHUD::ShowDishWashingMinigameHUD()
{
	InitializeHUD(DishwashingMinigameHUDClass, DishwashingMinigameHUD, true);
	RemoveHUDFromViewport(DishwashingMainHUD);
}

void AStellaFanGameHUD::HideDishWashingMinigameHUD()
{
	RemoveHUDFromViewport(DishwashingMinigameHUD);
}

void AStellaFanGameHUD::RemoveAllDishWashingMinigameHUD()
{
	HideDishWashingMinigameHUD();
	HideDishWashingMainHUD();
}
