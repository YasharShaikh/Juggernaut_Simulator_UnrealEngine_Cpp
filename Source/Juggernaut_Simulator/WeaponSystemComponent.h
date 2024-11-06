// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "WeaponSystemComponent.generated.h"


UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class JUGGERNAUT_SIMULATOR_API UWeaponSystemComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UWeaponSystemComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	virtual void Fire();
	virtual void Reload();
	virtual void Aim();

protected:

	// Fire rate in rounds per minute
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Gun|Stats")
	float FireRate;
	// Ammo properties
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Gun|Ammo")
	int32 AmmoCapacity; // Maximum ammo capacity for the gun
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Gun|Ammo")
	int32 CurrentAmmo; // Current ammo in the magazine
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Gun|Ammo")
	int32 TotalAmmo; // Total ammo available for reloading
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Gun|Ammo")
	float ReloadTime; // Time required to reload the gun

	UPROPERTY(BlueprintReadOnly, Category = "Gun|Ammo")
	bool bIsReloading;

	UPROPERTY(BlueprintReadOnly, Category = "Gun|Ammo")
	bool bFired;

	// Projectile properties
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Gun|Projectile")
	float MuzzleVelocity; // Velocity of the projectile when it leaves the barrel
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Gun|Projectile")
	float ProjectileMass; // Mass of the projectile (used in physics calculations)

	/** Recoil and Kickback **/

	// Amount of kickback applied to the vehicle when fired
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Gun|Recoil")
	FVector RecoilForce;

	// Pitch and yaw kick values for visual and mechanical recoil
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Gun|Recoil")
	float RecoilPitch;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Gun|Recoil")
	float RecoilYaw;

	// Time required to settle after recoil (for a realistic "kick" effect)
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Gun|Recoil")
	float RecoilRecoveryTime;

	/** Heating and Overheating **/

	// Heat generated per shot
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Gun|Heat")
	float HeatPerShot;

	// Cooling rate per second
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Gun|Heat")
	float CoolingRate;

	// Maximum heat capacity before overheating
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Gun|Heat")
	float MaxHeatCapacity;

	// Whether the gun is overheated (disables firing until cooled)
	UPROPERTY(BlueprintReadOnly, Category = "Gun|Heat")
	bool bIsOverheated;

	/** Accuracy and Ballistics **/

	// Initial accuracy (spread) of the gun
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Gun|Accuracy")
	float BaseAccuracy;

	// Decrease in accuracy due to heat/recoil, making the gun less accurate as it fires continuously
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Gun|Accuracy")
	float AccuracyDropPerShot;

	// Minimum achievable accuracy (maximum inaccuracy)
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Gun|Accuracy")
	float MinAccuracy;

	/** Barrel and Projectile Mechanics **/

	// Barrel length (in meters), affects muzzle velocity and recoil
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Gun|Barrel")
	float BarrelLength;

	// Barrel twist rate (for rifled guns), affects projectile stability
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Gun|Barrel")
	float BarrelTwistRate;

	// Type of barrel (smoothbore or rifled)
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Gun|Barrel")
	FString BarrelType;

	/** Firing Modes and Burst Settings **/

	// Burst fire settings, if applicable
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Gun|Burst")
	int32 BurstCount;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Gun|Burst")
	float BurstDelay; // Delay between burst shots

	/** Additional Effects **/

	// Muzzle flash particle system
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Gun|Effects")
	UParticleSystem* MuzzleFlash;

	// Sound effect for firing
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Gun|Effects")
	USoundBase* FireSound;

	// Animation or camera shake for firing effect
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Gun|Effects")
	TSubclassOf<UCameraShakeBase> FireCameraShake;

	/** Aiming and Targeting **/

	// Maximum range of the gun
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Gun|Range")
	float MaxRange;

	// The arc or degree to which the gun can elevate/depress (for turret-mounted guns)
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Gun|Range")
	float ElevationAngle;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Gun|Range")
	float DepressionAngle;

	// Rate at which the gun can aim (degrees per second)
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Gun|Aiming")
	float AimSpeed;

	// Target acquisition assistance (e.g., laser rangefinder)
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Gun|Aiming")
	bool bHasTargetingAssistance;

	/** Firing State **/

	// Internal timer to manage firing rate
	UPROPERTY(BlueprintReadOnly, Category = "Gun|State")
	float LastFireTime;

	// Check if the gun is ready to fire based on fire rate and cooldowns
	bool CanFire() const;

	// Internal function to handle heat buildup and cooldown
	void UpdateHeat(float DeltaTime);

	// Internal function to manage recoil and accuracy changes
	void ApplyRecoil();


private:
	FTimerHandle ReloadTimeHandler;
	void CompleteReload();
};
