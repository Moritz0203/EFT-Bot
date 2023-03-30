#pragma once
#include <iostream>
#include <vector>
#include <conio.h>
#include <windows.h>
#include <vector>
using namespace std;

//enum Color { RED, ORANGSH, GREEN, BLUE, PURPLE, PINK, GRAY, NOCOLOR };

class PointCaseInStash
{
public:
	std::string tagCase = {};
	POINT point = {};
	int heightTempl = {}, widthTempl = {}, page = {};
	std::string nameOfCase = {};
	int identyfierAsHEX{};
	std::vector<std::vector<POINT>> freeSlots{};

	PointCaseInStash();
	PointCaseInStash(POINT point, std::string nameOfCase, const std::string tagCase, int heightTempl, int widthTempl, int page, int identyfierAsHEX, std::vector<std::vector<POINT>> freeSlots);
};

class PointCaseInCase
{
public:
	std::string tagCase = {};
	POINT point = {}, pointFromParentCase = {};
	int heightTempl = {}, widthTempl = {}, pageOfParentCase = {};
	std::string nameOfCase = {};
	int identyfierAsHEX{};
	std::vector<std::vector<POINT>> freeSlots{};

	PointCaseInCase();
	PointCaseInCase(POINT point, POINT pointFromParentCase, std::string nameOfCase, const std::string tagCase, int heightTempl, int widthTempl, int pageOfParentCase, int identyfierAsHEX, std::vector<std::vector<POINT>> freeSlots);
};