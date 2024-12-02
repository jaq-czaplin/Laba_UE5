// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Delegates/DelegateCombinations.h"
#include "PlayerExpComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnExpUpdated);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class JCC_PROJECT_LABA_API UPlayerExpComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UPlayerExpComponent();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (ClampMin = "0", UIMin = "0"))
	int32 CurrentExp = 0;

	UPROPERTY(BlueprintAssignable)
	FOnExpUpdated OnExpUpdated;


protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION(BlueprintCallable, Category = "Laba_UE5")
	void SetExp(int32 NewExp);

	UFUNCTION(BlueprintCallable, Category = "Laba_UE5")
	void AddExp(int32 NewExp);
		
};
