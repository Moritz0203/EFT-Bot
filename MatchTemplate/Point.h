#pragma once
#include <iostream>
#include <vector>
#include <conio.h>
#include <windows.h>

enum Color { RED, ORANGSH, GREEN, BLUE, PURPLE, PINK, GRAY, NOCOLOR };

class PointCaseInStash
{
public:
	Color color = {};
	POINT point = {};
	int heightTempl = {}, widthTempl = {}, page = {};
	std::string nameOfCase = {};

	PointCaseInStash();
	PointCaseInStash(POINT point, std::string nameOfCase, Color color, int heightTempl, int widthTempl, int page);
};

class PointCaseInCase
{
public:
	Color color = {};
	POINT pointInCase = {}, pointFromParentCase = {};
	int heightTempl = {}, widthTempl = {}, page = {};
	std::string nameOfCase = {};

	PointCaseInCase();
	PointCaseInCase(POINT pointInCase, POINT pointFromParentCase, std::string nameOfCase, Color color, int heightTempl, int widthTempl, int page);
};

