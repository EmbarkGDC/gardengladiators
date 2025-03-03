#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "GGPlayerCharacter.generated.h"

UCLASS()
class GARDENGLADIATORS_API AGGPlayerCharacter : public ACharacter
{
    GENERATED_BODY()

public:
    AGGPlayerCharacter();

protected:
    virtual void BeginPlay() override;
    virtual void Tick(float DeltaTime) override;
    virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

    // Basic movement functions
    void MoveForward(float Value);
    void MoveRight(float Value);

    // Camera component
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera")
    class UCameraComponent* CameraComponent;

    // Spring arm for camera
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera")
    class USpringArmComponent* CameraBoom;
};