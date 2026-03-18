// Copyright to Andres Echeverri 2023

#pragma once

#include "CoreMinimal.h"
#include "MVVMViewModelBase.h"
#include "SPlayerHUDVM.generated.h"

USTRUCT(BlueprintType)
struct FHUDValues
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite)
	int32 Health;

	UPROPERTY(BlueprintReadWrite)
	int32 MaxHealth;

	UPROPERTY(BlueprintReadWrite)
	int32 Mana;

	UPROPERTY(BlueprintReadWrite)
	int32 MaxMana;

	FHUDValues() :
		Health(0),
		MaxHealth(0),
		Mana(0),
		MaxMana(0)
	{
	};

	FHUDValues(int32 InHealth, int32 InMaxHealth, int32 InMana, int32 InMaxMana) :
		Health(InHealth),
		MaxHealth(InMaxHealth),
		Mana(InMana),
		MaxMana(InMaxMana)
	{
	};

};

/**
 * 
 */
UCLASS(BlueprintType)
class SHOWPROJECT_API USPlayerHUDVM : public UMVVMViewModelBase
{
	GENERATED_BODY()
	
public:

	int32 GetHealth() const;

	int32 GetMaxHealth() const;

	int32 GetMana() const;

	int32 GetMaxMana() const;

	int32 GetCredits() const;

	UFUNCTION(BlueprintCallable)
	void SetHealth(int32 InHealth);

	void SetMaxHealth(int32 InMaxHealth);

	void SetMana(int32 InMana);

	void SetMaxMana(int32 InMaxMana);

	void SetCredits(int32 InCredits);

	UFUNCTION(BlueprintCallable)
	void Initialize(FHUDValues InitValues);

	UFUNCTION(BlueprintPure, FieldNotify)
	float GetHealthPercent() const;

	UFUNCTION(BlueprintPure, FieldNotify)
	float GetManaPercent() const;


private:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, FieldNotify, Setter, Getter, meta = (AllowPrivateAccess = "true"));
	int32 Health;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, FieldNotify, Setter, Getter, meta = (AllowPrivateAccess = "true"));
	int32 MaxHealth;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, FieldNotify, Setter, Getter, meta = (AllowPrivateAccess = "true"));
	int32 Mana;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, FieldNotify, Setter, Getter, meta = (AllowPrivateAccess = "true"));
	int32 MaxMana;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, FieldNotify, Setter, Getter, meta = (AllowPrivateAccess = "true"));
	int32 Credits;
};
