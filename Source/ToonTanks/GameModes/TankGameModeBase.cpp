// Copyright Samuel Carriere 2020


#include "TankGameModeBase.h"
#include "ToonTanks/Pawns/PawnTank.h"
#include "ToonTanks/Pawns/PawnTurret.h"
#include "ToonTanks/PlayerControllers/PlayerControllerBase.h"
#include "Kismet/GameplayStatics.h"

void ATankGameModeBase::BeginPlay()
{
	Super::BeginPlay();
	UGameplayStatics::CreatePlayer(GetWorld());
	HandleGameStart();
}

void ATankGameModeBase::ActorDied(AActor * DeadActor)
{
	if (APawnTank* DestroyPlayer = Cast<APawnTank>(DeadActor))
	{
		DestroyPlayer->HandleDestruction();
		if (APlayerControllerBase* PlayerController = Cast<APlayerControllerBase>(DestroyPlayer->GetController()))
		{
			PlayerController->SetPlayerEnabledState(false);
		}

		if (--PlayerCounts == 0)
		{
			HandleGameOver(false);
		}
	}
	else if (APawnTurret* DestroyTurret = Cast<APawnTurret>(DeadActor))
	{
		DestroyTurret->HandleDestruction();
		if (--TargetTurrets == 0)
		{
			HandleGameOver(true);
		}
	}
}

int32 ATankGameModeBase::GetTargetTurretsCount()
{
	TArray<AActor*> TurretActors;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), APawnTurret::StaticClass(), TurretActors);
	return TurretActors.Num();
}

void ATankGameModeBase::HandleGameStart()
{
	TargetTurrets = GetTargetTurretsCount();

	TArray<AActor*> PlayerActors;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), APawnTank::StaticClass(), PlayerActors);

	PlayerCounts = PlayerActors.Num();

	for (AActor* Actor : PlayerActors)
	{
		UE_LOG(LogTemp, Warning, TEXT("disabling actor"))
		if (APawnTank* PlayerPawn = Cast<APawnTank>(Actor))
		{
			UE_LOG(LogTemp, Warning, TEXT("disabling pawn"))
			if (APlayerControllerBase* PlayerController = Cast<APlayerControllerBase>(PlayerPawn->GetController()))
			{
				UE_LOG(LogTemp, Warning, TEXT("disabling controller"))
				PlayerController->SetPlayerEnabledState(false);

				FTimerHandle PlayerEnableHandle;
				FTimerDelegate PlayerEnableDelegate = FTimerDelegate::CreateUObject(PlayerController,
					&APlayerControllerBase::SetPlayerEnabledState, true);
				GetWorld()->GetTimerManager().SetTimer(PlayerEnableHandle, PlayerEnableDelegate, StartDelay, false);
			}
		}

	}

	GameStart();
}

void ATankGameModeBase::HandleGameOver(bool PlayerWon)
{
	GameOver(PlayerWon);
}
