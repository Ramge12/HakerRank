// Fill out your copyright notice in the Description page of Project Settings.

#include "Practice1Character.h"


// Sets default values
APractice1Character::APractice1Character()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SPRINGARM"));
	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("CAMERA"));
	hairMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("HairMesh"));
	upperMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("UpperMesh"));
	underMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("UnderMesh"));

	SpringArm->SetupAttachment(GetCapsuleComponent());
	Camera->SetupAttachment(SpringArm);

	GetCapsuleComponent()->SetCapsuleRadius(10);
	GetCapsuleComponent()->SetCapsuleHalfHeight(35);

	GetMesh()->SetRelativeLocationAndRotation(FVector(0.0f, 0.0f, -35.0f),FRotator(0.0f,-90.0f,0.0f));
	
	SpringArm->TargetArmLength = 150.0f;
	SpringArm->SetRelativeRotation(FRotator(-15.0f, 0.0f, 0.0f));

	static ConstructorHelpers::FObjectFinder<USkeletalMesh> Root_Mesh(TEXT("/Game/PlayerCharacter/LINK_FBX/Idle.Idle"));
	if (Root_Mesh.Succeeded()) {
		GetMesh()->SetSkeletalMesh(Root_Mesh.Object);
	}
	static ConstructorHelpers::FObjectFinder<USkeletalMesh> hairSkeletal(TEXT("/Game/PlayerCharacter/Hair/1/Hair.Hair"));
	if (hairSkeletal.Succeeded()) {
		hairMesh->SetSkeletalMesh(hairSkeletal.Object);
	}
	hairMesh->SetupAttachment(GetMesh());
	static ConstructorHelpers::FObjectFinder<USkeletalMesh> shirtsSkeletal(TEXT("/Game/PlayerCharacter/Shirts/1/shirts2.shirts2"));
	if (shirtsSkeletal.Succeeded()) {
		upperMesh->SetSkeletalMesh(shirtsSkeletal.Object);
	}
	upperMesh->SetupAttachment(GetMesh());
	static ConstructorHelpers::FObjectFinder<USkeletalMesh> pantsSkeletal(TEXT("/Game/PlayerCharacter/Pants/1/Pants.Pants"));
	if (pantsSkeletal.Succeeded()) {
		underMesh->SetSkeletalMesh(pantsSkeletal.Object);
	}
	underMesh->SetupAttachment(GetMesh());

	GetMesh()->SetAnimationMode(EAnimationMode::AnimationBlueprint);
	static ConstructorHelpers::FClassFinder<UAnimInstance> Player_ANIM(TEXT("/Game/PlayerCharacter/BP_Animation/Animation_BP.Animation_BP_C"));
	if (Player_ANIM.Succeeded()) {
		GetMesh()->SetAnimInstanceClass(Player_ANIM.Class);
		hairMesh->SetAnimInstanceClass(Player_ANIM.Class);
		upperMesh->SetAnimInstanceClass(Player_ANIM.Class);
		underMesh->SetAnimInstanceClass(Player_ANIM.Class);
	}
	SpringArm->bUsePawnControlRotation = true;
	SpringArm->bInheritPitch = true;
	SpringArm->bInheritRoll = true;
	SpringArm->bInheritYaw = true;
	SpringArm->bDoCollisionTest = true;
	bUseControllerRotationYaw = false;

	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 720.0f, 0.0f);
	GetCharacterMovement()->bUseControllerDesiredRotation = false;

	GetCharacterMovement()->JumpZVelocity = 400.0f;
	GetCharacterMovement()->GravityScale = 1.0f;
}

// Called when the game starts or when spawned
void APractice1Character::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APractice1Character::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);


}

// Called to bind functionality to input
void APractice1Character::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis(TEXT("UpDown"), this, &APractice1Character::UpDown); 
	PlayerInputComponent->BindAxis(TEXT("LeftRight"), this, &APractice1Character::LeftRight);
	PlayerInputComponent->BindAxis(TEXT("LookUp"), this, &APractice1Character::LookUp);
	PlayerInputComponent->BindAxis(TEXT("Turn"), this, &APractice1Character::Turn);
	PlayerInputComponent->BindAction(TEXT("JUMP"), EInputEvent::IE_Pressed, this, &ACharacter::Jump);
}

void APractice1Character::UpDown(float NewAxisValue)
{
	//AddMovementInput(GetActorForwardVector(), NewAxisValue);
	AddMovementInput(FRotationMatrix(GetControlRotation()).GetUnitAxis(EAxis::X), NewAxisValue);
}

void APractice1Character::LeftRight(float NewAxisValue)
{
	//AddMovementInput(GetActorRightVector(), NewAxisValue);
	AddMovementInput(FRotationMatrix(GetControlRotation()).GetUnitAxis(EAxis::Y), NewAxisValue);
}

void APractice1Character::LookUp(float NewAxisValue)
{
	AddControllerPitchInput(NewAxisValue);
}

void APractice1Character::Turn(float NewAxisValue)
{
	AddControllerYawInput(NewAxisValue);
}

