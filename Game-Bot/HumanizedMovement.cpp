#include "HumanizedMovement.h"

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

void HumanizedMovement::StartMove(MoveType moveType) {

}

void HumanizedMovement::StopMove(MoveType moveType, bool KillProcess, bool SoftKillProcess) {

}
