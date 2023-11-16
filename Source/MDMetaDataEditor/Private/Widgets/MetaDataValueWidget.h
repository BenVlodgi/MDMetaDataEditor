#pragma once

#include "CoreMinimal.h"
#include "EditorUtilityWidget.h"

#include "MetaDataValueWidget.generated.h"


/**
 * Base Class for creating a Meta Data value editor Widget.
 */
UCLASS(Abstract)
class EXTENDEDDETAILSPANELEDITOR_API UMetaDataValueWidget : public UEditorUtilityWidget
{
	GENERATED_BODY()
	
public:
	/** Blueprint being edited. */
	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "MetaDataValueWidget")
	TWeakObjectPtr<UBlueprint> EditingBlueprint;

	/** Variable Name if the edit target is a variable. */
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "MetaDataValueWidget")
	FName VariableName;

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "MetaDataValueWidget")
	FName VariableType;


	/** Function Name if the edit target is a function. */
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "MetaDataValueWidget")
	FName FunctionName;

	/** Key to target as specified in the extended details panel config. */
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "MetaDataValueWidget")
	FName MetaDataKey;

	/** The value associated with the Meta Data Key. Set this to change the value. */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "MetaDataValueWidget", BlueprintGetter = GetMetaDataValue, BlueprintSetter = SetMetaDataValue)
	FString MetaDataValue;

	/** Values List as specified in the config. */
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "MetaDataValueWidget")
	TMap<FName, FString> ValuesList;
	
	UFUNCTION(BlueprintGetter, Category = "MetaDataValueWidget")
	FString GetMetaDataValue() const;

	UFUNCTION(BlueprintSetter, Category = "MetaDataValueWidget")
	void SetMetaDataValue(FString Value);

};
