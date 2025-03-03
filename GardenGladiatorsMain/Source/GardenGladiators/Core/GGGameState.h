#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"
#include "Framework/GGTypes.h"
#include "GGGameState.generated.h"

UCLASS()
class GARDENGLADIATORS_API AGGGameState : public AGameStateBase
{
    GENERATED_BODY()

public:
    AGGGameState();

protected:
    UPROPERTY(ReplicatedUsing = OnRep_CurrentGameState)
    EGGGameState CurrentGameState;

    UFUNCTION()
    void OnRep_CurrentGameState();
};