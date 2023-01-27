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
	std::string nameOfAmmunition = {};

	PointAmmunition();
	PointAmmunition(POINT point, std::string nameOfAmmunition, int stackSize, int heightTempl, int widthTempl, int page);
};

class PointMagazine
{
public:
	int fillStatus = {};
	POINT point = {};
	int heightTempl = {}, widthTempl = {}, page = {};
	std::string nameOfMagazine = {};

	PointMagazine();
	PointMagazine(POINT point, std::string nameOfMagazine, int fillStatus, int heightTempl, int widthTempl, int page);
};
