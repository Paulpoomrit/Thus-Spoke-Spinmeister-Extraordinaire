// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "SpinmeisterGameInstance.generated.h"

/**
 * 
 */

UENUM(BlueprintType)
enum class EGameCurrentState : uint8
{
	FPSIntro = 0 UMETA(DisplayName = "FPSIntro"),
	SpinnerIntro = 1 UMETA(DisplayName = "SpinnerIntro"),
	FPSLevel1 = 2 UMETA(DisplayName = "FPSLevel1"),
	SpinnerLevel1 = 3 UMETA(DisplayName = "SpinnerLevel1"),
	FPSLevel2 = 4 UMETA(DisplayName = "FPSLevel2"),
	SpinnerLevel2 = 5 UMETA(DisplayName = "SpinnerLevel2"),
	FPSLevel3 = 6 UMETA(DisplayName = "FPSLevel3"),
	FPSLevelRepeat = 7 UMETA(DisplayName = "FPSLevelRepeat"),
};

UCLASS()
class THUSSPOKESPINMEISTER_API USpinmeisterGameInstance : public UGameInstance
{
	GENERATED_BODY()
	EGameCurrentState CurrentPlayerState = EGameCurrentState::SpinnerLevel2;
	int NumBabiesKilled = 0;
	bool FirstPersonPlayerIsDead = false;

public:
	[[nodiscard]] bool GetFirstPersonPlayerIsDead() const
	{
		return FirstPersonPlayerIsDead;
	}

	void SetFirstPersonPlayerIsDead(const bool bFirstPersonPlayerIsDead)
	{
		FirstPersonPlayerIsDead = bFirstPersonPlayerIsDead;
	}

	UFUNCTION(BlueprintCallable, Category = "Stat")
	[[nodiscard]] int GetNumBabiesKilled() const
	{
		return NumBabiesKilled;
	}

	UFUNCTION(BlueprintCallable, Category = "Stat")
	void IncrementNumBabiesKilled(const int NumBabiesKilled)
	{
		this->NumBabiesKilled++;
	}

	UFUNCTION(BlueprintCallable, Category = "PlayerState")
	[[nodiscard]] EGameCurrentState GetCurrentPlayerState() const
	{
		return CurrentPlayerState;
	}

	UFUNCTION(BlueprintCallable, Category = "PlayerState")
	void SetCurrentPlayerState(const EGameCurrentState CurrentPlayerState)
	{
		this->CurrentPlayerState = CurrentPlayerState;
	}

	UFUNCTION(BlueprintCallable, Category = "PlayerState")
	void ProgressPlayerState();
	
};
