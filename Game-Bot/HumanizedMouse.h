#pragma once
#include <random>
#include "Windows.h"

typedef enum e_rotation_x {
	LeftX = -900,
	RightX = 900,
	HalfLeft = -400,
	HalfRight = 400,

	TurnAround = 1,
	AutoRotationX = 2,
}RotationX;

typedef enum e_rotation_y {
	Up = -800,
	Down = 800,
	HalfUp = -400,
	HalfDown = 400,

	AutoRotationY = 1,
}RotationY;

class HumanizedMouse
{
	void moveMouse(int x, int y) {
		INPUT input;
		input.type = INPUT_MOUSE;
		input.mi.dwFlags = MOUSEEVENTF_MOVE;
		input.mi.dx = x;
		input.mi.dy = y;
		input.mi.mouseData = 0;
		input.mi.time = 0;
		input.mi.dwExtraInfo = 0;

		SendInput(1, &input, sizeof(INPUT));
	}

	bool shouldAddPrefix() {
		std::srand(static_cast<unsigned>(std::time(0)));
		return (std::rand() % 2 == 0);
	}

	int getRandomValueForAutoRotation(int lower, int uper) {
		std::random_device rd;
		std::mt19937 gen(rd());
		std::uniform_int_distribution<int> distribution(lower, uper);

		return distribution(gen);
	}

	bool isXGreaterThanY(int x, int y) {
		return x > y;
	}


	std::vector<std::pair<int, int>> makePath(int x, int y);

public:

	void MoveViaRotation(float xRotation, float yRotation, UINT speedIn_NS) { }

	void MoveToExactPoint(int x, int y, UINT speedIn_NS); // Only for Small Movements
	void MoveToDirection(RotationX rotationX = AutoRotationX, RotationY rotationY = AutoRotationY, UINT speedIn_NS = 900);
};