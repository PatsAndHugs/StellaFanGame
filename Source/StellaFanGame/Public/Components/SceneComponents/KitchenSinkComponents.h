// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Interactions/Interfaces/MinigameInterface.h"
#include "KitchenSinkComponents.generated.h"

class UBoxComponent;
class UCameraComponent;
class USpringArmComponent;

UCLASS()
class STELLAFANGAME_API AKitchenSinkComponents : public AActor, public IMinigameInterface
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AKitchenSinkComponents();

	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Mesh",meta=(AllowPrivateAccess=true))
	UStaticMeshComponent* SinkMeshComp;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	USpringArmComponent* CameraBoom;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	UCameraComponent* CameraComp;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Interact", meta = (AllowPrivateAccess = "true"))
	UBoxComponent*  BoxCollision;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UFUNCTION()
	void BoxCollisionOnBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult);

	UFUNCTION()
	void BoxCollisionOnEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual void MinigameInteract() override;

};
