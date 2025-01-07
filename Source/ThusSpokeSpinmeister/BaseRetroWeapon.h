// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BaseRetroWeapon.generated.h"

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

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Gameplay")
	int MaxShootDistance = 400;

	UFUNCTION(BlueprintCallable, Category="Gameplay")
	void FireWeapon();
};
