#include "Includes.h"
#include "DistributorForMatching.h"
#include "InputMT.h"
#include "getMat.h"
//external controllers for applications / ECFA
void startFunktion(vector<POINT> Returner);


int main() {

	vector<POINT> Returner;
	
	string Start;
	cin >> Start;


	if (Start == "start") {
		startFunktion(Returner);
	}
	else if (Start == "test") {
		const char* image_window = "Source Image";
		namedWindow(image_window, WINDOW_AUTOSIZE);
	
		HWND hWND = FindeWindow();
		SetForegroundWindow(hWND);
		Mat img = getMat(hWND);
		Mat img_display;
		img.copyTo(img_display);
		imshow(image_window, img);
		waitKey(0);
	}

	/*for (int i = 0; i < Returner.size(); i++) {
			cout << Returner[i].y << " " << Returner[i].x << endl;
	}*/

	/*Mouse::Mover(Returner);*/
}

void startFunktion(vector<POINT> Returner) {
	Mat Screen;
	Returner = Matching::AmmunitionMatching(Screen);
}