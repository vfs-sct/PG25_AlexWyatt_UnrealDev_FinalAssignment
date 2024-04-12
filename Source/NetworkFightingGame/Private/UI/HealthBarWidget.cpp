// Copyright Rohit 2023-2024


#include "UI/HealthBarWidget.h"
#include "GameFramework/PlayerState.h"
#include "HealthComponent.h"
#include "GameFramework/Pawn.h"

void UHealthBarWidget::NativeOnListItemObjectSet(UObject* ListItemObject)
{
	if (TObjectPtr<APlayerState> PlayerState = Cast<APlayerState>(ListItemObject))
	{
		if (TObjectPtr<APawn> Pawn = PlayerState->GetPawn())
		{
			HealthComponent =  Pawn->FindComponentByClass<UHealthComponent>();
		}
	}
}
