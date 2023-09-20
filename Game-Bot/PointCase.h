#pragma once
#include <iostream>
#include <vector>
#include <conio.h>
#include <windows.h>
#include "PointItems.h"
using namespace std;

class Pouch {
public:
	std::string nameOfPouch = {};
	POINT pointPouch = {};// only my screen 
	vector<PointMedical> ItemsInPouch{};

	Pouch();
	Pouch(std::string nameOfPouch, const POINT pointPouch, vector<PointMedical> ItemsInPouch);

public:
	static Pouch pouch;
};

class PointCase {
public:
	std::string tagCase = {}, nameOfCase = {};
	POINT point = {};
	int heightTempl = {}, widthTempl = {}, page = {}, identyfierAsHEX = {};

	PointCase();
	PointCase(POINT point, std::string nameOfCase, const std::string tagCase, int heightTempl, int widthTempl, int page);
	virtual ~PointCase() {};
};

class PointCaseInStash: public PointCase
{
public:
	vector<PointItem> ItemsInCase{};// Maybe change later 

	PointCaseInStash();
	PointCaseInStash(POINT point, std::string nameOfCase, const std::string tagCase, int heightTempl, int widthTempl, int page, vector<PointItem> ItemsInCase);

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

class PointCaseInStashMedical : public PointCase
{
public:
	vector<PointMedical> ItemsInCase{};

	PointCaseInStashMedical();
	PointCaseInStashMedical(POINT point, std::string nameOfCase, const std::string tagCase, int heightTempl, int widthTempl, int page, vector<PointMedical> ItemsInCase);

public:
	static std::vector<std::vector<PointCaseInStashMedical>> pointCaseInStashMedical_C;
	static std::vector<std::vector<PointCaseInStashMedical>> pointCaseInStashMedical_NC;
};