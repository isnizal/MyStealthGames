// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Classes/Components/SphereComponent.h"
#include"MyStealthGamesCharacter.h"
#include "MyObjectiveActor.generated.h"

UCLASS()
class MYSTEALTHGAMES_API AMyObjectiveActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMyObjectiveActor();
	UPROPERTY(VisibleAnywhere, Category = "Components")
	UStaticMeshComponent * MeshComp;
	UPROPERTY(VisibleAnywhere, Category = "Components")
	USphereComponent * SphereComp;
	UPROPERTY(EditDefaultsOnly, Category = "ParticleEffects")
	UParticleSystem * ParticleFire;
	virtual void PlayEffects() const;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	virtual void NotifyActorBeginOverlap(AActor* OtherActor) override;

};
