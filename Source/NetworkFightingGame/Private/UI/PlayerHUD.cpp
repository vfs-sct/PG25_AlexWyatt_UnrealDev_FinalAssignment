// Copyright Rohit 2023-2024


#include "UI/PlayerHUD.h"
#include "Components/ListView.h"
#include "GameFramework/GameStateBase.h"
#include "GameFramework/PlayerState.h"

void UPlayerHUD::OnPawnChanged(APlayerState* Player, APawn* NewPawn, APawn* OldPawn)
{
	TObjectPtr<AGameStateBase> GameState = GetWorld()->GetGameState();
	CharacterHealthBars->ClearListItems();
	CharacterHealthBars->SetListItems(GameState->PlayerArray);
	CharacterHealthBars->RegenerateAllEntries();
}

void UPlayerHUD::NativeConstruct()
{
	Super::NativeConstruct();
	TObjectPtr<AGameStateBase> GameState = GetWorld()->GetGameState();
  
	for (TObjectPtr<APlayerState> PlayerState : GameState->PlayerArray)
	{
		PlayerState->OnPawnSet.AddUniqueDynamic(this,&UPlayerHUD::OnPawnChanged);
	}
}
