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

class PointMedical : public PointItem {
public:
	uint16_t hpItem = {};
	uint16_t hpItemMax = {};

	PointMedical();
	PointMedical(POINT point, std::string nameOfItem, int heightTempl, int widthTempl, int page, int slotsPerItem, uint16_t hpItem, uint16_t hpItemMax);

public:
	static std::vector<std::vector<PointMedical>> pointMedical_C;
	static std::vector<std::vector<PointMedical>> pointMedical_NC;
};