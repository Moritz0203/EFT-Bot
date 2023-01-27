#include "PointItems.h"

PointAmmunition::PointAmmunition()
{
}

PointAmmunition::PointAmmunition(POINT point, std::string nameOfAmmunition, int stackSize, int heightTempl, int widthTempl, int page)
{
	this->point = point;
	this->nameOfAmmunition = nameOfAmmunition;
	this->stackSize = stackSize;
	this->heightTempl = heightTempl;
	this->widthTempl = widthTempl;
	this->page = page;
}

PointMagazine::PointMagazine()
{
}

PointMagazine::PointMagazine(POINT point, std::string nameOfMagazine, int fillStatus, int heightTempl, int widthTempl, int page)
{
	this->point = point;
	this->nameOfMagazine = nameOfMagazine;
	this->fillStatus = fillStatus;
	this->heightTempl = heightTempl;
	this->widthTempl = widthTempl;
	this->page = page;
}
