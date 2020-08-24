// Fill out your copyright notice in the Description page of Project Settings.


#include "PawnBase.h"
#include "Components/CapsuleComponent.h"

// Sets default values
APawnBase::APawnBase()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CapsuleComp = CreateDefaultSubobject<UCapsuleComponent>(TEXT("CapsuleCollider"));
	RootComponent = CapsuleComp;

	BaseMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BaseMesh"));
	BaseMesh->SetupAttachment(RootComponent);

	TurretMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Turret"));
	TurretMesh->SetupAttachment(BaseMesh);

	ProjectileSpawnPoint = CreateDefaultSubobject<USceneComponent>(TEXT("ProjectileSpawnPoint"));
	ProjectileSpawnPoint->SetupAttachment(TurretMesh);

}

void APawnBase::RotateTurretFunction(FVector LookAtTarget)
{
	//Update TurretMesh rotation to face towards the LookAtTarget passed in Ch=ildClasss
	FVector LookAtTargetCleaned = FVector(LookAtTarget.X, LookAtTarget.Y, TurretMesh->GetComponentLocation().Z);
	FVector StartLocation = FVector(TurretMesh->GetComponentLocation());

	FRotator TurretRotation = FVector(LookAtTargetCleaned - StartLocation).Rotation();
	//TurretMesh->SetWorldRotation()...
	TurretMesh->SetWorldRotation(TurretRotation);
}

void APawnBase::Fire()
{
	//Get ProjectileSpawnPoint Location && Rotation->Spawn projectile at location firing torwards rotation
}

void APawnBase::HandleDestruction()
{
	//--Universal functionality
	//play death effect particle ,sound and camera shake

	//then do child override
	//--PawnTurret inform GameMode turret died->then destory() self
	//--PawnTank inform GameMode Turret died->then hide all component and stop movement input
}

