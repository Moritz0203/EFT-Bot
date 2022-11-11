#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include <iostream>
using namespace std;
using namespace cv;


class Matching {
public:
	static int templateMatching(string filename, string templatename, double threshold) {
		const char* image_window = "Source Image";
		int match_method = 5;
		Mat result;

		Mat img = cv::imread(filename);
		Mat templ = cv::imread(templatename);
		if (img.empty() || templ.empty())
		{
			cout << "Error reading file(s) in templateMatching Funkion!" << endl;
			return 0;
		}
		namedWindow(image_window, WINDOW_AUTOSIZE);


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
			if (maxVal >= threshold)
			{
				cv::rectangle(img_display, matchLoc, Point(matchLoc.x + templ.cols, matchLoc.y + templ.rows), CV_RGB(0, 255, 0), 1);;
				floodFill(result, matchLoc, 0); //mark drawn blob
			}
			else
				break;
		}
		cv::imshow(image_window, img_display);

		waitKey(0);
		return matchLoc, templ.cols, templ.rows;
	}
};

