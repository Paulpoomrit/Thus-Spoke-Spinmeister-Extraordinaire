// Fill out your copyright notice in the Description page of Project Settings.


#include "BossBaby.h"

#include "Kismet/GameplayStatics.h"
#include "Math/TransformCalculus3D.h"

void ABossBaby::BeginPlay()
{
	Super::BeginPlay();
	this->BabyHealth = OriginalMaxHealth;
	this->MaxMeleeAttackDistance = 500;
	SpawnBabies(1,5,5);
}

void ABossBaby::SpawnBabies(int NumBabies, float NewBabyHealth, float NewBabyDamage)
{
	ABaby* BabyMinionRef = GetWorld()->SpawnActorDeferred<ABaby>(BabyClass, FTransform(FRotator(0, 0, 0)));
	if (BabyMinionRef)
	{
		FTransform SpawnTransform = GetRandomizedBabyTransform(NumBabies);
		BabyMinionRef->BabyDamage = NewBabyDamage;
		BabyMinionRef->BabyHealth = NewBabyHealth;
		BabyMinionRef->SpawnDefaultController();
		BabyMinionRef->FinishSpawning(SpawnTransform);
	}
}

bool ABossBaby::BeingDamaged(float DamageAmount)
{
	Super::BeingDamaged(DamageAmount);
	if (BabyHealth == OriginalMaxHealth-50)
	{
		UE_LOG(LogTemp, Warning, TEXT("Spawn Baby!"));
	}
	return true;
}

float ABossBaby::GetHealthPercentage() const
{
	return BabyHealth/OriginalMaxHealth;
}

FTransform ABossBaby::GetRandomizedBabyTransform(int seed) const
{
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


