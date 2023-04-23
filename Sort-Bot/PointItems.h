#pragma once
#include <iostream>
#include <vector>
#include <conio.h>
#include <windows.h>

class PointAmmunition
{
public:
	int stackSize = {};
	POINT point = {};
	int heightTempl = {}, widthTempl = {}, page = {};
	std::string nameOf = {};
	int slotsPerItem = {};

	PointAmmunition();
	PointAmmunition(POINT point, std::string nameOf, int stackSize, int heightTempl, int widthTempl, int page, int slotsPerItem);
};

class PointMagazine
{
public:
	int fillStatus = {};
	POINT point = {};
	int heightTempl = {}, widthTempl = {}, page = {};
	std::string nameOfMagazine = {};
	int slotsPerItem = {};

	PointMagazine();
	PointMagazine(POINT point, std::string nameOfMagazine, int fillStatus, int heightTempl, int widthTempl, int page, int slotsPerItem);
};

class PointBarter
{
public:
	bool isFoundInRaid = {};
	POINT point = {};
	int heightTempl = {}, widthTempl = {}, page = {};
	std::string nameOfBarter = {};
	int slotsPerItem = {};

	PointBarter();
	PointBarter(POINT point, std::string nameOfBarter, bool isFoundInRaid, int heightTempl, int widthTempl, int page, int slotsPerItem);
};
