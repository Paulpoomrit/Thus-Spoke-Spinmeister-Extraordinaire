// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ProjectileBase.generated.h"

UCLASS()
class THUSSPOKESPINMEISTER_API AProjectileBase : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AProjectileBase();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere,BlueprintReadWrite, Category="Projectile Properties")
	float ProjectileSpeed = 0;

	UPROPERTY(EditAnywhere,BlueprintReadWrite, Category="Projectile Properties")
	float ProjectileDamage = 0;

	void SetProjectileSpeed(float value);
	void SetProjectileDamage(float value);
};
