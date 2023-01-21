#pragma once
#include <iostream>
#include <vector>
#include <conio.h>
#include <windows.h>

//enum Color { RED, ORANGSH, GREEN, BLUE, PURPLE, PINK, GRAY, NOCOLOR };

class PointCaseInStash
{
public:
	std::string tagCase = {};
	POINT point = {};
	int heightTempl = {}, widthTempl = {}, page = {};
	std::string nameOfCase = {};

	PointCaseInStash();
	PointCaseInStash(POINT point, std::string nameOfCase, const std::string tagCase, int heightTempl, int widthTempl, int page);
};

class PointCaseInCase
{
public:
	std::string tagCase = {};
	POINT pointInCase = {}, pointFromParentCase = {};
	int heightTempl = {}, widthTempl = {}, pageOfParentCase = {};
	std::string nameOfCase = {};

	PointCaseInCase();
	PointCaseInCase(POINT pointInCase, POINT pointFromParentCase, std::string nameOfCase, const std::string tagCase, int heightTempl, int widthTempl, int pageOfParentCase);
};