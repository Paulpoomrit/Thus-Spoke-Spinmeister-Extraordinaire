// Fill out your copyright notice in the Description page of Project Settings.


#include "FirstPersonCharacter.h"
#include "SpinmeisterGameInstance.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AFirstPersonCharacter::AFirstPersonCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AFirstPersonCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AFirstPersonCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AFirstPersonCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void AFirstPersonCharacter::UpdatePlayerHealthAndShield(float Damage)
{
	if (Shield > 0 && Shield >= Damage)
	{
		Shield -= Damage;
	}
	else if (Shield > 0 && Shield < Damage)
	{
		Damage -= Shield;
		Shield = 0;
		Health -= Damage;
	}
	else
	{
		Health -= Damage;
	}
}

bool AFirstPersonCharacter::HasLowHealth() const
{
	return Health <= 20;
}

bool AFirstPersonCharacter::IsDead() const
{
	return Health <= 0;
}


