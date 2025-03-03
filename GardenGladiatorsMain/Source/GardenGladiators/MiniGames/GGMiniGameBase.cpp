#include "GGMiniGameBase.h"
#include "GGMiniGameState.h"

AGGMiniGameBase::AGGMiniGameBase()
{
    PrimaryActorTick.bCanEverTick = true;

    // Set default values
    bIsActive = false;
    bIsPaused = false;
    GameDuration = 60.0f; // Default 60 seconds
}

void AGGMiniGameBase::BeginPlay()
{
    Super::BeginPlay();
}

void AGGMiniGameBase::StartMiniGame()
{
    if (!bIsActive)
    {
        bIsActive = true;
        bIsPaused = false;

        // Find and initialize mini-game state
        if (UWorld* World = GetWorld())
        {
            MiniGameState = Cast<AGGMiniGameState>(World->GetGameState());
        }

        OnMiniGameStart.Broadcast();
    }
}

void AGGMiniGameBase::EndMiniGame()
{
    if (bIsActive)
    {
        bIsActive = false;
        bIsPaused = false;

        OnMiniGameEnd.Broadcast();

        // Cleanup and reset mini-game state
        if (MiniGameState)
        {
            // Reset state
        }
    }
}

void AGGMiniGameBase::PauseMiniGame()
{
    if (bIsActive && !bIsPaused)
    {
        bIsPaused = true;
        // Implement pause logic
    }
}

void AGGMiniGameBase::ResumeMiniGame()
{
    if (bIsActive && bIsPaused)
    {
        bIsPaused = false;
        // Implement resume logic
    }
}