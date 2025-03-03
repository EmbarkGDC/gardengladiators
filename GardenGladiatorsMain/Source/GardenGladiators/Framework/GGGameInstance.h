#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "Framework/GGTypes.h"
#include "GGGameInstance.generated.h"

UCLASS()
class GARDENGLADIATORS_API UGGGameInstance : public UGameInstance
{
    GENERATED_BODY()

public:
    UGGGameInstance();

    virtual void Init() override;

    // Game state management
    UFUNCTION(BlueprintCallable, Category = "Game Flow")
    void TransitionToOverworld();

    UFUNCTION(BlueprintCallable, Category = "Game Flow")
    void TransitionToMiniGame(const FString& MiniGameName);

    // Player data management
    UFUNCTION(BlueprintCallable, Category = "Player Data")
    void SavePlayerProgress();

    UFUNCTION(BlueprintCallable, Category = "Player Data")
    void LoadPlayerProgress();

protected:
    // Current game state tracking
    UPROPERTY()
    EGGGameState CurrentGameState;

    // Player progress data
    UPROPERTY()
    TArray<FGGPlayerData> PlayerDataArray;

    // Save game handling
    UFUNCTION()
    void HandleSaveGameComplete(const FString& SlotName, const int32 UserIndex, bool bSuccess);

    UFUNCTION()
    void HandleLoadGameComplete(const FString& SlotName, const int32 UserIndex, bool bSuccess);
};