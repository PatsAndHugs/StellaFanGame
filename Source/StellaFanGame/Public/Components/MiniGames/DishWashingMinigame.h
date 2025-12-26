// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "DishWashingMinigame.generated.h"

UENUM(BlueprintType)
enum class EArrowPrompts : uint8
{
	Up UMETA(DisplayName = "↑"),
	Down UMETA(DisplayName = "↓"),
	Left UMETA(DisplayName = "←"),
	Right UMETA(DisplayName = "→")
};

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class STELLAFANGAME_API UDishWashingMinigame : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UDishWashingMinigame();
	
protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION()
	void ShowArrowPrompts();

	int32 DifficultyLevel = 1;
};
