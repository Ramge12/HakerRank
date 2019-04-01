// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "ZeldaBOTW.h"
#include "Object/TotalItemClass.h"
#include "Blueprint/UserWidget.h"
#include "NPC_UI.generated.h"

/**
 * 
 */
UCLASS()
class ZELDABOTW_API UNPC_UI : public UUserWidget
{
	GENERATED_BODY()
		int count = 0;
	UPROPERTY(Category = NPC, EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
		UTotalItemClass* totalitemClass;
private:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = UI, Meta = (AllowPrivateAccess = true))
		class ANPC_Shop* NpcShop;
public:
	UFUNCTION(BlueprintCallable, Category = "UI")
	void ItemImageChange(UImage* image);
	
	void setNpcShop(class ANPC_Shop* shop);
};
