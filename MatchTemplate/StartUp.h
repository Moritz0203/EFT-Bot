#include "Includes.h"
#include "DistributorForMatching.h"
#include "getMat.h"

namespace StartUp {
	void Entrance() {
		HWND hWND = FindeWindow();
		SetForegroundWindow(hWND);
		Mat MatScreen = getMat(hWND);

		const char* image_window = "Source Image";
		namedWindow(image_window, WINDOW_AUTOSIZE);
		Mat templ = imread("ObjectImages/scrollbar.png");

		POINT point = TemplateMatching::templateMatchingObjects(MatScreen, templ, 0.70);

	}


	void CheckForFails() {

	}
}


