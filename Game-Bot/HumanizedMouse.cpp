#include "HumanizedMouse.h"

#include <Windows.h>
#include <random>
#include <thread>
//#include <iostream>

//Random Number Generator
int HumanizedMouse::Random(int lowerBound, int upperBound) {
	std::random_device rd;
	std::uniform_int_distribution<int> distribution(lowerBound, upperBound);
	std::mt19937 engine(rd()); // Mersenne twister MT19937
	int value = distribution(engine);
	return value;
}

//Standard mouse move function via SendInput
void HumanizedMouse::MouseMoveInternal(float x, float y) {
	double fScreenWidth = ::GetSystemMetrics(SM_CXSCREEN);
	double fScreenHeight = ::GetSystemMetrics(SM_CYSCREEN);
	double fx = x * (65535.0f / fScreenWidth);
	double fy = y * (65535.0f / fScreenHeight);

	INPUT  Input = { 0 };
	Input.type = INPUT_MOUSE;
	Input.mi.dwFlags = MOUSEEVENTF_MOVE | MOUSEEVENTF_ABSOLUTE;
	Input.mi.dx = (long)fx;
	Input.mi.dy = (long)fy;
	::SendInput(1, &Input, sizeof(INPUT));
}

void HumanizedMouse::MoveMouse(int x, int y) {
    // Accuracy to desired pixel
    int Acc = 8;

    int targetX = x + (int)(Acc * targetDistribution.NextGaussian());
    int targetY = y + (int)(Acc * targetDistribution.NextGaussian());

    // Declare the original pointer position
    POINT p;
    GetCursorPos(&p);
    int originalX = (int)p.x;
    int originalY = (int)p.y;

    // Find a mid point between the original and target position
    int midPointX = (x - targetX) / 2;
    int midPointY = (y - targetY) / 2;

    // Points normal to the straight line between start and end point
    int factor = 6;
    int bezierMidPointX = (int)((midPointX / factor) * (midpointDistribution.NextGaussian()));
    int bezierMidPointY = (int)((midPointY / factor) * (midpointDistribution.NextGaussian()));

    BezierCurve bc;
    double input[] = { originalX, originalY, bezierMidPointX, bezierMidPointY, targetX, targetY };

    // Change numberOfPoints for more or fewer control points
    const int numberOfPoints = 700;

    // Don't change numberOfDataPoints
    const int numberOfDataPoints = numberOfPoints * 2;
    double* output = new double[numberOfDataPoints]; // Allocate on the heap

    // Control points are couples of two, so divide by 2
    bc.Bezier2D(input, numberOfDataPoints / 2, output);

    int initialDelay = 1000; // Initial delay in nanoseconds
    int maxDelay = 1700;   // Maximum delay in nanoseconds

    for (int count = 1; count != numberOfDataPoints - 1; count += 2) {
        POINT A;
        A.x = (int)output[count + 1];
        A.y = (int)output[count];

        MouseMoveInternal((float)A.x, (float)A.y);

        // Incremental delay adjustment
        int currentDelay = initialDelay + (count / 2) * (maxDelay - initialDelay) / (numberOfDataPoints / 2);
        std::this_thread::sleep_for(std::chrono::nanoseconds(currentDelay));
    }

    delete[] output; // Don't forget to free the memory when done
}



void HumanizedMouse::MoveMouseInGame(int xOffset, int yOffset, int initialDelay_NS, int Accuracy) {
    //Accuracy to desired pixel
    int Acc = Accuracy; // 8 
    const int screenWidth = 1920;
    const int screenHeight = 1080;

    int originalX = screenWidth / 2;
    int originalY = screenHeight / 2;

    int targetX = (originalX + xOffset) + (int)(Acc * targetDistribution.NextGaussian());
    int targetY = (originalY + yOffset) + (int)(Acc * targetDistribution.NextGaussian());

    POINT p;
    GetCursorPos(&p);
     originalX = (int)p.x;
     originalY = (int)p.y;

    // Find a mid point between the original and target position
    int midPointX = ((originalX + xOffset) - targetX) / 2;
    int midPointY = ((originalY + yOffset) - targetY) / 2;

    // Points normal to the straight line between start and end point
    int factor = 6;
    int bezierMidPointX = (int)((midPointX / factor) * (midpointDistribution.NextGaussian()));
    int bezierMidPointY = (int)((midPointY / factor) * (midpointDistribution.NextGaussian()));

    BezierCurve bc;
    double input[] = { originalX, originalY, bezierMidPointX, bezierMidPointY, targetX, targetY };

    // Change numberOfPoints for more or fewer control points
    const int numberOfPoints = 700;

    // Don't change numberOfDataPoints
    const int numberOfDataPoints = numberOfPoints * 2;
    double* output = new double[numberOfDataPoints]; // Allocate on the heap

    // Control points are couples of two, so divide by 2
    bc.Bezier2D(input, numberOfDataPoints / 2, output);

    int initialDelay = initialDelay_NS; // Initial delay in nanoseconds
    int maxDelay = 1700;   // Maximum delay in nanoseconds

    for (int count = 1; count != numberOfDataPoints - 1; count += 2) {
        POINT A;
        A.x = (int)output[count + 1];
        A.y = (int)output[count];

        MouseMoveInternal((float)A.x, (float)A.y);

        // Incremental delay adjustment
        int currentDelay = initialDelay + (count / 2) * (maxDelay - initialDelay) / (numberOfDataPoints / 2);
        std::this_thread::sleep_for(std::chrono::nanoseconds(currentDelay));
    }

    delete[] output; // Don't forget to free the memory when done
}
