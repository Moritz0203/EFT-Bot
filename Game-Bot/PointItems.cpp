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

std::vector<std::vector<PointAmmunition>> PointAmmunition::pointAmmunition_C;
std::vector<std::vector<PointAmmunition>> PointAmmunition::pointAmmunition_NC;

PointBarter::PointBarter()
{
}

PointBarter::PointBarter(POINT point, std::string nameOfItem, int heightTempl, int widthTempl, int page, int slotsPerItem, bool isFoundInRaid)
	:PointItem(point, nameOfItem, heightTempl, widthTempl, page, slotsPerItem)
{
	this->isFoundInRaid = isFoundInRaid;
}

std::vector<std::vector<PointBarter>> PointBarter::pointBarter_C;
std::vector<std::vector<PointBarter>> PointBarter::pointBarter_NC;

PointMedical::PointMedical()
{
}

PointMedical::PointMedical(POINT point, std::string nameOfItem, int heightTempl, int widthTempl, int page, int slotsPerItem, uint8_t hpItem, uint8_t hpItemMax)
	:PointItem(point, nameOfItem, heightTempl, widthTempl, page, slotsPerItem)
{
	this->hpItem = hpItem;
	this->hpItemMax = hpItemMax;
}

std::vector<std::vector<PointMedical>> PointMedical::pointMedical_C;
std::vector<std::vector<PointMedical>> PointMedical::pointMedical_NC;