// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/MiniGames/DishWashingMinigame.h"

// Sets default values for this component's properties
UDishWashingMinigame::UDishWashingMinigame()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UDishWashingMinigame::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UDishWashingMinigame::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UDishWashingMinigame::ShowArrowPrompts()
{
	TArray<EArrowPrompts> ArrowPromptsList = {EArrowPrompts::Up, EArrowPrompts::Down, EArrowPrompts::Left, EArrowPrompts::Right};
	FString ArrowPrompts;
	//add temp number to difficulty to add more prompts 
	for (int i = 0; i < DifficultyLevel + 4; i++)
	{
		int32 ArrowRandIndex = FMath::RandRange(0, ArrowPromptsList.Num() - 1);
		ArrowPrompts.Append(UEnum::GetDisplayValueAsText(ArrowPromptsList[ArrowRandIndex]).ToString());
	}

	if (GEngine)
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, ArrowPrompts);
}

