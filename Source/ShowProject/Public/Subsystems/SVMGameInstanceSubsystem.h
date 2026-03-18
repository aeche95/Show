// Copyright to Andres Echeverri 2023

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "SVMGameInstanceSubsystem.generated.h"

/**
 * 
 */
UCLASS()
class SHOWPROJECT_API USVMGameInstanceSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

private:
	void RegisterViewModels();
	void AddViewModel(class UMVVMViewModelCollectionObject* VMCollection, const TSubclassOf<class UMVVMViewModelBase>& ViewModelClass, FName ViewModelUniqueIdentifier);
	
};
