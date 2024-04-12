// Copyright Rohit 2023-2024

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Engine/DataAsset.h"
#include "CharacterSelectionScreen.generated.h"

/**
 * 
 */

class AFightingCharacterBase;
class UTexture2D;

UCLASS(Blueprintable, BlueprintType)
class NETWORKFIGHTINGGAME_API UCharacterData : public UDataAsset
{
	GENERATED_BODY()
public:

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TSoftClassPtr<AFightingCharacterBase> CharacterToSpawn;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TObjectPtr<UTexture2D> CharacterImage;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FText CharacterName;
};

class UListView;

UCLASS()
class NETWORKFIGHTINGGAME_API UCharacterSelectionScreen : public UUserWidget
{
	GENERATED_BODY()

public:

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	TObjectPtr<UListView> CharacterSelectListWidget;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TArray<TObjectPtr<UCharacterData>> CharacterList;


	void NativeConstruct() override;
	
};
