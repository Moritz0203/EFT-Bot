#pragma once
#include <iostream>
#include <vector>
#include <conio.h>
#include <windows.h>
#include "MovPrefix.h"
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
	std::shared_ptr<Prefix> prefix{};

	PointCaseInStash();
	PointCaseInStash(POINT point, std::string nameOfCase, const std::string tagCase, int heightTempl, int widthTempl, int page, int identyfierAsHEX, std::vector<std::vector<POINT>> freeSlots, std::shared_ptr<Prefix> prefix);

public:
	static std::vector<std::vector<PointCaseInStash>> pointCaseInStash_C;
	static std::vector<std::vector<PointCaseInStash>> pointCaseInStash_NC;
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
	std::shared_ptr<Prefix> prefix{};

	PointCaseInCase();
	PointCaseInCase(POINT point, POINT pointFromParentCase, std::string nameOfCase, const std::string tagCase, int heightTempl, int widthTempl, int pageOfParentCase, int identyfierAsHEX, std::vector<std::vector<POINT>> freeSlots, std::shared_ptr<Prefix> prefix);

public:
	static std::vector<std::vector<PointCaseInCase>> pointCaseInCase;
};