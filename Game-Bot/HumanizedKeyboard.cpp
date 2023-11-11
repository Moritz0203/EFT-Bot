#include "HumanizedKeyboard.h"
#include "getMat.h"

DirectionState::DirectionState(Direction dir, bool killProcess, bool softKillProcess)
	: direction(dir) {
	if (killProcess && softKillProcess) {
		KillProcess = true;
		SoftKillProcess = false;
	}
	else {
		KillProcess = killProcess;
		SoftKillProcess = softKillProcess;
	}
}


thread DirectionThread;
thread LeftRightThread;

DirectionState DirectionFB{ NoDirection, false, false };// Forward Backwards
DirectionState DirectionRL{ NoDirection, false, false };// Right Left

std::shared_ptr<DirectionState> DirectionFB_ptr = std::make_shared<DirectionState>(DirectionFB);// Forward Backwards pointer
std::shared_ptr<DirectionState> DirectionRL_ptr = std::make_shared<DirectionState>(DirectionRL);// Right Left pointer


int HumanizedKeyboard::CheckForError(Direction direction, Direction conflictDirection) {

	if (direction == DirectionFB_ptr->direction || direction == DirectionRL_ptr->direction)
		return DirectionAlreadyExists;

	if (conflictDirection == DirectionFB_ptr->direction || conflictDirection == DirectionRL_ptr->direction)
		return DirectionConflict;

	return 0;
}

int HumanizedKeyboard::CheckStaminaBar() {
	const HWND hWND = GetMat::FindeWindow();
	cv::Mat MatScreen = GetMat::getMatWithRect(hWND, { 50, 1035 }, 146, 3);

	/// 142 , 1 
	/// 4 , 1 

	cv::Point pointFull(142, 2);
	cv::Point pointEmpty(4, 2);

	cv::Vec3b colorFull = MatScreen.at<cv::Vec3b>(pointFull);
	cv::Vec3b colorEmpty = MatScreen.at<cv::Vec3b>(pointEmpty);

	cv::Vec3b targetColorFull(106, 128, 32);
	cv::Vec3b targetColorEmpty(0, 0, 0);

	if (colorFull == targetColorFull) {
		return 100;
	}
	else if (colorEmpty == targetColorEmpty) {
		return 0;
	}
	else {
		return -1;
	}
}



void HumanizedKeyboard::ForwardMove(std::shared_ptr<DirectionState> directionState_ptr) {
	INPUT input[1];
	input[0].type = INPUT_KEYBOARD;
	input[0].ki.wVk = 'W'; // Hier die gewünschte Taste
	input[0].ki.dwFlags = 0;
	SendInput(1, &input[0], sizeof(INPUT));

	while (directionState_ptr->KillProcess != true) {
		std::this_thread::sleep_for(std::chrono::milliseconds(100));
	}

	input[0].ki.dwFlags = KEYEVENTF_KEYUP;
	SendInput(1, &input[0], sizeof(INPUT));
}

void HumanizedKeyboard::BackwardsMove(std::shared_ptr<DirectionState> directionState_ptr) {
	INPUT input[1];
	input[0].type = INPUT_KEYBOARD;
	input[0].ki.wVk = 'S';
	input[0].ki.dwFlags = 0;
	SendInput(1, &input[0], sizeof(INPUT));

	while (directionState_ptr->KillProcess != true) {
		std::this_thread::sleep_for(std::chrono::milliseconds(100));
	}

	input[0].ki.dwFlags = KEYEVENTF_KEYUP;
	SendInput(1, &input[0], sizeof(INPUT));
}

void HumanizedKeyboard::RightMove(std::shared_ptr<DirectionState> directionState_ptr) {
	INPUT input[1];
	input[0].type = INPUT_KEYBOARD;
	input[0].ki.wVk = 'D';
	input[0].ki.dwFlags = 0;
	SendInput(1, &input[0], sizeof(INPUT));

	while (directionState_ptr->KillProcess != true) {
		std::this_thread::sleep_for(std::chrono::milliseconds(100));
	}

	input[0].ki.dwFlags = KEYEVENTF_KEYUP;
	SendInput(1, &input[0], sizeof(INPUT));
}

void HumanizedKeyboard::LeftMove(std::shared_ptr<DirectionState> directionState_ptr) {
	INPUT input[1];
	input[0].type = INPUT_KEYBOARD;
	input[0].ki.wVk = 'A';
	input[0].ki.dwFlags = 0;
	SendInput(1, &input[0], sizeof(INPUT));

	while (directionState_ptr->KillProcess != true) {
		std::this_thread::sleep_for(std::chrono::milliseconds(100));
	}

	input[0].ki.dwFlags = KEYEVENTF_KEYUP;
	SendInput(1, &input[0], sizeof(INPUT));
}

void HumanizedKeyboard::SprindForwardMove(std::shared_ptr<DirectionState> directionState_ptr) {
	INPUT input[2];
	input[0].type = INPUT_KEYBOARD;
	input[0].ki.wVk = 'W';
	input[0].ki.dwFlags = 0;

	SendInput(1, &input[0], sizeof(INPUT));
	Sleep(1000);

	input[1].type = INPUT_KEYBOARD;
	input[1].ki.wVk = VK_SHIFT;
	input[1].ki.dwFlags = 0;
	SendInput(1, &input[1], sizeof(INPUT));

	while (directionState_ptr->KillProcess != true) {
		std::this_thread::sleep_for(std::chrono::milliseconds(100));
	}

	input[1].ki.dwFlags = KEYEVENTF_KEYUP;
	SendInput(1, &input[1], sizeof(INPUT));
	Sleep(500);
	input[0].ki.dwFlags = KEYEVENTF_KEYUP;
	SendInput(1, &input[0], sizeof(INPUT));
}

void HumanizedKeyboard::SprintForwardControler(std::shared_ptr<DirectionState> directionState_ptr) {
	thread InternalThread;
	HumanizedKeyboard humanizedKeyboard;

	DirectionState ForwardStateInternal{ Forward, false, false };
	DirectionState SprintForwardStateInternal{ SprintForward, false, false };

	shared_ptr<DirectionState> ForwardState_ptr = std::make_shared<DirectionState>(ForwardStateInternal);
	shared_ptr<DirectionState> SprintForwardState_ptr = std::make_shared<DirectionState>(SprintForwardStateInternal);

	int stamina = CheckStaminaBar();

	if (stamina == -1) {
		InternalThread = thread(&HumanizedKeyboard::ForwardMove, &humanizedKeyboard, ForwardState_ptr);

		while (true)
		{
			stamina = CheckStaminaBar();

			if (stamina == 100)
				break;
			 
			std::this_thread::sleep_for(std::chrono::milliseconds(500));
		}

		ForwardState_ptr->KillProcess = true;
		InternalThread.join();
		ForwardState_ptr->KillProcess = false;
	}

	bool isSprintForward = false;
	bool isSprintForwardFirstTime = true;
	int count = 4;
	while (directionState_ptr->KillProcess != true) {
		stamina = CheckStaminaBar();

		if (stamina == 0 && directionState_ptr->SoftKillProcess == true)
			break;

		if (stamina == 0) {

			if (isSprintForward) {
				SprintForwardState_ptr->KillProcess = true;
				InternalThread.join();

				SprintForwardState_ptr->KillProcess = false;

				InternalThread = thread(&HumanizedKeyboard::ForwardMove, &humanizedKeyboard, ForwardState_ptr);
				isSprintForward = false;
			}
		}
		else if (stamina == 100) {

			if (!isSprintForward) {

				if (!isSprintForwardFirstTime) {
					ForwardState_ptr->KillProcess = true;
					InternalThread.join();

					ForwardState_ptr->KillProcess = false;
				}
				else {
					isSprintForwardFirstTime = false;
				}

				InternalThread = thread(&HumanizedKeyboard::SprindForwardMove, &humanizedKeyboard, SprintForwardState_ptr);
				isSprintForward = true;
				count = 4;
			}
			else if (stamina == 100 && isSprintForward == true) {

				if (count == 0) {

					INPUT input[2];
					input[0].type = INPUT_KEYBOARD;
					input[0].ki.wVk = VK_SHIFT;
					input[0].ki.dwFlags = KEYEVENTF_KEYUP;
					SendInput(1, &input[0], sizeof(INPUT));

					Sleep(500);

					input[1].type = INPUT_KEYBOARD;
					input[1].ki.wVk = VK_SHIFT;
					input[1].ki.dwFlags = 0;
					SendInput(1, &input[1], sizeof(INPUT));

					count = 4;
				}
				else {
					count--;
				}
			}
		}

		std::this_thread::sleep_for(std::chrono::milliseconds(500));
	}

	if (isSprintForward)
		SprintForwardState_ptr->KillProcess = true;
	else
		ForwardState_ptr->KillProcess = true;

	InternalThread.join();
}


/// Public functions
int HumanizedKeyboard::EndMoveToDirection(Direction direction, bool KillProcess, bool SoftKillProcess) {
	std::shared_ptr<DirectionState> directionState_ptr;
	bool isDirectionFB = false;

	if (direction == DirectionFB_ptr->direction) {
		directionState_ptr = DirectionFB_ptr;
		isDirectionFB = true;
	}
	else if (direction == DirectionRL_ptr->direction) {
		directionState_ptr = DirectionRL_ptr;
	}
	else
		return DirectionDoesNotExist;

	if (KillProcess == false && SoftKillProcess == false)
		return NoKillProcess;

	if (KillProcess == true && SoftKillProcess == true) {
		directionState_ptr->KillProcess = true;
		directionState_ptr->SoftKillProcess = false;
	}
	else {
		directionState_ptr->KillProcess = KillProcess;
		directionState_ptr->SoftKillProcess = SoftKillProcess;
	}

	if (isDirectionFB)
		DirectionThread.join();
	else
		LeftRightThread.join();

	directionState_ptr->KillProcess = false;
	directionState_ptr->SoftKillProcess = false;

	return 0;
}

int HumanizedKeyboard::MoveToDirection(Direction direction) {
	int errorCode = 0;
	HumanizedKeyboard humanizedKeyboard;

	switch (direction) {
	case NoDirection:
		return InvalidDirection;
		break;

	case Forward:
		errorCode = CheckForError(direction, Backwards);
		if (errorCode != 0) {
			return errorCode;
		}
		DirectionFB_ptr->direction = direction;
		DirectionThread = thread(&HumanizedKeyboard::ForwardMove, &humanizedKeyboard, DirectionFB_ptr);
		break;

	case Backwards:
		errorCode = CheckForError(direction, Forward);
		if (errorCode != 0) {
			return errorCode;
		}
		DirectionFB_ptr->direction = direction;
		DirectionThread = thread(&HumanizedKeyboard::BackwardsMove, &humanizedKeyboard, DirectionFB_ptr);
		break;

	case Right:
		errorCode = CheckForError(direction, Left);
		if (errorCode != 0) {
			return errorCode;
		}
		DirectionRL_ptr->direction = direction;
		LeftRightThread = thread(&HumanizedKeyboard::RightMove, &humanizedKeyboard, DirectionRL_ptr);
		break;

	case Left:
		errorCode = CheckForError(direction, Right);
		if (errorCode != 0) {
			return errorCode;
		}
		DirectionRL_ptr->direction = direction;
		LeftRightThread = thread(&HumanizedKeyboard::LeftMove, &humanizedKeyboard, DirectionRL_ptr);
		break;

	case AutoForward:
		errorCode = CheckForError(direction, Backwards);
		if (errorCode != 0) {
			return errorCode;
		}
		DirectionFB_ptr->direction = direction;
		DirectionThread = thread(&HumanizedKeyboard::AutoForwardMove, &humanizedKeyboard, DirectionFB_ptr);
		break;

	case SprintForward:
		errorCode = CheckForError(direction, Backwards);
		if (errorCode != 0) {
			return errorCode;
		}
		DirectionFB_ptr->direction = direction;
		DirectionThread = thread(&HumanizedKeyboard::SprintForwardControler, &humanizedKeyboard, DirectionFB_ptr);
		break;

	case AutoSprintForward:
		errorCode = CheckForError(direction, Backwards);
		if (errorCode != 0) {
			return errorCode;
		}
		DirectionFB_ptr->direction = direction;
		DirectionThread = thread(&HumanizedKeyboard::AutoSprintForwardMove, &humanizedKeyboard, DirectionFB_ptr);
		break;
	}
}
