// Fill out your copyright notice in the Description page of Project Settings.


#include "SpinmeisterGameInstance.h"

#include "PlayerStateBase.h"

void USpinmeisterGameInstance::ProgressPlayerState()
{
	switch(CurrentPlayerState)
	{
		case EGameCurrentState::FPSIntro:
			CurrentPlayerState = EGameCurrentState::SpinnerIntro;
			break;
			
		case EGameCurrentState::SpinnerIntro:
			CurrentPlayerState = EGameCurrentState::FPSLevel1;
			break;
		
		case EGameCurrentState::FPSLevel1:
			CurrentPlayerState = EGameCurrentState::SpinnerLevel1;
			break;

		case EGameCurrentState::SpinnerLevel1:
			CurrentPlayerState = EGameCurrentState::FPSLevel2;
			break;

		case EGameCurrentState::FPSLevel2:
			CurrentPlayerState = EGameCurrentState::SpinnerLevel2;
			break;	

		case EGameCurrentState::SpinnerLevel2:
			CurrentPlayerState = EGameCurrentState::FPSLevel3;
			break;
		
	}
	
		
}
