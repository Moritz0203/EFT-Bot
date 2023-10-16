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



void MouseMoving(int xOffset, int yOffset, int durationMs) {
    const int steps = 20;
    const int sleepMs = durationMs / steps;

    // Maximale Abweichung vom Bogen
    int maxDeviation = 50;

    // Erzeuge einen Zufallszahlengenerator für die Bogenbewegung
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<double> angleDist(-0.2, 0.2); // Kleine Winkelabweichung

    // Easing-Funktion: Verwendet eine kubische Interpolation rückwärts (1 - (1-t)^3) für Geschwindigkeitsänderung
    auto ease = [](double t) { return 1.0 - pow(1.0 - t, 3); };

    // Berechne Schritte in x und y Richtung
    double xStep = static_cast<double>(xOffset) / steps;
    double yStep = static_cast<double>(yOffset) / steps;

    // Mausbewegung mit allmählicher Krümmung und Easing
    for (int step = 1; step <= steps; ++step) {
        double t = static_cast<double>(step) / steps;

        // Anwendung der Easing-Funktion auf t
        t = ease(t);

        // Allmähliche Krümmung der Bewegung
        double curveFactor = sin(t * M_PI / 2);  // Von 0 bis 1 in Form eines Sinus

        // Zufälliger Winkel entlang des Bogens
        double angle = angleDist(gen);

        // Anpasse der x- und y-Koordinaten für die Krümmung
        double curvedX = xStep * t;
        double curvedY = yStep * t * curveFactor;

        //mouse_event(MOUSEEVENTF_MOVE, (DWORD)curvedX, (DWORD)curvedY, 0, 0);
		//SetPosition(curvedX, curvedY);

		Sleep(sleepMs); // Pausiere für eine kurze Zeit zwischen den Schritten
    }
}


void SetPosition(std::int32_t x, std::int32_t y)
{
	mouse_event(MOUSEEVENTF_MOVE, (DWORD)x, (DWORD)y, 0, 0);
}

//void SetPosition(std::int32_t x, std::int32_t y)
//{
//	SetCursorPos(x, y);
//}









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