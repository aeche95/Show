// Copyright to Andres Echeverri 2023


#include "SGameplayStatics.h"
#include "Types/MVVMViewModelContext.h"
#include "UI/MVVM/SPlayerHUDVM.h"
#include "MVVMGameSubsystem.h"
#include "Settings/SGameInstance.h"

USPlayerHUDVM* USGameplayStatics::GetHUDVM(UObject* WorldContextObject)
{
	if (WorldContextObject)
	{
		const UMVVMViewModelCollectionObject* VMCollection = WorldContextObject->GetWorld()->GetGameInstance()->GetSubsystem<UMVVMGameSubsystem>()->GetViewModelCollection();

		FMVVMViewModelContext Context;
		Context.ContextName = TEXT("HUDVM");
		Context.ContextClass = USPlayerHUDVM::StaticClass();

		UMVVMViewModelBase* Found = VMCollection->FindViewModelInstance(Context);
		return Cast<USPlayerHUDVM>(Found);
	}
	return nullptr;
}
