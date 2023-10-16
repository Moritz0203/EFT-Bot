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




class HumanizedMouse
{

public:
	
	void MoveToExactPoint(int x, int y, uint speedIn_NS) {

	}

	void MoveToDirection(float xRotation, float yRotation, uint speedIn_NS) {

	}
};


typedef enum e_direction {
	Forward = 0,
	Backwards = 1,

	NoDirection = 10,
}Direction;

typedef enum e_rotation {
	Left = 0,
	Right = 1,
	HalfLeft = 2,
	HalfRight = 3,
	TurnAround = 4,

	NoRotation = 10,
}Rotation;

class HumanizedKeyboard
{

public:

	void MoveToExactPosition() {

	}

	void MoveToDirection(Direction direction = NoDirection, Rotation rotation = NoRotation, uint speedIn_NS = 900) {

	}
};









int main() {
	c_log::add_out(new c_log::c_log_consolestream);










	//const HWND hWND = GetMat::FindeWindow();
	//SetForegroundWindow(hWND);
	//Sleep(1000);//Delete later

	/*const int screenWidth = 1920;
    const int screenHeight = 1080;

    int originalX = screenWidth / 2;
    int originalY = screenHeight / 2;



	int x = originalX;
	int stopX = originalX + 10;
	while (true)
	{
		if(x > stopX)
			break;

		SetPosition(x++, 540);
		Sleep(10);
	}*/






	/*POINT originalPos;
	GetCursorPos(&originalPos);

	cout << originalPos.x << " " << originalPos.y << endl;

	MouseMoving(500, 0, 100);

	GetCursorPos(&originalPos);

	cout << originalPos.x << " " << originalPos.y << endl;*/

	/*const int screenWidth = 1920;
	const int screenHeight = 1080;

	int originalX = screenWidth / 2;
	int originalY = screenHeight / 2;

	HumanizedMouse mouse;
	while (!GetAsyncKeyState(VK_F4))
	{

		mouse.MoveMouseInGame(500, 0, 990, 8);

		Sleep(1000);
	}*/

	/*	POINT point;
	while (true)
	{
		GetCursorPos(&point);

		cout << point.x << " " << point.y << endl;

	}*/

	//const int screenWidth = 1920;
	//const int screenHeight = 1080;

	//int originalX = screenWidth / 2;
	//int originalY = screenHeight / 2;
	//
	//
	///*while (true)
	//{
	//	while (GetAsyncKeyState(VK_F4))
	//	{
	//	}
	//}*/
	//
	//RealisticMoveImpl(1500, 200, 2000);

	//RealisticMoveImpl(500, 200, 2000);






 //   HumanMouse mouse;

 //   mouse.Start_Normal();
 //   mouse.SetGravity(2);

 //   //const int screenWidth = 1920;
 //   //const int screenHeight = 1080;

 //   //int originalX = screenWidth / 2;
 //   //int originalY = screenHeight / 2;

	//POINT point;

 //   while (!(GetAsyncKeyState(VK_F4) & 0x8000))
 //   {
	//	mouse.SetTarget(1000, 540);

	//	GetCursorPos(&point);

	//	cout << point.x << " " << point.y << endl;
 //   }

 //   mouse.Stop();
	//int test = 500;
	//while (true)
	//{
	//	SetPosition(test++, 540);

	//}

}