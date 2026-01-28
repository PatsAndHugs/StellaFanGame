// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "MinigameInterface.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UMinigameInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class STELLAFANGAME_API IMinigameInterface
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:

	virtual void MinigameInteract() = 0;
	virtual void ChangeToNewMappingContext() = 0;
	virtual void RevertToDefaultMappingContext() = 0;
	virtual void PlayerPressedUp() = 0;
	virtual void PlayerPressedDown() = 0;
	virtual void PlayerPressedLeft() = 0;
	virtual void PlayerPressedRight() = 0;
	virtual void ResetPlayerScore() = 0;

};
