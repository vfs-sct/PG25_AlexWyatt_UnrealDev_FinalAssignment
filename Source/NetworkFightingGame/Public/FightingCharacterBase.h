// Copyright Rohit 2023-2024

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "FightingCharacterBase.generated.h"

class UHealthComponent;
class UInputAction;
class UAnimMontage;

UCLASS()
class NETWORKFIGHTINGGAME_API AFightingCharacterBase : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AFightingCharacterBase();

	UPROPERTY(BlueprintReadOnly)
	TObjectPtr<UHealthComponent> HealthComponent;

	UPROPERTY(EditAnywhere, Category = "Animations")
	TObjectPtr<UAnimMontage> LightAttackMontage;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TObjectPtr<UInputAction> LightAttackAction;

	UFUNCTION(Server, Reliable, BlueprintCallable)
	void SER_LightAttack(const FInputActionValue& value);

	UFUNCTION(NetMulticast, Reliable)
	void MULTI_LightAttack();



public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
