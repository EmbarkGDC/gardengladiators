#include "GGPlayerCharacter.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Kismet/GameplayStatics.h"

AGGPlayerCharacter::AGGPlayerCharacter()
{
    PrimaryActorTick.bCanEverTick = true;

    // Create camera boom
    CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
    CameraBoom->SetupAttachment(RootComponent);
    CameraBoom->TargetArmLength = 300.0f;
    CameraBoom->bUsePawnControlRotation = true;

    // Create follow camera
    CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
    CameraComponent->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);
    CameraComponent->bUsePawnControlRotation = false;

    // Configure character movement
    GetCharacterMovement()->bOrientRotationToMovement = true;
    GetCharacterMovement()->RotationRate = FRotator(0.0f, 540.0f, 0.0f);
    GetCharacterMovement()->JumpZVelocity = 400.0f;
    GetCharacterMovement()->AirControl = 0.2f;

    // Don't rotate when the controller rotates
    bUseControllerRotationPitch = false;
    bUseControllerRotationYaw = false;
    bUseControllerRotationRoll = false;

    // Initialize movement properties
    BaseMovementSpeed = 600.0f;
    SprintSpeedMultiplier = 1.5f;
    bIsSprinting = false;
    CurrentStamina = 100.0f;

    // Initialize sound properties
    bCanPlayFootstep = true;
    bCanPlayVoiceLine = true;
}

void AGGPlayerCharacter::BeginPlay()
{
    Super::BeginPlay();
    
    // Set initial movement speed
    GetCharacterMovement()->MaxWalkSpeed = BaseMovementSpeed;
}

void AGGPlayerCharacter::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    // Check for footstep sounds during movement
    CheckAndPlayFootstep();
}

// ... [Previous movement and basic sound functions remain unchanged] ...

USoundBase* AGGPlayerCharacter::GetRandomSound(const TArray<USoundBase*>& SoundArray)
{
    if (SoundArray.Num() > 0)
    {
        int32 RandomIndex = FMath::RandRange(0, SoundArray.Num() - 1);
        return SoundArray[RandomIndex];
    }
    return nullptr;
}

bool AGGPlayerCharacter::CanPlayVoiceLine() const
{
    return bCanPlayVoiceLine;
}

void AGGPlayerCharacter::StartVoiceLineCooldown()
{
    bCanPlayVoiceLine = false;
    GetWorld()->GetTimerManager().SetTimer(
        VoiceLineCooldownTimer,
        this,
        &AGGPlayerCharacter::EnableVoiceLine,
        VoiceLineCooldown,
        false
    );
}

void AGGPlayerCharacter::PlayRandomVoiceSound(const TArray<USoundBase*>& SoundArray, const FVector2D& VolumeRange, const FVector2D& PitchRange)
{
    if (CanPlayVoiceLine())
    {
        if (USoundBase* SelectedSound = GetRandomSound(SoundArray))
        {
            float RandomVolume = FMath::RandRange(VolumeRange.X, VolumeRange.Y);
            float RandomPitch = FMath::RandRange(PitchRange.X, PitchRange.Y);
            
            PlayCharacterSound(SelectedSound, RandomVolume, RandomPitch);
            StartVoiceLineCooldown();
        }
    }
}

void AGGPlayerCharacter::PlayAttackSound()
{
    PlayRandomVoiceSound(VoiceSounds.AttackSounds, VoiceSounds.VolumeRange, VoiceSounds.PitchRange);
}

void AGGPlayerCharacter::PlayBattleStartSound()
{
    PlayRandomVoiceSound(VoiceSounds.BattleStartSounds, VoiceSounds.VolumeRange, VoiceSounds.PitchRange);
}

void AGGPlayerCharacter::PlayCharacterSelectSound()
{
    PlayRandomVoiceSound(VoiceSounds.CharacterSelectSounds, VoiceSounds.VolumeRange, VoiceSounds.PitchRange);
}

void AGGPlayerCharacter::PlayDefeatSound()
{
    PlayRandomVoiceSound(VoiceSounds.DefeatSounds, VoiceSounds.VolumeRange, VoiceSounds.PitchRange);
}

void AGGPlayerCharacter::PlayMissSound()
{
    PlayRandomVoiceSound(VoiceSounds.MissSounds, VoiceSounds.VolumeRange, VoiceSounds.PitchRange);
}

void AGGPlayerCharacter::PlayPerfectStrikeSound()
{
    PlayRandomVoiceSound(VoiceSounds.PerfectStrikeSounds, VoiceSounds.VolumeRange, VoiceSounds.PitchRange);
}

void AGGPlayerCharacter::PlayVictorySound()
{
    PlayRandomVoiceSound(VoiceSounds.VictorySounds, VoiceSounds.VolumeRange, VoiceSounds.PitchRange);
}

void AGGPlayerCharacter::PlayCharacterSound(USoundBase* Sound, float VolumeMultiplier, float PitchMultiplier)
{
    if (Sound)
    {
        UGameplayStatics::PlaySoundAtLocation(
            this,
            Sound,
            GetActorLocation(),
            VolumeMultiplier,
            PitchMultiplier
        );
    }
}

void AGGPlayerCharacter::CheckAndPlayFootstep()
{
    // Check if character is moving on ground and fast enough
    if (GetCharacterMovement()->IsMovingOnGround() && 
        GetVelocity().Size() > MinFootstepSpeed &&
        bCanPlayFootstep)
    {
        PlayFootstepSound();
    }
}

void AGGPlayerCharacter::PlayFootstepSound()
{
    if (FootstepSounds.Num() > 0 && bCanPlayFootstep)
    {
        // Select random footstep sound from array
        if (USoundBase* FootstepSound = GetRandomSound(FootstepSounds))
        {
            PlayCharacterSound(FootstepSound, 0.7f, 1.0f);

            // Start cooldown timer
            bCanPlayFootstep = false;
            GetWorld()->GetTimerManager().SetTimer(
                FootstepTimerHandle,
                this,
                &AGGPlayerCharacter::EnableFootstep,
                FootstepInterval,
                false
            );
        }
    }
}

void AGGPlayerCharacter::PlayJumpSound()
{
    PlayCharacterSound(JumpSound, 1.0f, 1.0f);
}

void AGGPlayerCharacter::PlayLandingSound()
{
    PlayCharacterSound(LandingSound, 1.0f, 1.0f);
}

void AGGPlayerCharacter::Jump()
{
    Super::Jump();
    PlayJumpSound();
}

void AGGPlayerCharacter::Landed(const FHitResult& Hit)
{
    Super::Landed(Hit);
    PlayLandingSound();
}

// ... [Previous movement functions remain unchanged] ...