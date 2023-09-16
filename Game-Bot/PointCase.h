#pragma once
#include <iostream>
#include <vector>
#include <conio.h>
#include <windows.h>
#include "PointItems.h"
using namespace std;

//enum Color { RED, ORANGSH, GREEN, BLUE, PURPLE, PINK, GRAY, NOCOLOR };

class PointCase {
public:
	std::string tagCase = {}, nameOfCase = {};
	POINT point = {};
	int heightTempl = {}, widthTempl = {}, page = {}, identyfierAsHEX = {};
	std::vector<std::vector<POINT>> freeSlots{};

	PointCase();
	PointCase(POINT point, std::string nameOfCase, const std::string tagCase, int heightTempl, int widthTempl, int page);
	virtual ~PointCase() {};
};

class PointCaseInStash: public PointCase
{
public:
	vector<PointMedical> ItemsInCase{};

	PointCaseInStash();
	PointCaseInStash(POINT point, std::string nameOfCase, const std::string tagCase, int heightTempl, int widthTempl, int page, vector<PointMedical> ItemsInCase);

public:
	static std::vector<std::vector<PointCaseInStash>> pointCaseInStash_C;
	static std::vector<std::vector<PointCaseInStash>> pointCaseInStash_NC;
};

class PointCaseInCase: public PointCase
{
public:
	POINT pointFromParentCase = {};
	int pageOfParentCase = {};

	PointCaseInCase();
	PointCaseInCase(POINT point, POINT pointFromParentCase, std::string nameOfCase, const std::string tagCase, int heightTempl, int widthTempl, int pageOfParentCase);

public:
	static std::vector<std::vector<PointCaseInCase>> pointCaseInCase;
};