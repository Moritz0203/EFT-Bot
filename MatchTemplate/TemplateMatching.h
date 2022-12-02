#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include <iostream>
#include <vector>
#include <conio.h>
#include <windows.h>
using namespace std;
using namespace cv;

class TemplateMatching {
public:
	static inline int templateMatchingItems(string filename, string templatename, double threshold, bool MabyHasInsurance, bool RoiNeed, 
									   string NameOfItem, vector<POINT> &ReturnData, Mat MatScreen)
	{
		int height = {}, width = {};
		const char* image_window = "Source Image";
		const char* Test = "Item Image";
		int match_method = 5;
		Mat result;
		Mat img;

		img = cv::imread(filename);

		if (!MatScreen.empty()) {
			img = MatScreen;
		}
	
	 	Mat templ = cv::imread(templatename);
		if (img.empty() || templ.empty())
		{
			cout << "Error reading file(s) in templateMatching Funkion!" << endl;
			return false;
		}
		namedWindow(image_window, WINDOW_AUTOSIZE);
		namedWindow(Test, WINDOW_AUTOSIZE);


		Mat img_display;
		img.copyTo(img_display);

		int StartY = 0, StartX = 0;
		if (MabyHasInsurance == true) {
			StartY = 2; StartX = 2;
			width = templ.cols - 4;
			height = templ.rows - 35;
		}	
		else if(RoiNeed == true) {
			width = templ.cols - 1;
			height = templ.rows - 20; 
		}
		else {
			width = templ.cols - 0;
			height = templ.rows - 0;
		}
			
		Rect Rec(StartY, StartX, width, height);
		Mat Roi = templ(Rec);
		imshow(Test, Roi);

		matchTemplate(img, Roi, result, match_method);
		double minVal; double maxVal; Point minLoc; Point maxLoc;
		Point matchLoc;

		int count = 0;
		POINT PointReturn;
		cout << NameOfItem << endl;
		while (true)
		{
			minMaxLoc(result, &minVal, &maxVal, &minLoc, &maxLoc, Mat());
			if (maxVal >= threshold)
			{
				matchLoc = maxLoc;
				cv::rectangle(img_display, matchLoc, Point(matchLoc.x + templ.cols, matchLoc.y + templ.rows), CV_RGB(0, 255, 0), 1);
				/*cv::line(img_display, matchLoc, Point(0 , 0), CV_RGB(0, 255, 0), 1);*/
				cv::line(img_display, Point(matchLoc.x + templ.cols / 2, matchLoc.y), Point(img.cols / 2, 0), CV_RGB(0, 255, 0), 1);
				floodFill(result, matchLoc, 0); //mark drawn blob
				if (matchLoc.y && matchLoc.x != 0) {
					cout << matchLoc.y << " " << matchLoc.x << " " << templ.cols << " " << templ.rows << " " << endl;
					PointReturn.y = matchLoc.y;
					PointReturn.x = matchLoc.x;
					ReturnData.push_back(PointReturn);
					count++;
				}
				else 
					return false;
			}
			else
				break;
		}
		cout << count << endl;
		cv::imshow(image_window, img_display);

		waitKey(0);
		return templ.cols, templ.rows;
	}


	static POINT templateMatchingObjects(Mat MatScreen, Mat templ, double threshold) {
		int height = {}, width = {};
		const char* image_window = "Source Image";
		const char* Test = "Item Image";
		int match_method = 5;
		Mat result;
		POINT PointReturn = {};

		/*if (MatScreen.empty() || templ.empty())
		{
			cout << "Error reading file(s) in templateMatching Funkion!" << endl;
		}*/
		namedWindow(image_window, WINDOW_AUTOSIZE);
		/*namedWindow(Test, WINDOW_AUTOSIZE);*/
		
		Mat img_display;
		MatScreen.copyTo(img_display);

		//imshow(Test, templ);

		matchTemplate(MatScreen, templ, result, match_method);
		double minVal; double maxVal; Point minLoc; Point maxLoc;
		Point matchLoc;

		while (true)
		{
			minMaxLoc(result, &minVal, &maxVal, &minLoc, &maxLoc, Mat());
			if (maxVal >= threshold)
			{
				matchLoc = maxLoc;
				cv::rectangle(img_display, matchLoc, Point(matchLoc.x + templ.cols, matchLoc.y + templ.rows), CV_RGB(0, 255, 0), 1);
				cv::line(img_display, matchLoc, Point(0 , 0), CV_RGB(0, 255, 0), 1);
				/*cv::line(img_display, Point(matchLoc.x + templ.cols / 2, matchLoc.y), Point(MatScreen.cols / 2, 0), CV_RGB(0, 255, 0), 1);*/
				floodFill(result, matchLoc, 0); //mark drawn blob
				if (matchLoc.y && matchLoc.x != 0) {
					cout << matchLoc.y << " " << matchLoc.x << " " << templ.cols << " " << templ.rows << " " << endl;
					PointReturn.y = matchLoc.y;
					PointReturn.x = matchLoc.x;
				}
			}
			else
				break;
		}
		cv::imshow(image_window, img_display);

		waitKey(0);

		return PointReturn;
	}
};