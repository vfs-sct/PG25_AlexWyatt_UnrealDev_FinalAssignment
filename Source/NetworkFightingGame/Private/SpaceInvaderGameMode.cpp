// Copyright Alex Buzmion 2023-2024


#include "SpaceInvaderGameMode.h"
#include "FightingGameStateBase.h"
#include "FightingPlayerState.h"
#include "FightingControllerBase.h"
#include "FightingCharacterBase.h"
#include "FightingGameHUDBase.h"

ASpaceInvaderGameMode::ASpaceInvaderGameMode(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
    GameStateClass = AFightingGameStateBase::StaticClass();
    PlayerStateClass = AFightingPlayerState::StaticClass();
    PlayerControllerClass = AFightingControllerBase::StaticClass();
    DefaultPawnClass = AFightingCharacterBase::StaticClass();
    HUDClass = AFightingGameHUDBase::StaticClass();
}

