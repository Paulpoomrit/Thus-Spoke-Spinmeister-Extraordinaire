// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseRetroWeapon.h"

#include "Baby.h"
#include "Blood.h"
#include "FirstPersonCharacter.h"
#include "Engine/World.h"
#include "Kismet/GameplayStatics.h"

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

void ABaseRetroWeapon::FireWeapon(int AmountOfAmmoNeeded)
{
	AFirstPersonCharacter* Player = Cast<AFirstPersonCharacter>(GetWorld()->GetFirstPlayerController()->GetCharacter());
	const FVector Start = GetActorLocation();
	const FVector End = Start + GetActorForwardVector() * MaxShootDistance;

	FHitResult Hit;
	FCollisionQueryParams CollisionParams; // define the collision
	CollisionParams.AddIgnoredActor(GetWorld()->GetFirstPlayerController()->GetPawn());
	TSubclassOf<UDamageType> WeaponAttack;
	
	GetWorld()->LineTraceSingleByChannel(Hit, Start , End, ECC_Visibility,CollisionParams);
	DrawDebugLine(GetWorld(), Start, End, Hit.bBlockingHit ? FColor::Red : FColor::Blue, true);
	DrawDebugSphere(GetWorld(), End, 10, 10, Hit.bBlockingHit ? FColor::Red : FColor::Blue, true);
	DecrementAmmo(AmountOfAmmoNeeded);
	
	if (!this->ActorHasTag("BFG"))
	{
		PlayFireSound();
	}
	
	if (Hit.bBlockingHit)
	{
		UE_LOG(LogTemp, Warning, TEXT("Hit Actor: %s"), *Hit.GetActor()->GetName());
		if (Hit.GetActor()->ActorHasTag(FName("Baby")))
		{
			UGameplayStatics::ApplyDamage(Hit.GetActor(), WeaponDamage, GetWorld()->GetFirstPlayerController(), this, WeaponAttack);
			// Spawn Blood
			GetWorld()->SpawnActor<ABlood>(Blood, Hit.Location, Hit.GetActor()->GetActorRotation() + FRotator(0, 90, 0));
		}
	}
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

void ABaseRetroWeapon::DecrementAmmo(int AmountOfAmmoNeeded)
{
	AFirstPersonCharacter* Player = Cast<AFirstPersonCharacter>(GetWorld()->GetFirstPlayerController()->GetCharacter());
	switch (AmmoType)
	{
		case EAmmoType::Bullet:
			Player->CurrentBullet-= AmountOfAmmoNeeded;
		case EAmmoType::Shell:
			Player->CurrentShell-= AmountOfAmmoNeeded;
		case EAmmoType::Rocket:
			Player->CurrentRocket-= AmountOfAmmoNeeded;
		case EAmmoType::Cell:
			Player->CurrentCell-= AmountOfAmmoNeeded;
	}
}

void ABaseRetroWeapon::FireProjectile()
{
	if (Projectile)
	{
		AProjectileBase* ProjectileRef = GetWorld()->SpawnActorDeferred<AProjectileBase>(Projectile, GetTransform());
		ProjectileRef->SetProjectileSpeed(this->ProjectileSpeed);
		ProjectileRef->SetProjectileDamage(this->WeaponDamage);
		ProjectileRef->FinishSpawning(GetTransform());
	}
}

void ABaseRetroWeapon::PlayFireSound()
{
	UGameplayStatics::PlaySound2D(GetWorld(), WeaponSound);
}

