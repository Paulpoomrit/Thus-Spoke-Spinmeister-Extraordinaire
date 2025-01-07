// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseRetroWeapon.h"

// Sets default values
ABaseRetroWeapon::ABaseRetroWeapon()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ABaseRetroWeapon::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABaseRetroWeapon::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABaseRetroWeapon::FireWeapon()
{
	const FVector Start = GetActorLocation();
	const FVector End = Start + GetActorForwardVector() * MaxShootDistance;
	DrawDebugLine(GetWorld(), Start, End, FColor::Red, true);
	DrawDebugSphere(GetWorld(), End, 10, 10 , FColor::Blue, true);
}

