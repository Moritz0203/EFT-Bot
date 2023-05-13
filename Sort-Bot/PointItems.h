#pragma once
#include <iostream>
#include <vector>
#include <conio.h>
#include <windows.h>


class PointItem {
public:
	POINT point = {};
	int heightTempl = {}, widthTempl = {}, page = {}, slotsPerItem = {};
	std::string nameOfItem = {};

	PointItem();
	PointItem(POINT point, std::string nameOfItem, int heightTempl, int widthTempl, int page, int slotsPerItem);
	virtual ~PointItem() {};
};

class PointAmmunition: public PointItem
{
public:
	int stackSize = {};

	PointAmmunition();
	PointAmmunition(POINT point, std::string nameOfItem, int heightTempl, int widthTempl, int page, int slotsPerItem, int stackSize);

public:
	static std::vector<std::vector<PointAmmunition>> pointAmmunition_C;
	static std::vector<std::vector<PointAmmunition>> pointAmmunition_NC;
};

class PointMagazine: public PointItem
{
public:
	int fillStatus = {};

	PointMagazine();
	PointMagazine(POINT point, std::string nameOfItem, int heightTempl, int widthTempl, int page, int slotsPerItem, int fillStatus);

public:
	static std::vector<std::vector<PointMagazine>> pointMagazine_C;
	static std::vector<std::vector<PointMagazine>> pointMagazine_NC;
};

class PointBarter: public PointItem
{
public:
	bool isFoundInRaid = {};

	PointBarter();
	PointBarter(POINT point, std::string nameOfItem, int heightTempl, int widthTempl, int page, int slotsPerItem, bool isFoundInRaid);

public:
	static std::vector<std::vector<PointBarter>> pointBarter_C;
	static std::vector<std::vector<PointBarter>> pointBarter_NC;
};
