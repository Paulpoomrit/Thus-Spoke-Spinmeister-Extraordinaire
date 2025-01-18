// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Baby.generated.h"

UCLASS()
class THUSSPOKESPINMEISTER_API ABaby : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ABaby();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Gameplay")
	int MaxMeleeAttackDistance = 150;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Gameplay")
	float BabyDamage = 1;
	
	UFUNCTION(BlueprintCallable)
    void MeleeAttack();

};
