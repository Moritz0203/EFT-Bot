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

typedef enum e_movingcondition {
	MOVING_CONDITION_SPRINT = 1,
	MOVING_CONDITION_WALK = 2,
	MOVING_CONDITION_CRIP = 3,
	MOVING_CONDITION_NONE = 4
} MovingCondition;

enum ErrorCodes_HumanizedMovement {
	ThreadAlreadyRunning = 1,
	InvalidMoveType = 2,
	MoveAlreadyRunning = 3,
	MoveNotRunning = 4,
	ThreadNotRunning = 5,
	InvalideMovingCondition = 6,
};
extern ErrorCodes_HumanizedMovement ErrorCodes_HM;

struct MoveState {
	MoveType moveType;
	bool KillProcess; // true = Kill Process, false = Continue Process
	bool SoftKillProcess; // true = Soft Kill Process, false = Continue Process

	MoveState(MoveType dir, bool killProcess, bool softKillProcess);
};


class HumanizedMovement {
	HumanizedKeyboard HumanizedKeyboard;
	HumanizedMouse HumanizedMouse;

	int MoveBigCircle(std::shared_ptr<MoveState> move_ptr);
	void MoveSmallCircle(std::shared_ptr<MoveState> move_ptr);
	void MoveBigSquare(std::shared_ptr<MoveState> move_ptr);
	void MoveSmallSquare(std::shared_ptr<MoveState> move_ptr);
	void MoveRandom(std::shared_ptr<MoveState> move_ptr);
	void MoveAuto(std::shared_ptr<MoveState> move_ptr);
	
public:

	int StartMove(MoveType moveType = MOVE_TYPE_AUTO);
	int MovingCondition(MovingCondition movingCondition = MOVING_CONDITION_WALK);
	int StopMove(bool KillProcess, bool SoftKillProcess);
};