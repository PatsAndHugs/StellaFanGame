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
	
	void AddUpInput();
	void AddDownInput();
	void AddLeftInput();
	void AddRightInput();
	
	UFUNCTION(BlueprintPure)
	float GetPlayerScore() const {return PlayerScore;}

	UFUNCTION(BlueprintPure)
	FString GetArrowPrompts() const {return ArrowPrompts; }

	UFUNCTION(BlueprintPure)
	TArray<FString> GetArrowPromptsArr() const {return DisplayArrowPromptsArr;}
	
	void ClearPlayerScore() {PlayerScore = 0;}

	UFUNCTION(BlueprintPure)
	TArray<bool> GetIsCurrentInputCorrect() const {return IsCurrentInputCorrectArr;}

	//Sets Difficulty level and updates number of prompts to be shown based on difficulty level
	UFUNCTION(BlueprintCallable)
	void SetDifficultyLevel(int32 NewVal);
	UFUNCTION(BlueprintCallable)
	int32 GetDifficultyLevel()const{ return DifficultyLevel;}
	
private:

	int32 DifficultyLevel = 1;
	int32 NumberOfPrompts = DifficultyLevel + 3;
	TArray<FString> DisplayArrowPromptsArr;
	TArray<FString> UserInputArr;
	TArray<bool> IsCurrentInputCorrectArr;
	float PlayerScore = 0.f;
	void GetNewPrompts();
	FString ArrowPrompts;
	int32 CurrentInputIndex = 0;
	bool CheckCurrentInput();
	bool bIsCurrentInputCorrect = false;
	//if check current input is true then add it to the end of the array otherwise empty the array
	void UpdateIsCurrentInputCorrectArr();
	void InitializeIsCurrentInputCorrectArr();
};
