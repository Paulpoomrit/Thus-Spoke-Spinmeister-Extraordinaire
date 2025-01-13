// Fill out your copyright notice in the Description page of Project Settings.


#include "PickableWeapon.h"

// Sets default values
APickableWeapon::APickableWeapon()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void APickableWeapon::BeginPlay()
{
	Super::BeginPlay();
	
	
}

// Called every frame
void APickableWeapon::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

