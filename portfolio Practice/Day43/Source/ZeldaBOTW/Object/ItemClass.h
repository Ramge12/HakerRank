// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "ZeldaBOTW.h"
#include "Components/Image.h"
#include "GameFramework/Actor.h"
#include "ItemClass.generated.h"


UENUM()
enum class ItemTypeValue : uint8 {
	ItemType_Weapon		UMETA(DisplayName = "ItemType_Weapon"),
	ItemType_Bow		UMETA(DisplayName = "ItemType_Bow"),
	ItemType_Material	UMETA(DisplayName = "ItemType_Material"),
	ItemType_Shield		UMETA(DisplayName = "ItemType_Shield"),
	ItemType_Tshirts	UMETA(DisplayName = "ItemType_Tshirts"),
	ItemType_Pants		UMETA(DisplayName = "ItemType_Pants")
};

UCLASS()
class ZELDABOTW_API AItemClass : public AActor
{
	GENERATED_BODY()
private:
	UPROPERTY(Category = Item, EditAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	FName ItemName;
	UPROPERTY(Category = Item, EditAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	UTexture2D*  ItemImage;
	UPROPERTY(Category = Item, EditAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	FString ItemInformation;
	UPROPERTY(Category = Item, EditAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	ItemTypeValue ItmeType;
	UPROPERTY(Category = Item, EditAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	float ItemPrice;
	
public:	
	AItemClass();

	FName getItmeName() { return ItemName; }
	UTexture2D*  getItemImage() { return ItemImage; }
	FString getItemInformation() { return ItemInformation; }
	ItemTypeValue getItmeTypeValue() { return ItmeType; }
	float getItemPrice() { return ItemPrice; }
	
};
