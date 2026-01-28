// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/MiniGames/DishWashingMinigame.h"

#include "Misc/AsyncTaskNotification.h"

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
	
}

void UDishWashingMinigame::ShowArrowPrompts()
{
	TArray<EArrowPrompts> ArrowPromptsList = {EArrowPrompts::Up, EArrowPrompts::Down, EArrowPrompts::Left, EArrowPrompts::Right};
	FString ArrowPrompts;
	//clear
	DisplayArrowPromptsArr.Empty();
	//add temp number to difficulty to add more prompts 
	for (int i = 0; i < NumberOfPrompts; i++)
	{
		//get random index
		int32 ArrowRandIndex = FMath::RandRange(0, ArrowPromptsList.Num() - 1);
		EArrowPrompts RandArrowPrompt = ArrowPromptsList[ArrowRandIndex];
		ArrowPrompts.Append(UEnum::GetDisplayValueAsText(RandArrowPrompt).ToString());
		DisplayArrowPromptsArr.Add(UEnum::GetDisplayValueAsText(RandArrowPrompt).ToString());
	}

	if (GEngine)
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, ArrowPrompts);
}

void UDishWashingMinigame::AddUpInput()
{
	UserInputArr.Add(TEXT("↑"));
	if (UserInputArr.Num() == NumberOfPrompts)
		GetNewPrompts();
}

void UDishWashingMinigame::AddDownInput()
{
	UserInputArr.Add(TEXT("↓"));
	if (UserInputArr.Num() == NumberOfPrompts)
		GetNewPrompts();
}

void UDishWashingMinigame::AddLeftInput()
{
	UserInputArr.Add(TEXT("←"));
	if (UserInputArr.Num() == NumberOfPrompts)
		GetNewPrompts();
}

void UDishWashingMinigame::AddRightInput()
{
	UserInputArr.Add(TEXT("→"));
	if (UserInputArr.Num() == NumberOfPrompts)
		GetNewPrompts();
}

bool UDishWashingMinigame::GetNewPrompts()
{
	if (UserInputArr.IsEmpty())
		return false;
	
	if (UserInputArr.Num() == NumberOfPrompts)
	{
		bool bIsAllInputCorrect = true;
		//Check if each input is equal to the currently shown prompts
		for (int i = 0; i < NumberOfPrompts; i++)
		{
			if (UserInputArr[i] != DisplayArrowPromptsArr[i])
				bIsAllInputCorrect = false;
		}
		//clear UserInput Arr
		UserInputArr.Empty();
		UE_LOG(LogTemp, Warning, TEXT("GetNewPrompts Result: %s"),bIsAllInputCorrect ? TEXT("true") : TEXT("false"));
		ShowArrowPrompts();
		
		if (bIsAllInputCorrect)
			PlayerScore += 100.f;
		
		return bIsAllInputCorrect;
	}

	return false;
}

