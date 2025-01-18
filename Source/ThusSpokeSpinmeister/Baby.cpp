// Fill out your copyright notice in the Description page of Project Settings.


#include "Baby.h"

#include "Kismet/GameplayStatics.h"
#include "FirstPersonCharacter.h"

// Sets default values
ABaby::ABaby()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ABaby::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABaby::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ABaby::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ABaby::MeleeAttack()
{
	AFirstPersonCharacter* Player = Cast<AFirstPersonCharacter>(GetWorld()->GetFirstPlayerController()->GetCharacter());
	const FVector Start = GetActorLocation();
	const FVector End = Start + GetActorForwardVector() * MaxMeleeAttackDistance;
	TSubclassOf <UDamageType> MeleeAttack;

	FHitResult Hit;
	FCollisionQueryParams CollisionParams;
	CollisionParams.AddIgnoredActor(this);

	GetWorld()->LineTraceSingleByChannel(Hit, Start, End, ECC_Visibility, CollisionParams);
	DrawDebugLine(GetWorld(), Start, End, Hit.bBlockingHit ? FColor::Red : FColor::Blue, false, 5);
	DrawDebugSphere(GetWorld(), End, 10, 10, Hit.bBlockingHit ? FColor::Red : FColor::Blue, false, 5);

	if (Hit.GetActor() == Player)
	{
		UGameplayStatics::ApplyDamage(Player, BabyDamage, this->GetController(), this, MeleeAttack);
	}
}

