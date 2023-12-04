#pragma once
#include "HumanizedMovement.h"


class Walk {
	bool CripWalkWhenNoStamina = false; // Set via User Input
	MoveType MoveTypes = MoveType::MOVE_TYPE_NONE;
	MovingCondition MovingConditions = MovingCondition::MOVING_CONDITION_NONE;

public:

	void SetCripWalkWhenNoStamina(bool value) {
		if(value != CripWalkWhenNoStamina)
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
		if(value != MovingCondition::MOVING_CONDITION_NONE){
			if (value != MovingConditions) {
				MovingConditions = value;
			}		
		}
	}

	bool GetCripWalkWhenNoStamina() {
		return CripWalkWhenNoStamina;
	}

	Walk(bool CripWalk, MoveType moveType, MovingCondition movingCondition) {
		SetCripWalkWhenNoStamina(CripWalk);
		SetMoveType(moveType);
		SetMovingConditions(movingCondition);
	}
};