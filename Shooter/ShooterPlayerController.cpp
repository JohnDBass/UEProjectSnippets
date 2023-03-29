// Fill out your copyright notice in the Description page of Project Settings.


#include "ShooterPlayerController.h"
#include "TimerManager.h"
#include "Blueprint/UserWidget.h"



void AShooterPlayerController::BeginPlay()
{
	Super::BeginPlay();
    PlayerHUD = CreateWidget(this, PlayerHUDClass);
    if (PlayerHUD)
    {
        PlayerHUD->AddToViewport();
    }
}

void AShooterPlayerController::GameHasEnded(class AActor *EndGameFocus, bool bIsWinner)
{
    Super::GameHasEnded(EndGameFocus, bIsWinner);

    if (bIsWinner)
    {
        UUserWidget* WinScreen = CreateWidget(this, WinScreenClass);
        if (WinScreen)
        {
            PlayerHUD->RemoveFromParent();
            WinScreen->AddToViewport();
        }
    }
    else
    {
        UUserWidget* LoseScreen = CreateWidget(this, LoseScreenClass);
        if (LoseScreen)
        {
            PlayerHUD->RemoveFromParent();
            LoseScreen->AddToViewport();
        }
    }
    GetWorldTimerManager().SetTimer(RestartTimer, this, &APlayerController::RestartLevel, RestartDelay);
}

