// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AJuggernautCharacter.generated.h"

class UCameraComponent;
class UStaticMeshComponent;




UCLASS()
class JUGGERNAUT_SIMULATOR_API AAJuggernautCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AAJuggernautCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(VisibleAnywhere)		UCameraComponent* PlayerViewCamera;
	UPROPERTY(VisibleAnywhere)		UStaticMeshComponent* PlayerStaticMesh;

private:

	void FirePrimaryGun();
	void FireSecondaryGun();
	void ReloadPrimaryGun();
	void SetRangeFinder();
};
