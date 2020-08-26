// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "BasePawn.generated.h"

class UCapsuleComponent;

UCLASS()
class TOONTANKS_API ABasePawn : public APawn
{
	GENERATED_BODY()

private:
	UPROPERTY()
	UCapsuleComponent* CapsuleComponent;
	UPROPERTY()
	UStaticMeshComponent* BaseMesh;
	UPROPERTY()
	UStaticMeshComponent* TurretMesh;
	UPROPERTY()
	USceneComponent* ProjectileSpawnPoint;

public:
	// Sets default values for this pawn's properties
	ABasePawn();
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
};
