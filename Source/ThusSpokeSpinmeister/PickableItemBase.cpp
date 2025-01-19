// Fill out your copyright notice in the Description page of Project Settings.


#include "PickableItemBase.h"

#include "FirstPersonCharacter.h"

// Sets default values
APickableItemBase::APickableItemBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void APickableItemBase::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APickableItemBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void APickableItemBase::UpdateItem()
{
	AFirstPersonCharacter* Player = Cast<AFirstPersonCharacter>(GetWorld()->GetFirstPlayerController()->GetCharacter());
	switch(ItemType)
	{
	case EItemType::Shield:
		Player->Shield += ItemAmount;
	case EItemType::Health:
		Player->Health += ItemAmount;
	case EItemType::Bullet:
		Player->CurrentBullet += ItemAmount;
	case EItemType::Cell:
		Player->CurrentCell += ItemAmount;
	case EItemType::Rocket:
		Player->CurrentRocket += ItemAmount;
	case EItemType::Shell:
		Player->CurrentShell += ItemAmount;
	}
}

