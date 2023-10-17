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
	Left = 0,
	Right = 1,
	HalfLeft = 2,
	HalfRight = 3,
	TurnAround = 4,

	NoRotationX = 10,
}RotationX;

typedef enum e_rotation_y {
	Up = 0,
	Down = 1,
	HalfUp = 2,
	HalfDown = 3,

	NoRotationY = 10,
	AutoRotation = 20,
}RotationY;

class HumanizedMouse
{
   


public:
	
	void MoveToExactPoint(int x, int y, uint speedIn_NS) {

	}

	void MoveViaRotation(float xRotation, float yRotation, uint speedIn_NS) {

	}

	void MoveToDirection(RotationX rotationX = NoRotationX, RotationY rotationY = AutoRotation, uint speedIn_NS = 900) {

	}
};


typedef enum e_direction {
	Forward = 0,
	Backwards = 1,

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






void moveMouse(int x, int y) {
    INPUT input;
    input.type = INPUT_MOUSE;
    input.mi.dwFlags = MOUSEEVENTF_MOVE;
    input.mi.dx = x;
    input.mi.dy = y;
    input.mi.mouseData = 0;
    input.mi.time = 0;
    input.mi.dwExtraInfo = 0;

	cout << "x: " << x << " y: " << y << endl;

    SendInput(1, &input, sizeof(INPUT));
}








int main() {
	//c_log::add_out(new c_log::c_log_consolestream);


	const HWND hWND = GetMat::FindeWindow();
	SetForegroundWindow(hWND);
	Sleep(1000);//Delete later

	while (true)
	{
		moveMouse(1, 0);
		Sleep(1);
	}


}