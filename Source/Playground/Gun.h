#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Gun.generated.h"

UCLASS()
class PLAYGROUND_API AGun : public AActor
{
	GENERATED_BODY()

public:
	AGun();

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;
	void Fire();

	private:
	UPROPERTY(VisibleAnywhere)
	USkeletalMeshComponent* GunMesh;
};
