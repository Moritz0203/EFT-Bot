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
#include "HumanizedMouse.h"

#define M_PI 3.14159265358979323846


// HighCard | High T
// SecurityCheck Items Barter / Medical / Food 


//void MouseMoving(int xOffset, int yOffset, int durationMs) {
//    const int steps = 20;
//    const int sleepMs = durationMs / steps;
//
//    // Maximale Abweichung vom Bogen
//    int maxDeviation = 50;
//
//    // Erzeuge einen Zufallszahlengenerator für die Bogenbewegung
//    std::random_device rd;
//    std::mt19937 gen(rd());
//    std::uniform_real_distribution<double> angleDist(-0.2, 0.2); // Kleine Winkelabweichung
//
//    // Easing-Funktion: Verwendet eine kubische Interpolation rückwärts (1 - (1-t)^3) für Geschwindigkeitsänderung
//    auto ease = [](double t) { return 1.0 - pow(1.0 - t, 3); };
//
//    // Berechne Schritte in x und y Richtung
//    double xStep = static_cast<double>(xOffset) / steps;
//    double yStep = static_cast<double>(yOffset) / steps;
//
//    // Mausbewegung mit allmählicher Krümmung und Easing
//    for (int step = 1; step <= steps; ++step) {
//        double t = static_cast<double>(step) / steps;
//
//        // Anwendung der Easing-Funktion auf t
//        t = ease(t);
//
//        // Allmähliche Krümmung der Bewegung
//        double curveFactor = sin(t * M_PI / 2);  // Von 0 bis 1 in Form eines Sinus
//
//        // Zufälliger Winkel entlang des Bogens
//        double angle = angleDist(gen);
//
//        // Anpasse der x- und y-Koordinaten für die Krümmung
//        double curvedX = xStep * t;
//        double curvedY = yStep * t * curveFactor;
//
//        mouse_event(MOUSEEVENTF_MOVE, (DWORD)curvedX, (DWORD)curvedY, 0, 0);
//        Sleep(sleepMs); // Pausiere für eine kurze Zeit zwischen den Schritten
//    }
//}







int main() {
	c_log::add_out(new c_log::c_log_consolestream);



	const HWND hWND = GetMat::FindeWindow();
	SetForegroundWindow(hWND);
	Sleep(100);//Delete later
    
    /*POINT originalPos;
    GetCursorPos(&originalPos);

    cout << originalPos.x << " " << originalPos.y << endl;  

    MouseMoving(500, 0, 100);

    GetCursorPos(&originalPos);

    cout << originalPos.x << " " << originalPos.y << endl;*/


    HumanizedMouse mouse;
    while (!GetAsyncKeyState(VK_F4))
    {
        
        mouse.MoveMouseInGame(300, 0, 990, 8);

        Sleep(1000);
    }


    //HumanMouse mouse;

    //mouse.SetTarget(1000, 700);
    //mouse.Start();

    //while (!(GetKeyState(VK_F4) & 0x8000))
    //{
    //   
    //}

    //mouse.Stop();
}