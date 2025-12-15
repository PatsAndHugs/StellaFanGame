// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ItemPool.generated.h"

UCLASS()
class STELLAFANGAME_API AItemPool : public AActor
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Mesh, meta=(AllowPrivateAccess = "true"))
	UStaticMeshComponent* ItemPoolMesh;
	
public:	
	// Sets default values for this actor's properties
	AItemPool();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
