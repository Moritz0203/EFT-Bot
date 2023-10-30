#include "ProgrammScheduler.h"

#include "DistributorForMatching.h"
#include "TemplateMatching.h"
#include "getMat.h"
#include "Utility.h"
#include "CaseProcessing.h"
#include "PouchProcessing.h"
#include "ReadConfigFile.h"
#include "c_log.h"
#include "BuyItemsFlea.h"
#include "LobbyControler.h"
#include "ItemMoving.h"
#include "StashObject.h"
#include "InputMK.h"

#include "human_mouse.h"
#include <cmath>
#include <random>

#define M_PI 3.14159265358979323846


// HighCard | High T
// SecurityCheck Items Barter / Medical / Food 


//void SetPosition(float x, float y) {
//	double fScreenWidth = ::GetSystemMetrics(SM_CXSCREEN);
//	double fScreenHeight = ::GetSystemMetrics(SM_CYSCREEN);
//	double fx = x * (65535.0f / fScreenWidth);
//	double fy = y * (65535.0f / fScreenHeight);
//
//	INPUT  Input = { 0 };
//	Input.type = INPUT_MOUSE;
//	Input.mi.dwFlags = MOUSEEVENTF_MOVE | MOUSEEVENTF_ABSOLUTE;
//	Input.mi.dx = (long)fx;
//	Input.mi.dy = (long)fy;
//	::SendInput(1, &Input, sizeof(INPUT));
//}

//void SetPosition(std::int32_t x, std::int32_t y)
//{
//	mouse_event(MOUSEEVENTF_MOVE, (DWORD)x, (DWORD)y, 0, 0);
//}

//void SetPosition(std::int32_t x, std::int32_t y)
//{
//	SetCursorPos(x, y);
//}




typedef enum e_rotation_x {
	Left = -900,
	Right = 900,
	HalfLeft = -400,
	HalfRight = 400,

	TurnAround = 1,
	AutoRotationX = 2,
}RotationX;

typedef enum e_rotation_y {
	Up = -800,
	Down = 800,
	HalfUp = -400,
	HalfDown = 400,

	AutoRotationY = 1,
}RotationY;

class HumanizedMouse
{
	void moveMouse(int x, int y) {
		INPUT input;
		input.type = INPUT_MOUSE;
		input.mi.dwFlags = MOUSEEVENTF_MOVE;
		input.mi.dx = x;
		input.mi.dy = y;
		input.mi.mouseData = 0;
		input.mi.time = 0;
		input.mi.dwExtraInfo = 0;

		SendInput(1, &input, sizeof(INPUT));
	}

	bool shouldAddPrefix() {
		std::srand(static_cast<unsigned>(std::time(0)));

		return (std::rand() % 2 == 0);
	}

	int getRandomValueForAutoRotation(int lower, int uper) {
		std::random_device rd;
		std::mt19937 gen(rd());
		std::uniform_int_distribution<int> distribution(-lower, uper);

		return distribution(gen);
	}

	bool isXGreaterThanY(int x, int y) {
		return x > y;
	}

	std::vector<std::pair<int, int>> makePath(int x, int y) {
		std::vector<std::pair<int, int>> result;
		std::vector<int> BiggerNumber;
		std::vector<int> SmallerNumber;

		int ProcessFirst = 0;
		int ControlProcessFirst = 0;
		int OriginalProcessFirst = 0;
		int ProcessSecond = 0;
		int ControlProcessSecond = 0;
		int OriginalProcessSecond = 0;

		bool isXGreater = isXGreaterThanY(x, y);
		std::random_device rd;
		std::mt19937 gen(rd());

		if (isXGreater) {
			ProcessFirst = abs(x);
			ControlProcessFirst = abs(x);
			OriginalProcessFirst = x;
			ProcessSecond = abs(y);
			ControlProcessSecond = abs(y);
			OriginalProcessSecond = y;
		}
		else {
			ProcessFirst = abs(y);
			ControlProcessFirst = abs(y);
			OriginalProcessFirst = y;
			ProcessSecond = abs(x);
			ControlProcessSecond = abs(x);
			OriginalProcessSecond = x;
		}

		std::uniform_int_distribution<int> distBiggerNumber_Default(6, 9);
		std::uniform_int_distribution<int> distBiggerNumber_FirstDown(4, 7);
		std::uniform_int_distribution<int> distBiggerNumber_SecondDown(2, 5);
		std::uniform_int_distribution<int> distBiggerNumber_ThirdDown(1, 3);

		int step = 0;
		while (ProcessFirst > 0) {

			if (ProcessFirst <= 1.0 / 12 * ControlProcessFirst) {
				step = distBiggerNumber_ThirdDown(gen);
			}
			else if (ProcessFirst <= 1.0 / 5 * ControlProcessFirst) {
				step = distBiggerNumber_SecondDown(gen);
			}
			else if (ProcessFirst <= 1.0 / 2 * ControlProcessFirst) {
				step = distBiggerNumber_FirstDown(gen);
			}
			else {
				step = distBiggerNumber_Default(gen);
			}

			if (step > ProcessFirst) step = ProcessFirst;

			ProcessFirst -= step;
			BiggerNumber.push_back(OriginalProcessFirst < 0 ? step *= -1 : step);
		}

		std::uniform_int_distribution<int> distSmallerNumber_Default(4, 6);
		std::uniform_int_distribution<int> distSmallerNumber_FirstDown(3, 4);
		std::uniform_int_distribution<int> distSmallerNumber_SecondDown(1, 2);
		std::uniform_int_distribution<int> distSmallerNumber_GenNull(1, 10);

		step = 0;
		while (ProcessSecond > 0) {

			if ((ProcessSecond <= (5.0 / 6) * ControlProcessSecond) && (ProcessSecond >= (2.0 / 3) * ControlProcessSecond)) {
				step = distSmallerNumber_FirstDown(gen);
			}
			else if (ProcessSecond <= (2.0 / 3) * ControlProcessSecond) {
				step = distSmallerNumber_SecondDown(gen);
			}
			else {
				step = distSmallerNumber_Default(gen);
			}

			if (step > ProcessSecond) step = ProcessSecond;

			ProcessSecond -= step;

			SmallerNumber.push_back(OriginalProcessSecond < 0 ? step *= -1 : step);
		}

		int div = BiggerNumber.size() - SmallerNumber.size();
		int Overhead = div / 5;
		int OverheadSplited = (Overhead / 2);

		while (Overhead > 0) {
			step = 1;

			if (step > Overhead) step = Overhead;

			Overhead -= step;

			if (OriginalProcessSecond < 0)
				step *= -1;

			if (Overhead < OverheadSplited)
				step *= -1;

			SmallerNumber.push_back(step);
		}

		div = BiggerNumber.size() - SmallerNumber.size();
		int zeroCount = div;

		int currentIndex = SmallerNumber.size() - 1;
		while (zeroCount > 0) {

			if (currentIndex < 0) {
				currentIndex = SmallerNumber.size() - 1;
				continue;
			}

			if (SmallerNumber[currentIndex] >= 3 || SmallerNumber[currentIndex] <= -3) {
				currentIndex = SmallerNumber.size() - 1;
				continue;
			}

			if (std::uniform_int_distribution<int>(1, 100)(gen) >= 40) {
				SmallerNumber.insert(SmallerNumber.begin() + currentIndex, 0);
				zeroCount--;
			}

			currentIndex--;
		}

		if (isXGreater) {
			if (BiggerNumber.size() == SmallerNumber.size()) {
				for (size_t i = 0; i < BiggerNumber.size(); ++i) {
					result.push_back(std::make_pair(BiggerNumber[i], SmallerNumber[i]));
				}
			}
		}
		else {
			if (BiggerNumber.size() == SmallerNumber.size()) {
				for (size_t i = 0; i < BiggerNumber.size(); ++i) {
					result.push_back(std::make_pair(SmallerNumber[i], BiggerNumber[i]));
				}
			}
		}

		return result;
	}

public:

	void MoveToExactPoint(int x, int y, uint speedIn_NS) {

	}

	void MoveViaRotation(float xRotation, float yRotation, uint speedIn_NS) {

	}

	void MoveToDirection(RotationX rotationX = AutoRotationX, RotationY rotationY = AutoRotationY, uint speedIn_NS = 900) {
		int XRotation = 0;
		int YRotation = 0;
		vector<pair<int, int>> mousePath;

		/// X
		if (rotationX == TurnAround) {
			if (shouldAddPrefix())
				XRotation = -1800;
			else
				XRotation = 1800;
		}
		else if (rotationX == AutoRotationX) {
			XRotation = getRandomValueForAutoRotation(-100, 100);
		}
		else {
			XRotation = static_cast<int>(rotationX);
		}

		/// Y
		if (rotationY == AutoRotationY) {
			YRotation = getRandomValueForAutoRotation(-20, 20);
		}
		else {
			YRotation = static_cast<int>(rotationY);
		}

		mousePath = makePath(XRotation, YRotation); 

	}
};


typedef enum e_direction {
	Forward = 0,
	Backwards = 1,
	AutoForward = 2,
	SprintForward = 3,
	AutoSprintForward = 4,

	NoDirection = 10,
}Direction;

class HumanizedKeyboard
{



public:

	void MoveToExactPosition() {

	}

	void MoveToDirection(Direction direction = NoDirection, uint speedIn_NS = 900) {

	}
};




class HumanizedMovement : public HumanizedMouse, public HumanizedKeyboard
{

};






namespace Testing {
	
	void moveMouse_testing(int x, int y) {
		INPUT input;
		input.type = INPUT_MOUSE;
		input.mi.dwFlags = MOUSEEVENTF_MOVE;
		input.mi.dx = x;
		input.mi.dy = y;
		input.mi.mouseData = 0;
		input.mi.time = 0;
		input.mi.dwExtraInfo = 0;

		std::cout << "x: " << x << " y: " << y << endl;

		SendInput(1, &input, sizeof(INPUT));
	}


	void KeyBoard_testing() {
		INPUT input;
		input.type = INPUT_KEYBOARD;
		input.ki.wVk = 0x41;
		input.ki.wScan = 0;
		input.ki.dwFlags = 0;
		input.ki.time = 0;
		input.ki.dwExtraInfo = 0;

		SendInput(1, &input, sizeof(INPUT));

		input.ki.dwFlags = KEYEVENTF_KEYUP;
		SendInput(1, &input, sizeof(INPUT));
	}


	bool isXGreaterThanY(int x, int y) {
		return x > y;
	}


	std::vector<std::pair<int, int>> makePath(int x, int y) {
		std::vector<std::pair<int, int>> result;
		std::vector<int> BiggerNumber;
		std::vector<int> SmallerNumber;

		int ProcessFirst = 0;
		int ControlProcessFirst = 0;
		int OriginalProcessFirst = 0;
		int ProcessSecond = 0;
		int ControlProcessSecond = 0;
		int OriginalProcessSecond = 0;

		bool isXGreater = isXGreaterThanY(x, y);
		std::random_device rd;
		std::mt19937 gen(rd());

		if (isXGreater) {
			ProcessFirst = abs(x);
			ControlProcessFirst = abs(x);
			OriginalProcessFirst = x;
			ProcessSecond = abs(y);
			ControlProcessSecond = abs(y);
			OriginalProcessSecond = y;
		}
		else {
			ProcessFirst = abs(y);
			ControlProcessFirst = abs(y);
			OriginalProcessFirst = y;
			ProcessSecond = abs(x);
			ControlProcessSecond = abs(x);
			OriginalProcessSecond = x;
		}


		std::uniform_int_distribution<int> distBiggerNumber_Default(6, 9);
		std::uniform_int_distribution<int> distBiggerNumber_FirstDown(4, 7);
		std::uniform_int_distribution<int> distBiggerNumber_SecondDown(2, 5);
		std::uniform_int_distribution<int> distBiggerNumber_ThirdDown(1, 3);

		int step = 0;
		while (ProcessFirst > 0) {

			if (ProcessFirst <= 1.0 / 12 * ControlProcessFirst) {
				step = distBiggerNumber_ThirdDown(gen);
			}
			else if (ProcessFirst <= 1.0 / 5 * ControlProcessFirst) {
				step = distBiggerNumber_SecondDown(gen);
			}
			else if (ProcessFirst <= 1.0 / 2 * ControlProcessFirst) {
				step = distBiggerNumber_FirstDown(gen);
			}
			else {
				step = distBiggerNumber_Default(gen);
			}

			if (step > ProcessFirst) step = ProcessFirst;

			ProcessFirst -= step;
			BiggerNumber.push_back(OriginalProcessFirst < 0 ? step *= -1 : step);
		}

		std::uniform_int_distribution<int> distSmallerNumber_Default(4, 6);
		std::uniform_int_distribution<int> distSmallerNumber_FirstDown(3, 4);
		std::uniform_int_distribution<int> distSmallerNumber_SecondDown(1, 2);
		std::uniform_int_distribution<int> distSmallerNumber_GenNull(1, 10);

		std::cout << (5.0 / 6) * ProcessSecond << " : " << (2.0 / 3) * ProcessSecond << endl;

		step = 0;
		while (ProcessSecond > 0) {

			if ((ProcessSecond <= (5.0 / 6) * ControlProcessSecond) && (ProcessSecond >= (2.0 / 3) * ControlProcessSecond)) {
				step = distSmallerNumber_FirstDown(gen);
			}
			else if (ProcessSecond <= (2.0 / 3) * ControlProcessSecond) {
				step = distSmallerNumber_SecondDown(gen);
			}
			else {
				step = distSmallerNumber_Default(gen);
			}

			if (step > ProcessSecond) step = ProcessSecond;

			ProcessSecond -= step;

			SmallerNumber.push_back(OriginalProcessSecond < 0 ? step *= -1 : step);
		}

		int div = BiggerNumber.size() - SmallerNumber.size();
		int Overhead = div / 5;
		int OverheadSplited = (Overhead / 2);

		while (Overhead > 0) {
			step = 1;

			if (step > Overhead) step = Overhead;

			Overhead -= step;

			if (OriginalProcessSecond < 0)
				step *= -1;

			if (Overhead < OverheadSplited)
				step *= -1;

			SmallerNumber.push_back(step);
		}

		div = BiggerNumber.size() - SmallerNumber.size();
		int zeroCount = div;

		int currentIndex = SmallerNumber.size() - 1;
		while (zeroCount > 0) {

			if (currentIndex < 0) {
				currentIndex = SmallerNumber.size() - 1;
				continue;
			}

			if (SmallerNumber[currentIndex] >= 3 || SmallerNumber[currentIndex] <= -3) {
				currentIndex = SmallerNumber.size() - 1;
				continue;
			}

			if (std::uniform_int_distribution<int>(1, 100)(gen) >= 40) {
				SmallerNumber.insert(SmallerNumber.begin() + currentIndex, 0);
				zeroCount--;
			}

			currentIndex--;
		}

		if (isXGreater) {
			if (BiggerNumber.size() == SmallerNumber.size()) {
				for (size_t i = 0; i < BiggerNumber.size(); ++i) {
					result.push_back(std::make_pair(BiggerNumber[i], SmallerNumber[i]));
				}
			}
		}
		else {
			if (BiggerNumber.size() == SmallerNumber.size()) {
				for (size_t i = 0; i < BiggerNumber.size(); ++i) {
					result.push_back(std::make_pair(SmallerNumber[i], BiggerNumber[i]));
				}
			}
		}

		return result;
	}


	std::vector<std::pair<int, int>> splitDistance(int x, int y) {
		std::vector<std::pair<int, int>> result;
		int initialX = x;
		int initialY = y;

		x = abs(x);
		y = abs(y);

		int progressTrackerX = x;
		int progressTrackerY = y;

		std::random_device rd;
		std::mt19937 gen(rd());
		std::uniform_int_distribution<int> distX_Default(6, 9);
		std::uniform_int_distribution<int> distY_Default(4, 6);

		std::uniform_int_distribution<int> distX_13(4, 7);
		std::uniform_int_distribution<int> distY_13(3, 4);

		std::uniform_int_distribution<int> distX_14(2, 5);
		std::uniform_int_distribution<int> distY_14(1, 2);
		std::uniform_int_distribution<int> distY_14_custom(1, 10); // Erhöhte Wahrscheinlichkeit für 1

		std::uniform_int_distribution<int> distX_15(1, 3);

		int stepX = 0;
		int stepY = 0;
		while (x > 0 || y > 0) {

			if (initialX > 100) {
				if (x <= 1.0 / 12 * progressTrackerX) {
					stepX = distX_15(gen);
				}
				else if (x <= 1.0 / 5 * progressTrackerX) {
					stepX = distX_14(gen);
				}
				else if (x <= 1.0 / 2 * progressTrackerX) {
					stepX = distX_13(gen);
				}
				else {
					stepX = distX_Default(gen);
				}
			}
			else {
				if (std::uniform_int_distribution<int>(1, 100)(gen) <= 20) {
					stepX = 0;
				}
				else {
					stepX = distX_15(gen);
				}
			}

			if (initialY < 80) {
				if (y <= 1.0 / 4 * progressTrackerY) {
					if (std::uniform_int_distribution<int>(1, 100)(gen) >= 30) {
						stepY = 0;
					}
					else {
						stepY = distY_14(gen);
					}
				}
				else if (y <= 1.0 / 2 * progressTrackerY) {
					stepY = distY_13(gen);
				}
				else {
					stepY = distY_Default(gen);
				}
			}
			else {
				if (initialX > 350) {
					if (std::uniform_int_distribution<int>(1, 100)(gen) >= (abs(initialY) - (abs(initialY) / 2))) {
						stepY = 0;
					}
					else {
						int randomValue = distY_14_custom(gen);
						stepY = (randomValue <= initialY > 60 ? 8 : 7) ? 1 : 2;
					}
				}
				else {
					if (std::uniform_int_distribution<int>(1, 100)(gen) >= 60) {
						stepY = 0;
					}
					else {
						stepY = distY_14(gen);
					}
				}
			}

			if (stepX > x) stepX = x;
			if (stepY > y) stepY = y;

			result.push_back(std::make_pair(stepX, stepY));

			x -= stepX;
			y -= stepY;
		}

		if (initialX < 0) {
			for (auto& step : result) {
				step.first *= -1;
			}
		}

		if (initialY < 0) {
			for (auto& step : result) {
				step.second *= -1;
			}
		}

		return result;
	}

}






/// 180 degree turn = ~1800 pixels
/// 90  degree turn = ~900  pixels
/// 45  degree turn = ~400  pixels

/// 90  degree up   = ~-800 pixels
/// 45  degree up   = ~-400 pixels


int main() {
	//c_log::add_out(new c_log::c_log_consolestream);

	const HWND hWND = GetMat::FindeWindow();
	SetForegroundWindow(hWND);
	Sleep(1000);//Delete later


	INPUT input[2];
	input[0].type = INPUT_KEYBOARD;
	input[0].ki.wVk = 'W'; // Hier die gewünschte Taste
	input[0].ki.dwFlags = 0;

	// SendInput für das Drücken von 'W'
	SendInput(1, &input[0], sizeof(INPUT));

	Sleep(1000);

	// Simuliere das Drücken der Shift-Taste
	input[1].type = INPUT_KEYBOARD;
	input[1].ki.wVk = VK_SHIFT; // Shift-Taste
	input[1].ki.dwFlags = 0;

	// SendInput für das Drücken der Shift-Taste
	SendInput(1, &input[1], sizeof(INPUT));
	
	// Warte eine Weile
	Sleep(10000); // Zum Beispiel 1 Sekunde


	// Setze die Flag auf true
	bool flag = true;

	// Simuliere das Loslassen der Shift-Taste
	input[1].ki.dwFlags = KEYEVENTF_KEYUP;

	// SendInput für das Loslassen der Shift-Taste
	SendInput(1, &input[1], sizeof(INPUT));


	// Warte eine Weile
	Sleep(500); // Zum Beispiel 1 Sekunde

	// Simuliere das Loslassen der W-Taste
	input[0].ki.dwFlags = KEYEVENTF_KEYUP;

	// SendInput für das Loslassen von 'W'
	SendInput(1, &input[0], sizeof(INPUT));



	//int endX = 900; // Endpunkt
	//int endY = -20;

	//std::vector<std::pair<int, int>> steps = Testing::makePath(endX, endY);
	//int currentX = 0, currentY = 0, count = 0;

	//for (const auto& step : steps) {
	//	currentX += step.first;
	//	currentY += step.second;
	//	count++;
	//	std::cout << "(" << step.first << ", " << step.second << ") -> Aktuelle Position: (" << currentX << ", " << currentY << ")" << std::endl;
	//}

	//std::cout << "Endpunkt erreicht: (" << currentX << ", " << currentY << ")\nPoints to Endpoint: " << count << std::endl;

	//for (const auto& step : steps) {
	//	Testing::moveMouse_testing(step.first, step.second);
	//	std::this_thread::sleep_for(std::chrono::nanoseconds(3700));
	//	//Sleep(0.999);
	//}
}