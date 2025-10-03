// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Interfaces/InteractInterface.h"
#include "VRHand.generated.h"

class UMotionControllerComponent;
class USkeletalMeshComponent;
class UWidgetInteractionComponent;
class USphereComponent;

UCLASS()
class ENDLESSWALK_V2_API AVRHand : public AActor
{
	GENERATED_BODY()
	
public:	
	AVRHand();


protected:
	virtual void OnConstruction(const FTransform& Transform) override;
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable)
	void GrabObject();
	UFUNCTION(BlueprintCallable)
	void ReleaseObject();

#pragma region Components

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
	TObjectPtr<UMotionControllerComponent> MotionController;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components|Hands")
	TObjectPtr<USkeletalMeshComponent> HandMesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components|Hands")
	TObjectPtr<UWidgetInteractionComponent> WidgetInteractionComponent;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components|Hands")
	TObjectPtr<USphereComponent> GrabSphere;

#pragma endregion

#pragma region HandData

	//Defines which Hand it is
	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly, Category = "Components|Hands|HandData")
	EControllerHand HandType;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Components|Hands|HandData")
	bool bMirrorAnimation;

#pragma endregion
private:	
	TScriptInterface<IInteractInterface> CurrentlyGrabbedActor;
};
