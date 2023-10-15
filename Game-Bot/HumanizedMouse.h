#pragma once

#include "Normal.h"
#include "BezierCurve.h"

class HumanizedMouse
{
private:
	Normal targetDistribution;
	Normal midpointDistribution;

	int Random(int lowerBound, int upperBound);
	void MouseMoveInternal(float x, float y);

public:
	void MoveMouse(int x, int y);

	void MoveMouseInGame(int xOffset, int yOffset, int initialDelay_NS, int Accuracy);
};

