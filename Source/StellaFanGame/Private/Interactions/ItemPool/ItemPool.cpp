// Fill out your copyright notice in the Description page of Project Settings.


#include "Interactions/ItemPool/ItemPool.h"

// Sets default values
AItemPool::AItemPool()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	ItemPoolMesh = CreateDefaultSubobject<UStaticMeshComponent>("ItemPoolMesh");
	Tags.Add("ItemPool");
}

// Called when the game starts or when spawned
void AItemPool::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AItemPool::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

