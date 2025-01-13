// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseRetroWeapon.h"

#include "FirstPersonCharacter.h"
#include "Engine/World.h"

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
	AFirstPersonCharacter* Player = Cast<AFirstPersonCharacter>(GetWorld()->GetFirstPlayerController()->GetCharacter());
	const FVector Start = GetActorLocation();
	const FVector End = Start + GetActorForwardVector() * MaxShootDistance;

	FHitResult Hit;
	FCollisionQueryParams CollisionParams; // define the collision
	CollisionParams.AddIgnoredActor(GetWorld()->GetFirstPlayerController()->GetPawn());
	
	GetWorld()->LineTraceSingleByChannel(Hit, Start , End, ECC_Visibility,CollisionParams);
	DrawDebugLine(GetWorld(), Start, End, Hit.bBlockingHit ? FColor::Red : FColor::Blue, true);
	DrawDebugSphere(GetWorld(), End, 10, 10, Hit.bBlockingHit ? FColor::Red : FColor::Blue, true);

	DecrementAmmo();
}

bool ABaseRetroWeapon::HasEnoughAmmo()
{
	AFirstPersonCharacter* Player = Cast<AFirstPersonCharacter>(GetWorld()->GetFirstPlayerController()->GetCharacter());

	switch (AmmoType)
	{
	case EAmmoType::Bullet:
		if (Player->CurrentBullet > 0)
		{
			return true;
		}
		return false;
	case EAmmoType::Shell:
		if (Player->CurrentShell > 0)
		{
			return true;
		} 
		return false;
	case EAmmoType::Rocket:
		if (Player->CurrentRocket > 0)
		{
			return true;
		}
		return false;
	case EAmmoType::Cell:
		if (Player->CurrentCell > 0)
		{
			return true;
		}
		return false;
	}
	
	return true;
}

void ABaseRetroWeapon::DecrementAmmo()
{
	AFirstPersonCharacter* Player = Cast<AFirstPersonCharacter>(GetWorld()->GetFirstPlayerController()->GetCharacter());
	switch (AmmoType)
	{
		case EAmmoType::Bullet:
			Player->CurrentBullet--;
		case EAmmoType::Shell:
			Player->CurrentShell--;
		case EAmmoType::Rocket:
			Player->CurrentRocket--;
		case EAmmoType::Cell:
			Player->CurrentCell--;
	}
}

void ABaseRetroWeapon::FireProjectile()
{
	if (Projectile)
	{
		FActorSpawnParameters SpawnParameters;
		AProjectileBase* ProjectileRef = GetWorld()->SpawnActor<AProjectileBase>(Projectile, GetTransform());
	}
}

