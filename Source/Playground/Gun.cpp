#include "Gun.h"
#include "Components/SkeletalMeshComponent.h"

AGun::AGun()
{
	PrimaryActorTick.bCanEverTick = true;

	GunMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("GunMesh"));
	RootComponent = GunMesh;
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
