// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ProjectileBase.h"
#include "GameFramework/Actor.h"
#include "BaseRetroWeapon.generated.h"

UENUM(BlueprintType)
enum class EAmmoType : uint8
{
	Bullet = 0b0000 UMETA(DisplayName = "Bullet"),
	Shell = 0b0001 UMETA(DisplayName = "Shell"),
	Rocket = 0b0010 UMETA(DisplayName = "Rocket"),
	Cell = 0b0011 UMETA(DisplayName = "Cell"),
};

UCLASS()
class THUSSPOKESPINMEISTER_API ABaseRetroWeapon : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABaseRetroWeapon();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Ammo)
    EAmmoType AmmoType = EAmmoType::Bullet;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Gameplay")
	int MaxShootDistance = 1000;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Gameplay")
	float WeaponDamage = 1;

	UFUNCTION(BlueprintCallable, Category="Gameplay")
	void FireWeapon(int AmountOfAmmoNeeded);

	UFUNCTION(BlueprintCallable, Category="Gameplay")
	bool HasEnoughAmmo();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Gameplay")
	float ProjectileSpeed = 4000;

	void DecrementAmmo(int AmountOfAmmoNeeded);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Gameplay")
	TSubclassOf<class AProjectileBase> Projectile;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Gameplay")
	TSubclassOf<class ABlood> Blood;
	
	UFUNCTION(BlueprintCallable, Category="Gameplay")
	void FireProjectile();

	UFUNCTION(BlueprintCallable, Category="Sound")
	void PlayFireSound();
private:
	UPROPERTY(EditAnywhere, Category="Sound")
	USoundBase* WeaponSound;
};
