// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/Scene Components/KitchenSinkComponents.h"

#include "Camera/CameraComponent.h"
#include "Components/BoxComponent.h"
#include "GameFramework/SpringArmComponent.h"

// Sets default values
AKitchenSinkComponents::AKitchenSinkComponents()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	BoxCollision = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxCollision"));
	SetRootComponent(BoxCollision);
	SinkMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("SinkMesh"));
	SinkMeshComp->SetupAttachment(RootComponent);
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraComp = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraComp"));
	CameraComp->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);
}

// Called when the game starts or when spawned
void AKitchenSinkComponents::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AKitchenSinkComponents::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

