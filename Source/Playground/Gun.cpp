#include "Gun.h"
#include "Components/SkeletalMeshComponent.h"
#include "Components/SphereComponent.h"
#include "PlayerCharacter.h"

AGun::AGun()
{
	PrimaryActorTick.bCanEverTick = true;

	GunMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("GunMesh"));
	RootComponent = GunMesh;

	SphereCollision = CreateDefaultSubobject<USphereComponent>(TEXT("CollisionComponent"));
	SphereCollision->SetupAttachment(RootComponent);
	SphereCollision->SetSphereRadius(50.0f);
	SphereCollision->OnComponentBeginOverlap.AddDynamic(this, &AGun::OnSphereBeginOverlap);
}

void AGun::BeginPlay()
{
	Super::BeginPlay();
}

void AGun::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AGun::Fire()
{
	// Implement the firing logic here
	UE_LOG(LogTemp, Warning, TEXT("Gun Fired!"));
}

void AGun::OnSphereBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	APlayerCharacter* Character = Cast<APlayerCharacter>(OtherActor);
	if (Character)
	{
		AttachToComponent(Character->GetMesh(), FAttachmentTransformRules::SnapToTargetNotIncludingScale, TEXT("GripPoint"));
		SetOwner(Character);
		Character->Fire();
		UE_LOG(LogTemp, Warning, TEXT("Gun attached to: %s"), *Character->GetName());
	}
}

