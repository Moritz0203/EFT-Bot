#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include <iostream>
using namespace std;
using namespace cv;

Mat result;
const char* image_window = "Source Image";
const char* result_window = "Result window";
int match_method = 5;
void MatchingMethod(int, void*, Mat img, Mat templ);


int main(string templatename, string filename, const char** argv) {
	Mat img = cv::imread(filename + ".jpg");
	Mat templ = cv::imread(templatename + ".jpg");
	if (img.empty() || templ.empty())
	{
		cout << "Error reading file(s)!" << endl;
		return -1;
	}

	/*img = imread("C:/Users/morit/OneDrive/Desktop/EFT-Sort-Bot/stashscreen1.png", IMREAD_COLOR);
	templ = imread("C:/Users/morit/OneDrive/Desktop/EFT-Sort-Bot/BP.png", IMREAD_COLOR);*/

	namedWindow(image_window, WINDOW_AUTOSIZE);
	MatchingMethod(0, 0, img, templ);

	waitKey(0);
	return EXIT_SUCCESS;
}

void MatchingMethod(int, void*, Mat img, Mat templ) {
	Mat img_display;
	img.copyTo(img_display);

	matchTemplate(img, templ, result, match_method);

	double minVal; double maxVal; Point minLoc; Point maxLoc;
	Point matchLoc;

	while (true)
	{
		minMaxLoc(result, &minVal, &maxVal, &minLoc, &maxLoc, Mat());

		matchLoc = minLoc;
		matchLoc = maxLoc;
		if (maxVal >= 0.74)
		{
			cv::rectangle(img_display, maxLoc, Point(maxLoc.x + templ.cols, maxLoc.y + templ.rows), CV_RGB(0, 255, 0), 1);;
			floodFill(result, matchLoc, 0); //mark drawn blob
		}
		else
			break;
	}

	//Nato60 = 0.74
	//BT = 0.74
	//BP = 0.74

	cv::imshow(image_window, img_display);

	return;
}