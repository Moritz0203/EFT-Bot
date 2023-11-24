#include "HumanizedMovement.h"
#include <thread>

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
std::thread MouseThread;

MoveState moveState(MOVE_TYPE_NONE, false, false);
MovingCondition movingCondition = MOVING_CONDITION_WALK;

std::shared_ptr<MoveState> MoveState_ptr = std::make_shared<MoveState>(moveState);
std::shared_ptr<MovingCondition> ConditionState_ptr = std::make_shared<MovingCondition>(movingCondition);


void HumanizedMovement::MoveBigCircle(std::shared_ptr<MoveState> move_ptr) {
	MovingCondition InternalMovingCondition = MOVING_CONDITION_NONE;

	while (move_ptr->moveType == MOVE_TYPE_BIG_CIRCLE) {
		
		if (move_ptr->KillProcess) {
			// Kill Process
			break;
		}
		else if (move_ptr->SoftKillProcess) {
			// Soft Kill Process
			break;
		}
		else {
			// Continue Process
			if (InternalMovingCondition != *ConditionState_ptr) {
				// Change Moving Condition
			}
		}

	}
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

int HumanizedMovement::StartMovingCondition(MovingCondition movingCondition) {
	int errorCode = 0;

	if (!MoveThread.joinable())
		return ThreadNotRunning;

	if (MoveState_ptr->moveType == MOVE_TYPE_NONE)
		return MoveNotRunning;

	*ConditionState_ptr = movingCondition;

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