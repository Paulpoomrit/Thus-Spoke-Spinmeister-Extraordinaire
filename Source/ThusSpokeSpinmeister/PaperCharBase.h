// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "InputAction.h"
#include "CoreMinimal.h"
#include "PaperZDCharacter.h"
#include "PaperCharBase.generated.h"

class UInputMappingContext;

UCLASS()
class THUSSPOKESPINMEISTER_API APaperCharBase : public APaperZDCharacter
{
	GENERATED_BODY()

protected:
	virtual void BeginPlay() override;

	// called for movement input
	void Move(const FInputActionValue& InputValue);
	void StartJump(const FInputActionValue& InputValue);
	void StopJump(const FInputActionValue& InputValue);

	// Mapping Context for Player Input
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Input")
	UInputMappingContext* PaperCharMappingContext;

	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Input")
	const UInputAction* MoveAction;

	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Input")
	const UInputAction* JumpAction;

	virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;
};



