#include "PlayerCharacter.h"
#include "HAL/Platform.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
APlayerCharacter::APlayerCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void APlayerCharacter::BeginPlay()
{
	Super::BeginPlay();

	APlayerController* PlayerController = Cast<APlayerController>(GetController());
}

// Called every frame
void APlayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void APlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("MoveForwards", this, &APlayerCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &APlayerCharacter::MoveRight);
	PlayerInputComponent->BindAxis("Turn", this, &APlayerCharacter::Turn);
	PlayerInputComponent->BindAxis("LookUp", this, &APlayerCharacter::LookUp);
	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &ACharacter::StopJumping);
}

void APlayerCharacter::MoveForward(float value)
{
	FRotator Rotation = Controller->GetControlRotation();
	FRotator YawRotation(0, Rotation.Yaw, 0);
	
    FVector direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
	UE_LOG(LogTemp, Warning, TEXT("MoveForward: %f"), value);
    AddMovementInput(direction, value);
}

void APlayerCharacter::MoveRight(float value)
{
    FVector direction = FRotationMatrix(Controller->GetControlRotation()).GetScaledAxis(EAxis::Y);
    AddMovementInput(direction, value);
}

void APlayerCharacter::Turn(float value)
{
    AddControllerYawInput(value);
}

void APlayerCharacter::LookUp(float value)
{
	AddControllerPitchInput(value);
}

void APlayerCharacter::SpawnActor()
{
	AActor* spawnedActor = GetWorld()->SpawnActor<AActor>(actorToSpawn, spawnLocation);
	if (actorToSpawn)
	{
		SpawnedActors.Add(spawnedActor);
		UE_LOG(LogTemp, Warning, TEXT("Spawned and added: %s"), *spawnedActor->GetName());
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("No actor to spawn"));
	}
}

void APlayerCharacter::DestroyActor()
{
	//FlushPersistentDebugLines(GetWorld());  // Ensure world updates before destruction

	if (actorToSpawn && SpawnedActors.Num() > 0)
	{
		for (AActor* actor : SpawnedActors)
		{
			if (actor)
			{
				actor->Destroy();
			}
		}
		SpawnedActors.Empty();
	}
}


