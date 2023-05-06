#pragma once
#include <iostream>
#include <vector>
#include <conio.h>
#include <windows.h>
#include "MovPrefix.h"
using namespace std;

//enum Color { RED, ORANGSH, GREEN, BLUE, PURPLE, PINK, GRAY, NOCOLOR };

class PointCase {
public:
	std::string tagCase = {}, nameOfCase = {};
	POINT point = {};
	int heightTempl = {}, widthTempl = {}, page = {}, identyfierAsHEX = {};
	std::vector<std::vector<POINT>> freeSlots{};
	Prefix prefix;

	PointCase();
	PointCase(POINT point, std::string nameOfCase, const std::string tagCase, int heightTempl, int widthTempl, int page, int identyfierAsHEX, std::vector<std::vector<POINT>> freeSlots, Prefix prefix);
	virtual ~PointCase() {};
};

class PointCaseInStash: public PointCase
{
public:
	PointCaseInStash();
	PointCaseInStash(POINT point, std::string nameOfCase, const std::string tagCase, int heightTempl, int widthTempl, int page, int identyfierAsHEX, std::vector<std::vector<POINT>> freeSlots, Prefix prefix);

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
	PointCaseInCase(POINT point, POINT pointFromParentCase, std::string nameOfCase, const std::string tagCase, int heightTempl, int widthTempl, int pageOfParentCase, int identyfierAsHEX, std::vector<std::vector<POINT>> freeSlots, Prefix prefix);

public:
	static std::vector<std::vector<PointCaseInCase>> pointCaseInCase;
};