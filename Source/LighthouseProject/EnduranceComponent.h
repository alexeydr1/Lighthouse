// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BaseValueComponent.h"
#include "EnduranceComponent.generated.h"

/**
 * 
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class LIGHTHOUSEPROJECT_API UEnduranceComponent : public UBaseValueComponent
{
	GENERATED_BODY()

protected:

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	float RegenerationStrong = 3.f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	class USoundBase* StandartBreathing;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	class USoundBase* TiredBreathing;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	class USoundBase* ExhaustedBreathing;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	class UAudioComponent* AudioComponent;

	virtual void BeginPlay() override;

	UFUNCTION()
	void OnEnduranceModifierChanged(float NewValue);

	virtual void OnAddValue(float Add) override;
	virtual void OnSubsractValue(float Substract) override;
	virtual void OnValueIsMin() override;
};
