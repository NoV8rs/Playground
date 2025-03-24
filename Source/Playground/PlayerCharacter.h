// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "PlayerCharacter.generated.h"

UCLASS()
class PLAYGROUND_API APlayerCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	APlayerCharacter();

	UFUNCTION(BlueprintCallable, Category = "PlayerCharacter")
	void SpawnActor();

	UFUNCTION(BlueprintCallable, Category = "PlayerCharacter")
	void DestroyActor();
	
	UPROPERTY(EditAnywhere, Category = "PlayerCharacter")
	float MaxHealth = 100.0f;

	UPROPERTY(EditAnywhere, Category = "PlayerCharacter")
	float CurrentHealth = 100.0f;

	UPROPERTY(EditAnywhere)
	TSubclassOf<AActor> actorToSpawn;

	UPROPERTY(EditAnywhere)
	FTransform spawnLocation;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	void MoveForward(float value);
	void MoveRight(float value);
	void Turn(float value);
	void LookUp(float value);

private:
	TArray<AActor*> SpawnedActors;

};
