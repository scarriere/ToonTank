// Copyright Samuel Carriere 2020

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerStart.h"
#include "PlayerStartBase.generated.h"

/**
 * 
 */
UCLASS()
class TOONTANKS_API APlayerStartBase : public APlayerStart
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere)
	float CapsuleSize = 66.f;
	
public:
	APlayerStartBase(const FObjectInitializer& ObjectInitializer);
};
