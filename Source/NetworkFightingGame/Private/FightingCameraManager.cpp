// Copyright Rohit 2023-2024


#include "FightingCameraManager.h"
#include "GameFramework/GameState.h"
#include "GameFramework/PlayerState.h"
#include "GameFramework/Pawn.h"
#include "FightingGameLibraray.h"
#include "Kismet/GameplayStatics.h"


void AFightingCameraManager::UpdateViewTargetInternal(FTViewTarget& OutVT, float DeltaTime)
{
	
	FVector camLoc = GetCameraLocation();
	FRotator camRot = GetCameraRotation();

	if (!IsValid(CameraData))
	{
		return;
	}

	TArray<TObjectPtr<AActor>> pawns;

	FVector avgLoc = UFightingGameLibraray::GetCharactersAveragePosition(this);
	avgLoc += CameraData->CameraOffset;

	FVector lerpLocation = FMath::VInterpTo(GetCameraLocation(), avgLoc, DeltaTime, CameraData->CameraDelay);

	camRot = CameraData->CameraRotationOffset;

	OutVT.POV.Location = lerpLocation;
	OutVT.POV.Rotation = camRot;
	OutVT.POV.FOV = 90.0f;
}
