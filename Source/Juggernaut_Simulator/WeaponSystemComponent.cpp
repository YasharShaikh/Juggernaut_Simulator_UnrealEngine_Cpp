// Fill out your copyright notice in the Description page of Project Settings.


#include "WeaponSystemComponent.h"

// Sets default values for this component's properties
UWeaponSystemComponent::UWeaponSystemComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UWeaponSystemComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...

	AmmoCapacity = 30;
	CurrentAmmo = AmmoCapacity;
	ReloadTime = 2.0f;
	MuzzleVelocity = 900.0f;
	RecoilForce = FVector(500.0f, 0.0f, 0.0f); ;
	HeatPerShot = 5.0f;
	CoolingRate = 2.0f;

	bIsOverheated = false;
	bIsReloading = false;
	bFired = false;
}


// Called every frame
void UWeaponSystemComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...


}

void UWeaponSystemComponent::Fire()
{
	if (!CanFire())
		return;


	bFired = true;
}

void UWeaponSystemComponent::Reload()
{
	if (bFired && !bIsReloading)
	{
		bIsReloading = true;
		GetWorld()->GetTimerManager().SetTimer(ReloadTimeHandler, this, &UWeaponSystemComponent::CompleteReload, ReloadTime, false);
	}
}
void UWeaponSystemComponent::CompleteReload()
{
	bFired = false;       // Set bFired to false
	bIsReloading = false; // Set bIsReloading to false

	// Optionally, print a message or trigger any other effects when reload is complete
	GEngine->AddOnScreenDebugMessage(-1, 3.0f, FColor::Green, "Reload Complete");
}
void UWeaponSystemComponent::Aim()
{
}

bool UWeaponSystemComponent::CanFire() const
{
	if (bIsOverheated)
	{
		GEngine->AddOnScreenDebugMessage(-1, 0.0f, FColor::Red, "Gun Overheated, Cannot Fire");
		return false;
	}

	if (bIsReloading)
	{
		GEngine->AddOnScreenDebugMessage(-1, 0.0f, FColor::Yellow, "Wait until reload is complete");
		return false;
	}

	if (bFired)
	{
		GEngine->AddOnScreenDebugMessage(-1, 0.0f, FColor::Red, "No Ammo to Fire");
		return false;
	}

	return true;
}


void UWeaponSystemComponent::UpdateHeat(float DeltaTime)
{
}

void UWeaponSystemComponent::ApplyRecoil()
{
}

