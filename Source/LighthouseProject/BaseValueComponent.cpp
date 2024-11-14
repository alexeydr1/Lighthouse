// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseValueComponent.h"

// Sets default values for this component's properties
UBaseValueComponent::UBaseValueComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

void UBaseValueComponent::SubstractValue(float Substract)
{
	if (CurrentValue - Substract <= MinValue)
	{
		CurrentValue = MinValue;
		OnValueIsMin();
	}
	else
	{
		CurrentValue -= Substract;
	}

	OnSubsractValue(Substract);
}

void UBaseValueComponent::AddValue(float Add)
{
	if (CurrentValue + Add > MaxValue)
		CurrentValue = MaxValue;
	else
		CurrentValue += Add;

	OnAddValue(Add);
}

// Called when the game starts
void UBaseValueComponent::BeginPlay()
{
	Super::BeginPlay();

	
}


// Called every frame
void UBaseValueComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

