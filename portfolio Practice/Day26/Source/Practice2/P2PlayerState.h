// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Practice2.h"
#include "GameFramework/PlayerState.h"
#include "P2PlayerState.generated.h"

UENUM()
enum class E_PlayerState : uint8 {
	Player_NONE		UMETA(DisplayName = "Player_NONE"),
	Player_IDLE		UMETA(DisplayName = "Player_IDLE"),
	Player_WALK		UMETA(DisplayName = "Player_WALK"),
	Player_JUMP		UMETA(DisplayName = "Player_JUMP"),
	Player_RUN		UMETA(DisplayName = "Player_RUN"),
	Player_COLLECT  UMETA(DisplayName = "Player_COLLECT"),
	Player_CROUCH	UMETA(DisplayName = "Player_CROUCH"),
	Player_PUSH		UMETA(DisplayName = "Player_PUSH"),
	Player_CLIMING	UMETA(DisplayName = "Player_CLIMING"),
	Player_SHOT		UMETA(DisplayName = "Player_SHOT"),
	Player_SWORD	UMETA(DisplayName = "Player_SWORD"),
	Player_SHIELD	UMETA(DisplayName = "Player_SHIELD"),
	Player_HURT		UMETA(DisplayName = "Player_HURT"),
	Player_DEATH	UMETA(DisplayName = "Player_DEATH"),
	Player_Carry	UMETA(DisplayName = "Player_Carry")
};

UCLASS()
class PRACTICE2_API AP2PlayerState : public APlayerState
{
	GENERATED_BODY()
	
private:
	int32 playerCurHp;
	int32 playerMaxHp;
	int32 playerATK;
	float invincibleTime=0.0f;
	bool invincible;

	FTimerHandle invincibleTimerHandle;
private:
	UPROPERTY(Category = State, VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	E_PlayerState EPlayerState;
	UPROPERTY(Category = State, VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	E_PlayerState preEPlayerState;
	UPROPERTY(Category = State, VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	E_PlayerState playerExtraState;
	UPROPERTY(Category = State, VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	bool ThrowObject;
	UPROPERTY(Category = State, VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	bool CounterAttack;
	UPROPERTY(Category = State, VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	bool CounterPossibility;
public:
	AP2PlayerState();

	E_PlayerState getCurPlayerState();
	E_PlayerState getPrePlayerState();
	void setPlayerState(E_PlayerState setValue);
	bool CheckCurState(E_PlayerState setValue);
	void CheckState_And_setState(E_PlayerState isCheckValue, E_PlayerState setValue);

	void setPlayerCurHP(int32 value);
	void setMaxHP(int32 value);

	void setExtraState();
	void CheckInvincibleTime();
	void setThrowObject(bool value) { ThrowObject = value; }

	void setExtraState(E_PlayerState Extra) { playerExtraState = Extra; }
	void setCounterAttackValue(bool value) { CounterAttack = value; }
	void setCounterPossibility(bool value) { CounterPossibility = value; }

	E_PlayerState getPlayerExtraState() { return playerExtraState; }
	int32 getPlayerCurHp() { return playerCurHp; }
	int32 getPlayerMaxHp() { return playerMaxHp; }
	bool getThrowValue() { return ThrowObject; }
	bool getCounterAttackValue() { return CounterAttack; }
	bool getCounterPossibility() { return CounterPossibility; }
};
