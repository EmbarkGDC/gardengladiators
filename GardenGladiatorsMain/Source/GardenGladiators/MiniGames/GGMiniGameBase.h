#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Framework/GGTypes.h"
#include "GGMiniGameBase.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnMiniGameStart);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnMiniGameEnd);

UCLASS(Abstract)
class GARDENGLADIATORS_API AGGMiniGameBase : public AActor
{
    GENERATED_BODY()

public:
    AGGMiniGameBase();

    // Core mini-game functions
    UFUNCTION(BlueprintCallable, Category = "Mini-Game")
    virtual void StartMiniGame();

    UFUNCTION(BlueprintCallable, Category = "Mini-Game")
    virtual void EndMiniGame();

    UFUNCTION(BlueprintCallable, Category = "Mini-Game")
    virtual void PauseMiniGame();

    UFUNCTION(BlueprintCallable, Category = "Mini-Game")
    virtual void ResumeMiniGame();

    // Delegates for game events
    UPROPERTY(BlueprintAssignable, Category = "Mini-Game|Events")
    FOnMiniGameStart OnMiniGameStart;

    UPROPERTY(BlueprintAssignable, Category = "Mini-Game|Events")
    FOnMiniGameEnd OnMiniGameEnd;

protected:
    virtual void BeginPlay() override;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Mini-Game")
    bool bIsActive;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Mini-Game")
    bool bIsPaused;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Mini-Game")
    float GameDuration;

    // Reference to the mini-game state
    UPROPERTY()
    class AGGMiniGameState* MiniGameState;
};