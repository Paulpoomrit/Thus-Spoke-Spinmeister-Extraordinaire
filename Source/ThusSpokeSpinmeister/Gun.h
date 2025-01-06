// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Gun.generated.h"
#include "NiagaraFunctionLibrary.h"
#include "Weapon.h"

UCLASS()
class THUSSPOKESPINMEISTER_API AGun : public AActor
{
	GENERATED_BODY()

	UPROPERTY(VisibleDefaultsOnly, Category="Mesh")
	UStaticMeshComponent* MeshComponent;
	
public:	
	// Sets default values for this actor's properties
	AGun();

	// Gun Sound Effect
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Sound")
	USoundBase* FireSound;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Sound")
	USoundBase* EmptySound;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Sound")
	TArray<USoundBase*> EnvironmentalSound;

	// Muzzle Offset
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Gameplay")
	FVector MuzzleOffset = FVector(100.f, 0, 10.f);

	// Muzzle Flash
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="SFX")
	UNiagaraSystem* MuzzleFlash;

    // Ammo Sizes
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Gameplay")
	int ClipSize = 8;

	// Max Ammo
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Gameplay")
	int MaxAmmo = 80;
		

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
