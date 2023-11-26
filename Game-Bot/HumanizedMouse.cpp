#include "HumanizedMouse.h"
#include <thread>
#include <iostream>

std::vector<std::pair<int, int>> HumanizedMouse::makePath(int x, int y) {
	std::vector<std::pair<int, int>> result;
	std::vector<int> BiggerNumber;
	std::vector<int> SmallerNumber;

	int ProcessFirst = 0;
	int ControlProcessFirst = 0;
	int OriginalProcessFirst = 0;
	int ProcessSecond = 0;
	int ControlProcessSecond = 0;
	int OriginalProcessSecond = 0;

	bool isXGreater = isXGreaterThanY(abs(x), abs(y));
	std::random_device rd;
	std::mt19937 gen(rd());

	if (isXGreater) {
		ProcessFirst = abs(x);
		ControlProcessFirst = abs(x);
		OriginalProcessFirst = x;
		ProcessSecond = abs(y);
		ControlProcessSecond = abs(y);
		OriginalProcessSecond = y;
	}
	else {
		ProcessFirst = abs(y);
		ControlProcessFirst = abs(y);
		OriginalProcessFirst = y;
		ProcessSecond = abs(x);
		ControlProcessSecond = abs(x);
		OriginalProcessSecond = x;
	}

	std::uniform_int_distribution<int> distBiggerNumber_Default(6, 9);
	std::uniform_int_distribution<int> distBiggerNumber_FirstDown(4, 7);
	std::uniform_int_distribution<int> distBiggerNumber_SecondDown(2, 5);
	std::uniform_int_distribution<int> distBiggerNumber_ThirdDown(1, 3);

	int step = 0;
	while (ProcessFirst > 0) {

		if (ProcessFirst <= 1.0 / 12 * ControlProcessFirst) {
			step = distBiggerNumber_ThirdDown(gen);
		}
		else if (ProcessFirst <= 1.0 / 4 * ControlProcessFirst) {
			step = distBiggerNumber_SecondDown(gen);
		}
		else if (ProcessFirst <= 1.0 / 2 * ControlProcessFirst) {
			step = distBiggerNumber_FirstDown(gen);
		}
		else {
			step = distBiggerNumber_Default(gen);
		}

		if (step > ProcessFirst) step = ProcessFirst;

		ProcessFirst -= step;
		BiggerNumber.push_back(OriginalProcessFirst < 0 ? step *= -1 : step);
	}

	std::uniform_int_distribution<int> distSmallerNumber_Default(4, 6);
	std::uniform_int_distribution<int> distSmallerNumber_FirstDown(3, 4);
	std::uniform_int_distribution<int> distSmallerNumber_SecondDown(1, 2);
	std::uniform_int_distribution<int> distSmallerNumber_GenNull(1, 10);

	step = 0;
	while (ProcessSecond > 0) {

		if ((ProcessSecond <= (5.0 / 6) * ControlProcessSecond) && (ProcessSecond >= (2.0 / 3) * ControlProcessSecond)) {
			step = distSmallerNumber_FirstDown(gen);
		}
		else if (ProcessSecond <= (2.0 / 3) * ControlProcessSecond) {
			step = distSmallerNumber_SecondDown(gen);
		}
		else {
			step = distSmallerNumber_Default(gen);
		}

		if (step > ProcessSecond) step = ProcessSecond;

		ProcessSecond -= step;

		SmallerNumber.push_back(OriginalProcessSecond < 0 ? step *= -1 : step);
	}


	/// Block if BiggerNumber.size() < SmallerNumber.size()
	if (BiggerNumber.size() < SmallerNumber.size()) {
		SmallerNumber.clear();
		ProcessSecond = ControlProcessSecond;

		while (ProcessSecond > 0) {

			if (ProcessSecond <= 1.0 / 8 * ControlProcessSecond) {
				step = distBiggerNumber_ThirdDown(gen);
			}
			else if (ProcessSecond <= 1.0 / 4 * ControlProcessSecond) {
				step = distBiggerNumber_SecondDown(gen);
			}
			else if (ProcessSecond <= 1.0 / 2 * ControlProcessSecond) {
				step = distBiggerNumber_FirstDown(gen);
			}
			else {
				step = distBiggerNumber_Default(gen);
			}

			if (step > ProcessSecond) step = ProcessSecond;

			ProcessSecond -= step;
			SmallerNumber.push_back(ControlProcessSecond < 0 ? step *= -1 : step);
		}

		int div = BiggerNumber.size() - SmallerNumber.size();
		int Overhead = div / 5;
		int OverheadSplited = (Overhead / 2);

		//cout << "Overhead: " << Overhead << endl;

		while (Overhead > 0) {
			step = 1;

			if (step > Overhead) step = Overhead;

			Overhead -= step;

			if (OriginalProcessSecond < 0)
				step *= -1;

			if (Overhead < OverheadSplited)
				step *= -1;

			SmallerNumber.push_back(step);
		}

		div = BiggerNumber.size() - SmallerNumber.size();
		int zeroCount = div;

		//cout << "div: " << div << endl;
		//cout << "zeroCount: " << zeroCount << endl;

		//for (int i : SmallerNumber)
		//	cout << i << endl;

		int currentIndex = SmallerNumber.size() - 1;
		if (currentIndex == 0) {
			for (int i = 0; i < zeroCount; i++) {
				SmallerNumber.push_back(0);
			}
		}
		else {
			int failSave = 400;
			while (zeroCount > 0) {
				//cout << "currentIndex: " << currentIndex << endl;

				if (failSave == 0)
					break;

				if (currentIndex < 0) {
					failSave--;
					currentIndex = SmallerNumber.size() - 1;
					continue;
				}

				if (SmallerNumber[currentIndex] > 6 || SmallerNumber[currentIndex] < -6) {
					failSave--;
					currentIndex = SmallerNumber.size() - 1;
					continue;
				}

				if (std::uniform_int_distribution<int>(1, 100)(gen) >= 40) {
					failSave = 400;
					SmallerNumber.insert(SmallerNumber.begin() + currentIndex, 0);
					zeroCount--;
				}

				currentIndex--;
			}
		}

	}
	else {
		int div = BiggerNumber.size() - SmallerNumber.size();
		int Overhead = div / 5;
		int OverheadSplited = (Overhead / 2);

		//cout << "Overhead: " << Overhead << endl;

		while (Overhead > 0) {
			step = 1;

			if (step > Overhead) step = Overhead;

			Overhead -= step;

			if (OriginalProcessSecond < 0)
				step *= -1;

			if (Overhead < OverheadSplited)
				step *= -1;

			SmallerNumber.push_back(step);
		}

		div = BiggerNumber.size() - SmallerNumber.size();
		int zeroCount = div;

		int currentIndex = SmallerNumber.size() - 1;
		if (currentIndex == 0) {
			for (int i = 0; i < zeroCount; i++) {
				SmallerNumber.push_back(0);
			}
		}
		else {
			while (zeroCount > 0) {
				//cout << "currentIndex: " << currentIndex << endl;

				if (currentIndex < 0) {
					currentIndex = SmallerNumber.size() - 1;
					continue;
				}

				if (SmallerNumber[currentIndex] >= 3 || SmallerNumber[currentIndex] <= -3) {
					currentIndex = SmallerNumber.size() - 1;
					continue;
				}

				if (std::uniform_int_distribution<int>(1, 100)(gen) >= 40) {
					SmallerNumber.insert(SmallerNumber.begin() + currentIndex, 0);
					zeroCount--;
				}

				currentIndex--;
			}
		}
	}

	//cout << BiggerNumber.size() << " : " << SmallerNumber.size() << endl;

	if (BiggerNumber.size() < SmallerNumber.size()) {
		int div = SmallerNumber.size() - BiggerNumber.size();

		for (int i = 0; i < div; i++) {
			BiggerNumber.push_back(0);
		}
	}
	else if (BiggerNumber.size() > SmallerNumber.size()) {
		int div = BiggerNumber.size() - SmallerNumber.size();

		for (int i = 0; i < div; i++) {
			SmallerNumber.push_back(0);
		}
	}

	if (isXGreater) {
		if (BiggerNumber.size() == SmallerNumber.size()) {

			for (size_t i = 0; i < BiggerNumber.size(); ++i) {
				result.push_back(std::make_pair(BiggerNumber[i], SmallerNumber[i]));
			}
		}
	}
	else {
		if (BiggerNumber.size() == SmallerNumber.size()) {

			for (size_t i = 0; i < BiggerNumber.size(); ++i) {
				result.push_back(std::make_pair(SmallerNumber[i], BiggerNumber[i]));
			}
		}
	}

	return result;
}


void HumanizedMouse::MoveToExactPoint(int x, int y, UINT speedIn_NS) {
	std::vector<std::pair<int, int>> result;
	std::vector<int> BiggerNumber;
	std::vector<int> SmallerNumber;
	std::random_device rd;
	std::mt19937 gen(rd());
	
	//std::cout << "Path Started" << std::endl;

	int ProcessFirst = 0;
	int ControlProcessFirst = 0;
	int OriginalProcessFirst = 0;
	int ProcessSecond = 0;
	int ControlProcessSecond = 0;
	int OriginalProcessSecond = 0;

	bool isXGreater = isXGreaterThanY(abs(x), abs(y));

	if (isXGreater) {
		ProcessFirst = abs(x);
		ControlProcessFirst = abs(x);	
		OriginalProcessFirst = x;
		ProcessSecond = abs(y);
		ControlProcessSecond = abs(y);
		OriginalProcessSecond = y;
	}
	else {
		ProcessFirst = abs(y);
		ControlProcessFirst = abs(y);
		OriginalProcessFirst = y;
		ProcessSecond = abs(x);
		ControlProcessSecond = abs(x);
		OriginalProcessSecond = x;
	}

	int step = 0;
	while (ProcessFirst > 0) {
		step = 1;

		if (step > ProcessFirst) step = ProcessFirst;

		ProcessFirst -= step;
		BiggerNumber.push_back(OriginalProcessFirst < 0 ? step *= -1 : step);
	}

	step = 0;
	while (ProcessSecond > 0) {
		step = 1;

		if (step > ProcessSecond) step = ProcessSecond;

		ProcessSecond -= step;

		SmallerNumber.push_back(OriginalProcessSecond < 0 ? step *= -1 : step);
	}

	//std::cout << "BiggerNumber.size(): " << BiggerNumber.size() << std::endl;
	//std::cout << "SmallerNumber.size(): " << SmallerNumber.size() << std::endl;

	int div = BiggerNumber.size() - SmallerNumber.size();
	int zeroCount = div;

	int currentIndex = SmallerNumber.size() - 1;
	if (currentIndex <= 0) {
		for (int i = 0; i < zeroCount; i++) {
			SmallerNumber.push_back(0);
		}
	}
	else {
		while (zeroCount > 0) {
			//cout << "currentIndex: " << currentIndex << endl;

			if (currentIndex < 0) {
				currentIndex = SmallerNumber.size() - 1;
				continue;
			}

			if (SmallerNumber[currentIndex] >= 3 || SmallerNumber[currentIndex] <= -3) {
				currentIndex = SmallerNumber.size() - 1;
				continue;
			}

			if (std::uniform_int_distribution<int>(1, 100)(gen) >= 40) {
				SmallerNumber.insert(SmallerNumber.begin() + currentIndex, 0);
				zeroCount--;
			}

			currentIndex--;
		}
	}



	if (BiggerNumber.size() < SmallerNumber.size()) {
		int div = SmallerNumber.size() - BiggerNumber.size();

		for (int i = 0; i < div; i++) {
			BiggerNumber.push_back(0);
		}
	}
	else if (BiggerNumber.size() > SmallerNumber.size()) {
		int div = BiggerNumber.size() - SmallerNumber.size();

		for (int i = 0; i < div; i++) {
			SmallerNumber.push_back(0);
		}
	}

	if (isXGreater) {
		if (BiggerNumber.size() == SmallerNumber.size()) {

			for (size_t i = 0; i < BiggerNumber.size(); ++i) {
				result.push_back(std::make_pair(BiggerNumber[i], SmallerNumber[i]));
			}
		}
	}
	else {
		if (BiggerNumber.size() == SmallerNumber.size()) {

			for (size_t i = 0; i < BiggerNumber.size(); ++i) {
				result.push_back(std::make_pair(SmallerNumber[i], BiggerNumber[i]));
			}
		}
	}

	UINT SleepDuration = speedIn_NS / result.size();

	//std::cout << result.size() << std::endl;	
	//std::cout << "Path Finished" << std::endl;

	for (const auto& step : result) {
		moveMouse(step.first, step.second);

		std::this_thread::sleep_for(std::chrono::nanoseconds(SleepDuration));
	}
}

void HumanizedMouse::MoveToDirection(RotationX rotationX, RotationY rotationY, UINT speedIn_NS) {
	int XRotation = 0;
	int YRotation = 0;
	std::vector<std::pair<int, int>> mousePath;

	while (true) {
		/// X
		if (rotationX == TurnAround) {
			if (shouldAddPrefix())
				XRotation = -1800 - getRandomValueForAutoRotation(-20, 20);
			else
				XRotation = 1800 - getRandomValueForAutoRotation(-20, 20);
		}
		else if (rotationX == AutoRotationX) {
			XRotation = getRandomValueForAutoRotation(-100, 100);
		}
		else {
			XRotation = static_cast<int>(rotationX) - getRandomValueForAutoRotation(-10, 10);
		}

		/// Y
		if (rotationY == AutoRotationY) {
			YRotation = getRandomValueForAutoRotation(-40, 40);
		}
		else {
			YRotation = static_cast<int>(rotationY) - getRandomValueForAutoRotation(-10, 10);
		}

		//cout << XRotation << "  :  " << YRotation << endl;
		//cout << endl;

		if (XRotation != 0 && YRotation != 0) {
			break;
		}
	}

	mousePath = makePath(XRotation, YRotation);

	/*std::cout << "X : Y" << std::endl;
	for (const auto& step : mousePath) {
		std::cout << step.first << " : " << step.second << std::endl;
	}*/

	UINT minSleep = 3400;
	UINT maxSleep = 4100;

	UINT stepDuration = (maxSleep - minSleep) / mousePath.size();
	UINT CurrentSleep = minSleep;

	for (const auto& step : mousePath) {
		moveMouse(step.first, step.second);

		std::this_thread::sleep_for(std::chrono::nanoseconds(CurrentSleep));

		CurrentSleep += stepDuration;
	}
}
