#include "GGGameState.h"
#include "Net/UnrealNetwork.h"

AGGGameState::AGGGameState()
{
    CurrentGameState = EGGGameState::None;
}

void AGGGameState::OnRep_CurrentGameState()
{
    // Handle state changes
}

void AGGGameState::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(AGGGameState, CurrentGameState);
}