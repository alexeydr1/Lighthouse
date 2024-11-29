// Fill out your copyright notice in the Description page of Project Settings.


#include "EnduranceComponent.h"
#include "SkillsComponent.h"
#include "Components/AudioComponent.h"
#include "TimerManager.h"

void UEnduranceComponent::BeginPlay()
{
	Super::BeginPlay();
	if (SkillsComponent)
	{
		SkillsComponent->OnEnduranceModifierChanged.AddDynamic(this, &ThisClass::OnEnduranceModifierChanged);
	}
	if (GetOwner())
	{
		if (AudioComponent)
		{
			AudioComponent->SetSound(StandartBreathing);
			AudioComponent->SetVolumeMultiplier(2);
			AudioComponent->Play();
		}
	}
	FTimerHandle Handle;
	GetWorld()->GetTimerManager().SetTimer(Handle, FTimerDelegate::CreateLambda([&] { AddValue(RegenerationStrong); }), 1.0f, true);
}

void UEnduranceComponent::OnEnduranceModifierChanged(float NewValue)
{
	MaxValue = 100.f * NewValue;
}

void UEnduranceComponent::OnAddValue(float Add)
{
	if (!AudioComponent)
		return;

	if (CurrentValue > (MaxValue / 2) && AudioComponent->GetSound() != StandartBreathing)
	{
		AudioComponent->SetSound(StandartBreathing);
		AudioComponent->SetVolumeMultiplier(2);
		AudioComponent->Play();
	}
}

void UEnduranceComponent::OnSubsractValue(float Substract)
{
	if (!AudioComponent)
		return;

	float MinAvailableValue = MaxValue / 2.f;
	if (CurrentValue <= MinAvailableValue && CurrentValue > 0)
	{
		if (AudioComponent->GetSound() != TiredBreathing)
		{
			AudioComponent->SetSound(TiredBreathing);
			AudioComponent->Play();
		}
		AudioComponent->SetVolumeMultiplier(1.f - (CurrentValue / MinAvailableValue));
		AudioComponent->SetPitchMultiplier(1.f - (CurrentValue / MinAvailableValue));
	}
}

void UEnduranceComponent::OnValueIsMin()
{
	if (!AudioComponent)
		return;
	if (AudioComponent->GetSound() != ExhaustedBreathing)
	{
		AudioComponent->SetSound(ExhaustedBreathing);
		AudioComponent->SetVolumeMultiplier(1.f);
		AudioComponent->SetPitchMultiplier(1.f);
		AudioComponent->Play();
	}
}
