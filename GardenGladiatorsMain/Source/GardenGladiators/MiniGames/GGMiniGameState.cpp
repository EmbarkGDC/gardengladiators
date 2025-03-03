#include "GGMiniGameState.h"
#include "Net/UnrealNetwork.h"

AGGMiniGameState::AGGMiniGameState()
{
    PrimaryActorTick.bCanEverTick = true;
    bIsMiniGameActive = false;
    TimeRemaining = 0.0f;
}

void AGGMiniGameState::BeginPlay()
{
    Super::BeginPlay();
}

void AGGMiniGameState::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    if (HasAuthority() && bIsMiniGameActive)
    {
        if (TimeRemaining > 0.0f)
        {
            TimeRemaining = FMath::Max(0.0f, TimeRemaining - DeltaTime);

            // When time runs out
            if (TimeRemaining <= 0.0f)
            {
                SetMiniGameActive(false);
            }
        }
    }
}

void AGGMiniGameState::SetMiniGameActive(bool bActive)
{
    if (HasAuthority())
    {
        bIsMiniGameActive = bActive;
        
        if (!bActive)
        {
            // Handle mini-game end
            TimeRemaining = 0.0f;
        }
    }
}

void AGGMiniGameState::SetTimeRemaining(float NewTime)
{
    if (HasAuthority())
    {
        TimeRemaining = FMath::Max(0.0f, NewTime);
    }
}

void AGGMiniGameState::OnRep_GameScore()
{
    // Handle score updates on clients
}

void AGGMiniGameState::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);

    DOREPLIFETIME(AGGMiniGameState, bIsMiniGameActive);
    DOREPLIFETIME(AGGMiniGameState, TimeRemaining);
    DOREPLIFETIME(AGGMiniGameState, PlayerScores);
}