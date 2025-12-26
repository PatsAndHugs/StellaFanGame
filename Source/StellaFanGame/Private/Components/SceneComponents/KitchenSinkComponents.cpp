// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/SceneComponents/KitchenSinkComponents.h"

#include "Camera/CameraComponent.h"
#include "Components/BoxComponent.h"
#include "Components/MiniGames/DishWashingMinigame.h"
#include "GameFramework/SpringArmComponent.h"
#include "Kismet/GameplayStatics.h"

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
	Minigame = CreateDefaultSubobject<UDishWashingMinigame>(TEXT("Minigame"));
	
	Tags.Add("MinigameLocationTag");
}

// Called when the game starts or when spawned
void AKitchenSinkComponents::BeginPlay()
{
	Super::BeginPlay();
	BoxCollision->OnComponentBeginOverlap.AddDynamic(this, &AKitchenSinkComponents::BoxCollisionOnBeginOverlap);
	BoxCollision->OnComponentEndOverlap.AddDynamic(this, &AKitchenSinkComponents::BoxCollisionOnEndOverlap);
}

void AKitchenSinkComponents::BoxCollisionOnBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherComp == nullptr)
		return;

	if (OtherComp->ComponentHasTag("PlayerInteractComponentTag") && !OtherComp->ComponentHasTag("MinigameProximityTag"))
	{
		OtherComp->ComponentTags.Add("MinigameProximityTag");
	}
}

void AKitchenSinkComponents::BoxCollisionOnEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	if (OtherComp == nullptr)
		return;

	if (OtherComp->ComponentHasTag("PlayerInteractComponentTag"))
	{
		OtherComp->ComponentTags.Remove("MinigameProximityTag");
	}
}

// Called every frame
void AKitchenSinkComponents::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AKitchenSinkComponents::MinigameInteract()
{
	APlayerController* PlayerController = UGameplayStatics::GetPlayerController(this, 0);
	PlayerController->SetViewTargetWithBlend(this, 0.5f,EViewTargetBlendFunction::VTBlend_Linear,true);
	Minigame->ShowArrowPrompts();
}

