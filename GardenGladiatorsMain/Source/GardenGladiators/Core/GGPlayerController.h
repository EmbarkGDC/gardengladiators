#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "GGPlayerController.generated.h"

UCLASS()
class GARDENGLADIATORS_API AGGPlayerController : public APlayerController
{
    GENERATED_BODY()

public:
    AGGPlayerController();

protected:
    virtual void BeginPlay() override;
    virtual void SetupInputComponent() override;
};