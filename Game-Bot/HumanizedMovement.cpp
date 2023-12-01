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

void HumanizedMovement::MoveBigCircle(std::shared_ptr<MoveState> move_ptr) {
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
			if (InternalDirection == SprintForward || InternalDirection == AutoSprintForward)
				HumanizedKeyboard.EndMoveToDirection(InternalDirection, false, true);
			else
				HumanizedKeyboard.EndMoveToDirection(InternalDirection, true, false);

			InternalMovingCondition = *ConditionState_ptr;
			InternalDirection = CheckDirection(InternalMovingCondition);

			HumanizedKeyboard.MoveToDirection(InternalDirection);
		}

		std::this_thread::sleep_for(std::chrono::milliseconds(5));
		HumanizedMouse.MoveToExactPoint(5, 0, 2000);// NOTE: Later with user input
	}
}

void HumanizedMovement::MoveSmallCircle(std::shared_ptr<MoveState> move_ptr) {
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
			if (InternalDirection == SprintForward || InternalDirection == AutoSprintForward)
				HumanizedKeyboard.EndMoveToDirection(InternalDirection, false, true);
			else
				HumanizedKeyboard.EndMoveToDirection(InternalDirection, true, false);

			InternalMovingCondition = *ConditionState_ptr;
			InternalDirection = CheckDirection(InternalMovingCondition);

			HumanizedKeyboard.MoveToDirection(InternalDirection);
		}

		std::this_thread::sleep_for(std::chrono::milliseconds(5));
		HumanizedMouse.MoveToExactPoint(8, 0, 1700);// NOTE: Later with user input
	}
}

void HumanizedMovement::MoveBigSquare(std::shared_ptr<MoveState> move_ptr) {
	MovingCondition InternalMovingCondition = MOVING_CONDITION_NONE;
	Direction InternalDirection = NoDirection;

	InternalMovingCondition = *ConditionState_ptr;
	InternalDirection = CheckDirection(InternalMovingCondition);

	HumanizedKeyboard.MoveToDirection(InternalDirection);
	int tick = 0;
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
			if (InternalDirection == SprintForward || InternalDirection == AutoSprintForward)
				HumanizedKeyboard.EndMoveToDirection(InternalDirection, false, true);
			else
				HumanizedKeyboard.EndMoveToDirection(InternalDirection, true, false);

			InternalMovingCondition = *ConditionState_ptr;
			InternalDirection = CheckDirection(InternalMovingCondition);

			HumanizedKeyboard.MoveToDirection(InternalDirection);
		}

		std::this_thread::sleep_for(std::chrono::milliseconds(5));
		tick++;

		if (HumanizedKeyboard.IsSprinting()) {
			if (tick >= 250) {
				HumanizedMouse.MoveToDirection(RotationX::RightSprintX);
				tick = 0;
			}
		}
		else {
			if (tick >= 600) {
				HumanizedMouse.MoveToDirection(RotationX::RightX);
				tick = 0;
			}
		}

	}
}

void HumanizedMovement::MoveSmallSquare(std::shared_ptr<MoveState> move_ptr) {

}


void HumanizedMovement::MoveThreadForRandom(std::shared_ptr<MoveState> move_ptr) {
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
			if (InternalDirection == SprintForward || InternalDirection == AutoSprintForward)
				HumanizedKeyboard.EndMoveToDirection(InternalDirection, false, true);
			else
				HumanizedKeyboard.EndMoveToDirection(InternalDirection, true, false);

			InternalMovingCondition = *ConditionState_ptr;
			InternalDirection = CheckDirection(InternalMovingCondition);

			HumanizedKeyboard.MoveToDirection(InternalDirection);
		}

		std::this_thread::sleep_for(std::chrono::milliseconds(100));
	}
}

void HumanizedMovement::MoveRandomControler(std::shared_ptr<MoveState> move_ptr) { // TODO: Make it more random
	std::thread MoveThreadForRandomThread(&HumanizedMovement::MoveThreadForRandom, this, move_ptr);
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> rand(1, 2);
	std::uniform_int_distribution<int> rand2(250, 1500);
	std::uniform_int_distribution<int> rand3(4, 12);

	int ChouseTypeTick = 0;
	int Tick = 0;
	int Type = 0;
	int LeftRight = 0;
	int SquareSize = 0;	
	int CircleSize = 0;

	while (true) {

		if (!MoveThreadForRandomThread.joinable())
			break;

		std::this_thread::sleep_for(std::chrono::milliseconds(5));
		ChouseTypeTick++;
		Tick++;

		if (ChouseTypeTick >= 6000) {
			Type = rand(gen);
			LeftRight = rand(gen);
			SquareSize = rand2(gen);
			CircleSize = rand3(gen);
			ChouseTypeTick = 0;
		}

		if (Type == 1) {// Square

			if (Tick >= SquareSize) {

				if (LeftRight == 1) {// Right
					if (HumanizedKeyboard.IsSprinting())
						HumanizedMouse.MoveToDirection(RotationX::RightSprintX);
					else
						HumanizedMouse.MoveToDirection(RotationX::RightX);

					Tick = 0;
				}
				else {// Left
					if (HumanizedKeyboard.IsSprinting())
						HumanizedMouse.MoveToDirection(RotationX::LeftSprintX);
					else
						HumanizedMouse.MoveToDirection(RotationX::LeftX);

					Tick = 0;
				}
			}
		}
		else {// Circle
			if (LeftRight == 1) {// Right
				HumanizedMouse.MoveToExactPoint(CircleSize, 0, 1700);
			}
			else {// Left
				HumanizedMouse.MoveToExactPoint(CircleSize *= -1, 0, 1700);
			}
		}
	}
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
		MoveThread = std::thread(&HumanizedMovement::MoveRandomControler, humanizedMovement, MoveState_ptr);
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