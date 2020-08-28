// Copyright Samuel Carriere 2020


#include "TankGameModeBase.h"

void ATankGameModeBase::BeginPlay()
{
}

void ATankGameModeBase::HandleGameStart()
{

}

void ATankGameModeBase::ActorDied(AActor * DeadActor)
{
	UE_LOG(LogTemp, Warning, TEXT("A Pawn Died"))
}

void ATankGameModeBase::HandleGameOver(bool PlayerWon)
{
}
