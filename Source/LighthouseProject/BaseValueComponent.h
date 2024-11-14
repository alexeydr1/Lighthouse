// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "BaseValueComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class LIGHTHOUSEPROJECT_API UBaseValueComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UBaseValueComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float CurrentValue = 100.f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float MaxValue = 100.f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float MinValue = 0.f;

	virtual void OnAddValue(float Add) {};
	virtual void OnSubsractValue(float Substract) {};
	virtual void OnValueIsMin() {};

public:	

	UFUNCTION(BlueprintCallable)
	void AddValue(float Add);

	UFUNCTION(BlueprintCallable)
	void SubstractValue(float Substract);

	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	
};
