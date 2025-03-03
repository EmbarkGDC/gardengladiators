#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "GGPlayerCharacter.generated.h"

/** Struct containing all voice/personality sounds for a character */
USTRUCT(BlueprintType)
struct FGGVoiceSoundSet
{
    GENERATED_BODY()

    /** Sounds played when attacking */
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Voice|Combat")
    TArray<USoundBase*> AttackSounds;

    /** Sounds played at the start of battle */
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Voice|Combat")
    TArray<USoundBase*> BattleStartSounds;

    /** Sounds played when character is selected */
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Voice|UI")
    TArray<USoundBase*> CharacterSelectSounds;

    /** Sounds played when defeated */
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Voice|Combat")
    TArray<USoundBase*> DefeatSounds;

    /** Sounds played when attack misses */
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Voice|Combat")
    TArray<USoundBase*> MissSounds;

    /** Sounds played for perfect hits */
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Voice|Combat")
    TArray<USoundBase*> PerfectStrikeSounds;

    /** Sounds played when victorious */
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Voice|Combat")
    TArray<USoundBase*> VictorySounds;

    /** Volume range for voice sounds */
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Voice|Settings")
    FVector2D VolumeRange = FVector2D(0.8f, 1.0f);

    /** Pitch range for voice sounds */
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Voice|Settings")
    FVector2D PitchRange = FVector2D(0.95f, 1.05f);
};

UCLASS()
class GARDENGLADIATORS_API AGGPlayerCharacter : public ACharacter
{
    GENERATED_BODY()

public:
    AGGPlayerCharacter();

    // Previous sound properties remain unchanged
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Audio|Movement")
    TArray<USoundBase*> FootstepSounds;

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Audio|Movement")
    USoundBase* JumpSound;

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Audio|Movement")
    USoundBase* LandingSound;

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Audio|Abilities")
    TMap<int32, USoundBase*> AbilitySounds;

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Audio|Character")
    USoundBase* DamageSound;

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Audio|Movement")
    float FootstepInterval = 0.3f;

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Audio|Movement")
    float MinFootstepSpeed = 10.0f;

    /** Character voice sound set */
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Audio|Voice")
    FGGVoiceSoundSet VoiceSounds;

    /** Cooldown between voice lines to prevent overlap */
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Audio|Voice")
    float VoiceLineCooldown = 0.5f;

    // Voice Sound Functions
    /** Plays a random attack voice line */
    UFUNCTION(BlueprintCallable, Category = "Audio|Voice", meta = (ToolTip = "Plays a random attack voice line"))
    void PlayAttackSound();

    /** Plays a random battle start voice line */
    UFUNCTION(BlueprintCallable, Category = "Audio|Voice", meta = (ToolTip = "Plays a random battle start voice line"))
    void PlayBattleStartSound();

    /** Plays a random character select voice line */
    UFUNCTION(BlueprintCallable, Category = "Audio|Voice", meta = (ToolTip = "Plays a random character select voice line"))
    void PlayCharacterSelectSound();

    /** Plays a random defeat voice line */
    UFUNCTION(BlueprintCallable, Category = "Audio|Voice", meta = (ToolTip = "Plays a random defeat voice line"))
    void PlayDefeatSound();

    /** Plays a random miss voice line */
    UFUNCTION(BlueprintCallable, Category = "Audio|Voice", meta = (ToolTip = "Plays a random miss voice line"))
    void PlayMissSound();

    /** Plays a random perfect strike voice line */
    UFUNCTION(BlueprintCallable, Category = "Audio|Voice", meta = (ToolTip = "Plays a random perfect strike voice line"))
    void PlayPerfectStrikeSound();

    /** Plays a random victory voice line */
    UFUNCTION(BlueprintCallable, Category = "Audio|Voice", meta = (ToolTip = "Plays a random victory voice line"))
    void PlayVictorySound();

    /** Plays a random sound from the provided array with volume and pitch variation */
    UFUNCTION(BlueprintCallable, Category = "Audio|Voice", meta = (ToolTip = "Plays a random sound from the provided array"))
    void PlayRandomVoiceSound(const TArray<USoundBase*>& SoundArray, const FVector2D& VolumeRange, const FVector2D& PitchRange);

protected:
    virtual void BeginPlay() override;
    virtual void Tick(float DeltaTime) override;
    virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
    virtual void Landed(const FHitResult& Hit) override;
    virtual void Jump() override;

    // Movement functions
    void MoveForward(float Value);
    void MoveRight(float Value);

    // Camera component
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera")
    class UCameraComponent* CameraComponent;

    // Spring arm for camera
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera")
    class USpringArmComponent* CameraBoom;

private:
    FTimerHandle FootstepTimerHandle;
    FTimerHandle VoiceLineCooldownTimer;
    bool bCanPlayFootstep;
    bool bCanPlayVoiceLine;
    
    void EnableFootstep() { bCanPlayFootstep = true; }
    void EnableVoiceLine() { bCanPlayVoiceLine = true; }
    void CheckAndPlayFootstep();
    
    /** Helper function to play sound with random variation */
    void PlayCharacterSound(USoundBase* Sound, float VolumeMultiplier = 1.0f, float PitchMultiplier = 1.0f);

    /** Helper function to validate and get a random sound from an array */
    USoundBase* GetRandomSound(const TArray<USoundBase*>& SoundArray);

    /** Helper function to check if voice line can be played */
    bool CanPlayVoiceLine() const;

    /** Helper function to start voice line cooldown */
    void StartVoiceLineCooldown();

    // Previous character properties remain unchanged
    float BaseMovementSpeed;
    float SprintSpeedMultiplier;
    bool bIsSprinting;
    float CurrentStamina;
};