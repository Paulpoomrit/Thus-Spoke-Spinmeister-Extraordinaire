// Fill out your copyright notice in the Description page of Project Settings.


#include "BossBaby.h"
#include "Kismet/GameplayStatics.h"
#include "Math/TransformCalculus3D.h"

void ABossBaby::BeginPlay()
{
	Super::BeginPlay();
	this->BabyHealth = OriginalMaxHealth;
	this->MaxMeleeAttackDistance = 500;
	
	CurrentPlayerState = Cast<APlayerStateBase>(UGameplayStatics::GetPlayerState(this, 0));
	CurrentGameInstance = Cast<USpinmeisterGameInstance>(UGameplayStatics::GetGameInstance(this));
	if (CurrentGameInstance)
	{
		UE_LOG(LogTemp, Error, TEXT("GameInstance is %s"), *CurrentGameInstance->GetName());
		EGameCurrentState CurrentGameState = CurrentGameInstance->GetCurrentPlayerState();
		switch (CurrentGameState)
		{
		case EGameCurrentState::FPSLevel1:
			HealthForEachMinion = 2;
			break;
		case EGameCurrentState::FPSLevel2:
			HealthForEachMinion = 3;
			break;
		case EGameCurrentState::FPSLevel3:
			HealthForEachMinion = 4;
			break;
		case EGameCurrentState::FPSLevelRepeat:
			HealthForEachMinion = 5;
			break;
		default:
			HealthForEachMinion = 1;
			break;
		}
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("GameInstanceNotFound"));
	}
	UE_LOG(LogTemp, Error, TEXT("HealthMinions: %f"), HealthForEachMinion);
	SpawnBabies(5,HealthForEachMinion,5);
}

void ABossBaby::SpawnBabies(int NumBabies, float NewBabyHealth, float NewBabyDamage)
{
	for (int i = 0; i < NumBabies; i++)
	{
		ABaby* BabyMinionRef = GetWorld()->SpawnActorDeferred<ABaby>(BabyClass, FTransform(FRotator(0, 0, 0)));
		if (BabyMinionRef)
		{
			UE_LOG(LogTemp, Warning, TEXT("Baby is being spawned"));
			FTransform SpawnTransform = GetRandomizedBabyTransform(i);
			BabyMinionRef->BabyDamage = NewBabyDamage;
			BabyMinionRef->BabyHealth = NewBabyHealth;
			BabyMinionRef->SpawnDefaultController();
			BabyMinionRef->FinishSpawning(SpawnTransform);
		}
	} 
}

int NextHealthThresholdForSpawning;

bool ABossBaby::BeingDamaged(float DamageAmount)
{
	Super::BeingDamaged(DamageAmount);
	
	if (BabyHealth <= NextHealthThresholdForSpawning-25)
	{
		SpawnBabies(NumberOfMinionsToSpawn,HealthForEachMinion,CurrentMinionDamage);
		NumberOfMinionsToSpawn+=5;
		CurrentMinionDamage++;
		NextHealthThresholdForSpawning -= 25;
	}
	
	return true;
}

float ABossBaby::GetHealthPercentage() const
{
	return BabyHealth/OriginalMaxHealth;
}

FTransform ABossBaby::GetRandomizedBabyTransform(int seed) const
{
	// location here is level-specific
	FTransform SpawnTransform = FTransform(FRotator(0, 0, 0),
			UE::Math::TVector<double>(-19014,-239170,-31601),
			UE::Math::TVector<double>(1,1,1));

	if (seed > 7)
	{
		seed %= 7;
	}

	if (seed == 0)
	{
		SpawnTransform.SetTranslation(SpawnTransform.GetTranslation() + UE::Math::TVector<double>(0,500,0));
	}
	else if (seed == 1)
	{
		SpawnTransform.SetTranslation(SpawnTransform.GetTranslation() + UE::Math::TVector<double>(0,-500,0));
	}
	else if (seed == 2)
	{
		SpawnTransform.SetTranslation(SpawnTransform.GetTranslation() + UE::Math::TVector<double>(500,0,0));
	}
	else if (seed == 3)
	{
		SpawnTransform.SetTranslation(SpawnTransform.GetTranslation() + UE::Math::TVector<double>(-500,0,0));
	}
	else if (seed == 4)
	{
		SpawnTransform.SetTranslation(SpawnTransform.GetTranslation() + UE::Math::TVector<double>(500,500,0));
	}
	else if (seed == 5)
	{
		SpawnTransform.SetTranslation(SpawnTransform.GetTranslation() + UE::Math::TVector<double>(500,-500,0));
	}
	else if (seed == 6)
	{
		SpawnTransform.SetTranslation(SpawnTransform.GetTranslation() + UE::Math::TVector<double>(-500,500,0));
	}
	else 
	{
		SpawnTransform.SetTranslation(SpawnTransform.GetTranslation() + UE::Math::TVector<double>(-500,-500,0));
	}

	return SpawnTransform;
}


