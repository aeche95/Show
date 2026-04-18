// Copyright to Andres Echeverri 2023


#include "Subsystems/SVMGameInstanceSubsystem.h"
#include "MVVMGameSubsystem.h"
#include "UI/MVVM/SPlayerHUDVM.h"
#include "UI/MVVM/SInventoryVM.h"

void USVMGameInstanceSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);

	Collection.InitializeDependency(ThisClass::StaticClass());

	RegisterViewModels();
}

void USVMGameInstanceSubsystem::RegisterViewModels()
{
	const auto MVVMCollection = GetGameInstance()->GetSubsystem<UMVVMGameSubsystem>()->GetViewModelCollection();

	AddViewModel(MVVMCollection, USPlayerHUDVM::StaticClass(), FName("HUDVM"));
	AddViewModel(MVVMCollection, USInventoryVM::StaticClass(), FName("InventoryVM"));
}

void USVMGameInstanceSubsystem::AddViewModel(UMVVMViewModelCollectionObject* VMCollection, const TSubclassOf<class UMVVMViewModelBase>& ViewModelClass, FName ViewModelUniqueIdentifier)
{
	FMVVMViewModelContext ViewModelContext;
	ViewModelContext.ContextName = ViewModelUniqueIdentifier;
	ViewModelContext.ContextClass = ViewModelClass;

	UMVVMViewModelBase* VMInstance = NewObject<UMVVMViewModelBase>(this, ViewModelClass);
	VMCollection->AddViewModelInstance(ViewModelContext, VMInstance);
}
