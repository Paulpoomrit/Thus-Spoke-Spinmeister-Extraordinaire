// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "FirstPersonCharacter.generated.h"

UENUM(BlueprintType)
enum class EWeaponType : uint8
{
	Pistol = 0b0000 UMETA(DisplayName = "Pistol"),
	MiniGun = 0b0001 UMETA(DisplayName = "MiniGun"),
	PlasmaRifle = 0b0010 UMETA(DisplayName = "PlasmaRifle"),
	RPG = 0b0011 UMETA(DisplayName = "RPG"),
	BFG = 0b1000 UMETA(DisplayName = "BFG"),
	Chainsaw = 0b1001 UMETA(DisplayName = "Chainsaw"),
	Fist = 0b1010 UMETA(DisplayName = "Fist"),
};


UCLASS()
class THUSSPOKESPINMEISTER_API AFirstPersonCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AFirstPersonCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Ammo)
	int CurrentBullet;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Ammo)
	int CurrentShell;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Ammo)
	int CurrentRocket;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Ammo)
	int CurrentCell;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Ammo)
	int MaxBullet = 200;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Ammo)
	int MaxShell = 50;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Ammo)
	int MaxRocket = 50;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Ammo)
	int MaxCell = 300;
};
