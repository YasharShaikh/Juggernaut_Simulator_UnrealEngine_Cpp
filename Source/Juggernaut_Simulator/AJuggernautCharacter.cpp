// Fill out your copyright notice in the Description page of Project Settings.


#include "AJuggernautCharacter.h"
#include "Camera/CameraComponent.h"
#include "Components/StaticMeshComponent.h"


// Sets default values
AAJuggernautCharacter::AAJuggernautCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	PlayerStaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Static Mesh Component"));
	PlayerStaticMesh->SetupAttachment(RootComponent);

	PlayerViewCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera Component"));
	PlayerViewCamera->SetupAttachment(RootComponent);
	PlayerViewCamera->bUsePawnControlRotation = true;


}

// Called when the game starts or when spawned
void AAJuggernautCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AAJuggernautCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AAJuggernautCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);



	//Action Mappings

#pragma region Weapon System
	PlayerInputComponent->BindAction(FName("PrimaryFire"), IE_Pressed, this, &AAJuggernautCharacter::FirePrimaryGun);
	PlayerInputComponent->BindAction(FName("SecondaryFire"), IE_Pressed, this, &AAJuggernautCharacter::FireSecondaryGun);
	PlayerInputComponent->BindAction(FName("ReloadPrimaryGun"), IE_Pressed, this, &AAJuggernautCharacter::ReloadPrimaryGun);
	PlayerInputComponent->BindAction(FName("RangeFinder"), IE_Pressed, this, &AAJuggernautCharacter::SetRangeFinder);
#pragma endregion

	
}


#pragma region Weapon System
void AAJuggernautCharacter::FirePrimaryGun()
{
}

void AAJuggernautCharacter::FireSecondaryGun()
{
}

void AAJuggernautCharacter::ReloadPrimaryGun()
{
}

void AAJuggernautCharacter::SetRangeFinder()
{
}
#pragma endregion




