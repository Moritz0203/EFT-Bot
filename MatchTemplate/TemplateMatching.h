#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include <iostream>
using namespace std;
using namespace cv;


class Matching {
public:
	static int templateMatching(string filename, string templatename, double threshold, int height, string NameOfItem) {
		const char* image_window = "Source Image";
		const char* Test = "Item Image";
		int match_method = 5;
		Mat result;

		Mat img = cv::imread(filename);
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

		int width = templ.rows -1;
		Rect Rec(0, 0, width, height);
		Mat Roi = templ(Rec);
		imshow(Test, Roi);

		matchTemplate(img, Roi, result, match_method);
		double minVal; double maxVal; Point minLoc; Point maxLoc;
		Point matchLoc;

		cout << NameOfItem << endl;

		while (true)
		{
			minMaxLoc(result, &minVal, &maxVal, &minLoc, &maxLoc, Mat());
			if (maxVal >= threshold)
			{
				matchLoc = maxLoc;
				cv::rectangle(img_display, matchLoc, Point(matchLoc.x + templ.cols, matchLoc.y + templ.rows), CV_RGB(0, 255, 0), 2);
				/*cv::line(img_display, matchLoc, Point(0 , 0), CV_RGB(0, 255, 0), 1);*/
				cv::line(img_display, Point(matchLoc.x + templ.cols / 2, matchLoc.y), Point(img.cols / 2, 0), CV_RGB(0, 255, 0), 1);
				floodFill(result, matchLoc, 0); //mark drawn blob
				cout << matchLoc.y << " " << matchLoc.x << " " << templ.cols << " " << templ.rows << " " << endl;
			}
			else
				break;
		}
		cv::imshow(image_window, img_display);

		
		waitKey(600);
		return matchLoc.y, matchLoc.x, templ.cols, templ.rows;
	}
};

