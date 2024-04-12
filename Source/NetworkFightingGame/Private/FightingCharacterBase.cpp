// Copyright Rohit 2023-2024


#include "FightingCharacterBase.h"
#include "Net/UnrealNetwork.h"
#include "HealthComponent.h"
#include "EnhancedInputComponent.h"
#include "InputAction.h"
#include "EnhancedInputSubsystems.h"
#include "Animation/AnimMontage.h"

// Sets default values
AFightingCharacterBase::AFightingCharacterBase()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	HealthComponent = CreateDefaultSubobject<UHealthComponent>(TEXT("Health Component"));
}

// Called when the game starts or when spawned
void AFightingCharacterBase::BeginPlay()
{
	Super::BeginPlay();
	if (IsValid(HealthComponent))
	{
		OnTakeAnyDamage.AddUniqueDynamic(HealthComponent.Get(), &UHealthComponent::TakeDamage);
	}
	
}

void AFightingCharacterBase::SER_LightAttack_Implementation(const FInputActionValue& value)
{
	MULTI_LightAttack();
}

void AFightingCharacterBase::MULTI_LightAttack_Implementation()
{
	if (!IsValid(LightAttackMontage))
	{
		return;
	}

	PlayAnimMontage(LightAttackMontage);
}

// Called every frame
void AFightingCharacterBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AFightingCharacterBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	
	const TObjectPtr<AController> controller =  GetController();
	if (TObjectPtr<APlayerController> playerCon = Cast<APlayerController>(controller))
	{	
		UEnhancedInputLocalPlayerSubsystem* enhancedInputSubsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(playerCon->GetLocalPlayer());

		UEnhancedInputComponent* InputComp = Cast<UEnhancedInputComponent>(PlayerInputComponent);
		if (IsValid(InputComp))
		{
			if (IsValid(LightAttackAction))
			{
				InputComp->BindAction(LightAttackAction, ETriggerEvent::Triggered, this, &AFightingCharacterBase::SER_LightAttack);
			}
		}

	}

}

