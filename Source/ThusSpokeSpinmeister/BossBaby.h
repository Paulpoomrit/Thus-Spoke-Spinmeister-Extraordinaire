// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SpinmeisterGameInstance.h"
#include "PlayerStateBase.h"
#include "Baby.h"
#include "Kismet/GameplayStatics.h"
#include "BossBaby.generated.h"

/**
 * 
 */
UCLASS()
class THUSSPOKESPINMEISTER_API ABossBaby : public ABaby
{
	GENERATED_BODY()
private:

	const float OriginalMaxHealth = 250.0f;
	float NextHealthThresholdForSpawning = OriginalMaxHealth;
	int NumberOfMinionsToSpawn = 5;
	float HealthForEachMinion = 1;
	int CurrentMinionDamage = 5;
	APlayerStateBase* CurrentPlayerState;
	USpinmeisterGameInstance* CurrentGameInstance;
	
	FName LevelToOpen = FName("DEMO_Map");

	
public:

	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable)
	void SpawnBabies(int NumBabies, float NewBabyHealth, float NewBabyDamage);

	virtual bool BeingDamaged(float DamageAmount) override;

	UFUNCTION(BlueprintCallable)
	float GetHealthPercentage() const;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<class ABaby> BabyClass;

	FTransform GetRandomizedBabyTransform(int seed) const;
};
