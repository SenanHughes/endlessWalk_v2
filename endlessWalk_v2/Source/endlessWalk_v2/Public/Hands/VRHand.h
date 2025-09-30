// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MotionControllerComponent.h"
#include "VRHand.generated.h"

UCLASS()
class ENDLESSWALK_V2_API AVRHand : public AActor
{
	GENERATED_BODY()
	
public:	
	AVRHand();


protected:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Components")
	UMotionControllerComponent* MotionController;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Components")
	USkeletalMeshComponent* HandMesh;
	

private:	

};
