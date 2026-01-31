// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/SceneComponents/KitchenSinkComponents.h"

#include "EnhancedInputSubsystems.h"
#include "Camera/CameraComponent.h"
#include "Components/BoxComponent.h"
#include "Components/MiniGames/DishWashingMinigame.h"
#include "GameFramework/SpringArmComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Blueprint/UserWidget.h"

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
	PlayerController = UGameplayStatics::GetPlayerController(GetWorld(),0);
	MinigameWidget = CreateWidget(PlayerController, DishWashingMinigameWidget);

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
	PlayerController = UGameplayStatics::GetPlayerController(this, 0);
	PlayerController->SetViewTargetWithBlend(this, 0.5f,EViewTargetBlendFunction::VTBlend_Linear,true);
	//Minigame->ShowArrowPrompts();
	//ShowMinigameWidget();
}

void AKitchenSinkComponents::ChangeToNewMappingContext()
{
	ChangeMappingContext(DishWashingMappingContext, DefaultMappingContext);
}

void AKitchenSinkComponents::RevertToDefaultMappingContext()
{
	ChangeMappingContext(DefaultMappingContext, DishWashingMappingContext);
	//RemoveMinigameWidget();
}

void AKitchenSinkComponents::PlayerPressedUp()
{
	UE_LOG(LogTemp, Warning, TEXT("PlayerPressedUp"));
	Minigame->AddUpInput();
}

void AKitchenSinkComponents::PlayerPressedDown()
{
	UE_LOG(LogTemp, Warning, TEXT("PlayerPressedDown"));
	Minigame->AddDownInput();
}

void AKitchenSinkComponents::PlayerPressedLeft()
{
	UE_LOG(LogTemp, Warning, TEXT("PlayerPressedLeft"));
	Minigame->AddLeftInput();
}

void AKitchenSinkComponents::PlayerPressedRight()
{
	UE_LOG(LogTemp, Warning, TEXT("PlayerPressedRight"));
	Minigame->AddRightInput();

}

void AKitchenSinkComponents::ResetPlayerScore()
{
	Minigame->ClearPlayerScore();
}

void AKitchenSinkComponents::StartEasyGame()
{
	Minigame->ShowArrowPrompts();
}

void AKitchenSinkComponents::SetMinigameDifficultyLevel(int32 DifficultyLevel)
{
	Minigame->SetDifficultyLevel(DifficultyLevel);
}

int32 AKitchenSinkComponents::GetDifficultyLevel()
{
	return Minigame->GetDifficultyLevel();
}

void AKitchenSinkComponents::ExitMinigame()
{
	RevertToDefaultMappingContext();
	ResetPlayerScore();
}

void AKitchenSinkComponents::ChangeMappingContext(const UInputMappingContext* NewMappingContext,
                                                  const UInputMappingContext* OldMappingContext)
{
	PlayerController = UGameplayStatics::GetPlayerController(GetWorld(),0);
	if (ULocalPlayer* LocalPlayer = Cast<ULocalPlayer>(PlayerController->GetLocalPlayer()))
	{
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = LocalPlayer->GetSubsystem<UEnhancedInputLocalPlayerSubsystem>())
		{
			// Remove the general gameplay context
			Subsystem->RemoveMappingContext(OldMappingContext);
			
			// Add the menu-specific context. Give it a higher priority (e.g., 1) to ensure it takes precedence over any remaining base contexts
			Subsystem->AddMappingContext(NewMappingContext, 1);
			UE_LOG(LogTemp, Warning, TEXT("Mapping Context Change"));
		}
	}
}

void AKitchenSinkComponents::ShowMinigameWidget()
{
	if (MinigameWidget != nullptr)
	{
		MinigameWidget->AddToViewport();
	}
}

void AKitchenSinkComponents::RemoveMinigameWidget()
{
	if (MinigameWidget != nullptr)
	{
		MinigameWidget->RemoveFromParent();
	}
}


