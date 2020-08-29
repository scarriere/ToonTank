// Copyright Samuel Carriere 2020


#include "PlayerStartBase.h"
#include "Components/CapsuleComponent.h"

APlayerStartBase::APlayerStartBase(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	GetCapsuleComponent()->InitCapsuleSize(CapsuleSize, CapsuleSize);
}
