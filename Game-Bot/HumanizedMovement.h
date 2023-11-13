#pragma once
#include "HumanizedKeyboard.h"
#include "HumanizedMouse.h"

typedef enum e_movetype {
	MOVE_TYPE_STOP = 1,
	MOVE_TYPE_BIG_CIRCLE = 2,
	MOVE_TYPE_SMALL_CIRCLE = 3,
	MOVE_TYPE_AUTO = 4,
	MOVE_TYPE_RANDOM = 5,
} MoveType;

struct MoveState {
	MoveType moveType;
	bool KillProcess; // true = Kill Process, false = Continue Process
	bool SoftKillProcess; // true = Soft Kill Process, false = Continue Process

	MoveState(MoveType dir, bool killProcess, bool softKillProcess);
};

class HumanizedMovement : public HumanizedKeyboard, public HumanizedMouse {
	

	
public:

	void StartMove(MoveType moveType = MOVE_TYPE_AUTO);
	void StopMove(MoveType moveType, bool KillProcess, bool SoftKillProcess);
};