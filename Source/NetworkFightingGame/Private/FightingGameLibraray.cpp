// Copyright Rohit 2023-2024


#include "FightingGameLibraray.h"
#include "GameFramework/GameState.h"
#include "GameFramework/PlayerState.h"
#include "Kismet/GameplayStatics.h"


FVector UFightingGameLibraray::GetCharactersAveragePosition(const UObject* worldContext)
{
	if (!IsValid(worldContext))
	{
		return FVector::ZeroVector;
	}

	const TObjectPtr<UWorld> world = worldContext->GetWorld();

	if (!IsValid(world))
	{
		return FVector::ZeroVector;
	}

	const TObjectPtr<AGameStateBase> gameState = world->GetGameState();
	if (!IsValid(gameState))
	{
		return FVector::ZeroVector;
	}

	TArray<TObjectPtr<AActor>> pawns;

	// geting all the characters and adding the positions to the list
	for (const TObjectPtr<APlayerState> playerStateIter : gameState->PlayerArray)
	{
		TObjectPtr<APawn> pawnIter = playerStateIter->GetPawn();
		if (!IsValid(pawnIter))
		{
			continue;
		}
		pawns.AddUnique(pawnIter);
	}

	return UGameplayStatics::GetActorArrayAverageLocation(pawns);
}
