// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PickableItemBase.generated.h"

UENUM(BlueprintType)
enum class EItemType : uint8
{
	Shield = 0 UMETA(DisplayName = "Shield"),
	Health = 1 UMETA(DisplayName = "Health"),
	Bullet = 2 UMETA(DisplayName = "Bullet"),
	Shell = 3 UMETA(DisplayName = "Shell"),
	Rocket = 4 UMETA(DisplayName = "Rocket"),
	Cell = 5 UMETA(DisplayName = "Cell"),
};

UCLASS()
class THUSSPOKESPINMEISTER_API APickableItemBase : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APickableItemBase();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;


	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EItemType ItemType = EItemType::Shield;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float ItemAmount;
	
	UFUNCTION(BlueprintCallable)
	void UpdateItem();

};
