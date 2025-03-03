#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Framework/GGTypes.h"
#include "GGOverworldManager.generated.h"

UCLASS()
class GARDENGLADIATORS_API AGGOverworldManager : public AActor
{
    GENERATED_BODY()

public:
    AGGOverworldManager();

    // Called when the game enters overworld state
    UFUNCTION(BlueprintCallable, Category = "Overworld")
    void InitializeOverworld();

    // Called when leaving overworld state
    UFUNCTION(BlueprintCallable, Category = "Overworld")
    void CleanupOverworld();

protected:
    virtual void BeginPlay() override;
    virtual void Tick(float DeltaTime) override;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Overworld")
    bool bIsOverworldActive;

    // Reference to currently active interactables
    UPROPERTY()
    TArray<class AGGInteractableBase*> ActiveInteractables;
};