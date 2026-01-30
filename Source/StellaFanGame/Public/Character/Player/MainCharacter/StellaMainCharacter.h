// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "StellaMainCharacter.generated.h"


class USpringArmComponent;
class UCameraComponent;
class UBoxComponent;
class UInputAction;
class UInputMappingContext;
class AStellaFanGameHUD;

struct FInputActionValue;

UCLASS(abstract)
class AStellaMainCharacter : public ACharacter
{
	GENERATED_BODY()

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	USpringArmComponent* CameraBoom;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	UCameraComponent* FollowCamera;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Interact", meta = (AllowPrivateAccess = "true"))
	UBoxComponent* BoxCollision;
	
public:
	// Sets default values for this character's properties
	AStellaMainCharacter();
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere,Category="Input")
	UInputAction* JumpAction;

	UPROPERTY(EditAnywhere,Category="Input")
	UInputAction* MoveAction;

	UPROPERTY(EditAnywhere,Category="Input")
	UInputAction* LookAction;

	UPROPERTY(EditAnywhere,Category="Input")
	UInputAction* MouseLookAction;
    
    UPROPERTY(EditAnywhere,Category="Input")
    UInputAction* InteractAction;
    
    UFUNCTION()
    void BoxCollisionOnBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult);

	UPROPERTY(EditAnywhere,Category="DishWashingMinigameInput")
	UInputAction* DWUpAction;

	UPROPERTY(EditAnywhere,Category="DishWashingMinigameInput")
	UInputAction* DWDownAction;
	
	UPROPERTY(EditAnywhere,Category="DishWashingMinigameInput")
	UInputAction* DWLeftAction;
	
	UPROPERTY(EditAnywhere,Category="DishWashingMinigameInput")
	UInputAction* DWRightAction;

	UPROPERTY(EditAnywhere,Category="DishWashingMinigameInput")
	UInputAction* ExitDWMinigameAction;
	
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:

	void Move(const FInputActionValue& Value);

	void Look(const FInputActionValue& Value);

private:

	APlayerController* PlayerController;
	
public:

	UFUNCTION(BlueprintCallable, Category="Input")
	virtual void DoMove(float Right, float Forward);

	UFUNCTION(BlueprintCallable, Category="Input")
	virtual void DoLook(float Yaw, float Pitch);

	UFUNCTION(BlueprintCallable, Category="Input")
	virtual void DoJumpStart();

	UFUNCTION(BlueprintCallable, Category="Input")
	virtual void DoJumpEnd();
	
	UFUNCTION(BlueprintCallable, Category="Input")
	void Interact();

	UFUNCTION(BlueprintCallable, Category="Input")
	void TestFunc();

	UFUNCTION(BlueprintCallable, Category="Input")
	void DWUpFunc();

	UFUNCTION(BlueprintCallable, Category="Input")
	void DWDownFunc();

	UFUNCTION(BlueprintCallable, Category="Input")
	void DWLeftFunc();

	UFUNCTION(BlueprintCallable, Category="Input")
	void DWRightFunc();

private:

	void ExitDWMinigame();
	void ReturnCameraViewToPlayer();
	AActor* CurrentInteractedActor;
	AStellaFanGameHUD* MainHUD;
	void InitializeHUD();
	void EnableMouseCursor();
	
public:
	UFUNCTION(BlueprintCallable)
	void DisableMouseCursor();

	/** Returns CameraBoom subobject **/
	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }

	/** Returns FollowCamera subobject **/
	FORCEINLINE class UCameraComponent* GetFollowCamera() const { return FollowCamera; }
};


