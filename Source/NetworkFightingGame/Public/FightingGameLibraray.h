// Copyright Rohit 2023-2024

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "FightingGameLibraray.generated.h"

/**
 * 
 */
UCLASS()
class NETWORKFIGHTINGGAME_API UFightingGameLibraray : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable, BlueprintPure)
	static FVector GetCharactersAveragePosition(const UObject* worldContext);
	
};
