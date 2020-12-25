// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "PhysicsEngine/PhysicsHandleComponent.h"
#include "Grabber.generated.h"

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ESCAPEROOM_API UGrabber : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UGrabber();

public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction) override;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

private:
	UPROPERTY(EditAnywhere)
	float Reach = 100.f;

	UPhysicsHandleComponent *PhysicsHandle = nullptr;
	UInputComponent *InputComponent = nullptr;

	void Grab();
	void Release();
	void FindPhysicsHandle();
	void SetupInputComponent();

	// Return the first actor within reach with physics body
	FHitResult GetFirstPhysicsBodyInReach() const;

	// Return line trace end (end location of player reach)
	FVector GetPlayerReach() const;

	// Get Player position in the world
	FVector GetPlayersWorldPosition() const;
};
