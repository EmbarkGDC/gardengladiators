#include "GGPlayerController.h"
#include "Player/GGPlayerCharacter.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Kismet/GameplayStatics.h"

AGGPlayerController::AGGPlayerController()
{
    // Enable tick for camera updates
    PrimaryActorTick.bCanEverTick = true;
    
    // Default settings for controller
    bAutoManageActiveCameraTarget = true;
}

void AGGPlayerController::BeginPlay()
{
    Super::BeginPlay();
    
    // Apply initial camera settings
    UpdateCameraSettings();
}

void AGGPlayerController::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
    
    // Update camera settings if needed
    if (PlayerCharacter && CameraMode != EGGCameraMode::Custom)
    {
        ApplyCameraSettings();
    }
}

void AGGPlayerController::OnPossess(APawn* InPawn)
{
    Super::OnPossess(InPawn);
    
    // Cache player character reference for performance
    PlayerCharacter = Cast<AGGPlayerCharacter>(InPawn);
    
    // Apply camera settings to newly possessed pawn
    if (PlayerCharacter)
    {
        UpdateCameraSettings();
    }
}

void AGGPlayerController::OnUnPossess()
{
    Super::OnUnPossess();
    
    // Clear cached reference
    PlayerCharacter = nullptr;
}

void AGGPlayerController::SetupInputComponent()
{
    Super::SetupInputComponent();
    
    // Movement bindings
    InputComponent->BindAxis("MoveForward", this, &AGGPlayerController::ProcessMovementInput);
    InputComponent->BindAxis("MoveRight", this, &AGGPlayerController::ProcessMovementInput);
    
    // Camera bindings
    InputComponent->BindAxis("Turn", this, &AGGPlayerController::ProcessCameraInput);
    InputComponent->BindAxis("LookUp", this, &AGGPlayerController::ProcessCameraInput);
    
    // Action bindings
    InputComponent->BindAction("Jump", IE_Pressed, this, &AGGPlayerController::ProcessJumpInput);
    InputComponent->BindAction("Sprint", IE_Pressed, this, &AGGPlayerController::ProcessSprintInput).bExecuteWhenPaused = false;
    InputComponent->BindAction("Sprint", IE_Released, this, &AGGPlayerController::ProcessSprintInput).bExecuteWhenPaused = false;
    InputComponent->BindAction("PrimaryAction", IE_Pressed, this, &AGGPlayerController::ProcessPrimaryActionInput);
    InputComponent->BindAction("SecondaryAction", IE_Pressed, this, &AGGPlayerController::ProcessSecondaryActionInput);
    InputComponent->BindAction("Interact", IE_Pressed, this, &AGGPlayerController::ProcessInteractionInput);
}

void AGGPlayerController::ProcessMovementInput(float ForwardValue, float RightValue)
{
    // Apply dead zone to analog inputs
    ForwardValue = ProcessAnalogInputWithDeadZone(ForwardValue);
    RightValue = ProcessAnalogInputWithDeadZone(RightValue);
    
    // Skip if no significant input
    if (FMath::IsNearlyZero(ForwardValue) && FMath::IsNearlyZero(RightValue))
    {
        return;
    }
    
    // Broadcast movement vector to delegates
    OnMovementInputDelegate.Broadcast(FVector2D(ForwardValue, RightValue));
    
    // Call blueprint extensible function
    OnMovementInput(ForwardValue, RightValue);
}

void AGGPlayerController::ProcessCameraInput(float YawValue, float PitchValue)
{
    // Apply sensitivity and inversion settings
    if (bInvertXAxis)
    {
        YawValue *= -1.0f;
    }
    
    if (bInvertYAxis)
    {
        PitchValue *= -1.0f;
    }
    
    YawValue *= CameraYawSensitivity;
    PitchValue *= CameraPitchSensitivity;
    
    // Apply to controller rotation
    if (!FMath::IsNearlyZero(YawValue))
    {
        AddYawInput(YawValue);
    }
    
    if (!FMath::IsNearlyZero(PitchValue))
    {
        AddPitchInput(PitchValue);
    }
}

void AGGPlayerController::ProcessJumpInput()
{
    // Broadcast to delegates
    OnJumpInputDelegate.Broadcast();
    
    // Call blueprint extensible function
    OnJumpInput();
}

void AGGPlayerController::ProcessSprintInput(bool bStartSprint)
{
    // Broadcast to appropriate delegate
    if (bStartSprint)
    {
        OnSprintStartDelegate.Broadcast();
    }
    else
    {
        OnSprintEndDelegate.Broadcast();
    }
    
    // Call blueprint extensible function
    OnSprintInput(bStartSprint);
}

void AGGPlayerController::ProcessPrimaryActionInput()
{
    // Broadcast to delegates
    OnPrimaryActionDelegate.Broadcast();
    
    // Call blueprint implementable event
    OnPrimaryAction();
}

void AGGPlayerController::ProcessSecondaryActionInput()
{
    // Broadcast to delegates
    OnSecondaryActionDelegate.Broadcast();
    
    // Call blueprint implementable event
    OnSecondaryAction();
}

void AGGPlayerController::ProcessInteractionInput()
{
    // Broadcast to delegates
    OnInteractionDelegate.Broadcast();
    
    // Call blueprint implementable event
    OnInteractionInput();
}

void AGGPlayerController::OnMovementInput_Implementation(float ForwardValue, float RightValue)
{
    // Default implementation passes input to character
    if (PlayerCharacter)
    {
        // Get the controller rotation
        const FRotator Rotation = GetControlRotation();
        const FRotator YawRotation(0, Rotation.Yaw, 0);
        
        // Get forward and right vectors
        const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
        const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
        
        // Add movement in those directions
        PlayerCharacter->AddMovementInput(ForwardDirection, ForwardValue);
        PlayerCharacter->AddMovementInput(RightDirection, RightValue);
    }
}

void AGGPlayerController::OnJumpInput_Implementation()
{
    // Default implementation calls jump on character
    if (PlayerCharacter)
    {
        PlayerCharacter->Jump();
    }
}

void AGGPlayerController::OnSprintInput_Implementation(bool bStartSprint)
{
    // Default implementation would handle sprint
    // This would typically modify movement speed on the character
    // For now, this is a placeholder as the sprint functionality
    // would need to be implemented in the character class
}

void AGGPlayerController::UpdateCameraSettings_Implementation()
{
    // Apply camera settings based on current mode
    ApplyCameraSettings();
    
    // Configure split screen based on screen mode
    switch (ScreenMode)
    {
        case EGGScreenMode::SharedScreen:
            UGameplayStatics::SetViewportSplitScreenState(false);
            break;
            
        case EGGScreenMode::SplitScreenHorizontal:
            UGameplayStatics::SetViewportSplitScreenState(true);
            UGameplayStatics::SetSplitScreenType(ESplitScreenType::TwoPlayer_Horizontal);
            break;
            
        case EGGScreenMode::SplitScreenVertical:
            UGameplayStatics::SetViewportSplitScreenState(true);
            UGameplayStatics::SetSplitScreenType(ESplitScreenType::TwoPlayer_Vertical);
            break;
            
        case EGGScreenMode::DynamicSplitScreen:
            UGameplayStatics::SetViewportSplitScreenState(true);
            UGameplayStatics::ConfigureDynamicSplitScreen(ESplitScreenType::TwoPlayer_Horizontal);
            UGameplayStatics::SetSplitScreenType(ESplitScreenType::None);
            break;
    }
}

void AGGPlayerController::SetCameraMode(EGGCameraMode NewCameraMode)
{
    if (CameraMode != NewCameraMode)
    {
        CameraMode = NewCameraMode;
        UpdateCameraSettings();
    }
}

void AGGPlayerController::SetScreenMode(EGGScreenMode NewScreenMode)
{
    if (ScreenMode != NewScreenMode)
    {
        ScreenMode = NewScreenMode;
        UpdateCameraSettings();
    }
}

void AGGPlayerController::ApplyCameraSettings()
{
    if (!PlayerCharacter)
    {
        return;
    }
    
    // Get camera components
    USpringArmComponent* CameraBoom = PlayerCharacter->CameraBoom;
    UCameraComponent* Camera = PlayerCharacter->CameraComponent;
    
    if (!CameraBoom || !Camera)
    {
        return;
    }
    
    // Apply settings based on camera mode
    switch (CameraMode)
    {
        case EGGCameraMode::FollowPlayer:
            // Standard third-person follow camera
            CameraBoom->TargetArmLength = CameraDistance;
            CameraBoom->SocketOffset = FVector(0.0f, 0.0f, CameraHeightOffset);
            CameraBoom->bUsePawnControlRotation = true;
            Camera->bUsePawnControlRotation = false;
            
            // Apply camera lag settings
            CameraBoom->bEnableCameraLag = bUseCameraLag;
            CameraBoom->CameraLagSpeed = CameraLagSpeed;
            
            // Character rotation settings
            PlayerCharacter->bUseControllerRotationYaw = false;
            if (PlayerCharacter->GetCharacterMovement())
            {
                PlayerCharacter->GetCharacterMovement()->bOrientRotationToMovement = true;
            }
            break;
            
        case EGGCameraMode::FixedAngle:
            // Fixed angle camera that doesn't rotate with input
            CameraBoom->TargetArmLength = CameraDistance;
            CameraBoom->SocketOffset = FVector(0.0f, 0.0f, CameraHeightOffset);
            CameraBoom->bUsePawnControlRotation = false;
            CameraBoom->SetRelativeRotation(FRotator(FixedCameraPitch, 0.0f, 0.0f));
            Camera->bUsePawnControlRotation = false;
            
            // Character rotation settings
            PlayerCharacter->bUseControllerRotationYaw = false;
            if (PlayerCharacter->GetCharacterMovement())
            {
                PlayerCharacter->GetCharacterMovement()->bOrientRotationToMovement = true;
            }
            break;
            
        case EGGCameraMode::TopDown:
            // Top-down camera
            CameraBoom->TargetArmLength = CameraDistance;
            CameraBoom->SocketOffset = FVector(0.0f, 0.0f, 0.0f);
            CameraBoom->bUsePawnControlRotation = false;
            CameraBoom->SetRelativeRotation(FRotator(-90.0f, 0.0f, 0.0f));
            Camera->bUsePawnControlRotation = false;
            
            // Character rotation settings
            PlayerCharacter->bUseControllerRotationYaw = false;
            if (PlayerCharacter->GetCharacterMovement())
            {
                PlayerCharacter->GetCharacterMovement()->bOrientRotationToMovement = true;
            }
            break;
            
        case EGGCameraMode::Custom:
            // Custom mode doesn't modify camera settings
            // This allows Blueprint extensions to fully control the camera
            break;
    }
}

float AGGPlayerController::ProcessAnalogInputWithDeadZone(float RawInput)
{
    // Apply dead zone to analog input
    if (FMath::Abs(RawInput) < AnalogStickDeadZone)
    {
        return 0.0f;
    }
    
    // Rescale the input after removing the dead zone
    const float Sign = (RawInput > 0.0f) ? 1.0f : -1.0f;
    return Sign * (FMath::Abs(RawInput) - AnalogStickDeadZone) / (1.0f - AnalogStickDeadZone);
}