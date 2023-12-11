#pragma once
#include "Includes.h"
using namespace std;

struct GetMat {
	static cv::Mat getMat(HWND hWND);
	static cv::Mat getMatWithRect(HWND hWND, POINT pointStart, int width, int height);

	void TakeScreenshots(int Screens);

	static HWND FindeWindow();

	__forceinline const std::vector<cv::Mat>& GetMatVector() { return MatScreenVector; }
private:
	static std::vector<cv::Mat> MatScreenVector;
};

