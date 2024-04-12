// Copyright Rohit 2023-2024


#include "UI/CharacterSelectionScreen.h"
#include "Components/ListView.h"


void UCharacterSelectionScreen::NativeConstruct()
{
	Super::NativeConstruct();

	CharacterSelectListWidget->SetListItems(CharacterList);
}
