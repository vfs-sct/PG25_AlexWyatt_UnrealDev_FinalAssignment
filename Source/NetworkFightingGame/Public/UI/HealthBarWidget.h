// Copyright Rohit 2023-2024

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Blueprint/IUserObjectListEntry.h"
#include "HealthBarWidget.generated.h"

/**
 * 
 */

class UHealthComponent;
class UProgressBar;

UCLASS()
class NETWORKFIGHTINGGAME_API UHealthBarWidget : public UUserWidget, public IUserObjectListEntry
{
	GENERATED_BODY()

public:

	UPROPERTY(BlueprintReadOnly, Transient)
	TObjectPtr<UHealthComponent> HealthComponent;


	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	TObjectPtr<UProgressBar> HealthBar;

	void NativeOnListItemObjectSet(UObject* ListItemObject);
	
};
