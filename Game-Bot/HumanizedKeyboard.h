#pragma once
#include "Windows.h"
#include <memory>

typedef enum e_direction {
	Forward = 0,
	Backwards = 1,
	Right = 2,
	Left = 3,
	AutoForward = 4,
	SprintForward = 5,
	AutoSprintForward = 6,

	NoDirection = 10,
}Direction;

enum ErrorCodes {
	InvalidDirection = 10,
	DirectionAlreadyExists = 11,
	DirectionConflict = 12,
	DirectionDoesNotExist = 13,
	NoKillProcess = 14,
};

struct DirectionState {
	Direction direction;
	bool KillProcess; // true = Kill Process, false = Continue Process
	bool SoftKillProcess; // true = Soft Kill Process, false = Continue Process

	DirectionState(Direction dir, bool killProcess, bool softKillProcess);
};

class HumanizedKeyboard {

	int CheckForError(Direction direction, Direction conflictDirection);
	int CheckStaminaBar();

	void ForwardMove(std::shared_ptr<DirectionState> directionState_ptr);
	void BackwardsMove(std::shared_ptr<DirectionState> directionState_ptr);
	void RightMove(std::shared_ptr<DirectionState> directionState_ptr);
	void LeftMove(std::shared_ptr<DirectionState> directionState_ptr);
	void SprindForwardMove(std::shared_ptr<DirectionState> directionState_ptr);

	void SprintForwardControler(std::shared_ptr<DirectionState> directionState_ptr);
	void AutoForwardMove(std::shared_ptr<DirectionState> directionState_ptr) {}
	void AutoSprintForwardMove(std::shared_ptr<DirectionState> directionState_ptr) {}

public:

	void MoveToExactPosition() { }

	int EndMoveToDirection(Direction direction, bool KillProcess, bool SoftKillProcess); // KillProcess instend kills the process, SoftKillProcess instend stops the process at the next possible point

	int MoveToDirection(Direction direction = NoDirection);
};