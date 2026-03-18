// Copyright to Andres Echeverri 2023

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "AbilitySystemInterface.h"
#include "SPlayerState.generated.h"

class UAbilitySystemComponent;
class USAttributeSet;
struct FOnAttributeChangeData;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnCreditsChangedSignature, ASPlayerState*, PlayerState, int32, NewCredits, int32, Delta);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnXPChangedSignature, ASPlayerState*, PlayerState, int32, NewXP, int32, Delta);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnLevelChangedSignature, ASPlayerState*, PlayerState, int32, NewLevel);
/**
 * 
 */
UCLASS()
class SHOWPROJECT_API ASPlayerState : public APlayerState, public IAbilitySystemInterface
{
	GENERATED_BODY()

protected:

	UPROPERTY()
	TObjectPtr<UAbilitySystemComponent> AbilitySystemComponent;

	UPROPERTY()
	TObjectPtr<USAttributeSet> AttributeSet;

	UPROPERTY(EditDefaultsOnly, Category = "Credits", ReplicatedUsing="OnRep_Credits")
	int32 Credits;

	UPROPERTY(BlueprintReadWrite, Category = "XP", ReplicatedUsing="OnRep_XP")
	int32 XPPoints;

	UPROPERTY(BlueprintReadWrite, Category = "XP", ReplicatedUsing = "OnRep_Level")
	int32 Level;

	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

	virtual void PostInitializeComponents() override;

	void OnHealthChanged(const FOnAttributeChangeData& Data);
	void OnManaChanged(const FOnAttributeChangeData& Data);

public:
	ASPlayerState();
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;

	USAttributeSet* GetAttributeSet() const { return AttributeSet; }

	UFUNCTION(BlueprintCallable, Category = "Credits")
	int32 GetCredits() const;

	void TrySetCredits(int32 NewCredits);

	UFUNCTION(Server, Reliable, WithValidation)
	void Server_SetCredits(int32 NewCredits);

	UFUNCTION(BlueprintCallable, Category = "Credits")
	void ChangeCredits(int32 Delta);

	void TryChangeCredits(int32 Delta);

	UFUNCTION(Server, Reliable, WithValidation)
	void Server_ChangeCredits(int32 Delta);

	UFUNCTION()
	void SetCredits(int32 NewCredits);

	UPROPERTY(BlueprintAssignable, Category = "Events")
	FOnCreditsChangedSignature OnCreditsChanged;

	UFUNCTION()
	void OnRep_Credits(int32 OldCredits);

	UPROPERTY(BlueprintAssignable, Category = "Events")
	FOnXPChangedSignature OnXPChanged;

	UPROPERTY(BlueprintAssignable, Category = "Events")
	FOnLevelChangedSignature OnLevelChanged;

	UFUNCTION()
	void OnRep_XP();

	UFUNCTION()
	void OnRep_Level(int32 OldLevel);
};
