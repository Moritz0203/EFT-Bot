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
	virtual ~PointItem() {}
};

class PointAmmunition: public PointItem
{
public:
	int stackSize = {};

	PointAmmunition();
	PointAmmunition(POINT point, std::string nameOfItem, int heightTempl, int widthTempl, int page, int slotsPerItem, int stackSize);
};

class PointMagazine: public PointItem
{
public:
	int fillStatus = {};

	PointMagazine();
	PointMagazine(POINT point, std::string nameOfItem, int heightTempl, int widthTempl, int page, int slotsPerItem, int fillStatus);
};

class PointBarter: public PointItem
{
public:
	bool isFoundInRaid = {};

	PointBarter();
	PointBarter(POINT point, std::string nameOfItem, int heightTempl, int widthTempl, int page, int slotsPerItem, bool isFoundInRaid);
};
