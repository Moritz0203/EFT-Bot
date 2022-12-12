#pragma once
#include <iostream>
#include <vector>
#include <conio.h>
#include <windows.h>

enum Color { RED, ORANGSH, GREEN, BLUE, PURPLE, PINK, GRAY, NOCOLOR };

class PointCase
{
public:
	Color color;
	POINT point;
	int heightTempl, widthTempl;
	std::string nameOfCase;

	PointCase();
	PointCase(POINT point, std::string nameOfCase, Color color, int heightTempl, int widthTempl);
};

