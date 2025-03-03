#include "GGPlayerState.h"
#include "Net/UnrealNetwork.h"

AGGPlayerState::AGGPlayerState()
{
    // Initialize default values
    PlayerData.PlayerName = TEXT("");
    PlayerData.Score = 0;
}

void AGGPlayerState::SetPlayerData(const FGGPlayerData& NewPlayerData)
{
    if (HasAuthority())
    {
        PlayerData = NewPlayerData;
        OnRep_PlayerData();
    }
}

void AGGPlayerState::OnRep_PlayerData()
{
    // Handle any client-side updates when player data changes
}

void AGGPlayerState::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(AGGPlayerState, PlayerData);
}