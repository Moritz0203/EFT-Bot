#pragma once
#include "HumanizedMovement.h"


class Walk {
	bool CripWalkWhenNoStamina = false; // Set via User Input
	bool MovingIsRunning = false;	
	MoveType MoveTypes = MoveType::MOVE_TYPE_NONE;
	MovingCondition MovingConditions = MovingCondition::MOVING_CONDITION_NONE;
	HumanizedMovement humanizedMovement;

public:

	Walk(bool CripWalk, MoveType moveType, MovingCondition movingCondition) {
		SetCripWalkWhenNoStamina(CripWalk);
		SetMoveType(moveType);
		SetMovingConditions(movingCondition);
	}


	void SetCripWalkWhenNoStamina(bool value) {
		if (value != CripWalkWhenNoStamina)
			CripWalkWhenNoStamina = value;
	}

	void SetMoveType(MoveType value) {
		if (value != MoveType::MOVE_TYPE_NONE) {
			if (value != MoveTypes) {
				MoveTypes = value;
			}
		}
	}

	void SetMovingConditions(MovingCondition value) {
		if (value != MovingCondition::MOVING_CONDITION_NONE) {
			if (value != MovingConditions) {
				MovingConditions = value;
				
				if (MovingIsRunning)
					humanizedMovement.SetMovingCondition(MovingConditions);
			}
		}
	}

	bool GetCripWalkWhenNoStamina() {
		return CripWalkWhenNoStamina;
	}

	void InstendStopMoving() {
		if (MoveTypes != MoveType::MOVE_TYPE_NONE) {
			humanizedMovement.StopMove(true, false);
			MovingIsRunning = false;
		}
	}

	void StopMoving() {
		if (MoveTypes != MoveType::MOVE_TYPE_NONE) {
			humanizedMovement.StopMove(false, true);
			MovingIsRunning = false;
		}
	}

	void StartMoving() {
		if (MoveTypes != MoveType::MOVE_TYPE_NONE) {
			if (MovingConditions != MovingCondition::MOVING_CONDITION_NONE) {
				humanizedMovement.StartMove(MoveTypes);
				humanizedMovement.SetMovingCondition(MovingConditions);

				MovingIsRunning = true;
			}
		}
	}
};