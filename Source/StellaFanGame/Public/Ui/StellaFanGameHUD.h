// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "StellaFanGameHUD.generated.h"

class UTextBlock;
/**
 * 
 */
UCLASS()
class STELLAFANGAME_API AStellaFanGameHUD : public AHUD
{
	GENERATED_BODY()

public:
	AStellaFanGameHUD();

protected:

	virtual void BeginPlay() override;

private:

	void InitializeHUD(TSubclassOf<UUserWidget> MenuClass, UUserWidget* MenuBar, bool bShouldAddToViewport);
	void RemoveHUDFromViewport(UUserWidget* MenuBar);
	APlayerController* PlayerController;

//DishWashing minigame
protected:
	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<UUserWidget> DishwashingMinigameHUDClass;

public:
	UPROPERTY(meta = (BindWidget))
	UTextBlock* DWMinigameScoreTextBox;
	
	void SetDishWashingMinigameScore(float Score);
};
