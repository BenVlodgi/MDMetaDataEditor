
#include "MetaDataValueWidget.h"

#include "Kismet2/BlueprintEditorUtils.h"


FString UMetaDataValueWidget::GetMetaDataValue() const
{
    return MetaDataValue;
}

void UMetaDataValueWidget::SetMetaDataValue(FString Value)
{
    MetaDataValue = Value;

	if (EditingBlueprint.IsValid())
	{
		FBlueprintEditorUtils::SetBlueprintVariableMetaData(
			EditingBlueprint.Get(),
			VariableName,
			nullptr,
			MetaDataKey,
			MetaDataValue
			);
	}
}