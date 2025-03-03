#include "GGOverworldManager.h"

AGGOverworldManager::AGGOverworldManager()
{
    PrimaryActorTick.bCanEverTick = true;
    bIsOverworldActive = false;
}

void AGGOverworldManager::BeginPlay()
{
    Super::BeginPlay();
}

void AGGOverworldManager::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    if (bIsOverworldActive)
    {
        // Handle overworld tick logic
    }
}

void AGGOverworldManager::InitializeOverworld()
{
    if (!bIsOverworldActive)
    {
        bIsOverworldActive = true;
        // Initialize overworld systems
        // Spawn necessary actors
        // Setup gameplay elements
    }
}

void AGGOverworldManager::CleanupOverworld()
{
    if (bIsOverworldActive)
    {
        bIsOverworldActive = false;
        // Cleanup overworld systems
        // Remove spawned actors
        ActiveInteractables.Empty();
    }
}