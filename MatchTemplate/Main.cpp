#include "Includes.h"
#include "DistributorForMatching.h"
#include "getMat.h"
//external controllers for applications / ECFA
void startFunktion(vector<POINT> &Returner, Mat MatScreen);


int main() {

	vector<POINT> Returner;
	
	
	HWND hWND = FindeWindow();
	SetForegroundWindow(hWND);
	Mat MatScreen = getMat(hWND);
	

	string Start;
	cin >> Start;

	if (Start == "start") {
		startFunktion(Returner, MatScreen);
	}
	else if (Start == "test") {
		const char* image_window = "Source Image";
		namedWindow(image_window, WINDOW_AUTOSIZE);
		Mat templ = imread("ObjectImages/scrollbar.png");
	
		POINT point = TemplateMatching::templateMatchingObjects(MatScreen, templ, 0.70);
		
		cout << point.y << " " << point.x << endl;

		
		/*Mat img_display;
		img.copyTo(img_display);
		imshow(image_window, img);
		waitKey(0);*/
	}

	//for (int i = 0; i < Returner.size(); i++) {
	//		cout << Returner[i].y << " " << Returner[i].x << endl;
	//}
}

void startFunktion(vector<POINT> &Returner, Mat MatScreen) {
	Returner = Matching::AmmunitionMatching(MatScreen);
}