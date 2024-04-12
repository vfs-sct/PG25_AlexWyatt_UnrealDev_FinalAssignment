// Copyright Rohit 2023-2024

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "PlayerHUD.generated.h"

/**
 * 
 */
class UListView;

UCLASS()
class NETWORKFIGHTINGGAME_API UPlayerHUD : public UUserWidget
{
	GENERATED_BODY()

public:

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	TObjectPtr<UListView> CharacterHealthBars;

	UFUNCTION(BlueprintCallable)
	void OnPawnChanged(APlayerState* Player, APawn* NewPawn, APawn* OldPawn);


	void NativeConstruct() override;
	
};
