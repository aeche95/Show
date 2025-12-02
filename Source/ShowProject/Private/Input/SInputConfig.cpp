// Copyright to Andres Echeverri 2023


#include "Input/SInputConfig.h"
#include "InputAction.h"

const UInputAction* USInputConfig::FindInputActionForTag(const FGameplayTag& InputTag, bool bLogNotFound) const
{
	for (const FSInputAction& Action : AbilityInputActions)
	{
		if (Action.InputAction && Action.InputTag == InputTag)
		{
			return Action.InputAction;
		}
	}

	return nullptr;
	
}
