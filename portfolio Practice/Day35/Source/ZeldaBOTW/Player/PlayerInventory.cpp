// Fill out your copyright notice in the Description page of Project Settings.

#include "PlayerInventory.h"

UPlayerInventory::UPlayerInventory()
{
	PrimaryComponentTick.bCanEverTick = false;

}

void UPlayerInventory::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}

void UPlayerInventory::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UPlayerInventory::AddSwordInventory(AWeapon_Equip * sword)
{
	Weapon_SwordList.Add(sword);
}

void UPlayerInventory::AddBowdInventory(AWeapon_Equip * Bow)
{
	Weapon_BowList.Add(Bow);
}

void UPlayerInventory::AddShieldInventory(AWeapon_Equip * Shield)
{
	Weapon_ShieldList.Add(Shield);
}

void UPlayerInventory::AddFoodInventory(AItemClassFood * Food)
{
	Item_FoodList.Add(Food);
}

void UPlayerInventory::AddMaterialInventory(AItemClassMaterial * Material)
{
	Item_MaterialList.Add(Material);
}

