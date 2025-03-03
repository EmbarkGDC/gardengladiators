#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GGInteractableBase.generated.h"

UCLASS(Abstract)
class GARDENGLADIATORS_API AGGInteractableBase : public AActor
{
    GENERATED_BODY()

public:
    AGGInteractableBase();

    // Interface for interaction
    UFUNCTION(BlueprintCallable, Category = "Interaction")
    virtual void Interact(class AGGPlayerCharacter* InteractingPlayer);

    // Check if interaction is possible
    UFUNCTION(BlueprintNativeEvent, Category = "Interaction")
    bool CanInteract(const class AGGPlayerCharacter* InteractingPlayer) const;
    virtual bool CanInteract_Implementation(const class AGGPlayerCharacter* InteractingPlayer) const;

protected:
    virtual void BeginPlay() override;

    // Interaction trigger volume
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Interaction")
    class USphereComponent* InteractionTrigger;

    // Visual representation
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Visuals")
    class UStaticMeshComponent* VisualMesh;

    // Interaction range
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Interaction")
    float InteractionRange;

    UFUNCTION()
    virtual void OnInteractionTriggerOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, 
        UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
};