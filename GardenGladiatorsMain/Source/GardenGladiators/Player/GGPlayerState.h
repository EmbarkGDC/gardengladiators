#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "Framework/GGTypes.h"
#include "GGPlayerState.generated.h"

UCLASS()
class GARDENGLADIATORS_API AGGPlayerState : public APlayerState
{
    GENERATED_BODY()

public:
    AGGPlayerState();

    UFUNCTION(BlueprintCallable, Category = "Player Data")
    void SetPlayerData(const FGGPlayerData& NewPlayerData);

    UFUNCTION(BlueprintPure, Category = "Player Data")
    const FGGPlayerData& GetPlayerData() const { return PlayerData; }

protected:
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

    UPROPERTY(ReplicatedUsing = OnRep_PlayerData)
    FGGPlayerData PlayerData;

    UFUNCTION()
    void OnRep_PlayerData();
};