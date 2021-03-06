// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Engine/TriggerVolume.h"
#include "OpenDoor.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FDoorEvent);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class UDEMY_PROJECT_API UOpenDoor : public UActorComponent
{
	GENERATED_BODY()

private:
	AActor *Owner = nullptr;

	UPROPERTY(EditAnywhere)
	ATriggerVolume *PressurePlate = nullptr;

	UPROPERTY(EditAnywhere)
	float TriggerMass = 30.f;

public:	
	UPROPERTY(BlueprintAssignable)
	FDoorEvent OnOpen;
	UPROPERTY(BlueprintAssignable)
	FDoorEvent OnClose;

	// Sets default values for this component's properties
	UOpenDoor();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	void InitPressurePlate();
	float GetTotalMassOfActorsOnPlate();

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
};
