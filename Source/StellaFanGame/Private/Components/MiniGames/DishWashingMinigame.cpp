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
	InitializeIsCurrentInputCorrectArr();
	TArray<EArrowPrompts> ArrowPromptsList = {EArrowPrompts::Up, EArrowPrompts::Down, EArrowPrompts::Left, EArrowPrompts::Right};
	
	//clear
	DisplayArrowPromptsArr.Empty();
	ArrowPrompts.Empty();
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
	
	UpdateIsCurrentInputCorrectArr();
	UE_LOG(LogTemp, Display, TEXT("Current index %d"), CurrentInputIndex);
	if (CurrentInputIndex == NumberOfPrompts)
	{
		GetNewPrompts();
		if (GEngine)
			GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("GetNewPrompt"));
	}
}

void UDishWashingMinigame::AddDownInput()
{
	UserInputArr.Add(TEXT("↓"));
	
	UpdateIsCurrentInputCorrectArr();
	UE_LOG(LogTemp, Display, TEXT("Current index %d"), CurrentInputIndex);
	if (CurrentInputIndex == NumberOfPrompts)
	{
		GetNewPrompts();
		if (GEngine)
			GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("GetNewPrompt"));
	}
}

void UDishWashingMinigame::AddLeftInput()
{
	UserInputArr.Add(TEXT("←"));
	
	UpdateIsCurrentInputCorrectArr();
	UE_LOG(LogTemp, Display, TEXT("Current index %d"), CurrentInputIndex);
	if (CurrentInputIndex == NumberOfPrompts)
	{
		GetNewPrompts();
		if (GEngine)
			GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("GetNewPrompt"));
	}
}

void UDishWashingMinigame::AddRightInput()
{
	UserInputArr.Add(TEXT("→"));
	
	UpdateIsCurrentInputCorrectArr();
	UE_LOG(LogTemp, Display, TEXT("Current index %d"), CurrentInputIndex);
	if (CurrentInputIndex == NumberOfPrompts)
	{
		GetNewPrompts();
		if (GEngine)
			GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("GetNewPrompt"));
	}
}

void UDishWashingMinigame::SetDifficultyLevel(int32 NewVal)
{
	DifficultyLevel = NewVal;
	if (NewVal == 1)
		NumberOfPrompts = DifficultyLevel + 3;
	else if (NewVal == 2)
		NumberOfPrompts = DifficultyLevel + 4;
	else if (NewVal == 3)
		NumberOfPrompts = DifficultyLevel + 5;
}

bool UDishWashingMinigame::CheckCurrentInput()
{
	if (CurrentInputIndex < NumberOfPrompts)
	{
		if (UserInputArr[CurrentInputIndex] == DisplayArrowPromptsArr[CurrentInputIndex])
        {
        	CurrentInputIndex = CurrentInputIndex < NumberOfPrompts ? CurrentInputIndex + 1 : 0;
        	bIsCurrentInputCorrect = true;
        	return true;
        }
	}
	CurrentInputIndex = 0;
	bIsCurrentInputCorrect = false;
	return false;
}

void UDishWashingMinigame::UpdateIsCurrentInputCorrectArr()
{
	if (CheckCurrentInput())
		IsCurrentInputCorrectArr[CurrentInputIndex - 1] = true;
	else
	{
		UserInputArr.Empty();
		InitializeIsCurrentInputCorrectArr();
	}
}

void UDishWashingMinigame::InitializeIsCurrentInputCorrectArr()
{
	IsCurrentInputCorrectArr.Empty();
	for(int i = 0; i < NumberOfPrompts; i++)
		IsCurrentInputCorrectArr.Add(false);
}

void UDishWashingMinigame::GetNewPrompts()
{
	if (IsCurrentInputCorrectArr.Num() < NumberOfPrompts)
		return;
	
	UserInputArr.Empty();
	CurrentInputIndex = 0;
	ShowArrowPrompts();
	PlayerScore += 100.f;
}

