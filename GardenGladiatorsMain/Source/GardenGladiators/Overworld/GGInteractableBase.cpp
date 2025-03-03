#include "GGInteractableBase.h"
#include "Components/SphereComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Player/GGPlayerCharacter.h"

AGGInteractableBase::AGGInteractableBase()
{
    PrimaryActorTick.bCanEverTick = false;

    // Create and setup root component
    InteractionTrigger = CreateDefaultSubobject<USphereComponent>(TEXT("InteractionTrigger"));
    RootComponent = InteractionTrigger;
    InteractionTrigger->SetCollisionProfileName(TEXT("Trigger"));
    InteractionTrigger->OnComponentBeginOverlap.AddDynamic(this, &AGGInteractableBase::OnInteractionTriggerOverlap);

    // Create visual component
    VisualMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("VisualMesh"));
    VisualMesh->SetupAttachment(RootComponent);
    VisualMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);

    // Set default values
    InteractionRange = 200.0f;
    InteractionTrigger->SetSphereRadius(InteractionRange);
}

void AGGInteractableBase::BeginPlay()
{
    Super::BeginPlay();
}

void AGGInteractableBase::Interact(AGGPlayerCharacter* InteractingPlayer)
{
    // Base implementation - override in child classes
    if (InteractingPlayer && CanInteract(InteractingPlayer))
    {
        // Handle interaction
    }
}

bool AGGInteractableBase::CanInteract_Implementation(const AGGPlayerCharacter* InteractingPlayer) const
{
    return InteractingPlayer != nullptr;
}

void AGGInteractableBase::OnInteractionTriggerOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, 
    UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
    if (AGGPlayerCharacter* PlayerCharacter = Cast<AGGPlayerCharacter>(OtherActor))
    {
        // Handle player entering interaction range
    }
}