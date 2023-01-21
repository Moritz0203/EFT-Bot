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
