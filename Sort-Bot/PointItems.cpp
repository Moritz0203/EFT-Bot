#include "PointItems.h"

PointItem::PointItem()
{
}

PointItem::PointItem(POINT point, std::string nameOfItem, int heightTempl, int widthTempl, int page, int slotsPerItem)
{
	this->point = point;
	this->heightTempl = heightTempl;
	this->widthTempl = widthTempl;
	this->page = page;
	this->slotsPerItem = slotsPerItem;
	this->nameOfItem = nameOfItem;
}

PointAmmunition::PointAmmunition()
{
}

PointAmmunition::PointAmmunition(POINT point, std::string nameOfItem, int heightTempl, int widthTempl, int page, int slotsPerItem, int stackSize)
	:PointItem(point, nameOfItem, heightTempl, widthTempl, page, slotsPerItem)
{
	this->stackSize = stackSize;
}

PointMagazine::PointMagazine()
{
}

PointMagazine::PointMagazine(POINT point, std::string nameOfItem, int heightTempl, int widthTempl, int page, int slotsPerItem, int fillStatus)
	:PointItem(point, nameOfItem, heightTempl, widthTempl, page, slotsPerItem)
{
	this->fillStatus = fillStatus;
}

PointBarter::PointBarter()
{
}

PointBarter::PointBarter(POINT point, std::string nameOfItem, int heightTempl, int widthTempl, int page, int slotsPerItem, bool isFoundInRaid)
	:PointItem(point, nameOfItem, heightTempl, widthTempl, page, slotsPerItem)
{
	this->isFoundInRaid = isFoundInRaid;
}


