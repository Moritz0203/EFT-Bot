#pragma once
#include "HumanizedKeyboard.h"
#include "HumanizedMouse.h"

typedef enum e_movetype {
	MOVE_TYPE_BIG_CIRCLE = 1,
	MOVE_TYPE_SMALL_CIRCLE = 2,
	MOVE_TYPE_BIG_SQUARE = 3,
	MOVE_TYPE_SMALL_SQUARE = 4,
	MOVE_TYPE_AUTO = 5,
	MOVE_TYPE_RANDOM = 6,
	MOVE_TYPE_NONE = 7
} MoveType;

enum ErrorCodes_HumanizedMovement {
	ThreadAlreadyRunning = 1,

} ErrorCodes_HM;

struct MoveState {
	MoveType moveType;
	bool KillProcess; // true = Kill Process, false = Continue Process
	bool SoftKillProcess; // true = Soft Kill Process, false = Continue Process

	MoveState(MoveType dir, bool killProcess, bool softKillProcess);
};

class HumanizedMovement : public HumanizedKeyboard, public HumanizedMouse {
	

	
public:

	int StartMove(MoveType moveType = MOVE_TYPE_AUTO);
	int StopMove(bool KillProcess, bool SoftKillProcess);
};