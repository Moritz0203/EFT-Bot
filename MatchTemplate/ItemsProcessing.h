#include <iostream>
#include <vector>
#include <conio.h>
#include <windows.h>
#include "StartUp.h"
using namespace std;
using namespace cv;


namespace ItemsProcessing {

	void AmmunitionProcess() {
		array<Mat, 11> ReturntMatScreen;

		StartUp::CheckScrollbarPositions();
		ReturntMatScreen = StartUp::TakeScreenshots();

		Matching::AmmunitionMatching(ReturntMatScreen);
		cleanVector::cleanUpVectorItems();
	}
}