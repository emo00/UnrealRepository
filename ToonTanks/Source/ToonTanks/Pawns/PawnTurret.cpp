// Fill out your copyright notice in the Description page of Project Settings.


#include "PawnTurret.h"
#include "Kismet/GameplayStatics.h"
#include "PawnTank.h"

APawnTurret::APawnTurret()
{
	
}

void APawnTurret::BeginPlay()
{
	Super::BeginPlay();

	PlayerPawn = Cast<APawnTank>(UGameplayStatics::GetPlayerPawn(this, 0));
	GetWorld()->GetTimerManager().SetTimer(FireRateTimerHandle, this, &APawnTurret::CheckFireCondition, FireRate, true);
	
}

void APawnTurret::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (!PlayerPawn||ReturnDistanceToPlayer()>FireRange)
	{
		return;
	}
	RotateTurretFunction(PlayerPawn->GetActorLocation());
}

void APawnTurret::CheckFireCondition()
{
	//if player ==null||is dead then bail!
	if (!PlayerPawn)
	{
		return;
	}
	//if player in the range then fire!
	if (ReturnDistanceToPlayer() <= FireRange)
	{
		//fire
		UE_LOG(LogTemp, Warning, TEXT("Fire"));
	}
	
}

float APawnTurret::ReturnDistanceToPlayer()
{
	if (!PlayerPawn)
	{
		return 0.0f;
	}
	return FVector::Dist(PlayerPawn->GetActorLocation(),GetActorLocation());

}
