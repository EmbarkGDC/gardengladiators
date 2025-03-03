#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"
#include "Framework/GGTypes.h"
#include "GGMiniGameState.generated.h"

UCLASS()
class GARDENGLADIATORS_API AGGMiniGameState : public AGameStateBase
{
    GENERATED_BODY()

public:
    AGGMiniGameState();

    UFUNCTION(BlueprintCallable, Category = "Mini-Game")
    void SetMiniGameActive(bool bActive);

    UFUNCTION(BlueprintPure, Category = "Mini-Game")
    bool IsMiniGameActive() const { return bIsMiniGameActive; }

    UFUNCTION(BlueprintCallable, Category = "Mini-Game")
    void SetTimeRemaining(float NewTime);

    UFUNCTION(BlueprintPure, Category = "Mini-Game")
    float GetTimeRemaining() const { return TimeRemaining; }

protected:
    virtual void BeginPlay() override;
    virtual void Tick(float DeltaTime) override;
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

    UPROPERTY(Replicated)
    bool bIsMiniGameActive;

    UPROPERTY(Replicated)
    float TimeRemaining;

    UPROPERTY(ReplicatedUsing = OnRep_GameScore)
    TArray<FGGPlayerData> PlayerScores;

    UFUNCTION()
    void OnRep_GameScore();
};