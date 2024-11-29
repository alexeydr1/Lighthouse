// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "SkillsComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnEnduranceModifierChanged, float, NewValue);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class LIGHTHOUSEPROJECT_API USkillsComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	USkillsComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float EnduranceModifier = 1.f;

public:	

	UPROPERTY(BlueprintAssignable)
	FOnEnduranceModifierChanged OnEnduranceModifierChanged;

	UFUNCTION(BlueprintCallable)
	void AddNewEnduranceModifier(float Add) 
	{ 
		EnduranceModifier += Add;
		OnEnduranceModifierChanged.Broadcast(EnduranceModifier);
	};
	UFUNCTION(BlueprintPure)
	float GetEnduranceModifier() { return EnduranceModifier; };

	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
};
