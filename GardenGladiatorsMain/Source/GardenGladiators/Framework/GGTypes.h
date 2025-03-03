#pragma once

#include "CoreMinimal.h"
#include "GGTypes.generated.h"

UENUM(BlueprintType)
enum class EGGGameState : uint8
{
    None UMETA(DisplayName = "None"),
    Overworld UMETA(DisplayName = "Overworld"),
    MiniGame UMETA(DisplayName = "MiniGame")
};

USTRUCT(BlueprintType)
struct FGGPlayerData
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString PlayerName;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 Score = 0;
};