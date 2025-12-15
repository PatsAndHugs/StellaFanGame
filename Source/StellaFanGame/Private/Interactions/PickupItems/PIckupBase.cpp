// Fill out your copyright notice in the Description page of Project Settings.


#include "Interactions/PickupItems/PIckupBase.h"
#include "Components/SphereComponent.h"
#include "Interactions/ItemPool/ItemPool.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
APIckupBase::APIckupBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
    
    SphereComp = CreateDefaultSubobject<USphereComponent>("SphereComponent");
	RootComponent = SphereComp;
	
    PickupMesh = CreateDefaultSubobject<UStaticMeshComponent>("PickupMesh");
    PickupMesh->SetupAttachment(RootComponent);
    Tags.Add("PickupTag");

	
}

// Called when the game starts or when spawned
void APIckupBase::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APIckupBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void APIckupBase::PickupItem()
{
	UE_LOG(LogTemp, Warning, TEXT("Item Picked Up"));
	//SetActorLocation()
	TArray<AActor*> FoundActors;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AItemPool::StaticClass(),FoundActors);

	if (FoundActors.Num() > 0)
	{
		UE_LOG(LogTemp, Warning, TEXT("ItemPoolValid"));
		FHitResult HitResult;
		SetActorLocation(FoundActors[0]->GetActorLocation(),false,&HitResult,ETeleportType::TeleportPhysics);
	}
	
}

