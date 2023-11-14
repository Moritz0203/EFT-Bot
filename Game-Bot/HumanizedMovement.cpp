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


std::thread MoveThread;

MoveState moveState(MOVE_TYPE_NONE, false, false);

std::shared_ptr<MoveState> MoveState_ptr = std::make_shared<MoveState>(moveState);

int HumanizedMovement::StartMove(MoveType moveType) {
	int errorCode = 0;

	if(!MoveThread.joinable())
		return ThreadAlreadyRunning;

	switch (moveType) {
	case MOVE_TYPE_BIG_CIRCLE:

		break;

	case MOVE_TYPE_SMALL_CIRCLE:

		break;

	case MOVE_TYPE_BIG_SQUARE:

		break;

	case MOVE_TYPE_SMALL_SQUARE:

		break;

	case MOVE_TYPE_AUTO:

		break;

	case MOVE_TYPE_RANDOM:

		break;
	}

	return errorCode;
}

int HumanizedMovement::StopMove(bool KillProcess, bool SoftKillProcess) {

}
