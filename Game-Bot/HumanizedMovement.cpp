#include "HumanizedMovement.h"
#include <thread>
#include <iostream>

MoveState::MoveState(MoveType dir, bool killProcess, bool softKillProcess)
	: moveType(dir) {
	if (killProcess && softKillProcess) {
		KillProcess = true;
		SoftKillProcess = false;
	}
	else {
		KillProcess = killProcess;
		SoftKillProcess = softKillProcess;
	}
}



/// Private
std::thread MoveThread;

MoveState moveState(MOVE_TYPE_NONE, false, false);
MovingCondition movingCondition = MOVING_CONDITION_WALK;

std::shared_ptr<MoveState> MoveState_ptr = std::make_shared<MoveState>(moveState);
std::shared_ptr<MovingCondition> ConditionState_ptr = std::make_shared<MovingCondition>(movingCondition);

Direction CheckDirection(MovingCondition movingCondition) {
	Direction InternalDirection = NoDirection;

	//std::cout << "CheckDirection: " << movingCondition << std::endl;

	switch (movingCondition)
	{
	case MOVING_CONDITION_NONE:
		return NoDirection;
		break;

	case MOVING_CONDITION_SPRINT:
		std::cout << "Sprint" << std::endl;
		InternalDirection = SprintForward;
		break;

	case MOVING_CONDITION_WALK:
		std::cout << "Walk" << std::endl;
		InternalDirection = Forward;
		break;

	case MOVING_CONDITION_CRIP:
		//InternalDirection = Crip; // TODO: Add Crip
		break;
	}

	return InternalDirection;
}

int HumanizedMovement::MoveBigCircle(std::shared_ptr<MoveState> move_ptr) {
	MovingCondition InternalMovingCondition = MOVING_CONDITION_NONE;
	Direction InternalDirection = NoDirection;

	InternalMovingCondition = *ConditionState_ptr;
	InternalDirection = CheckDirection(InternalMovingCondition);

	HumanizedKeyboard.MoveToDirection(InternalDirection);

	while (true) {

		if (move_ptr->KillProcess) {
			HumanizedKeyboard.EndMoveToDirection(InternalDirection, true, false);
			break;
		}
		else if (move_ptr->SoftKillProcess) {
			HumanizedKeyboard.EndMoveToDirection(InternalDirection, false, true);
			break;
		}
		else if (InternalMovingCondition != *ConditionState_ptr) { 
			if(InternalDirection == SprintForward || InternalDirection == AutoSprintForward)
				HumanizedKeyboard.EndMoveToDirection(InternalDirection, false, true);
			else 
				HumanizedKeyboard.EndMoveToDirection(InternalDirection, true, false);

			InternalMovingCondition = *ConditionState_ptr;

			InternalDirection = CheckDirection(InternalMovingCondition);

			HumanizedKeyboard.MoveToDirection(InternalDirection);
		}

		std::this_thread::sleep_for(std::chrono::milliseconds(10));
		HumanizedMouse.MoveToExactPoint(5, 0, 2000);
	}

	return 0;
}

void HumanizedMovement::MoveSmallCircle(std::shared_ptr<MoveState> move_ptr) {

}

void HumanizedMovement::MoveBigSquare(std::shared_ptr<MoveState> move_ptr) {

}

void HumanizedMovement::MoveSmallSquare(std::shared_ptr<MoveState> move_ptr) {

}

void HumanizedMovement::MoveRandom(std::shared_ptr<MoveState> move_ptr) {

}


void HumanizedMovement::MoveAuto(std::shared_ptr<MoveState> move_ptr) {

}



/// Public
int HumanizedMovement::StartMove(MoveType moveType) {
	int errorCode = 0;
	HumanizedMovement humanizedMovement;

	if (MoveThread.joinable())
		return ThreadAlreadyRunning;

	if (moveType == MOVE_TYPE_NONE)
		return InvalidMoveType;

	if (MoveState_ptr->moveType != MOVE_TYPE_NONE)
		return MoveAlreadyRunning;

	switch (moveType) {
	case MOVE_TYPE_BIG_CIRCLE:
		MoveState_ptr->moveType = moveType;
		MoveThread = std::thread(&HumanizedMovement::MoveBigCircle, humanizedMovement, MoveState_ptr);
		break;

	case MOVE_TYPE_SMALL_CIRCLE:
		MoveState_ptr->moveType = moveType;
		MoveThread = std::thread(&HumanizedMovement::MoveSmallCircle, humanizedMovement, MoveState_ptr);
		break;

	case MOVE_TYPE_BIG_SQUARE:
		MoveState_ptr->moveType = moveType;
		MoveThread = std::thread(&HumanizedMovement::MoveBigSquare, humanizedMovement, MoveState_ptr);
		break;

	case MOVE_TYPE_SMALL_SQUARE:
		MoveState_ptr->moveType = moveType;
		MoveThread = std::thread(&HumanizedMovement::MoveSmallSquare, humanizedMovement, MoveState_ptr);
		break;

	case MOVE_TYPE_AUTO:
		MoveState_ptr->moveType = moveType;
		MoveThread = std::thread(&HumanizedMovement::MoveAuto, humanizedMovement, MoveState_ptr);
		break;

	case MOVE_TYPE_RANDOM:
		MoveState_ptr->moveType = moveType;
		MoveThread = std::thread(&HumanizedMovement::MoveRandom, humanizedMovement, MoveState_ptr);
		break;
	}

	return errorCode;
}

int HumanizedMovement::SetMovingCondition(MovingCondition movingCondition) {
	int errorCode = 0;

	if (!MoveThread.joinable())
		return ThreadNotRunning;

	if (MoveState_ptr->moveType == MOVE_TYPE_NONE)
		return MoveNotRunning;

	//std::cout << "SetMovingCondition: " << movingCondition << std::endl;

	*ConditionState_ptr = movingCondition;

	//std::cout << "SetMovingCondition_ptr: " << *ConditionState_ptr << std::endl;

	return errorCode;
}

int HumanizedMovement::StopMove(bool KillProcess, bool SoftKillProcess) {
	int errorCode = 0;

	if (MoveState_ptr->moveType == MOVE_TYPE_NONE)
		return MoveNotRunning;

	if (!MoveThread.joinable())
		return ThreadNotRunning;

	if (KillProcess && SoftKillProcess) {
		MoveState_ptr->KillProcess = true;
		MoveState_ptr->SoftKillProcess = false;
	}
	else {
		MoveState_ptr->KillProcess = KillProcess;
		MoveState_ptr->SoftKillProcess = SoftKillProcess;
	}

	MoveThread.join();

	MoveState_ptr->moveType = MOVE_TYPE_NONE;
	MoveState_ptr->KillProcess = false;
	MoveState_ptr->SoftKillProcess = false;

	return errorCode;
}