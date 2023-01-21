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

