#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "GGPlayerController.generated.h"

/**
 * Screen configuration options for multiplayer games
 */
UENUM(BlueprintType)
enum class EGGScreenMode : uint8
{
    SharedScreen UMETA(DisplayName = "Shared Screen"),
    SplitScreenHorizontal UMETA(DisplayName = "Split Screen Horizontal"),
    SplitScreenVertical UMETA(DisplayName = "Split Screen Vertical"),
    DynamicSplitScreen UMETA(DisplayName = "Dynamic Split Screen")
};

/**
 * Camera behavior options for third person control
 */
UENUM(BlueprintType)
enum class EGGCameraMode : uint8
{
    FollowPlayer UMETA(DisplayName = "Follow Player"),
    FixedAngle UMETA(DisplayName = "Fixed Angle"),
    TopDown UMETA(DisplayName = "Top Down"),
    Custom UMETA(DisplayName = "Custom")
};

/**
 * Delegate for character movement events
 */
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMovementInputDelegate, FVector2D, MovementVector);

/**
 * Delegate for character action events
 */
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnActionInputDelegate);

/**
 * Base player controller class for Garden Gladiators
 * Provides third-person controls with support for shared screen, split-screen,
 * and blueprint extensions for different game modes
 */
UCLASS(Blueprintable, BlueprintType)
class GARDENGLADIATORS_API AGGPlayerController : public APlayerController
{
    GENERATED_BODY()

public:
    AGGPlayerController();

    /** Called when controller possesses a pawn */
    virtual void OnPossess(APawn* InPawn) override;
    
    /** Called when controller unpossesses a pawn */
    virtual void OnUnPossess() override;

    //~ Begin Input Handling

    /** Process movement input and pass to character */
    UFUNCTION(BlueprintCallable, Category = "GG|Input")
    virtual void ProcessMovementInput(float ForwardValue, float RightValue);

    /** Process camera rotation input */
    UFUNCTION(BlueprintCallable, Category = "GG|Input")
    virtual void ProcessCameraInput(float YawValue, float PitchValue);

    /** Process jump input */
    UFUNCTION(BlueprintCallable, Category = "GG|Input")
    virtual void ProcessJumpInput();

    /** Process sprint input */
    UFUNCTION(BlueprintCallable, Category = "GG|Input")
    virtual void ProcessSprintInput(bool bStartSprint);

    /** Process primary action input */
    UFUNCTION(BlueprintCallable, Category = "GG|Input")
    virtual void ProcessPrimaryActionInput();

    /** Process secondary action input */
    UFUNCTION(BlueprintCallable, Category = "GG|Input")
    virtual void ProcessSecondaryActionInput();

    /** Process interaction input */
    UFUNCTION(BlueprintCallable, Category = "GG|Input")
    virtual void ProcessInteractionInput();

    //~ End Input Handling

    //~ Begin Blueprint Extensible Functions

    /** 
     * Called when movement input is received
     * Can be overridden in Blueprints to customize movement behavior
     */
    UFUNCTION(BlueprintNativeEvent, Category = "GG|Movement")
    void OnMovementInput(float ForwardValue, float RightValue);

    /** 
     * Called when jump input is received
     * Can be overridden in Blueprints to customize jump behavior
     */
    UFUNCTION(BlueprintNativeEvent, Category = "GG|Movement")
    void OnJumpInput();

    /** 
     * Called when sprint input is received
     * Can be overridden in Blueprints to customize sprint behavior
     */
    UFUNCTION(BlueprintNativeEvent, Category = "GG|Movement")
    void OnSprintInput(bool bStartSprint);

    /** 
     * Called when primary action input is received
     * Can be implemented in Blueprints for character-specific actions
     */
    UFUNCTION(BlueprintImplementableEvent, Category = "GG|Actions")
    void OnPrimaryAction();

    /** 
     * Called when secondary action input is received
     * Can be implemented in Blueprints for character-specific actions
     */
    UFUNCTION(BlueprintImplementableEvent, Category = "GG|Actions")
    void OnSecondaryAction();

    /** 
     * Called when interaction input is received
     * Can be implemented in Blueprints for character-specific interactions
     */
    UFUNCTION(BlueprintImplementableEvent, Category = "GG|Interaction")
    void OnInteractionInput();

    /** 
     * Called when camera settings should be updated (e.g., on game mode change)
     * Can be overridden in Blueprints to customize camera behavior
     */
    UFUNCTION(BlueprintNativeEvent, Category = "GG|Camera")
    void UpdateCameraSettings();

    //~ End Blueprint Extensible Functions

    //~ Begin Camera Configuration

    /** Sets the camera mode for this player controller */
    UFUNCTION(BlueprintCallable, Category = "GG|Camera")
    void SetCameraMode(EGGCameraMode NewCameraMode);

    /** Gets the current camera mode */
    UFUNCTION(BlueprintPure, Category = "GG|Camera")
    EGGCameraMode GetCameraMode() const { return CameraMode; }

    /** Sets the screen mode for multiplayer games */
    UFUNCTION(BlueprintCallable, Category = "GG|Screen")
    void SetScreenMode(EGGScreenMode NewScreenMode);

    /** Gets the current screen mode */
    UFUNCTION(BlueprintPure, Category = "GG|Screen")
    EGGScreenMode GetScreenMode() const { return ScreenMode; }

    //~ End Camera Configuration

    //~ Begin Delegates

    /** Delegate fired when movement input is processed */
    UPROPERTY(BlueprintAssignable, Category = "GG|Delegates")
    FOnMovementInputDelegate OnMovementInputDelegate;

    /** Delegate fired when jump input is processed */
    UPROPERTY(BlueprintAssignable, Category = "GG|Delegates")
    FOnActionInputDelegate OnJumpInputDelegate;

    /** Delegate fired when sprint input is processed */
    UPROPERTY(BlueprintAssignable, Category = "GG|Delegates")
    FOnActionInputDelegate OnSprintStartDelegate;

    /** Delegate fired when sprint is released */
    UPROPERTY(BlueprintAssignable, Category = "GG|Delegates")
    FOnActionInputDelegate OnSprintEndDelegate;

    /** Delegate fired when primary action input is processed */
    UPROPERTY(BlueprintAssignable, Category = "GG|Delegates")
    FOnActionInputDelegate OnPrimaryActionDelegate;

    /** Delegate fired when secondary action input is processed */
    UPROPERTY(BlueprintAssignable, Category = "GG|Delegates")
    FOnActionInputDelegate OnSecondaryActionDelegate;

    /** Delegate fired when interaction input is processed */
    UPROPERTY(BlueprintAssignable, Category = "GG|Delegates")
    FOnActionInputDelegate OnInteractionDelegate;

    //~ End Delegates

protected:
    virtual void BeginPlay() override;
    virtual void SetupInputComponent() override;
    virtual void Tick(float DeltaTime) override;

    //~ Begin Input Properties

    /** Sensitivity for camera movement (yaw) */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GG|Input", meta = (ClampMin = "0.1", ClampMax = "5.0"))
    float CameraYawSensitivity = 1.0f;

    /** Sensitivity for camera movement (pitch) */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GG|Input", meta = (ClampMin = "0.1", ClampMax = "5.0"))
    float CameraPitchSensitivity = 1.0f;

    /** Dead zone for analog stick input */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GG|Input", meta = (ClampMin = "0.0", ClampMax = "0.5"))
    float AnalogStickDeadZone = 0.25f;

    /** Whether to invert the Y-axis for camera control */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GG|Input")
    bool bInvertYAxis = false;

    /** Whether to invert the X-axis for camera control */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GG|Input")
    bool bInvertXAxis = false;

    //~ End Input Properties

    //~ Begin Camera Properties

    /** Current camera mode */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GG|Camera")
    EGGCameraMode CameraMode = EGGCameraMode::FollowPlayer;

    /** Distance from camera to player in follow mode */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GG|Camera", meta = (ClampMin = "100.0", ClampMax = "1000.0"))
    float CameraDistance = 300.0f;

    /** Height offset for camera in follow mode */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GG|Camera", meta = (ClampMin = "-200.0", ClampMax = "500.0"))
    float CameraHeightOffset = 70.0f;

    /** Fixed camera pitch angle (for fixed angle mode) */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GG|Camera", meta = (ClampMin = "-89.0", ClampMax = "89.0"))
    float FixedCameraPitch = -30.0f;

    /** Camera lag speed (lower = more lag) */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GG|Camera", meta = (ClampMin = "1.0", ClampMax = "20.0"))
    float CameraLagSpeed = 10.0f;

    /** Whether to use camera lag for smoother following */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GG|Camera")
    bool bUseCameraLag = true;

    //~ End Camera Properties

    //~ Begin Screen Configuration

    /** Current screen mode for multiplayer */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GG|Screen")
    EGGScreenMode ScreenMode = EGGScreenMode::SharedScreen;

    /** Distance threshold for dynamic split screen (when players are this far apart, split screen activates) */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GG|Screen", meta = (ClampMin = "500.0", ClampMax = "5000.0"))
    float DynamicSplitScreenThreshold = 1000.0f;

    //~ End Screen Configuration

private:
    /** Reference to possessed character (cached for performance) */
    UPROPERTY()
    class AGGPlayerCharacter* PlayerCharacter;

    /** Apply camera settings to the character's camera boom */
    void ApplyCameraSettings();

    /** Process analog stick input with dead zone */
    float ProcessAnalogInputWithDeadZone(float RawInput);
};