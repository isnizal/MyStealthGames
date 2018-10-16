// Fill out your copyright notice in the Description page of Project Settings.

#include "MyObjectiveActor.h"
#include"Classes/Kismet/GameplayStatics.h"
#include"Components/StaticMeshComponent.h"
#include"Classes/Engine/EngineTypes.h"




// Sets default values
AMyObjectiveActor::AMyObjectiveActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComp"));
	MeshComp->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	RootComponent = MeshComp;
	SphereComp = CreateDefaultSubobject<USphereComponent>(TEXT("SphereComp"));
	SphereComp->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	SphereComp->SetCollisionResponseToAllChannels(ECR_Ignore);
	SphereComp->SetCollisionResponseToChannel(ECC_Pawn, ECR_Overlap);
	SphereComp->SetupAttachment(MeshComp);

}

// Called when the game starts or when spawned
void AMyObjectiveActor::BeginPlay()
{
	Super::BeginPlay();


}

void AMyObjectiveActor::NotifyActorBeginOverlap(AActor * OtherActor)
{
	Super::NotifyActorBeginOverlap(OtherActor);
	AMyStealthGamesCharacter * MyCharacter = Cast<AMyStealthGamesCharacter>(OtherActor);
	if (MyCharacter)
	{
		MyCharacter->isCarryingObjectives = true;
	}
	Destroy();
	PlayEffects();
	
}

// Called every frame
void AMyObjectiveActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
void AMyObjectiveActor::PlayEffects() const
{
	UGameplayStatics::SpawnEmitterAtLocation(this, ParticleFire, GetActorLocation());

}

