#include "PointItems.h"

PointAmmunition::PointAmmunition()
{
}

PointAmmunition::PointAmmunition(POINT point, std::string nameOf, int stackSize, int heightTempl, int widthTempl, int page, int slotsPerItem)
{
	this->point = point;
	this->nameOf = nameOf;
	this->stackSize = stackSize;
	this->heightTempl = heightTempl;
	this->widthTempl = widthTempl;
	this->page = page;
	this->slotsPerItem = slotsPerItem;
}

PointMagazine::PointMagazine()
{
}

PointMagazine::PointMagazine(POINT point, std::string nameOfMagazine, int fillStatus, int heightTempl, int widthTempl, int page, int slotsPerItem)
{
	this->point = point;
	this->nameOfMagazine = nameOfMagazine;
	this->fillStatus = fillStatus;
	this->heightTempl = heightTempl;
	this->widthTempl = widthTempl;
	this->page = page;
	this->slotsPerItem = slotsPerItem;
}

PointBarter::PointBarter()
{
}

PointBarter::PointBarter(POINT point, std::string nameOfBarter, bool isFoundInRaid, int heightTempl, int widthTempl, int page, int slotsPerItem)
{
	this->point = point;
	this->nameOfBarter = nameOfBarter;
	this->isFoundInRaid = isFoundInRaid;
	this->heightTempl = heightTempl;
	this->widthTempl = widthTempl;
	this->page = page;
	this->slotsPerItem = slotsPerItem;
}
